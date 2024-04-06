/**
 * 成员函数做友元函数
 */

#include <iostream>

using namespace std;

class Building;

class GoodGay {

public:
    GoodGay();

    void visit();

    void play();

private :
    Building *building;

};

class Building {

    // 只让 GoodGay 的成员函数 visit() 作为友元函数
    friend void GoodGay::visit();

public:
    Building();

public:
    string m_SittingRoom;

private:
    string m_BedRoom;
};

GoodGay::GoodGay() {
    this->building = new Building();
}

void GoodGay::visit() {
    cout << "Good friend visiting " << this->building->m_SittingRoom << endl;
    // 这里 GoodGay 的成员函数 visit() 可以访问 Building 的私有成员变量
    cout << "Good friend visiting " << this->building->m_BedRoom << endl;
}

void GoodGay::play() {
    cout << "Good friend playing in " << this->building->m_SittingRoom << endl;
    // 这里 GoodGay 的成员函数 play() 不可以访问 Building 的私有成员变量
    // cout << "Good friend playing in " << this->building->m_BedRoom << endl;
}

Building::Building() {
    this->m_SittingRoom = "sitting room";
    this->m_BedRoom = "bed room";
}

void test01() {
    GoodGay goodGay;
    goodGay.visit();
    goodGay.play();
}

int main() {
    test01();
    return 0;
}
