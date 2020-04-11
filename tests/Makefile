CC := gcc

OBJECTS :=	main.o \
			../src/logic.o \
			../src/circular_buffer.o \
			mock/mock_driver.o

INCLUDE_DIR := 	-I../include \
				-I mock

CFLAGS :=  $(INCLUDE_DIR) -DTEST
LDFLAGS := -lm

PROJECT_NAME := tests

$(PROJECT_NAME): $(OBJECTS)
	$(info $(OBJECTS))
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -rf $(OBJECTS) $(PROJECT_NAME)