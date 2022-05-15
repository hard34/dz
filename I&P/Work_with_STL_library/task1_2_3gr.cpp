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
	for (int i = 0; i < n; i++) {//создание вектора
		cout << "a[" << i << "] = ";
		cin >> x;
		vec.push_back(x);
	}

	for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)//вывод
		cout << *iter << " ";
	cout << endl;

	cout << " Удаление минимальные элементов:\n"; 
	vector<int>::iterator iter = min_element(vec.begin(), vec.end()); //поиск минимальных элементов
	int Min = *iter;
	vector<int>::iterator it = remove(vec.begin(), vec.end(), Min);
	vec.erase(it, vec.end()); //удаление
	
	for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++) //вывод
		cout << *iter << " ";
	cout << endl;
	return 0;
}