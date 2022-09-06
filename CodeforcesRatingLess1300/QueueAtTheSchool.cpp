#include <bits/stdc++.h>

using namespace std;

int main(){
    int t, n;
    string line;
    cin >> n >> t >> line;
    while(t--){
        int i = 0;
        while(i < line.size() - 1){
            if (line[i] == 'B' && line[i + 1] == 'G'){
                swap(line[i], line[i + 1]);
                i++;
            }
            i++;
        }
    }
    cout << line;
    return 0;
}
