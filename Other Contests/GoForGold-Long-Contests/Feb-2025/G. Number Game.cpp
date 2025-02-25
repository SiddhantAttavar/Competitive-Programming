#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define int long long
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e18 + 31;

int mod_pow(__int128_t a, int b, int m = MOD) {
    __int128_t res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % m;
        }
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int phi(int n)
{    
    int result = n;   // Initialize result as n

    // Consider all prime factors of n and subtract their
    // multiples from result
    for (int p=2; p*p<=n; ++p)
    {
        // Check if p is a prime factor.
        if (n % p == 0)
        {
            // If yes, then update n and result 
            while (n % p == 0)
                n /= p;
            result -= result / p;
        }
    }

    // If n has a prime factor greater than sqrt(n)
    // (There can be at-most one such prime factor)
    if (n > 1)
        result -= result / n;
    return result;
}

int mod_pow_rep(int a, int b, int m = MOD) {
    if (m == 1) {
        return 0;
    }
    int x = phi(m);
    print(x);
    cout.flush();
    return mod_pow(a, mod_pow_rep(a, b - 1, x), m);
}


#define ll __int128_t
#define rep range

int modLog(ll a, ll b, ll m) {
	ll n = (ll) sqrt(m) + 1, e = 1, f = 1, j = 1;
	unordered_map<ll, ll> A;
	while (j <= n && (e = f = e * a % m) != b % m)
		A[e * b % m] = j++;
	if (e == b % m) return j;
	if (__gcd(m, e) == __gcd(m, b)) 
		rep(i,2,n+2) if (A.count(e = e * f % m))
			return n * i - A[e];
	return -1;
}

int32_t main() {
    setup();

    int n;
    input(n);

    print(modLog(42, 960002411612632915, MOD));
    return 0;

    int m = MOD;
    int o = 960002411612632915;
    int x = o;
    int c = 0;
    int k = 42;
    do {
        if (c % 1000000 == 0) {
            print(c, x);
            cout.flush();
        }
        x = mod_pow(k, x, m);
        c++;
    } while (x != o);
    print(c);
}
