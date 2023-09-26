#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;

    map<string, int> m; // 선수와 등수 저장
    int s1, s2; // 등수가 바뀔 선수들
    string tmp; // swap을 위한 변수

    for (int i = 0; i < players.size(); i++) {
        m.insert(pair<string, int>(players[i], i));
    }

    for (int i = 0; i < callings.size(); i++)
    {
        s2 = m[callings[i]];
        s1 = s2 - 1;

        m[players[s2]]--; m[players[s1]]++;

        tmp = players[s2];
        players[s2] = players[s1];
        players[s1] = tmp;
    }

    for (int i = 0; i < players.size(); i++)
        answer.push_back(players[i]);

    return answer;
}