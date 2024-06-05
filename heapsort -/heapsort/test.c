#include"heapsort.h"
void HeapSort(int* a, int n)
{
	//先建小堆
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
	// 造数据
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
	printf("请输入所取数据个数");
	scanf("%d", &k);
	//给k个数申请空间，并形成堆
	int* capacity = (int*)malloc(sizeof(int) * k);
	if (capacity == NULL)
	{
		perror("error");
		return;
	}
	//读取数据
	char* file = "data.txt";
	FILE* fout = fopen(file, "r");
	if (fout == NULL)
	{
		perror("fout error");
	}
	//读取前k个数据
	for (int i = 0; i < k; i++)
	{
		fscanf(fout, "%d", &capacity[i]);

	}
	//将前k个数据建成小堆
	for (int i = 1; i < k; i++)
	{
		adjustup(capacity, i);
	}
	//将之后n-k的数据与堆顶比较
	int x = 0;
	while (fscanf(fout, "%d", &x)>0)
	{
		if (x > capacity[0])
		{

			capacity[0] = x;
			//向下调整
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