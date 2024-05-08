#include"sqlist.h"
void Initsq(sys* ps)
{
    ps->arr = NULL;
    ps->size = ps->capacity = 0;
}

void espushback(sys* ps, datatype x)
{
    if (ps->capacity == ps->size)
    {
        int Newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
        datatype* tmp = (datatype*)realloc(ps->arr, Newcapacity * sizeof(datatype));
        if (tmp == NULL)
        {
            perror("realloc fail");
            exit(1);
        }
        ps->capacity = Newcapacity;
        ps->arr = tmp;
    }
    ps->arr[ps->size++] = x;
}
void SLErase(sys* ps, int pos) //ָ��λ��ɾ��
{

    if (pos > ps->size || pos < 1)
    {
        perror("����λ��");
        exit(1);
    }
    for (int i = pos; i < ps->size; i++)
    {
        ps->arr[i - 1] = ps->arr[i];
    }
    ps->size--;
}
int FindByName(sys* ps, char name[])//����
{
    for (int i = 0; i < ps->size; i++)
    {
        if (strcmp(ps->arr[i].usname, name) == 0)
        {
            //�ҵ���
            return i;
        }
    }
    //û���ҵ�
    return -1;
}
void SLDestroy(sys* ps)
{
    if (ps->arr) //�ȼ���  if(ps->arr != NULL)
    {
        free(ps->arr);
    }
    ps->arr = NULL;
    ps->size = ps->capacity = 0;
}