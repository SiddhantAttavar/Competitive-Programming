#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << x << endl;
#define println(...) printf(__VA_ARGS__); printf("\n");
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);

int main() {
    setup();

    //Input
    input(int, n);
    input(int, k);
    k--;
    arrput(int, a, n);
    
    //dp1 represents the forward phase
    //dp1[i] = score at forward phase when 
    //starting from k and ending on i
    int dp1[n];
    dp1[k] = 0;
    if ((k + 1) < n) {
        dp1[k + 1] = a[k + 1];
    }
    range(i, k + 2, n) {
        dp1[i] = max(dp1[i - 1], dp1[i - 2]) + a[i];
    }

    //dp2 represents the backward phase
    //dp2[i] = score at backward phase when
    //starting from i and ending on 1
    int dp2[n];
    dp2[0] = 0;
    dp2[1] = a[0];
    range(i, 2, n) {
        dp2[i] = max(dp2[i - 1] + a[i - 1], dp2[i - 2] + a[i - 2]);
    }

    //Find the turning point at which maximum score is obtained
    int res = numeric_limits<int>::min();
    range(i, k, n) {
        res = max(res, dp1[i] + dp2[i]);
    }
    print(res);
}