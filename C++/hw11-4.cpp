#include<iostream>
#include<cstdlib>
#include<iomanip>
using namespace std;
enum week{sun,mon,tue,wed,thu,fri,sat};
int main()
{
    char cChiName[][10] = {"星期日","星期一","星期二","星期三","星期四","星期五","星期六"};
    char cEngName[][10] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    cout<< "英文       中文    "<<endl;
    for(int i = sat;i >=sun;i--)
    {
        cout<<setiosflags(ios::left);
        cout<<setw(10)<<cEngName[i]<<" "<<cChiName[i]<<endl;
    }
}