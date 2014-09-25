#include <stdio.h>

int i,j,n,max,min,w,x,y;
int r[21][21];
int eet[21],et[21];

int main(){
  scanf("%d",&n);
  for(i = 1;i <= n;i ++){
    for(j = 1;j <= n;j ++){
      r[i][j] = -1;
    }
  }
  scanf("%d %d %d",&x,&y,&w);
  while(x != 0){
    r[x][y] = w;
    scanf("%d %d %d",&x,&y,&w);
  }
  eet[1] = 0;
  for(i = 2;i <= n;i ++){
    max = 0;
    for(j = 1;j <= n;j ++){
      if(r[j][i] != -1){
        if(r[j][i] + eet[j] > max){
          max = r[j][i] + eet[j];
        }
      }
    }
  }
  et[n] = eet[n];
  for(i = n - 1;i >= 1;i --){
    min = 10000;
    for(j = 1;j <= n;j ++){
      if(r[i][j] != -1){
        if(et[j] - r[i][j] < min){
          min = et[j] - r[i][j];
        }
      }
    }
  }
  printf("%d\n",eet[n]);
  for(i = 1;i <= n - 1;i ++){
    if(eet[i] == et[i]){
      printf("%d ->",i);
    }
  }
  printf("%d",n);
}
