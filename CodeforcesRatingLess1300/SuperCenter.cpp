/*************************************
 * Problem:  165A - Supercentral Point
 * Geneal Solution:
 * Run check on every coordinate. Should check each other coordinate to see if it has neighbors
 * on left, right, top, and bottom. If it does, then it is a Supercentral point.
 * The resulting time complexity should be O(N^2).
**************************************/

#include <bits/stdc++.h>

using namespace std;

int main(){
    //Initialize variables
    bool left, right, bot, top;//keep track of neighbors
    int n, x, y, ans = 0, index;
    vector<pair<int,int>> coords;//Store the coordinates as pairs

    //Set up inputs
    cin >> n;
    index = n;
    while (index){
        cin >> x >> y;
        coords.push_back(make_pair(x,y));
        index--;
    }

    //Carry out algorithim compare to each coordinate
    for (int i = 0; i < n; i++){
        left = false;
        right = false;
        bot = false;
        top = false;
        for (int j = 0; j < n; j++){
            if (coords[i].first == coords[j].first){
                //checks if it has a neighbor on top or bottom
                if (coords[i].second  < coords[j].second) top = true;
                else if(coords[i].second > coords[j].second) bot = true;
            } else if(coords[i].second == coords[j].second){
                //checks if it has a neighbor on left or right
                if (coords[i].first < coords[j].first) right = true;
                else if(coords[i].first > coords[j].first) left = true;
            }
        }
        if(left && right && bot && top) ans++;//increment answer by 1 if supercentral
    }
    cout << ans;
    return 0;
}