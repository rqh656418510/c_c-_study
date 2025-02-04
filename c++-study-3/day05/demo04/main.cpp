/**
 * 虚函数、静态绑定和动态绑定
 *
 * <p> 静态绑定（不使用虚函数）
 */

#include <iostream>
#include <typeinfo>

using namespace std;

class Base {

public:
    Base(int data = 10) : ma(data) {

    }

    // 普通函数（非虚函数）
    void show() {
        cout << "Base::show()" << endl;
    }

    // 普通函数（非虚函数）
    void show(int a) {
        cout << "Base::show(int a)" << endl;
    }

private:
    int ma;

};

class Device : public Base {

public:
    Device(int data = 20) : Base(data), mb(data) {

    }

    void show() {
        cout << "Device::show()" << endl;
    }

private:
    int mb;

};

int main() {
    Device device(50);

    Base *pb = &device;
    pb->show();           // 静态（编译时期）绑定（函数的调用）

    cout << sizeof(Base) << endl;
    cout << sizeof(Device) << endl;

    cout << typeid(pb).name() << endl;      // class Base *
    cout << typeid(*pb).name() << endl;     // class Base

    return 0;
}
