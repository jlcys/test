
#include"quenen.h"
// ��ʼ������ 
void QueueInit(Queue* q)
{
	q->_front = q->_rear = NULL;
	q->size = 0;

}

// ��β����� 
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
// ��ͷ������ 
void QueuePop(Queue* q)
{
	assert(q);
	Queue* next = q->_front->_next;
	free(q->_front);
	q->_front = next;
	q->size--;
}
// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q)
{
	assert(q);
	return q->_front->_data;
}
// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q)
{
	assert(q);
	return q->_rear->_data;
}
// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q)
{
	return q->size;
}
// �������Ƿ�Ϊ��
bool QueueEmpty(Queue* q)
{
	if (q->size == 0)
	{
		return true;
	}
	return false;
}
// ���ٶ��� 
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