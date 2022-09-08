/*************************************
 * Problem:  			A - Translation
 * Geneal Solution:
 * The solution here is straightforward. Just revers the string of the second input
 * and compare it to the first. If they are are same, the print "YES". Else, print "NO".
 * Time complexity, O(N).
**************************************/

#include <bits\stdc++.h>

using namespace std;

#define ll long long
#define ar array

string reverse(string word){
    //Set pointers to beginning and end
    int left = 0, right = word.length() - 1;
    while(left < right){
        swap(word[left], word[right]);//Swap left and right
        left++;
        right--;
    }
    return word;
}

int main(){
    //Optimize stdio
    ios::sync_with_stdio(0);
    cin.tie(0);
    //Variables
    string s, t;
    cin >> s >> t;
    //Check if the revers of second input is the same as the first
    if (reverse(t) == s) cout << "YES";
    else cout << "NO";
    return 0;
}