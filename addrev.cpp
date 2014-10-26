/*
	http://www.spoj.com/problems/ADDREV/
	Print the reversed sum of two reversed numbers
*/
#include <bits/stdc++.h>

using namespace std;

int reverseNumber(int n){
	int t = 0;
	while (n != 0){
		t *= 10;
		t = t + n%10;
		n = n/10;
	}
	return t;
}

int main(){
	int t, a1, a2, v1;
	cin >> t;
	while(t--){
		cin >> a1;
		cin >> a2;
		v1 = reverseNumber(a1) + reverseNumber(a2);
		cout << reverseNumber(v1) << endl;
	}
	return 0;
}

