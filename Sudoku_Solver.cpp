#include <iostream>
#include <vector>
using namespace std;

bool valid(int row, int col, char el, vector<vector<char>> &board)
{
    for (int i = 0; i <= 8; i++)
    {
        int matrow = (3 * (row / 3) + (i / 3));
        int matcol = (3 * (col / 3) + (i % 3));
        if (board[row][i] == el || board[i][col] == el || board[matrow][matcol] == el)
            return false;
    }
    return true;
}

bool solve(vector<vector<char>> &b)
{
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            if (b[row][col] == '.')
            {
                for (char i = '1'; i <= '9'; i++)
                {
                    if (valid(row, col, i, b) == true)
                    {
                        b[row][col] = i;
                        if (solve(b) == true)
                            return true;
                        b[row][col] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>> &board)
{
    solve(board);
}
int main()
{
    vector<vector<char>> b = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '.'}};
    solveSudoku(b);

    for (int i = 0; i < b.size(); i++)
    {
        for (int j = 0; j < b[i].size(); j++)
        {
            cout << " '" << b[i][j] << "' ";
        }
        cout << endl;
    }

    return 0;
}