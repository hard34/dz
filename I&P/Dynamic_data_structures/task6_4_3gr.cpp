#include<iostream>
using namespace std;

struct list {
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
		h = r; 
	}
	else {
		t->next = r; 
		r->prev = t; 
	}
	t = r; 
}

void print(list* h, list* t) {
	list* p = h; 
	cout << "New list: ";
	while (p){ 
		cout << p->inf << " "; 
		p = p->next; 
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
	int n = 0, temp = 0; 
	cout << "Number of elements: ";
	cin >> n; 
	for (int i = 0; i < n; i++){ 
		cout << "Elements [" << i << "] = ";
		cin >> temp; 
		push(head, tail, temp);
	}
	list* ptr = head; 
	list* next; 
	while (ptr != NULL) { 
		next = ptr->next; 
		if (ptr->inf % 2 == 0) 
			deleteNode(head, tail, ptr); 
		ptr = next; 
	}
	print(head, tail); 
	return 0;
}