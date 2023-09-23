#include "Function.h"



//��ȡ�ֿ����Ʒ���ݣ�����¼�ֿ����Ʒ��������(ͷ��㲻������)
int ReadFileOfBase(BaseOfGoods &Base)
{
	FILE* fp;
	if ((fp = fopen("DataOfBase.txt", "r+")) == NULL)
	{
		printf("δ�ܴ����ݿ��ļ���\n");
		return 0;
	}
	int i=1;
	Base.next =(BaseOfGoods*) malloc(sizeof(BaseOfGoods));
	BaseOfGoods* Base_1 = Base.next,*Base_2;
	//��ȡ��Ʒ���룬���ƣ��������۸�
	fscanf(fp, "%s%s%d%f", Base_1->goods.code, Base_1->goods.name, &Base_1->goods.sum, &Base_1->goods.price);
	//��ȡ��Ʒ����������(������)��������(�����·�)
	fscanf(fp, "%d%d%d%d", &Base_1->goods.ED.pd.y, &Base_1->goods.ED.pd.m, &Base_1->goods.ED.pd.d, &Base_1->goods.ED.Ex_Mon);
	//�������(������)
	fscanf(fp, "%d%d%d\n", &Base_1->goods.InTime.year, &Base_1->goods.InTime.month, &Base_1->goods.InTime.day);
	/*printf("%s %s %d %.2f", Base_1->goods.code, Base_1->goods.name, Base_1->goods.sum, Base_1->goods.price);
	printf(" %d %d %d %d", Base_1->goods.ED.pd.y, Base_1->goods.ED.pd.m, Base_1->goods.ED.pd.d, Base_1->goods.ED.Ex_Mon);
	printf(" %d %d %d\n", Base_1->goods.InTime.year, Base_1->goods.InTime.month, Base_1->goods.InTime.day);*/
	while (!feof(fp))
	{
		Base_2 = (BaseOfGoods*)malloc(sizeof(BaseOfGoods));
		if (fscanf(fp, "%s%s%d%f", Base_2->goods.code, Base_2->goods.name, &Base_2->goods.sum, &Base_2->goods.price) != 4)
			break;
		fscanf(fp, "%d%d%d%d", &Base_2->goods.ED.pd.y, &Base_2->goods.ED.pd.m, &Base_2->goods.ED.pd.d, &Base_2->goods.ED.Ex_Mon);
		fscanf(fp, "%d%d%d", &Base_2->goods.InTime.year, &Base_2->goods.InTime.month, &Base_2->goods.InTime.day);
		Base_1->next = Base_2;
		Base_1 = Base_1->next;
		i++;
	}
	Base_1->next= NULL;
	Base.sumOfGoods = i;
	if (fclose(fp))
	{
		printf("�ļ�δ�رճɹ���\n");
		return 0;
	}
	return 1;
}

//���������ļ�
int ConserveFileOfBase(BaseOfGoods Base)
{
	FILE* fp;
	if ((fp = fopen("DataOfBase.txt", "r+")) == NULL)
	{
		printf("δ�ܴ����ݿ��ļ���\n");
		return 0;
	}
	BaseOfGoods *Base_1 = &Base;
	while (Base_1->next!= NULL)
	{
		Base_1 = Base_1->next;
		fprintf(fp, "%s %s %d %.2f", Base_1->goods.code, Base_1->goods.name, Base_1->goods.sum, Base_1->goods.price);
		fprintf(fp, " %d %d %d %d", Base_1->goods.ED.pd.y, Base_1->goods.ED.pd.m, Base_1->goods.ED.pd.d, Base_1->goods.ED.Ex_Mon);
		fprintf(fp, " %d %d %d\n", Base_1->goods.InTime.year, Base_1->goods.InTime.month, Base_1->goods.InTime.day);
	}
	if (fclose(fp))
	{
		printf("�ļ�δ�رճɹ���\n");
		return 0;
	}
	return 1;
}

//��δ���)���˵�
void MainMenu()
{
	system("cls");
	printf("*************************************�ֿ����ݹ���ϵͳ*****************************************\n");
	printf("������Ҫ���еĲ�����\n");
	printf("1.��ѯ����˵�                        2.�������Ǽ�\n");
	printf("3.�������Ǽ�                        4.��������ͳ��\n");
	printf("5.�޸Ļ�����Ϣ(��ɾ���)ϵͳ          6.�˳�ϵͳ\n");
	printf("**********************************************************************************************\n");
	int opt;
	while(1)
	{ 
		scanf("%d", &opt);
		if (opt > 6 || opt <= 0)
		{
			printf("������������������:\n");
			continue;
		}
		else if (opt == 6)
			break;		
		switch (opt)
		{
		case 1:
			SearchMenu();
			break;
		case 2:
			
			break;
		case 3:

			break;
		case 4:

			break;
		case 5:

			break;
		default:
			break;
		}
	}
	
}


//(δ���)��ѯϵͳ
void SearchMenu()
{
	int opt;
	while (1)
	{
		system("cls");
		printf("*************************************�ֿ����ݹ���ϵͳ*****************************************\n");
		printf("        *****************************  ��ѯϵͳ�˵�  *****************************    \n");
		printf("������Ҫ���еĲ�����\n");
		printf("1.���������ѯ                        2.���������Ʋ�ѯ\n");
		printf("3.�������ʱ���ѯ                    4.�������ʱ���ѯ\n");
		printf("5.��Χ��ѯ������Ϣ                    6.��ʾ���л�����Ϣ����ҳ���\n");
		printf("7.�˳���ϵͳ��������һ����\n");
		printf("**********************************************************************************************\n");
		scanf("%d", &opt);
		if (opt > 7 || opt <= 0)
		{
			printf("������������������:\n");
			continue;
		}
		else if (opt == 7)
			break;
		switch (opt)
		{
		case 1:
			BaseOfGoods * b;
			b=SearchByCode();
			PrintSheet();
			PrintGoods(b);
			break;
		case 2:

			break;
		case 3:

			break;
		case 4:

			break;
		case 5:

			break;
		case 6:
			PrintAllGoods();
			break;
		default:
			break;
		}
	}



}

//���������Ʒ
BaseOfGoods* SearchByCode()
{
	BaseOfGoods *Base_1 = Base.next;
	printf("������Ҫ������Ʒ�ĳ����룺\n");
	char tem_a[LEN];
	scanf("%s", tem_a);
	while (!Is_MarkCode(tem_a))
	{
		printf("����ĳ����벻���Ϲ���(CSXXX)�����������룺\n");
		scanf("%s", tem_a);
	}
	printf("����ɹ���\n");
	while (Base_1!=NULL)
	{
		if (strcmp(Base_1->goods.code, tem_a)==0)
		{ 
			printf("��ƥ�䵽��Ӧ��Ʒ��\n");
			return Base_1;
		}
		Base_1 = Base_1->next;
	}
	printf("Ҫ���ҵ�%s���ڳ������С�\n", tem_a);
	return NULL;
}

//������Ʒ���ʽ�жϣ�
int Is_MarkCode(char* code)
{
	if (code[0] == 'C' && code[1] == 'S')
	{
		if (code[2] <= '9' && code[2] >= '0')
			if (code[3] <= '9' && code[3] >= '0')
				if (code[4] <= '9' && code[4] >= '0')
					return 1;
	}
	else return 0;
}

//��Ʒ��Ϣ������
void PrintSheet()
{
	printf("\t��Ʒ��\t����\t����\t�۸�\t��������\t\t������\t���ʱ��\n");
}

//��ʾָ����Ʒ��Ϣ
void PrintGoods(BaseOfGoods* b)
{
	printf("\t%s\t%s\t%d\t%.2f",b->goods.code,b->goods.name,b->goods.sum,b->goods.price);
	printf("\t%d\t%d\t%d\t%d", b->goods.ED.pd.y, b->goods.ED.pd.m, b->goods.ED.pd.d, b->goods.ED.Ex_Mon);
	printf("\t%d\t%d\t%d\n", b->goods.InTime.year, b->goods.InTime.month, b->goods.InTime.day);
}

//��ʾ������Ʒ��Ϣ����ҳ��ʽ��;
void PrintAllGoods()
{
	BaseOfGoods* Base_1 = Base.next;
	int count = 0, page = 1, All_page = Base.sumOfGoods / 10+1;
	//count ����һҳ���ʮ����Ʒ��Ϣ��page��¼��ǰҳ��
	PrintByPage(page);
	while(true)
	{
		char opt;	
		while (1)
		{
			printf("������Ҫ���еĲ�����\n");			
		    getchar();
			scanf("%c", &opt);
			if (opt == '0')
				return;
			else if (opt != 'a' && opt != 'd' && opt != 'w' && opt != 's')
			{
				printf("���벻�ڷ�Χ,���������룺\n");
				continue;
			}			
			else break;
		}
		int opt_num = (int)opt;
		switch(opt_num)
		{
		case 'a':
			if (page == 1)
			printf("��ҳ�Ѿ�����ҳ��\n");
			else
			{
				page = 1;
				PrintByPage(page);
				system("pause");
			}			
			break;
		case's':
			if(page==All_page)
				printf("��ҳ�Ѿ���βҳ��\n");
			else
			{
				PrintByPage(++page);
				system("pause");
			}
			break;
		case 'w':
			if (page == 1)
			printf("��ҳ�Ѿ�����ҳ��\n");
			else
		{
			PrintByPage(--page);
			system("pause");
		}
			break;
		case 'd':
			if (page ==All_page )
				printf("��ҳ�Ѿ���βҳ��\n");
			else
			{
				page = All_page;
				PrintByPage(page);
				system("pause");
			}
			break;
		default:
			break;
		}

	}

}


//��ҳ��ӡ��Ʒ��Ϣ��
void PrintByPage(int page)
{
	BaseOfGoods *Base_1 = Base.next;
	int count=0;
	while (count / 10 + 1 < page&&Base_1->next!=NULL)
	{
		Base_1 = Base_1->next;
		count++;
	}
	system("cls");
	printf("********************************************   ��Ʒ��Ϣ��   *********************************************\n");
	PrintSheet();
	while (count < page * 10 && Base_1 != NULL)
	{
	    PrintGoods(Base_1);
		Base_1 = Base_1->next;
		count++;
	}
	printf("**********************************************************************************************************\n");
	printf("-------------------------------��ǰΪ��%dҳ,��%dҳ--------------------------------\n", page, Base.sumOfGoods/10+1);
	printf("����:w.��һҳ***a.ת��ҳ��***d.ת��ҳβ***s.��һҳ***0.���ز�ѯϵͳ\n");
}