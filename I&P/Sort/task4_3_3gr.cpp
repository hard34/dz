# include <iostream>
# include <fstream>
# include <cstdio>
# include <string>
# include <vector>
# include <algorithm>


using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

vector<vector<int>> create()
{
	int n;
	string count;
	in >> count;
	n = stoi(count);
	vector<vector<int>> matrix;
	for (int i = 0; i < n; i++) {
		vector<int> tempVec;
		for (int j = 0; j < n; j++) {
			string temp;
			in >> temp;
			int t = stoi(temp);
			tempVec.push_back(t);
		}
		matrix.push_back(tempVec);
	}
	return matrix;
}


vector <int> LSDsort(vector <int> a) {
	int ms = 10;
	int maxras = 0, k = 1;
	int n = a.size();   
	for (int i = 0; i < n; i++) {
		maxras = max(maxras, a[i]);
	}
	maxras = log10(maxras) + 1;       
	for (int q = 1; q <= maxras; q++) {
		int temp = 0;  
		vector <int> mas(ms);      
		vector <vector <int> > dop_mas(n);        
		for (int i = 0; i < n; i++) {
			dop_mas[i].resize(ms);
		}

		for (int i = 0; i < n; i++) {
			int x = a[i] / k % 10;    
			dop_mas[mas[x]][x] = a[i];  
			mas[x] += 1;
		}
		for (int i = 0; i < ms; i++) {
			for (int j = 0; j < mas[i]; j++) {   
				a[temp] = dop_mas[j][i];
				temp += 1;
			}
		}
		k *= 10;
	}
	return a;
}

vector<vector<int>> transp(vector<vector<int>> matrix) {   
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix.size(); j++) {
			if ((matrix[i][j] != matrix[j][i]) && j >= i) {
				matrix[i][j] = matrix[i][j] xor matrix[j][i]; 
				matrix[j][i] = matrix[i][j] xor matrix[j][i]; 
				matrix[i][j] = matrix[i][j] xor matrix[j][i]; 
			}
		}

	}
	return matrix;
}


int main() {
	setlocale(LC_ALL, "RUS");  
	vector<vector <int>> numbers = create();
	int i = 0;
	numbers = transp(numbers);
	for (int i = 0; i < numbers.size(); i++)
	{
		numbers[i] = LSDsort(numbers[i]);
	}


	numbers = transp(numbers);
	for (int i = 0; i < numbers.size(); i++) {
		for (int j = 0; j < numbers.size(); j++) {
			cout << numbers[i][j] << ' ';
		}
		cout << "\n";
	}
	system("pause");  

}