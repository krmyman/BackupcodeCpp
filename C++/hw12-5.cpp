#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class CSongList 
{
private:
    vector<string> songs; // 儲存歌曲清單

public:
    void AddSong(string song) 
    {
        songs.push_back(song);
        cout << "已新增歌曲: " << song << endl;
    }

    void ShowSongs() 
    {
        if (songs.empty()) 
        {
            cout << "目前沒有任何歌曲。" << endl;
            return;
        }

        cout << "歌曲清單如下：" << endl;
        for (size_t i = 0; i < songs.size(); ++i) 
        {
            cout << i + 1 << ". " << songs[i] << endl;
        }
    }

    void Sorting() 
    {
        sort(songs.begin(), songs.end());
        cout << "歌曲已排序完畢（按名稱）" << endl;
    }

    void SelectSong(int index) 
    {
        if (index <= 0 || index > songs.size()) 
        {
            cout << "無效的選擇。" << endl;
        } else 
        {
            cout << "你點播的歌曲是：「" << songs[index - 1] << "」" << endl;
        }
    }
};
int main() 
{
    CSongList myPlayer;
    myPlayer.AddSong("Lemon - 米津玄師");
    myPlayer.AddSong("夜に駆ける - YOASOBI");
    myPlayer.AddSong("Pretender - Official髭男dism");

    myPlayer.ShowSongs();

    myPlayer.Sorting();
    myPlayer.ShowSongs();

    int choice;
    cout << "請輸入你要點播的歌曲編號：";
    cin >> choice;
    myPlayer.SelectSong(choice);

    return 0;
}