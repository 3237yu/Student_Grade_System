#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define LEN 24
#define MAXSIZE 100

typedef struct time_IO  //����ֿ��ʱ��
{
	int year;
	int month;
	int day;
}IO_Time;

typedef struct produce_date
{
	int y;
	int m;
	int d;
}ProDate;

typedef struct expiration_date  //������
{
	ProDate pd;
	int Ex_Mon;
}Exp_Date;

typedef struct goods  //��Ʒ���룬��Ʒ���ƣ���Ʒ��������Ʒ�۸񡢱�����ʱ�䡢���ʱ��
{
	char code[LEN];
	char name[LEN];
	int sum;
	float price;
	Exp_Date ED;
	IO_Time InTime;
}Goods;

//�ֿ�ṹ����������
typedef struct baseofGoods
{
	Goods goods;
	int sumOfGoods;
	baseofGoods* next;
}BaseOfGoods;

extern BaseOfGoods Base;   //ʹ��ȫ�ֱ�����ʽ�����ֿ�

int ReadFileOfBase(BaseOfGoods &Base); //��ȡ�ļ�����
int ConserveFileOfBase(BaseOfGoods Base);//�����ļ�����
void MainMenu();//���˵�
void SearchMenu();//��ѯ�˵�
BaseOfGoods* SearchByCode();//���������Ʒ
int Is_MarkCode(char* code);//������Ʒ���ʽ�жϣ�
void PrintSheet();//��Ʒ��Ϣ��������ʾ
void PrintGoods(BaseOfGoods* b);//��ʾָ����Ʒ��Ϣ
void PrintAllGoods();//��ʾ������Ʒ��Ϣ����ҳ��ʽ��;
void PrintByPage(int page);//��ӡָ��ҳ����Ʒ��Ϣ
void SearchMenu();//��Ʒ���ݹ���ϵͳ
void InsertGoods();//������Ʒ��Ϣ
void DeleteGoods();//ɾ����Ʒ��Ϣ
void ModityGoods();//�޸���Ʒ��Ϣ
void GoodsIOMenu();//��Ʒ�����˵�
void GetNowTime(int &a,int &b,int &c);//��ȡ��ǰʱ��