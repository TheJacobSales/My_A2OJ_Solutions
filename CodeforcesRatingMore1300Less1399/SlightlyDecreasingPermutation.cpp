/*************************************
 * Problem:  					285A - Slightly Decreasing Permutations
 * Geneal Solution:
 * Wording is confusing for this problem. Basically means that you need to print a permutation p where the length of the
 * permutation is n and k is the number of elements that are greater than their successors. Best way to do this is to
 * solve the k parameter in the beginning of the permutation then have the number increase directly after. Thus,
 * we print the k greatest elements first, then print 1 and count up till we reach n numbers.
 * Time complexity: O(n)
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

    int n, k;
    cin >> n >> k;
    //Print the k decreaseing numbers
    REP(i, 0, k){
        cout << n - i << " ";
    }
    //Print the increaseing numbers
    REP(i, 1, n - k + 1){
        cout << i << " ";
    }

    return 0;
}