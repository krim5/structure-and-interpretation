#include <iostream>

class EfficiencyFunction {
public:
    virtual double calculate(double q, double h, double ro, double p) const {
        return (9.81 * ro * q * h) / (p * 1000);
    }
};

class PNFunction : public EfficiencyFunction {
public:
    double calculate(double q, double h, double ro, double p, double p_n, const EfficiencyFunction& ef) const {
        std::cout << "PNFunction" << std::endl;
        return (9.81 * ro * q * h) / (p_n * 1000 * ef.calculate(q, h, ro, p));
    }
};

class PumpModel {
private:
    const EfficiencyFunction& f1;
    const PNFunction& f2;

public:
    PumpModel(const EfficiencyFunction& f1, const PNFunction& f2) : f1(f1), f2(f2) {}

    double calculate(double q, double h, double ro, double p, double p_n = -1) const {
        if (p_n == -1) {
            return f1.calculate(q, h, ro, p);
        }
        else {
            return f2.calculate(q, h, ro, p, p_n, f1);
        }
    }
};

int main() {
    EfficiencyFunction ef;
    PNFunction pn;
    PumpModel pumpModel(ef, pn);

    double result = pumpModel.calculate(12, 12, 3, 5, 12);
    std::cout << result << std::endl;

    return 0;
}