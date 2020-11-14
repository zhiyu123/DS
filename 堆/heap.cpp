#include"heap.h"

Heap::Heap()
{
	this->count = 0;
	this->data = new elemtype[CAPACITY];
}

Heap::~Heap()
{
	delete []data;
	data = NULL;
}

void Heap::Insert(elemtype e)
{
	data[++count] = e;				//索引0处不放元素，从1开始放元素，并且放完后，count就已经+1，表示的是数组长度
	Swim(count);					//通过上浮来使e插入到合适的位置，传入的参数为e的下标
}

void Heap::Swim(int k)
{
	//通过循环不断地比较当前节点和父节点的值，如果大于父节点，则交换位置，小于就退出循环
	while (k > 1)	//当k为2时，就已经交换根节点和子节点的的值了,所以待插入结点已经上浮到根节点了，
	{				//最后再使k/2就成为1了，就要退出循环了，所以k不能等于1 
		//比较当前节点和其父节点
		if (data[k / 2] <  data[k])	//k / 2 为 k 父节点所在的索引下标，父节点小于当前节点，则交换两者
		{
			int tmp = data[k];
			data[k] = data[k / 2];
			data[k / 2] = tmp;
		}
		k /= 2;	//改变k的值，使其指向变换后的当前节点(原来的父节点)
	}
}

elemtype Heap::DelMax()
{
	elemtype Max = data[1];			//最大堆的堆顶为最大元素，所以索引1处为最大值
	//交换索引1处的元素和最大索引处的元素，让完全二叉树中最后一个元素变为临时根节点
	int tmp = data[count];
	data[count] = data[1];
	data[1] = tmp;

	//最大索引处的元素删除掉,可以不用这步，count减一即可
	data[count] = NULL;

	//元素个数减一
	this->count--;

	//通过下沉算法调整堆，使堆重新有序
	Skin(1);
	return Max;		//返回最大值，就是删除元素
}

void Heap::Skin(int k)
{
	//通过循环不断的对比当前k结点和其左子节点2k以及右子节点2k+1处两者中较大值的元素大小，如果当前结点小于两个子节点的较大值，则需要交换位置
	while (2 * k <= count)    //2 * k是k结点的左子节点，如果2k > count，也就证明k没有左孩子，则说明k是叶子节点，那就结束循环
	{
		//获取当前节点的左右子节点中的较大节点
		int max = 0;
		if (2 * k + 1 <= count)			//如果有右子节点，则比较左子节点和右子节点
		{
			if (data[2 * k] < data[2 * k + 1])	//如果左子节点小
			{
				max = 2 * k + 1;		//最大值为右子节点的索引
			}
			else
			{
				max = 2 * k;		//否则，为左子节点的索引
			}
		}
		else                             //如果没有右子节点，最大值直接就是左子节点的索引
		{
			max = 2 * k;
		}	

		//比较当前结点和较大节点的值
		if (data[k] >= data[max])	//如果 data[k] >= data[max]，则说明当前节点比子节点都大，就不需要下沉，直接退出即可
		{
			break;
		}
		else                            //小于交换
		{
			int tmp1 = data[max];
			data[max] = data[k];
			data[k] = tmp1;

			k = max;		//更新索引，继续循环
		}
	}
}