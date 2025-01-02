#include <bits/stdc++.h>
using namespace std;

struct Player {
    int level;
    string name;
    Player(int l, string n): level(l), name(n) {}
    bool operator<(const Player& p) const {
        return name < p.name;
    }
};
int p, m, l;
string n;
vector<vector<Player>> room;
vector<int> le;

void create(int l, string n) {
    vector<Player> temp = {{l, n}};
    room.push_back(temp);
    le.push_back(l);
}

bool enter(int l, string n) {
    for (int i = 0; i < room.size(); i++) {
        if (room[i].size() == m) continue;
        
        int diff = le[i] - l;
        if (diff < -10 || diff > 10) continue;
        room[i].push_back({l, n});
        return true;
    }
    return false;
}

void output() {
    for (auto &r: room) {
        if (r.size() < m) cout << "Waiting!\n";
        else cout << "Started!\n";
        
        sort(r.begin(), r.end());
        for (auto &p: r) {
            cout << p.level << ' ' << p.name << '\n';
        }
    }
}

int main() {
    cin >> p >> m;
    for (int i = 0; i < p; i++) {
        cin >> l >> n;
        if (room.size() == 0) {
            create(l, n);
        }
        else if (!enter(l, n)) {
            create(l, n);
        }
    }
    output();
}