#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 50;
int n, k;
char num[MAXN];
long long dp[MAXN][10]; // dp[i][j]表示前i个数分成j+1个部分的最大乘积

int main() {
	int t;
	cin >> t;//测试几组数据
	cout << "t=" << t << endl;
	while (t--) {
		cin >> n >> k >> num + 1;
		cout << "n=" << n << endl;
		cout << "k=" << k << endl;
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++) {
			dp[i][0] = dp[i - 1][0] * 10 + num[i] - '0'; // 不分割的情况
			cout << dp[i][0] << endl;
		}
		for (int i = 2; i <= k + 1; i++) { // 枚举分割次数
			for (int j = 1; j <= min(k + 1, i); j++) { // 枚举分割点
				for (int p = j - 1; p <= i - 1; p++) { // 枚举上一次分割点
					dp[i][j] = max(dp[i][j], dp[p][j - 1] * (dp[j][0] - dp[p][0]));
				}
			}
		}
		cout << dp[n][k] << endl;
	}
	return 0;
}