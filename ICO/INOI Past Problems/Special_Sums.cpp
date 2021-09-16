#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << x << endl;
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);

int n;
vector<long long> a, b, prefSum;

int main() {
    setup();
    cin >> n;
    a = vector<long long>(n);
    b = vector<long long>(n);
    prefSum = vector<long long>(n + 1);
    range(i, 0, n) {
        cin >> a[i];
    }
    range(i, 0, n) {
        cin >> b[i];
    }
    
    prefSum[0] = 0;
    range(i, 0, n) {
        prefSum[i + 1] = prefSum[i] + b[i];
    }

    long long res = numeric_limits<long long>::min();

    //Solve for i = j
    for (long long i: a) {
        res = max(res, i);
    }

    //Solve for i < j
    long long dp[n];
    dp[0] = a[0];
    range(i, 1, n) {
        dp[i] = max(a[i], dp[i - 1] + b[i]);
    }
    range(i, 1, n) {
        res = max(res, dp[i - 1] + a[i]);
    }

    //Solve for i > j
    long long dpf[n], dpb[n];
    dpf[0] = a[0];
    range(i, 1, n - 1) {
        dpf[i] = max(dpf[i - 1], prefSum[i] + a[i]);
    }
    dpb[n - 1] = a[n - 1];
    for (int i = n - 2; i > 0; i--) {
        dpb[i] = max(dpb[i + 1], prefSum[n] - prefSum[i + 1] + a[i]);
    }
    range(i, 1, n) {
        res = max(res, dpf[i - 1] + dpb[i]);
    }

    print(res);
}