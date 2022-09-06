#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

int main(){
    int size, sumFing = 0, finger, dima = 0;
    cin >> size;
    for (int i = 0; i < size; i++){
        cin >> finger;
        sumFing += finger;
    }
    size++;
    for(int i = 1; i <= 5; i++){
        if(((sumFing + i) % size) != 1){
            dima++;
        }
    }
    cout << dima;
    return 0;
}