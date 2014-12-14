/*
	http://www.spoj.com/problems/BYECAKES/
	Calculate quantity to buy
*/
#include <iostream>
#include <math.h>

using namespace std;

int main(){
	int E, F , S, M , E1 , F1 , S1, M1;
	cin >> E >> F >> S >> M >> E1 >> F1 >> S1 >> M1;
	while(E != -1){
		int ans = 0;
		int numCakes = max( max(ceil(E*1.0/E1), ceil(M*1.0/M1)), max(ceil(F*1.0/F1), ceil(S*1.0/S1)) );

		if (numCakes*E1-E > 0)
			cout << numCakes*E1-E << " ";
		else
			cout << 0 << " ";
		if (numCakes*F1-F > 0)
			cout << numCakes*F1-F << " ";
		else
			cout << 0 << " ";
		if (numCakes*S1-S > 0)
			cout << numCakes*S1-S << " ";
		else
			cout << 0 << " ";
		if (numCakes*M1-M > 0)
			cout << numCakes*M1-M << " ";
		else
			cout << 0 << " ";
		cout << endl;
		cin >> E >> F >> S >> M >> E1 >> F1 >> S1 >> M1;
	}

	return 0;
}
