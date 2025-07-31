import numpy as np
import matplotlib.pyplot as plt

t = np.linspace(0, 2 * np.pi, 1000)

# real
sin_actual = np.sin(t)
cos_actual = np.cos(t)
e_actual = np.exp(1j * t)

# Maclaurin
def maclaurin_sin(t, order):
    result = np.zeros_like(t)
    for n in range(order + 1):
        if 2*n + 1 > order:
            break
        result += ((-1)**n * t**(2*n + 1)) / np.math.factorial(2*n + 1)
    return result

def maclaurin_cos(t, order):
    result = np.zeros_like(t)
    for n in range(order + 1):
        if 2*n > order:
            break
        result += ((-1)**n * t**(2*n)) / np.math.factorial(2*n)
    return result

def maclaurin_eit(t, order):
    result = np.zeros_like(t, dtype=complex)
    for n in range(order + 1):
        result += (1j * t) ** n / np.math.factorial(n)
    return result

# Orders
orders = range(21)

fig, axs = plt.subplots(len(orders), 3, figsize=(12, 4 * len(orders)))

for idx, order in enumerate(orders):
    sin_approx = maclaurin_sin(t, order)
    cos_approx = maclaurin_cos(t, order)
    e_approx = maclaurin_eit(t, order)

    # sin(t)
    axs[idx, 0].plot(t, sin_actual, label='$ \sin \ t $', color='black', linewidth=1)
    axs[idx, 0].plot(t, sin_approx, label=f'Order {order}', linestyle='-', linewidth=2)
    #axs[idx, 0].set_title(f'$ \sin \ t $ - Order {order}')
    axs[idx, 0].grid(True)
    axs[idx, 0].legend(loc='upper center', ncol=2, bbox_to_anchor=(0.5, 1.21))
    axs[idx, 0].set_xlim(0, 2*np.pi)
    axs[idx, 0].set_ylim(-np.pi, np.pi)
    axs[idx, 0].set_aspect('equal')

    # cos(t)
    axs[idx, 1].plot(cos_actual, t, label='$ \cos \ t$', color='black', linewidth=1)
    axs[idx, 1].plot(cos_approx, t, label=f'Order {order}', linestyle='-', linewidth=2)
    #axs[idx, 1].set_title(f'$ \cos \ t$ - Order {order}', pad=30)
    axs[idx, 1].set_title(' ', pad=30)
    axs[idx, 1].grid(True)
    axs[idx, 1].legend(loc='upper center', ncol=2, bbox_to_anchor=(0.5, 1.21))
    axs[idx, 1].set_xlim(-np.pi, np.pi)
    axs[idx, 1].set_ylim(0, 2*np.pi)
    axs[idx, 1].set_aspect('equal')

    # e^{it}
    axs[idx, 2].plot(e_actual.real, e_actual.imag, label='$e^{it}$', color='black', linewidth=1)
    axs[idx, 2].plot(e_approx.real, e_approx.imag, label=f'Order {order}', linestyle='-', linewidth=2)
    #axs[idx, 2].set_title(f'$e^{{it}}$ in Complex Plane - Order {order}')
    axs[idx, 2].set_aspect('equal')
    axs[idx, 2].grid(True)
    axs[idx, 2].legend(loc='upper center', ncol=2, bbox_to_anchor=(0.5, 1.21))
    axs[idx, 2].set_xlim(-3, 3)
    axs[idx, 2].set_ylim(-3, 3)
    axs[idx, 2].set_aspect('equal')

plt.tight_layout()
plt.show()
