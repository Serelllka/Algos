#include<iostream>
#include<fstream>
 
using namespace std;
 
int main()
{
    freopen ("turtle.in", "r", stdin);
    freopen ("turtle.out", "w", stdout);
 
    int x[1000][1000];
    int h, w;
    cin >> h >> w;
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            cin >> x[i][j];
        }
    }
 
    for (int i = h - 1; i >= 0; --i)
    {
        for (int j = 0; j < w; ++j)
        {
            int a = x[i][j];
            if (i != h - 1)
            {
                x[i][j] = x[i + 1][j] + a;
            }
            if (j != 0)
            {
                x[i][j] = max(x[i][j], x[i][j - 1] + a);
            }
        }
    }
 
    cout << x[0][w - 1];
 
    return 0;
}
