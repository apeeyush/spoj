/*
	http://www.spoj.com/problems/PT07Y/
	Given an unweighted, undirected graph, check if it's a tree topology
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<int>* adj;

bool noCycle(){
	bool visited[N+1];
	int front, parent[N+1];
	vector<int>::iterator myIntIterator;
	for(int i=0; i<N+1; i++){
		visited[i] = false;
		parent[i] = -1;
	}
	for(int i=1; i<=N; i++){
		if(!visited[i]){
			queue<int> myQueue;
			myQueue.push(i);
			visited[i] = true;
			while(!myQueue.empty()){
				front = myQueue.front();
				myQueue.pop();
				for(myIntIterator=adj[front].begin(); myIntIterator != adj[front].end(); myIntIterator++){
					if(*myIntIterator != parent[front]){
						if(visited[*myIntIterator] == true){
							return false;
						}else{
							myQueue.push(*myIntIterator);
							visited[*myIntIterator] = true;
							parent[*myIntIterator] = front;
						}
					}
				}
			}
		}
	}
	return true;
}

int main(){
	int v1, v2;
	cin >> N >> M;
	adj = new vector<int>[N+1];
	for(int i=0; i<M; i++){
		cin >> v1 >> v2;
		adj[v1].push_back(v2);
		adj[v2].push_back(v1);
	}
	if(N == M+1){
		if(noCycle())
			cout << "YES"<< endl;
		else
			cout << "NO" << endl;
	}else{
		cout << "NO" << endl;
	}
	return 0;
}
