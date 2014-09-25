#include <stdio.h>

int main() {
  int i,j,n,s;
  int b[101],d[101][21];
  int g[1001];
  scanf("%d",&n);
  for(i = 1;i <= n + 1;i ++){
    scanf("%d",&d[i][0]);
    for(j = 1;j <= d[i][0];j ++){
      scanf("%d",&d[i][j]);
    }
  }
  d[0][0] = 1;
  for(i = 1;i <= n + 1;i ++){
    b[i] = 1;
  }
  b[0] = 0;
  for(i = 0;i <= 1000;i ++){
    g[i] = 0;
  }
  while(b[0] == 0){
    s = 0;
    for(i = 1;i <= n + 1;i ++){
      s = s + d[i][b[i]];
    }
    g[s] = 1;
    j = n + 1;
    while(b[j] == d[j][0]){
      j --;
    }
    b[j] = b[j] + 1;
    for(i = j + 1;i <= n + 1;i ++){
      b[i] = 1;
    }
  }
  s = 0;
  for(i = 1;i <= 1000;i ++){
    s = s + g[i];
  }
  printf("%d",s);
}
