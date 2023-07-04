#include<bits/stdc++.h>
#include <iostream>
#include<time.h>
#include<vector>
#define pi 3.1415926
using namespace std;

int v[8];
int mapf[501][501];
int x[100001], y[100001], now, cs[100001], fx[100001];

void get_viewpoint() {
	cout << 3 << endl;
	string viewpoint;
	cin >> viewpoint;
	int i_bin;
	for (int i = 0; i < 8; i++)
	{
		i_bin = (int)viewpoint[i];
		v[i] = i_bin - 48;
	}
}

void 

void do_action() {
	int finish = 0;
	//fill(mapf[0], mapf[0] + 501 * 501, 1);
	for (int i = 0; i <= 500; i++) {//地图初始化，0访问过，1没访问过
		for (int j = 0; j <= 500; j++) {
			mapf[i][j] = 1;
		}
	}
	mapf[0][0] = 0;//初始在(0,0)
	now = 1;//时间值
	x[now] = 0;
	y[now] = 0;
	fx[now] = 0;//方向
	cs[now] = 1;
	while (now > 0) {
		int dx, dy;//下一步移动方向
		double ddy = cos((fx[now]) * pi / 4);
		double ddx = -sin((fx[now]) * pi / 4);
		if (ddy >= 0)
			dy = (int)(ddy + 0.5);
		else
			dy = (int)(ddy - 0.5);
		if (ddx >= 0)
			dx = (int)(ddx + 0.5);
		else
			dx = (int)(ddx - 0.5);

		if (mapf[x[now] + dx][y[now] + dy])
		{
			get_viewpoint();
		}
		if ((v[3] == 0) && (mapf[x[now] + dx][y[now] + dy])) {
			cout << 2 << endl;//可走
			now++;
			x[now] = x[now - 1] + dx;
			y[now] = y[now - 1] + dy;//x,y数组记录当前位置
			cs[now] = 1;
			fx[now] = fx[now - 1];//方向不变
			mapf[x[now]][y[now]] = 0;//访问过这个点了
			cin >> finish;
			if (finish == 1) return;
		}
		else {//当前方向不能走
			cout << 1 << endl;//换方向
			fx[now] = (fx[now] + 1) % 8;
			cs[now]++;//再试一个方向
			if (cs[now] > 8) {//八个方向都试过了，回溯
				cout << 1 << endl << 1 << endl << 1 << endl << 1 << endl << 2 << endl;
				cin >> finish;
				cout << 1 << endl << 1 << endl << 1 << endl << 1 << endl;//再按回溯之前的方向试
				now--;
			}
		}
	}
}
int main() {
	int map_num;
	cin >> map_num;
	while (map_num--) {
		do_action();
	}
	return 0;
}
