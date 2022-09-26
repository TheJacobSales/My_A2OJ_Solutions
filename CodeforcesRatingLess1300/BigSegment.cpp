/*************************************
 * Problem:  				242B - Big Segment
 * Geneal Solution:
 * A segment that can hold all point must have the its left bound as the minimum value of the 
 * set, and it must also have its right bound be the maximum value of the set. If there is
 * an input that satisfies these parameters, then we report the index where this is found. Else
 * we have to print a -1. Best way to do this is by trying to find an index that satifies these parameters while also keeping
 * track of the minimum and maximum values of the set. If there ever comes a segment that pushes outside the maximum bound
 * but not the mnimum bound( and vice versa), then we know that there is not a segment that includes all values.
 * Time complexity: O(n) since it only runs through inputs once.
**************************************/

#include <bits\stdc++.h>

using namespace std;
//Definitions for competition
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i < b; i++)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int min, max, n, ans = 1, left, right;
    bool valid = true;
    cin >> n >> min >> max;
    REP(i, 0, n - 1){
        cin >> left >> right;
        if(left <= min && right >= max ){
            min = left;
            max = right;
            ans = i + 2;
            valid = true;
            // cout << "True at " << i + 2 << endl;
        }else {
            if (left < min || right > max) valid = false;
            min = left <= min ? left : min;
            max = right >= max ? right : max;
        }
    }
    ans = valid ? ans : -1;
    cout << ans;
    return 0;
}