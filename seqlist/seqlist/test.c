#include"head.h"
int main()
{
	SL L;
	SLInit(&L);
	SLPushBack(&L, 1);
	SLPushBack(&L, 2);
	SLPushBack(&L, 3);
	SLPushBack(&L, 4);
	//SLPopBack(&L);
	//SLPushFront(&L, 5);
	//SLPopFront(&L);
	//SLInsert(&L, 2, 6);
	//SLDestroy(&L);
	//SLErase(&L, 3);
	SLPrint(L);
	//int z=SLFind(&L, 3);
	//if(z!=0)
	//printf("此数的位置是%d", z);
	
	
}