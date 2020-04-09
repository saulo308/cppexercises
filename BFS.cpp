#include <iostream>
#include <list>
using namespace std;

class Graph{
    int numVertices;
    list<int> *adjList;
    bool* visited;
public:
    Graph(int vertices);
    void AddEdges(int src,int dest);
    void BFS(int start);
};

Graph::Graph(int vertices){
    numVertices = vertices;
    adjList = new list<int>[vertices];
}

void Graph::AddEdges(int src,int dest){
    adjList[src].push_back(dest);
    adjList[dest].push_back(src);
}

void Graph::BFS(int start){
    //Inititializing visited array
    visited = new bool[numVertices];
    for(int i = 0;i < numVertices;i++)
        visited[i] = false;

    //First element is visited
    list<int> queue;
    visited[start] = true;
    queue.push_back(start);

    //Iterator
    list<int>::iterator i;

    while(!queue.empty()){
        //Getting the first vertice on the queue
        int curVertex = queue.front();
        cout << "Visited: " << curVertex << endl;
        queue.pop_front();

        for(i = adjList[curVertex].begin();i != adjList[curVertex].end();i++){
            int adjVertex = *i;
            if(!visited[adjVertex]){
                visited[adjVertex] = true;
                queue.push_back(adjVertex);
            }
        }
    }
}

int main(){
    Graph g(4);
    g.AddEdges(0,1);
    g.AddEdges(0,2);
    g.AddEdges(1,2);
    g.AddEdges(2,0);
    g.AddEdges(2,3);
    g.AddEdges(3,3);

    g.BFS(2);

    return 0;
}