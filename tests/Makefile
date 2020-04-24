CC := gcc

OBJECTS :=	../src/logic.o \
			../src/linreg.o \
			../src/sampler.o \
			mock/mock_driver.o \
			main.o


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

checkpatch:
	./checkpatch.pl --no-tree -f ../SleepDrip.ino
	for f in ../src/*.cpp ../include/*.h; do ./checkpatch.pl --no-tree --ignore SPDX_LICENSE_TAG --ignore NEW_TYPEDEFS --show-types  -f $$f ;done

valgrind: $(PROJECT_NAME)
	valgrind ./$(PROJECT_NAME)
clean:
	rm -rf $(OBJECTS) $(PROJECT_NAME)

