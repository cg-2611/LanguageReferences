#include <cmath>
#include <iostream>

int main(int argc, char const *argv[])
{
    // some math functions have alternatives for different return types

    // constants
    std::cout << "e = " << M_E << std::endl;
    std::cout << "log_2 e = " << M_LOG2E << std::endl;
    std::cout << "log_10 e = " << M_LOG10E << std::endl;
    std::cout << "ln 2 = " << M_LN2 << std::endl;
    std::cout << "ln 10 = " << M_LN10 << std::endl;
    std::cout << "pi = " << M_PI << std::endl;
    std::cout << "pi/2 = " << M_PI_2 << std::endl;
    std::cout << "pi/4 = " << M_PI_4 << std::endl;
    std::cout << "1/pi = " << M_1_PI << std::endl;
    std::cout << "2/pi = " << M_2_PI << std::endl;
    std::cout << "2/sqrt(pi) = " << M_2_SQRTPI << std::endl;
    std::cout << "sqrt(2) = " << M_SQRT2 << std::endl;
    std::cout << "1/sqrt(2) = sqrt(1/2) = \n" << M_SQRT1_2 << std::endl;

    // absolute value
    int int_abs_value = abs(-9); // has alternatives for long and long long types
    std::cout << "|-9| = " << int_abs_value << std::endl;

    float float_abs_value = fabs(-9.81);
    std::cout << "|-9.81| " << float_abs_value << "\n" << std::endl;

    // rounding
    std::cout << "Round 4.5 = " << round(4.5) << std::endl;
    std::cout << "Ceil 3.2 = " << ceil(3.2) << std::endl;
    std::cout << "Floor 5.9 = " << floor(5.9) << std::endl;

    // division
    div_t division_result = div(27, 4); // has alternatives for long and long long types
    std::cout << "27 /4 = " << division_result.quot << " remainder " << division_result.rem << std::endl;

    std::cout << "53.3 %% 7 = " << fmod(53.3, 7) << std::endl;

    // exponents
    std::cout << "e^8 = " << exp(8) << std::endl;
    std::cout << "2^8 = " << pow(2, 8) << std::endl;
    std::cout << "21.02^1.34 = " << pow(21.02, 1.34) << "\n" << std::endl;

    // square and cube root
    std::cout << "sqrt(64) = " << sqrt(64) << std::endl;
    std::cout << "cbrt(125) = " << cbrt(125) << std::endl;

    // logarithms
    std::cout << "log_e 2 = " << log(2) << std::endl;
    std::cout << "log_10 2 = " << log10(2) << std::endl;
    std::cout << "log_2 2 = " << log2(2) << "\n" << std::endl;

    // trigonometry
    std::cout << "sin((4 * pi) / 7) = " << sin((4 * M_PI) / 7) << std::endl;
    std::cout << "cos(pi / 6) = " << cos(M_PI / 6) << std::endl;
    std::cout << "tan(0.4) = " << tan(0.4) << std::endl;
    std::cout << "arcsin(4 / 7) = " <<  asin(4.0f / 7.0f) << std::endl;
    std::cout << "arccos(34.7 / 54.1) = " <<  acos(34.7 / 54.1) << std::endl;
    std::cout << "arctan(0.4) = " <<  atan(0.4) << std::endl;

    return 0;
}
