#include <iostream>
#include <climits>
/*
	ʵ��˫��ѭ������
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

//�����ӡ˫��ѭ������
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

//��indexλ�ò���һ���µĽ��
void insert_Index_Node(List& list, const int index,const int value)
{
	Binary_List_Point p = list.front->next;
	int cnt = 1;
	while (p != list.front && cnt < index)
	{
		cnt++;
		p = p->next;
	}
	if (cnt < index)  //����ĳ��ȱȱ���Ҫ��
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
	else   //����λ�ñȱ���Ҫ�󣬣�ֱ�ӵ���push_Value����
	{
		push_Value(list, value);
	}
}

//ɾ����indexλ�õĽ��
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
	if (p == list.back)  //��ǰɾ���������һ�����
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

//�޸ĵ�indexλ�õ�ֵ
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

//�ж������Ƿ�Ϊ��
bool is_Empty(List list) noexcept
{
	return list.front == list.back;
}

//��ȡ����ĵ�һ��Ԫ��
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

//��ȡ��������һ��Ԫ��
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

//���ٳ���ͷ���֮��Ľ��
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

	//AI�Ż���,,//ԭ����ͷָ��Ҳ��Ҫ�޸�
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
	
	delete_Index_Node(list, 10);  //����ɾ�����һ������Ƿ�ɹ�
	print_List(list);
	std::cout << "front->value = " << list.back->next->value << std::endl;
	
	//���Բ������λ�ã���
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
		std::cout << "������Ҫ�޸ĵ��±�:" << std::endl;
		std::cin >> index;
		int value;
		std::cout << "������Ҫ�޸ĵ�ֵ:" << std::endl;
		std::cin >> value;
		modify_Index_Node(list, index, value);
		print_List(list);
	}
#endif
	std::cout << "front = " << get_Front(list) << std::endl;
	std::cout << "back = " << get_Back(list) << std::endl;
	std::cout << std::boolalpha << "��ǰ�����Ƿ�Ϊ��:" << is_Empty(list) << std::endl;
	destroy_List(list);  //����֮������Ϊ�գ�����ʾ���ٳɹ�
	std::cout << std::boolalpha << "��ǰ�����Ƿ�Ϊ��:" << is_Empty(list) << std::endl;
	return 0;
}