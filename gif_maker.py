from PIL import Image
from IPython.display import Image as Img
from IPython.display import display

images = []

for x in range(300):
    path = f'./figures/{x}.png'
    with Image.open(path) as im:
        images.append(im.copy())

images[0].save(
    'res.gif',
    save_all=True,
    append_images=images[1:],
    loop=0xff,
    duration=20
)

display(Img(url='res.gif'))
