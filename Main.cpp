#include "Function.h"

BaseOfGoods Base;

int main()
{
	Base.next = NULL;
	if (ReadFileOfBase(Base))
		printf("��ȡ�ֿ���Ʒ���ݳɹ���\n");
	else printf("��ȡ�ֿ���Ʒ����ʧ�ܡ�\n");
	/*if(Base.next->next->next!=NULL)
	printf("%s", Base.next->next->next);*/
	MainMenu();



	if(ConserveFileOfBase(Base))
		printf("����ֿ���Ʒ���ݳɹ���\n");
	else printf("����ֿ���Ʒ����ʧ�ܡ�\n");
	system("pause");
	return 0;
}