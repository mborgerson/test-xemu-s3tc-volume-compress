#!/usr/bin/env python3

WIDTH=64
HEIGHT=64
DEPTH=8
data=[open('d%04d.bmp.dxt1' % i, 'rb').read() for i in range(DEPTH)]

BLOCK_SIZE=4
BLOCK_WIDTH=WIDTH//BLOCK_SIZE
BLOCK_HEIGHT=HEIGHT//BLOCK_SIZE
BLOCK_DEPTH=DEPTH//4

def get_unswizzled_block(x, y, z):
	block_idx = y * BLOCK_WIDTH + x
	block_size = 8
	offset = block_idx * block_size
	return data[z][offset:offset+block_size]

with open('compressed', 'wb') as f:
	for z in range(BLOCK_DEPTH):
		for y in range(BLOCK_HEIGHT):
			for x in range(BLOCK_WIDTH):
				z_min = z * BLOCK_SIZE
				z_max = min(z_min+BLOCK_SIZE, DEPTH)
				for z_loc in range(z_min, z_max):
					f.write(get_unswizzled_block(x, y, z_loc))
