#define VIDEO_MEMORY 0xA0000
#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 200

void draw_pixel(int x, int y, unsigned char color) {
    unsigned char *video = (unsigned char *)VIDEO_MEMORY;
    video[y * SCREEN_WIDTH + x] = color;
}

void main() {
    // Clear screen with black color
    for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
        ((unsigned char *)VIDEO_MEMORY)[i] = 0;
    }

    // Draw a white pixel
    draw_pixel(160, 100, 15);

    // Infinite loop
    while (1) {}
}
