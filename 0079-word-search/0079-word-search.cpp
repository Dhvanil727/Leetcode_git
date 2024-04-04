#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, int row, int column, int wordindex) {
        if (wordindex == word.length()) {
            return true;
        }
        int r = board.size();
        int c = board[0].size();
        if (row < 0 || column < 0 || row >= r || column >= c) {
            return false;
        }
        if (board[row][column] == '#' || board[row][column] != word[wordindex]) {
            return false;
        }
        char ch = board[row][column];
        board[row][column] = '#';
        if (dfs(board, word, row - 1, column, wordindex + 1) ||
            dfs(board, word, row, column + 1, wordindex + 1) ||
            dfs(board, word, row + 1, column, wordindex + 1) ||
            dfs(board, word, row, column - 1, wordindex + 1)) {
            return true;
        }
        board[row][column] = ch;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[0].size(); c++) {
                if (board[r][c] == word[0]) {
                    if (dfs(board, word, r, c, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
