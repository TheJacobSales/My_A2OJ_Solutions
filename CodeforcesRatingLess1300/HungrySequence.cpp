/*************************************
 * Problem:  				327B - Hungry Sequence
 * Geneal Solution:
 * Brute force method of the solution would be to find all the possible prime numbers. However this solution plays with
 * the bounds of the largest data type and how many numbers are needed. We know that the largest number in from 'a'
 * would be 10e^7. We also know that large numbers located closely together are unlikely to be factors of eachother.
 * Using this idea, the easiest way to solve the problem is to count up to the largest number based on the needed
 * 'n' numbers.
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
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n;
    cin >> n;
    for(int i=1e6-n; i<1e6 ;i++)
        cout<<i<<" ";
 
    return 0;
}