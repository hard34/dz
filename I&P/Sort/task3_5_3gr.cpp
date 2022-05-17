#include <string> //Библиотека для работы со строками
#include <iostream> //Библиотека потока ввода-вывода данных
#include <vector> //Библиотека для работы с вектором
#include <cmath> //Библиотека для работы с математическими функциями
#include <algorithm> //Библиотека для работы с алгоритмами
#include <cstdlib> //Библиотека для работы с динамической памятью
#include <ctime> //Возвращает указатель на строку следующего формата
#include <fstream> //Бибилотека для работы с файлами
#include <iomanip> //Библиотека для работы с манипуляторами

using namespace std; //Пространство имен std

struct date { //Создаем структуру
    int dd, mm, yy; //Указываем тип
};

struct person { //Создаем структуру
    string surname; //Фамилия
    string doljnost; //Должность
    date dt; //Дата
    int staj; //Стаж работы
    int salary; //Зарплата
};

bool operator < (person a, person b) { //Сортировка по должности
    if (a.doljnost < b.doljnost) 
        return true;
    else 
        return false;
}

bool operator > (person a, person b) { //Сортировка по должности
    if (a.doljnost > b.doljnost) 
        return true;
    else 
        return false;
}

void print(vector <person>& v) { //Выдача результата
    ofstream out;
    out.open("output1.txt");
    for (int i = 0; i < v.size(); i++) {
    out « left « v[i].surname;
    out « left « " " « v[i].doljnost;
    if (v[i].dt.dd < 10) out « left « " " « "0" « v[i].dt.dd « "."; //Если условие выполняется то выдаем
    else out « " " « v[i].dt.dd « ".";
    if (v[i].dt.mm < 10) out « "0" « v[i].dt.mm « "."; //Если условие выполняется то выдаем
    else out « v[i].dt.mm « ".";
    out « left « v[i].dt.yy; //Вывод
    out « left « " " « v[i].staj; //Вывод
    out « left « " " « v[i].salary « endl; //Вывод
    }
}

void heapify(vector <person>& v, int n, int i){
    int largest = i; // Инициализировать наибольший
    int l = 2 * i + 1; // левое = 2*i + 1
    int r = 2 * i + 2; // правое = 2*i + 2
    if (l < n && v[l] > v[largest]) // Если левый ребенок больше корня
        largest = l;
    if (r < n && v[r] > v[largest]) // Если правый ребенок больше самого большого на данный момент
        largest = r;
    if (largest != i) { // Если самый большой не корень
        swap(v[i], v[largest]);
        heapify(v, n, largest); // Рекурсивно увеличиваем затронутое поддерево
    }
}

void heapSort(vector <person>& v, int n){
    for (int i = n / 2 - 1; i >= 0; i--) //Построить кучу(переупорядочить массив)
        heapify(v, n, i);
    for (int i = n - 1; i >= 0; i--) { // По одному извлекаем элемент из кучи
        swap(v[0], v[i]); // Переместить текущий корень в конец
        heapify(v, i, 0); // вызов max heapify для перегруженного
    }
}
int main(){
    ifstream in;
    in.open("input1.txt"); //Открываем файл
    vector <person> v;
    while (!in.eof()) { //Пока условие выполняется выполняем цикл
        person p;
        in » p.surname » p.doljnost » p.dt.dd; //Считываем фамилию должность дату
        in.ignore(1, '.');
        in » p.dt.mm;
        in.ignore(1);
        in » p.dt.yy » p.staj » p.salary; //Считываем дату стаж и зарплату
        v.push_back(p);
    }
    heapSort(v, v.size());
    print(v); //Вывод
    return 0;
}