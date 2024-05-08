
#include "sq.h"  
void addata(sys* ps)//加入数据
{
    datatype info;
    printf("请输入用户名\n");
    scanf("%s", info.usname);
    printf("请输入单价\n");
    scanf("%lf", &info.uprice);
    printf("请输入用电量\n");
    scanf("%lf", &info.pwercon);
    info.price = info.pwercon * info.uprice;
    espushback(ps, info);
}

void datadel(sys *ps)//删除数据
{
    char name[NAMEMAX];
    printf("请输入要删除的用户名:\n");
    scanf("%s", name);

    int find = FindByName(ps, name);
    if (find < 0)
    {
        printf("要删除的用户名数据不存在！\n");
        return;
    }
    SLErase(ps, find);
    printf("删除成功！\n");
}

void reversedata(sys* ps)//更改指定数据
{
    char name[NAMEMAX];
    printf("请输入要更改的用户名:\n");
    scanf("%s", name);
    int find = FindByName(ps, name);
    if (find < 0)
    {
        printf("要删除的用户名数据不存在！\n");
        return;
    }
            printf("请输入更改后的用户名\n");
            scanf("%s", ps->arr[find].usname);

            printf("请输入更改后的单价\n");
            scanf("%lf", &ps->arr[find].uprice);
           
            printf("请输入更改后的用电量\n");
            scanf("%lf", &ps->arr[find].pwercon);
            
            ps->arr[find].price = ps->arr[find].uprice * ps->arr[find].pwercon;
            printf("更改完成\n");
            return ;
       
    
    
}
void printdata(sys* ps)//打印数据
{
    for (int i = 0; i < ps->size; i++)
    {
        printf("用户名   单价    用电量    总价\n");
        printf("%s       ", ps->arr[i].usname);
        printf("%.2lf    ", ps->arr[i].uprice);
        printf("%.2lf    ", ps->arr[i].pwercon);
        printf("%.2lf ", ps->arr[i].price);
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
            printf("用户名   单价    用电量    总价\n");
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