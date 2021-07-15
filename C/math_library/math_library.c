#include <math.h>
#include <stdio.h>
#include <stdlib.h> // contains maths functions abs and div

int main(int argc, char *argv[])
{

    // some math functions have alternatives for different return types

    // constants
    printf("e = %f\n", M_E);
    printf("log_2 e = %f\n", M_LOG2E);
    printf("log_10 e = %f\n", M_LOG10E);
    printf("ln 2 = %f\n", M_LN2);
    printf("ln 10 = %f\n", M_LN10);
    printf("pi = %f\n", M_PI);
    printf("pi/2 = %f\n", M_PI_2);
    printf("pi/4 = %f\n", M_PI_4);
    printf("1/pi = %f\n", M_1_PI);
    printf("2/pi = %f\n", M_2_PI);
    printf("2/sqrt(pi) = %f\n", M_2_SQRTPI);
    printf("sqrt(2) = %f\n", M_SQRT2);
    printf("1/sqrt(2) = sqrt(1/2) = %f\n\n", M_SQRT1_2);

    // absolute value
    int int_abs_value = abs(-9); // has alternatives for long and long long types
    printf("|-9| = %d\n", int_abs_value);

    float float_abs_value = fabs(-9.81);
    printf("|-9.81| = %f\n\n", float_abs_value);

    // rounding
    printf("Round 4.5 = %f\n", round(4.5));
    printf("Ceil 3.2 = %f\n", ceil(3.2));
    printf("Floor 5.9 = %f\n\n", floor(5.9));

    // division
    div_t division_result = div(27, 4); // has alternatives for long and long long types
    printf("27 /4 = %d remainder %d\n", division_result.quot, division_result.rem);

    printf("53.3 %% 7 = %f\n\n", fmod(53.3, 7));

    // exponents
    printf("e^8 = %f\n", exp(8));
    printf("2^8 = %f\n", pow(2, 8));
    printf("21.02^1.34 = %f\n\n", pow(21.02, 1.34));

    // square and cube root
    printf("sqrt(64) = %f\n", sqrt(64));
    printf("cbrt(125) = %f\n\n", cbrt(125));

    // logarithms
    printf("log_e 2 = %f\n", log(2));
    printf("log_10 2 = %f\n", log10(2));
    printf("log_2 2 = %f\n\n", log2(2));

    // trigonometry
    printf("sin((4 * pi) / 7) = %f\n", sin((4 * M_PI) / 7));
    printf("cos(pi / 6) = %f\n", cos(M_PI / 6));
    printf("tan(0.4) = %f\n", tan(0.4));
    printf("arcsin(4 / 7) = %f\n",  asin(4.0f / 7.0f));
    printf("arccos(34.7 / 54.1) = %f\n",  acos(34.7 / 54.1));
    printf("arctan(0.4) = %f\n",  atan(0.4));

    return 0;
}
