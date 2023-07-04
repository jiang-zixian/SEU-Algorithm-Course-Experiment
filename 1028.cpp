//�Ͻ�˹�����㷨
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int m, n,E,s,t; //m��������ݣ�������������������s�Լ�����t.
int edge[501][501];
int dis[501];
int sel[501];//��ʾ������Ƿ񱻷��ʹ�
int flag=1;//��¼��ǰ�ǲ������е㶼�����ʹ���

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
			if (dis[i] < minEdge&&sel[i]==0)//�ҵ���С��
			{
				minEdge = dis[i];
				minPoint = i;
				flag = 0;
			}
		}
		if (flag == 1)//�����е㶼��ѡ���
		{
			break;
		}
		sel[minPoint] = 1;//����㱻���ʹ���
		for (int i = 1; i <= n; i++)//����dis����
		{
			dis[i] = min(dis[i], minEdge + edge[minPoint][i]);
		}
	}
}

int main() {
	cin >> m;
	while (m--)
	{
		cin >> n;//������������������s�Լ�����t.
		cin >> E;
		cin >> s;
		cin >> t;
		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= n; j++)
			{
				edge[i][j] = 0x3f3f3f3f;//��ʼ��Ϊ�����
			}
			edge[i][i] = 0;
		}
		for (int i = 0; i <= n; i++)
		{
			sel[i] = 0;//δ������
		}
		sel[s] = 1;//��㱻����
		int u1, v1, w1;
		for (int i = 0; i <E; i++) {//��������ߵ���Ϣ
			cin >> u1;
			cin >> v1;
			cin >> w1;
			edge[u1][v1] = min(edge[u1][v1], w1);
			edge[v1][u1] = edge[u1][v1];//�����
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
