#include <iostream>
/*����˫������Ľṹ��*/
struct LNode {
	int value;
	struct LNode* next;
	struct LNode* prior;
};
/*�������͵ı���*/
using LLNode = LNode;
using PLNode = LNode*;

/*��ʼ��˫������*/
void create_Bin_LNode(PLNode& head)
{
	head = new LLNode;
	if (!head) {
		exit(1);
	}
	head->value = INT_MAX;
	head->next = nullptr;
	head->prior = nullptr;
}

/*β�巨��˫���������n������*/
void insert_LLNode(PLNode&head,const int n)
{
	if (head == nullptr) {
		return;
	}
	LLNode* p = nullptr;
	LLNode* s = head;   /*βָ��*/
	for (int i = 1; i <= n; i++)
	{
		std::cout << "�������" << i << "������valueֵ:" << std::endl;
		p = new LLNode;
		std::cin >> p->value;
		s->next = p;
		p->prior = s;
		s = p;
	}
	s->next = head;
	head->prior = s;
}

/*��ӡ���������*/
void print_LNode(PLNode& head)
{
	LLNode* p = head->next;
	while (p != head)
	{
		std::cout << "value = " << p->value << std::endl;
		p = p->next;
	}
}

/*�ж������Ƿ��л�?���ж��ĸ����뻷���*/
/*r��ʾ��������    �����ҵ��뻷���   */
bool is_Huan_LNode(PLNode& head,PLNode &r)
{
	LLNode* first = head;
	LLNode* second = head;
	bool flag = false;
	first = first->next;
	second = second->next->next;
	if (first == second) {
		flag == true;
	}
	else
	{
		while (first != second)
		{
			first = first->next;
			second = second->next->next;
			if (first == second) {
				flag = true;
				break;
			}
		}
	}
	r = head;
	while (r != second)
	{
		r = r->next;
		second = second->next;
	}
	if (r == second) {
		r = second;
	}
	return flag;
}
void delete_PLNode(PLNode& head)
{
	
}
int main()
{
	PLNode head = nullptr;
	/*����˫������Ĺ����ʹ�ӡ*/
	create_Bin_LNode(head);
	insert_LLNode(head, 10);
	print_LNode(head);
	/*�����Ƿ����л�����Ͳ����뻷���*/
	PLNode r = nullptr;
	std::cout << std::boolalpha <<is_Huan_LNode(head, r)<<std::endl;
	std::cout << "�뻷����valueֵΪ:" << r->value << std::endl;
	return 0;
}