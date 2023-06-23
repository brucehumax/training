.PHONY: prep, comp, assem, link, clean, all
CC = /opt/trendchip/buildroot-gcc493_glibc222_arm32_32bServer/usr/bin/arm-buildroot-linux-gnueabi-gcc

prep:
	$(CC) -E main.c -o main.i
comp: 
	$(CC) -S main.i -o main.s
assem: 
	$(CC) -c main.s -o main.o
link: 
	$(CC) -o main_b2 main.o

all:
	$(CC) -o main_b2 main.c
clean:	
	rm -rf main_b2 main.i main.s main.o
