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
			dp[i] = 1;  // ��ʼ�� dp ����
		}
		ans1 = ans2 = 0;
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j < i; j++) {
				if (h[j] >= h[i]) {
					dp[i] = max(dp[i], dp[j] + 1);  // ״̬ת�Ʒ���
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			ans1 = max(ans1, dp[i]);  // ������½������еĳ���
		}
		ans2 = ceil((double)n / ans1);  // ����������Ҫ�䱸��ϵͳ����
		cout << ans1 << " " << ans2 << endl;
	}
	return 0;
}
