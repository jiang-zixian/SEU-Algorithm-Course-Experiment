//��Ȩ�ѡ��
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int m, n;//m��������ݣ������
int mostWeight[10001];//mostWeight[i]��ʾ��i�����֮ǰ�Ļ�ļ��Ͽɻ�õ����Ȩֵ
struct activity
{
	int si; // si��ʾ���ʼʱ��
	int fi; // fi��ʾ��Ľ���ʱ��
	int vi; // vi��ʾ���Ȩ��

	// ���캯��
	activity(int start, int end, int weight)
	{
		si = start;
		fi = end;
		vi = weight;
	}
};

//�º���
bool cmp(const activity& a, const activity& b) {//�������ʱ������
	return a.fi < b.fi;
}

int selAct(vector<activity>& act)
{
	sort(act.begin(), act.end(), cmp);//�������ʱ������
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
		cin >> n;//�����
		vector<activity>act;
		act.push_back(activity(0,0,0));//��±��1��ʼ
		int u1, v1, w1;
		for (int i = 0; i < n; i++) {//��������ߵ���Ϣ
			cin >> u1;
			cin >> v1;
			cin >> w1;
			act.push_back(activity(u1, v1, w1));
		}
		cout << selAct(act) << endl;
	}
	return 0;
}
