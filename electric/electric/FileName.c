#include "sq.h"  
void menu()
{
    printf("*********************\n");
    printf("***1. �� ******2.ɾ***\n");
    printf("***3. ��*******4.��***\n");
    printf("***5. չʾ���� ********\n");
    printf("***0. �˳�*************\n");
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
            printf("�˳�\n");
        default:
            printf("�������\n");
            break;
        }
    }
    while (n);
    DesTroy(&L);
    return 0;
}