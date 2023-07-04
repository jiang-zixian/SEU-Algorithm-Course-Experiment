#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int getans(int n, int ans1, int ans2, vector<int> &h, vector<int> &dp) {
	for (int i = 1; i <= n; i++) {
		dp[i] = 1; // 初始化 dp 数组
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (h[j] >= h[i]) {
				dp[i] = max(dp[i], dp[j] + 1); // 状态转移方程
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		ans1 = max(ans1, dp[i]); // 计算最长下降子序列的长度
	}
	return ans1;
}

int main() {
	int m, n, ans1, ans2;

	cin >> m;
	while (m--) {
		vector<int> h(100);
		vector<int> dp(100);
		cin >> n;
		h.erase(h.begin() + n + 1, h.begin() + 100);
		dp.erase(dp.begin() + n + 1, dp.begin() + 100);
		for (int i = 1; i <= n; i++) {
			cin >> h[i];
			dp[i] = 1; // 初始化 dp 数组
		}
		ans1 = ans2 = 0;
		cout << getans(n, ans1, ans2, h, dp) << " ";
		int count = 0;

		int test = n;
		// 然后扫描dp数组，将所有长度为ans1的不上升子序列的元素顺序删除
		while (h.size() > 1) {
			int temp = getans(h.size() - 1, ans1, ans2, h, dp);
			for (int i = test; i >= 1 && temp > 0; i--) {

				if (dp[i] == temp) {
					h.erase(h.begin() + i);
					dp.erase(dp.begin() + i);
					test--;
					temp--;
				}

			}

			count++;

		}
		cout << count << endl;
	}
}
