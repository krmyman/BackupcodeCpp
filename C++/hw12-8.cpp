#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class CGuessing {
private:
    int computerChoice; // 0=剪刀, 1=石頭, 2=布
    int playerWinCount;
    int computerWinCount;

public:
    CGuessing() {
        playerWinCount = 0;
        computerWinCount = 0;
        srand(time(0));
    }

    void Generate() {
        computerChoice = rand() % 3; // 0~2
    }

    int Judge(int userChoice) {
        // 0=剪刀, 1=石頭, 2=布
        if (userChoice == computerChoice) {
            cout << "平手！" << endl;
        }
        else if ((userChoice == 0 && computerChoice == 2) || 
                 (userChoice == 1 && computerChoice == 0) || 
                 (userChoice == 2 && computerChoice == 1)) {
            cout << "你贏了！" << endl;
            playerWinCount++;
        } else {
            cout << "電腦贏了！" << endl;
            computerWinCount++;
        }

        if (computerWinCount >= 3) return 1;
        if (playerWinCount >= 3) return -1;
        return 0;
    }

    void Show() {
        string names[] = {"剪刀", "石頭", "布"};
        cout << "電腦出拳: " << names[computerChoice] << endl;
        cout << "目前比分 - 玩家: " << playerWinCount << " | 電腦: " << computerWinCount << endl;
    }
};
int main() {
    CGuessing game;
    int userInput;
    int result;

    cout << "歡迎來玩剪刀石頭布遊戲！輸入 0=剪刀, 1=石頭, 2=布" << endl;

    do {
        cout << "你的出拳 (0=剪刀, 1=石頭, 2=布): ";
        cin >> userInput;

        if (userInput < 0 || userInput > 2) {
            cout << "請輸入有效數字（0～2）！" << endl;
            continue;
        }

        game.Generate();
        result = game.Judge(userInput);
        game.Show();

    } while (result == 0);

    if (result == 1) cout << "電腦勝利，遊戲結束！" << endl;
    else cout << "玩家勝利，恭喜你！" << endl;

    return 0;
}