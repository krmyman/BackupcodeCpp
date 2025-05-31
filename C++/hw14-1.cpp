#include <iostream>

class CVector {
private:
    float m_fx;
    float m_fy;

public:
    // 預設建構函數，m_fx = 0, m_fy = 0
    CVector() : m_fx(0), m_fy(0) {}

    // 兩個參數的建構函數
    CVector(float x, float y) : m_fx(x), m_fy(y) {}

    // 一個參數的建構函數，m_fx = m_fy = val
    CVector(float val) : m_fx(val), m_fy(val) {}

    // operator= 運算子重載，允許 v1 = v2 與 v1 = v2 = v3
    CVector& operator=(const CVector& other) {
        if (this != &other) {
            m_fx = other.m_fx;
            m_fy = other.m_fy;
        }
        return *this;
    }

    // 顯示成員內容（測試用）
    void Print() const {
        std::cout << "(" << m_fx << ", " << m_fy << ")" << std::endl;
    }
};
int main() {
    CVector v1, v2(1, 3), v3(2);  // 預設、兩參、單參建構

    v1 = v2;
    v1.Print();  // (1, 3)

    v1 = v2 = v3;
    v1.Print();  // (2, 2)
    v2.Print();  // (2, 2)

    return 0;
}