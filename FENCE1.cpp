/*
	http://www.spoj.com/problems/FENCE1/
	Output the largest area for the given length (and an infinite wall)
*/
#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	double pi = 3.1415926535897;
	int length;
	cin >> length;
	while(length){
		float max_area = (length*length/pi)/2;
		printf("%.2f\n", max_area);
		cin >> length;
	}
	return 0;
}
