# Имя библиотеки
LIB_NAME = list

# Исходные файлы библиотеки
LIB_SOURCES = list.c

# Объектные файлы библиотеки
LIB_OBJECTS = $(LIB_SOURCES:.c=.o)

# Исполняемый файл
EXECUTABLE = main

# Компилятор и флаги
CC = gcc
CFLAGS = -Wall -fPIC

# Правила сборки
all: $(LIB_NAME).so $(EXECUTABLE)

# Создание динамической библиотеки
$(LIB_NAME).so: $(LIB_OBJECTS)
	$(CC) -shared -o $@ $^

# Компиляция объектных файлов для библиотеки
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Компиляция исполняемого файла с подключением библиотеки
$(EXECUTABLE): main.c $(LIB_NAME).so
	$(CC) -o $@ main.c -L. -l$(LIB_NAME)

# Очистка
clean:
	rm -f $(LIB_OBJECTS) $(LIB_NAME).so $(EXECUTABLE)