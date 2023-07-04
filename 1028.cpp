//迪杰斯特拉算法
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int m, n,E,s,t; //m组测试数据，顶点数、边数、顶点s以及顶点t.
int edge[501][501];
int dis[501];
int sel[501];//表示这个点是否被访问过
int flag=1;//记录当前是不是所有点都被访问过了

void dijkstra()
{
	int minPoint = s;
	for (int i = 1; i <= n; i++)
	{
		dis[i] = edge[minPoint][i];
	}
	while (1)
	{
		int minEdge = 0x3f3f3f3f;
		flag = 1;
		for (int i = 1; i <= n; i++)
		{
			if (dis[i] < minEdge&&sel[i]==0)//找到最小的
			{
				minEdge = dis[i];
				minPoint = i;
				flag = 0;
			}
		}
		if (flag == 1)//当所有点都被选择过
		{
			break;
		}
		sel[minPoint] = 1;//这个点被访问过了
		for (int i = 1; i <= n; i++)//更新dis数组
		{
			dis[i] = min(dis[i], minEdge + edge[minPoint][i]);
		}
	}
}

int main() {
	cin >> m;
	while (m--)
	{
		cin >> n;//顶点数、边数、顶点s以及顶点t.
		cin >> E;
		cin >> s;
		cin >> t;
		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= n; j++)
			{
				edge[i][j] = 0x3f3f3f3f;//初始化为无穷大
			}
			edge[i][i] = 0;
		}
		for (int i = 0; i <= n; i++)
		{
			sel[i] = 0;//未被访问
		}
		sel[s] = 1;//起点被访问
		int u1, v1, w1;
		for (int i = 0; i <E; i++) {//输入无向边的信息
			cin >> u1;
			cin >> v1;
			cin >> w1;
			edge[u1][v1] = min(edge[u1][v1], w1);
			edge[v1][u1] = edge[u1][v1];//无向边
		}

		dijkstra();

		if (dis[t] < 0x3f3f3f3f)
		{
			cout << dis[t] << endl;
		}
		else
		{
			cout << -1 << endl;
		}
	}
	return 0;
}
