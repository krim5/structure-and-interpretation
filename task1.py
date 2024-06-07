# НАПИШИТЕ ИТЕРАТИВНЫЙ АЛГОРИТМ
# ДЛЯ АЛГОРИТМА 
# ПОСЛЕДОВАТЕЛЬНОГО 
# ВОЗВЕДЕНИЯ В КВАДРАТ

def sq_iter(b, n, count):
    if n == 0:
        return count 
    if n % 2 == 0:
        return sq_iter(b, n/2, sq_iter(b, n/2, count))
    else:
        return sq_iter(b, n-1, count * b)


def squaring(b, n):
    return sq_iter(b, n, 1)


print(squaring(2, 6))