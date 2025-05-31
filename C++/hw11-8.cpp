#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
int main()
{
    ifstream file("story.txt");
    if (!file)
    {
        cout << "檔案無法開啟" << endl;
        return 0;
    }
    int vowelcount[5] = { 0 };
    int wordcount = 0;
    string word;
    char getch;
    while (file.get(getch))
    {
        if (isalpha(getch))//判斷是否為字母
        {
            switch (tolower(getch))//轉成小寫
            {
            case 'a':vowelcount[0]++;break;
            case 'e':vowelcount[1]++;break;
            case 'i':vowelcount[2]++;break;
            case 'o':vowelcount[3]++;break;
            case 'u':vowelcount[4]++;break;
            default: break;
            }
            word += getch;
        }
        else
        {
            if(!word.empty())//空字串回傳true
            {
                wordcount++;
                word.clear();
            }
        }
    }
    file.close();
    cout << "A的數量:" << vowelcount[0] << endl;
    cout << "E的數量:" << vowelcount[1] << endl;
    cout << "I的數量:" << vowelcount[2] << endl;
    cout << "O的數量:" << vowelcount[3] << endl;
    cout << "U的數量:" << vowelcount[4] << endl;
    cout << "wordcount的數量:" << wordcount << endl;
    return 0;
}