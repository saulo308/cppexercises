#include <iostream>
#include <list>
using namespace std;

class Graph{
    int numVertices;
    list<int> *adjList;
    bool *visited;
public:
    Graph(int vertices);
    void AddEdges(int src,int dest);
    void DFS(int startVertex);
};

Graph::Graph(int vertices){
    numVertices = vertices;
    adjList = new list<int>[vertices];
    visited = new bool[numVertices];

    for(int i = 0;i < numVertices;i ++)
        visited[i] = false;
}

void Graph::AddEdges(int src,int dest){
    adjList[src].push_front(dest);
}

void Graph::DFS(int startVertex){
    visited[startVertex] = true;

    cout << startVertex << " " << endl;

    list<int>::iterator i;
    for(i = adjList[startVertex].begin();i != adjList[startVertex].end();i++){
        int curVertex = *i;
        if(!visited[curVertex]){
            DFS(curVertex);
        }
    }
}

int main(){
    Graph g(4);
    g.AddEdges(0,1);
    g.AddEdges(0,2);
    g.AddEdges(0,3);
    g.AddEdges(1,2);
    g.AddEdges(2,0);
    g.DFS(2);


    return 0;
}