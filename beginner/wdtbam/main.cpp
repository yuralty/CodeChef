#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

void playRound() {
    int n;
    std::vector<char> question;
    std::vector<char> answer;
    std::vector<int> win;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        question.push_back(c);
    }

    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        answer.push_back(c);
    }

    for (int i = 0; i <= n; ++i) {
        int w;
        cin >> w;
        win.push_back(w);
    }

    int correct = 0;
    for (int i = 0; i < n; ++i) {
        correct += (question[i] == answer[i]);
    }

    if (correct == n) 
    {
        cout << win[n] << endl;
        return;
    }

    int max = -1;
    for (int i = 0; i <= correct; ++i) {
        if (win[i] > max) max = win[i];
    }

    cout << max << endl;
}

int main(void)
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        playRound();
    }
    return 0;
}
