#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int m, n, x;
	cin >> m;
	while (m--) {
		cin >> n;
		cin >> x;
		vector<int>h(n, 0);
		vector<int>h_(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> h[i];
			h_[i] = x - h[i];
		}
		unique(h.begin(), h.end());
		unique(h_.begin(), h_.end());
		for (int i = 0; i < h.size(); i++) {
			cout << h[i] << " ";
		}
		cout << endl;
		for (int i = 0; i < h.size(); i++) {
			cout << h_[i] << " ";
		}
		cout << endl;
		sort(h.begin(), h.end());
		sort(h_.begin(), h_.end());
		int i = 0;
		int j = 0;
		while (i < n && j < n) {

			if (h[i] < h[j])
				i++;
			else if (h[i] > h[j])
				j++;
			else if (h[i] == h[j]) {
				cout << "yes" << endl;
				break;
			}
		}
		if (i == n || j == n)
			cout << "no" << endl;
	}
	return 0;
}