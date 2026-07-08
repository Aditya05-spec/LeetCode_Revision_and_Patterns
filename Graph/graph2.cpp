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

    // Topological Sort using DFS
    void topologicalSortDFS(int src , unordered_map<int , bool> &visited , stack<int> &ans) {  //Kahn's algorithm
            visited[src] = true;
            for(auto i : adjList[src]) {
                if(!visited[i.first]) {
                    topologicalSortDFS(i.first , visited , ans);
                }
            }
            // While returning store the node in the stack
            ans.push(src);
    }

    // Shortest Path using BFS
    void shortestPathBFS(int src , int dest) {
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

    // Shortest Path using DFS
    void shortestPathDFS(int dest , stack<int> &topoOrder , int n) {
        vector<int> dist(n , INT_MAX);
        int src = topoOrder.top();
        topoOrder.pop();
        dist[src] = 0;

        for(auto i : adjList[0]) {
            if(dist[0] + i.second < dist[i.first]) {
                dist[i.first] = dist[0] + i.second;
            }
        }

        while(!topoOrder.empty()) {
            int topElement = topoOrder.top();
            topoOrder.pop();

            if(dist[topElement] != INT_MAX) {
                for(auto i : adjList[topElement]) {
                    if(dist[topElement] + i.second < dist[i.first]) {
                        dist[i.first] = dist[topElement] + i.second;
                    }
                }
            }
            else {

            }
        }
        
        cout << "Printing Ans : " << endl;
        for(int i=0 ; i<n ; i++) {
            cout << i << "-> " << dist[i] << endl;
        }
    }

    void shortestDistDijkstra(int src , int n) {
        vector<int> dist(n , INT_MAX);
        set<pair<int , int > > st;

        dist[src] = 0;
        st.insert(make_pair(0,src));

        while(!st.empty()) {
            auto topElement = *(st.begin());
            int nodeDistance = topElement.first;
            int node = topElement.second;
            st.erase(st.begin());

            for(auto i : adjList[node]) {
                if(nodeDistance + i.second < dist[i.first]) {
                    // We need to update the distance
                    // Finding entry in the set
                    if(st.find(make_pair(dist[i.first] , i.first)) != st.end()) {
                        // If wew found remove that entry
                        st.erase(make_pair(dist[i.first] , i.first));
                    }
                    // Update both in the distance array and set
                    dist[i.first] = nodeDistance + i.second ;
                    st.insert(make_pair(nodeDistance + i.second , i.first));
                }
            }
        }

        for(auto i : dist) {
            cout << i << " ";
        }
        cout << endl;
    }

};



int main() {
    Graph g;
    g.addEdges(6,3,2,0);
    g.addEdges(6,1,14,0);
    g.addEdges(3,1,9,0);

    g.addEdges(3,2,10,0);
    g.addEdges(1,2,7,0);
    g.addEdges(2,4,15,0); 

    g.addEdges(4,3,11,0);
    g.addEdges(6,5,9,0);
    g.addEdges(4,5,6,0);

    g.printList();

    // int src = 0;
    // int dest = 4;
    // g.shortestPathBFS(src , dest);


    // Shortest path using DFS
    // stack<int> topoOrder;
    // unordered_map<int , bool> visited;
    // g.topologicalSortDFS(0 , visited , topoOrder);
    // g.shortestPathDFS(3 , topoOrder , 5);


    g.shortestDistDijkstra(6 , 7);

    return 0;
}