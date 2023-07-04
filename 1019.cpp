#include <iostream>
#include<vector>
#include <map>
#include<algorithm>
#include <math.h>
using namespace std;

int main()
{
	int m, n, c;

	cin >> m;
	while (m--) {
		cin >> n;//��ʯ��Ŀ
		cin >> c;//��������
		int** dp = new int* [n+1];          //dp��n��c�У�dp[i][j]��ʾǰi����ʯװ������Ϊj�ı����пɻ�õ�����ֵ                     
		for (int i = 0; i < n+1; i++)
			dp[i] = new int[c + 1];
		vector<int>s;//����
		vector<int>p;//��ֵ
		s.push_back(0);
		p.push_back(0);
		for (int i = 1; i <= n; i++) {//����
			int p1, p2;
			cin >> p1;
			cin >> p2;
			s.push_back(p1);
			p.push_back(p2);
		}
		for (int i = 0; i <= c; i++)
			dp[0][i] = 0;//��ʾû�б�ʯ��ʱ��ʱ��ֵΪ0
		for (int i = 0; i <= n; i++)
			dp[i][0] = 0;//��������Ϊ0ʱ��ֵΪ0

		for (int j = 1; j <= c; j++) {
			for (int i = 1; i <= n; i++) {
				if (j < s[i])//������װ���µ�i����ʯ
					dp[i][j] = dp[i - 1][j];
				else {
					dp[i][j] = max(dp[i - 1][j], p[i] + dp[i - 1][j - s[i]]);
				}
			}
		}
		cout << dp[n][c] << endl;
	}
	return 0;
}



