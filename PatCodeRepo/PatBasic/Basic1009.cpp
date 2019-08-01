#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	string words, word;
	vector<string> v;
	getline(cin, words);
	int start, end, i;
	start = 0, end = 0;
	while (end < words.length()) {
		if (words[end] == ' ') {
			word = words.substr(start, end - start);
			v.push_back(word);
			start = end + 1;
		}
		end++;
	}
	if (end == words.length()) {
		word = words.substr(start, end - start);
		v.push_back(word);
	}

	for (i = 0; i < v.size(); i++) {
		if (i != 0)
			cout << " ";
		cout << v[v.size() - 1 - i];
	}
	cout << endl;
}