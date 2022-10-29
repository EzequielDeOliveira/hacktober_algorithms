#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 1e9+7;

ll power(ll a, ll b) {
    ll result = 1;
    while(b) {
        if (b % 2) result = (result * a) % MOD;
        a = (a * a) % MOD;
        b /= 2;
    }
    return result;
}
