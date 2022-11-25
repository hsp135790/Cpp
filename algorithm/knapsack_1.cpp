#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int w[101]; //����
int v[101]; //��ġ
int dp[101];

int N, K; //��ǰ�� �� N, ��ƿ �� �ִ� ���� K

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;

	for (int i = 1;i <= N;i++)
	{
		cin >> w[i] >> v[i];

	}

	for (int i = 1;i <= N;i++)
	{
		for (int j = K;j >= 1;j--)
		{
			if (w[i] <= j)
			{
				dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
			}
		}
	}
	cout << dp[K];
	return 0;
}