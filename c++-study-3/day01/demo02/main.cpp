#include <iostream>

using namespace std;

int sum(int a, int b) {
    int temp = 0;
    temp = a + b;
    return temp;
}

int main() {
    int a = 10;
    int b = 20;
    int result = sum(a, b);
    cout << "result = " << result << endl;
    return 0;
}