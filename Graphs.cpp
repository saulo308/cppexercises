#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<int> adj[],int v1,int v2){
    adj[v1].push_back(v2);
    adj[v2].push_back(v1);
}

void printGraph(vector<int> adj[], int V){
    for(int i = 0;i < V;i++){
        if(adj[i].size() != 0){
            cout << "Vertice " << i << ":" << endl;
            cout << "Head";
            for(auto& x : adj[i]){
                cout << " -> " << x;
            }
            cout << endl;
        }
    }
}

int main (){
    const int V = 5;
    vector<int> adj[V];

    addEdge(adj,0,1);
    addEdge(adj,0,2);
    printGraph(adj,V);

    return 0;
}