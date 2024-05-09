
#include"quenen.h"
// 初始化队列 
void QueueInit(Queue* q)
{
	q->_front = q->_rear = NULL;
	q->size = 0;

}

// 队尾入队列 
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	QNode* mid = (QNode*)malloc(sizeof(QNode));
	if (mid == NULL)
	{
		perror("error");
	}
	mid->_data = data;
	mid->_next = NULL;
	if (q->_rear == NULL)
	{
		q->_front = q->_rear = mid;
	}
	else
	{
		q->_rear ->_next= mid;
		q->_rear = q->_rear->_next;
	}
	q->size++;
}
// 队头出队列 
void QueuePop(Queue* q)
{
	assert(q);
	Queue* next = q->_front->_next;
	free(q->_front);
	q->_front = next;
	q->size--;
}
// 获取队列头部元素 
QDataType QueueFront(Queue* q)
{
	assert(q);
	return q->_front->_data;
}
// 获取队列队尾元素 
QDataType QueueBack(Queue* q)
{
	assert(q);
	return q->_rear->_data;
}
// 获取队列中有效元素个数 
int QueueSize(Queue* q)
{
	return q->size;
}
// 检测队列是否为空
bool QueueEmpty(Queue* q)
{
	if (q->size == 0)
	{
		return true;
	}
	return false;
}
// 销毁队列 
void QueueDestroy(Queue* q)
{
	assert(q);
	Queue* cur = q->_front;
	while (cur)
	{
		q->_front = q->_front->_next;
		free(cur);
		cur = q->_front;

	}
	q->_front = q->_rear = NULL;
	q->size = 0;
}