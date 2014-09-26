#include <stdio.h>

int i,j,sp1,sp2,l,max;
int tree[21][7];
int q[101][7];
int d[21];


int main(){
  for(i = 1;i <= 14;i ++){
    for(j = 1;j <= 6;j ++){
      tree[i][j] = 0;
    }
  }

  for(j = 1;j <= 14;j ++){
    tree[j][i] = j;
  }
  tree[1][2] = 2;
  tree[1][3] = 3;
  tree[1][4] = 4;
  tree[2][2] = 5;
  tree[2][3] = 6;
  tree[3][2] = 7;
  tree[3][3] = 8;
  tree[4][2] = 9;
  tree[4][3] = 10;
  tree[4][4] = 11;
  tree[7][2] = 12;
  tree[7][3] = 13;
  tree[13][2] = 14;
  sp1 = 1;
  sp2 = 1;
  for(i = 1;i <= 6;i ++){
    q[1][i] = tree[1][i];
  }
  q[1][0] = 1;
  while(sp1 <= sp2){
    l = q[sp1][0] + 1;
    j = 2;
    while(q[sp1][j] != 0){
      sp2 ++;
      q[sp2][0] = l;
      q[sp2][1] = q[sp1][j];
      for(i = 2;i <= 6;i ++){
        q[sp2][i] = tree[q[sp1][j]][i];
      }
      j ++;
    }
    sp1 ++;
  }
  printf("%d\n",q[sp2][0]);
  for(i = 0;i <= 20;i ++){
    d[i] = 0;
  }
  for(i = 1;i <= sp2;i ++){
    d[q[i][0]] = d[q[i][0]] + 1;
  }
  max = d[1];
  for(i = 2;i <= 20;i ++){
    if(d[i] > max){
      max = d[i];
    }
  }
  printf("%d\n",max);
}
