#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int X;  //предикат может содержать только один параметр
bool odd(int x) {//кратные Х
	return x % X == 0;
}
int a, b;
bool ab(int x) {//промежуток
	return (x >= a && x <= b);
}



int main() {
	setlocale(LC_ALL, "russian");
	int n, m;
	cout << "n = "; cin >> n;
	vector<int> vec, vec1, vec2;

	int x;
	for (int i = 0; i < n; i++) {//создание вектора
		cout << "a[" << i << "] = ";
		cin >> x;
		vec1.push_back(x);
	}
	for (vector<int>::iterator iter = vec1.begin(); iter != vec1.end(); iter++)//вывод
		cout << *iter << " ";
	cout << endl;

	cout << "m = "; cin >> m;
	for (int i = 0; i < m; i++) {//создание вектора
		cout << "a[" << i << "] = ";
		cin >> x;
		vec2.push_back(x);
	}

	for (vector<int>::iterator iter = vec2.begin(); iter != vec2.end(); iter++)//вывод
		cout << *iter << " ";
	cout << endl;

	cout << "X = ";	cin >> X;
	cout << " Удаление кратные X элементов:\n";
	vector<int>::iterator it = remove_if(vec1.begin(), vec1.end(), odd);
	vec1.erase(it, vec1.end()); //удаление

	for (vector<int>::iterator iter = vec1.begin(); iter != vec1.end(); iter++) //вывод
		cout << *iter << " ";
	cout << endl;

	int Y;
	cout << "Введите диапозон:\n";
	cin >> a >> b;
	cout << "Введите Y:\n";
	cin >> Y;
	cout << "Заменить элементы, попадающие в интервал [a,b] числом Y:\n";
	replace_if(vec2.begin(), vec2.end(), ab, Y); //замена

	for (vector<int>::iterator iter = vec2.begin(); iter != vec2.end(); iter++) //вывод
		cout << *iter << " ";
	cout << endl;

	cout << "Сортировка1:\n";
	sort(vec1.begin(), vec1.end()); //сортировка
	for (vector<int>::iterator iter = vec1.begin(); iter != vec1.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	cout << "Сортировка2:\n";
	sort(vec2.begin(), vec2.end()); //сортировка
	for (vector<int>::iterator iter = vec2.begin(); iter != vec2.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	cout << "Объединение:\n"; //объединяет
	vec.insert(vec.end(), vec1.begin(), vec1.end());
	vec.insert(vec.end(), vec2.begin(), vec2.end());

	for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	cout << "Сортировка:\n";
	sort(vec.begin(), vec.end()); //сортировка
	for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
		cout << *iter << " ";
	cout << endl;
	return 0;
}