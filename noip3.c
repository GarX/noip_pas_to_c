#include <stdio.h>
#include <stdbool.h>

int main() {
  int i,j,k,n;
  bool p;
  int a[21][11],b[21];

  scanf("%d %d",&n,&k);
  for(i = 1;i <= k;i ++){
    for(j = 1;j <= n;j ++){
      scanf("%d",&a[i][j]);
    }
  }
  for(i = 0;i <= n;i ++){
    b[i] = 0;
  }

  p = true;
  while(p && b[0] == 0){
    j = n;
    while(b[j] == 1){
      j --;
    }
    b[j] = 1;
    p = false;
    for(i = j + 1;i <= n;i ++) {
      b[i] = 0;
    }
    for(i = 1;i <= k;i ++){
      if((a[i][j] == 1 && b[j] == 0) || (a[i][j] == -1 && b[j] == 1)){
        p = true;
      }
    }
  }
  if(p){
    printf("找不到!");
  } else {
    for (i = 1;i <= n;i ++){
      if(b[i] == 1){
        printf("物质 %d 需要",i);
      } else {
        printf("物质 %d 不需要",i);
      }
    }
  }
}
