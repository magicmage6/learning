from PIL import Image
from PIL import ImageFilter
im = Image.open('example.jpg')

im.show()

print(im.format, im.size, im.mode)

# thumnail
size = (128, 128)
im.thumbnail(size)

im.show()

im.save('thumbnail.jpg', 'JPEG')

# rotating
rotated = im.rotate(45)
rotated.save('rotated.jpg', 'JPEG')

rotated.show()

# transpose
transposed = im.transpose(Image.FLIP_TOP_BOTTOM)
transposed.save('upsidedown.jpg', 'JPEG')

transposed.show()

#filter
detail = im.filter(ImageFilter.DETAIL)
detail.save('detail.jpg', 'JPEG')

detail.show()

#black and white
black_white = im.convert('L')
black_white.save('black_white.jpg', 'JPEG')

black_white.show()