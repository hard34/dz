#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

ifstream in("input1.txt");
double A = 0.61803;

struct People {//структура людей
	string name, duty, data;
	int stage, salary;
};

void find(vector<People>& hash, int m) {//функция поиска
	int x = 0; cout << "Input stage: "; cin >> x;
	int j = 0;
	int p = 0;
	double k = A * x;
	double n;
	int l = m * modf(k, &n);
	while (true) {
		int p = l + j;
		j++;
		if (hash[p].stage == x) {
			cout << "Found " << hash[p].name << " " << hash[p].duty << " " << hash[p].data << " " << hash[p].stage << " " << hash[p].salary << "\n";
			return;
		}
	}
	cout << "Not found\n";
}

void _run() {
	string str = "";
	vector<People> base;

	for (int i = 0; in.peek() != EOF; ++i) {//считываем файл
		base.resize(i + 1);
		getline(in, str);
		istringstream input(str);
		input >> base[i].name >> base[i].duty >> base[i].data >> base[i].stage >> base[i].salary;
	}

	int m = 0; cout << "Input M = "; cin >> m;
	vector<People> hash; hash.resize(m);
	People r;
	r.stage = -1;
	for (int i = 0; i < m; hash[i] = r, ++i); //хэш-таблицу заполняем значениями

	for (int i = 0; i < base.size(); ++i) { //пока не дошли до конца
		int j = 0;
		int p = 0;
		double k = A * base[i].stage; //вспомогательная формулы
		double n;
		int l = m * modf(k, &n);
		while (true) {
			int p = l + j; //значение хэш-функции
			if (hash[p].stage == r.stage) { //если ячейка не занята
				hash[p] = base[i]; //вставляем в ячейка
				break;
			}
			else
				j++; //иначе увеличиваем j
		}
	}


	for (int i = 0; i < m; ++i) {
		cout << i << ": ";
		if (hash[i].stage != r.stage)
			cout << hash[i].name << " " << hash[i].duty << " " << hash[i].data << " " << hash[i].stage << " " << hash[i].salary << "\n";
		else
			cout << "NULL\n";
	}

	cout << "Add person :" << endl; //добавление нового человека
	People man;
	cin >> man.name >> man.duty >> man.data >> man.stage >> man.salary;
	if (man.stage != -1) {
		int j = 0;
		int p = 0;
		double k = A * man.stage;
		double n;
		int l = m * modf(k, &n);
		while (true) {
			int p = l + j;
			if (hash[p].stage == -1) {
				hash[p] = man;
				break;
			}
			else {
				j++;
			}
		}
	}
	cout << endl;

	for (int i = 0; i < m; ++i) {
		cout << i << ": ";
		if (hash[i].stage != r.stage)
			cout << hash[i].name << " " << hash[i].duty << " " << hash[i].data << " " << hash[i].stage << " " << hash[i].salary << "\n";
		else
			cout << "NULL\n";
	}

	find(hash, m);
}

int main() {
	_run();

	return 0;
}