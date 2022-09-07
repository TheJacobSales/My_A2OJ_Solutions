/*************************************
 * Problem - 	139A - Petr and Book
 * Geneal Solution:
 * Continuously subtract pages based on the day until all pages are read.
 * Should be O(N) since at least one page is read each week.
**************************************/

#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> days;
    int n, pages;

    //Handle inputs
    cin >> n;
    for (int i = 0; i < 7; i++){
        cin >> pages;
        days.push_back(pages); 
    }

    //Subtract until there are no pages left
    int total = 0;
    while (true){
        n -= days[total % 7];// make sure to us % 7 to target specific days in week
        if (n <= 0) break;
        total++;//Total days taken
    }
    cout << total % 7 + 1;//Add 1 to total % 7 since answer is not zero indexed.
    return 0;
}