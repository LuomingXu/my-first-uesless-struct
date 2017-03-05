#include<stdio.h>
#include<string.h>
#define weizhi c:\\Users\xjy46\Desktop\wenjian.txt
//����ṹ 
struct book
{
	int number;
	double price;
	char name[20];
	char publish[20];
	char bookshelf[20];
	char borrow[20];
	char who[20];
	char date[20];
};

void print();
void print2();
int InputBookInfo(struct book b[]);
void OutputBookInfo(struct book b[], int count);
int PlusBookInfo(struct book b[], int count);
void ChangeBookInfo(struct book b[], int count);
void DelBookInfo(struct book b[], int count);
double StaBookInfo(struct book b[], int count);
void RankBookNumberInfo(struct book b[], int count);
void RankPriceBookInfo(struct book b[], int count);
int Read(struct book b[]);
void Save(struct book b[], int count);

int main(void)
{
	struct book b[20];
	int count = 0, choice = 0, choice2 = 0;

	print();
	printf("����ѡ��1��ѡ������������������������������������������������������������������\n");

	while (choice != -1)
	{
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			count = InputBookInfo(b);
			OutputBookInfo(b, count);
			break;
		case 2:
			ChangeBookInfo(b, count);
			break;
		case 3:
			count = PlusBookInfo(b, count);
			OutputBookInfo(b, count);
			break;
		case 4:
			DelBookInfo(b, count);
			count--;
			OutputBookInfo(b, count);
			break;
		case 5:
			printf("\n�۸��ܼ�=%f\n", StaBookInfo(b, count));
			print();
			break;
		case 6:
			OutputBookInfo(b, count);
			break;
		case 7:
			while (choice2 != -1)
			{
				print2();
				scanf("%d", &choice2);

				if (choice2 == 1)
				{
					RankBookNumberInfo(b, count);
					OutputBookInfo(b, count);
				}
				else if (choice2 == 2)
				{
					RankPriceBookInfo(b, count);
					OutputBookInfo(b, count);
				}
				else if (choice2 == -1)
					break;
				else
					printf("������ѡ��\n");
			}
			choice2 = 0;
			printf("-----------�ѽ���ͼ�����ϵͳ-----------\n");
			break;
		case 8:
			count = Read(b);
			OutputBookInfo(b, count);
			break;
		case 9:
			Save(b, count);
			break;
		case -1:
			break;
		default:
			printf("������1~10������\n");
			break;
		}
	}
	printf("\n\n----------------------------����--------------------------\n\n");
	return 0;
}

void print()
{
	printf("\n\n");
	printf("---------------------------------ͼ�����ϵͳ---------------------------------\n");
	printf("----------------------------1. ���벢��ӡ��Ϣ---------------------\n");
	printf("----------------------------2. �޸���Ϣ-----------------------------------\n");
	printf("----------------------------3. �����Ϣ-----------------------------------\n");
	printf("----------------------------4. ɾ����Ϣ-----------------------------------\n");
	printf("----------------------------5. ͳ��---------------------------------------\n");
	printf("----------------------------6. ��ӡͼ���嵥-----------------------------------\n");
	printf("----------------------------7. ����-------------------------------------\n");
	printf("----------------------------8. ������Ϣ---------------------------------\n");
	printf("----------------------------9. д����Ϣ----------------------------------\n");
	printf("--------------------------��-1��. �˳�------------------------------------------\n");
	printf("\n");
}
void print2()
{
	printf("\n");
	printf("������ѡ��\n");
	printf("---1���Ա�Ŵ�ӡ---\n");
	printf("---2���Լ۸��ӡ---\n");
	printf("---(-1)���˳���ѡ�---\n");
	printf("\n");
}


//����ͼ����Ϣ 
int InputBookInfo(struct book b[])
{
	int i = 0;

	printf("������ͼ����Ϣ(�������������)\n");
	printf("ͼ����\t�۸�\t����\t������\t���\t�Ƿ���\t������\tӦ�黹����\n");

	while (i<20)
	{
		scanf("%d", &b[i].number);
		getchar();
		if (b[i].number == 0)
			break;

		scanf("%lf%s%s%s%s%s%s", &b[i].price, b[i].name, b[i].publish, b[i].bookshelf, b[i].borrow, b[i].who, b[i].date);

		i++;
	}

	return i;
}


//���ͼ����Ϣ 
void OutputBookInfo(struct book b[], int count)
{
	int i = 0;

	printf("\nͼ����Ϣ����\n");
	//	printf("ͼ����\t�۸�\t����\t������\t���\t�Ƿ���\t������\tӦ�黹����\n");
	printf("%-15s%-15s%-15s%-15s%-15s%-15s%-15s%-15s\n", "ͼ����", "�۸�", "����", "������", "���", "�Ƿ���", "������", "Ӧ�黹����");
	for (i = 0; i<count; i++)
		printf("%-d��%-13d%-13.2f%-15s%-15s%-15s%-15s%-15s%-15s\n", i + 1, b[i].number, b[i].price, b[i].name, b[i].publish, b[i].bookshelf, b[i].borrow, b[i].who, b[i].date);

	print();
}

//�޸�ͼ����Ϣ
void ChangeBookInfo(struct book b[], int count)
{
	int num = 0, i = 0, number = 0;
	double price = 0.0;
	char name[20], publish[20], bookshelf[20], borrow[20], who[20], date[20];

	printf("\n��������Ҫ�޸ĵڼ�����Ϣ\n");
	scanf("%d", &i);

	printf("\n���������޸ĵ���Ϣ\n");
	//	scanf("%d", &number);
	scanf("%d%lf%s%s%s%s%s%s", &number, &price, name, publish, bookshelf, borrow, who, date);

	b[i - 1].number = number;
	b[i - 1].price = price;
	strcpy(b[i - 1].name, name);
	strcpy(b[i - 1].publish, publish);
	strcpy(b[i - 1].bookshelf, bookshelf);
	strcpy(b[i - 1].borrow, borrow);
	strcpy(b[i - 1].who, who);
	strcpy(b[i - 1].date, date);

	OutputBookInfo(b, count);
}

//���ͼ����Ϣ
int PlusBookInfo(struct book b[], int count)
{
	int i = count;

	printf("\n�뿪ʼ�����%d��ͼ����Ϣ(�������������)\n", count + 1);
	printf("\nͼ����\t�۸�\t����\t������\t���\t�Ƿ���\t������\tӦ�黹����\n");

	while (i<100)
	{
		scanf("%d", &b[i].number);
		getchar();

		if (b[i].number == 0)
			break;

		scanf("%lf%s%s%s%s%s%s", &b[i].price, b[i].name, b[i].publish, b[i].bookshelf, b[i].borrow, b[i].who, b[i].date);

		i++;
	}

	return i;
}

//ɾ����Ϣ
void DelBookInfo(struct book b[], int count)
{
	int i = 0, k = 0, l = 0, change1 = 0;
	double change2 = 0.0;
	printf("��������Ҫɾ���ڼ�����Ϣ\n");
	scanf("%d", &i);
	b[i - 1].number = 0;
	for (k = 0; k < count; k++)
		for (l = 0; l < count - k - 1; l++)
		{
			if (b[l].number == 0 /*< b[l + 1].number*/)
			{
				change1 = b[l].number;
				b[l].number = b[l + 1].number;
				b[l + 1].number = change1;
				change2 = b[l].price;
				b[l].price = b[l + 1].price;
				b[l + 1].price = change2;
				strcpy(b[l].name, b[l + 1].name);
				strcpy(b[l].publish, b[l + 1].publish);
				strcpy(b[l].bookshelf, b[l + 1].bookshelf);
				strcpy(b[l].borrow, b[l + 1].borrow);
				strcpy(b[l].who, b[l + 1].who);
				strcpy(b[l].date, b[l + 1].date);
			}
		}
}

//ͳ��
double StaBookInfo(struct book b[], int count)
{
	int i = 0;
	double total = 0.0;
	for (i = 0; i<count; i++)
		total += b[i].price;

	return total;
}

//���򣬱�Ż�۸� 
void RankBookNumberInfo(struct book b[], int count)
{
	int k = 0, l = 0, change1 = 0;
	double change2 = 0.0;
	for (k = 0; k < count - 1; k++)
		for (l = 0; l < count - k - 1; l++)
		{
			if (b[l].number > b[l + 1].number)
			{
				change1 = b[l].number;
				b[l].number = b[l + 1].number;
				b[l + 1].number = change1;
				change2 = b[l].price;
				b[l].price = b[l + 1].price;
				b[l + 1].price = change2;
				strcpy(b[l].name, b[l + 1].name);
				strcpy(b[l].publish, b[l + 1].publish);
				strcpy(b[l].bookshelf, b[l + 1].bookshelf);
				strcpy(b[l].borrow, b[l + 1].borrow);
				strcpy(b[l].who, b[l + 1].who);
				strcpy(b[l].date, b[l + 1].date);
			}
		}
}
void RankPriceBookInfo(struct book b[], int count)
{
	int k = 0, l = 0, change1 = 0;
	double change2 = 0.0;

	for (k = 0; k < count - 1; k++)
		for (l = 0; l < count - k - 1; l++)
		{
			if (b[l].price > b[l + 1].price)
			{
				change1 = b[l].number;
				b[l].number = b[l + 1].number;
				b[l + 1].number = change1;
				change2 = b[l].price;
				b[l].price = b[l + 1].price;
				b[l + 1].price = change2;
				strcpy(b[l].name, b[l + 1].name);
				strcpy(b[l].publish, b[l + 1].publish);
				strcpy(b[l].bookshelf, b[l + 1].bookshelf);
				strcpy(b[l].borrow, b[l + 1].borrow);
				strcpy(b[l].who, b[l + 1].who);
				strcpy(b[l].date, b[l + 1].date);
			}
		}
}

//���棬��ȡ 
void Save(struct book b[], int count)
{
	int i = 0;
	//	FILE *fp = fopen("c:\\wenjian.txt","w");
	FILE *fp = fopen("weizhi", "w");
	if (fp)
	{
		fprintf(fp, "%d\n", count);
		while (i<count)
		{
			fprintf(fp, "%-15d%-13.2f%-15s%-15s%-15s%-15s%-15s%-15s\n", b[i].number, b[i].price, b[i].name, b[i].publish, b[i].bookshelf, b[i].borrow, b[i].who, b[i].date);
			i++;
		}
		fprintf(fp, "%d", 0);
		//		printf("�洢���\n");
		fclose(fp);
		printf("�洢���\n");
	}
	else
	{
		printf("�޷����ļ�\n");
		return;
	}
}
int Read(struct book b[])
{
	int i = 0, count = 0;
	//	FILE *fp = fopen("c:\\wenjian.txt","r");
	FILE *fp = fopen("weizhi", "r");
	if (fp)
	{
		fscanf(fp, "%d", &count);
		//		printf("Read.count=%d\n",count);
		while (i<count)
		{
			fscanf(fp, "%d", &b[i].number);
			//			printf("%d\n",i);
			if (b[i].number == 0)
				break;

			fscanf(fp, "%lf%s%s%s%s%s%s", &b[i].price, b[i].name, b[i].publish, b[i].bookshelf, b[i].borrow, b[i].who, b[i].date);

			i++;
		}
		printf("�������\n");
		fclose(fp);
	}
	else
		printf("�޷����ļ�\n");
	return count;
}
