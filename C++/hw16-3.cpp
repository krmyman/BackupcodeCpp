#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// 抽象類別（基底類）
class C2DShape {
public:
    float m_fArea;

    C2DShape() : m_fArea(0.0f) {}

    virtual void Calculate() = 0; // 純虛擬函式
    virtual void Show() = 0;      // 純虛擬函式
    virtual ~C2DShape() {}        // 虛擬解構子（重要）
};

// 派生類別：圓形
class CCircle : public C2DShape {
private:
    float m_fRadius;

public:
    CCircle(float r) : m_fRadius(r) {}

    void Calculate() override {
        m_fArea = static_cast<float>(M_PI) * m_fRadius * m_fRadius;
    }

    void Show() override {
        cout << fixed << setprecision(3);
        cout << "半徑 " << m_fRadius << " 的圓，面積為 " << m_fArea << endl;
    }
};

// 派生類別：矩形
class CRectangle : public C2DShape {
private:
    float m_fLength;
    float m_fWidth;

public:
    CRectangle(float l, float w) : m_fLength(l), m_fWidth(w) {}

    void Calculate() override {
        m_fArea = m_fLength * m_fWidth;
    }

    void Show() override {
        cout << fixed << setprecision(3);
        cout << "寬 " << m_fLength << " 高 " << m_fWidth << " 的矩形，面積為 " << m_fArea << endl;
    }
};

// =======================
// 測試主程式
int main() {
    C2DShape* pShape[3];  // 指標陣列

    // 建立實體
    pShape[0] = new CCircle(4.5f);
    pShape[1] = new CCircle(3.3f);
    pShape[2] = new CRectangle(2.5f, 3.5f);

    // 計算面積
    for (int i = 0; i < 3; i++) {
        pShape[i]->Calculate();
    }

    // 顯示面積
    for (int i = 0; i < 3; i++) {
        pShape[i]->Show();
    }

    // 釋放記憶體
    for (int i = 0; i < 3; i++) {
        delete pShape[i];
    }

    return 0;
}