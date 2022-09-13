/*************************************
 * Problem:  		222A - Shooshuns and Sequence
 * Geneal Solution:
 * There are 2 main things to extract from the problem statement. That since the value at k will always
 * be appended to the back of the sequence, then values from k to n must already be equal. This is because
 * that range of numbers from k to n will never be changed. Then we must consider the first part of the sequence.
 * each operation will delete the first value of the sequence, so all we need to do is find the last number
 * in the first sequence that is not equal to the numbers in the last part of the sequence.
 * This means we have to search through all elements once.
 * Time complexity: O(n)
**************************************/

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array
#define vec vector

vector<int> a;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //Variables
    int n, k, input;
    //Algorithm
    cin >> n >> k;
    //Populate our vector
    for (int i = 0; i < n; i++){
        cin >> input;
        a.push_back(input);
    }
    //Check if all numbers in index k-1 to n are all the same
    int index = k - 1, same = a[k - 1], counter = 0, begin = -1;
    while(index < n){
        if(same != a[index]) counter = -1;// not the same, so save -1
        index++;
    }
    //Check what the index is of the last number from index 0 to k is not the same as the numbers in the last part of the sequence
    for(int i = 0; i < k - 1; i++){
        if (a[i] != same) begin = i;//save the index of the last number not equal to same
    }
    int ans;
    if (counter == -1) ans = -1;//Can't not have an all equal sequence
    else ans = begin + 1;//Answer written in a non zero index
    cout << ans;
    return 0;
}