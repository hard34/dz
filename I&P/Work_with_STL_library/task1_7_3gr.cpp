#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

bool odd(int x) {//четные
	return x % 2 == 0;
}

int X; //предикат может содержать только один параметр
bool kratn(int x) {//кратный X
	return x % X == 0;
}

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

	cout << " ”даление четных элементов:\n";
	vector<int>::iterator it = remove_if(vec.begin(), vec.end(), odd);
	vec.erase(it, vec.end()); //удаление

	for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++) //вывод
		cout << *iter << " ";
	cout << endl;

	cout << "«амена максимальных  элементов на минимальный\n"; 
	int Max = *max_element(vec.begin(), vec.end()); //поиск максимальных
	int Min = *min_element(vec.begin(), vec.end()); //поиск минимальных
	replace(vec.begin(), vec.end(), Max, Min); //замена

	for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++) //вывод
		cout << *iter << " ";
	cout << endl;

	cout << "X = ";
	cin >> X;
	int k = count_if(vec.begin(), vec.end(), kratn); //подсчет
	cout << " оличество элементов, кратных ’: " << k << endl;
	return 0;
}