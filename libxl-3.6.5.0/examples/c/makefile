CC = gcc

ARCH = $(shell getconf LONG_BIT)
ifeq ($(ARCH), 32)
  LIBPATH = ../../lib
else
  LIBPATH = ../../lib64
endif

CFLAGS = -I ../../include_c -L $(LIBPATH) -lxl -Wl,-rpath,$(LIBPATH)

all: generate extract edit custom format invoice performance

generate: generate.c
	$(CC) -o generate generate.c $(CFLAGS)

extract: extract.c
	$(CC) -o extract extract.c $(CFLAGS)

edit: edit.c
	$(CC) -o edit edit.c $(CFLAGS)

custom: custom.c
	$(CC) -o custom custom.c $(CFLAGS)

format: format.c
	$(CC) -o format format.c $(CFLAGS)

invoice: invoice.c
	$(CC) -o invoice invoice.c $(CFLAGS)

performance: performance.c
	$(CC) -o performance performance.c $(CFLAGS)

clean:
	rm -f generate extract edit custom format invoice performance *.xls *.xlsx

