#include <iostream> 
using namespace std;

struct stack{
	int inf; 
	stack* next; 
};

void push(stack*& NEXT, const int INF){
	stack* r = new stack; 
	r->inf = INF; 
	r->next = NEXT; 
	NEXT = r; 
}

int pop(stack*& NEXT){ 
	int temp = NEXT->inf; 
	stack* r = NEXT;
	NEXT = NEXT->next; 
	delete r; 
	return temp; 
}

int main(){
	setlocale(LC_ALL, "RUS");
	int n, x, temp; 
	bool flag = false; 
	stack* st = NULL; 
	stack* new_st = NULL; 
	cout << "x = "; 
	cin >> x; 
	cout << "n =  "; 
	cin >> n; 
	for (int i = 0; i < n; i++) { 
		cout << "a[" << i << "]: "; 
		cin >> temp; 
		push(st, temp);
	}

	for (int i = 0; i < n; i++) 
		push(new_st, pop(st)); 

	cout << "New stack: ";
	for (int i = 0; i < n; i++) { 
		temp = pop(new_st); 
		if ((temp % x == 0) && flag == false) 
			flag = true; 
		else
			cout << temp << " "; 
	}
	system("pause");
	return 0;
}