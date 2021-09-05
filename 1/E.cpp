#include<bits/stdc++.h>
#define pb push_back
 
typedef int ll;
typedef double ld;
 
using namespace std;
 
//map<ll, ll> mp;
vector<pair<ll, ll> > vc;
 
void bubble_sort (vector<pair<ll, ll> >& vec)
{
    bool f = true;
    while (f)
    {
        f = false;
        for (int i = 1; i < vec.size(); ++i)
            if (vec[i].first < vec[i - 1].first)
            {
                f = true;
                swap (vec[i], vec[i - 1]);
            }
    }
}
 
int main()
{
    freopen ("sortland.in", "r", stdin);
    freopen ("sortland.out", "w", stdout);
 
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        ld x;
        cin >> x;
        vc.pb(make_pair(int(x * 100), i + 1));
    }
 
    /**
    for (auto it = vc.begin(); it!= vc.end(); ++it)
    {
        cout << it -> first << ' ' << it -> second << endl;
    }
    **/
 
    bubble_sort(vc);
    auto it = vc.begin() + n/2;
    cout << vc.begin() -> second << ' ' << it -> second << ' ' << vc.rbegin() -> second;
 
}
