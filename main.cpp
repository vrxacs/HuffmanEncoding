#include <vector>
#include <iostream>
#include <string>
#include "huffman.cpp"

using std::cout;
using std::cin;
using std::vector;
using std::string;

int main(){

	string s = "aabcccccdddd";
	vector<bool> encode;

	huffman(s, encode);

	//a:  101
	//b:  100
	//c:  0
	//d:  11


	for(auto i = encode.begin(); i != encode.end(); ++i){
		cout << (*i);
	}

}
