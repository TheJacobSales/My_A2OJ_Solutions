/*************************************
 * Problem:  			186A - Comparing Strings
 * Geneal Solution:
 * Solution for this is done by looking for the number of differences between the letters in
 * each string. If there are 1 or more differences in the strings, then they cannot be swapped to be the same.
 * Also, if the strings are different lengths, then they cannot be modified to be the same.
 * This implementation tries to go through and simulate the process. Starts comparing the first letters.
 * If there is a differece, it will try to find a valid letter to swap with. If it doesn't find it, it will break
 * and return false. Else it will swap the letters and continue. If it finds any more differences between the string
 * it will break and return false
 * Time complexity: O(n) since the max number of loop iterations is 2 saying that the swapp is needed at the beggining and end of the string
**************************************/

#include <bits/stdc++.h>

using namespace std;

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
    //Variables
    bool swapped = false, valid = true;
    string first, second;
    //Algorithm
    cin >> first >> second;
    if (first.length() != second.length()) cout << "NO";//2 different lengths
    else{
        //Compare each letter in the string
        REP(i,0,first.length()){
            //Found a difference in the string
            if(first[i] != second[i] && swapped){//We already swapped so not possible to make the same
                valid = false;
                break;
            }
            else if(first[i] != second[i] && !swapped){
                int temp = i;
                //Search to find a possible swap to make equal
                while(temp < first.length()){
                    if (first[temp] == second[i] && first[i] == second[temp]){//Found a potential swap
                        swap(first[temp], first[i]);
                        swapped = true;
                        break;
                    }
                    temp++;
                }
                if (!swapped) {//Couldn't find a potential swap, so can't make equal
                    valid = false;
                    break;
                }
            }
        }

        string ans = valid ? "YES": "NO";
        cout << ans;
    }

    return 0;
}