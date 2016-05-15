CC = g++

ARCH = $(shell getconf LONG_BIT)
ifeq ($(ARCH), 32)
  LIBPATH = ../../lib
else
  LIBPATH = ../../lib64
endif

CFLAGS = -I ../../include_cpp -L $(LIBPATH) -lxl -Wl,-rpath,$(LIBPATH)

all: write read edit custom format invoice performance

write: write.cpp
	$(CC) -o write write.cpp $(CFLAGS)

read: read.cpp
	$(CC) -o read read.cpp $(CFLAGS)

edit: edit.cpp
	$(CC) -o edit edit.cpp $(CFLAGS)

custom: custom.cpp
	$(CC) -o custom custom.cpp $(CFLAGS)

format: format.cpp
	$(CC) -o format format.cpp $(CFLAGS)

invoice: invoice.cpp
	$(CC) -o invoice invoice.cpp $(CFLAGS)

performance: performance.cpp
	$(CC) -o performance performance.cpp $(CFLAGS)

clean:
	rm -f write read edit custom format invoice performance *.xls *.xlsx

