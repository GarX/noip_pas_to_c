#include <stdio.h>
#include <math.h>

int main() {
  float a,b,c,r,s,t;

  scanf("%f %f %f",&a,&b,&c);
  s = (a + b + c) / 2;
  t = sqrt(s * (s - a) * (s - b) * (s - c));
  r = t / s;
  printf("%0.2f", 3.1415927 * r * r);
  return 0;
}
