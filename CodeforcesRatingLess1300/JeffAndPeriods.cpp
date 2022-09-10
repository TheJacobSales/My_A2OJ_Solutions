/*************************************
 * Problem:  			352B - Jeff and Periods
 * Geneal Solution:
 * Main part of this problem is choosing the data structure to use to interact with the data.
 * Best to think of the needed data. This problem needs to keep track of the value and the index where it occurs.
 * Also need to make sure the solution is printed in accending order. So, we should use a vector of pairs. Pairs
 * will consist of the value and which index it occurs in. Populate our datastructure with this info, then sort it based
 * on value. All we need to do now is check if distance of the same values are the same. Simply run through our 
 * create data structure and check if this is true. Single values should have an interval of 0.
 * Time complexity: O(n)
**************************************/

#include <bits\stdc++.h>

using namespace std;

#define ll long long
#define ar array

vector<pair<int,int>> a, ans;//Our datastructure for algorithm

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //Variables
    int n, in, valid = 0, dif = 0;
    //Algorithm
    cin >> n;
    //Populate our datastructure
    for (int i = 0; i < n; i++){
        cin >> in;
        a.push_back(make_pair(in, i));
    }
    //Sort the datastructure based on value
    sort(a.begin(), a.end());
    //Check if each value occurs at a regular interval
    bool isValid = true;//Valid means the value is a singular value or occurs at a regular interval
    for(int i = 1; i < n; i++){
        //Checks if it is a singular value or value changes
        if (a[i].first == a[i - 1].first){
            if (dif == 0) dif = a[i].second - a[i - 1].second;//No longer a singular value and has an interval
            if (dif != a[i].second - a[i - 1].second) isValid = false;//Inteval changed making it invalid
            // cout << dif << " " << a[i].second - a[i - 1].second << " " << isValid << endl;
        } else {
            //Add value and interval if valid
            if (isValid) {
                // cout << "Found True! " << dif << "\n";
                valid++;
                ans.push_back(make_pair(a[i - 1].first, dif));
            }
            //Reset variables
            dif = 0;
            isValid = true;
        }
    }
    //Make sure to check the last value for valid values
    if(dif == 0 || isValid){
        valid++;
        ans.push_back(make_pair(a.back().first, dif));
    }
    //Output results
    cout << valid << "\n";
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
    return 0;
}