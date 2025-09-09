/* 0-1 BFS Algorithm */
// This code implements the 0-1 BFS algorithm to find the shortest path in a graph with edges of weight 0 or 1.
// It uses a deque to efficiently handle nodes based on edge weights.
// The graph is represented using an adjacency list with pairs indicating the adjacent node and the edge weight.
// The algorithm initializes distances to infinity and updates them based on the edge weights.
// The main function reads the graph input, calls the sssp function to compute shortest paths, and outputs the results.
// O(n + m) time complexity, where n is the number of nodes and m is the number of edges.
// O(n) space complexity for the graph, visited array, and distance array.
// This code can be used to find the shortest path in graphs with 0-1 weights

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <climits>
#include <iomanip>
using namespace std;
#define INF 1e9 
#define F first
#define S second 


int n,m;
vector<vector<pair<int,int>>> graph;
vector<int> visited;
vector<int> dist;


void sssp(int sc){
    visited.assign(n+1,0);
    dist.assign(n+1,INF);
    
    deque<int> dq;
    dist[sc]=0;
    dq.push_back(sc);
    
    while(!dq.empty()){
        int node = dq.front();
        dq.pop_front();
        
        if(visited[node]) continue;
        visited[node]=1;
        
        for(auto v:graph[node]){
            int neigh = v.F;
            int cost = v.S;
            
            if(dist[neigh]>dist[node]+cost){
                if(cost==0){
                    dist[neigh]=dist[node];
                    dq.push_front(neigh);
                }else{
                    dist[neigh]=dist[node]+1;
                    dq.push_back(neigh);
                }
            }
        }
        
    }
}


void solve()
{
   
    cin>>n>>m; // n - nodes , m - edges 
    graph.resize(n+1);
    
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    
    // for(int i=1;i<=n;i++){
    //     for(auto v:graph[i]){
    //         cout<<i<<" "<<v.F<<" "<<v.S<<endl;
    //     }
    // }
    
    int sc = 0;
    cin>>sc; // take source node as the input 
    
    sssp(sc);
    
    for(int i=1;i<=n;i++){
        cout<<i<<" "<<dist[i]<<endl;
    }
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}


/*
Input:
8 9
1 2 0
1 5 1
4 5 1
2 4 0 
2 6 1
4 6 1
6 7 0
2 3 0
3 8 1
1



Output:
1 0
2 0
3 0
4 0
5 1
6 1
7 1
8 1
*/
