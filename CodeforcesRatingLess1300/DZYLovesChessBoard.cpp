/*************************************
 * Problem:  			445A - DZY Loves Chessboard
 * Geneal Solution:
 * Best way to solve the problem is to associate each space with
 * the sum of the row and colum position. Ex: board[0][0] is 0, board[2][1] is 3, board[4][5] is 9.
 * By doing this, we can just seperate each board piece by even and odd numbers. Odd will be white, and even will be black.
 * This will guarentee that the entire board will no have consecutive colors. For the bad positions,
 * we will just keep it as the '-' character. 
 * Time complexity: O(n * m) or the size of the board.
**************************************/

#include <bits\stdc++.h>

using namespace std;

#define ll long long
#define ar array

int main(){
    //Oprtimize stdio
    ios::sync_with_stdio(0);
    cin.tie(0);
    //Variables
    string row;
    int n, m;
    cin >> n >> m;
    for(int i = 0 ; i < n; i++){
        cin >> row;
        for(int j = 0; j < m; j++){
            //Check if the char in row is either '.' or '-'
            if (row[j] == '.'){ 
                if ((j + i) % 2) cout << 'W';//Odd spaces are 'W'
                else cout << 'B';//Even spaces are 'B'
            } else {
                cout << '-';//Keep the same if bad space
            }
        }
        cout << "\n";
    }
    return 0;
}