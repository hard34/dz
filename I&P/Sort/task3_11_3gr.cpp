#include<iostream>
#include<fstream>
#include<string>
#include<vector>
 #include<iomanip>
 using namespace std;


 ifstream in("input.txt");
 ofstream out("output.txt");

 struct date {//дата
	 int dd, mm, yy;
	
};

 struct people {//данные о человеке
	 string Surname; //фамилия
	 date DateOfBirth; //дата рождения
	 int Salary; //зарплата
	
};

 date Str_to_Date(string str) {//из строки в дату
	 date x;
	 string temp = str.substr(0, 2);//день
	 x.dd = atoi(temp.c_str());
	 temp = str.substr(3, 2);//месяц
	 x.mm = atoi(temp.c_str());
	 temp = str.substr(6, 4);//год
	 x.yy = atoi(temp.c_str());
	 return x;
	
}

 vector<people> inFile() {//ввод из файла
	 vector<people> x;
	 people temp;
	 while (in.peek() != EOF) {
		 in >> temp.Surname;//фамилия
		 string tmp;//дата рождения
		 in >> tmp;
		 temp.DateOfBirth = Str_to_Date(tmp);
		 in >> temp.Salary;//зарплата
		 x.push_back(temp);
		
	}
	 return x;
	
}

 void print(people x) {//вывод в файл
	 out << setw(10) << left << x.Surname;//по левому краю, 10 позиций для фамилии
	 if (x.DateOfBirth.dd < 10) out << left << "0" << x.DateOfBirth.dd << ".";//добавляем 0
	 else out << left << x.DateOfBirth.dd << ".";
	 if (x.DateOfBirth.mm < 10) out << "0" << x.DateOfBirth.mm << ".";
		 else out << x.DateOfBirth.mm << ".";
	 out << left << setw(6) << x.DateOfBirth.yy;//на год 6 позиций
	 out << left << setw(10) << x.Salary << endl;//запрлата
	
}

 bool operator < (people a, people b) {//переопределяем оператор < в соотвествии с условием
	 if (a.Salary < b.Salary) return true;
	 return false;
	}

void stupid_sort(vector<people> &x) {//глупая сортировка
	for (int i = 0; i < x.size() - 1;)
		if (x[i + 1] < x[i]) {//не на месте
		swap(x[i], x[i + 1]);//поменяли
	    i = 0;//возвращаемя в начало
		
	}
	else i++;//идем дальше
	
}

int main() {
	vector<people> x;
	x = inFile();
	stupid_sort(x);
	for (int i = 0; i < x.size(); i++)
		print(x[i]);
	return 0;
	
}
vector<int> getMax(vector<people>& x)
{
	int mx;
	for (int i = 0; i < x.size() - 1; i++) {
		mx = x[0];
		if (mx < x[i])
			mx = x[i];
	}
	return mx;
}

// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(vector<people>& x, int n, int exp)
{
	int output[n]; // output array
	int i, count[10] = { 0 };

	// Store count of occurrences in count[]
	for (i = 0; i < n; i++)
		count[(x[i] / exp) % 10]++;

	// Change count[i] so that count[i] now contains actual
	//  position of this digit in output[]
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// Build the output array
	for (i = n - 1; i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	// Copy the output array to arr[], so that arr[] now
	// contains sorted numbers according to current digit
	for (i = 0; i < n; i++)
		arr[i] = output[i];
}

// The main function to that sorts arr[] of size n using
// Radix Sort
void radixsort(vector<people>& x, int n)
{
	// Find the maximum number to know number of digits
	int m = getMax(x, n);

	// Do counting sort for every digit. Note that instead
	// of passing digit number, exp is passed. exp is 10^i
	// where i is current digit number
	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(x, n, exp);
}