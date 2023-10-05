#include <string>
#include <vector>
#include <iostream>
using namespace std;

// n : ���� ����, m : �ѷ� ����
int solution(int n, int m, vector<int> section) {
    int answer = 1; // �ּ� �� ��

    int pivot = section[0];
    for (const auto v : section) {
        if (v < pivot + m) {    // ĥ�� ������ ������
            continue;
        }
        else {  // ������
            pivot = v;  // ������ �ٲٱ�
            answer++;   // �� �� �� ĥ�ϱ�
        }
    }




    //vector<int> walls;
    //int answer = 0; // �ѷ��� ����Ʈĥ�ؾ� �ϴ� �ּ� Ƚ��

    //int idx = 0;    // section�� �ε���
    //int overPaint; // ��ĥ�� �κ�
    //while (idx < section.size()) {
    //    overPaint = section[idx];   // ó�� ��ĥ�� �κ�
    //    overPaint += (m-1); // ��ĥ�ϱ�
    //    answer++;
    //    idx++;
    //    while (idx < section.size() && 
    //        overPaint >= section[idx]) { // ��ĥ �� �� �κ� ã��
    //            idx++;
    //    }
    //}

    return answer;
}

int main() {
    //vector<int> section = { 2,3,6 };
    //vector<int> section = { 1,3 };
    vector<int> section = { 1,2,3,4 };

    cout << solution(4, 1, section);

}