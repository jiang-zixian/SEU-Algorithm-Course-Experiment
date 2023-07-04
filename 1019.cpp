#include <iostream>
#include<vector>
#include <map>
#include<algorithm>
#include <math.h>
using namespace std;

int main()
{
	int m, n, c;

	cin >> m;
	while (m--) {
		cin >> n;//宝石数目
		cin >> c;//背包容量
		int** dp = new int* [n+1];          //dp有n行c列，dp[i][j]表示前i件宝石装进限重为j的背包中可获得的最大价值                     
		for (int i = 0; i < n+1; i++)
			dp[i] = new int[c + 1];
		vector<int>s;//重量
		vector<int>p;//价值
		s.push_back(0);
		p.push_back(0);
		for (int i = 1; i <= n; i++) {//输入
			int p1, p2;
			cin >> p1;
			cin >> p2;
			s.push_back(p1);
			p.push_back(p2);
		}
		for (int i = 0; i <= c; i++)
			dp[0][i] = 0;//表示没有宝石的时候时价值为0
		for (int i = 0; i <= n; i++)
			dp[i][0] = 0;//背包容量为0时价值为0

		for (int j = 1; j <= c; j++) {
			for (int i = 1; i <= n; i++) {
				if (j < s[i])//当背包装不下第i个宝石
					dp[i][j] = dp[i - 1][j];
				else {
					dp[i][j] = max(dp[i - 1][j], p[i] + dp[i - 1][j - s[i]]);
				}
			}
		}
		cout << dp[n][c] << endl;
	}
	return 0;
}



