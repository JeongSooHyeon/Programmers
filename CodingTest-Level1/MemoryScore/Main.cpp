#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string, int> score;
    for (int i = 0; i < name.size(); i++) {
        score.insert(pair<string, int>(name[i], yearning[i]));
    }

    for (int i = 0; i < photo.size(); i++) {    // 사진 몇장
        int result = 0;
        for (int j = 0; j < photo[i].size(); j++) { // 사진 당 사람 수
            result += score[photo[i][j]];
        }
        answer.push_back(result);
    }

    return answer;
}