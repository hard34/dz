#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int X;  
bool odd(int x) {
	return x % X == 0;
}
int a, b;
bool ab(int x) {
	return (x >= a && x <= b);
}



int main() {
	setlocale(LC_ALL, "russian");
	int n, m;
	cout << "n = "; cin >> n;
	vector<int> vec, vec1, vec2;

	int x;
	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "] = ";
		cin >> x;
		vec1.push_back(x);
	}
	for (vector<int>::iterator iter = vec1.begin(); iter != vec1.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	cout << "m = "; cin >> m;
	for (int i = 0; i < m; i++) {
		cout << "a[" << i << "] = ";
		cin >> x;
		vec2.push_back(x);
	}

	for (vector<int>::iterator iter = vec2.begin(); iter != vec2.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	cout << "X = ";	cin >> X;
	cout << "In the first sequence, delete all elements that are multiples of X.:\n";
	vector<int>::iterator it = remove_if(vec1.begin(), vec1.end(), odd);
	vec1.erase(it, vec1.end()); 

	for (vector<int>::iterator iter = vec1.begin(); iter != vec1.end(); iter++) 
		cout << *iter << " ";
	cout << endl;

	int Y;
	cout << "Enter the gap:\n";
	cin >> a >> b;
	cout << "Enter Y:\n";
	cin >> Y;
	cout << "In the second one, replace the elements falling in the interval [a, b] with the number Y:\n";
	replace_if(vec2.begin(), vec2.end(), ab, Y); 

	for (vector<int>::iterator iter = vec2.begin(); iter != vec2.end(); iter++) 
		cout << *iter << " ";
	cout << endl;

	cout << "Sort vector 1:\n";
	sort(vec1.begin(), vec1.end()); 
	for (vector<int>::iterator iter = vec1.begin(); iter != vec1.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	cout << "Sort vector 2:\n";
	sort(vec2.begin(), vec2.end()); 
	for (vector<int>::iterator iter = vec2.begin(); iter != vec2.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	cout << "Combine them into one:\n"; 
	vec.insert(vec.end(), vec1.begin(), vec1.end());
	vec.insert(vec.end(), vec2.begin(), vec2.end());

	for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	cout << "Sort vector:\n";
	sort(vec.begin(), vec.end()); 
	for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
		cout << *iter << " ";
	cout << endl;
	return 0;
}