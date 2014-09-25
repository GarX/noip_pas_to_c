#include <stdio.h>
#include <stdbool.h>

long i,k,m,start;
bool find;

bool check(int remain){
  int result;
  result = (start + m - 1)  % remain;
  if(result >= k){
    start = result;
    return true;
  } else {
    return false;
  }
}

int main() {
  find = false;
  scanf("%ld",&k);
  m = k;
  while(!find) {
    find = true;
    start = 0;
    for(i = 0;i <= k - 1;i ++){
      if(!check(2 * k - i)){
        find = false;
        break;
      }
    }
    m ++;
  }
  printf("%ld",m - 1);
}
