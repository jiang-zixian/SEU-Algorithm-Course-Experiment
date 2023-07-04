//岛国难题
//注意，不可以用float，会wrong answer,只能double
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include<iomanip>
using namespace std;
int m, N;//岛屿被分为N个部分
double pi[1001];//N-1座桥梁，每座桥梁坍塌的概率

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
			ans += pi[i];//数学公式，最后等于1+p1+p2+...+pn
		}
		cout << fixed << setprecision(6) << ans << endl;
	}
	return 0;
}
