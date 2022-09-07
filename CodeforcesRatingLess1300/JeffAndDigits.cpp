/*************************************
 * Problem:  352A - Jeff and Digits
 * Geneal Solution:
 * Use a brute force solution to solve. Understand that there can only be a 
 * multiple of 90 if there is one zero located in the ones place. Also notice the hint
 * to the algorith given in the examples. Second example shows a number consistent of only 5s
 * is divisible by 9 only if there are a multile of 9 5s in the digit. We can build an algo
 * using these rules.
**************************************/

#include <bits\stdc++.h>

using namespace std;

#define ll long long
#define ar array

int main(){
    //Vaiables
    int n, input, fives = 0;
    bool zero = false;//Holds if there is a zero
    string ans = "", temp = "";//Use string since int wont hold 10^3 digits

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> input;
        if (input == 5){
            //Count the ammount of 5s
            fives++;
        }
        else {
            temp += to_string(input);//save zeros for final answer
            zero = true;//There is atleast one zero.
        }
    }
    if (!zero) cout << -1;//No zeros in answer = can't be a multiple of 90
    else if (fives < 9) cout << 0;//Not enough 5s to be anything but 0
    else{
        int size = (fives / 9) * 9;//Largest possible multiple of 9 5s
        for(int i = 0; i < size; i++){
            //Create beggining of string with 5s
            ans += "5";
        }
        ans += temp;//Append saved 0s
        cout << ans;
    };
    return 0;
}