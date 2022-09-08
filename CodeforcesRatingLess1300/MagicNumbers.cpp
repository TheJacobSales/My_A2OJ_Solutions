/*************************************
 * Problem:  		320A - Magic Numbers
 * Geneal Solution:
 * The solution to this problem is easiest using a string rather than parsing
 * an integer. The reason is that we can access individual digits using array opperators.
 * Thiking of the pattern, there are only 3 sequences: 1, 14, and 144. We can create a 2 pointer
 * solution where the digit check has to start with a 1. If it does, then it checks the next 2 digits are 4s.
 * If not, then it checks the next digit. If there is a 4, then the index jumps to the digit right after the furthest 4.
 * If none of these conditions are true, then we break the look and print "NO". If conditions run true for entire input,
 * then we print 'YES'. Time compleity: O(n) where n is the length of the input.
**************************************/

#include <bits\stdc++.h>

using namespace std;

#define ll long long
#define ar array

int main(){
    //Optimize stdio
    ios::sync_with_stdio(0);
    cin.tie(0);
    //Variables
    string n, ans;
    bool magic = true;//Sets if any of the conditions fail

    cin >> n;
    int i = 0;
    while (i < n.length()){
        if(n[i] == '1' && n[i + 1] == '4' && n[i + 2] == '4') i += 3;// check 144
        else if(n[i] == '1' && n[i + 1] == '4') i += 2;// check 14
        else if(n[i] == '1') i += 1;//check 1
        else{
            magic = false;//All conditions failed
            break;
        }
    }

    ans = magic ? "YES" : "NO";
    cout << ans;

    return 0;
}