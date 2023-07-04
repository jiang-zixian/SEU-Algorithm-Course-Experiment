#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 50;

int n, k;
char str[N];
int f[N][10];

int main() {
	int T;
	cin >> T;
	while (T -- ) {
		cin >> n >> k >> str + 1;

		memset(f, 0, sizeof f);

		for (int i = 1; i <= n; i ++ )
			str[i] -= '0';

		for (int i = 1; i <= n; i ++ )
			for (int j = 1; j <= k && j <= i - 1; j ++ ) {
				for (int u = j - 1; u < i; u ++ )
					f[i][j] = max(f[i][j], f[u][j - 1] * (int)(str[u + 1] - '0'));
			}

		cout << f[n][k] << endl;
	}
	return 0;
}
