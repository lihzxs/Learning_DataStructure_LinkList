#include <iostream>
/*定义双向链表的结构体*/
struct LNode {
	int value;
	struct LNode* next;
	struct LNode* prior;
};
/*定义类型的别名*/
using LLNode = LNode;
using PLNode = LNode*;

/*初始化双向链表*/
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

/*尾插法向双向链表插入n个数据*/
void insert_LLNode(PLNode&head,const int n)
{
	if (head == nullptr) {
		return;
	}
	LLNode* p = nullptr;
	LLNode* s = head;   /*尾指针*/
	for (int i = 1; i <= n; i++)
	{
		std::cout << "请输入第" << i << "个结点的value值:" << std::endl;
		p = new LLNode;
		std::cin >> p->value;
		s->next = p;
		p->prior = s;
		s = p;
	}
	s->next = head;
	head->prior = s;
}

/*打印链表的数据*/
void print_LNode(PLNode& head)
{
	LLNode* p = head->next;
	while (p != head)
	{
		std::cout << "value = " << p->value << std::endl;
		p = p->next;
	}
}

/*判断链表是否有环?和判断哪个是入环结点*/
/*r表示传出参数    即查找的入环结点   */
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
	/*测试双向链表的构建和打印*/
	create_Bin_LNode(head);
	insert_LLNode(head, 10);
	print_LNode(head);
	/*测试是否是有环链表和查找入环结点*/
	PLNode r = nullptr;
	std::cout << std::boolalpha <<is_Huan_LNode(head, r)<<std::endl;
	std::cout << "入环结点的value值为:" << r->value << std::endl;
	return 0;
}