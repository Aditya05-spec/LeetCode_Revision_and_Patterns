#include<bits/stdc++.h>
using namespace std;
template <typename T>

class Graph {
    public:
        unordered_map<int , list<int> > adjList;
        
        void addEdge(int u , int v , bool direction) {
            // Direction -> 0 undirected Graph
            // Direction -> 1 Directed Graph
            
            adjList[u].push_back(v);
            if(direction == 0) {
                adjList[v].push_back(u);
            }
        }

        void printAdjList() {
            for(auto node : adjList) {
                cout << node.first << "->";
                for(auto neighbour : node.second) {
                    cout << neighbour << ", ";
                }
                cout << endl;
            }
        }

        void bfs(int src , unordered_map<int , bool> &visited) {
            queue<int> q;

            q.push(src);
            visited[src] = true;
            while(!q.empty()) {
                int frontNode = q.front();
                cout << frontNode << " ";
                q.pop();

                for(auto i : adjList[frontNode]) {
                    if(!visited[i]) {
                        q.push(i);
                        visited[i] = true;
                    }
                }
            }
        }

        void dfs(int src , unordered_map<int , bool> &visited) {
            cout << src << ", ";
            visited[src] = true;
            for(auto i : adjList[src]) {
                if(!visited[i]) {
                    dfs(i , visited);
                }
            }
        }

        bool checkCyclicUsingBFS(int src , unordered_map<int , bool> &visited) {
            queue<int> q;
            unordered_map<int , int> parent;
            q.push(src);
            visited[src] = true;
            parent[src] = -1;
            while(!q.empty()) {
                int frontNode = q.front();
                q.pop();

                for(auto i : adjList[frontNode]) {
                    if(!visited[i]) {
                        q.push(i);
                        visited[i] = true;
                        parent[i] = frontNode;
                    }
                    else {
                        //Already visited
                        if(i != parent[frontNode]) {
                            return true;
                        }
                    }
                }
            }
            return false;
        }

        bool checkCyclicUsingDFS(int src , unordered_map<int , bool> &visited , int parent) {
            visited[src] = true;
            for(auto nbr : adjList[src]) {
                if(!visited[nbr]) {
                    bool aageKaAns = checkCyclicUsingDFS(nbr , visited , src);
                    if(aageKaAns == true) return true;
                }
                if(visited[nbr] && nbr != parent)
                // Cycle present
                return true;

            }
            return false;
        }

        bool checkCyclicDirectedGraphUsingDFS(int src , unordered_map<int , bool> & visited , unordered_map<int , bool> dfsVisited) {
            visited[src] = true;
            dfsVisited[src] = true;
            for(auto i : adjList[src]) {
                if(!visited[i]) {
                    bool aageKaAns = checkCyclicDirectedGraphUsingDFS(i , visited , dfsVisited);
                    if(aageKaAns) {
                        return true;
                    }
                }

                if(visited[i] && dfsVisited[i]) {
                    return true;
                }
            }
            dfsVisited[src] = false;
            return false;
        }

        void topologicalSortDFS(int src , unordered_map<int , bool> &visited , stack<int> &ans) {  //Kahn's algorithm
            visited[src] = true;
            for(auto i : adjList[src]) {
                if(!visited[i]) {
                    topologicalSortDFS(i , visited , ans);
                }
            }
            // While returning store the node in the stack
            ans.push(src);
        }

        void topologicalSortBFS(int n , vector<int> &ans) {
            queue<int> q;
            unordered_map<int , int> inDegree;

            // Indegree calculation
            for(auto i : adjList) {
                int src = i.first;
                for(auto nbr : i.second) {
                    inDegree[nbr]++;
                }
            }

            // Put all node inside queue with indegree 0
            for(int i=0 ; i<n ; i++) {
                if(inDegree[i] == 0) {
                    q.push(i);
                }
            }

            while(!q.empty()) {
                int frontNode = q.front();
                q.pop();

                ans.push_back(frontNode);
                for(auto i : adjList[frontNode]) {
                    inDegree[i]--;
                    if(inDegree[i] == 0) {
                        q.push(i);
                    }
                }
            }
        }
};

int main() {

    int n=8;
    Graph<int> g2;
    g2.addEdge(2,4,1);
    g2.addEdge(2,5,1);
    g2.addEdge(4,6,1);
    g2.addEdge(5,3,1);
    g2.addEdge(3,7,1);
    g2.addEdge(6,7,1);
    g2.addEdge(7,0,1);
    g2.addEdge(7,1,1);

    g2.printAdjList();
    cout << endl;

    vector<int> ans;
    g2.topologicalSortBFS(n , ans);

    cout << "Printing Topological sort using BFS: " << endl;
    for(auto i : ans) {
        cout << i << " ";
    }
    cout << endl;


    // unordered_map<int , bool> visited;
    // stack<int> ans;
    // for(int i=0 ; i<n ; i++) {
    //     if(!visited[i]) {
    //         g2.topologicalSortDFS(i , visited , ans);
    //     }
    // }

    // cout << "Topological Sort using DFS: " << endl;
    // while(!ans.empty()) {
    //     cout << ans.top() << " ";
    //     ans.pop();
    // }

    // int ans = false;
    // unordered_map<int , bool> visited;
    // for(int i=0 ; i<n ; i++) {
    //     if(!visited[i]) {
    //         ans = g2.checkCyclicUsingBFS(i , visited);
    //         if(ans == true) break;
    //     }
    // }

    // if(ans == true) {
    //     cout << "Cycle is present" << endl;
    // }
    // else {
    //     cout << "Cycle absent" << endl;
    // }




    // int ansDFS = false;
    // unordered_map<int , bool> visitedDFS;
    // for(int i=0 ; i<n ; i++) {
    //     if(!visitedDFS[i]) {
    //         ansDFS = g2.checkCyclicUsingDFS(i , visitedDFS , -1);
    //         if(ansDFS == true) break;
    //     }
    // }

    // if(ansDFS == true) {
    //     cout << "Cycle is present" << endl;
    // }
    // else {
    //     cout << "Cycle absent" << endl;
    // }



    // bool ans = false;
    // unordered_map<int , bool> visited;
    // unordered_map<int , bool> dfsVisited;
    // for(int i=0 ; i<n ; i++) {
    //     ans = g2.checkCyclicDirectedGraphUsingDFS(i , visited , dfsVisited);
    //     if(ans) {
    //         break;
    //     }
    // }

    // if(ans) {
    //     cout << "Cycle is present" << endl;
    // }
    // else {
    //     cout << "Cycle is not present" << endl;
    // }



    // Graph<int> g1;
    // g1.addEdge(0,1,0);
    // g1.addEdge(1,2,0);
    // g1.addEdge(1,3,0);
    // g1.addEdge(3,5,0);
    // g1.addEdge(3,7,0);
    // g1.addEdge(7,6,0);
    // g1.addEdge(7,4,0);
    // g1.printAdjList();


    // unordered_map<int , bool> visited1;
    // run a loop on all the nodes
    // Doing1 BFS traversal
    // for(int i=0 ; i<=7 ; i++) {
    //     if(!visited1[i]) {
    //         g1.bfs(i , visited1);
    //     }
    // }


    // Doing DFS traversal
    // Graph<int> g2;
    // g2.addEdge(0,1,0);
    // g2.addEdge(1,3,0);
    // g2.addEdge(0,2,0);
    // g2.addEdge(2,4,0);
    // cout << endl << endl;
    // unordered_map<int , bool> visited2;
    // for(int i=0 ; i<=4 ; i++) {
    //     if(!visited2[i]) {
    //         g2.dfs(i , visited2);
    //     }
    // }
    
    // Graph<int> g;
    // g.addEdge(0,1,5);
    // g.addEdge(1,2,8);
    // g.addEdge(0,2,6);
    // cout << endl;
    // g.printAdjList();


    // This is how we implement Adjacency Matrix
    // int n;
    // cout << "Enter the number of rows : " << endl;
    // cin >> n;

    // vector<vector<int> > adj(n , vector<int> (n , 0));

    // int e;
    // cout << "Enter the number of Edges : " << endl;
    // cin >> e;

    // for(int i=0 ; i<e ; i++) {
    //     int u , v;
    //     cin >> u >> v;

    //     adj[u][v] = 1;
    // }

    // for(int i=0 ; i<n ; i++) {
    //     for(int j=0 ; j<n ; j++) {
    //         cout << adj[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // This is how we implements a adjacency list

    return 0;
}