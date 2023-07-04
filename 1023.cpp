#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include <limits.h>
#include<queue>
using namespace std;

// 表示与某一国家相邻的编号为v的国家，w表示二者距离
struct country {
	int v, w;
};

//world[i]中存储了所有与i国相邻的国家以及它们的距离
vector <country> world[505];

//m表示从起点到达点v后剩余的钱，dis则表示走的距离
struct vertex {
	int m, dis, v;
};

struct mycompare
{
	bool operator()(vertex a, vertex b)
	{
		return a.dis > b.dis;
	}
};

priority_queue<vertex, vector<vertex>, mycompare> arr;//优先级队列，将点按照dis从小到大排列


int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		//小A所在世界的国家数、国家之间的总道路数、小A的国籍、小A向往的国家以及小A的家底
		int n, E, s, t, M;

		int cost[505];  //国家花费
		int distance[505][105]; //distance[i][j]表示剩余钱数为j的情况下,从起点走到i点走过的距离
		bool flag[505][105]; //flag数组用于标记某个顶点在剩余一定钱数时是否已经被遍历过


		//初始化
		memset(distance, -1, sizeof(distance));
		memset(flag, false, sizeof(flag));

		cin >> n >> E >> s >> t >> M;
		for (int i = 1; i <= n; i++)
			cin >> cost[i];
		int x, y, z;
		for (int i = 0; i < E; i++)
		{
			cin >> x >> y >> z;
			country temp;
			temp.v = y;
			temp.w = z;
			world[x].push_back(temp);
			temp.v = x;
			world[y].push_back(temp);
		}


		//初始化起点
		vertex temp;
		temp.m = M; temp.dis = 0; temp.v = s; distance[temp.v][M] = 0;
		arr.push(temp);


		//更新distance[][]数组
		while (!arr.empty())
		{
			temp = arr.top();
			arr.pop();
			int p = temp.v;

			//如果当前顶点已经访问过，或者起点到该顶点的距离已经大于distance[temp.v][temp.m],就没有必要继续下去了
			if (flag[p][temp.m] || temp.dis > distance[temp.v][temp.m])
				continue;
			flag[p][temp.m] = true;

			for (int i = 0; i < world[p].size(); i++)
			{
				int v = world[p][i].v;
				if (v == s)
					continue;  //跳过起点

				//钱够，并且花费同样的钱，从temp.v过来的路程更少
				if (temp.m >= cost[v] && (distance[v][temp.m - cost[v]] == -1 ||
					temp.dis + world[p][i].w < distance[v][temp.m - cost[v]]))
				{
					distance[v][temp.m - cost[v]] = temp.dis + world[p][i].w;
					vertex point;
					point.dis = distance[v][temp.m - cost[v]];
					point.v = v;
					point.m = temp.m - cost[v];
					arr.push(point);
				}
			}
		}


		//在distance[t][j]中进行遍历，找到剩余j钱的情况下走到t的最短路程。
		int ans = INT_MAX; bool index = 0;
		for (int i = 0; i <= M; i++)
			if (distance[t][i] != -1) {
				ans = min(ans, distance[t][i]);
				index = 1;
			}
		if (!index)
			cout << -1 << endl;
		else
			cout << ans << endl;


		//清空
		for (int i = 1; i <= n; i++)
			world[i].clear();
	}
}
