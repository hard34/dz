#include<iostream>
#include <algorithm> 
#include <string> 
#include <set> 
#include<iterator> 
#include <map>
#include <windows.h>
#include <fstream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	string num = "1234567890";
	string s, number;
	map<string, int> a;
	ifstream in("input_task2_15.txt");
	while (getline(in, s)) { //Cчитывание строки из файла.
		while (!empty(s)) {
			if (s[0] == ' ')
				s.erase(0, 1);
			string::size_type k = s.find_first_of(" "); //Выделяем слово.
			number = s.substr(0, k);
			if (number.find_first_of(num) != string::npos) {//Проверка является слово числом.	
				a[number]++;//Запись в map
			}
			s.erase(0, k);//Удаление от 0 до k.
		}
	}
	int z;
	cout << "Введите кол-во вхождений: ";
	cin >> z;
	for (auto it = a.begin(); it != a.end(); it++)
		if (it->second == z)
		cout<< it->first << endl;
	in.close();
}
