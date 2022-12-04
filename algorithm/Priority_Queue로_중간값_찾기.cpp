#include<iostream>
#include<queue>

#define MAX 100010
using namespace std;

int N;
int Arr[MAX];

void Input()
{
	cin >> N;

	for (int i = 0;i < N;i++)
	{
		cin >> Arr[i];
	}

}

void solution()
{
	priority_queue<int> MAX_PQ, MIN_PQ;

	for (int i = 0;i < N;i++)
	{
		if (MAX_PQ.size() > MIN_PQ.size())
		{
			MIN_PQ.push(Arr[i]);
		}
		else
		{
			MAX_PQ.push(Arr[i]);
		}

		if (MAX_PQ.empty() == false && MIN_PQ.empty() == false)
		{
			int MAX_VALUE = MAX_PQ.top();
			int MIN_VALUE = MIN_PQ.top();

			MAX_PQ.pop();
			MIN_PQ.pop();

			MAX_PQ.push(MIN_VALUE);
			MIN_PQ.push(MAX_VALUE);
		}
		cout << MAX_PQ.top() << endl;
	}
	
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	Input();
	solution();

	return 0;
}