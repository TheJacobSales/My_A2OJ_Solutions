/*************************************
 * Problem:  		222A - Shooshuns and Sequence
 * Geneal Solution:
 * When trying to find the solution, its best to remeber that the only numbers in the sequence are 
 * those with positive values and a max value of 7. Then we can determine there are only 3 possible answers
 * to the conditions:
 * 1 2 4
 * 1 2 6
 * 1 3 6
 * These are the only triplets that can satisfy these conditions. So, we need to keep track of the number of times these values occur in the sequence.
 * If the value ever is 5 or 7, then the sequence is failed immediatly since we cannot seperate all the numbers to satisfy the conditions. Also, any excess of a certain number
 * base on these conditions should fail immediately. In order to check if we have the proper amount of each value, we need to think about the
 * general possibilites. First, we know there are 2 groups that include the value of 2 that satisfy the conditions. We then know that the values of
 * 2 can occur as many times (or more) as there are values of 4. Then we can check if the total amount of 1s is equal to the total number of occurances of 
 * 4 and 6. This indicates that there are a propper amount of 1s. Then we need to check if there are a propper amount of 3s. We can do this by finding 
 * total occurances of 3 and 2 and compare it to the total occurances of 4 and 6. The should be equal.
 * Time complexity: O(n)
**************************************/

#include <bits\stdc++.h>

using namespace std;

#define ll long long
#define ar array
#define vec vector

vec<int> vals(8, 0);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //variables
    int n;
    //Set up out counting data structure
    cin >> n;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        vals[temp]++;
    }
    //Check if this is a a valid sequence base on our condition
    if(vals[5] == 0 && vals[7] == 0 && vals[2] >= vals[4] && vals[1] == vals[4] + vals[6] && vals[2] + vals[3] == vals[4] + vals[6]){
        //These are the total amount of groups that include the value of 4
        for(int i = 0; i < vals[4]; i++){
            cout << "1 2 4\n";
        }
        vals[2] -= vals[4];//This will find our other groups of 2 that do not include 4
        //Groups that include 2 but not 4
        for(int i = 0; i < vals[2]; i++){
            cout << "1 2 6\n";
        }
        //Groups that include value of 3
        for(int i = 0; i < vals[3]; i++){
            cout << "1 3 6\n";
        }
    } else cout << -1;//Didn't fit the conditions

    return 0;
}