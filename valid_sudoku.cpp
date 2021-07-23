#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

bool checkSquare(int x, int y, const vector<vector<char>>& board) {
    unordered_set<int> sett;
    for(int i = x; i < x+3; i++) {
        for(int j = y; j < y+3; j++) {
            if(sett.find(board[i][j]) != sett.end())
                return false;
            if(board[i][j] != '.')
                sett.insert(board[i][j]);
        }
    }
    return true;
}

//[[".",".",".",".","5",".",".","1","."]
 //[".","4",".","3",".",".",".",".","."]
 //[".",".",".",".",".","3",".",".","1"]
 //["8",".",".",".",".",".",".","2","."]
 //[".",".","2",".","7",".",".",".","."]
 //[".","1","5",".",".",".",".",".","."]
 //[".",".",".",".",".","2",".",".","."]
 //[".","2",".","9",".",".",".",".","."]
 //[".",".","4",".",".",".",".",".","."]]


bool isValidSudoku(vector<vector<char>>& board) {
    int n = board.size();
    // Rows
    for(int i = 0; i < n; ++i) {
        unordered_set<int> sett;
        for(int j = 0; j < n; ++j) {
            if(sett.find(board[i][j]) != sett.end())
                return false;
            if(board[i][j] != '.')
                sett.insert(board[i][j]);
        }
    }


    // Cols
    for(int i = 0; i < n; ++i) {
        unordered_set<int> sett;
        for(int j = 0; j < n; ++j) {
            if(sett.find(board[j][i]) != sett.end())
                return false;
            if(board[j][i] != '.')
                sett.insert(board[j][i]);
        }
    }

    // Squares
    for(int i = 0; i < n; i+=3) {
        for(int j = 0; j < n; j+=3) {
            if(!checkSquare(i,j,board))
                return false;
        }
    }
    return true;
}

int main() {
    vector<vector<char>> vect {
        {'.','.','.','.','5','.','.','1','.'},
        {'.','4','.','3','.','.','.','.','.'},
        {'.','.','.','.','.','3','.','.','1'},
        {'8','.','.','.','.','.','.','2','.'},
        {'.','.','2','.','7','.','.','.','.'},
        {'.','1','5','.','.','.','.','.','.'},
        {'.','.','.','.','.','2','.','.','.'},
        {'.','2','.','9','.','.','.','.','.'},
        {'.','.','4','.','.','.','.','.','.'}
    };
    isValidSudoku(vect);


}
