/*
	http://www.spoj.com/problems/PT07Z/
	Find the longest distance in a tree (2-BFS)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int M;
vector<int>* adj;
int* distance;

pair<int, int> bfs(int source){
	queue<int> myQueue;
	bool visited[M+1];
	int distance[M+1];
	pair<int, int> ans;
	for(int i=0; i<M+1; i++){
		visited[i] = false;
		distance[i] = -1;
	}
	myQueue.push(source);
	visited[source] = true;
	distance[source] = 0;
	while(!myQueue.empty()){
		int node = myQueue.front();
		myQueue.pop();
		vector<int>::iterator it;
		for(it=adj[node].begin(); it!= adj[node].end(); it++){
			if(visited[*it] == false){
				myQueue.push(*it);
				visited[*it] = true;
				distance[*it] = distance[node] + 1;
				if(distance[*it] > ans.second){
					ans.first = *it;
					ans.second = distance[*it];
				}
			}
		}
	}
	return ans;
}

int main(){
	int V1, V2;
	pair<int, int> last_node, max_val;
	cin >> M;
	adj = new vector<int>[M+1];
	for(int i=0; i<M-1; i++){
		cin >> V1 >> V2;
		adj[V1].push_back(V2);
		adj[V2].push_back(V1);
	}
	last_node = bfs(1);
	max_val = bfs(last_node.first);
	cout << max_val.second << endl;
	return 0;
}
