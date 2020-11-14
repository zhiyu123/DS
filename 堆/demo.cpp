#include"heap.h"

int main()
{
	Heap h;
	h.Insert(43);
	h.Insert(23);
	h.Insert(1);
	h.Insert(4);
	h.Insert(33);
	h.Insert(67);
	h.Insert(86);
	h.Insert(43);
	h.Insert(25);
	h.Insert(5);
	h.Insert(2);
	for (int i = 1; i <= h.count; i++)
	{
		cout << h.data[i] << " ";
	}
	cout << endl;

	while (h.count >= 1)
	{
		h.DelMax();
		for (int i = 1; i <= h.count; i++)
		{		
			cout << h.data[i] << " ";
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}