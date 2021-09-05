#include<iostream>
#include<vector>
 
#define pb push_back
 
using namespace std;
 
long long k = 0;
 
void merge (long long l, long long r, vector<long long> &a)
{
    if (r - l > 0)
    {
        long long m = (l + r) / 2;
        merge (l, m, a);
        merge (m + 1, r, a);
        long long xl = l, xr = m + 1, i = 0;
        long long mas[a.size() + 1];
        while (xl <= m && xr <= r)
        {
            if (a[xl] <= a[xr])
            {
                mas[i] = a[xl];
                xl++;
            }
            else
            {
                mas[i] = a[xr];
                xr++;
                k += m + 1 - xl;
            }
            ++i;
        }
 
        while (xl <= m)
        {
            mas[i] = a[xl];
            i++;
            xl++;
        }
 
        while (xr <= r)
        {
            mas[i] = a[xr];
            i++;
            xr++;
        }
 
        for (int j = 0; j < i; ++j)
        {
            a[l + j] = mas[j];
        }
    }
 
}
 
 
 
int main()
{
    freopen ("inversions.in", "r", stdin);
    freopen ("inversions.out", "w", stdout);
 
    vector<long long> a;
    long long n;
    cin >> n;
    for (long long i = 0; i < n; ++i)
    {
        long long x;
        cin >> x;
        a.pb(x);
    }
    merge (0, a.size() - 1, a);
    cout << k;
 
    return 0;
}
