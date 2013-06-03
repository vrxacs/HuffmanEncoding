#include <vector>
#include <string>
#include <queue>
#include <map>
#include <iterator>
#include <iostream>


using std::string;
using std::vector;
using std::pair;
using std::priority_queue;
using std::map;
using std::iterator;

class Node {
	public:
		int freq;
		int left;
		int right;
		char c;

		Node()=default;
		Node(char, int);
		bool operator<(const Node& a) const;

};

Node::Node(char ch, int fr){
	freq = fr;
	left = -1;
	right = -1;
	c = ch;
}

bool Node::operator <(const Node& a) const{
	return freq > a.freq;
}


void huffman(const string &message, vector<bool> &encoding);
void buildCodes(int root, const vector<Node> &tree, map<char, vector<bool>> &codes, vector<bool> code);


void huffman(const string &message, vector<bool> &encoding){

	priority_queue<Node> pq;
	vector<Node> tree;
	map<char, vector<bool> > codes;
	int freq[256] = {0};

	//1. get frequency
	for(unsigned int i = 0; i < message.size(); ++i){
		freq[message[i]]++;
	}


	//2. create priority queue
	for(int i = 0; i<256; ++i){
		if(freq[i] > 0)
			pq.push(Node((char)i, freq[i]));
	}

	//3. build huffman tree
	int root;
	int n = pq.size();
	Node z;
	int x, y;
	for(int i = 1; i < n; ++i){
		z = Node();
		//get x;
		tree.push_back(pq.top());
		x = tree.size()-1;
		pq.pop();
		//get y;
		tree.push_back(pq.top());
		y = tree.size()-1;
		pq.pop();

		z.left = x;
		z.right = y;
		z.freq = tree[x].freq + tree[y].freq;

		pq.push(z);
	}
	//set root;
	tree.push_back(pq.top());
	root = tree.size()-1;
	pq.pop();



	//4. use huffman tree to create a map from character to huffman code ?
	vector<bool> code;
	buildCodes(root, tree, codes, code);

	//5. use the map to construct the encoding
	code.clear();
	for(unsigned int i = 0; i < message.size(); ++i){
		code = codes.at(message[i]);
		encoding.insert(encoding.end(), code.begin(), code.end());
	}

	//6. ???
	//7. profit

}

void buildCodes(int root, const vector<Node> &tree, map<char, vector<bool> > &codes, vector<bool> code){

	if(tree[root].left == -1 && tree[root].right == -1){
		codes.insert(std::make_pair(tree[root].c,code));
		return;
	}

	//go left
	if(tree[root].left != -1){
		code.push_back(0);
		buildCodes(tree[root].left, tree, codes, code);
		code.pop_back();
	}

	//go right
	if(tree[root].right != -1){
		code.push_back(1);
		buildCodes(tree[root].right, tree, codes, code);
		code.pop_back();
	}

}


