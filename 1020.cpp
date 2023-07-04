#include <iostream>
#include<vector>
#include <map>
#include<algorithm>
using namespace std;

int m,n;
vector<int>row;
vector<int>col;

int MatrixChain(int i,int j, int** m)//����ֵΪm[i,j],����i�����󵽵�j���������С�˷�����
{
	if (i == j) {
		m[i][j] = 0; 
		return 0;
	}
	m[i][j] = 0x3f3f3f3f;
	for (int k = i; k < j; k++)
	{
		int a = m[i][k];
		int b = m[k + 1][j];
		int q;
		if (a == -1)
			a = MatrixChain(i, k,m);
		if (b == -1)
			b = MatrixChain(k + 1, j, m);
		q = a + b + row[i] * col[k] * col[j];
		if (q < m[i][j])
			m[i][j] = q;
	}
	return m[i][j];
}

int main() {
	cin >> m;
	while (m--) {
		cin >> n;//�������
		row.clear();
		col.clear();
		for (int i = 1; i <= n; i++) {
			int p1, p2;
			cin >> p1;
			cin >> p2;
			row.push_back(p1);
			col.push_back(p2);
		}
		int** m = new int* [n];          //��ֲ������ӽṹ��Ӧ����˴���                             
		for (int i = 0; i < n; i++)           
			m[i] = new int[n];
		for(int i=0;i<n;i++)
			for (int j = 0; j < n; j++)
				m[i][j] = -1;//��ʼ��
		cout << MatrixChain(0, n - 1,m) << endl;
	}
	return 0;
}