/*************************************
 * Problem:  				450B - Jzzhu and Sequences
 * Geneal Solution:
 * The main trick to this problem is realizing that there are only 6 possible outcomes. Meaning the sequence repeats
 * itself. Now we know f1 = x and f2 = y. So, we can start solving the problem by first continuing the sequence.
 * Thus:
 * f3 = f2 + f4
 * f4 = f3 + f5
 * f5 = f4 + f6
 * f6 = f5 + f7
 * This is continuing the sequence, but we must remember that i >= 2. So,
 * f2 = f1 + f3
 * We can include this since the set of i can include 2. This is key to solve all fi in terms of x and y.
 * Then we can say:
 * f3 = f2 - f1
 * f4 = f3 - f2 = -f1
 * f5 = f4 - f3 = -f1 - (f2 - f1) = -f2
 * f6 = f5 - f4 = f1 - f2
 * f7 = f6 - f5 = f1
 * If we continue this sequence, we will see that the sequence will continue to repeat itself. So we can write the
 * sequece in terms of x and y.
 * {x, y, y - x, -x, -y, x - y}
 * Then we all we have to do is a mathmatical modulo since we have to account for negative numbers.
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

const ll MODULO = 1000000007;//Modulo required by the problem


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // Variables
    ll x, y, n, ans;
    cin >> x >> y >> n;
    vector<ll> possible = {x, y, y - x, -x, -y, x - y};//Our possible sequences
    cout << (possible[(n - 1) % 6] % MODULO + MODULO) % MODULO;//Mathmatical Modulo that includes negative numbers
    return 0;
}