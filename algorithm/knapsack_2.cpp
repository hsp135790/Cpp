#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int w[101]; //무게
int v[101]; //가치
int dp[101][10001];

int N, K; //물품의 수 N, 버틸 수 있는 무게 K

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		cin >> w[i] >> v[i];

	}

	for (int i = 1;i <= N;i++)
	{
		for (int j = 1;j <= K;j++)
		{
			if (j - w[i] >= 0)
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			}

			else
			{
				dp[i][j] = dp[i - 1][j];
			}


		}
		
	}
	cout << dp[N][K];
	return 0;




}

