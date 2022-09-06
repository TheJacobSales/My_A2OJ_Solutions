/*************************************
 * Problem - 	450A - Jzzhu and Children
 * Geneal Solution:
 * Find the last maximum of ceil(candy wanted/ candy given)
**************************************/

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

int main(){
    //Initialize variables
    int maxCandy = 0, maxIndex = 0;
    float n, m, candy;//use float for ceil to work
    //Algo Start
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> candy;
        //Find the last max of ceil(candy / m)
        if ( ceil(candy / m) >= maxCandy){
            maxIndex = i;//Save index
            maxCandy = ceil(candy / m);
        }
    }
    if (maxCandy == 0) cout << n;//Case where all cadies are given in first round
    else cout << maxIndex + 1;//Answer is not zero index; so add 1
    return 0;
}
