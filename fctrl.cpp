/*
	http://www.spoj.com/problems/FCTRL/
	Number of zeros at the end of n!
*/

#include <bits/stdc++.h>

using namespace std;

int numZerosAtEnd(int n){
	int m = 5;
	int ans = 0;
	while (n/m != 0){
		ans += n/m;
		m=m*5;
	}
	return ans;
}

int main(){
	int t, input;
	cin >> t;
	while(t--) {
		cin >> input;
	    cout << numZerosAtEnd(input) << endl;
	}
}