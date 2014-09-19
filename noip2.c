#include <stdio.h>
#include <stdbool.h>

int n,k;
int len[10001];
int i,left,right,mid;

bool isok(int t){
  int num,i;
  num = 0;
  for(i = 1;i <= n;i ++){
    if(num >= k){
      break;
    }
    num = num + len[i] / t;
  }
  return num >= k;
}

int main(){
  scanf("%d %d",&n,&k);
  right = 0;
  for(i = 1;i <= n;i ++){
    scanf("%d",len + i);
    if(right < len[i]){
      right = len[i];
    }
  }
  right ++;
  left = 0;
  while(left + 1 < right) {
    mid = (left + right) / 2;
    if (!isok(mid)) {
      right = mid;
    } else {
      left = mid;
    }
  }
  printf("%d",left);
  return 0;
}
