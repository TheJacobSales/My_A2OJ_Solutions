#include <bits/stdc++.h>

using namespace std;

int main(){
    int rows = 5, curr;
    pair <int, int> target(2,2);
    pair <int, int> start;
    bool foundStart = false;

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < rows; j++){
            cin >> curr;
            if (curr == 1){
                foundStart == true;
                start.first = i;
                start.second = j;
                break;
            }
        }
        if (foundStart) break;
    }
    cout << abs(target.first - start.first) + abs(target.second - start.second);
    
    return 0;
}