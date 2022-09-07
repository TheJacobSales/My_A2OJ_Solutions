#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

int main(){
    int minDif, height, prevHeight, firstHeight, n, left = 0, right = 1;
    vector<int> circle;

    cin >> n >> prevHeight >> height;
    firstHeight = prevHeight;
    minDif = abs(prevHeight - height);
    prevHeight = height;
    for (int i = 2; i < n; i++){
        cin >> height;
        if (abs(height - prevHeight) < minDif){
            minDif = abs(height - prevHeight);
            left = i - 1;
            right = i;
        }
        prevHeight = height;
        // cout << minDif << endl;
    }
    // cout << abs(height - firstHeight) << endl;
    if (abs(height - firstHeight) < minDif){
        left = n - 1;
        right = 0;
    }
    cout << left + 1 << " " << right + 1;
    return 0;
}