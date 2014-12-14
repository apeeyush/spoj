/*
	http://www.spoj.com/problems/MISERMAN/
	Calculate min fare (DP)
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int N, M;
	cin >> N >> M;
	int fare[100][100] = {0};
	int DP[100][100] = {0};
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin >> fare[i][j];
		}
	}
	for(int j=0; j<M; j++){
		DP[0][j] = fare[0][j];
	}
	for(int i=1;i<N;i++){
		for(int j=0; j<M; j++){
			int min_up = DP[i-1][j];
			if(j-1>=0){
				min_up = min(min_up, DP[i-1][j-1]);
			}
			if(j+1<M){
				min_up = min(min_up, DP[i-1][j+1]);
			}
			DP[i][j] = fare[i][j] + min_up;
		}
	}
	int min_fare = DP[N-1][0];
	for(int j=0; j<M; j++){
		min_fare = min(min_fare, DP[N-1][j]);
	}
	cout << min_fare;
	return 0;
}
