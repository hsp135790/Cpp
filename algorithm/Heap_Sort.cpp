#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<ctime>

#define MAX 100

using namespace std;

int Arr[MAX + 1];
bool Flag[10000];

void Print()
{
	cout << "##############################################" << endl;
	int Cnt = 0;
	for (int i = 1;i <= MAX;i++)
	{
		printf("%3d ", Arr[i]);
		Cnt++;
		if (Cnt == 20)
		{
			Cnt = 0;
			cout << endl;
		}
	}
	cout << "##############################################" << endl;
	cout << endl;
}

void Build_heap()
{
	for (int Cur_idx = 2;Cur_idx <= MAX;Cur_idx++)
	{
		while (Cur_idx > 1) //if Current idx is not root
		{
			int Parent_idx = Cur_idx / 2;
			if (Arr[Cur_idx] > Arr[Parent_idx])
			{
				swap(Arr[Cur_idx], Arr[Parent_idx]);
				Cur_idx = Parent_idx;
			}
			else break;
		}
	}
}

void Heapify(int Current, int N)
{
	int Cur_idx = Current;
	int left_child = Current * 2;
	int right_child = Current * 2 + 1;

	if ((left_child <= N) && (Arr[left_child] > Arr[Cur_idx]))
		Cur_idx = left_child;
	if ((right_child <= N) && (Arr[right_child] > Arr[Cur_idx]))
		Cur_idx = right_child;

	if (Cur_idx != Current)
	{
		swap(Arr[Cur_idx], Arr[Current]);
		Heapify(Cur_idx, N);
	}
}

void HeapSort()
{
	Build_heap();
	for (int i = MAX;i >= 2;i--)
	{
		swap(Arr[i], Arr[1]);
		Heapify(1, i - 1);
	}
}

int main(void)
{
	srand((unsigned)time(NULL));
	for (int i = 1; i <= MAX;)
	{
		Arr[i] = rand() % 300 + 1;
		if (Flag[Arr[i]] == false)
		{
			Flag[Arr[i]] = true;
			i++;
		}
	}

	cout << "[Initilal Array State]" << endl;
	Print();
	HeapSort();
	cout << "[Array State After Heap Sorting]" << endl;
	Print();

	return 0;
}