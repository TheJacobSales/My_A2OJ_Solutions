#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

vector <int> force(3, 0);
int a, b, c;

void sums(){
    cin >> a >> b >> c;
    force[0] += a;
    force[1] += b;
    force[2] += c;
}

int main(){
   int numInputs = 0;
   cin >> numInputs;
   while (numInputs--) sums();
   for (int x: force){
    if (x != 0) {
        cout << "NO";
        return 0;
    }
   }
    cout << "YES" << endl;
   return 0;
}