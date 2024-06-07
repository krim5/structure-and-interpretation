# Рациональные числа, три функции превратить в одну
from math import gcd

# (define (make-rat n d)
#     (cons n d))
# (define (numer x)
#     (let ((g (gcd (car x) (cdr x))))
#         (/ (car x) g)))
# (define (denom x)
#     (let ((g (gcd (car x) (cdr x))))
#         (/ (cdr x) g)))




# def make_rat(n, d):
    
#     g = gcd(n, d)

#     n_simp = n // g
#     d_simp = d // g
    
#     return (n_simp, d_simp)

# rat = make_rat(4, 8)
# numer, denom = rat
# print(f"Numerator: {numer}, Denominator: {denom}")
# print(f"{numer}/{denom}")



def rat_func(n, d):

    def get_rat():
        return (n, d)

    def numer_simp():
        g = gcd(n, d)
        return n // g

    def denom_simp():
        g = gcd(n, d)
        return d // g

    return (get_rat, numer_simp, denom_simp)

rat = rat_func(4, 8)
print(f"Rat: {rat[0]()}\nNumerator: {rat[1]()}, Denominator: {rat[2]()}")