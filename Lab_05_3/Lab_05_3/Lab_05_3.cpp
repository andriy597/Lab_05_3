// z(f) = t(f^2) + 2*t(2f + 1) + sqrt(t(1))
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double t(const double x);

int main()
{
    double fp, fk, f, z;
    int n;
    cout << "fp = "; cin >> fp;
    cout << "fk = "; cin >> fk;
    cout << "n = ";  cin >> n;

    double df = (fk - fp) / n;

    cout << fixed;
    cout << "---------------------------------" << endl;
    cout << "|" << setw(10) << "f" << " |"
        << setw(18) << "z(f)" << " |" << endl;
    cout << "---------------------------------" << endl;

    f = fp;
    while (f <= fk)
    {
        z = t(f * f) + 2 * t(2 * f + 1) + sqrt(t(1));
        cout << "|" << setw(10) << setprecision(4) << f << " |"
            << setw(18) << setprecision(8) << z << " |" << endl;
        f += df;
    }
    cout << "---------------------------------" << endl;
    return 0;
}

double t(const double x)
{
    if (fabs(x) >= 1)
        return (cos(x) + 1) / (exp(x) + sin(x) * sin(x));
    else
    {
        int j = 0;
        double a = x; // перший доданок (j = 0)
        double S = a;
        do
        {
            j++;
            double R = -x * x / ((2 * j) * (2 * j + 1)); // коефіцієнт рекурентності
            a *= R;
            S += a;
        } while (j < 5);
        return S;
    }
}