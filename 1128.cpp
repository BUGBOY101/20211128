#define	_CRT_SECURE_NO_WARNINGS 1
//Á´Õ»
#include<iostream>
using namespace std;
typedef int Selemtype;
typedef struct SNode {
	Selemtype data;
	struct SNode* next;
}SNode,*LinkStack;
void InitStack(LinkStack&S) {
	S = new SNode;
	if (!S) {
		cout << "ÄÚ´æ·ÖÅäÊ§°Ü" << endl;
		exit(-1);
	}
	else {
		S->next = NULL;
		S->data = 0;
	}
}

void Push(LinkStack& S, Selemtype e) {
	LinkStack p;
	p = new SNode;
	p->data = e;
	p->next = S->next;
	S->next = p;
}

void Pop(LinkStack& S, Selemtype& e) {
	LinkStack p = S->next;
	S = p->next;
	e = p->data;
	delete p;
}

void Gettop(LinkStack S, Selemtype& e) {
	e = S->next->data;
}

int main() {
	LinkStack S;
	InitStack(S);
	Push(S, 1);
	Push(S, 2);
	int e;
	Gettop(S, e);
	cout << e << endl;
	Pop(S, e);
	cout << e << endl;
}