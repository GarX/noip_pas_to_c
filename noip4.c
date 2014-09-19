#include <stdio.h>

int main() {
  int a[37],b[32];
  int i,j,k,s,p;
  for(i = 1;i <= 36;i ++){
    a[i] = 0;
  }
  for(i = 28;i <= 32;i ++){
    a[i] = 1;
  }
  p = 1;
  a[6] = 1;
  while(p == 1){
    j = 27;
    while(a[j] == 1){
      j --;
    }
    a[j] = 1;
    for(i = j + 1;i <= 27;i ++){
      a[i] = 0;
    }
    for(i = 0;i <= 31;i ++){
      b[1] = 0;
    }
    for(i = 1;i <= 32;i ++){
      s = 0;
      for(k = i;k <= i + 4;k ++){
        s = s*2 + a[k];
      }
      b[s] = 1;
    }
    s = 0;
    for(i = 0;i <= 31;i ++){
      s = s + b[i];
    }
    if (s == 32){
      p = 0;
    }
  }
  for(i = 1;i <= 32;i ++){
    for(j = i;j <= i + 4;j ++){
      printf("%d",a[j]);
    }
    printf("\n");
  }
  return 0;
}
