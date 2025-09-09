CC = gcc
CFLAGS = -Wall -Wextra -O2
LDFLAGS = -lraylib -lm -lpthread -ldl -lrt -lX11

TARGET = warehouse
SOURCES = main.c storage.c operator.c
OBJECTS = $(SOURCES:.c=.o)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: clean run
