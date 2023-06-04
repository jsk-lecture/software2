def my_sqrt(x):
    y = x
    while True:
        if (y * y) - x < 0.001:
            return y
        y = ( y + x / y ) / 2.0
