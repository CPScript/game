steps:
Assemble the bootloader: `nasm -f bin bootloader.asm -o bootloader.bin`
compile: `i686-elf-gcc -ffreestanding -c kernel.c -o kernel.o`
link: `i686-elf-ld -T linker.ld kernel.o -o kernel.bin --oformat binary`
combine: `cat bootloader.bin kernel.bin > os-image.bin`
