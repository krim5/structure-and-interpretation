# МОДЕЛИРОВАНИЕ НАСОСА

def main_fun(f1, f2):
    def sub_fun(q, h, ro, p, p_n=None):
        if p_n is None:
            return f1(q, h, ro, p)
        else:
            return f2(q, h, ro, p, p_n, f1)
    return sub_fun


def ef(q, h, ro, p):
    return (9.81 * ro * q * h) / (p * 1000)


def pN(q, h, ro, p, p_n, f1):
    print("pN")
    return (9.81 * ro * q * h) / (p_n * 1000 * f1(q, h, ro, p))

sub_fun = main_fun(ef, pN)
print(sub_fun(13, 14, 2, 4, 15))