#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) printf("%d\n", x);
#define println(...) printf(__VA_ARGS__); printf("\n");
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}

int main() {
    input(int, n);
    input(int, m);

    array<int, 3> edges[m];
    range(i, 0, m) {
        input(int, u);
        input(int, v);
        input(int, w);
        edges[i] = {u - 1, v - 1, w};
    }

    int distance[n];
    range(i, 0, n) {
        distance[i] = numeric_limits<int>::max();
    }
    distance[0] = 0;

    range(i, 0, n - 1) {
        for (array<int, 3> j: edges) {
            if (distance[j[0]] != numeric_limits<int>::max()) {
                distance[j[1]] = min(distance[j[1]], distance[j[0]] + j[2]);
            }
        }
    }

    range(i, 0, n) {
        println("1 => %d: %d", i + 1, distance[i]);
    }
}