/*************************************
 * Problem:  				296A - Yaroslav and Permutations
 * Geneal Solution:
 * Notice the wording of the problem. Yaroslave can switch as many neighboring elements as long as we can
 * come to solution. Time does not matter here, and neither does the amount of times they have to switch
 * places of the numbers. So all we need to know is if there is a possible solution. Thinking of the
 * possible solutions, we can conclude that there are 2 main cases. There is an even amout of numbers
 * and an odd amount of numbers. Now we know there cannot be a possible solution if a number A takes up
 * more than half the values. For example, lets have a set of 6 values consisting of the values A and B.
 * If more than half thes set of values are value A( A A A A B B), then there cannot be a solution where there are
 * no duplilicate numbers. This is an example for an even case. For an odd case, we cannot have more than half plus 1.
 * Example, a set of 5 values (A A A A B) cannot have a solution, where A if the set was (A A A B B) could have a solution.
 * Thus the best method of solving this problem is to keep track of the amount of each individual value and see if
 * any of them accumulate over half.
 * Time complexity: O(n) assuming a hash map traversal of O(1)
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

map<int,int> total;//Hash map to keep track of all individual values

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //Variables
    int n, temp, half;
    bool valid = true;
    //Algorithm
    cin >> n;
    half = n % 2 ? n / 2 + 1 : n / 2;//Check if we are looking for an even or odd set of numbers
    REP(i, 0, n){
        cin >> temp;
        //Populate our hash map
        if(total.find(temp) == total.end()) total[temp] = 1;
        else total[temp]++;
        //If value ever accumulates over half, then we cannot have a solution
        if (total[temp] > half){
            valid = false;
            break;
        }
    }
    string ans = valid ? "YES" : "NO";
    cout << ans;

    return 0;
}