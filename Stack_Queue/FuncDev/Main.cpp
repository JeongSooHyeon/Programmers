#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

// ���� ���� Queue
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    queue<int> q;

    ///////////////// �ٸ� ��� Ǯ�� ////////////////////////////
    // �ɸ��� �Ⱓ queue�� ����
    //for (int i = 0; i< progresses.size(); i++) {
    //    int temp = (100 - progresses[i]) % speeds[i];   // ���ϰ� ������
    //    if (temp == 0) {    // ���� �� �߾�
    //        q.push((100 - progresses[i]) / speeds[i]);
    //    }
    //    else {
    //        q.push((100 - progresses[i]) / speeds[i] + 1);
    //    }
    //}

    //while (!q.empty()) {
    //    int cnt = 1;    // �� ���� ������ �۾� ����
    //    int cur = q.front();    // ���� ���� �۾�
    //    q.pop();

    //    while (cur >= q.front() && !q.empty()) {
    //        q.pop();
    //        cnt++;
    //    }
    //    answer.push_back(cnt);
    //}
    //return answer;















    int n = progresses.size();


    int pred = 0;   // ���� �����ߵ� ���
    int result = 0; 

    for (int i = 0; i < n; i++) {
        q.push(i);  // �۾� ������� �־����
    }

    while(true){
        // �Ϸ� �۾�
        for (int i = 0; i < n; i++) {
            progresses[i] += speeds[i]; // �۾��ϱ�
            if (pred == i && progresses[i] >= 100) { // �۾� �Ϸ�
                pred++; 
                if (q.front() < pred) {
                    q.pop();
                    result++;
                }
            }
        }
        if (result != 0)
            answer.push_back(result);
        result = 0;
        if (pred == n)
            break;
    }

    return answer;
}

int main() {
    //vector<int> progresses = { 93,30,55 };    // �۾� ����
    //vector<int> speeds = { 1,30,5 };        // ���� �ӵ�
    vector<int> progresses = { 93,90,99,99,80,99 };    // �۾� ����
    vector<int> speeds = { 1,1,1,1,1,1 };        // ���� �ӵ�
    vector<int> result = solution(progresses, speeds);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << ' ';

}