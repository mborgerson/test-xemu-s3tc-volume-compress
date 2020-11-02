#!/bin/bash -e
gcc -o decompress -DSTANDALONE=1 main.c
for i in *.bmp; do
	convert $i.dds -depth 8 $i.rgba
done
cat *.rgba > expected

./decompress ./compressed ./decompressed
for i in $(seq 0 7); do
	dd if=decompressed of=decompressed_$i.rgba bs=16K count=1 skip=$i
	dd if=expected of=expected_$i.rgba bs=16K count=1 skip=$i
	convert -depth 8 -size 64x64 decompressed_$i.rgba decompressed_$i.bmp
	convert -depth 8 -size 64x64 expected_$i.rgba expected_$i.bmp
done
