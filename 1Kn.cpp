#include <bits/stdc++.h>
using namespace std;
int x[10];     // stores the answer
int v[11][11]; // tabulation method table
void knapsack(int p[], int w[], int m, int n)
{
    v[0][0] = {0};
    for (int i = 1; i <= n; i++)
    {
        // int val = ();
        for (int j = 1; j <= m; j++)
        {
            if (w[i - 1] <= j)
            {
                v[i][j] = max(p[i - 1] + v[i - 1][j - w[i - 1]], v[i - 1][j]);
            }
            else
            {
                v[i][j] = v[i - 1][j];
            }
        }
    }
    cout << "v matrix is -> " << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    /*
0 10 10 10 10 10 10 10 10 10
0 10 15 15 25 25 25 25 25 25
0 10 15 15 25 25 30 35 35 45
0 10 15 15 25 25 30 35 35 45
    */
}
int main()
{
    int p[] = {10, 15, 20, 25};
    int w[] = {2, 3, 5, 7};
    int m = 10;
    int n = 4;
    knapsack(p, w, m, n);
}