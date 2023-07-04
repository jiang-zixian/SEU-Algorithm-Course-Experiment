//带权活动选择
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int m, n;//m组测试数据，活动数量
int mostWeight[10001];//mostWeight[i]表示第i个活动及之前的活动的集合可获得的最大权值
struct activity
{
	int si; // si表示活动开始时间
	int fi; // fi表示活动的结束时间
	int vi; // vi表示活动的权重

	// 构造函数
	activity(int start, int end, int weight)
	{
		si = start;
		fi = end;
		vi = weight;
	}
};

//仿函数
bool cmp(const activity& a, const activity& b) {//按活动结束时间排序
	return a.fi < b.fi;
}

int selAct(vector<activity>& act)
{
	sort(act.begin(), act.end(), cmp);//按活动结束时间排序
	mostWeight[0] = 0;
	mostWeight[1] = act[1].vi;
	for (int i = 2; i <= n; i++)
	{
		for (int j=i;j>=0;j--)
		{
			if (act[j].fi <= act[i].si)
			{
				mostWeight[i] = max(mostWeight[j] + act[i].vi, mostWeight[i - 1]);
				break;
			}
		}
	}
	return mostWeight[n];
}

int main() {
	cin >> m;
	while (m--)
	{
		cin >> n;//活动数量
		vector<activity>act;
		act.push_back(activity(0,0,0));//活动下标从1开始
		int u1, v1, w1;
		for (int i = 0; i < n; i++) {//输入无向边的信息
			cin >> u1;
			cin >> v1;
			cin >> w1;
			act.push_back(activity(u1, v1, w1));
		}
		cout << selAct(act) << endl;
	}
	return 0;
}
