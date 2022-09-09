/*************************************
 * Problem:  			459B - Pashmak and Flowers
 * Geneal Solution:
 * Solve this problem by first finding what the max and min numbers are. We can use these to find the difference.
 * Then count all the occurances of the min and max. If the min and max are equal, this means all numbers
 * are equal. The solution equation for this is n * (n - 1) / 2. Otherwise, it is the count1 * count2 where
 * count1 is the total number of occurances of the max number and count2 is the total number of occurances of
 * the min number.
**************************************/

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //Variables
    vector<int> nums;// Here to keep for the count in second for loop
    ll totalMax = 0, totalMin = 0, maxDif, maxCombo, maxFlow = 0, minFlow = INT_MAX, n, b;
    //Algo
    cin >> n;
    //Find max and min numbers
    for (int i = 0; i < n; i++){
        cin >> b;
        nums.push_back(b);
        maxFlow = max(maxFlow, b);
        minFlow = min(minFlow, b);
    }
    //Find the numver of occurances of the max and min numbers
    for (int i = 0; i < n; i++){
        if (nums[i] == maxFlow) totalMax++;
        if (nums[i] == minFlow) totalMin++;
    }
    //If all the numbers are equal, then n * (n - 1) / 2. Else multiply the number of occurances
    maxCombo = maxFlow == minFlow ? n * (n - 1) / 2 : totalMax * totalMin;
    cout << maxFlow - minFlow << " " << maxCombo;
    return 0;
}