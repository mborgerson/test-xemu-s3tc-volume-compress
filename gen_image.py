from PIL import Image, ImageDraw, ImageFont
 
fnt = ImageFont.truetype('/Library/Fonts/Arial.ttf', 55)

for i in range(8):
	img = Image.new('RGB', (64, 64), color=(255, 0, 0))
	d = ImageDraw.Draw(img)
	d.text((15,0), f'{i}', font=fnt, fill=(255, 255, 255))
	img.save('d%04d.bmp' % i)