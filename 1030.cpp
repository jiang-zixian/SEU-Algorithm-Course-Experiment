//黑白连线
//贪心算法，从左向右遍历2n个点，遇到黑点时，找到与其最近的还未被连线的白点，
//左边的白点优先于右边的，因为该黑点右边的黑点连接左边的白点所造成的连线长度一定比该黑点的大
//所以从左向右遍历点，遇到黑点时，找该黑点左边的与其连线最近的白点配对，若左边没有白点再去找右边的最近的白点
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int m, n;//n个黑点和n个白点
int p[20000];//黑点和白点序列
int sel[20000];//记录对应位置的点是否被选过
int main() {
	cin >> m;
	int len = 0;
	while (m--)
	{
		cin >> n;
		for (int i = 0; i < 2 * n; i++)
		{
			cin >> p[i];
		}
		for (int i = 0; i < 2 * n; i++)
		{
			sel[i] = 0;
		}
		len = 0;//总连线长度
		for (int i = 0; i < 2 * n; i++)
		{
			if (p[i] == 1)//黑点，找距离最近的白点
			{
				if (sel[i] == 0)
				{
					for (int j = 1; i - j >= 0; j++)
					{//先找左边的
						if (i - j >= 0 && p[i - j] == 0 && sel[i - j] == 0 && sel[i] == 0)
						{
							sel[i - j] = 1;
							sel[i] = 1;
							len += j;
							break;
						}
					}
				}
				if (sel[i] == 0)
				{//再找右边的
					for (int j = 1; i + j < 2 * n; j++)
					{
						if (i + j >= 0 && p[i + j] == 0 && sel[i + j] == 0)
						{
							sel[i + j] = 1;
							sel[i] = 1;
							len += j;
							break;
						}
					}
				}
				
			}
		}
		cout << len << endl;
	}
	return 0;
}
