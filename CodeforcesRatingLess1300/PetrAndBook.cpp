#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> days;
    int n, pages, weekSum = 0, last;

    cin >> n;
    for (int i = 0; i < 7; i++){
        cin >> pages;
        weekSum += pages;
        days.push_back(pages); 
    }
    int total = 0;
    while (true){
        n -= days[total % 7];
        if (n <= 0) break;
        total++;
    }
    cout << total % 7 + 1;
    return 0;
}