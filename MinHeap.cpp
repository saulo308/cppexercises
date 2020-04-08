#include <iostream>
#include <queue>
using namespace std;

class Point{
    int x,y;
public:
    Point(int dataX,int dataY){
        x = dataX;
        y = dataY;
    }
    int GetX(){return x;}
    int GetY(){return y;}
};

class Comparator{
public:
    bool operator()(Point& p1,Point& p2){
        return p1.GetX() > p2.GetX();
    }
};

void PrintHeap(priority_queue<int,vector<int>,greater<int>> heap){
    while(!heap.empty()){
        cout << heap.top() << endl;
        heap.pop();
    }
}

int main(){
    priority_queue<int,vector<int>, greater<int>> minHeap;

    minHeap.push(10);
    minHeap.push(4);
    minHeap.push(12);
    PrintHeap(minHeap);

    cout << endl;
    priority_queue<Point,vector<Point>,Comparator> customHeap;
    Point p1(2,2);
    Point p2(1,3);
    Point p3(10,5);
    customHeap.push(p1);
    customHeap.push(p2);
    customHeap.push(p3);
    Point p = customHeap.top();
    cout << p.GetX() << endl;
    customHeap.pop();
    p = customHeap.top();
    cout << p.GetX() << endl;
    customHeap.pop();
    p = customHeap.top();
    cout << p.GetX() << endl;


    return 0;
}