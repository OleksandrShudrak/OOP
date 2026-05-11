#include "Dyhotomia_class.h"
#include <cmath>
#include <iostream>

using namespace std;

Dyhotomia_class::Dyhotomia_class() {}
Dyhotomia_class::~Dyhotomia_class() {}

double Dyhotomia_class::Func(double x){
    if (x <= 0) {
        cout << "Error: x <= 0" << endl;
        return NAN;
    }
    return 0.1 * pow(x, 2) - 5 * x * log(x) - 1;
}

void Dyhotomia_class::setVolums(double temp_a, double temp_b){
    this->a = temp_a;
    this->b = temp_b;
}
    
void Dyhotomia_class::setTolerance(double eps){
    this->eps = eps;
}

double Dyhotomia_class::pohidna(double x){
    double f1 = Func(x + eps);
    double f2 = Func(x);
    if (isnan(f1) || isnan(f2)) return NAN;
    return (f1 - f2) / eps;
}

double Dyhotomia_class::Newtonmet(){
    double x = this->b;
    double dx = eps + 1;
    int max_iter = 1000;
    int iter = 0;

    while(abs(dx) > eps && iter < max_iter){
        double f_x = Func(x);
        double f_prime = pohidna(x);

        if (isnan(f_x) || isnan(f_prime) || abs(f_prime) < 1e-12) {
            return NAN;
        }

        dx = f_x / f_prime;

        x -= dx;
        iter++;
    }
   
    return x;
}

double Dyhotomia_class::Dyhotomia(){
    double a_local = this->a;
    double b_local = this->b;
    double fa = Func(a_local);
    double fb = Func(b_local);

    if(isnan(fa) || isnan(fb) || fa * fb > 0){
        return NAN;
    }

    double c = (b_local + a_local) / 2;
    while((b_local - a_local) > eps){
        double fc = Func(c);
        if (isnan(fc)) return NAN;

        if (fa * fc > 0) {
            a_local = c;
            fa = fc;
        } else {
            b_local = c;
            fb = fc;
        }
        c = (b_local + a_local) / 2;
    }

    return c;
}