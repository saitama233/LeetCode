/*
 * 79. Word Search
 * Medium
 * 
 * Given a 2D board and a word, find if the word exists in the grid.
 * The word can be constructed from letters of sequentially adjacent cell, 
 * where "adjacent" cells are those horizontally or vertically neighboring. 
 * The same letter cell may not be used more than once.
 * 
 * Example:
 * board =
 * [
 *     ['A','B','C','E'],
 *     ['S','F','C','S'],
 *     ['A','D','E','E']
 * ]
 * 
 * Given word = "ABCCED", return true.
 * Given word = "SEE", return true.
 * Given word = "ABCB", return false.
 * Accepted 257,624    Submissions 843,126
 */

/*
 * 回溯，2.5h，一次AC， 
 * Runtime: 36 ms, faster than 71.71% of C++ online submissions for Word Search.
 * Memory Usage: 11.5 MB, less than 68.60% of C++ online submissions for Word Search.
 */
 
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> status(board.size(), vector<bool>(board[0].size()));
        if (!word.size())
            return board.size() ? true : false;
        for (size_t i = 0; i < status.size(); i++) {
            for (size_t j = 0; j < status[i].size(); j++) {
                status[i][j] = false;
            }
        }
        for (size_t i = 0; i < board.size(); i++) {
            for (size_t j = 0; j < board[i].size(); j++) {
                if (backtrace(board, i, j, status, word, 0))
                    return true;
            }
        }
        return false;
    }
    bool backtrace(vector<vector<char>>& board, size_t i, size_t j,
                vector<vector<bool>>& status, string &word, unsigned int cur) {
        if (board[i][j] != word[cur])
            return false;
        /* cout << "i is " << i << ", j is " << j << endl; */
        
        if (status[i][j]) {
            /* cout << "status[i][j] is " << status[i][j] << endl; */
            return false;
        }
        
        if (cur == word.size() - 1)
            return true;
        /* cout << "board[i][j] is " << board[i][j] << ", word[cur] is " << word[cur] << endl; */
        
        status[i][j] = true;
        if (i > 0) {
            if (backtrace(board, i - 1, j, status, word, cur + 1))
                return true;
        }
        if (i < board.size() - 1) {
            if (backtrace(board, i + 1, j, status, word, cur + 1))
                return true;
        }
        if (j > 0) {
            if (backtrace(board, i, j - 1, status, word, cur + 1))
                return true;
        }
        if (j < board[i].size() - 1) {
            if (backtrace(board, i, j + 1, status, word, cur + 1))
                return true;
        }
        status[i][j] = false;
        return false;
    }
};

int main()
{
    return 0;
}
