/*
	http://www.spoj.com/problems/SILVER/
	Min cuts on the silver bar such that all integers from 1 to n are possible
*/
#include <iostream>

using namespace std;

int main(){
	int N;
	cin >> N;
	while(N){
		int count = 0;
		while(N >= 2){
			count += 1;
			N = N/2;
		}
		cout << count << endl;
		cin >> N;
	}
	return 0;
}