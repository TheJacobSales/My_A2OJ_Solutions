/*************************************
 * Problem:  				289B - Polo the Penguin and Matrix
 * Geneal Solution:
 * Solution can be broken down into 2 parts. The first part is seeing if there can be a possible solution. 
 * Given that d is the number that will be added or subtracted to any element a for any amount of times, we
 * have to confirm that all numbers can be equal. Best way to do this is by making sure that each value has the 
 * same remainder when divided by d. This is because if a number A and a number B have a different remainder when
 * modulized by d, then no matter how much you add or subtract them, they will never be the same since the rate
 * of increase and decrease will be linear. So we will first test to see if all elements have the same remainder 
 * when modulized by d.
 * 
 * Now, if we have a possible solution, we have to find that solution. The best way to do this is by using the median.
 * The main reason we do this is because we will have the same number of elements on each side of the median. This means
 * that all numbers to the left of the median and to the right of the median will converge to equall the median. If we
 * were to make it a number that is less than the median, then more elements to the right of that number(including the median)
 * would have to decrease to that number. Thus we increase the number of elements on the right needing to decrease. The further
 * Away we get from the median, then the hight this number will grow. Thus, it is best to keep the target value as the median to
 * ensure we have an equal amount of elements increaseing or decreaseing on both sides
 * Time complexity: O(n*mlog(n*m)) since we need to sort the entire vector of values to find the median
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


void solve(int n, int m, int d){
    vi vals;
    int a, remain, ans = 0, median;
    cin >> a;
    remain = a % d;//Our remainder that is needed to check for possible solutions
    vals.push_back(a);
    REP(i, 0, n * m -1){
        cin >> a;
        //Found a value with a different remainder
        if (a % d != remain){
            cout << -1;
            return;
        }
        vals.push_back(a);//Set up our vector of values
    }
    //Find our median and calculate our answer
    sort(vals.begin(), vals.end());
    median = vals[n * m / 2];
    REP(i, 0, vals.size()){
        ans += abs(vals[i] - median);
    }
    cout << ans / d;
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //Setup for the algorithm
    int n, m, d, a, remain;
    cin >> n >> m >> d;
    solve(n, m, d);

    return 0;
}