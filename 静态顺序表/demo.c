#include"SqList.h"
#pragma warning(disable:6031) 

void menu()
{
	printf("*****************************************************************\n");
	printf("**************   1.初始化顺序表     2.打印顺序表   **************\n");
	printf("**************   3.头插             4.尾插         **************\n");
	printf("**************   5.头删             6.尾删         **************\n");
	printf("**************   7.任意位置插入     8.任意位置删除 **************\n");
	printf("**************   9.查询某元素的位置 10.排序        **************\n");
	printf("**************   11.清空            0.退出         **************\n");
	printf("*****************************************************************\n");
}

int main()
{
	SqList L;
	int choose = 0;
	elemtype num = 0;
	elemtype pos = 0;
	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &choose);
		switch (choose)
		{
		case 0:
			printf("退出成功！\n");
			break;
		case 1:
			InitList(&L);
			break;
		case 2:
			PrintList(&L);
			break;
		case 3:
			printf("请输入要插入的元素：");
			scanf("%d", &num);
			PushPront(&L, num);  
			break;
		case 4:
			printf("请输入要插入的元素：");
			scanf("%d", &num);
			PushBack(&L, num);
			break;
		case 5:
			PopPront(&L);
			break;
		case 6:
			PopBack(&L);
			break;
		case 7:
			printf("请输入插入的位置：");
			scanf("%d", &pos);
			printf("请输入要插入的元素：");
			scanf("%d", &num);
			InsertElem(&L, pos, num);
			break;
		case 8:
			printf("请输入要删除的位置：");
			scanf("%d", &pos);
			DeleteElem(&L, pos);
			break;
		case 9:
			printf("请输入要查询的元素：");
			scanf("%d", &num);
			LocateElem(&L, num);
			break;
		case 10:
			SortList(&L);
			break;
		case 11:
			ClearList(&L);
			break;
		default:
			printf("输入错误，请重新输入!\n");
			break;
		}
	} while (choose);
	return 0;
}
