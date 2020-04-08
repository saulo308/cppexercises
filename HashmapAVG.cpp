#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    unordered_multimap<int,int> map = {{1,1},{1,4},{24,4},{4,10},{4,14},{2,2}};

    for(auto it = map.begin(); it != map.end(); it = map.upper_bound(it->first)){
        int sum = 0;
        auto p = map.equal_range(it->first);
        for(auto bucketIterator = p.first; bucketIterator != p.second;bucketIterator++){
           // cout << bucketIterator->first << "-" << bucketIterator->second << endl;
            sum += bucketIterator->second;
        }

        cout << "Bucket " << it->first << " average is: " << sum / map.count(it->first) << endl;
    }

    return 0;
}