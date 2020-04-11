CC := gcc
OBJECTS :=	test.o \
			logic.o \
			circular_buffer.o

INCLUDE_DIR := -Iinclude
CFLAGS :=  $(INCLUDE_DIR) -DTEST
LDFLAGS := -lm


test: $(OBJECTS)
	$(info $(OBJECTS))
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)