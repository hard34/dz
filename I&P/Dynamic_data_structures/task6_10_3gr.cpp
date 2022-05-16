#include <iostream>
using namespace std;

struct list{ 
	int inf; 
	list* next; 
	list* prev;
};

void push(list*& h, list*& t, int x) {
	list* r = new list; 
	r->inf = x; 
	r->next = NULL;
	if (!h && !t){ 
		r->prev = NULL; 
		t = r;
	}
	else {
		h->prev = r;
		r->next = h; 
	}
	h = r; 
}

void print(list* h, list* t) {
	list* p = t; 
	cout << "New list: ";
	while (p){ 
		cout << p->inf << " "; 
		p = p->prev; 
	}
}

void deleteNode(list*& h, list*& t, list* r) { 
	if (r == h && r == t) 
		h = t = NULL;
	else if (r == h){ 
		h = h->next; 
		h->prev = NULL;
	}
	else if (r == t){ 
		t = t->prev; 
		t->next = NULL;
	}
	else { 
		r->next->prev = r->prev;
		r->prev->next = r->next; 
	}
	delete r; 
}

list* find(list* h, list* t, int x) { 
	list* p = h;
	while (p){
		if (p->inf == x) break;
		p = p->next; 
	}
	return p; 
}

int main(){
	setlocale(LC_ALL, "RUS"); 
	list* head = NULL, * tail = NULL; 
	int n = 0, temp = 0, last = 0; 
	cout << "Number of elements: ";
	cin >> n; 
	for (int i = 0; i < n; i++) {
		cout << "Element[" << i << "] = ";
		cin >> temp; 
		push(head, tail, temp);
	}
	last = head->inf; 
	list* ptr = NULL; 
	for (int i = 0; i < n; i++){ 
		ptr = find(head, tail, last);
		if (ptr)
			deleteNode(head, tail, ptr);
		else
			break; 
	}
	print(head, tail);
	return 0;
}