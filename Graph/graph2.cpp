#include <bits/stdc++.h>
using namespace std;

class Graph {
    public:
    unordered_map<int , list<pair<int , int> > > adjList;
    void addEdges(int u , int v , int wt , int direction) {
        adjList[u].push_back({v,wt});
        // Undirected Graph
        if(direction == 0) {
            adjList[v].push_back({u,wt});
        }
    }

    void printList() {
        for(auto i : adjList) {
            cout << i.first << "--> ";
            for(auto j : i.second) {
                cout << "(" << j.first << ", " << j.second << "), ";
            }
            cout << endl;
        }
    }

    void shortestPath(int src , int dest) {
        queue<int> q;
        unordered_map<int , bool> visited;
        unordered_map<int , int> parent;

        q.push(src);
        visited[src] = true;
        parent[src] = -1;
        while(!q.empty()) {
            int frontNode = q.front();
            q.pop();

            for(auto i : adjList[frontNode]) {
                if(!visited[i.first]) {
                    q.push(i.first);
                    visited[i.first] = true;
                    parent[i.first] = frontNode;
                }
            }
        }

        vector<int> ans;
        int node = dest;
        while(node != -1) {
            ans.push_back(node);
            node = parent[node];
        }

        reverse(ans.begin() , ans.end());
        cout << "Printing Ans vector : " << endl;
        for(auto i : ans) {
            cout << i << "-->"; 
        }
    }

};



int main() {
    Graph g;
    g.addEdges(0,1,1,1);
    g.addEdges(1,2,1,1);
    g.addEdges(2,3,1,1);

    g.addEdges(3,4,1,1);
    g.addEdges(0,5,1,1);
    g.addEdges(5,4,1,1);

    g.addEdges(0,6,1,1);
    g.addEdges(6,7,1,1);
    g.addEdges(7,8,1,1);
    g.addEdges(8,4,1,1);

    g.printList();

    int src = 0;
    int dest = 4;
    g.shortestPath(src , dest);
    return 0;
}