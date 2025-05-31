#include <iostream>
#include <cstdlib>  // for rand()
#include <ctime>    // for time()

class CVector {
private:
    float* m_pV2d;  // 指向2個float的動態陣列

public:
    // 預設建構子
    CVector() {
        m_pV2d = new float[2];
        m_pV2d[0] = 0;
        m_pV2d[1] = 0;
    }

    // 兩參數建構子
    CVector(float x, float y) {
        m_pV2d = new float[2];
        m_pV2d[0] = x;
        m_pV2d[1] = y;
    }

    // 複製建構子
    CVector(const CVector& other) {
        m_pV2d = new float[2];
        m_pV2d[0] = other.m_pV2d[0];
        m_pV2d[1] = other.m_pV2d[1];
    }

    // 解構子：釋放記憶體
    ~CVector() {
        delete[] m_pV2d;
    }

    // Set：設定為隨機值 0~1
    void Set() {
        m_pV2d[0] = static_cast<float>(rand()) / RAND_MAX;
        m_pV2d[1] = static_cast<float>(rand()) / RAND_MAX;
    }

    // Show：印出座標
    void Show() const {
        std::cout << "(" << m_pV2d[0] << ", " << m_pV2d[1] << ")" << std::endl;
    }
};
int main() {
    srand(static_cast<unsigned int>(time(0)));  // 初始化亂數種子

    CVector v1, v2(1, 3), v3(v1), * pVx;

    v1.Show();
    v2.Show();

    pVx = new CVector[10];
    for (int i = 0; i < 10; i++) {
        (pVx + i)->Set();
        (pVx + i)->Show();
    }

    delete[] pVx;  // 釋放記憶體
    return 0;
}