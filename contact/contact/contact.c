
#include "sqlist.h"  
void addata(sys* ps)//��������
{
    datatype info;
    printf("����������\n");
    scanf("%s", info.usname);
    printf("����������\n");
    scanf("%d", &info.age);
    printf("���������\n");
    scanf("%d", &info.tele);
    printf("�������ַ\n");
    scanf("%s", info.site);
    espushback(ps, info);
}

void datadel(sys* ps)//ɾ������
{
    char name[NAMEMAX];
    printf("������Ҫɾ��������:\n");
    scanf("%s", name);

    int find = FindByName(ps, name);
    if (find < 0)
    {
        printf("Ҫɾ�����û����ݲ����ڣ�\n");
        return;
    }
    SLErase(ps, find);
    printf("ɾ���ɹ���\n");
}

void reversedata(sys* ps)//����ָ������
{
    char name[NAMEMAX];
    printf("������Ҫ���ĵ�����:\n");
    scanf("%s", name);
    int find = FindByName(ps, name);
    if (find < 0)
    {
        printf("Ҫɾ�������������ڣ�\n");
        return;
    }
    printf("��������ĺ������\n");
    scanf("%s", ps->arr[find].usname);

    printf("��������ĺ������\n");
    scanf("%d", &ps->arr[find].age);
    printf("��������ĺ�ĺ���\n");
    scanf("%d", &ps->arr[find].tele);
    printf("��������ĺ�ĵ�ַ\n");
    scanf("%s", ps->arr[find].site);

  
    printf("�������\n");
    return;



}
void printdata(sys* ps)//��ӡ����
{
    for (int i = 0; i < ps->size; i++)
    {
        printf("�û���   ����    ����    ��ַ\n");
        printf("%s       ", ps->arr[i].usname);
        printf("%d    ", ps->arr[i].age);
        printf("%d    ", ps->arr[i].tele);
        printf("%s ", ps->arr[i].site);
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
    printf("�û���   ����    ����    ��ַ\n");
    printf("%s    ", ps->arr[find].usname);
    printf("%d    ", ps->arr[find].age);
    printf("%d    ", ps->arr[find].tele);
    printf("%s ", ps->arr[find].site);
    printf("\n");
}
void DesTroy(datatype* con)
{
    SLDestroy(con);
}