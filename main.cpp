#include "polynoms.cpp"


int main()
{
	boost::array<double, 20> a_tmp{}, b_tmp{}, d_tmp{};

	std::fstream in;
	in.open("polynoms.txt", std::ios::in);
	if (!in.is_open())
		exit(1);
	else {
		int i = 0;
		int count = 0;
		std::string line;
		while (std::getline(in, line, '\n')) {
			std::stringstream str_strm;
			str_strm << line;
			if (count == 0) {
				while (!str_strm.eof()) {
					str_strm >> a_tmp[i++];
				}
				count++;
			}
			if (count == 1 && !str_strm.eof()) {
				i = 0;
				while (!str_strm.eof()) {
					str_strm >> b_tmp[i++];
				}
				count++;
			}
			if (count > 1) {
				i = 0;
				while (!str_strm.eof()) {
					str_strm >> d_tmp[i++];
				}
			}
		}
	}


	//boost::array<double, 9> const d3a = { {0, 0, 1, 0, 1, 0, 1, 0, 1} };
	polynomial<double> const a(a_tmp.begin(), a_tmp.end());

	//boost::array<double, 3> const d3b = { {1, 0, 1} };
	polynomial<double> const b(b_tmp.begin(), b_tmp.end());

	//boost::array<double, 15> const d3d = { {0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 1} };
	polynomial<double> const d(d_tmp.begin(), d_tmp.end());

	cout << "Example with ints:\n";
	cout << "equlid(80, 2) = " << gcd_(80, 2) << "\n";
	cout << "equlid(9999, 3) = " << gcd_(9999, 3) << "\n\n";

	cout << "Example with boost/polynomials from polynoms.txt:" << "\n";

	cout << "a = " << formula_format(a)
		<< "\nb = " << formula_format(b) << "\nd = " << formula_format(d) << "\n\n";

	polynomial<double> s = a + b;
	cout << "a + b = " << formula_format(s) << "\n";
	polynomial<double> e = a - b;
	cout << "a - b = " << formula_format(e) << "\n";
	polynomial<double> p = a * b;
	cout << "a * b = " << formula_format(p) << "\n";
	polynomial<double> q = a / b;
	cout << "a / b = " << formula_format(q) << "\n";
	polynomial<double> r = a % b;
	cout << "a % b = " << formula_format(r) << "\n";

	cout << "equlid(a, b) = " << formula_format(gcd_(a, b)) << "\n";
	cout << "equlid(a, d) = " << formula_format(gcd_(a, d)) << "\n";

	cout << "d / equlid(a, d) = " << formula_format(d / (gcd_(a, d))) << "\n";
	cout << "a / equlid(a, d) = " << formula_format(a / (gcd_(a, d))) << "\n";

	pair< polynomial<double>, polynomial<double> > result;
	result = quotient_remainder(a, b);
}

/*Написать с помощью boost/math/tools/polynomial.hpp программу с функционалом polynom_example.exe.
// https://www.boost.org/doc/libs/1_61_0/libs/math/example/polynomial_arithmetic.cpp
// в polynoms.txt записаны a,b,d многочлены*/