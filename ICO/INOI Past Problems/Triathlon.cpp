#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << x << endl;
#define println(...) printf(__VA_ARGS__); printf("\n");
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);

struct Player {
    int a, b, c;
};

bool compare(Player x, Player y) {
    return (x.b + x.c) > (y.b + y.c);
}

int main() {
    setup();
    
    //Input
    input(int, n);
    Player players[n];
    range(i, 0, n) {
        cin >> players[i].a >> players[i].b >> players[i].c;
    }

    //Sort the array on basis of reverse of 
    //sum of pole vault and dougnut eating timings
    sort(players, players + n, compare);

    //Return the maximum timing
    long long cobolTime = 0;
    long long res = 0;
    for (Player player: players) {
        cobolTime += player.a;
        res = max(res, cobolTime + player.b + player.c);
    }
    print(res);
}