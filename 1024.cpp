//最优二叉搜索树
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int m, n,num;//m组测试数据，n个关键字
double a[501],p[501], q[501];//关键字、关键字概率、关键字外区间概率
double c[501][501], w[501][501];//c[i][j]表示第i+1到j个key构造的最优二叉树的代价（平均搜索长度），则c[0][n]是最后结果
//w[i][j]表示第i+1到j个key权值及第i到j个空隙权值和
int main() {
	cin >> m;
	while (m--) 
	{
		cin >> n;
		for (int i = 1; i <= n; i++) {//关键字数组下标从1开始
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++) {//关键字概率数组下标从1开始
			cin >> p[i];
		}
		for (int i = 0; i <= n; i++) {//关键字外区间概率数组下标从0开始
			cin >> q[i];
			c[i][i] = 0;
			w[i][i] = q[i];
		}
		for (int x = 1; x <= n; x++) {
			for (int i = 0; i <= n - x; i++) {
				int j = i + x;
				c[i][j] = 0x3f3f3f3f;
				w[i][j] = w[i][j - 1] + p[j] + q[j];
				for (int k = i+1; k <= j; k++) {
					double t = w[i][j];
					if (k>= i) {
						t += c[i][k-1];
					}
					if (k + 1 <= j) {
						t += c[k][j];
					}
					if (t < c[i][j]) {
						c[i][j] = t;
					}
				}
			}
		}
		//cout << c[0][n] << endl;
		printf("%.6f\n",c[0][n]);
	}
	return 0;
}


