#include<iostream>
using namespace std;
int& max(int& a, int& b) //函數取變數位址，判斷完後直接改變相對應的參照值
{
    return (a > b) ? a : b;
}
int& min(int& a, int& b)
{
    return (a < b) ? b : a;
}
int main()
{
    int a = 10, b = 5;
    max(a, b) = 100;
    min(a, b) = 100;
    cout<<"a = "<<a<<" b = "<<b<<endl;
    return 0;
}