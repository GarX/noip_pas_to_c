#include <stdio.h>

int main() {
  int i,j,n,yu,j0,j1,s;
  int b[31],c[31],d[31],e[31];

  scanf("%d",&n);
  for (i = 1;i <= n;i ++){
    scanf("%d %d %d",b + i, c + i,d + i);
  }
  for (i = 1;i <= n;i ++){
    e[i] = 0;
  }
  c[n + 1] = 10000;
  c[n + 2] = 0;
  b[n + 1] = 0;
  j0 = 1;
  while(j0 <= n) {
    yu = c[j0];
    j1 = j0;
    s = b[j0];
    while(yu + d[j1] < c[j1 + 1]) {
      yu = yu + d[j1];
      j1 = j1 + 1;
      s = s + b[j1];
    }
    e[j0] = s;
    j0 = j1 + 1;
  }
  for (i = 1;i <= n;i ++){
    printf("%4d",e[i]);
  }
  return 0;
}
