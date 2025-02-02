#include <iostream>
#include <string>
using namespace std;

string GameChallenge(string strArr[], int arrLength) {
    string board[3][3] = {
        {strArr[0], strArr[1], strArr[2]},
        {strArr[4], strArr[5], strArr[6]},
        {strArr[8], strArr[9], strArr[10]}
    };
    int dirs[8][2] = {
        {-1,-1}, {-1,0}, {-1,1},
        {0,-1}, {0,1},
        {1,-1}, {1,0}, {1,1}
    };
    string valid[9] = {
        "467", "6", "56",
        "4", "", "",
        "4", "", ""
    };
    
    for (int k = 0; k < 9; ++k) {
        int row = k / 3, col = k % 3;
        for (char d: valid[k]) {
            int drow = dirs[d-'0'][0], dcol = dirs[d-'0'][1];
            int i = row, j = col;
            int cntx = 0, cnto = 0, cnt_ = 0;
            int i_ = -1, j_ = -1;
            while (i >= 0 && i < 3 && j >= 0 && j < 3) {
                if (board[i][j] == "X") cntx += 1;
                else if (board[i][j] == "O") cnto += 1;
                else {
                    cnt_ += 1;
                    i_ = i;
                    j_ = j;
                }
                i += drow;
                j += dcol;
            }
            if (cnt_ == 1 && (cntx == 2 || cnto == 2)) {
                int idx = i_ * 3 + j_;
                if (idx > 5) idx += 2;
                else if (idx > 2) idx += 1;
                string res = to_string(idx);
                return res;
            }
        }
    }
    return "";
}

int main() {
    string strArr[] = {"X", "O", "-", "<>", "-", "O", "-", "<>", "O", "X", "-"};
    // string strArr[] = {"X", "-", "O", "<>", "-", "-", "O", "<>", "-", "-", "X"};
    // string strArr[] = {"X", "O", "X", "<>", "-", "O", "O", "<>", "X", "X", "O"};
    int arrLength = sizeof(strArr) / sizeof(*strArr);
    cout << GameChallenge(strArr, arrLength) << '\n';
    return 0;
}