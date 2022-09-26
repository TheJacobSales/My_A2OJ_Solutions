/*************************************
 * Problem:  				258A - Little Elephant and Bits
 * Geneal Solution:
 * Pattern can be found in the examples. We can see that the first 0 to appear in the bit string
 * always gets deleted in the examples. If we think about it, we would not want to delete any 1s
 * since they are inherently greater that 0. We also know that there are no leading 0s in the problem.
 * We also know that 0s closest to the most significant bit carry the most weight because of their
 * place value. This means when this zero is erased, a 1 will fill it's place.
 * This automatically makes this the max possible value when removing a bit. Also keep in mind the
 * edge case where there are only 1s in the value. Thus, we can remove any bit and reach a max value.
 * Time complexity: O(n) where n is the size of the input string
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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a;
    bool found = false;
    cin >> a;
    REP(i, 0, a.length()){
        if(!found && a[i] == '0'){
            a.erase(a.begin() + i);
            found = true;
            break;
        }
    }
    if (!found) a.pop_back();
    cout << a;

    return 0;
}