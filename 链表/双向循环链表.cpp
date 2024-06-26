#include <iostream>
#include <climits>
/*
	实现双向循环链表
*/
typedef struct Binary_List
{
	struct Binary_List* next;
	struct Binary_List* rear;
	int value;
}Binary_List,*Binary_List_Point;
typedef struct List
{
	Binary_List_Point front;
	Binary_List_Point back;
}List;

void create_List(List& list)
{
	list.front = new Binary_List;
	if (list.front == nullptr)
	{
		exit(1);
	}
	list.front->value = INT_MIN;
	list.front->next = list.front;
	list.front->rear = list.front;
	list.back = list.front;
}

void push_Value(List& list, const int value)
{
	Binary_List_Point p = new Binary_List;
	if (p == nullptr)
	{
		exit(1);
	}
	p->value = value;
	p->next = list.front;
	list.front->rear = p;
	list.back->next = p;
	p->rear = list.back;
	list.back = p;
}

void print_List(List list)
{
	Binary_List_Point p = list.front->next;
	while (p != list.front)
	{
		std::cout << p->value << " ";
		p = p->next;
	}
	std::cout << std::endl;
}

//逆序打印双向循环链表
void print_Reverse_List(List list)
{
	Binary_List_Point p = list.back;
	while (p != list.front)
	{
		std::cout << p->value << " ";
		p = p->rear;
	}
	std::cout << std::endl;
}

int get_Length(List list)
{
	int length = 0;
	Binary_List_Point p = list.front->next;
	while (p != list.front)
	{
		length++;
		p = p->next;
	}
	return length;
}

//往index位置插入一个新的结点
void insert_Index_Node(List& list, const int index,const int value)
{
	Binary_List_Point p = list.front->next;
	int cnt = 1;
	while (p != list.front && cnt < index)
	{
		cnt++;
		p = p->next;
	}
	if (cnt < index)  //插入的长度比表长还要大
	{
		return;
	}
	if (cnt <= get_Length(list))
	{
		Binary_List_Point new_Node = new Binary_List;
		if (new_Node == nullptr)
		{
			exit(1);
		}
		new_Node->value = value;
		p->rear->next = new_Node;
		new_Node->rear = p->rear;
		new_Node->next = p;
		p->rear = new_Node;
	}
	else   //插入位置比表长还要大，，直接调用push_Value方法
	{
		push_Value(list, value);
	}
}

//删除第index位置的结点
void delete_Index_Node(List& list, const int index)
{
	Binary_List_Point p = list.front->next;
	int cnt = 1;
	while (p != list.front && cnt < index)
	{
		cnt++;
		p = p->next;
	}
	if (cnt < index)  
	{
		return;
	}
	if (p == list.back)  //当前删除的是最后一个结点
	{
		p->rear->next = list.front;
		list.back = p->rear;
		delete p;
		p = nullptr;
	}
	else
	{
		p->rear->next = p->next;
		p->next->rear = p->rear;
		delete p;
		p = nullptr;
	}
}

//修改第index位置的值
void modify_Index_Node(List& list, const int index,const int value)
{
	if (index == -1)
	{
		return;
	}
	Binary_List_Point p = list.front->next;
	int cnt = 1;
	while (cnt < index && p != list.front)
	{
		p = p->next;
		cnt++;
	}
	if (cnt < index)
	{
		return;
	}
	p->value = value;
}

//判断链表是否为空
bool is_Empty(List list) noexcept
{
	return list.front == list.back;
}

//获取链表的第一个元素
int get_Front(List list) noexcept
{
	if (!is_Empty(list))
	{
		return list.front->next->value;
	}
	else
	{
		return INT_MIN;
	}
}

//获取链表的最后一个元素
int get_Back(List list) noexcept
{
	if (!is_Empty(list))
	{
		return list.back->value;
	}
	else
	{
		return INT_MIN;
	}
}

//销毁除了头结点之外的结点
void destroy_List(List& list)
{
	Binary_List_Point p = list.front->next;
	while (p != list.front)
	{
		Binary_List_Point temp = p->next;
		delete p;
		p = temp;
	}
	list.back = list.front;

	//AI优化的,,//原来的头指针也需要修改
	list.front->next = list.front;
	list.front->rear = list.front;
	
}

int main()
{
	List list;
	create_List(list);
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int len = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < len; i++)
	{
		push_Value(list, arr[i]);
	}
	print_List(list);
	print_Reverse_List(list);

	std::cout << "length = " << get_Length(list) << std::endl;
	
	delete_Index_Node(list, 10);  //测试删除最后一个结点是否成功
	print_List(list);
	std::cout << "front->value = " << list.back->next->value << std::endl;
	
	//测试插入结点的位置，，
	insert_Index_Node(list, 1, 100);
	print_List(list);

	insert_Index_Node(list, 10, 1000);
	print_List(list);

	insert_Index_Node(list, 12, 10000);
	print_List(list);

	print_Reverse_List(list);
#if 0
	int index = -1;
	while (true)
	{
		std::cout << "请输入要修改的下标:" << std::endl;
		std::cin >> index;
		int value;
		std::cout << "请输入要修改的值:" << std::endl;
		std::cin >> value;
		modify_Index_Node(list, index, value);
		print_List(list);
	}
#endif
	std::cout << "front = " << get_Front(list) << std::endl;
	std::cout << "back = " << get_Back(list) << std::endl;
	std::cout << std::boolalpha << "当前链表是否为空:" << is_Empty(list) << std::endl;
	destroy_List(list);  //销毁之后链表为空，，表示销毁成功
	std::cout << std::boolalpha << "当前链表是否为空:" << is_Empty(list) << std::endl;
	return 0;
}