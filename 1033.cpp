//������ҵ
#include <iostream>
#include <algorithm>
#include <cmath>
#include<map>
#include<queue>
using namespace std;
int m, N;//N����ҵ
int di[50001];//��ֹʱ��
int pi[50001];//����
int main() {
	cin >> m;
	long long ans = 0;//������
	int clock = 0;//��ǰʱ��
	while (m--)
	{
		cin >> N;
		multimap<int, int>w;//����map������ʱ������
		int p, q, i, j;
		ans = 0;
		for (i = 1; i <= N; i++)
		{
			cin >> p;
			cin >> q;
			w.insert(pair<int, int>(p, q));
		}
		multimap<int, int>::iterator it;
		i = 1;
		j = 1;
		for (it = w.begin(); it != w.end(); it++) {
			di[i++] = it->first;
			pi[j++] = it->second;//�������еĹ���������ʱ����������
		}
		//priority_queue<int> maxHeap;
		clock = 0;
		int maxn = 0;
		int maxi = 0;
		for (i = 1; i <= N; i++ )
		{

			for (j = 1; j <= N; j++)
			{
				if (di[j] == clock + 1)
				{
					maxn = max(maxn, pi[j]);
					maxi = j;
					continue;
				}
				else if(di[j] > clock + 1)
				{
					if (di[j] == di[i])
					{
						maxn = max(maxn, pi[j]);
						maxi = j;
						continue;
					}
					else {
						break;
					}
				}
			}
			ans += maxn;
			if (maxn == 0)
			{
				maxi = 0;
			}
			pi[maxi] = 0;
			maxn = 0;
			maxi = 0;
			clock++;
		}
		cout << ans << endl;
	}
	return 0;
}
