/*************************************
 * Problem:  				298B - Sail
 * Geneal Solution:
 * Directions are to simply find if it is possible to get to starting point to destination
 * within a set amount of time. The best way to do this is by using a greedy alogorithm.
 * The boat only has 2 choices, move in the direction of the wind or hold position. Each
 * choice will take 1 unit of time. So, we can keep a total amount of choices to get to
 * the destination. If it does not reach the destination within the given time, then we print -1.
 * Time complexity: O(n)
**************************************/

#include <bits\stdc++.h>

using namespace std;

#define ll long long
#define ar array
#define vec vector

pair<ll,ll>start, dest, cur;
map<char,int> comp;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    comp['N'] = 1;
    comp['E'] = 1;
    comp['S'] = -1;
    comp['W'] = -1;
    ll t, dur = 0, xdif, ydif;
    string direct;
    cin >> t >> start.first >> start.second >> dest.first >> dest.second >> direct;
    cur = start;
    ydif = abs(dest.second - start.second);
    xdif = abs(dest.first - start.first);
    for(int i = 0; i < direct.length(); i++){
        if(cur == dest) break;
        if ((direct[i] == 'N' || direct[i] == 'S') && abs(dest.second - (comp[direct[i]] + cur.second)) < ydif) {
            cur.second += comp[direct[i]];
            ydif = abs(dest.second - cur.second);
        } else if ((direct[i] == 'W' || direct[i] == 'E') && abs(dest.first - (comp[direct[i]] + cur.first)) < xdif) {
            cur.first += comp[direct[i]];
            xdif = abs(dest.first - cur.first);
        }
        dur++;
    }
    if(cur != dest) dur = -1;
    cout << dur;
    return 0;
}