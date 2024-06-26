#include <iostream>
#include <climits>    //使用 INT_MIN这个宏
typedef struct Queue
{
	struct Queue* next;
	int Value;
}Queue,*Queue_Point;

typedef struct QueueNode
{
	Queue_Point front;
	Queue_Point back;
}QueueNode;

void create_Queue(QueueNode &queue) noexcept
{
	queue.front = new Queue;
	if (queue.front == nullptr)
	{
		exit(1);
	}
	queue.front->next = nullptr;
	queue.front->Value = INT_MIN;
	queue.back = queue.front;
}

void push_Value(QueueNode& queue, const int Value) noexcept
{
	Queue* node = new Queue;
	if (node == nullptr)
	{
		exit(1);
	}
	node->Value = Value;
	node->next = queue.back->next;
	queue.back->next = node;
	queue.back = node;
}

void pop(QueueNode& queue) noexcept
{
	Queue* first = queue.front->next;
	
	if (first != nullptr)
	{
		queue.front->next = first->next;
		/*
			如果当前队列中只有两个元素
			再pop就是空队列
			需要将back指针指向front指针处
		*/
		if (first == queue.back)    
		{
			queue.back = queue.front;
		}
		delete first;
	}
}

//取队头元素
int getTop(QueueNode queue) noexcept
{
	if (queue.front->next != nullptr)
	{
		return queue.front->next->Value;
	}
	else
	{
		return INT_MIN;
	}
}

bool empty(QueueNode queue)
{
	return queue.front == queue.back;
}

void print_Queue(QueueNode queue)
{
	Queue* p = queue.front->next;
	while (p != nullptr)
	{
		std::cout << "value = " << p->Value << std::endl;
		p = p->next;
	}
}

void destroy_Queue(QueueNode& queue)
{
	Queue* first = queue.front;
	while (first != nullptr)
	{
		Queue* next_ = first->next;
		delete first;
		first = next_;
	}
}

int main()
{
	QueueNode queue;
	create_Queue(queue);
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int len = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < len; i++)
	{
		push_Value(queue, arr[i]);
	}
	print_Queue(queue);
	
	std::cout << "---------------------------" << std::endl;

	int cnt = 9;
	while (cnt--)
	{
		pop(queue);
	}
	print_Queue(queue);

	std::cout << "back = " << queue.back->Value << std::endl;
	std::cout << "front = " << queue.front->Value << std::endl;

	std::cout << "empty = " << std::boolalpha << empty(queue) << std::endl;
	
	std::cout << "top = " << getTop(queue) << std::endl;
	destroy_Queue(queue);
	return 0;
}