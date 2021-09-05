#include<bits/stdc++.h>
#define pb push_back
 
typedef long long ll;
 
using namespace std;
 
vector<ll> vc;
 
void buble_sort (vector<ll>& vc)
{
    bool f = true;
    while (f)
    {
        f = false;
        for (int i = 1; i < vc.size(); ++i)
            if (vc[i] < vc[i - 1])
            {
                f = true;
                swap (vc[i], vc[i - 1]);
            }
    }
}
 
int main()
{
 
    freopen ("smallsort.in", "r", stdin);
    freopen ("smallsort.out", "w", stdout);
 
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int x;;
        cin >> x;
        vc.pb(x);
    }
 
    //sort(vc.begin(), vc.end());
    buble_sort(vc);
 
    for (auto it = vc.begin(); it != vc.end(); ++it)
        cout << *it << ' ';
 
    return 0;
}
