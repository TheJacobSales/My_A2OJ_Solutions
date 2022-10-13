/*************************************
 * Problem:  				315A - Sereja and Bottles
 * Geneal Solution:
 * Best way to solve this is through brute force. Also this problem is a little hard to read. Basically if any bottle with lable ai can open
 * any bottle wich corresponding lable bi. So essentailly finding other bottles with lable a and b matching so they can be opened. 
 * Check each bottle and find if they can open another bottle.
 * Time complexity: O(n^2)
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

vi a, b;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //Variables
    int n, ain, bin, ans;
    //Algorithm
    cin >> n;
    ans = n;
    //setup vectors to hold a and b values
    REP(i, 0, n){
        cin >> ain >> bin;
        a.push_back(ain);
        b.push_back(bin);
    }
    //Using value from a, see if it is possible to open comparing to values from b
    REP(i, 0, a.size()){
        REP(j, 0, b.size()){
            if (j == i) continue;//Can't open from the same bottle
            //Found a bottle it use to be opened. Start next search
            if(a[i] == b[j]){
                ans--;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}