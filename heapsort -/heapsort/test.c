#include"heapsort.h"
void HeapSort(int* a, int n)
{
	//�Ƚ�С��
	for (int i = 1; i < n; i++)
	{
		adjustup(a, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		swap(&a[0], &a[end]);
		adjustdown(a, end, 0);
		end--;
	}

}
void CreateNDate()
{
	// ������
	int n = 100;
	srand(time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen error");
		return;
	}

	for (size_t i = 0; i < n; ++i)
	{
		int x = rand() % 1000000;
		fprintf(fin, "%d\n", x);
	}

	fclose(fin);
}
void heaptest1()
{
int a[10] = { 7,32,12,2,3,5,6,1,2,44 };
HeapSort(a, sizeof(a) / sizeof(int));
for (int i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);

	}
}



void heaptest2()
{
	int k;
	printf("��������ȡ���ݸ���");
	scanf("%d", &k);
	//��k��������ռ䣬���γɶ�
	int* capacity = (int*)malloc(sizeof(int) * k);
	if (capacity == NULL)
	{
		perror("error");
		return;
	}
	//��ȡ����
	char* file = "data.txt";
	FILE* fout = fopen(file, "r");
	if (fout == NULL)
	{
		perror("fout error");
	}
	//��ȡǰk������
	for (int i = 0; i < k; i++)
	{
		fscanf(fout, "%d", &capacity[i]);

	}
	//��ǰk�����ݽ���С��
	for (int i = 1; i < k; i++)
	{
		adjustup(capacity, i);
	}
	//��֮��n-k��������Ѷ��Ƚ�
	int x = 0;
	while (fscanf(fout, "%d", &x)>0)
	{
		if (x > capacity[0])
		{

			capacity[0] = x;
			//���µ���
			adjustdown(capacity, k, 0);
		}
	}
	for (int i = 0; i < k; i++)
	{
		printf("%d ", capacity[i]);
	}
}

int main()

{
	//CreateNDate();
	heaptest2();
}