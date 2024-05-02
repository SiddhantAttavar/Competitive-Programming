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
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7;

double dist(double a, double b, double x, double y) {  
    return sqrt((a - x) * (a - x) + (b - y) * (b - y));
}

double gcd(double a, double b) {
    if(fabs(b) < 1e-2) return a;
    if(fabs(a) < 1e-2) return b;
    return gcd(b, fmod(a, b));    
}

int32_t main() {
	setup();
	double a, b, c, d, e, f;
	input(a, b, c, d, e, f);
	double x = dist(a, b, c, d), y = dist(c, d, e, f), z = dist(e, f, a, b);
	double t = (x + y + z) / 2;
	double k = sqrt(t * (t - x) * (t - y) * (t - z));
	double r = x * y * z / (4 * k);
	double p = acos(1 - (x * x) / (2 * r * r)), q = acos(1 - (y * y) / (2 * r * r)), s = acos(1 - (z * z) / (2 * r * r));
	s = 2 * acos(-1.0) - p - q;
	t = gcd(s, gcd(p, q));
	printf("%.6lf", (acos(-1.0) * r * r * sin(t)) / t);
}
