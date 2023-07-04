#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int m, n, h[105], dp[105], ans1, ans2;
	cin >> m;
	while (m--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> h[i];
			dp[i] = 1;  // 初始化 dp 数组
		}
		ans1 = ans2 = 0;
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j < i; j++) {
				if (h[j] >= h[i]) {
					dp[i] = max(dp[i], dp[j] + 1);  // 状态转移方程
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			ans1 = max(ans1, dp[i]);  // 计算最长下降子序列的长度
		}
		ans2 = ceil((double)n / ans1);  // 计算最少需要配备的系统数量
		cout << ans1 << " " << ans2 << endl;
	}
	return 0;
}
