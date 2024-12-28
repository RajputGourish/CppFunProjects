#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int row, int col, vector<string> &board, int n)
{
    int duprow = row;
    int dupcol = col;

    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row--;
        col--;
    }

    row = duprow;
    col = dupcol;

    while (col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        col--;
    }

    row = duprow;
    col = dupcol;
    while (row < n && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row++;
        col--;
    }

    return true;
}
void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n) == true)
        {
            board[row][col] = 'Q';
            solve(col + 1, board, ans, n);
            board[row][col] = '.';
        }
    }
}
vector<vector<string>> Brute_solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }
    solve(0, board, ans, n);
    return ans;
}

// optimize upper code

void Optimal_solve(int col, vector<string> &board, vector<vector<string>> &ans, int n, vector<int> &leftrow, vector<int> &lowerdiagnol, vector<int> &upperdiagnol)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (leftrow[row] == 0 && lowerdiagnol[row + col] == 0 && upperdiagnol[n - 1 + col - row] == 0)
        {
            board[row][col] = 'Q';
            leftrow[row] = 1;
            lowerdiagnol[row + col] = 1;
            upperdiagnol[n - 1 + col - row] = 1;
            Optimal_solve(col + 1, board, ans, n, leftrow, lowerdiagnol, upperdiagnol);
            board[row][col] = '.';
            leftrow[row] = 0;
            lowerdiagnol[row + col] = 0;
            upperdiagnol[n - 1 + col - row] = 0;
        }
    }
}
vector<vector<string>> Optimal_solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }
    vector<int> leftrow(n, 0), lowerdiagnol(2 * n - 1, 0),
        upperdiagnol(2 * n - 1, 0);
    Optimal_solve(0, board, ans, n, leftrow, lowerdiagnol, upperdiagnol);
    return ans;
}

int main()
{
    vector<vector<string>> ans = Optimal_solveNQueens(4);
    for (auto it : ans)
    {
        for (auto i : it)
        {
            cout<<"| " << i << " |\n";
        }
        cout <<"--------"<< endl;
    }
   return 0; 
}