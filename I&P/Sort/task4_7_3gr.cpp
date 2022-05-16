# include <iostream>
# include <fstream>
# include <cstdio>
# include <string>
# include <vector>
# include <algorithm>


using namespace std;

ifstream in("input_task4.txt");  
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
			if (i % 2 != 0) {
				t *= (-1);
			}
			tempVec.push_back(t);
		}
		matrix.push_back(tempVec);
	}
	return matrix;
}

vector<int> shellSort(vector<int> a) {
	int step;
	int temp = 1;
	while (pow(3, temp) - 1 < a.size() - 1) {
		temp++;
	}
	step = pow(3, temp) - 1;
	while (step > 0) {
		for (int i = 0; i < a.size() - step; i++) {
			int j = i;
			while ((j >= 0) && (a[j] > a[j + step])) {
				swap(a[j], a[j + step]);
				j -= step;
			}
		}
		temp--;
		step = pow(3, temp) - 1;
		if (temp == 0) {
			step++;
		}
	}
	return a;
}

int main() {
	setlocale(LC_ALL, "RUS");
	vector <vector<int>> matrix = create();
	for (int i = 0; i < matrix.size(); i++) {
		matrix[i] = shellSort(matrix[i]);
	}
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix.size(); j++) {
			if (i % 2 != 0) {
				matrix[i][j] *= (-1);
			}
			cout << matrix[i][j] << ' ';
		}
		cout << "\n";
	}
	system("pause");
	return 0;
}