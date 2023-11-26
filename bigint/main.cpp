#include <iostream>

#include "bigint.h"
#include "biguint.h"

using namespace std;

void check_result(const BigUint& actual, const BigUint& expected) {
    if (actual == expected) {
        cout << "PASS: ";
    } else {
        cout << "FAIL: actual = " << actual << " expected = " << expected << " ";
    }
}

void check_operator_result(const BigUint& n1, const BigUint& n2, 
    const BigUint& actual, const BigUint& expected, const string& s) {
    check_result(actual, expected);
    cout << n1 << " " << s << " " << n2 << " = " << actual << endl;
}

void test_size(const string& a, const int expected) {
    BigUint n1(a);
    check_result(a.size(), expected);
    cout << " size of " << n1 << " = " << a.size() << endl;
}

void test_add(const string& a, const string& b, const string& expected) {
    BigUint n1(a);
    BigUint n2(b);
    BigUint e(expected);
    check_operator_result(n1, n2, n1+n2, e, "+");
    BigUint product = n1;
    product += n2;
    check_operator_result(n1, n2, product, e, "+");
}

void test_subtraction(const string& a, const string& b, const string& expected) {
    BigUint n1(a);
    BigUint n2(b);
    BigUint e(expected);
    check_operator_result(n1, n2, n1-n2, e, "-");
    BigUint product = n1;
    product -= n2;
    check_operator_result(n1, n2, product, e, "-");
}

void test_multiply(const string& a, const string& b, const string& expected) {
    BigUint n1(a);
    BigUint n2(b);
    BigUint e(expected);
    check_operator_result(n1, n2, n1*n2, e, "*");
    BigUint product = n1;
    product *= n2;
    check_operator_result(n1, n2, product, e, "*");
}

void test_division(const string& a, const string& b, const string& expected) {
    BigUint n1(a);
    BigUint n2(b);
    BigUint e(expected);
    check_operator_result(n1, n2, n1/n2, e, "/");
    BigUint quotation = n1;
    quotation /= n2;
    check_operator_result(n1, n2, quotation, e, "/");
}

int main() {
    BigUint a("1119"), b("22234"), e(9812340);

    cout << "=========Testing size=================" << endl;
    test_size("0", 0);
    test_size("2345", 4);
    test_size("012345", 6);
    test_size("02311223412345", 14);
    cout << "======================================" << endl << endl;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "e = " << e << endl;
    cout << "a == b " << (a == b) << endl;
    cout << "a > b " << (a > b) << endl;
    cout << "a < b " << (a < b) << endl;
    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;

    cout << "=========Testing add==================" << endl;
    test_add("20", "0", "20");
    test_add("1", "301", "302");
    test_add("3", "5", "8");
    test_add("3", "2", "5");
    test_add("6", "3", "9");
    test_add("9000", "300", "9300");
    test_add("894567", "2311", "896878");
    test_add("894567983718299491823", "239994567888998889988", "1134562551607298381811");
    cout << "======================================" << endl << endl;

    cout << "=========Testing subtraction==========" << endl;
    test_subtraction("20", "0", "20");
    test_subtraction("1", "301", "0");
    test_subtraction("3", "5", "0");
    test_subtraction("3", "2", "1");
    test_subtraction("6", "3", "3");
    test_subtraction("9000", "300", "8700");
    test_subtraction("894567", "2311", "892256");
    test_subtraction("894567983718299491823", "239994567888998889988", "654573415829300601835");
    cout << "======================================" << endl << endl;

    cout << "=========Testing multiply============" << endl;
    test_multiply("20", "0", "0");
    test_multiply("1", "301", "301");
    test_multiply("3", "5", "15");
    test_multiply("3", "2", "6");
    test_multiply("6", "3", "18");
    test_multiply("9000", "300", "2700000");
    test_multiply("894567", "2311", "2067344337");
    test_multiply("894567983718299491823", "23", "20575063625520888311929");
    test_multiply("894567983718299491823", "2367899345566777", "2118246943211552589309421187011964471");
    cout << "======================================" << endl << endl;
    
    cout << "=========Testing division===========" << endl;
    test_division("3", "5", "0");
    test_division("3", "2", "1");
    test_division("6", "3", "2");
    test_division("9000", "300", "30");
    test_division("894567", "2311", "387");
    test_division("894567983718299491823", "23", "38894260161665195296");
    cout << "======================================" << endl << endl;

    cout << "a >> 1 = " << (a >> 1) << endl;
    cout << "a >> 3 = " << (a >> 3) << endl;
    cout << "a >> 100 = " << (a >> 100) << endl;
    cout << "a >> 0 = " << (a >> 0) << endl;
    cout << "a >> -1 = " << (a >> -1) << endl;
    cout << "a << 1 = " << (a << 1) << endl;
    cout << "a << 3 = " << (a << 3) << endl;
    cout << "a << 12 = " << (a << 12) << endl;
    cout << "a << 100 = " << (a << 100) << endl;
    cout << "a << 0 = " << (a << 0) << endl;
    cout << "a << -1 = " << (a << -1) << endl;
    cout << "a * b = " << a * b << endl;
    cout << BigUint(21) << " * " << BigUint(323) << " = " << BigUint(21) * BigUint(323) << endl;
   
    BigInt c("34"), d("-33"), f(-24);

    cout << "c = " << c << endl;
    cout << "d = " << d << endl;
    cout << "f = " << f << endl;
    cout << "c == d " << (c == d) << endl;
    cout << "c < d " << (c < d) << endl;
    cout << "c > d " << (c > d) << endl;
    cout << "c + d " << (c + d) << endl;
    cout << "c * d " << (c * d) << endl;
}