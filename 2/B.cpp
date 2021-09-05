#include<iostream>
#include<vector>
 
#define pb push_back
 
using namespace std;
 
void merge (int l, int r, vector<pair<string, string> > &a)
{
    if (l == r) return;
    if (r - l == 1)
    {
        if (a[r].first < a[l].first) swap (a[r], a[l]);
        return;
    }
    int m = (l + r) / 2;
    merge (l, m, a);
    merge (m + 1, r, a);
    int xl = l, xr = m + 1, i = 0;
    pair<string, string> mas[r - l + 1];
    while (r - l + 1 != i)
    {
        if (xl > m)
            mas[i++] = a[xr++];
        else if (xr > r)
            mas[i++] = a[xl++];
        else if (a[xl].first > a[xr].first)
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
    #ifndef ONPC
        freopen ("race.in", "r", stdin);
        freopen ("race.out", "w", stdout);
    #endif // ONPC
 
    vector<pair<string, string> > a;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string str1, str2;
        cin >> str1 >> str2;
        a.pb(make_pair(str1, str2));
    }
 
    merge (0, a.size() - 1, a);
 
    string str1 = "";
    for (int i = 0; i < n; ++i)
    {
        if (str1 != a[i].first)
        {
            cout << "=== " << a[i].first << " ===\n";
            str1 = a[i].first;
        }
        cout << a[i].second << endl;
    }
 
}
