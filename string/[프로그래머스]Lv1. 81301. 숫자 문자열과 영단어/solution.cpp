#include <vector>
#include <regex>

using namespace std; 

// regex 이용한 풀이 (속도 느림)
#include <string>
int solution(string s) {
    vector<string> v= {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    for (int i = 0; i < 10; i++) {
        regex re(v[i]);
        // regex re = v[i] (x)
        // regex re = regex(v[i]) (o)
        s = regex_replace(s, re, to_string(i));
    }
    return stoi(s);
}

// 첫 풀이 (속도 빠름)
int solution(string s) {
    string answer = "";
    while (s.length() != 0) {
        if (s[0] == 'z') {
            answer += '0';
            s = s.substr(4);
        }
        else if (s[0] == 'o') {
            answer += '1';
            s = s.substr(3);
        }
        else if (s[0] == 't') {
            if (s[1] == 'w') {
                answer += '2';
                s = s.substr(3);
            }
            else {
                answer += '3';
                s = s.substr(5);
            }
        }
        else if (s[0] == 'f') {
            if (s[1] == 'o') {
                answer += '4';
                s = s.substr(4);
            }
            else {
                answer += '5';
                s = s.substr(4);
            }
        }
        else if (s[0] == 's') {
            if (s[1] == 'i') {
                answer += '6';
                s = s.substr(3);
            }
            else {
                answer += '7';
                s = s.substr(5);
            }
        }
        else if (s[0] == 'e') {
            answer += '8';
            s = s.substr(5);
        }
        else if (s[0] == 'n') {
            answer += '9';
            s = s.substr(4);
        }
        else {
            answer += s[0];
            s = s.substr(1);
        }
    }
    return stoi(answer);
}