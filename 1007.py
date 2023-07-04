if __name__ == '__main__':
    M = int(input())
    for _ in range(M):
        N, K, num = input().split()
        N, K = int(N), int(K)
        dp = [[0] * (K + 1) for _ in range(N + 1)]
        for i in range(1, N + 1):
            dp[i][0] = int(num[:i])
        for i in range(2, N + 1):
            for j in range(1, min(K + 1, i)):
                for k in range(j - 1, i - 1):
                    dp[i][j] = max(dp[i][j], dp[k][j - 1] * int(num[k + 1:i]))
        print(dp[N][K])