
#include "sqlist.h"  
void addata(sys* ps)//加入数据
{
    datatype info;
    printf("请输入姓名\n");
    scanf("%s", info.usname);
    printf("请输入年龄\n");
    scanf("%d", &info.age);
    printf("请输入号码\n");
    scanf("%d", &info.tele);
    printf("请输入地址\n");
    scanf("%s", info.site);
    espushback(ps, info);
}

void datadel(sys* ps)//删除数据
{
    char name[NAMEMAX];
    printf("请输入要删除的姓名:\n");
    scanf("%s", name);

    int find = FindByName(ps, name);
    if (find < 0)
    {
        printf("要删除的用户数据不存在！\n");
        return;
    }
    SLErase(ps, find);
    printf("删除成功！\n");
}

void reversedata(sys* ps)//更改指定数据
{
    char name[NAMEMAX];
    printf("请输入要更改的姓名:\n");
    scanf("%s", name);
    int find = FindByName(ps, name);
    if (find < 0)
    {
        printf("要删除的姓名不存在！\n");
        return;
    }
    printf("请输入更改后的姓名\n");
    scanf("%s", ps->arr[find].usname);

    printf("请输入更改后的年龄\n");
    scanf("%d", &ps->arr[find].age);
    printf("请输入更改后的号码\n");
    scanf("%d", &ps->arr[find].tele);
    printf("请输入更改后的地址\n");
    scanf("%s", ps->arr[find].site);

  
    printf("更改完成\n");
    return;



}
void printdata(sys* ps)//打印数据
{
    for (int i = 0; i < ps->size; i++)
    {
        printf("用户名   年龄    号码    地址\n");
        printf("%s       ", ps->arr[i].usname);
        printf("%d    ", ps->arr[i].age);
        printf("%d    ", ps->arr[i].tele);
        printf("%s ", ps->arr[i].site);
        printf("\n");
    }
}
void findata(sys* ps)//查找指定数据
{
    char name[NAMEMAX];
    printf("请输入要查找的用户名:\n");
    scanf("%s", name);

    int find = FindByName(ps, name);
    if (find < 0)
    {
        printf("要查找的用户名数据不存在！\n");
        return;
    }
    printf("找到了\n");
    printf("\n");
    printf("用户名   年龄    号码    地址\n");
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