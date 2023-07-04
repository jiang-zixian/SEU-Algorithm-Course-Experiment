#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include <limits.h>
#include<queue>
using namespace std;

// ��ʾ��ĳһ�������ڵı��Ϊv�Ĺ��ң�w��ʾ���߾���
struct country {
	int v, w;
};

//world[i]�д洢��������i�����ڵĹ����Լ����ǵľ���
vector <country> world[505];

//m��ʾ����㵽���v��ʣ���Ǯ��dis���ʾ�ߵľ���
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

priority_queue<vertex, vector<vertex>, mycompare> arr;//���ȼ����У����㰴��dis��С��������


int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		//СA��������Ĺ�����������֮����ܵ�·����СA�Ĺ�����СA�����Ĺ����Լ�СA�ļҵ�
		int n, E, s, t, M;

		int cost[505];  //���һ���
		int distance[505][105]; //distance[i][j]��ʾʣ��Ǯ��Ϊj�������,������ߵ�i���߹��ľ���
		bool flag[505][105]; //flag�������ڱ��ĳ��������ʣ��һ��Ǯ��ʱ�Ƿ��Ѿ���������


		//��ʼ��
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


		//��ʼ�����
		vertex temp;
		temp.m = M; temp.dis = 0; temp.v = s; distance[temp.v][M] = 0;
		arr.push(temp);


		//����distance[][]����
		while (!arr.empty())
		{
			temp = arr.top();
			arr.pop();
			int p = temp.v;

			//�����ǰ�����Ѿ����ʹ���������㵽�ö���ľ����Ѿ�����distance[temp.v][temp.m],��û�б�Ҫ������ȥ��
			if (flag[p][temp.m] || temp.dis > distance[temp.v][temp.m])
				continue;
			flag[p][temp.m] = true;

			for (int i = 0; i < world[p].size(); i++)
			{
				int v = world[p][i].v;
				if (v == s)
					continue;  //�������

				//Ǯ�������һ���ͬ����Ǯ����temp.v������·�̸���
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


		//��distance[t][j]�н��б������ҵ�ʣ��jǮ��������ߵ�t�����·�̡�
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


		//���
		for (int i = 1; i <= n; i++)
			world[i].clear();
	}
}
