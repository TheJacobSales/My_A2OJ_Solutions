/*************************************
 * Problem:  				450B - Jzzhu and Sequences
 * Geneal Solution:
 * Most challenging part of the problem is reading it. To make it more simple, its to find the maximum amount of
 * point that can be chosen from the cards. Once done picking K cards out of N, then points are added up the 
 * following way: Each of the same cards are multiplied together. For example, if you choose 5 'D' cards, then that will be
 * 25 points(5 points for each 'D' card). If there were 3 'D' cards chosen, then that will be 9 points. (3 points for each of the 3 Ds)
 * So, the best way to solve this is to make a greedy algorithm that takes the best outcome. So we can
 * find the most occuring card in the set, and the the second most occuring, and so on until we've chosen k cards.
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

map<char,ll> apple;// Holds the frequency of all cards

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //Variables
    ll n, k, ans = 0;
    string cards;
    //Algorithm
    cin >> n >> k >> cards;
    //Finds frequency of each card in set
    for (int i = 0; i < cards.length(); i++){
        if (apple.find(cards[i]) == apple.end()) apple[cards[i]] = 1;
        else apple[cards[i]]++;
    }
    vector<ll> cardSort;//Vector to hold frequency of each card
    for (auto x: apple){
        cardSort.push_back(x.second);
    }
    sort(cardSort.begin(), cardSort.end());//Sort by increaseing frequency
    //Go through frequency vector backwards and subtract number of cards used from k
    for(int i = cardSort.size() - 1; i >= 0; i--){
        //Reach the max amount of cards that can be selected
        if (k - cardSort[i] <= 0){
            ans += k * k;//just the square of rest of cards
            break;
        } else{
            //just the square of the card frequency
            ans += cardSort[i] * cardSort[i];
            k -= cardSort[i];
        }
    }
    cout << ans;

    return 0;
}