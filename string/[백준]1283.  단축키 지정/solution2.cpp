#include <bits/stdc++.h>
using namespace std;
int n;
string menu;
bool key[26];
inline int lower(char c) {
    if (c >= 'a') return c - 'a';
    return c - 'A';
}

int main() {
    cin >> n;
    cin.ignore();
    for (int t = 0; t < n; t++) {
        getline(cin, menu);
        bool assigned = false;
        int l = menu.size();
        for (int i = 0; i < l; i++) {
            if (i != 0 && menu[i - 1] != ' ') continue;

            int c = lower(menu[i]);
            if (!key[c]) {
                key[c] = true;
                menu.insert(i, "[");
                menu.insert(i + 2, "]");
                cout << menu << '\n';
                assigned = true;
                break;
            }
        }

        if (assigned) continue;

        for (int i = 0; i < l; i++) {
            if (menu[i] == ' ' || key[lower(menu[i])]) continue;

            key[lower(menu[i])] = true;
            menu.insert(i, "[");
            menu.insert(i + 2, "]");
            break;
        }
        cout << menu << '\n';
    }
}