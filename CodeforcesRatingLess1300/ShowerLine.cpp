/*************************************
 * Problem:  					431B - Shower Line
 * Geneal Solution:
 * Best solution is to use brute force and simluate the situations. When using c++, we can use
 * next_permutaion to go through all permutations of the solution.
 * Time complexity: O(n!)
**************************************/

#include <bits\stdc++.h>

using namespace std;

#define ll long long
#define ar array
#define vec vector

const int STUDENTS = 5;// number of students in line
vec<vec<int>> happy(STUDENTS, vec<int>(STUDENTS, 0));//2d vector of student happiness

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //Variables
    vec<int> p;
    int happySum = -1, tmp, g;//happy sume must be -1 to find absolute min
    //Fill in datastructure
    for(int i = 0; i < STUDENTS; i++){
        for(int j = 0; j < STUDENTS; j++){
            cin >> happy[i][j];
        }
    }
    //Set p to be based on permutation values(0,1,2,3,4)
    for(int i = 0; i < STUDENTS; i++)
        p.push_back(i);
    
    do{
        // first and second talk, second and 3rd talk
        tmp = happy[p[0]][p[1]] + happy[p[1]][p[0]];
        tmp += happy[p[2]][p[3]] + happy[p[3]][p[2]];
        //2nd and 3rd talk, 4th and 5th talk
        tmp += happy[p[1]][p[2]] + happy[p[2]][p[1]];
        tmp += happy[p[3]][p[4]] + happy[p[4]][p[3]];
        //3rd and 4th talk
        tmp += happy[p[2]][p[3]] + happy[p[3]][p[2]];
        //4th and 5th talk
        tmp += happy[p[3]][p[4]] + happy[p[4]][p[3]];
        
        if(happySum < tmp) happySum = tmp;//Keep the largest sum
    }while(next_permutation(p.begin(), p.end()));//next_permutation goes through each unique permutation(0,1,2,3,4  to 0,2,3,4,1 to 0,3,4,1,2 etc.)

    cout << happySum;

    return 0;
}