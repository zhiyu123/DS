#include"SqList.h"
#pragma warning(disable:6031) 

void menu()
{
	printf("*****************************************************************\n");
	printf("**************   1.��ʼ��˳���     2.��ӡ˳���   **************\n");
	printf("**************   3.ͷ��             4.β��         **************\n");
	printf("**************   5.ͷɾ             6.βɾ         **************\n");
	printf("**************   7.����λ�ò���     8.����λ��ɾ�� **************\n");
	printf("**************   9.��ѯĳԪ�ص�λ�� 10.����        **************\n");
	printf("**************   11.���            0.�˳�         **************\n");
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
		printf("��ѡ��");
		scanf("%d", &choose);
		switch (choose)
		{
		case 0:
			printf("�˳��ɹ���\n");
			break;
		case 1:
			InitList(&L);
			break;
		case 2:
			PrintList(&L);
			break;
		case 3:
			printf("������Ҫ�����Ԫ�أ�");
			scanf("%d", &num);
			PushPront(&L, num);  
			break;
		case 4:
			printf("������Ҫ�����Ԫ�أ�");
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
			printf("����������λ�ã�");
			scanf("%d", &pos);
			printf("������Ҫ�����Ԫ�أ�");
			scanf("%d", &num);
			InsertElem(&L, pos, num);
			break;
		case 8:
			printf("������Ҫɾ����λ�ã�");
			scanf("%d", &pos);
			DeleteElem(&L, pos);
			break;
		case 9:
			printf("������Ҫ��ѯ��Ԫ�أ�");
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
			printf("�����������������!\n");
			break;
		}
	} while (choose);
	return 0;
}
