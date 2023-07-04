//��С������
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int m, n, E; //m��������ݣ�������������


struct edge
{
	int u; // ���
	int v; // �յ�
	int w; // ����ߵ�Ȩֵ

	// ���캯��
	edge(int start, int end, int weight)
	{
		u = start;
		v = end;
		w = weight;
	}
};

// ���鼯���ݽṹ
struct UnionFind {
	vector<int> parent;
	vector<int> rank;

	UnionFind(int n) {
		parent.resize(n + 1);
		rank.resize(n + 1, 0);
		for (int i = 1; i <= n; ++i) {
			parent[i] = i;
		}
	}

	int find(int x) {
		if (parent[x] != x) {
			parent[x] = find(parent[x]);
		}
		return parent[x];
	}

	void unite(int x, int y) {
		int rootX = find(x);
		int rootY = find(y);
		if (rootX == rootY) {
			return;
		}
		if (rank[rootX] < rank[rootY]) {
			parent[rootX] = rootY;
		}
		else if (rank[rootX] > rank[rootY]) {
			parent[rootY] = rootX;
		}
		else {
			parent[rootY] = rootX;
			rank[rootX]++;
		}
	}
};

bool cmp(const edge& a, const edge& b) {
	return a.w < b.w;
}

int kruskal(vector<edge>& edges) {
	UnionFind uf(n);
	sort(edges.begin(), edges.end(), cmp);//�º����ı�sort����

	int totalWeight = 0;
	int numEdges = 0;

	for (int i = 0; i < edges.size(); i++) {
		const edge& e = edges[i];
		if (uf.find(e.u) != uf.find(e.v)) {
			uf.unite(e.u, e.v);
			totalWeight += e.w;
			numEdges++;
		}
		if (numEdges == n - 1) {
			break;
		}
	}

	if (numEdges == n - 1) {
		return totalWeight;
	}
	else {
		return -1;
	}
}


int main() {
	cin >> m;
	
	while (m--)
	{
		cin >> n;//������������������s�Լ�����t.
		cin >> E;
		vector<edge>edges;
		int u1, v1, w1;
		for (int i = 0; i < E; i++) {//��������ߵ���Ϣ
			cin >> u1;
			cin >> v1;
			cin >> w1;
			edges.push_back(edge(u1, v1, w1));
		}
		cout << kruskal(edges) << endl;
	}
	return 0;
}
