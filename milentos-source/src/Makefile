GPP = g++
LD = ld

GPP_CFLAGS = -Wall -Wextra -std=c++17 -ffreestanding -fno-exceptions -fno-rtti -m32
LDFLAGS = -m elf_i386 -T linker.ld

KERNEL = kernel.bin

SRCS = $(wildcard *.cpp) $(wildcard */*.cpp)
OBJS = $(SRCS:.cpp=.o)


all: $(KERNEL)

$(KERNEL): $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o $(KERNEL)


%.o: %.cpp
	$(GPP) $(GPP_CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJS) $(KERNEL)

run: all
	qemu-system-i386 -kernel $(KERNEL)
