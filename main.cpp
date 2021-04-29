#include "includes.h"



int main() {


//    set<string> a;
    cout << "Hello World!" << endl;
    cout << INT_MAX << endl;
    vector<int> vec(10);
    for (int i = 0; i < 10; i++) {
        vec[i] = i;
    }
    auto it = vec.begin();
    advance(it, 5);
    vector<int> v2(vec.begin(), it);
    for (auto i: v2)
        cout << i << endl;

//    uint32_t n = 12, m = 2;
//    auto result = n&m;
//    cout << result << endl;

//    vector<vector<int>> test = {{1,2},{1,2},{1,2}};
//    cout << eraseOverlapIntervals(test) << endl;
    return 0;
}



