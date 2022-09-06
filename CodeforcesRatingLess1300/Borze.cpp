#include <bits/stdc++.h>

using namespace std;

int main(){
    string borze, tern;
    cin >> borze;
    int i = 0, size = 0;
    while(i < borze.size()){
        if (borze[i] == '-'){
            if(borze[i + 1] == '-') tern += '2';
            else tern += '1';
            i++;
        }
        else tern += '0';
        i++;
    }
    cout << tern;

    return 0;
}