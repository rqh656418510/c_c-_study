/**
 * 类型转换-静态类型
 */

#include <iostream>

using namespace std;

class Father {

public:
    Father(string name, int age) {
        this->m_Name = name;
        this->m_Age = age;
    }

    // 虚函数
    virtual void print() {
        cout << endl << "name = " << this->m_Name << ", age = " << this->m_Age << endl;
    }

protected:
    string m_Name;
    int m_Age;

};

class Son : public Father {

public:
    Son(string name, int age, string hobby) : Father(name, age) {
        this->m_Name = name;
        this->m_Age = age;
        this->m_hobby = hobby;
    }

    void print() override {
        cout << endl << "name = " << this->m_Name << ", age = " << this->m_Age << ", hobby = " << m_hobby << endl;
    }

private:
    string m_hobby;

};

// 基本数据类型的转换
void test01() {
    char a = 'a';
    double d = static_cast<double>(a);
    cout << endl << d << endl;
}

// 继承关系引用互相转换
void test02() {
    Father father("Father", 60);
    Son son("Son", 25, "Game");

    // 上行转换（将派生类的引用转换成基类表示），是安全的
    Father &father1 = static_cast<Father &>(son);
    father1.print();    // 发生多态

    // 下行转换（将基类的引用转换成派生类表示），是不安全的
    Son &son2 = static_cast<Son &>(father);
    son2.print();
}

// 继承关系指针互相转换
void test03() {
    // 上行转换（将派生类的指针转换成基类表示），是安全的
    Son *son1 = new Son("Son", 25, "Game");
    Father *father1 = static_cast<Father *>(son1);
    father1->print();   // 发生多态

    // 下行转换（将基类的指针转换成派生类表示），是不安全的
    Father *father2 = new Father("Father", 60);
    Son *son2 = static_cast<Son *>(father2);
    son2->print();
}

int main() {
    cout << endl << "-------- test01() --------";
    test01();

    cout << endl << "-------- test02() --------";
    test02();

    cout << endl << "-------- test03() --------";
    test03();
    return 0;
}
