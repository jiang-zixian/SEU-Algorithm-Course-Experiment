//���Ŷ���������
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int m, n,num;//m��������ݣ�n���ؼ���
double a[501],p[501], q[501];//�ؼ��֡��ؼ��ָ��ʡ��ؼ������������
double c[501][501], w[501][501];//c[i][j]��ʾ��i+1��j��key��������Ŷ������Ĵ��ۣ�ƽ���������ȣ�����c[0][n]�������
//w[i][j]��ʾ��i+1��j��keyȨֵ����i��j����϶Ȩֵ��
int main() {
	cin >> m;
	while (m--) 
	{
		cin >> n;
		for (int i = 1; i <= n; i++) {//�ؼ��������±��1��ʼ
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++) {//�ؼ��ָ��������±��1��ʼ
			cin >> p[i];
		}
		for (int i = 0; i <= n; i++) {//�ؼ�����������������±��0��ʼ
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


