#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_L 4096
#define GAP 30

char str[100][MAX_L];
char str1[MAX_L], str2[MAX_L];
int l1, l2;
int dp[MAX_L+1][MAX_L+1];
int res = 0;

int min(int a, int b){
  if(a < b) return a;
  else return b;
}

int main(int argc, char const *argv[])
{
  int i,j,n,m,l,cost;
  scanf("%d", &n);
  for(i = 0; i < n; i++) scanf("%s", str[i]);
  for(l = 0; l < n;l++)for(m = l+1;m < n;m++){
    l1 = strlen(str[l]);
    strcpy(&str1[1], str[l]);
    l2 = strlen(str[m]);
    strcpy(&str2[1], str[m]);
    for (i = 0; i <= l1; i++)
    {
      dp[i][0] = i;
    }
    for (i = 0; i <= l2; i++)
    {
      dp[0][i] = i;
    }
    for(i = 1; i <= l1; i++){
      for(j = i-GAP; j <= i+GAP; j++){
        if(j <= 0) continue;
        if(j > l2) break;
        if(str1[i] == str2[j]) cost = 0;
        else cost = 1;
        //printf("i=%d j=%d cost=%d %c %c\n", i, j, cost, str1[i], str2[j]);
        dp[i][j] = dp[i-1][j-1]+cost;
        if(j > i-GAP) dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
        if(j < i+GAP) dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
        //printf("i=%d j=%d dp=%d\n", i,j,dp[i][j]);
      }
    }
    //printf("%d\n", dp[l1][l2]);
    if(dp[l1][l2] < 10) res++;
  }
  printf("%d\n", res);
  return 0;
}
