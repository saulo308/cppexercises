#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    unordered_multimap<int,string> map = {{1,"First"},{1,"Forth"},{4,"SaULO!"}};

    for(auto& x: map){
        cout << x.first << ":" << x.second << endl;
    }

    auto p = map.equal_range(1);
    for(auto it = p.first; it != p.second;it++){
        cout << it->first << ":" << it->second << endl;
    }

    cout << map.size() << endl;
    auto pt = map.find(1);
    cout << pt->first << endl << pt->second;

    return 0;
}