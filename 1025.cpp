#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int m, n, h[10000], dp[10000], ans1;
int main() {
	
	cin >> m;
	while (m--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> h[i];
			dp[i] = 1;  // ��ʼ�� dp ����
		}
		ans1  = 0;
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j < i; j++) {
				if (h[j] <= h[i]) {//dp[i]��ʾ��iλ֮ǰ��ǽ������г���
					dp[i] = max(dp[i], dp[j] + 1);  // ״̬ת�Ʒ���
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			ans1 = max(ans1, dp[i]);  // ������ǽ������еĳ���
		}
		cout << ans1 << endl;
	}
	return 0;
}
