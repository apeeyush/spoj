/*
	http://www.spoj.com/problems/FCTRL2/
	Calculate factorial for number lying b/w 1 and 100
*/
#include <bits/stdc++.h>

using namespace std;

int factorial[101][10000] = {0};

void precomputeFactorial(){
	factorial[0][0] = 1;
	for (int i=1;i<=100;i++){
		for (int j=0;j<9998;j++){
			factorial[i][j] = factorial[i-1][j]*i;
			factorial[i][j+1] += factorial[i][j]/10;
			factorial[i][j] = factorial[i][j]%10;
		}
	}
	for (int i=1;i<=100;i++){
		for(int j=0;j<9999;j++){
			factorial[i][j+1] += factorial[i][j]/10;
			factorial[i][j] = factorial[i][j]%10;
		}
	}
}

int main(){
	precomputeFactorial();
	int t, input;
	cin >> t;
	while(t--){
		cin >> input;
		int check = 0;
		int qw = 9999;
		while(check == 0 && qw-- ){
			if (factorial[input][qw] != 0)
				check = 1;
		}
		qw++;
		while(qw--)
			cout << factorial[input][qw];
		cout << endl;
	}
	return 0;
}