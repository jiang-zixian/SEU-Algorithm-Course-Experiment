#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int m, n;
	cin >> m;
	while (m--) {
		cin >> n;
		vector<int>h(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> h[i];
		}
		for (int i = 0; i < n; i++) {
			cout << h[i] << "  ";
		}
		cout << endl;
		int sum = 0;
		int ans = h[0]; //记录当前最大子数组和
		for (int i = 0; i < n; i++) {
			if (sum > 0) {
				sum += h[n];
			} else {
				sum = h[n];
			}
			ans = max(ans, sum);
			cout << ans << endl;
		}
		cout << ans << endl;
	}
	return 0;
}