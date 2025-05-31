//利用類別抓取當下時間並持續更新
#include <iostream>
#include <cstdlib>//提供rand功能
#include <ctime>//能夠抓取現在時間
#include <thread>   // 提供 sleep_for 所需的 this_thread
#include <chrono>   // 提供時間單位，如 seconds, milliseconds 等
using namespace std;

class CTimer
{
private:
    int hour, min, sec;
    time_t now = time(0);//抓取現在時間
public:
    void SetTime(int h,int m,int s)
    {
        hour = h;
        min = m;
        sec = s;
    }
    int Tick()
    {
        sec++;
        if(sec>=60)
        {
            min++;
            sec=0;
        }
        else if(min>=60)
        {
            hour++;
            min=0;
        }
        else if(hour>=24)
            hour=0;
        return 1;
    }
    void Show()
    {
        cout << (hour < 10 ? "0" : " ") << hour << ":"
            << (min < 10 ? "0" : " ") << min << ":"
            << (sec < 10 ? "0" : " ") << sec << endl;
    }
};
int main() 
{
    time_t now = time(0);//取得當下時間
    tm *ltm = localtime(&now);//轉換成當下當地時間
    CTimer timer;
    timer.SetTime(ltm->tm_hour,ltm->tm_min,ltm->tm_sec);
    while(true)
    {
        timer.Show();
        std::this_thread::sleep_for(std::chrono::seconds(1));//休息1秒
        timer.Tick();
    }
    return 0;
}