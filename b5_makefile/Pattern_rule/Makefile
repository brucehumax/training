.PHONY: clean
CC = /opt/trendchip/buildroot-gcc493_glibc222_arm32_32bServer/usr/bin/arm-buildroot-linux-gnueabi-gcc

%.o: %.c
	$(CC) -c $< -o $@
clean:
	rm -rf *.o
