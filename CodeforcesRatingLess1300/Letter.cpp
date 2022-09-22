/*************************************
 * Problem:  		43B - Letter
 * Geneal Solution:
 * Best way to do this is by using a map to hold all possible letters to be used in headers.
 * With this set up, we can imagine these as already cut up magazine letters in front of you. 
 * Then we just iterate through the second sentence to see if we have all the letters in the hash map.
 * If we don't have enought letters, we escape the loop and print "NO". Else, we have enought letters and print "YES".
 * Time complexity: O(n) assuming searching through the hasmap is idealy O(1)
**************************************/

#include <bits/stdc++.h>

using namespace std;
//All the cool definition to help with competitions
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i < b; i++)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

map<char,int> headers;//Hash map to hold all the letters in the header

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //Variables
    string s1, s2, ans;
    //Algorithm
    getline(cin, s1);//Get line is easier for this problem since we need entire line
    getline(cin, s2);
    bool valid = true;
    //Setting up hashmap based on how many of each letter we have
    for(int i = 0; i < s1.length(); i++){
        if(s1[i] == ' ') continue;//Don't care about spaces
        if(headers.find(s1[i]) == headers.end()){
            headers[s1[i]] = 1;
        } else headers[s1[i]]++;
    }
    //Compare our sentence to the letters in hash map
    for(int i = 0; i < s2.length(); i++){
        if(s2[i] == ' ') continue;//Don't care about spaces
        if(headers.find(s2[i]) == headers.end() || headers[s2[i]] == 0){
            valid = false;//We found a letter that doesn't exist in hashmap or ran out of letters
            break;//Escape
        } else headers[s2[i]]--;
    }
    ans = valid ? "YES" : "NO";
    cout << ans;

    return 0;
}