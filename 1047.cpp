#include<bits/stdc++.h>
#define pi 3.1415926
using namespace std;

int v[8];
bool mapf[501][501];
int x[100001], y[100001], now, cs[100001], fx[100001];

void get_viewpoint(){    
    cout<<3<<endl;
    string viewpoint; 
	cin >> viewpoint;
	int i_bin;
	for(int i=0;i<8;i++)
	{
		i_bin = (int)viewpoint[i];
		v[i] = i_bin - 48;
	}
}
void do_action() {
	int finish = 0;
	for (int i = 0; i <= 500; i++) {
		for (int j = 0; j <= 500; j++) {
			mapf[i][j] = true;
		}
	}
	mapf[0][0] = false;
	now = 1;
	x[now] = 0;
	y[now] = 0;
	fx[now] = 0;
	cs[now] = 1;
	while (now > 0) {
		get_viewpoint();
		int dx,dy;
		double ddy = cos((fx[now])*pi/4);
		double ddx = -sin((fx[now])*pi/4);
		if(ddy>=0)
			dy = (int) (ddy+0.5);
		else
			dy = (int) (ddy-0.5);
		if(ddx>=0)
			dx = (int) (ddx+0.5);
		else
			dx = (int) (ddx-0.5);
		if ((v[3] == 0) && (mapf[x[now] + dx][y[now] + dy])) {
			cout << 2 << endl;
			now++;
			x[now] = x[now - 1] + dx;
			y[now] = y[now - 1] + dy;
			cs[now] = 1;
			fx[now] = fx[now - 1];
			mapf[x[now]][y[now]] = false;
			cin >> finish;
			if (finish == 1) return;
		}
		else {
			cout << 1 << endl;
			fx[now] = (fx[now] + 1) % 8;
			cs[now]++;
			if (cs[now] > 8) {
				cout << 1 << endl << 1 << endl << 1 << endl << 1 << endl << 2 << endl;
				cin >> finish;
				cout << 1 << endl << 1 << endl << 1 << endl << 1 << endl;
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
