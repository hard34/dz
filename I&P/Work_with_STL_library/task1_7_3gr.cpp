#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

bool odd(int x) {
	return x % 2 == 0;
}

int X;
bool kratn(int x) {
	return x % X == 0;
}

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

	cout << " Delete all even elements:\n";
	vector<int>::iterator it = remove_if(vec.begin(), vec.end(), odd);
	vec.erase(it, vec.end()); 
	for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++) 
		cout << *iter << " ";
	cout << endl;

	cout << "Replace all the maximum elements with the minimum:\n"; 
	int Max = *max_element(vec.begin(), vec.end()); 
	int Min = *min_element(vec.begin(), vec.end()); 
	replace(vec.begin(), vec.end(), Max, Min);

	for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++) 
		cout << *iter << " ";
	cout << endl;

	cout << "X = ";
	cin >> X;
	int k = count_if(vec.begin(), vec.end(), kratn); 
	cout << "Find the number of elements that are multiples of X: " << k << endl;
	return 0;
}