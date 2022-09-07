/*************************************
 * Problem:  199A - Hexadecimal's theorem
 * Geneal Solution:
 * Tricky at first glance, but you have to remember the Fibonacci rule(Fi = F(i-1) + F(i-2)).
 * Since each number in the sequence is just the sum of the 2 prior number in
 * the sequence, then we can find 3 unique fibonachi number the following way:
 * Fi = F(i-1) + F(i-2) = F(i-1) + (F(i-3) + F(i-4))
 * This is because F(i-2) = F(i-3) + F(i-4)
 * Thus create an algorithm that will find the 4 prior fibonachi numbers.
**************************************/

#include <bits\stdc++.h>

using namespace std;

#define ll long long
#define ar array

int main(){
    // set and intitialize variables for Fibonachi Sequence
    int n, a = 0, b = 1, temp = 1, c = 2, fib = c + a + b;
    cin >> n;
    if (n == 0) a = b = c = 0;// 0 fibonachi sum is a sum of 0s
    else if (n == 1) {
        //Sum must be a sum of 0s and a single 1
        b = 0;
        c = 1;
    } else if (n == 2){
        //sum must be a pair of 1s and a 0
        c = 1;
    } else if (n == 3){
        //Can be a mix of 1s, 0s, and 2s. Programmer's choice
        a = c = 1;
    } else{
        //Algo that will keep track of 4 previous Fib numbers
        while (fib < n){
            a = b;
            b = temp;
            temp = c;
            c = fib;
            fib = c + a + b;
        }
    }
    cout << a << " " << b << " " << c;
}