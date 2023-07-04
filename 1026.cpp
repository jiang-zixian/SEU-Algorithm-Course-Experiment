#include<iostream>
#include<algorithm>
#include<cmath>
#include <numeric>
using namespace std;

long long solution(int a[], int n, int k)
{
	long long* sum = new long long[n];
	sum[0] = a[0];
	for (int i = 1; i < n; i++)//前i个数的和
	{
		sum[i] = sum[i - 1] + a[i];
	}
	long long** dp = new long long* [n];
	for (int i = 0; i < n; i++)
		dp[i] = new long long[k + 1];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			dp[i][j] = 0;//dp[i][j]表示前i个数字有j个乘号的情况下的最大值
		}
	}
	dp[0][0] = sum[0];
	for (int i = 0; i < n; i++)
		dp[i][0] = sum[i];
	for (int i = 1; i < n; i++)
		for (int j = 1; j <= i && j <= k; j++)
			for (int t = 0; t < i; t++)
			{
				dp[i][j] = max(dp[i][j], dp[t][j - 1] * (sum[i] - sum[t]));
			}
	long long ans = dp[n - 1][k];
	delete[]dp;
	return ans;
}

int main()
{
	int M;
	cin >> M;//M组数据
	while (M--)
	{
		int N;
		int k;
		cin >> N;
		cin >> k;
		int* a = new int[N];
		for (int i = 0; i < N; i++)
		{
			a[i] = 0;
			cin >> a[i];
		}
		long long ans = solution(a, N, k);
		cout << ans << endl;
	}

}

