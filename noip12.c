#include <stdio.h>

int L = 19;
int SZ = 50;
char UP = '/';
char DN = '\\';

int i,nth,x,y,h,e,f;
int m[2][39][20];
char pic[50][50];

void init(){
  int k,s,a,b,c;
  for(a = 0;a <= 1;a ++){
    for(b = 0;b <= 2 * L;b ++){
      for(c = 0;c <= L;c ++){
        m[a][b][c] = 0;
      }
    }
  }
  m[0][0][0] = 1;
  for(k = 0;k <= 2 * L - 1;k ++){
    for(s = 1;s <= L;s ++){
      m[0][k + 1][s] = m[0][k][s + 1] + m[1][k][s + 1];
      m[1][k + 1][s] = m[0][k][s - 1] + m[1][k][s - 1];
    }
    m[0][k + 1][0] = m[0][k][1] + m[1][k][1];
  }
}


void draw(int k,int s,int nth) {
  printf("k = %d s = %d nth = %d\n",k,s,nth);
  if(k == 0){
    return;
  }
  if(nth - m[1][k][s] >= 0){
    nth = nth - m[1][k][s];
    if(y > h){
      h = y;
    }
    printf("y = %d x = %d UP\n",y,x);
    pic[y][x] = UP;
    y ++;
    x ++;
    draw(k - 1,s + 1,nth);
  } else {
    y = y - 1;
    printf("y = %d x = %d DOWN\n",y,x);
    pic[y][x] = DN;
    x ++;
    draw(k - 1,s - 1,nth);
  }
}

int main(){
  init();
  scanf("%d",&nth);
  for(e = 0;e <= SZ -1;e ++){
    for(f = 0;f <= SZ -1;f ++){
      pic[e][f] = ' ';
    }
  }
  x = y = h = i = 0;
  while(nth - m[0][2 * i][0] >= 0){
    nth = nth - m[0][2 * i][0];
    i ++;
  }
  draw(2 * i,0,nth);
  printf("h = %d x = %d\n",h,x);
  for(i = h;i >= y;i --){
    for(e = 0;e <= x - 1;e ++){
      printf("%c",pic[i][e]);
    }
    printf(" \n");
  }
}
