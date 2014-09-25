#include <stdio.h>

int main(){
  int i,j,k,sp,d,l;
  int dk[101][3];
  scanf("%d",&sp);
  for(i = 1;i <= sp;i ++){
    scanf("%d %d",&dk[i][1],&dk[i][2]);
  }
  dk[0][1] = dk[0][2] = 0;
  sp ++;
  dk[sp][1] = 10000;
  dk[sp][2] = 0;
  scanf("%d %d",&d,&l);
  i = 1;
  while(dk[i][1] < d){
    i = i + 1;
  }
  i --;
  if(dk[i][1] + dk[i][2] == d) {
    if(d + l == dk[i + 1][1]){
      dk[i][2] = dk[i][2] + l + dk[i + 1][2];
      for(j = i + 1;j <= sp - 1;j ++){
        for(k = 0;k <= 2;k ++){
          dk[j][k] += dk[j + 1][k];
        }
      }
      sp --;
    } else {
      dk[i][2] = dk[i][2] + l;
    }
  } else if(d + l == dk[i + 1][1]) {
    dk[i + 1][1] = d;
    dk[i + 1][2] = dk[i + 1][2] + l;
  } else {
    for(j = sp;j >= i + 1;j --){
      for(k = 0;k <= 2;k ++){
        dk[j + 1][k] = dk[j][k];
      }
    }
    dk[i + 1][1] = d;
    dk[i + 1][2] = l;
    sp ++;
  }
  for(i = 1;i <= sp - 1;i ++){
    printf("%4d %4d",dk[i][1],dk[i][2]);
  }
}
