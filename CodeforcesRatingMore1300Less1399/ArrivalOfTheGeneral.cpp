/*************************************
 * Problem:  				144A - Arrival of the General
 * Geneal Solution:
 * Solution is based on where the minimum and maximum values are positioned. Remember that only the front and
 * back values are important. Also we only want the minimum number of moves to achive what we want. So thinking
 * from a more broad scope, the most optimum method of moving the people is to move the shortest value that is closer
 * to the back and to move the largest value that is closer to the front. These are the only ones that will move. 
 * The amount of times these specific values will move is simply the index difference from the front or the back.
 * Then we can find their sum to get our final answer. However, there is one special case where the maximum index and
 * the minimum index will pass eachother when they are traveling to the fron or the back. Since they are moving past eachother,
 * it will decrease the number of moves needed to get the minimum or maximum to their respective places.
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
    //Variables
    int n, height, ans = 0, maxInd = 0, minInd = 0;
    cin >> n;
    cin >> height;//Need to set the min and max of the set
    int min = height, max = height;
    //Algorithm
    REP(i, 0, n - 1){
        cin >> height;
        //Set the max or min with thier corresponding indexes
        if (height > max){
            //Not we only take greater than values because we want the max value closest to the front
            max = height;
            maxInd = i + 1;
        } else if(height <= min){
            //Not that we do less that or equal to because we need to make sure the value is the furthest to the back
            min = height;
            minInd = i + 1;
        }
    }
    ans = maxInd + (n - 1 - minInd);//Find the sum of the distances to move
    ans = maxInd > minInd ? ans - 1 : ans;//Solve for the case that these values are moved passed eachother
    cout << ans;

    return 0;
}