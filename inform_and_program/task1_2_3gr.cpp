#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int main() {
	setlocale(LC_ALL, "russian");
	int n;
	cout << "n = "; cin >> n;
	vector<int> vec;

	int x;
	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "] = ";
		cin >> x;
		vec.push_back(x);
	}

	for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	cout << "Delete min:\n"; 
	vector<int>::iterator iter = min_element(vec.begin(), vec.end()); 
	int Min = *iter;
	vector<int>::iterator it = remove(vec.begin(), vec.end(), Min);
	vec.erase(it, vec.end()); 
	
	for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++) 
		cout << *iter << " ";
	cout << endl;
	return 0;
}