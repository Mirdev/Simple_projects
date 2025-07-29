import numpy as np
import matplotlib.pyplot as plt

fig, ax = plt.subplots()

for i, x in enumerate(np.linspace(0.0, 2*np.pi, 200)):
    z = np.exp(x*1j)
    t = 1j*z
    theta = np.linspace(0, x, 200)
    circle = np.exp(1j * theta)

    ax.cla()
    ax.set_xticks([-1,0,1])
    ax.set_yticks([-1, 0, 1])
    ax.set_xlim(-1.5, 1.5)
    ax.set_ylim(-1.5, 1.5)
    ax.set_aspect('equal')

    ax.plot([-1.5, 1.5], [0, 0], color='black', linewidth=1)
    ax.plot([0, 0], [-1.5, 1.5], color='black', linewidth=1)

    ax.annotate('', xy=(z.real, z.imag), xytext=(0, 0), arrowprops=dict(facecolor='blue', edgecolor='blue', arrowstyle='->', linewidth=2, shrinkA=0, shrinkB=0))
    ax.plot(z.real, z.imag, 'ro')
    ax.plot(circle.real, circle.imag, 'black', linestyle='-')
    ax.annotate('', xy=(z.real+t.real, z.imag+t.imag), xytext=(z.real, z.imag), arrowprops=dict(facecolor='green', edgecolor='green', arrowstyle='->', linewidth=2, shrinkA=0, shrinkB=0))
    plt.savefig(f'./figures/{i}.png')
