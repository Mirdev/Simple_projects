# Visualizes a regular polygon and highlights its triangulation from fixed vertices.

import numpy as np
import matplotlib.pyplot as plt

n = 4
size = 6

inner_angle = np.pi*(1-2/n)
angles = np.arange(inner_angle/2, 2*np.pi+inner_angle/2+1e-8, 2*np.pi/n)
points = [(np.cos(x+np.pi), np.sin(x+np.pi)) for x in angles[::-1]]
xs, ys = zip(*points)

fig = plt.figure()
fig, axes = plt.subplots(2, n, figsize=(size*n, size*2))
for ax in axes.flat:
    ax.set_aspect('equal')
    ax.axis('off')
    ax.plot(xs, ys)
    
ax_iter = iter(axes.flat)

for k, ax in zip(range(1, n-1), ax_iter):
    triangle_points = [points[x] for x in (0, k, -2)]
    triangle_points.append(triangle_points[0])
    txs, tys = zip(*triangle_points)
    ax.scatter(xs[k], ys[k], color='r')
    ax.plot(txs, tys, color='r')
    
for ax in ax_iter:
    ax.remove()
