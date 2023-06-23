.PHONY: static, dynamic, objectstatic, objectdynamic, clnstatic, clndynamic
CC = gcc
# /opt/trendchip/buildroot-gcc493_glibc222_arm32_32bServer/usr/bin/arm-buildroot-linux-gnueabi-gcc
AR = /opt/trendchip/buildroot-gcc493_glibc222_arm32_32bServer/usr/bin/arm-buildroot-linux-gnueabi-gcc-ar

static:
	$(AR) rcs lib/static_lib/libstatic.a obj/static/hung.o obj/static/sum.o
	$(CC) obj/static/main.o -Llib/static_lib -lstatic -o obj/statically-linked

dynamic:
	$(CC) -shared obj/dynamic/hung.o obj/dynamic/sum.o -o lib/dynamic_lib/libshared.so
	$(CC) obj/dynamic/main.o -Llib/dynamic_lib -lshared -o obj/use-shared-library

objectstatic:
	$(CC) -c main.c -o obj/static/main.o -I./inc
	$(CC) -c src/hung.c -o obj/static/hung.o -I./inc
	$(CC) -c src/sum.c -o obj/static/sum.o -I.inc

objectdynamic:
	$(CC) -c -fPIC main.c -o obj/dynamic/main.o -I./inc
	$(CC) -c -fPIC src/hung.c -o obj/dynamic/hung.o -I./inc
	$(CC) -c -fPIC src/sum.c -o obj/dynamic/sum.o -I.inc

clnstatic:
	rm -rf obj/static/* obj/statically-linked lib/static_lib/*

clndynamic:
	rm -rf obj/dynamic/* obj/use-shared-library lib/dynamic_lib/*
