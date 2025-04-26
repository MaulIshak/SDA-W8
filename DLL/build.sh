CC=gcc

# Compile the C files
$CC -o main.exe main.c linked_list/linked_list.c kota.c warga.c

if [ $? = 0 ]; then
    echo "Compilation successful."
    ./main.exe
else
    echo "Compilation failed."
    exit 1
fi