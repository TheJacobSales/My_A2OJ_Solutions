/*************************************
 * Problem - 	224A - Parallelepiped
 * Geneal Solution:
 * Mainly a mathematical problem. Need to solve the equation for each of the 
 * unique vertices on the parallelepiped using the given areas. Key to the solution
 * is setting the sides based on this information:
 * s1 = ab
 * s2 = bc
 * s3 = ac
 * The following solution can be used by each vertex:
 * a = s1 / b where b = s2 / c and c = s3 / a
 * then a = s1 * s3 * a / s2. 'a' can be multiplied to both sides making --> a^2 = s1 * s3 / s2.
 * Take the square root of each side to find final answer for one vertex. a = sqrt(s1 * s3 / s2.)
**************************************/

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    cout << 4 * (sqrt(a * c / b) + sqrt(a * b / c) + sqrt(b * c / a));
    return 0;
}