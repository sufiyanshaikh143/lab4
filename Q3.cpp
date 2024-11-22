#include <iostream>
#include <iomanip>
using namespace std;

void print_real(float number, int fieldspace, int precision) {
    cout << fixed << setw(fieldspace) << setprecision(precision) << number << endl;
}

template <typename T>
void update_scale(T &m1, T &m2, T m3 = 10) {
    T original_m1 = m1;
    T original_m2 = m2;

    m1 = (original_m1 + original_m2) * m3; 
    m2 = (original_m1 - original_m2) * m3; 
}

int main() {
    float a = 5.5, b = 2.5;

    cout << "Initial values of a and b:\n";
    print_real(a, 10, 2); 
    print_real(b, 10, 2); 

    update_scale(a, b);

    cout << "\nUpdated values of a and b:\n";
    print_real(a, 10, 2);
    print_real(b, 10, 2);

    return 0;
}
