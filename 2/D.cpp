#include<iostream>
#include<vector>
 
using namespace std;
 
int main()
{
    #ifndef ONPC
        freopen ("antiqs.in", "r", stdin);
        freopen ("antiqs.out", "w", stdout);
    #endif // ONPC
 
    int n;
    cin >> n;
    int a[n];
    for (int i = 1; i <= n; ++i)
    {
        a[i - 1] = i;
    }
    for (int i = 0; i < n; i += 1)
    {
        swap(a[i], a[i / 2]);
    }
 
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << ' ';
    }
}
