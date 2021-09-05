#include<iostream>
#include<vector>
 
#define pb push_back
 
using namespace std;
 
void merge (int l, int r, vector<int> &a)
{
    if (l == r) return;
    if (r - l == 1)
    {
        if (a[r] < a[l]) swap (a[r], a[l]);
        return;
    }
    int m = (l + r) / 2;
    merge (l, m, a);
    merge (m + 1, r, a);
    int xl = l, xr = m + 1, i = 0;
    int mas[a.size()];
    while (r - l + 1 != i)
    {
        if (xl > m)
            mas[i++] = a[xr++];
        else if (xr > r)
            mas[i++] = a[xl++];
        else if (a[xl] > a[xr])
            mas[i++] = a[xr++];
        else
            mas[i++] = a[xl++];
    }
    for (int j = 0; j < i; ++j)
    {
        a[l + j] = mas[j];
    }
}
 
 
 
int main()
{
    freopen ("sort.in", "r", stdin);
    freopen ("sort.out", "w", stdout);
 
    vector<int> a;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        a.pb(x);
    }
    merge (0, a.size() - 1, a);
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << ' ';
    }
 
}
