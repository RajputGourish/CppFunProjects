#include <iostream>
#include <vector>
using namespace std;

void solve(vector<vector<int>> &mat, vector<string> &ans, string output, vector<vector<int>> &vis, int row, int col, int n, int di[], int dj[])
{
    // base case
    if (row == n - 1 && col == n - 1)
    {
        ans.push_back(output);
        return;
    }

    string dir = "DLRU";
    for (int ind = 0; ind < 4; ind++)
    {
        int nexti = row + di[ind];
        int nextj = col + dj[ind];
        if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj] && mat[nexti][nextj] == 1)
        {
            vis[row][col] = 1;
            solve(mat, ans, output + dir[ind], vis, nexti, nextj, n, di, dj);
            vis[row][col] = 0;
        }
    }
}
vector<string> findPath(vector<vector<int>> &mat)
{
    int n = mat.size();
    vector<string> ans;
    vector<vector<int>> vis(n, vector<int>(n, 0));
    int di[] = {+1, 0, 0, -1};
    int dj[] = {0, -1, +1, 0};
    if (mat[0][0] == 1)
        solve(mat, ans, "", vis, 0, 0, n, di, dj);
    return ans;
}
int main()
{
    vector<vector<int>> mat = {{1, 0, 0, 0},
                               {1, 1, 0, 1},
                               {1, 1, 0, 0},
                               {0, 1, 1, 1}};

    vector<string> ans = findPath(mat);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}