def my_factorial_1(n):
    if n == 1:
        return 1
    else:
        return n * my_factorial_1(n - 1)

def my_factorial_2(n):
    def iter(product, counter, max_count):
        if counter > max_count:
            return product
        else:
            return iter(counter * product, counter + 1, max_count)
    return iter(1, 1, n)

from goto import with_goto

def my_factorial_3(n):
    @with_goto
    def iter(product, counter, max_count):
        label .begin
        if counter > max_count:
            return product
        else:
            product = counter * product
            counter = counter + 1
            goto .begin
    return iter(1, 1, n)

def my_factorial_4(n):
    product = 1
    counter = 1
    max_count = n
    while True:
        if counter > max_count:
            return product

        product = counter * product
        counter = counter + 1
