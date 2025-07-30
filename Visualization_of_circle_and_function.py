import numpy as np
import matplotlib.pyplot as plt

theta = np.pi/3

x = np.cos(theta)
y = np.sin(theta)

fig, ax = plt.subplots(figsize=(6,6))
ax.set_xlim(-1.2, 1.2)
ax.set_ylim(-1.2, 1.2)
ax.set_aspect('equal')

ax.axhline(0, color='black', linewidth=1)
ax.axvline(0, color='black', linewidth=1)

circle = plt.Circle((0, 0), 1, color='black', fill=False, linestyle='-')
ax.add_artist(circle)

ax.plot([0, x], [0, y], 'r', linewidth=2)

ax.plot([x, x], [0, y], 'b--', linewidth=1)  # sin
ax.plot([0, x], [y, y], 'g--', linewidth=1)  # cos

ax.plot(x, y, 'ro')

arc = np.linspace(0, theta, 100)
arc_x = 0.2 * np.cos(arc)
arc_y = 0.2 * np.sin(arc)
ax.plot(arc_x, arc_y, 'k')

ax.text(0.2, 0.1, r'$x$', fontsize=14)
ax.text(x + 0.05, y/2, r'$\sin\ x$', color='blue', fontsize=12, va='center')
ax.text(x/2, y-0.1, r'$\cos\ x$', color='green', fontsize=12, ha='center')
ax.text(x + 0.05, y + 0.05, r'$e^{ix}$', fontsize=14)

plt.grid(True, linestyle=':', alpha=0.5)
plt.show()
