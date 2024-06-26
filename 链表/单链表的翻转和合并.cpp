#include <iostream>
using myType = int;
struct LNode
{
	myType value;
	struct LNode* next;
};
using LLNode = LNode*;

/*��ʼ��������*/
void create_LNode(LLNode& head)
{
	head = new LNode;
	if (!head) exit(1);
	head->value = INT_MAX;
	head->next = nullptr;
}

/*�������в�������*/
void insert_LNode(LLNode& head,int n)
{
	if (head == nullptr) {
		return;
	}
	LNode* p = nullptr;
	LNode* s = head;/*βָ��*/
	for(int i = 1;i<=n;i++)
	{
		p = new LNode;
		std::cout << "�������" << i << "��value��ֵ:" << std::endl;
		std::cin >> p->value;
		p->next = s->next;
		s->next = p;
		s = p;
	}
}

/*��ӡ�������е�����*/
void print_LNode(LLNode& head)
{
	LNode* p = head->next;
	while (p != nullptr)
	{
		std::cout << p->value << std::endl;
		p = p->next;
	}
}

/*ͷ�巨��ת������*/
void reverse_LNode(LLNode& head)
{
	LNode* p = head->next;
	head->next = nullptr;
	while (p != nullptr)
	{
		LNode* q = p->next;
		p->next=head->next;
		head->next = p;
		p = q;
	}
}

/*��������ת����*/
void reverse_LNode_Second(LLNode& head)
{
	LNode* p = head->next;
	LNode* q = head->next->next;

	while (q != nullptr)
	{
		p->next = q->next;
		q->next=head->next;
		head->next = q;
		q = p->next;
	}
}
/*�ϲ�����������*/
LLNode merge_List(LLNode& head_one, LLNode head_two)
{
	//����һ��������virtual_LNode
	LNode* virtual_LNode = nullptr;
	create_LNode(virtual_LNode);
	//����һ��βָ�룬������������
	LNode* s = virtual_LNode;

	LNode* p = head_one->next;
	LNode* q = head_two->next;

	while (p != nullptr && q != nullptr)
	{
		if (p->value <= q->value)
		{
			s->next = p;
			s = p;
			p = p->next;
		}
		else
		{
			s->next = q;
			s = q;
			q = q->next;
		}
	}
	if (p != nullptr) {
		s->next = p;
	}
	if (q != nullptr) {
		s->next = q;
	}
	return virtual_LNode;
}
/*���㵥����ĳ���*/
inline size_t length_LNode(LLNode head) 
{
	if (head == nullptr || head->next == nullptr) {
		return 0;
	}
	LNode* p = head->next;
	int cnt = 0;
	while (p != nullptr)
	{
		++cnt;
		p = p->next;
	}
	return cnt;
}
/*�����������*/
void sort_List(LLNode& head)
{

}
/*ɾ����������ֵΪvalue�Ľ��*/
void delete_LLNode_Value(LLNode& head, const int value)
{
	
}
/*Ѱ��������м���*/
/*���������Ⱥ�ż������֮�֣���ѭ����������һ��*/

int main()
{
#if 0
	LLNode head = nullptr;
	create_LNode(head);
	insert_LNode(head, 10);
	print_LNode(head);
	reverse_LNode(head);
	std::cout << "ͷ�巨��ת����Ľ������:" << std::endl;
	print_LNode(head);
	reverse_LNode_Second(head);
	std::cout << "��������ת����Ľ������:" << std::endl;
	print_LNode(head);
#endif
#if 0
	LLNode head_one = nullptr;
	LLNode head_two = nullptr;
	create_LNode(head_one);
	create_LNode(head_two);
	std::cout << "�������һ�������ֵ:" << std::endl;
	insert_LNode(head_one, 5);
	std::cout << "������ڶ��������ֵ:" << std::endl;
	insert_LNode(head_two, 10);
	LLNode newLNode = merge_List(head_one, head_two);
	std::cout << "�ϲ��������Ϊ:" << std::endl;
	print_LNode(newLNode);

	std::cout << "�ϲ����������Ϊ:" << length_LNode(newLNode) << std::endl;
#endif
	/*ɾ�������е�value��Ԫ��*/
	LLNode head = nullptr;
	create_LNode(head);
	insert_LNode(head, 10);
	delete_LLNode_Value(head, 10);
	print_LNode(head);
	return 0;
}