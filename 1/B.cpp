#include<iostream>
#include<fstream>
 
using namespace std;
 
int main()
{
    freopen ("aplusbb.in", "r", stdin);
    freopen ("aplusbb.out", "w", stdout);
 
    long long x, y;
 
    cin >> x >> y;
    cout << x + y * y;
 
    return 0;
}
