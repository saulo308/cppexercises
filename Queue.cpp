#include <iostream>
#include <queue>
using namespace std;

void PrintPriorityQueue(priority_queue<int> queue){
    while(!queue.empty()){
        cout << queue.top() << endl;
        queue.pop();
    }
}

void PrintQueue(queue<int> q){
    while(!q.empty()){
        cout << q.front() << endl;
        q.pop();
    }
}

int main(){
    priority_queue<int> pq;
    queue<int> queue;

    pq.push(30);
    pq.push(20);
    pq.push(50);
    PrintPriorityQueue(pq);

    cout << endl;
    queue.push(20);
    queue.push(10);
    PrintQueue(queue);

    return 0;
}