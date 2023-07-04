#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	int m, n, x;
	cin >> m;
	while (m--) {
		cin >> n;
		cin >> x;
		vector<int>h(n, 0);
		vector<int>h_(n, 0);
		multimap<int, int>mp;
		for (int i = 0; i < n; i++) {
			cin >> h[i];
			mp.insert(pair<int, int>(h[i], x - h[i]));
		}
		int flag = 0;
		for (multimap<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
			if (mp.find(it->second) != mp.end() ) {
				cout << "yes" << endl;
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			cout << "no" << endl;
		}
	}
	return 0;
}