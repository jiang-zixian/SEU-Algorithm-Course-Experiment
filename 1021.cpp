#include <iostream>
#include<vector>
#include <map>
#include<algorithm>
#include <math.h>
using namespace std;
int m, n, k;
//int* r = new int(n + 1);//r[i]表示长度为i米的钢条的最大收益
int r[10000];
int main()
{
	cin >> m;
	while (m--) {
		cin >> n;//钢条长度
		cin >> k;//价格表有几组
		vector<int>Lvec(1, 0);//长度
		vector<int>Pvec(1, 0);//价格
		map<int, int>mp;
		for (int i = 1; i <= k; i++) {//输入
			int p1, p2;
			cin >> p1;
			cin >> p2;
			mp.insert(pair<int, int>(p1, p2));
		}
		map<int, int>::iterator it;
		for (it = mp.begin(); it != mp.end(); it++) {
			Lvec.push_back(it->first);
			Pvec.push_back(it->second);
		}

		if (n < Lvec[1])
		{
			cout << 0 << endl;
			continue;
		}
		for (int i = 0; i < Lvec[1]; i++)
		{
			r[i] = 0;
		}
		int q = 0;
		for (int i = 0; i <= n; i++)//钢条最大长度递增
		{
			for (int j = 1; j <= k; j++)
			{
				if (i >= Lvec[j])
				{
					q = max(q, Pvec[j] + r[i - Lvec[j]]);
				}
				else
					break;
			}
			r[i] = q;
		}
		cout << q << endl;
	}
	return 0;
}



