CFLAGS += -I/opt/ros/foxy/include
LDFLAGS += -L/opt/ros/foxy/lib -lrcl -lrmw -lrcutils \
	-lrosidl_typesupport_c \
	-lrosidl_typesupport_introspection_c \
	-lfastcdr -lfastrtps -lrmw_fastrtps_cpp \

all: object exe

object:
	gcc -c main.c $(CFLAGS) -o main.o 
exe: object
	gcc main.o $(LDFLAGS) -o main.out 
strace: exe
	strace -o log.txt ./main.out
clean:
	rm -f main.o main.out log.txt
