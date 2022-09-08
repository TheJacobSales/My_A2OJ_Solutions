/*************************************
 * Problem:  	339B - Xenia and Ringroad
 * Geneal Solution:
 * There are many solutions to this problem, but the most straightforward
 * solution is as follows. We can thing of this as a 2 pointer solution. 
 * We need to save the value of the previous house position(A) and compare it to the current house position(B).
 * If the comparison of position values is A <= B, then the time to travel between them is just B - A.
 * If the comparison results in A > B, then there is a need to loop around to the starting house.
 * So the equation to be use is n - A + B; where n is the total number of houses.
 * Continue this until the end. Time complexity : O(m)
**************************************/

#include <bits\stdc++.h>

using namespace std;

#define ll long long
#define ar array

int main(){
    //make stdio more efficient
    ios::sync_with_stdio(0);
    cin.tie(0);

    //Variables
    ll n, m, prev = 1, curr, time = 0;

    //Algorithm
    cin >> n >> m;
    for (int i = 0; i < m ; i++){
        cin >> curr;
        if (prev <= curr) time += curr - prev;//move to next house
        else time += n - prev + curr;//loop back around
        prev = curr;
    }
    cout << time;
    return 0;
}