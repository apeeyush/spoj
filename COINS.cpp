/*
    http://www.spoj.com/problems/COINS/
    Max dollar for gold coin
*/

#include <iostream>
#include <algorithm>

#define MAXNUM 200000000

using namespace std;

unsigned int maxAmount[MAXNUM] = {0};

void precomputeMaxAmounts(){
    maxAmount[0]=0;
    for(unsigned int i=1; i<=MAXNUM; i++){
        maxAmount[i]=max(maxAmount[i/2]+maxAmount[i/3]+maxAmount[i/4] , i);
    }
}

unsigned int computeAmount(int num){
    if(num < MAXNUM){
        return maxAmount[num];
    }else{
        return max(computeAmount(num/2)+computeAmount(num/3)+computeAmount(num/4) , (unsigned)num);
    }
}

int main()
{
    precomputeMaxAmounts();
    int tmp;
    while (cin >> tmp){
        cout << computeAmount(tmp) << endl;
    }
    return 0;
}
