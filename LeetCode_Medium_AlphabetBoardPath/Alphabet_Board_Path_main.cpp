/*
Alphabet Board Path
On an alphabet board, we start at position (0, 0), corresponding to character board[0][0].

Here, board = ["abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"], as shown in the diagram below.

We may make the following moves:

'U' moves our position up one row, if the position exists on the board;
'D' moves our position down one row, if the position exists on the board;
'L' moves our position left one column, if the position exists on the board;
'R' moves our position right one column, if the position exists on the board;
'!' adds the character board[r][c] at our current position (r, c) to the answer.
(Here, the only positions that exist on the board are positions with letters on them.)

Return a sequence of moves that makes our answer equal to target in the minimum number of moves.  You may return any path that does so.

https://leetcode.com/problems/alphabet-board-path/

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    string alphabetBoardPath(string target) {
        string res;
        //for letter ?, the row index is (?-'a') / 5, the row index is (?- 'a') % 5.
        int row1 = 0, col1 = 0;
        for (int i = 0; i < target.size(); i++) {
            int row2 = (target[i] - 'a') / 5;
            int col2 = (target[i] - 'a') % 5;

            if (col2 < col1) {
                res.append(string(col1 - col2, 'L'));
            }
            if (row2 > row1) {
                res.append(string(row2 - row1, 'D'));
            }
            if (row2 < row1) {
                res.append(string(row1 - row2, 'U'));
            }
            if (col2 > col1) {
                res.append(string(col2 - col1, 'R'));
            }
            res.push_back('!');
            row1 = row2;
            col1 = col2;
        }
        return res;
    }
};

int main()
{


	return 0;
}