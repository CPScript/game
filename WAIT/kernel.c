#include <dos.h>  // For delay function
#include <conio.h> // For keyboard input

#define VIDEO_MEMORY 0xA0000
#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 200
#define CUBE_SIZE 40
#define SPHERE_RADIUS 20

unsigned char *video = (unsigned char *)VIDEO_MEMORY;

// Function to draw a pixel on the screen
void draw_pixel(int x, int y, unsigned char color) {
    if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT) {
        video[y * SCREEN_WIDTH + x] = color;
    }
}

// Function to draw a colorful terrain
void draw_terrain() {
    for (int y = 0; y < SCREEN_HEIGHT; y++) {
        for (int x = 0; x < SCREEN_WIDTH; x++) {
            unsigned char color = (x + y) % 256; // Example gradient
            draw_pixel(x, y, color);
        }
    }
}

// Function to draw a reflective cube
void draw_cube(int camera_x, int camera_y) {
    int cube_center_x = SCREEN_WIDTH / 2;
    int cube_center_y = SCREEN_HEIGHT / 2;

    for (int y = -CUBE_SIZE; y <= CUBE_SIZE; y++) {
        for (int x = -CUBE_SIZE; x <= CUBE_SIZE; x++) {
            int pixel_x = cube_center_x + x + camera_x;
            int pixel_y = cube_center_y + y + camera_y;

            unsigned char color = 15; // White for cube
            // Apply simple reflection effect based on position
            color = (pixel_x + pixel_y) % 256;

            draw_pixel(pixel_x, pixel_y, color);
        }
    }
}

// Function to draw a shiny golden sphere
void draw_sphere(int camera_x, int camera_y) {
    int sphere_center_x = SCREEN_WIDTH / 2 + 60;
    int sphere_center_y = SCREEN_HEIGHT / 2;

    for (int y = -SPHERE_RADIUS; y <= SPHERE_RADIUS; y++) {
        for (int x = -SPHERE_RADIUS; x <= SPHERE_RADIUS; x++) {
            if (x * x + y * y <= SPHERE_RADIUS * SPHERE_RADIUS) { // Circle equation
                int pixel_x = sphere_center_x + x + camera_x;
                int pixel_y = sphere_center_y + y + camera_y;
                unsigned char color = 14; // Yellow for the sphere
                draw_pixel(pixel_x, pixel_y, color);
            }
        }
    }
}

// Function to draw a triangle with "Hello World"
void draw_triangle(int camera_x, int camera_y) {
    int triangle_x = SCREEN_WIDTH / 2 - 60;
    int triangle_y = SCREEN_HEIGHT / 2 - 30;

    // Draw the triangle
    draw_pixel(triangle_x, triangle_y, 15); // Top vertex
    draw_pixel(triangle_x + 20, triangle_y + 40, 15); // Bottom right vertex
    draw_pixel(triangle_x - 20, triangle_y + 40, 15); // Bottom left vertex

    // Draw text "Hello World" as simple pixels (not true text rendering)
    char *message = "Hello World";
    for (int i = 0; message[i] != '\0'; i++) {
        draw_pixel(triangle_x + i * 8, triangle_y + 10, 15); // Just as an example
    }
}

// Function to get input from the keyboard
void get_input(int *camera_x, int *camera_y) {
    if (kbhit()) {
        switch (getch()) {
            case 'w': // Move up
                *camera_y -= 2;
                break;
            case 's': // Move down
                *camera_y += 2;
                break;
            case 'a': // Move left
                *camera_x -= 2;
                break;
            case 'd': // Move right
                *camera_x += 2;
                break;
            case 27: // Escape key to exit
                exit(0);
                break;
        }
    }
}

// Main function
void main() {
    int camera_x = 0;
    int camera_y = 0;

    // Clear screen with black color
    for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
        video[i] = 0; // Clear screen to black
    }

    while (1) {
        draw_terrain(); // Draw the colorful terrain
        draw_cube(camera_x, camera_y); // Draw the cube
        draw_sphere(camera_x, camera_y); // Draw the shiny sphere
        draw_triangle(camera_x, camera_y); // Draw the triangle with text
        get_input(&camera_x, &camera_y); // Get player input
        delay(50); // Simple frame rate control
    }
}
