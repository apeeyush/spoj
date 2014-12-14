/*
	http://www.spoj.com/problems/STAMPS/
	Tell the minimum number of friends she needs to borrow from (Sorting)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int numCases;
	cin >> numCases;
	for(int i=0; i<numCases; i++){
		int numStamps, numFriends, stampCount, count = 0, sum = 0;
		vector<int> stampsCount;
		cin >> numStamps >> numFriends;
		for(int j=0; j<numFriends; j++){
			cin >> stampCount;
			stampsCount.push_back(stampCount);
		}
		sort(stampsCount.begin(), stampsCount.end(), greater<int>());
		vector<int>::iterator it = stampsCount.begin();
		int flag = 0;
		while(it!=stampsCount.end() && flag!=1){
			sum += *it;
			count += 1;
			if(sum >= numStamps){
				flag = 1;
			}
			it++;
		}
		cout << "Scenario #" << i+1 << ":" << endl;
		if(sum >= numStamps)
			cout << count << endl;
		else
			cout << "impossible" << endl;
		cout << endl;
	}
	return 0;
}
