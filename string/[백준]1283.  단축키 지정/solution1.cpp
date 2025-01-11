#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> menuList;
set<char> keySet;

int main() {
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string menu;
        getline(cin, menu);
        menuList.push_back(menu);
    }

    for (auto &menu: menuList) {
        bool assigned = false;

        // 단어 단위 처리
        istringstream ss(menu);
        string word, result = menu;
        vector<string> words;

        while (ss >> word) {
            words.push_back(word);
        }

        // 첫 글자로 단축키 지정
        for (auto &word: words) {
            char k = tolower(word[0]);
            if (keySet.find(k) == keySet.end()) {
                keySet.insert(k);
                word = "[" + string(1, word[0]) + "]" + word.substr(1);
                assigned = true;
                break;
            }
        }

        // 단축키를 지정하지 못한 경우, 전체 문자열 탐색
        if (!assigned) {
            for (size_t i = 0; i < menu.size(); i++) {
                char c = menu[i];
                if (c != ' ' && keySet.find(tolower(c)) == keySet.end()) {
                    keySet.insert(tolower(c));
                    menu.insert(i, "[");
                    menu.insert(i + 2, "]");
                    result = menu;
                    break;
                }
            }
        }
        else {
            result.clear();
            for (auto &word: words) {
                if (!result.empty()) result += " ";
                result += word;
            }
        }

        cout << result << '\n';
    }
}