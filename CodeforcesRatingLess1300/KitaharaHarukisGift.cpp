/*************************************
 * Problem:  		43B - Letter
 * Geneal Solution:
 * Solution is using brute force. Best way is to divide out the larges weights first which would
 * bet the 200 weighted fruit. Then we can see if we can see if we can make them even by using the
 * 100 weighted fruit. By doing this, we essentialy simulate the entire process.
**************************************/

#include <bits/stdc++.h>

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

vi w;//Vector to hold all the weights

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //Varibles
    int n, a = 0, b = 0, temp;
    //Algorithm
    cin >> n;
    //Set up vector of weights
    REP(i,0,n){
        cin >> temp;
        w.PB(temp);
    }
    sort(w.begin(), w.end());//First sort
    reverse(w.begin(), w.end());//Makes sure to make the largest weights first
    //Simulate the process
    REP(i,0,w.size()){
        if (a > b) b += w[i];
        else a += w[i];
    }
    // cout << endl;
    // cout << a << " " << b << endl;
    string ans = a == b ? "YES" : "NO";//If they are both equal, then we can divide them equally
    cout << ans;
    return 0;
}