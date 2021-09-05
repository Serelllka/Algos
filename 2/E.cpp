#include<iostream>
#include<vector>
 
#define pb push_back
 
using namespace std;
 
int k;
 
int _partition (long long l, long long r, vector<int> &a)
{
    int mid = a[k];
    int i = l, j = r;
    while (i <= j)
    {
        for (;a[i] < mid; ++i) {}
        for (;a[j] > mid; --j) {}
        if (i >= j) break;
        swap (a[i], a[j]);
        i++;
        j--;
    }
    //cout << j << endl;
    return j;
}
 
int _qsort (long long l, long long r, vector<int> &a)
{
    while (1)
    {
        int t = _partition(l, r, a);
        if (t == k)
        {
            //cout << t << endl;
            int x = a[l];
            for (int i = l; i <= t; ++i)
                x = max(x, a[i]);
            return x;
        }
        else if (t > k)
        {
            r = t;
        }
        else
        {
            l = t + 1;
        }
    }
}
 
 
int main()
{
    //30000000
    #ifndef ONPC
        freopen ("kth.in", "r", stdin);
        freopen ("kth.out", "w", stdout);
    #endif
 
    vector<int> vc;
    int n;
    int a, b, c, d, e;
    cin >> n >> k >> a >> b >> c >> d >> e;
    vc.pb(d);
    vc.pb(e);
    k--;
    for (int i = 2; i < n; ++i)
    {
        int t = a * d + b * e + c;
        d = e;
        e = t;
        vc.pb(e);
    }
 
    cout << _qsort (0, vc.size() - 1, vc) << endl;
 
}
