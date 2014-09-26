#include <stdio.h>
#include <stdbool.h>

int m;

int solve(int m){
  int i,t,d;
  bool flag;
  int ret;

  if(m == 1){
    ret = 2;
  } else {
    d = 2 * m + 1;
    t = 2;
    i = 1;
    flag = false;
    do{
      if(t == 1){
        ret = i * m;
        flag = true;
      } else if(t == 2 * m){
        ret = i * m - 1;
        flag = true;
      } else {
        t = (t * 2) % d;
      }
      i ++;
    }while(!flag);
  }
  return ret;
}

int main() {
  scanf("%d",&m);
  if(m > 0 && m < 1000){
    printf("%d",solve(m));
  }
}
