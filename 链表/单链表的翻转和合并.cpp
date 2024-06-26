#include <iostream>
using myType = int;
struct LNode
{
	myType value;
	struct LNode* next;
};
using LLNode = LNode*;

/*初始化单链表*/
void create_LNode(LLNode& head)
{
	head = new LNode;
	if (!head) exit(1);
	head->value = INT_MAX;
	head->next = nullptr;
}

/*向单链表中插入数据*/
void insert_LNode(LLNode& head,int n)
{
	if (head == nullptr) {
		return;
	}
	LNode* p = nullptr;
	LNode* s = head;/*尾指针*/
	for(int i = 1;i<=n;i++)
	{
		p = new LNode;
		std::cout << "请输入第" << i << "个value的值:" << std::endl;
		std::cin >> p->value;
		p->next = s->next;
		s->next = p;
		s = p;
	}
}

/*打印单链表中的数据*/
void print_LNode(LLNode& head)
{
	LNode* p = head->next;
	while (p != nullptr)
	{
		std::cout << p->value << std::endl;
		p = p->next;
	}
}

/*头插法反转单链表*/
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

/*迭代法反转链表*/
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
/*合并两个单链表*/
LLNode merge_List(LLNode& head_one, LLNode head_two)
{
	//定义一个虚拟结点virtual_LNode
	LNode* virtual_LNode = nullptr;
	create_LNode(virtual_LNode);
	//定义一个尾指针，用来穿针引线
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
/*计算单链表的长度*/
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
/*单链表的排序*/
void sort_List(LLNode& head)
{

}
/*删除单链表中值为value的结点*/
void delete_LLNode_Value(LLNode& head, const int value)
{
	
}
/*寻找链表的中间结点*/
/*有奇数长度和偶数长度之分，，循环的条件不一样*/

int main()
{
#if 0
	LLNode head = nullptr;
	create_LNode(head);
	insert_LNode(head, 10);
	print_LNode(head);
	reverse_LNode(head);
	std::cout << "头插法反转链表的结果如下:" << std::endl;
	print_LNode(head);
	reverse_LNode_Second(head);
	std::cout << "迭代法反转链表的结果如下:" << std::endl;
	print_LNode(head);
#endif
#if 0
	LLNode head_one = nullptr;
	LLNode head_two = nullptr;
	create_LNode(head_one);
	create_LNode(head_two);
	std::cout << "请输入第一个链表的值:" << std::endl;
	insert_LNode(head_one, 5);
	std::cout << "请输入第二个链表的值:" << std::endl;
	insert_LNode(head_two, 10);
	LLNode newLNode = merge_List(head_one, head_two);
	std::cout << "合并后的链表为:" << std::endl;
	print_LNode(newLNode);

	std::cout << "合并后的链表长度为:" << length_LNode(newLNode) << std::endl;
#endif
	/*删除链表中的value的元素*/
	LLNode head = nullptr;
	create_LNode(head);
	insert_LNode(head, 10);
	delete_LLNode_Value(head, 10);
	print_LNode(head);
	return 0;
}