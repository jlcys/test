#include "sq.h"  
void menu()
{
    printf("*********************\n");
    printf("***1. 增 ******2.删***\n");
    printf("***3. 改*******4.查***\n");
    printf("***5. 展示数据 ********\n");
    printf("***0. 退出*************\n");
}
int main()
{
    sys L;
    Initsq(&L);
    int n = 0;
    do
    {
        menu();
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            addata(&L);
            break;
        case 2:
            datadel(&L);
            break;
        case 3:
            reversedata(&L);
            break;
        case 4:
            findata(&L);
            break;
        case 5:
            printdata(&L);
            break;
        case 0:
            printf("退出\n");
        default:
            printf("输入错误\n");
            break;
        }
    }
    while (n);
    DesTroy(&L);
    return 0;
}