# РАЦИОНАЛЬНЫЕ ЧИСЛА

def make_rat(a, b):
    return [a, b]


def add_rat(x, y):
    return make_rat((x[0] * y[1]) + (y[0] * x[1]), x[1] * y[1])


x = make_rat(5, 3)
y = make_rat(2, 8)
print(add_rat(x, y))