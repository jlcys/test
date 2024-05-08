#include"sq.h"
PeoInfo* CreateNewContact()
{
	PeoInfo* newcode = (PeoInfo*)malloc(sizeof(PeoInfo));
	if (newcode == NULL) {
		// �����ڴ����ʧ�ܵ����  
		exit(-1);
	}
	return newcode;
}
void AddContact(PeoInfo** con)
{
	PeoInfo* newcode = CreateNewContact();
	PeoInfo* cur = *con;
	printf("�û���\n");
	scanf("%s", newcode->usname);
	printf("�����뵥��\n");
	scanf("%lf", &(newcode->uprice));
	printf("�������õ���\n");
	scanf("%lf", &(newcode->pwercon));
	newcode->price = newcode->uprice * newcode->pwercon;
	newcode->next = *con; // �½ڵ��nextָ��ǰͷ�ڵ�  
	*con = newcode;

}
void ShowContact(PeoInfo* con)
{
	PeoInfo* petail = con;


	while (petail)
	{

		printf("\n");
		printf("�û���: %s\n", petail->usname);
		printf("����: %.2lf\n", petail->uprice);
		printf("�õ���: %.2lf\n", petail->pwercon);
		printf("�ܼ�: %.2lf\n", petail->price);
		
		printf("\n"); // ��ӡһ�������Էָ���ͬ����Ϣ
		petail = petail->next;
	}
}
PeoInfo* FindContact(PeoInfo* con)
{
	printf("��������Ҫ����/ɾ��/�޸ĵ��û���");
	char namex[100];
	scanf("%s", namex);
	PeoInfo* pcur = con;
	int count = 0;
	if (con == NULL) {
		printf("�û�Ϊ��\n");
		return NULL;
	}
	PeoInfo* prev = NULL;
	while (pcur)
	{
		if (strcmp(pcur->usname, namex) == 0)
		{
			count = 1;
			printf("\n");

			printf("�ҵ���\n");
			printf("\n");
			printf("�û���: %s\n", pcur->usname);
			printf("����: %.2lf\n", pcur->uprice);
			printf("�õ���: %.2lf\n", pcur->pwercon);
			printf("�ܼ�: %.2lf\n", pcur->price);
			return pcur;
		}
		pcur = pcur->next;
	}
	if (count == 0)
	{
		printf("û�ҵ�\n");
		return NULL;
	}


}
void DelContact(PeoInfo** con)//ɾ��
{

	PeoInfo* det = FindContact(*con);
	if (det == NULL)
	{
		printf("ɾ��ʧ��\n");
		return;
	}
	PeoInfo* cur = *con;
	if (det == cur)
	{
		*con = det->next;
	}
	else
	{
		while (cur->next != det)
		{
			cur = cur->next;
		}
	}
	cur->next = det->next;
	free(det); // �ͷű�ɾ���ڵ���ڴ�  
	printf("ɾ���ɹ�\n");
	printf("\n");

}
void ModifyContact(PeoInfo** con)
{

	PeoInfo* reverse = FindContact(*con);
	printf("\n");

	printf("\n");
	printf("�û���: %s\n", reverse->usname);
	printf("����: %.2lf\n", reverse->uprice);
	printf("�õ���: %.2lf\n", reverse->pwercon);
	printf("�ܼ�: %.2lf\n", reverse->price);
	printf("�޸ĳɹ�\n");
}
void DestroyContact(PeoInfo** con)
{
	*con = NULL;

	free(*con);


}