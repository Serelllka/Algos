#include<iostream>
#include<vector>
 
#define pb push_back
 
typedef long long ll;
 
using namespace std;
 
int main()
{
    #ifndef ONPC
        freopen("isheap.in", "r", stdin);
        freopen("isheap.out", "w", stdout);
    #endif
    ll n;
    vector<ll> vc;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        ll x;
        cin >> x;
        vc.pb(x);
    }
 
    bool f = true;
    for (ll i = 0; (i < vc.size()/2) & f; ++i)
    {
        if (2 * i + 1 < n) f = vc[i] < vc[2 * i + 1];
        if ((2 * i + 2 < n) & f) f = vc[i] < vc[2 * i + 2];
    }
    cout << (f ? "YES\n" : "NO\n");
}
