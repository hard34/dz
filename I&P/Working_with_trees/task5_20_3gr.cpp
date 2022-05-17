// Дано дерево. Определить высоту узла X
#include<iostream>
#include <string>
using namespace std;

struct tree { // структура дерева
	int dual; // значения узла
	tree* right; // правый узел
	tree* left; // левый узел
};

tree* node(int x) { // функция создание узла 
	tree* n = new tree; // выделение памяти
	n->dual = x; // значения узла х
	n->left = n->right = NULL; // левый и правый узел ноль
	return n; // возвращение готового узла
}

void create(tree*& tr, int n) { //функция создание идеально сбалансированного дерева 
	int x; // объявление переменной 
	if (n > 0) { // пока n больше нуля 
		cout << "Элемент:  "; // вывод на экран
		cin >> x; // ввод 
		tr = node(x); // создание узла
		int nl = n / 2; // нахождение кол-ва элементов в левой ветке
		int nr = n - nl - 1; // нахождение кол-ва элементов в правой ветке
		create(tr->left, nl); // рекурсивный вызов для левой ветки
		create(tr->right, nr); // рекурсивный вызов для левой правой
	}
}

void preorder(tree* tr) { // функция прямого обхода
	if (tr) { // если tr не ноль
		cout << tr->dual << " "; // вывод значения
		preorder(tr->left);  // рекурсивный вызов по левой ветке
		preorder(tr->right); // рекурсивный вызов по правой ветке
	}
}

void find(tree* tr, int x, tree*& res) { // функция поиска 
	 if (tr) { // если узел не ноль
		 if (tr-> dual == x) { // если значение узла соответствует искомому элементу 
			 res = tr; // то элемент найден 
		}
		else { // иначе 
			 find(tr->left, x, res); // рекурсивный вызов функции для левой ветки 
			 find(tr->right, x, res); // рекурсивный вызов функции для правой ветки 
		}
	}
}

int hight(tree* tr){ // функция нахождения высоты дерева
	int l, r, h = 0; // объявление переменных
	if (tr){ // Если узел не ноль
		l = hight(tr->left); // рекурсивный вызов функции для левой ветки
		r = hight(tr->right); // рекурсивный вызов функции для правой ветки
		h = ((l > r) ? l : r) + 1; // если l > r, то l, иначе r , а потом увеличение на 1
	}
	return h; // возврат найденной высоты
}

int main() {
	setlocale(LC_ALL, "RUS"); // подключение русской раскладки
	int n, x; // объявление переменной 
	cout << "n = "; // вывод на экран
	cin >> n; // ввод n
	cout << "x = "; // вывод на экран
	cin >> x; // ввод x
	tree* tr = NULL; // объявление дерева 
	create(tr, n); // вызов функции заполнения дерева
	preorder(tr);  // прямой обход
	cout << endl;
	tree* ptr = NULL; // объявление дополнительного узла
    find(tr, x, ptr); // функция поиска нужного элемента
	cout << "Высота = " << hight(ptr) - 1 << endl; // вывод значения
	return 0;
}