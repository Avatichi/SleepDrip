CC := gcc

OBJECTS :=	../src/logic.o \
			../src/circular_buffer.o \
			../src/linreg.o \
			main.o \
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

run: $(PROJECT_NAME)
	./$(PROJECT_NAME)

clean:
	rm -rf $(OBJECTS) $(PROJECT_NAME)