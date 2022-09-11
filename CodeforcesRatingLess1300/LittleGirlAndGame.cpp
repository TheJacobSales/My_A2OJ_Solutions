/*************************************
 * Problem:  				276B - Little Girl and Game
 * Geneal Solution:
 * Read rules carefully. Player can remove a character and rearrange. Means starting order doesn't mean anything.
 * Now we understand that the we can only have one character with an odd number of occurances in a palindrome.
 * This means that in order for the players to win, they must remove one character from all other characters 
 * with odd occurances. Thus if there is only one or more characters with odd occurances or if the number of characters
 * with odd occurances is odd, the First player will win. Else the second play will win since there would be an even number
 * of characters with odd occurances.
 * Time complexity: O(n)
**************************************/

#include <bits\stdc++.h>

using namespace std;

#define ll long long
#define ar array

map<char,int> pal;//Store our palindrome

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //Variables
    string word, ans;
    int odds = 0;
    //Algorithm
    cin >> word;
    //Populate datastructure with the character being the key, and the number of occurances as the value
    for (int i = 0; i < word.length(); i++){
        if(pal.find(word[i]) != pal.end()){
            pal[word[i]]++;
        } else {
            pal[word[i]] = 1;
        }
    }
    //Check every key and find the total amount of keys with odd values
    for(auto entry: pal){
        int x = entry.second;
        if (x % 2) odds++;
    }
    //Check to see if the number of odd values meet the conditions of First or Second
    if(odds <= 1 || odds % 2) ans = "First";
    else ans = "Second";
    cout << ans;
    return 0;
}