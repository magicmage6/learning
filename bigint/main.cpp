#include <iostream>

#include "bigint.h"
#include "biguint.h"

using namespace std;

template<class T>
void base_check(const T& actual, const T& expected) {
    if (actual == expected) {
        cout << "PASS: ";
    } else {
        cout << "FAIL: actual = " << actual << " expected = " << expected << " ";
    }
}

void check_result(const int actual, const int expected) {
    base_check<int>(actual, expected);
}

void check_result(const bool actual, const bool expected) {
    base_check<bool>(actual, expected);
}

void check_result(const BigUint& actual, const BigUint& expected) {
    base_check<BigUint>(actual, expected);
}

void check_operator_result(const BigUint& n1, const BigUint& n2, 
    const BigUint& actual, const BigUint& expected, const string& s) {
    check_result(actual, expected);
    cout << n1 << " " << s << " " << n2 << " = " << actual << endl;
}

void test_constructor(const string& s, const BigUint expected) {
    BigUint n1(s);
    check_result(n1, expected);
    cout << " BitUint(" << n1 << ") = " << n1 << endl;
}

void test_size(const string& a, const int expected) {
    BigUint n1(a);
    check_result(n1.size(), expected);
    cout << " size of " << n1 << " = " << n1.size() << endl;
}

void test_equal(const string& a, const string &b, const bool expected) {
    BigUint n1(a);
    BigUint n2(b);
    check_result((n1 == n2), expected);
    cout << " " << n1 << " == " << n2 << " " << (n1 == n2) << endl;
}

void test_less(const string& a, const string &b, const bool expected) {
    BigUint n1(a);
    BigUint n2(b);
    check_result((n1 < n2), expected);
    cout << " " << n1 << " < " << n2 << " " << (n1 < n2) << endl;
}

void test_greater(const string& a, const string &b, const bool expected) {
    BigUint n1(a);
    BigUint n2(b);
    check_result((n1 > n2), expected);
    cout << " " << n1 << " > " << n2 << " " << (n1 > n2) << endl;
}

void test_left_shift(const string& a, const int i, const string& expected) {
    BigUint n(a);
    BigUint e(expected);
    check_result(n << i, e);
    cout << " " << n << " << " << i << " = " << (n << i) << endl;
}

void test_right_shift(const string& a, const int i, const string& expected) {
    BigUint n(a);
    BigUint e(expected);
    check_result(n >> i, e);
    cout << " " << n << " >> " << i << " = " << (n >> i) << endl;
}

void test_add(const string& a, const string& b, const string& expected) {
    BigUint n1(a);
    BigUint n2(b);
    BigUint e(expected);
    check_operator_result(n1, n2, n1+n2, e, "+");
    BigUint sum = n1;
    sum += n2;
    check_operator_result(n1, n2, sum, e, "+");
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

void test_big_uint() {
    cout << "=========Testing constructor==========" << endl;
    test_constructor("0", BigUint(0));
    test_constructor("0233445", BigUint(233445));
    test_constructor("34510", BigUint(34510));
    test_constructor("023145555", BigUint(23145555));
    cout << "======================================" << endl << endl;

    cout << "=========Testing size=================" << endl;
    test_size("0", 0);
    test_size("2345", 4);
    test_size("012345", 5);
    test_size("01234500", 7);
    test_size("02311223412345", 13);
    cout << "======================================" << endl << endl;

    cout << "=========Testing equal=================" << endl;
    test_equal("0", "0", true);
    test_equal("0", "1", false);
    test_equal("12", "21", false);
    test_equal("012345", "12345", true);
    test_equal("123", "223", false);
    cout << "======================================" << endl << endl;

    cout << "=========Testing less=================" << endl;
    test_less("0", "0", false);
    test_less("0", "1", true);
    test_less("12", "21", true);
    test_less("32", "111", true);
    test_less("111", "32", false);
    test_less("134", "223", true);
    cout << "======================================" << endl << endl;

    cout << "=========Testing greater==============" << endl;
    test_greater("0", "0", false);
    test_greater("0", "1", false);
    test_greater("9", "1", true);
    test_greater("12", "21", false);
    test_greater("32", "111", false);
    test_greater("111", "32", true);
    test_greater("134", "223", false);
    cout << "======================================" << endl << endl;

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

    cout << "=========Testing left shift===========" << endl;
    test_left_shift("34521213", 1, "345212130");
    test_left_shift("34521213", 0, "34521213");
    test_left_shift("34521213", -1, "34521213");
    test_left_shift("34521213", 5, "3452121300000");
    test_left_shift("34521213", 12, "34521213000000000000");
    cout << "======================================" << endl << endl;

    cout << "=========Testing right shift===========" << endl;
    test_right_shift("34521213", 1, "3452121");
    test_right_shift("34521213", 0, "34521213");
    test_right_shift("34521213", -1, "34521213");
    test_right_shift("34521213", 5, "345");
    test_right_shift("34521213", 12, "0");
    cout << "======================================" << endl << endl;
}

void check_big_int_result(const BigInt& actual, const BigInt& expected) {
    base_check<BigInt>(actual, expected);
}

void test_int_constructor(const string& s, const BigInt expected) {
    BigInt n1(s);
    check_big_int_result(n1, expected);
    cout << " BitInt(" << n1 << ") = " << n1 << endl;
}

void test_int_compare(const string& a, const string &b, const int expected) {
    BigInt n1(a);
    BigInt n2(b);
    check_result(n1.compare(n2), expected);
    cout << " " << n1 << ".compare(" << n2 << ") = " << n1.compare(n2) << endl;
}

void test_int_equal(const string& a, const string &b, const bool expected) {
    BigInt n1(a);
    BigInt n2(b);
    check_result((n1 == n2), expected);
    cout << " " << n1 << " == " << n2 << " " << (n1 == n2) << endl;
}

void test_int_less(const string& a, const string &b, const bool expected) {
    BigInt n1(a);
    BigInt n2(b);
    check_result((n1 < n2), expected);
    cout << " " << n1 << " < " << n2 << " " << (n1 < n2) << endl;
}

void test_int_greater(const string& a, const string &b, const bool expected) {
    BigInt n1(a);
    BigInt n2(b);
    check_result((n1 > n2), expected);
    cout << " " << n1 << " > " << n2 << " " << (n1 > n2) << endl;
}

void check_big_int_operator_result(const BigInt& n1, const BigInt& n2, 
    const BigInt& actual, const BigInt& expected, const string& s) {
    check_big_int_result(actual, expected);
    cout << n1 << " " << s << " " << n2 << " = " << actual << endl;
}

void test_int_add(const string& a, const string& b, const string& expected) {
    BigInt n1(a);
    BigInt n2(b);
    BigInt e(expected);
    check_big_int_operator_result(n1, n2, n1+n2, e, "+");
    BigInt sum = n1;
    sum += n2;
    check_big_int_operator_result(n1, n2, sum, e, "+");
}

void test_int_multiply(const string& a, const string& b, const string& expected) {
    BigInt n1(a);
    BigInt n2(b);
    BigInt e(expected);
    check_big_int_operator_result(n1, n2, n1*n2, e, "*");
    BigInt product = n1;
    product *= n2;
    check_big_int_operator_result(n1, n2, product, e, "*");
}

void test_int_division(const string& a, const string& b, const string& expected) {
    BigInt n1(a);
    BigInt n2(b);
    BigInt e(expected);
    check_big_int_operator_result(n1, n2, n1/n2, e, "/");
    BigInt quotation = n1;
    quotation /= n2;
    check_big_int_operator_result(n1, n2, quotation, e, "/");
}

void test_big_int() {
    cout << "=========Testing int constructor======" << endl;
    test_int_constructor("0", BigInt(0));
    test_int_constructor("0233445", BigInt(233445));
    test_int_constructor("-0233445", BigInt(-233445));
    test_int_constructor("34510", BigInt(34510));
    test_int_constructor("-34510", BigInt(-34510));
    test_int_constructor("023145555", BigInt(23145555));
    test_int_constructor("-023145555", BigInt(-23145555));
    cout << "======================================" << endl << endl;

    cout << "=========Testing int compare======" << endl;
    test_int_compare("23", "21", 1);
    test_int_compare("21", "23", -1);
    test_int_compare("21", "21", 0);
    test_int_compare("0", "0", 0);
    test_int_compare("-23", "-21", -1);
    test_int_compare("-21", "-23", 1);
    test_int_compare("-21", "-21", 0);
    test_int_compare("-23", "21", -1);
    test_int_compare("21", "-23", 1);
    cout << "======================================" << endl << endl;

    cout << "=========Testing int equal============" << endl;
    test_int_equal("0", "0", true);
    test_int_equal("0", "1", false);
    test_int_equal("12", "21", false);
    test_int_equal("012345", "12345", true);
    test_int_equal("123", "223", false);
    test_int_equal("0", "-1", false);
    test_int_equal("12", "-21", false);
    test_int_equal("012345", "-12345", false);
    test_int_equal("-012345", "-12345", true);
    test_int_equal("-123", "223", false);
    cout << "======================================" << endl << endl;

    cout << "=========Testing int less=============" << endl;
    test_int_less("0", "0", false);
    test_int_less("0", "1", true);
    test_int_less("12", "21", true);
    test_int_less("32", "111", true);
    test_int_less("111", "32", false);
    test_int_less("134", "223", true);
    test_int_less("0", "-1", false);
    test_int_less("12", "-21", false);
    test_int_less("-32", "111", true);
    test_int_less("-111", "32", true);
    test_int_less("134", "-223", false);
    test_int_less("-134", "-223", false);
    test_int_less("-223", "-134", true);
    cout << "======================================" << endl << endl;

    cout << "=========Testing int greater==========" << endl;
    test_int_greater("0", "0", false);
    test_int_greater("0", "1", false);
    test_int_greater("9", "1", true);
    test_int_greater("12", "21", false);
    test_int_greater("32", "111", false);
    test_int_greater("111", "32", true);
    test_int_greater("134", "223", false);
    test_int_greater("0", "-1", true);
    test_int_greater("-9", "1", false);
    test_int_greater("12", "-21", true);
    test_int_greater("-32", "111", false);
    test_int_greater("-111", "32", false);
    test_int_greater("-134", "-223", true);
    test_int_greater("-223", "-134", false);
    cout << "======================================" << endl << endl;

    cout << "=========Testing add==================" << endl;
    test_int_add("20", "0", "20");
    test_int_add("1", "301", "302");
    test_int_add("3", "5", "8");
    test_int_add("3", "2", "5");
    test_int_add("6", "3", "9");
    test_int_add("9000", "300", "9300");
    test_int_add("894567", "2311", "896878");
    test_int_add("894567983718299491823", "239994567888998889988", "1134562551607298381811");
    test_int_add("1", "-20", "-19");
    test_int_add("22", "-20", "2");
    test_int_add("22", "-22", "0");
    test_int_add("-1", "301", "300");
    test_int_add("-303", "301", "-2");
    test_int_add("-303", "303", "0");
    test_int_add("-3", "-5", "-8");
    cout << "======================================" << endl << endl;

    cout << "=========Testing int multiply=========" << endl;
    test_int_multiply("20", "0", "0");
    test_int_multiply("1", "301", "301");
    test_int_multiply("3", "5", "15");
    test_int_multiply("3", "2", "6");
    test_int_multiply("6", "3", "18");
    test_int_multiply("9000", "300", "2700000");
    test_int_multiply("894567", "2311", "2067344337");
    test_int_multiply("894567983718299491823", "23", "20575063625520888311929");
    test_int_multiply("894567983718299491823", "2367899345566777", "2118246943211552589309421187011964471");
    test_int_multiply("6", "-3", "-18");
    test_int_multiply("-6", "3", "-18");
    test_int_multiply("-6", "-3", "18");
    test_int_multiply("-6", "0", "0");
    cout << "======================================" << endl << endl;

    cout << "=========Testing int division=========" << endl;
    test_int_division("3", "5", "0");
    test_int_division("3", "2", "1");
    test_int_division("6", "3", "2");
    test_int_division("9000", "300", "30");
    test_int_division("894567", "2311", "387");
    test_int_division("894567983718299491823", "23", "38894260161665195296");
    test_int_division("-6", "3", "-2");
    test_int_division("6", "-3", "-2");
    test_int_division("-6", "-3", "2");
    test_int_division("0", "-3", "0");
    cout << "======================================" << endl << endl;
}

int main() {
    test_big_uint();
    test_big_int();
}