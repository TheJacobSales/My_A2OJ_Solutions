/*************************************
 * Problem:  205A - Little Elephant and Rozdil
 * Geneal Solution:
 * Basically a bruteforce implementation. Need to search through all inputs
 * for an absolute minimum. If found and no other duplicates exist, the 
 * print its position. If there are duplicates, the print Still Rozdil.
**************************************/

#include <bits\stdc++.h>

using namespace std;

int main() {
    // Variables to hold the city position and distance
    pair<int,int> city;
    int n, dist;
    bool still = false;//Here to hold if there are any duplicate mins

    //Handle Inputs
    cin >> n >> city.first;
    city.second = 1;
    for (int i = 1; i < n; i++){
        cin >> dist;
        if (dist == city.first){
            still = true;// found a duplicate min
        } else if (dist < city.first){
            still = false;//found a new unique min
            city.first = dist;//store new min and position
            city.second = i + 1;
        }
    }
    // cout << city.first << " " << city.second << endl;
    if (still) cout << "Still Rozdil";//Found a duplicate min
    else cout << city.second;//Found a unique min with position

    return 0;
}