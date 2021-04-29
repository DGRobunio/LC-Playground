#include "includes.h"



int main() {


//    set<string> a;
    cout << "Hello World!" << endl;
    cout << INT_MAX << endl;
    string a = "";
    cout << a.length() << endl;
    int num[9] = {1,2,3,4,5,6,7,8,9};
    for (int i = 0; i < 9; i++) {
        int n = num[i];
        cout << n << endl;
    }

    for (auto n: num) {
        cout << n << endl;
    }


//    uint32_t n = 12, m = 2;
//    auto result = n&m;
//    cout << result << endl;

//    vector<vector<int>> test = {{1,2},{1,2},{1,2}};
//    cout << eraseOverlapIntervals(test) << endl;
    return 0;
}



