/*
  http://www.spoj.com/problems/ACPC10A/
  Determine if AP or GP and print the next number
*/
#include <bits/stdc++.h>

using namespace std;

int is_ap(int a1, int a2, int a3){
  return a2-a1 == a3-a2;
}

int is_gp(int a1, int a2, int a3){
  return (a3*a1) == (a2*a2);
}

int main(){
  int a1, a2, a3, res;
  scanf("%d%d%d", &a1, &a2, &a3);
  while( a1 != 0 || a2 != 0 || a3 != 0){
    if ( is_ap(a1,a2,a3) ){
      res = a3 + (a3 - a2);
      printf("AP %d", res);
    }
    if( is_gp(a1,a2,a3) ){
      res = a3 * (a2/a1);
      printf("GP %d", res);
    }
    printf("\n");
    scanf("%d%d%d", &a1, &a2, &a3);
  }
  return 0;
}