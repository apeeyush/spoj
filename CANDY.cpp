/*
	http://www.spoj.com/problems/CANDY/
	Print the smallest number of moves to equalize candies
*/
#include <iostream>

using namespace std;

int countNumMoves(int N){
	int tmp, sum=0, count=0, avg, values[N];
	for(int i=0; i<N; i++){
		cin >> tmp;
		values[i] = tmp;
		sum += tmp;
	}
	if(sum%N != 0){
		return -1;
	}else{
		avg = sum/N;
		for(int i=0; i<N; i++){
			if (values[i] > avg)
				count += values[i]-avg;
		}
		return count;
	}
}

int main(){
	int N;
	cin >> N;
	while(N != -1){
		cout << countNumMoves(N) << endl;
		cin >> N;
	}
	return 0;
}
