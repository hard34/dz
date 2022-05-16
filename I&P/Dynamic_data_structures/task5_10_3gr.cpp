#include <iostream> 
using namespace std;

struct stack {
	int inf; 
	stack* next; 
};

void push(stack*& NEXT, const int INF) { 
	stack* r = new stack;  
	r->inf = INF; 
	r->next = NEXT;
	NEXT = r; 
}

int pop(stack*& NEXT) {
	int temp = NEXT->inf; 
	stack* r = NEXT;
	NEXT = NEXT->next; 
	delete r; 
	return temp; 

int countNumbers(int x){ 
	int sum = 0; 
	while (x > 0){
		sum += x % 10; 
		x /= 10; 
	}
	return sum; 
}


int main() {
	setlocale(LC_ALL, "RUS");
	int n, temp = 0, sum = 0, max = 0, tempc; 
	bool flag = false; 
	stack* st = NULL; 
	stack* stb = NULL; 
	cout << "n =  "; 
	cin >> n; 
	for (int i = 0; i < n; i++) { 
		cout << "a[" << i << "]: ";
		cin >> temp; 
		push(st, temp); 

	for (int i = 0; i < n; i++) { 
		temp = pop(st); 
		tempc = countNumbers(temp);
		if (max < tempc) 
			max = tempc; 
		push(stb, temp); 
	}

	cout << "New stack: ";
	for (int i = 0; i < n; i++) { 
		temp = pop(stb);
		tempc = countNumbers(temp); 
		if (tempc == max) 
			push(st, temp); 
		else {
			cout << temp << " "; 
		}
	}
	return 0; 
}