import sys
def main(argv):
    if(len(sys.argv) == 1):
        print(0)
    elif(len(sys.argv) == 2):
        print(len(sys.argv[1]))
    else:
        S = sys.argv[1]
        T = sys.argv[2]
        dp = [[0 for i in range(len(S)+1)] for j in range(len(T)+1)]
        for i in range(len(T)+1):
            for j in range(len(S)+1):
                dp[i][j] = sys.maxsize
        # print(dp)
        dp[0][0] = 0
        for i in range(-1,len(T)):
            for j in range(-1,len(S)):
                if(i >= 0 and j>= 0):
                    if(T[i] == S[j]):
                        dp[i+1][j+1] = min(dp[i+1][j+1],dp[i][j])
                    else:
                        dp[i+1][j+1] = min(dp[i+1][j+1],dp[i][j] + 1)
                if (i >= 0):
                    dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j+1] + 1);
                if (j >= 0):
                    dp[i+1][j+1] = min(dp[i+1][j+1], dp[i+1][j] + 1);
    # print(dp)
    print(dp[len(T)][len(S)])
