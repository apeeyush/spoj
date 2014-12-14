/*
	http://www.spoj.com/problems/PIGBANK/
	Minimum amount of money that can be achieved using coins with the given total weight (DP)
*/
#include <iostream>

using namespace std;

void calculateMinWeight(){
	int E, F, coinsWeight, numCoins, tmpP, tmpW;
	cin >> E >> F >> numCoins;
	int P[500], W[500], DP[10000];
	coinsWeight = F-E;
	for(int i=0;i<numCoins;i++){
		cin >> tmpP >> tmpW;
		P[i] = tmpP;
		W[i] = tmpW;
	}
	DP[0] = 0;
	for(int i=1; i<=coinsWeight; i++){
		DP[i] = -1;
		for(int j=0; j<numCoins; j++){
			if(i-W[j] >= 0 && (DP[i] == -1 || DP[i] > DP[i-W[j]] + P[j] ))
				if (DP[i-W[j]] != -1)
					DP[i] = DP[i-W[j]] + P[j];
		}
	}
	if(DP[coinsWeight] != -1)
		cout << "The minimum amount of money in the piggy-bank is " << DP[coinsWeight] << "." << endl;
	else
		cout << "This is impossible." << endl;
}


int main(){
	int numCases;
	cin >> numCases;
	while(numCases--){
		calculateMinWeight();
	}
	return 0;
}
