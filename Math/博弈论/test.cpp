#pragma warning (disable:4996)
#include<cstdio>
#include<malloc.h>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;

#define Stack_Size 50

typedef struct car {
	string number;
	int time;
	car operator = (const car &tmp) {
		number = tmp->number;//////
		time = tmp->time;
		return *this;
	}
}car;

typedef struct{
	car  elem[Stack_Size];
	int top;
} SeqStack;

void InitStack(SeqStack  *s) {
	s->top = -1;
}

bool IsEmpty(SeqStack  *s) {
	return s->top == -1;
}

bool Push(SeqStack  *s, car e) {
	if (s->top == Stack_Size - 1)
		return false;
	s->top++;
	s->elem[s->top] = e;
	return true;
}

bool Pop(SeqStack  *s, car *e) {
	if (s->top == -1)
		return false;
	*e = s->elem[s->top];
	s->top--;
	return true;
}

int size(SeqStack *s) {
	return s->top + 1;
}

bool IsFull(SeqStack *s) {
	return s->top == Stack_Size - 1;
}

typedef struct Node{
	car data;
	struct Node *next;
} LinkQueueNode;

typedef struct{
	LinkQueueNode * front;
	LinkQueueNode * rear;
} LinkQueue;

void InitQueue(LinkQueue *q) {
	q->front = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	q->rear = q->front;
	q->front->next = NULL;
}

bool IsEmpty(LinkQueue *q) {
	return q->rear == q->front;
}

void EnterQueue(LinkQueue *q, car x) {
	LinkQueueNode *newNode;
	newNode = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	newNode->data = x;//赋值出错
	q->rear->next = newNode;
	q->rear = newNode;
}

bool DeleteQueue(LinkQueue *q, car *x) {
	if (q->front == q->rear)
		return false;
	LinkQueueNode *p = q->front->next;
	if (q->rear == p)
		q->rear = q->front;
	*x = p->data;
	free(p);
	return true;
}

int size(LinkQueue *q) {
	int len = 0;
	LinkQueueNode *p = q->front;
	while (p != q->rear) {
		len++;
		p = p->next;
	}
	return len;
}

SeqStack carPort, backLane;//车库和暂时退车道
LinkQueue shortCut;

void arrive(string number, int time) {
	car tmp;
	tmp.number = number;
	tmp.time = time;
	if (!IsFull(&carPort)) {
		EnterQueue(&shortCut, tmp);
		cout << tmp.number;
		printf("当前停放在便道%d号位\n", size(&shortCut));
	}
	else {
		Push(&carPort, tmp);
		cout << tmp.number;
		printf("当前停放在车库%d号位\n", size(&carPort));
	}
}

void leave(string number, int time) {
	if (IsEmpty(&carPort)) {
		printf("车库已空，请输入正确操作\n");
		return;
	}
	car tmp;
	Pop(&carPort, &tmp);
	bool flag = true;
	while (tmp.number != number) {
		Push(&backLane, tmp);
		if (IsEmpty(&carPort)) {
			printf("车库无该车，请输入正确操作\n");
			flag = false;
		}
		Pop(&carPort, &tmp);
	}
	if (flag) {
		cout << number;
		printf("停放时间为%d，停车费用为%d元\n", time - tmp.time, 5 * (time - tmp.time));
	}
	while (!IsEmpty(&backLane)) {
		Pop(&backLane, &tmp);
		Push(&carPort, tmp);
	}
	if (!IsEmpty(&shortCut)) {
		car q;
		DeleteQueue(&shortCut, &q);
		q.time = time;
		Push(&carPort, q);
	}
}

int main() {
	int flag, time;
	string number;

	InitQueue(&shortCut);
	InitStack(&backLane);
	InitStack(&carPort);

	while (cin >> flag >> number >> time&&flag != -1) {
		if (flag == 0)
			leave(number, time);
		else if (flag == 1)
			arrive(number, time);
		else
			printf("请正确输入\n");
	}
}
