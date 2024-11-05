#include <iostream>
#include <deque>
#include <cstdint>
#include <algorithm>
#include <string>
#include <fstream>
#include <cmath>

std::deque<uint8_t> operator+(const std::deque<uint8_t>& num1, const std::deque<uint8_t>& num2);
std::deque<uint8_t> operator-(const std::deque<uint8_t>& num1, const std::deque<uint8_t>& num2);
bool operator>(const std::deque<uint8_t>& num1, const std::deque<uint8_t>& num2);
bool operator<(const std::deque<uint8_t>& num1, const std::deque<uint8_t>& num2);
bool operator==(const std::deque<uint8_t>& num1, const std::deque<uint8_t>& num2);
bool operator!=(const std::deque<uint8_t>& num1, const std::deque<uint8_t>& num2);
std::ostream& operator<<(std::ostream& out, const std::deque<uint8_t>& num);
std::istream& operator>>(std::istream& in, std::deque<uint8_t>& num);
std::deque<uint8_t> operator*(const std::deque<uint8_t>& num1, const std::deque<uint8_t>& num2);
std::deque<uint8_t> operator*(const std::deque<uint8_t>& num1, int a);
std::deque<uint8_t> operator%(const std::deque<uint8_t>& num1, const std::deque<uint8_t>& num2);
std::deque<uint8_t> part(const std::deque<uint8_t>& num, int begin, int end);
std::deque<uint8_t> str_to_deq(const std::string& str);
std::deque<uint8_t> operator/(const std::deque<uint8_t>& num1, const std::deque<uint8_t>& num2);
std::deque<uint8_t> int_to_deq(const int num);
int deq_to_int(const std::deque<uint8_t>& num);
//(x^y) mod n
std::deque<uint8_t> pow_mod(const std::deque<uint8_t>& x, 
										const std::deque<uint8_t>& y, const std::deque<uint8_t>& n);
std::deque<uint8_t> binary_deq(const std::deque<uint8_t>& n);
std::deque<uint8_t> d_finder(const std::deque<uint8_t>& fn, const std::deque<uint8_t>& e);
//c=(m^e) mod n
std::deque<uint8_t> scrumble(const std::deque<uint8_t>& m, 
										const std::deque<uint8_t>& e, const std::deque<uint8_t>& n);
//m=(c^d) mod n
std::deque<uint8_t> unscrumble(const std::deque<uint8_t>& c, 
										const std::deque<uint8_t>& d, const std::deque<uint8_t>& n);

/*std::deque<uint8_t> scrumble(const std::string message, 
										const std::deque<uint8_t>& e, const std::deque<uint8_t>& n);

std::string unscrumble(const std::deque<uint8_t>& scrumbled_message, 
										const std::deque<uint8_t>& d, const std::deque<uint8_t>& n);*/









