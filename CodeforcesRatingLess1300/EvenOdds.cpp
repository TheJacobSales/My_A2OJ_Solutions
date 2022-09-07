/*************************************
 * Problem:  318A - Even Odds
 * Geneal Solution:
 * Brute force will take too long. Can figure out an eqation to solve by
 * thinging of 2 different arrays; one with odd numbers and one with even.
 * Determine if the position k will land in either odd or even array. Then,
 * determine where it will land in the array. Can simply be done by multiplying by 2.
 * Watch data size as indicated with inputs that can reach 10^12.
 * Time complexity should be O(1) to solve an equation.
**************************************/

#include <bits\stdc++.h>
 
using namespace std; 
 
#define ll long long
#define ar array
 
int main(){
    //Make sure to use double and long long to handle large inputs
    ll  index = 0, ans;
    double n, k;
    cin >> n >> k;
    // Check if landing in odd or even arrays
    // position can be calculated by using k
    if (ceil(n/2) >= k){
        //Odd will need to subtract by k by 1
        k--;
        ans = k * 2 + 1;
    } else {
        //Subtract the amount of elements stored in even array and then multiply by 2
        ans = (k - ceil(n/2)) * 2;
    }
    cout << ans;
    return 0;
}