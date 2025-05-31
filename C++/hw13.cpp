#include <iostream>
#include <cmath>
using namespace std;

class CVector {
private:
    float m_fx, m_fy;       // 向量分量
    float m_fNorm;          // 向量長度（norm）

public:
    // 預設建構子
    CVector() {
        m_fx = 0;
        m_fy = 0;
        m_fNorm = Dist();   // 計算本身的向量長度
    }

    // 一個參數建構子
    CVector(float x) {
        m_fx = x;
        m_fy = x;
        m_fNorm = Dist();
    }

    // 兩個參數建構子
    CVector(float x, float y) {
        m_fx = x;
        m_fy = y;
        m_fNorm = Dist();
    }

    // 拷貝建構子
    CVector(const CVector &v) {
        m_fx = v.m_fx;
        m_fy = v.m_fy;
        m_fNorm = Dist();
    }

    // 顯示向量內容
    void Show() {
        cout << "(" << m_fx << ", " << m_fy << ")" << endl;
    }

    // 計算並回傳本身向量長度
    float Dist() {
        return sqrt(m_fx * m_fx + m_fy * m_fy);//平方根
    }

    // 顯示本身向量長度
    void ShowNorm() {
        cout << "向量長度: " << m_fNorm << endl;
    }

    // 計算本身與另一個向量的距離
    float Dist(const CVector &v) {
        float dx = m_fx - v.m_fx;
        float dy = m_fy - v.m_fy;
        return sqrt(dx * dx + dy * dy);
    }
};

int main() {
    CVector v1;           // 預設 (0, 0)
    CVector v2(1);        // (1, 1)
    CVector v3(1, 3);     // (1, 3)
    CVector v4 = v2;      // 拷貝 v2

    // 顯示每個向量內容與長度
    v1.Show(); v1.ShowNorm();
    v2.Show(); v2.ShowNorm();
    v3.Show(); v3.ShowNorm();
    v4.Show(); v4.ShowNorm();

    // 額外測試：v3 與 v2 之間的距離
    cout << "v3 到 v2 的距離: " << v3.Dist(v2) << endl;

    return 0;
}