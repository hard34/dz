#include <iostream>
#include <set>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream input;
	input.open("input.txt");
	int k = 0, n = 0;
	string s;
	set <string> strs;
	set <string> vec;
	while (!input.eof()) {
		input >> s;

		if (s[s.size() - 1] != '!' && s[s.size() - 1] != '?' && s[s.size() - 1] != '.') {
			s[0] = tolower(s[0]);
			strs.insert(s);
		}
		else {
			strs.insert(s.substr(0, s.size() - 1));
			if (s[s.size() - 1] != '.') {
				for (set<string>::iterator it = strs.begin(); it != strs.end(); it++) {
					string temp = *it;
					vec.insert(temp);
					k++;
				}
			}
			strs.clear();
		}

	}
	for (set<string>::iterator it = vec.begin(); it != vec.end(); it++) {
		cout << *it << " ";
	}
	cout << endl << k << endl;
}
//Who told you this ?
//It's not my fault!
//Don't make me repeat twice.