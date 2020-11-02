#!/bin/bash -e
python3 gen_image.py

for i in *.bmp;
do
	# Gen DXT1 image
	convert $i $(basename $i).dds

	# Ignore header and levels > 0
	dd if=$(basename $i).dds of=$(basename $i).dxt1 skip=128 bs=1 count=2048
done

python3 swizzle.py
