#include"confere.h"
typedef int SLDataType;
// 动态顺序表 -- 按需申请
typedef struct SeqList
{
    SLDataType* a;
    int size;     // 有效数据个数
    int capacity; // 空间容量
}SL;
void SLInit(SL* ps)//初始化
{
    ps->a = NULL;
    ps->size =ps->capacity =0;
   
}
void SLDestroy(SL* ps)//销毁
{
    if (ps->a)
    {
        free(ps->a);
    }
    ps->a = NULL;
    ps->size = ps->capacity = 0;
}
void SLPrint(SL s)//打印
{
    for (int i = 0; i < s.size; i++)
    {
        printf("%d ",s.a[i]);
    }
    printf("\n");
}

void SLPushBack(SL* ps, SLDataType x)//尾插
{
    if (ps->capacity == ps->size)
    {
        SLDataType Newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
        SLDataType tmp = (SLDataType*)realloc(ps->a, Newcapacity * sizeof(SLDataType));
       if (tmp == NULL)
        {
           perror("realloc fail");
           exit(1);
        }
       ps->capacity = Newcapacity;
       ps->a = tmp;
    }
  
    ps->a[ps->size++] = x;

}
void SLPopBack(SL* ps)//尾删
{
    ps->size--;
}
void SLPushFront(SL* ps, SLDataType x)//头插
{
    for (int i = ps->size - 1; i >=0; i--)
    {
        ps->a[i + 1] = ps->a[i];
            
    }
    ps->size++;
    ps->a[0] = x;
}
void SLPopFront(SL* ps)//头删；
{
    for (int i = 0; i<ps->size; i++)
    {
        ps->a[i-1] = ps->a[i];

    }
    ps->size--;
}
void SLInsert(SL* ps, int pos, SLDataType x)//指定位置插入
{
    if (pos > ps->size+1 || pos < 1)
    {
        perror("超出位置");
            exit(1);
    }
    for (int i = ps->size-1; i>=pos-1; i--)
    {
        ps->a[i + 1] = ps->a[i];

    }
    ps->a[pos - 1] = x;
    ps->size++;
}
void SLErase(SL* ps, int pos) //指定位置删除
{
    
    if (pos > ps->size  || pos < 1)
    {
        perror("超出位置");
        exit(1);
    }
    for (int i = pos; i<ps->size; i++)
    {
        ps->a[i-1] = ps->a[i];
    }
    ps->size--;
}
int SLFind(SL* ps, SLDataType x)//查找
{
    for (int i = 0; i < ps->size; i++)
    {
        if (ps->a[i] == x)
        {
            return i + 1;

        }

    }
    printf("没找到这个数");
    return 0;
}