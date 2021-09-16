#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) printf("%d\n", x);
#define println(...) printf(__VA_ARGS__); printf("\n");
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}

bool compare(pair<int, int> &a, pair<int, int> &b) {
    return a.first < b.first;
}

int find_subset(int l, int u, int w[], int n, int result[]) {
    pair<int, int> a[n];
    range(i, 0, n) {
        a[i] = make_pair(w[i], i);
    }

    sort(a, a + n, compare);
    int prefSum[n + 1];
    prefSum[0] = 0;
    range(i, 0, n) {
        prefSum[i + 1] = prefSum[i] + a[i].first;
    }

    range(s, 1, n) {
        if ((prefSum[s] >= l || (prefSum[n] - prefSum[n - s]) >= l) &&
            (prefSum[s] <= u || (prefSum[n] - prefSum[n - s]) <= u)) {
            range(i, 0, n - s) {
                int sum = prefSum[i + s] - prefSum[i];
                if (sum >= l && sum <= u) {
                    range(j, 0, s) {
                        result[j] = a[j + 1].second;
                    }
                    return s;
                }
            }
        }
    }
    return 0;
}

int main() {
    input(int, n);
    input(int, l);
    input(int, u);
    arrput(int, w, n);

    int result[200000];

    int size = find_subset(l, u, w, n, result);
    print(size);
    range(i, 0, size) {
        printf("%d ", result[i]);
    }
}