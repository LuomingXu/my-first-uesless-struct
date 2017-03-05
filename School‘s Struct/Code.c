#include<stdio.h>
#include<string.h>
#define weizhi c:\\Users\xjy46\Desktop\wenjian.txt
//定义结构 
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
	printf("请先选择1再选择其他······························\n");

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
			printf("\n价格总计=%f\n", StaBookInfo(b, count));
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
					printf("请重新选择\n");
			}
			choice2 = 0;
			printf("-----------已进入图书管理系统-----------\n");
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
			printf("请输入1~10的数字\n");
			break;
		}
	}
	printf("\n\n----------------------------结束--------------------------\n\n");
	return 0;
}

void print()
{
	printf("\n\n");
	printf("---------------------------------图书管理系统---------------------------------\n");
	printf("----------------------------1. 输入并打印信息---------------------\n");
	printf("----------------------------2. 修改信息-----------------------------------\n");
	printf("----------------------------3. 添加信息-----------------------------------\n");
	printf("----------------------------4. 删除信息-----------------------------------\n");
	printf("----------------------------5. 统计---------------------------------------\n");
	printf("----------------------------6. 打印图书清单-----------------------------------\n");
	printf("----------------------------7. 排序-------------------------------------\n");
	printf("----------------------------8. 读入信息---------------------------------\n");
	printf("----------------------------9. 写入信息----------------------------------\n");
	printf("--------------------------（-1）. 退出------------------------------------------\n");
	printf("\n");
}
void print2()
{
	printf("\n");
	printf("请输入选择\n");
	printf("---1、以编号打印---\n");
	printf("---2、以价格打印---\n");
	printf("---(-1)、退出此选项卡---\n");
	printf("\n");
}


//输入图书信息 
int InputBookInfo(struct book b[])
{
	int i = 0;

	printf("请输入图书信息(输入零结束输入)\n");
	printf("图书编号\t价格\t书名\t出版社\t书架\t是否借出\t借书人\t应归还日期\n");

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


//输出图书信息 
void OutputBookInfo(struct book b[], int count)
{
	int i = 0;

	printf("\n图书信息如下\n");
	//	printf("图书编号\t价格\t书名\t出版社\t书架\t是否借出\t借书人\t应归还日期\n");
	printf("%-15s%-15s%-15s%-15s%-15s%-15s%-15s%-15s\n", "图书编号", "价格", "书名", "出版社", "书架", "是否借出", "借书人", "应归还日期");
	for (i = 0; i<count; i++)
		printf("%-d、%-13d%-13.2f%-15s%-15s%-15s%-15s%-15s%-15s\n", i + 1, b[i].number, b[i].price, b[i].name, b[i].publish, b[i].bookshelf, b[i].borrow, b[i].who, b[i].date);

	print();
}

//修改图书信息
void ChangeBookInfo(struct book b[], int count)
{
	int num = 0, i = 0, number = 0;
	double price = 0.0;
	char name[20], publish[20], bookshelf[20], borrow[20], who[20], date[20];

	printf("\n请输入需要修改第几条信息\n");
	scanf("%d", &i);

	printf("\n请输入需修改的信息\n");
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

//添加图书信息
int PlusBookInfo(struct book b[], int count)
{
	int i = count;

	printf("\n请开始输入第%d条图书信息(输入零结束输入)\n", count + 1);
	printf("\n图书编号\t价格\t书名\t出版社\t书架\t是否借出\t借书人\t应归还日期\n");

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

//删除信息
void DelBookInfo(struct book b[], int count)
{
	int i = 0, k = 0, l = 0, change1 = 0;
	double change2 = 0.0;
	printf("请输入需要删除第几条信息\n");
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

//统计
double StaBookInfo(struct book b[], int count)
{
	int i = 0;
	double total = 0.0;
	for (i = 0; i<count; i++)
		total += b[i].price;

	return total;
}

//排序，编号或价格 
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

//保存，读取 
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
		//		printf("存储完毕\n");
		fclose(fp);
		printf("存储完毕\n");
	}
	else
	{
		printf("无法打开文件\n");
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
		printf("读入完毕\n");
		fclose(fp);
	}
	else
		printf("无法打开文件\n");
	return count;
}
