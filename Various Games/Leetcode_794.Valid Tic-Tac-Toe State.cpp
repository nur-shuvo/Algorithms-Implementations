/**
TC: O(N*N)

State is valid if

1. xCount == 0Count or xCount = yCount + 1
2. If 0 is in winning condition
   i. if x is not in winning condition
   ii. xCount == 0Count
3. If x is in winning condition, then xCount = yCount + 1

*/

class Solution {
public:

    bool isWinning(vector<string>& board, char c) {
        if (board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][2] == c) return true;
        if (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][2] == c) return true;
        if (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][2] == c) return true;

        if (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[2][0] == c) return true;
        if (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[2][1] == c) return true;
        if (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[2][2] == c) return true;

        if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == c) return true;
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] == c) return true;

        return false;
    }

    bool validTicTacToe(vector<string>& board) {
        int freqX, freq0;
        freqX = freq0 = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 'X') freqX++;
                if (board[i][j] == 'O') freq0++;
            }
        }
        if (!((freqX == freq0) || (freqX == freq0 + 1))) return false;

        if (isWinning(board, 'O')) {
            if (isWinning(board, 'X')) return false;
            if (freqX != freq0) return false;
        }

        if (isWinning(board, 'X')) {
            if (freqX != freq0 + 1) return false;
        }

        return true;
    }
};