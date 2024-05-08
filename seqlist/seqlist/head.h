#include"confere.h"
typedef int SLDataType;
// ��̬˳��� -- ��������
typedef struct SeqList
{
    SLDataType* a;
    int size;     // ��Ч���ݸ���
    int capacity; // �ռ�����
}SL;
void SLInit(SL* ps)//��ʼ��
{
    ps->a = NULL;
    ps->size =ps->capacity =0;
   
}
void SLDestroy(SL* ps)//����
{
    if (ps->a)
    {
        free(ps->a);
    }
    ps->a = NULL;
    ps->size = ps->capacity = 0;
}
void SLPrint(SL s)//��ӡ
{
    for (int i = 0; i < s.size; i++)
    {
        printf("%d ",s.a[i]);
    }
    printf("\n");
}

void SLPushBack(SL* ps, SLDataType x)//β��
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
void SLPopBack(SL* ps)//βɾ
{
    ps->size--;
}
void SLPushFront(SL* ps, SLDataType x)//ͷ��
{
    for (int i = ps->size - 1; i >=0; i--)
    {
        ps->a[i + 1] = ps->a[i];
            
    }
    ps->size++;
    ps->a[0] = x;
}
void SLPopFront(SL* ps)//ͷɾ��
{
    for (int i = 0; i<ps->size; i++)
    {
        ps->a[i-1] = ps->a[i];

    }
    ps->size--;
}
void SLInsert(SL* ps, int pos, SLDataType x)//ָ��λ�ò���
{
    if (pos > ps->size+1 || pos < 1)
    {
        perror("����λ��");
            exit(1);
    }
    for (int i = ps->size-1; i>=pos-1; i--)
    {
        ps->a[i + 1] = ps->a[i];

    }
    ps->a[pos - 1] = x;
    ps->size++;
}
void SLErase(SL* ps, int pos) //ָ��λ��ɾ��
{
    
    if (pos > ps->size  || pos < 1)
    {
        perror("����λ��");
        exit(1);
    }
    for (int i = pos; i<ps->size; i++)
    {
        ps->a[i-1] = ps->a[i];
    }
    ps->size--;
}
int SLFind(SL* ps, SLDataType x)//����
{
    for (int i = 0; i < ps->size; i++)
    {
        if (ps->a[i] == x)
        {
            return i + 1;

        }

    }
    printf("û�ҵ������");
    return 0;
}