// Kruskal_algotrithm

#include <bits/stdc++.h>
using namespace std;

int parent[10];

int find(int i)
{
    while (parent[i])
        i = parent[i];
    return i;
}

bool uni(int i, int j)
{
    if (i != j)
    {
        parent[j] = i;
        return true;
    }
    return false;
}

int main()
{
    int n, cost[10][10], mincost = 0, edges = 1;

    cin >> n;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> cost[i][j];
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }

    while (edges < n)
    {
        int min = 999, a, b, u, v;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (cost[i][j] < min)
                    min = cost[i][j], a = u = i, b = v = j;

        u = find(u);
        v = find(v);

        if (uni(u, v))
        {
            cout << edges++ << " edge (" << a << "," << b << ") = " << min << '\n';
            mincost += min;
        }

        cost[a][b] = cost[b][a] = 999;
    }

    cout << "Minimum cost = " << mincost << '\n';
}