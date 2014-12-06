/*
	http://www.spoj.com/problems/FASHION/
	Return the sum of maximum hotness bonds for all pairs
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int calcMaxSumHotness(){
	int maxSum=0, numPeople, tmp;
	vector<int> menHotness, womenHotness;
	cin >> numPeople;
	for(int i=0; i<numPeople; i++){
		cin >> tmp;
		menHotness.push_back(tmp);
	}
	for(int i=0; i<numPeople; i++){
		cin >> tmp;
		womenHotness.push_back(tmp);
	}
	sort(menHotness.begin(), menHotness.end());
	sort(womenHotness.begin(), womenHotness.end());
	for(int i=0; i<numPeople; i++){
		maxSum += menHotness[i]*womenHotness[i];
	}
	return maxSum;
}

int main(){
	int numCases;
	cin >> numCases;
	while(numCases--){
		cout << calcMaxSumHotness() << endl;
	}
	return 0;
}