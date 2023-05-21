#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Edge
{
    int v1;
    int v2;
    int weight;
};
int w[4][4] = {{0, 9, -4, 9999},
               {6, 0, 9999, 2},
               {9999, 5, 0, 9999},
               {9999, 9999, 5, 0}};
int noV = 4;
int d[4][4];
void floyd(int src)
{
    for (int i = 0; i < noV; i++)
    {
        for (int j = 0; j < noV; j++)
        {
            d[i][j] = w[i][j];
        }
        // cout << endl;
    }
    for (int i = 0; i < noV; i++)
    {
        for (int j = 0; j < noV; j++)
        {
            cout << d[i][j] << " ";
        }
        cout << endl;
    }
    for (int k = 0; k < noV; k++)
    {
        for (int i = 0; i < noV; i++)
        {
            for (int j = 0; j < noV; j++)
            {
                // via j
                d[i][j] = min(d[i][j], (d[i][k] + d[k][j]));
                // if (d[i][j] > d[i][k] + d[k][j])
                // {
                //     d[i][j] = d[i][k] + d[k][j];
                // }
            }
        }
    }
    for (int i = 0; i < noV; i++)
    {
        for (int j = 0; j < noV; j++)
        {
            cout << d[i][j] << " ";
        }
        cout << endl;
    }
}

int main(void)
{
    floyd(0);
    return 0;
}
