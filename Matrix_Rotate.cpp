#include <iostream>
#include <algorithm>
using namespace std;
const int n = 4, m = 4;

void Brute_Matrix_Rotate_90(int n, int m, int arr[][4]){
    int matrix[n][m] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[j][n - 1 - i] = arr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void Optimal_Matrix_Rotate_90(int n, int m, int arr[][4])
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        // reverse(arr[i][0], arr[i][n]);
        int p1 = 0, p2 = n - 1;
        while (p1 < p2)
        {
            swap(arr[i][p1], arr[i][p2]);
            p1++;
            p2--;
        }
    }
}
int main()
{
    int arr[n][m] = {{1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12},
                     {13, 14, 15, 16}};

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl
         << endl;

    // Brute_Matrix_Rotate_90(n, m, arr);
    Optimal_Matrix_Rotate_90(n, m, arr);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}