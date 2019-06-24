# This is python version of Numerical_Integrator.cpp.
# This just can numerical integrate of x^x from 0 to 1
# scipy result is (0.7834305107121343, 3.351485755587191e-11)

def f(x):
    return x ** x

n = 10000000
step = 1/n

#rectangular
tot = lx = 0
for i in range(n):
    tot += f(lx)*step
    lx += step
print(tot)

#trapezoidal
tot = lx = 0
for i in range(n):
    tot += (f(lx)+f(lx+step))*step/2
    lx += step
print(tot)

#simpson
tot = lx = 0
tot = f(0)+f(1)
for i in range(1, n, 2):
    tot += 4 * f(i * step)
for i in range(2, n-1, 2):
    tot += 2 * f(i * step)
tot = tot * step / 3
print(tot)
