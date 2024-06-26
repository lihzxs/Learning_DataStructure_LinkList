#include <iostream>
#include <limits.h>
typedef struct Binary_List
{
	struct Binary_List* next;
	struct Binary_List* rear;
	int value;
}Binary_List,*Binary_List_Point;

typedef struct Binary_Node
{
	Binary_List_Point front;  //头指针
	Binary_List_Point back;   //尾指针
}Binary_Node;

void create_Binary_List(Binary_Node& node)
{
	node.front = new Binary_List;
	if (node.front == nullptr)
	{
		exit(1);
	}
	node.front->next = nullptr;
	node.front->rear = nullptr;
	node.front->value = INT_MIN;

	node.back = node.front;
}

void push_Node(Binary_Node &node,const int Value)
{
	Binary_List* p = new Binary_List;
	if (p == nullptr)
	{
		exit(1);
	}
	p->value = Value;
	p->next = node.back->next;
	p->rear = node.back;
	node.back->next = p;
	node.back = p;
}

int get_Length(Binary_Node node)
{
	Binary_List* p = node.front->next;
	int size = 0;
	while (p != 0)
	{
		size++;
		p = p->next;
	}
	return size;
}

void print_Binary_Node(Binary_Node node)
{
	Binary_List* p = node.front->next;
	while (p != nullptr)
	{
		std::cout << "value = " << p->value << std::endl;
		p = p->next;
	}
}

//逆序输出链表
void reverse_Print_Node(Binary_Node node)
{
	Binary_List* p = node.back;

	while (p != nullptr && p->value != INT_MIN)
	{
		std::cout << "reverse value = " << p->value << std::endl;
		p = p->rear;
	}
}
void destroy_Binary_Node(Binary_Node& node)
{
	Binary_List* p = node.front->next;
	while (p != nullptr)
	{
		Binary_List* q = p->next;
		delete p;
		p = q;
	}
}

//双向链表的插入
void insert_Value(Binary_Node& node, const int index,const int Value)
{
	Binary_List* p = node.front->next;
	int i = 1;
	while (i < index && p != nullptr)
	{
		p = p->next;
	}
	if (i < index)    //也就是p == nullptr
	{
		return;
	}
	Binary_List* q = new Binary_List;
	q->value = Value;
	p->rear->next = q;
	q->rear = p->rear;
	q->next = p;
	p->rear = q;
}

//删除第一个值为Value的结点
void delete_Value(Binary_Node& node, const int Value)
{
	Binary_List* p = node.front->next;
	
	while (p != nullptr && p->value != Value)
	{
		p = p->next;
	}
	if (p == nullptr)   //没有与Value相同的值
	{
		return;
	}
	Binary_List* temp = p;
	p->rear->next = p->next;
	p->next->rear = p->rear;
	delete temp;
}
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	Binary_Node node;
	create_Binary_List(node);
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		push_Node(node, arr[i]);
	}

	std::cout << get_Length(node) << std::endl;
	print_Binary_Node(node);
	std::cout << "-----------------------------" << std::endl;
	
	insert_Value(node, 1, 100);
	print_Binary_Node(node);

	std::cout << "---------------------------" << std::endl;

	delete_Value(node, 100);
	print_Binary_Node(node);

	destroy_Binary_Node(node);
	return 0;
}