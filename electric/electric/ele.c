
#include "sq.h"  
void addata(sys* ps)//��������
{
    datatype info;
    printf("�������û���\n");
    scanf("%s", info.usname);
    printf("�����뵥��\n");
    scanf("%lf", &info.uprice);
    printf("�������õ���\n");
    scanf("%lf", &info.pwercon);
    info.price = info.pwercon * info.uprice;
    espushback(ps, info);
}

void datadel(sys *ps)//ɾ������
{
    char name[NAMEMAX];
    printf("������Ҫɾ�����û���:\n");
    scanf("%s", name);

    int find = FindByName(ps, name);
    if (find < 0)
    {
        printf("Ҫɾ�����û������ݲ����ڣ�\n");
        return;
    }
    SLErase(ps, find);
    printf("ɾ���ɹ���\n");
}

void reversedata(sys* ps)//����ָ������
{
    char name[NAMEMAX];
    printf("������Ҫ���ĵ��û���:\n");
    scanf("%s", name);
    int find = FindByName(ps, name);
    if (find < 0)
    {
        printf("Ҫɾ�����û������ݲ����ڣ�\n");
        return;
    }
            printf("��������ĺ���û���\n");
            scanf("%s", ps->arr[find].usname);

            printf("��������ĺ�ĵ���\n");
            scanf("%lf", &ps->arr[find].uprice);
           
            printf("��������ĺ���õ���\n");
            scanf("%lf", &ps->arr[find].pwercon);
            
            ps->arr[find].price = ps->arr[find].uprice * ps->arr[find].pwercon;
            printf("�������\n");
            return ;
       
    
    
}
void printdata(sys* ps)//��ӡ����
{
    for (int i = 0; i < ps->size; i++)
    {
        printf("�û���   ����    �õ���    �ܼ�\n");
        printf("%s       ", ps->arr[i].usname);
        printf("%.2lf    ", ps->arr[i].uprice);
        printf("%.2lf    ", ps->arr[i].pwercon);
        printf("%.2lf ", ps->arr[i].price);
        printf("\n");
    }
}
void findata(sys* ps)//����ָ������
{
    char name[NAMEMAX];
    printf("������Ҫ���ҵ��û���:\n");
    scanf("%s", name);

    int find = FindByName(ps, name);
    if (find < 0)
    {
        printf("Ҫ���ҵ��û������ݲ����ڣ�\n");
        return;
    }
            printf("�ҵ���\n");
            printf("\n");
            printf("�û���   ����    �õ���    �ܼ�\n");
            printf("%s       ", ps->arr[find].usname);
            printf("%.2lf    ", ps->arr[find].uprice);
            printf("%.2lf    ", ps->arr[find].pwercon);
            printf("%.2lf ", ps->arr[find].price);
            printf("\n");
    
}
void DesTroy(datatype* con)
{
    SLDestroy(con);
}