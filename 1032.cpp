//��������
//ע�⣬��������float����wrong answer,ֻ��double
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include<iomanip>
using namespace std;
int m, N;//���챻��ΪN������
double pi[1001];//N-1��������ÿ������̮���ĸ���

int main() {
	cin >> m;
	double ans = 1;
	while (m--)
	{
		cin >> N;
		ans = 1;
		for (int i = 0; i < N-1; i++)
		{
			cin >> pi[i];
			pi[i] = pi[i] / 100;
		}
		for (int i = 0; i < N-1; i++)
		{
			ans += pi[i];//��ѧ��ʽ��������1+p1+p2+...+pn
		}
		cout << fixed << setprecision(6) << ans << endl;
	}
	return 0;
}
