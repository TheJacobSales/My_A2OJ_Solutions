#include <bits/stdc++.h>

using namespace std;

int main(){
    int year, most = 9000, ind = 0;
    string test;
    cin >> year;
    ind = year;
    while (ind++){
        map <char, int> m;
        test = to_string(ind);
        bool foundInd = true;
        for(int i = 0; i < 4; i++){
            if(m.find(test[i]) != m.end()){
                foundInd = false;
                break;
            }
            m[test[i]] = 0;
        }
        if (foundInd) break;
    }
    cout << ind;

    return 0;
}