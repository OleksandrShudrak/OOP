#ifndef DYHOTOMIA_CLASS
#define DYHOTOMIA_CLASS

class Dyhotomia_class {
public:
    Dyhotomia_class();
    ~Dyhotomia_class();
    void setVolums(double a, double b);
    void setTolerance(double eps);
    double Func(double x);
    double pohidna(double x);
    double Dyhotomia();
    double Newtonmet();
private:
    double a, b, eps;
};

#endif