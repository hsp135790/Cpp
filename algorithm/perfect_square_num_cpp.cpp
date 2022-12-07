#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	int M, N, sum = 0, cnt = 0, small = 10001;

	cin >> M >> N;

	for (int i = 1;i <= 100;i++)
	{
		if (i * i >= M && i * i <= N)
		{
			sum = sum + i * i;
			cnt++;
		}
		if (i * i >= M && i * i <= N && small > i * i)
			small = i * i;
	}

	if (cnt == 0)
	{
		cout << "-1";
		return 0;
	}
	cout << sum << "\n" << small;


}