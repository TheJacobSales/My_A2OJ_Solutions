#include <bits/stdc++.h>

using namespace std;

const int MAXSIZE = 3;

void solve(vector<vector<int>> grid){
    vector<int> sol;
    int total;
    for (int i = 0; i < MAXSIZE; i++){
        for (int j = 0; j < MAXSIZE; j++){
            total = 0;
            if (i > 0) total += grid[i - 1][j];
            if(i < MAXSIZE - 1) total += grid[i + 1][j];
            if(j > 0) total += grid[i][j - 1];
            if(j < MAXSIZE - 1) total += grid[i][j + 1];
            total += grid[i][j];
            // cout << total << endl;
            sol.push_back(!(total % 2));
        }   
    }
    for (int i = 0; i < MAXSIZE * MAXSIZE; i++){
        cout << sol[i];
        if (i % 3 == 2) cout << endl;
    }
    return;
}

int main(){
    // cout << "start" << endl;
    vector<vector<int>> grid;
    grid.resize(MAXSIZE, vector<int>(MAXSIZE, 0));
    int val;
    for (int i = 0; i < MAXSIZE; i++){
        // cout << "in for" << endl;
        for (int j = 0; j < MAXSIZE; j++){
            cin >> val;
            grid[i][j] = val;
            // cout << grid[i][j] << endl;
        }
    }
    // cout << "Got past input" << endl;
    solve(grid);
    return 0;
}