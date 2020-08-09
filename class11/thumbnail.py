from PIL import Image

im = Image.open('spaceship.png')

im.show()

# thumnail
size = (64, 64)
im.thumbnail(size)

im.show()

im.save('spaceshiphumbnail.png', 'PNG')