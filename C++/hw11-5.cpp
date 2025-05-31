#include<iostream>
#include<cstdlib>
using namespace std;
struct CharacterInfo
{
    char name[16];
    float x,y;
    int life;
    void inputAttrib()
    {
        cout << "輸入姓名:";
        cin.getline(name,16);//取16個，不超過陣列上限
        cout<<"輸入x,y座標:";
        cin>>x>>y;
        cout << "輸入生命值:";
        cin >> life;
    }
    void showAttrib()
    {
        cout << "姓名:"<<name<<" x,y座標:"<<x<<" , "<<y<<" 生命值:"<<life<<endl;
    }
}player;

int main()
{
    player.inputAttrib();
    player.showAttrib();
    return 0;
}