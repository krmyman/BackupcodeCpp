#include<iostream>
#include<iomanip>
using namespace std;
void printstart1(int n, int m)
{
    char p = '*';
    if (n == 0)
    {
        cout.width(7);//將索引位置定在七
        cout << p << endl;
    }
    else
    {
        if (m == 1)
        {
            cout<<setw(7-n);//遞減索引的起始位置
            for (int i = 0;i < n;i++)
            {
                cout << p;
            }
        }
        else if (m == 2)
        {
            cout<<" ";
            for (int i = 0;i < n;i++)
            {
                cout << p;
            }
            cout << endl;
        }
    }
}
int main()
{
    int m = 1;
    for (int i = 0;i < 7;i++)
    {
        if (i == 0)
            printstart1(i, m);//呼叫函式
        else
        {
            //呼叫函式並區分第一次呼叫還是第二次呼叫
            m = 1;
            printstart1(i, m);
            m = 2;
            printstart1(i, m);
        }

    }
}