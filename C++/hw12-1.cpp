#include <iostream>
#include <cstdlib>//提供rand功能
#include <ctime>//能夠抓取現在時間
using namespace std;

class Cmouse 
{
//私有變數
    private:
    int ix, iy;//位置
    int iStatus;//mouse status
    char cIcon;//顯示圖示
    char cMicon[2];//mouse 兩種圖示
//公開變數
public:
    Cmouse()//建構子 初始化老鼠
    {
        ix = rand() % 10 + 1;//rand起始位置
        iy = rand() % 10 + 1;
        iStatus = 1;
        cIcon = cMicon[0] = '@';
        cMicon[1] = 'Q';
    }

    void Show()
    {
        cout << "老鼠出現在位置 (" << ix << ", " << iy << ")，圖示: " << cIcon << endl;
    }

    int GetStatus()
    {
        return iStatus;
    }

    int update(char input) {
        switch (input) {
        case 'w': iy--; break;
        case 's': iy++; break;
        case 'a': ix--; break;
        case 'd': ix++; break;
        case 'x': iStatus = 0; break;
        default: break;
        }

        if (ix <= 0 || iy <= 0 || ix > 20 || iy > 20) iStatus = 0;//檢查是否超出邊界
        return iStatus;
    }
};

int main() {
    srand(time(0));//利用當下時間作為亂數的參數
    char cIn;
    int iStatus;

    for (int i = 0; i < 10; ++i) {
        cout << "第 " << i + 1 << " 隻老鼠登場!" << endl;
        Cmouse mouseX;//宣告類別的變數名稱
        mouseX.Show();
        iStatus = mouseX.GetStatus();

        while (iStatus != 0) {
            cout << "輸入指令 (w/a/s/d 移動，x 結束): ";
            cin >> cIn;  // 需按 Enter
            iStatus = mouseX.update(cIn);
            if (iStatus)
                mouseX.Show();
            else
                cout << "老鼠已經死亡，第 " << i + 1 << " 隻老鼠遊戲結束" << endl;
        }
    }

    cout << "所有老鼠都已死亡，遊戲結束。" << endl;
    return 0;
}