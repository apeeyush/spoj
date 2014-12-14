/*
	http://www.spoj.com/problems/CRSCNTRY/
	Longest Common Subsequence (DP)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lcs(vector<int> seq1, vector<int> seq2, int seq1count, int seq2count){
	int maxMeets[seq1count+1][seq2count+1];
	for(int i=0; i<=seq1count; i++){
		for(int j=0; j<=seq2count; j++){
			if(i==0 || j==0)
				maxMeets[i][j] = 0;
			else{
				if(seq1[i-1] == seq2[j-1])
					maxMeets[i][j] = 1 + maxMeets[i-1][j-1];
				else
					maxMeets[i][j] = max(maxMeets[i-1][j],maxMeets[i][j-1]);
			}
		}
	}
	return maxMeets[seq1count][seq2count];
}

void caclMaxMeets(){
	vector<int> seq1;
	int tmp, maxMeets=0, seq1count=0;
	cin >> tmp;
	while(tmp){
		seq1.push_back(tmp);
		seq1count++;
		cin >> tmp;
	}
	cin >> tmp;
	while(tmp){
		vector<int> seq2;
		int seq2count=1;
		seq2.push_back(tmp);
		cin >> tmp;
		while(tmp){
			seq2.push_back(tmp);
			seq2count++;
			cin >> tmp;
		}
		maxMeets = max(maxMeets,lcs(seq1, seq2,seq1count,seq2count));
		cin >> tmp;
	}
	cout << maxMeets << endl;
}

int main(){
	int numCases;
	cin >> numCases;
	while(numCases--){
		caclMaxMeets();
	}
	return 0;
}
