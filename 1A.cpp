#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int a, n, m, nr, mr;
    cin >> n >> m >> a;
    nr = n / a;
    mr = m / a;
    if (n % a != 0) nr++;
    if (m % a != 0) mr++;
    cout << nr * mr;
}