//最长公共子序列
#include <iostream>
#include <algorithm>
#include<vector>
#include <string>
#include <cmath>
using namespace std;
int m, num,lenA,lenB;//num表示结果
char A[500], B[500];//两个字符串
int LCS[501][501];//LCS[i][j]表示A数组前i个字母和B数组前j个字母的最长公共子序列
int main() {
	cin >> m;
	char c = getchar();
	

	while (m--) {
		lenA = 0;
		lenB = 0;
		while ((c = getchar()) != EOF && lenA <= 500) {
			if (c != '\n')A[(lenA++)+1] = c;//第0位不放字母
			if ('\n' == c)  break;
		}
		while ((c = getchar()) != EOF && lenB <= 500) {
			if (c != '\n') B[(lenB++)+1] = c;
			if ('\n' == c)  break;
		}

		for (int i = 0; i <= 500; i++)
		{
			for (int j = 0; j <= 500; j++)
			{
				LCS[i][j] = 0;
			}
		}
		
		for (int i = 1; i <= lenA; i++)
		{
			for (int j = 1; j <= lenB; j++)
			{
				if (A[i] == B[j]) {
					LCS[i][j] = 1 + LCS[i - 1][j - 1];
				}
				else {
					LCS[i][j] = max(LCS[i][j - 1], LCS[i - 1][j]);
				}
			}
		}
		cout << LCS[lenA][lenB] << endl;//注意不是LCS[lenA-1][lenB-1]
	}
	return 0;
}
