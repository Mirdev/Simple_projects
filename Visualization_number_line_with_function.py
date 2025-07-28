import matplotlib.pyplot as plt
import numpy as np

fig, ax = plt.subplots(1, 1, figsize=(20, 1))

for i, x in enumerate(np.arange(0.0, 2.0, 0.01)):
    ax.cla()
    ax.plot([0, 15], [0, 0], color='black', linewidth=1)
    ax.set_xlim(-1, 16)
    ax.set_xticks(range(0, 16))
    ax.set_xticklabels(range(0, 16))
    ax.yaxis.set_visible(False)
    ax.spines['top'].set_visible(False)
    ax.spines['right'].set_visible(False)
    ax.spines['left'].set_visible(False)
    ax.annotate('', xy=(np.exp(x), 0), xytext=(0, 0), arrowprops=dict(arrowstyle='->', color='blue', linewidth=2, shrinkA=0, shrinkB=0))
    ax.annotate('', xy=(np.exp(x)+np.exp(x), 0), xytext=(np.exp(x), 0), arrowprops=dict(arrowstyle='->', color='green', linewidth=4, shrinkA=0, shrinkB=0))
    plt.savefig(f'./figures/{i}.png')
