#include <iostream>
using namespace std;
typedef int ElemType;
typedef struct Binary_Tree
{
	ElemType value;
	struct Binary_Tree* next;
	struct Binary_Tree* priot;
}Binary_Node,*Binary_Node_Point;
/*����ͷ���*/
void create_Head_Node(Binary_Node_Point& head_node)
{
	if (head_node != NULL) return;
	else
	{
		head_node = new Binary_Node;
		head_node->next = head_node;
		head_node->value = -111111111;
		head_node->priot = head_node;
	}
}
void print_Binary_Node(Binary_Node_Point head_node)
{
	if (head_node == NULL || head_node->next == NULL)
	{
		return;
	}
	else
	{
		Binary_Node* temp = head_node->next;
		while (temp != head_node)
		{
			cout << temp->value << " ";
			temp = temp->next;
		}
		cout << endl;
	}
}
/*��ȡ˫������ı�*/
int get_Binary_Node_Length(Binary_Node_Point head_node)
{
	if (head_node->next == NULL || head_node == NULL) return 0;
	int cnt = 0;
	Binary_Node* temp = head_node->next;
	while (temp != head_node)
	{
		cnt++;
		temp->next;
	}
	return cnt;
}
/*�ڵ�indexλ�ò���ֵΪvalue�Ľ��*/
void insert_Index_Node(Binary_Node_Point &head_node,int index,const ElemType value)
{
	
}
/*ɾ��indexλ�õĽ��*/
void delete_Index_Node(Binary_Node_Point& head_node, int index)
{
	int len = get_Binary_Node_Length(head_node);
	//�ж�ɾ����λ��
	if (index > len || index <= 0)   //�������len ����С�ڵ���0��ɾ��λ�ò�����Ҫ��
	{
		return;
	}
	int cnt = 1;
	Binary_Node_Point temp = head_node->next;
	while (cnt < index)
	{
		cnt++;
		temp = temp->next;
	}
	Binary_Node_Point q = temp;
	temp -> priot -> next = temp -> next;
	temp -> next -> priot = temp -> priot;
	delete q;
	q = NULL;
}
int main()
{
	Binary_Node_Point head_node = NULL;
	create_Head_Node(head_node);
	int n = 10;
	while (n--)
	{
		int choose,index,value;
		cin >> choose;
		if (choose == 1)
		{
			cout << "˫������ı�Ϊ:" << get_Binary_Node_Length(head_node) << endl;
		}
		else if (choose == 2)
		{
			cout << "������Ҫ����Ԫ�ص�λ��:" << endl;
			cin >> index;
			cout << "���������Ԫ�ص�ֵ:" << endl;
			cin >> value;
			insert_Index_Node(head_node, index, value);
		}
		else
			print_Binary_Node(head_node);
	}
	return 0;
}