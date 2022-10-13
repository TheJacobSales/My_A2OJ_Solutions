/*************************************
 * Problem:  				260A - Adding Digits
 * Geneal Solution:
 * Read very carefully the implementation of the sequence. Each time the digit is added to the right, then
 * the resulting number has to be divisible by b. Very important to remeber. Thus we can simply solve this
 * using the described implementation. If result is not divisible by b, then we print -1. If is is divisible,
 * then we can append the rest 0 since 0 does not affect it's remainder.
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
    //Variables
    int a, b, n;
    //Algorithm
    cin >> a >> b >> n;
    bool exist = false;
    //Try to append a digit(0 to 9) to the right 
    REP(i, 0, 10)
    {   
        //check to see if the result is divisible by b
        if ((a * 10 + i) % b == 0) {
            cout << a * 10 + i;
            string s(n - 1, '0');//Append zeros based on our n value
            cout << s << endl;
            exist = true;
            break;
        }
    }
    if (!exist)
    {
        cout << -1 << endl;//Couldn't find a digit to append that makes the number divisible by b
    }

    return 0;
}