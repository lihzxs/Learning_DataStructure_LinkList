#include <iostream>
typedef struct Stack
{
	struct Stack* next;
	int Value;
}Stack,*Stack_Point;

void create_Stack(Stack_Point& stack)
{
	stack = nullptr;
}

void push_Value(Stack_Point&stack,const int Value)
{
	Stack* node = new Stack;
	if (node == nullptr)
	{
		exit(1);
	}
	node->Value = Value;
	node->next = stack;
	stack = node;
}

bool empty(Stack_Point stack) noexcept
{
	return stack == nullptr;
}

int getTop(Stack_Point stack) noexcept
{
	if(stack != nullptr)
	return stack->Value;
}

void pop(Stack_Point &stack) noexcept
{
	Stack* temp = stack;
	Stack* p = temp->next;
	delete temp;
	stack = p;
}

void print_Stack(Stack_Point stack)
{
	while (stack != nullptr)
	{
		std::cout << "value = " << stack->Value << std::endl;
		stack = stack->next;
	}
}

void destroy_Stack(Stack_Point& stack)
{
	Stack* temp = stack;
	while (temp != nullptr)
	{
		Stack* next = temp->next;
		delete temp;
		temp = next;
	}
}
int main()
{
	Stack_Point stack;
	create_Stack(stack);
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int len = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < len; i++)
	{
		push_Value(stack, arr[i]);
	}
	print_Stack(stack);

	std::cout << "-----------------------" << std::endl;
	pop(stack);

	print_Stack(stack);

	std::cout << "top = " << getTop(stack) << std::endl;

	std::cout << "Õ»ÊÇ·ñÎª¿Õ:"<<std::boolalpha << empty(stack) << std::endl;
	destroy_Stack(stack);
	return 0;
}