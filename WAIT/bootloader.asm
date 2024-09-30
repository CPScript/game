BITS 16
ORG 0x7C00

start:
    ; Set video mode to 320x200 256-color (Mode 13h)
    mov ax, 0x0013
    int 0x10

    ; Jump to the kernel
    jmp 0x0000:0x7E00

times 510-($-$$) db 0
dw 0xAA55
