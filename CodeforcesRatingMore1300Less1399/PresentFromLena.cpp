/*************************************
 * Problem:  					118B - Present from Lena
 * Geneal Solution:
 * Solution is implementation of pattern. It's a good problem if you're not familiar with construction problems.
 * Best way to do this is to have 2 different counters. These will keep track of the index where numbers should
 * be printed and also keep track of which numbers should be printed. Since it is always increasing till till the
 * middle and then it decreases, we can copy that behavior using conditional statements. In order to format this 
 * based on the problem parameters, we also need to break as soon as the last character in the row is printed.
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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //Variables
    int n;
    cin >> n;
    int countCol = 0;//Counter for column space
    //Algorithms
    REP(i, 0 ,n * 2 + 1){
        int countRow = 0;//Counter for row number
        REP(j, 0, n * 2 + 1){
            //Check if we are in the range of j that needs to print a char
            if ( j >= (n * 2 + 1)/2 - countCol && j <= (n * 2 + 1)/2 + countCol ){
                cout << countRow;
                //Increase if we are less than half of j, else decrease
                if (j < (n * 2 + 1)/2) countRow++;
                else countRow--;
                //Check if we have printed the last number in the range
                if(j >= (n * 2 + 1)/2 + countCol) break;
                else cout << " ";
            } else{
                if(j != n * 2) cout << "  ";//Note we need to print out a double space to line up digits correctly
                else cout << " ";
            }
        }
        //Increase if we are less than half of i, else decrease
        if (i < (n * 2 + 1)/2) countCol++;//Not this enlarges or shrinks the range
        else countCol--;
        cout << "\n";
    }

    return 0;
}