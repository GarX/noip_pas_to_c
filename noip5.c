#include <stdio.h>

int main() {
  int cmin,sum,i,j,n,k,a[101],b[101],d[101],s[31];

  scanf("%d %d",&n,&k);
  for(i = 1;i <= n;i ++){
    scanf("%d",a+i);
  }
  for(i = 0;i <= n;i ++){
    b[i] = 1;
  }
  cmin = 1000000;
  while(b[0] == 1){
    for(i = 1;i <= k;i ++){
      s[k] = 0;
    }
    for(i = 1;i <= n;i ++){
      s[b[i]] = s[b[i]] + a[i];
    }
    sum = 0;
    for(i = 1;i <= k - 1;i ++){
      for(j = i + 1;j <= k;j ++){
        sum = sum + (s[i] - s[j]) * (s[i] - s[j]);
      }
    }
    if(sum < cmin){
      cmin = sum;
      for(i = 1;i <= n;i ++){
        d[i] = b[i];
      }
    }
    j = n;
    while(b[j] == k){
      j --;
    }
    b[j] ++;
    for(i = j + 1;i <= n;i ++){
      b[i] = 1;
    }
  }
  printf("%d\n",cmin);
  for(i = 1;i <= n;i ++){
    printf("%40d",d[i]);
  }

}

