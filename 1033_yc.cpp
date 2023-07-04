#include<iostream>
#include<algorithm>
using namespace std;
#define job struct j
bool* deadline;

struct j
{
    int price;
    int ddl;
};

bool com(const job& x, const job& y)
{
    return x.price >= y.price;
}
job* work;

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int N;
        long long rev = 0;//������
        cin >> N;
        work = new job[N + 2];

        int max_ddl = 0;
        for (int i = 0; i < N; i++)
        {
            cin >> work[i].ddl >> work[i].price;
            if (work[i].ddl > max_ddl)
                max_ddl = work[i].ddl;
        }
        if (max_ddl == 0) {
            cout << 0 << endl;
            continue;
        }
        deadline = new bool[max_ddl + 1];
        for (int i = 0; i < max_ddl + 1; i++)
        {
            deadline[i] = 1;
        }
        //���水���潫work��������
        sort(&work[0], &work[N], com);//���۸������������ҵ��
        for (int j = 0; j <= N - 1; j++) // ����work����
        {
            for (int ptr = work[j].ddl; ptr >= 1; ptr--)
            {
                if (deadline[ptr])
                {
                    rev += work[j].price;
                    deadline[ptr] = 0;
                    break;
                }
            }
        }
        cout << rev << endl;
    }
}
