#include <boost/math/tools/polynomial.hpp>

#include <boost/array.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/assert.hpp>

#include <iostream>
#include <stdexcept>
#include <cmath>
#include <string>
#include <utility>

#include <fstream>

using std::string;
using std::exception;
using std::cout;
using std::abs;
using std::pair;

using namespace boost::math;
using namespace boost::math::tools;
using boost::lexical_cast;

template <typename T>

T gcd_(T a, T b) {
    T null_ptr = { 0 };
    if (b == null_ptr)
        return a;
    return gcd_(b, a % b);
}

template <typename T>
string sign_str(T const& x)
{
    return x < 0 ? "-" : "+";
}

template <typename T>
string inner_coefficient(T const& x)
{
    string result(" " + sign_str(x) + " ");
    if (abs(x) != T(1))
        result += lexical_cast<string>(abs(x));
    return result;
}

template <typename T>
string formula_format(polynomial<T> const& a)
{
    string result;
    if (a.size() == 0)
        result += lexical_cast<string>(T(0));
    else
    {
        unsigned i = a.size() - 1;
        if (a[i] < 0)
            result += "-";
        if (abs(a[i]) != T(1))
            result += lexical_cast<string>(abs(a[i]));

        if (i > 0)
        {
            result += "x";
            if (i > 1)
            {
                if (a[i])
                result += "^" + lexical_cast<string>(i);
                i--;
                for (; i != 1; i--)
                    if (a[i])
                        result += inner_coefficient(a[i]) + "x^" + lexical_cast<string>(i);

                if (a[i])
                 result += inner_coefficient(a[i]) + "x";
            }
            i--;

            if (a[i])
            result += " " + sign_str(a[i]) + " " + lexical_cast<string>(abs(a[i]));
        }
    }
    return result;
}
