//�ڰ�����
//̰���㷨���������ұ���2n���㣬�����ڵ�ʱ���ҵ���������Ļ�δ�����ߵİ׵㣬
//��ߵİ׵��������ұߵģ���Ϊ�úڵ��ұߵĺڵ�������ߵİ׵�����ɵ����߳���һ���ȸúڵ�Ĵ�
//���Դ������ұ����㣬�����ڵ�ʱ���Ҹúڵ���ߵ�������������İ׵���ԣ������û�а׵���ȥ���ұߵ�����İ׵�
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int m, n;//n���ڵ��n���׵�
int p[20000];//�ڵ�Ͱ׵�����
int sel[20000];//��¼��Ӧλ�õĵ��Ƿ�ѡ��
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
		len = 0;//�����߳���
		for (int i = 0; i < 2 * n; i++)
		{
			if (p[i] == 1)//�ڵ㣬�Ҿ�������İ׵�
			{
				if (sel[i] == 0)
				{
					for (int j = 1; i - j >= 0; j++)
					{//������ߵ�
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
				{//�����ұߵ�
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
