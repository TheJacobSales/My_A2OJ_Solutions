#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

int main(){
    vector<int> arr;
    map<int, int> m;
    int curr, arrSize, quarSize;
    cin >> arrSize;
    for(int i = 0; i < arrSize; i++){
        cin >> curr;
        m[curr] = i;
    }
    cin >> quarSize;

    ll vas = 0, pet = 0, val;
    for(int i = 0; i < quarSize; i++){
        cin >> curr;
        if (m.find(curr) == m.end()){
            vas += arrSize;
            pet += arrSize;
        } else {
            val = m[curr] + 1;
            vas += val;
            pet += arrSize - val + 1;
        }
    }
    cout << vas << " " << pet;
    return 0;
}