#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

float vertices[] = {
    // positions          // colors           // normals
    -0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f,  0.0f, 0.0f, -1.0f,
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f,  0.0f, 0.0f, -1.0f,
     0.5f,  0.5f, -0.5f,  0.0f, 0.0f, 1.0f,  0.0f, 0.0f, -1.0f,
     0.5f,  0.5f, -0.5f,  0.0f, 0.0f, 1.0f,  0.0f, 0.0f, -1.0f,
    -0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 0.0f,  0.0f, 0.0f, -1.0f,
    -0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 0.0f,  0.0f, 0.0f, -1.0f,

    -0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f,  0.0f, 0.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  0.0f, 1.0f, 0.0f,  0.0f, 0.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f,  0.0f, 0.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f,  0.0f, 0.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 0.0f,  0.0f, 0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  1.0f, 1.0f, 0.0f,  0.0f, 0.0f, 1.0f,

    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f, -1.0f, 0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f ,  0.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f,
    -0.5f, -0.5f,  0.5f,  1.0f, 1.0f, 0.0f, -1.0f, 0.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 0.0f, -1.0f, 0.0f, 0.0f,

     0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f,  1.0f, 0.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f,  1.0f, 0.0f, 0.0f,
     0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 1.0f,  1.0f, 0.0f, 0.0f,
     0.5f, -0.5f, -0.5f,  0.0 f, 0.0f, 1.0f,  1.0f, 0.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 1.0f, 0.0f,  1.0f, 0.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 0.0f,  1.0f, 0.0f, 0.0f,

    -0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f,  0.0f, -1.0f, 0.0f,
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f,  0.0f, -1.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f,  0.0f, -1.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f,  0.0f, -1.0f, 0.0f,
    -0.5f, -0.5f,  0.5f,  1.0f, 1.0f, 0.0f,  0.0f, -1.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 0.0f,  0.0f, -1.0f, 0.0f,

    -0.5f,  0.5f, -0.5f,  1.0f, 0.0f, 0.0f,  0.0f, 1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f,  0.0f, 1.0f, 0.0f,
     0.5f ,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f,  0.0f, 1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f,  0.0f, 1.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 0.0f,  0.0f, 1.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 0.0f,  0.0f, 1.0f, 0.0f
};

unsigned int indices[] = {
    0, 1, 2, 2, 3, 0,
    4, 5, 6, 6, 7, 4,
    8, 9, 10, 10, 11, 8,
    12, 13, 14, 14, 15, 12,
    16, 17, 18, 18, 19, 16,
    20, 21, 22, 22, 23, 20
};

int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        printf("Failed to initialize GLFW\n");
        return -1;
    }

    // Create a window
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "3D Rendering", NULL, NULL);
    if (!window) {
        printf("Failed to create GLFW window\n");
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Initialize GLEW
    if (glewInit() != GLEW_OK) {
        printf("Failed to initialize GLEW\n");
        glfwTerminate();
        return -1;
    }

    // Create vertex buffer object
    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    // Create element buffer object
    unsigned int EBO;
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // Load shaders
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    char* vertexShaderSource = "..."; // Load vertex shader source
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    char* fragmentShaderSource = "..."; // Load fragment shader source
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    // Create shader program
    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    // Set up the view and projection matrices
    glm::mat4 view = glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);

    // Set up the camera
    glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
    glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Handle input
        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
            cameraPos += cameraFront * 0.1f;
        }
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
            cameraPos -= cameraFront * 0.1f;
        }
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
            cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * 0.1f;
        }
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
            cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * 0.1f;
        }

        // Clear the screen
        glClearColor(0.53f, 0.81f, 0.98f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Use the shader program
        glUseProgram(shaderProgram);

        // Set up the model matrix
        glm::mat4 model = glm::mat4(1.0f);

        // Set up the view and projection matrices
        glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
        glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));

        // Draw the cube
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

        // Swap buffers and poll events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Clean up
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glDeleteProgram(shaderProgram);

    glfwTerminate();
    return 0;
}
