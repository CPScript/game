description:
* attempt to make an extremely "simple" and low level 3d game... (simple 3d engine that makes a small map that has a reflective cube)
* this was used as a example for a diffrent repository called 'malware-game' i made
* might be buggy

stucture:

```
game/
├── main.c
├── shaders/
│   ├── vertex_shader.glsl
│   └── fragment_shader.glsl
└── Makefile
```


#### Limitations
* This code is a simplified version of a 3D rendering engine and does not include many features that a full engine would have.
* The code is written in **C** and uses the **GLFW** and **GLEW** libraries for window and OpenGL management.
* The code assumes that the user has a basic understanding of 3D graphics programming and OpenGL.


## main.c
This file contains the main program logic for initializing the window, setting up OpenGL, and rendering the 3D scene.

 - Explanation:
Includes and Constants:

Includes necessary headers for OpenGL, GLFW, and GLM.
Defines constants for the screen width and height.
Vertex Data:

Defines an array of vertices for a cube, including positions, colors, and normals.
 ' Main Function:

* **Initialize GLFW**: Sets up GLFW and creates a window.
* **Initialize GLEW**: Sets up GLEW to handle OpenGL function pointers.
* **Create Buffers**: Creates and binds Vertex Array Object (VAO), Vertex Buffer Object (VBO), and Element Buffer Object (EBO).
* **Load Shaders**: Loads and compiles vertex and fragment shaders.
* **Create Shader Program**: Links the shaders into a shader program.
* **Set Up Matrices**: Sets up view and projection matrices for the camera.
* **Main Loop**: Handles input, updates the camera position, clears the screen, sets up shader uniforms, and draws the cube.
* **Clean Up**: Deletes buffers and terminates GLFW.

## vertex_shader.glsl
This file contains the vertex shader code, which handles the transformation of vertex positions and normals, and passes them to the fragment shader.

Explanation:
Inputs:

aPos: Vertex position.
aColor: Vertex color.
aNormal: Vertex normal.
Outputs:

FragPos: Transformed position of the vertex.
Normal: Transformed normal of the vertex.
Color: Color of the vertex.
Uniforms:

model: Model matrix.
view: View matrix.
projection: Projection matrix.
Main Function:

Transforms the vertex position using the model, view, and projection matrices.
Transforms the vertex normal.
Passes the color to the fragment shader.

## fragment_shader.glsl
This file contains the fragment shader code, which handles the lighting calculations, including ambient, diffuse, and specular components, to create a realistic rendering effect.

Explanation:
Outputs:

FragColor: Final color of the fragment.
Inputs:

FragPos: Position of the fragment.
Normal: Normal of the fragment.
Color: Color of the fragment.
Uniforms:

viewPos: Position of the camera.
Main Function:

Ambient Lighting: Adds a constant ambient light to the fragment.
Diffuse Lighting: Calculates diffuse lighting based on the angle between the light direction and the fragment normal.
Specular Lighting: Calculates specular highlights based on the angle between the view direction and the reflection of the light direction.
Combines the ambient, diffuse, and specular components to compute the final color of the fragment.

## Makefile
This file contains the build instructions for compiling and linking the program.

Explanation:
Variables:
* **CC**: The compiler to use, in this case, gcc.
* **CFLAGS**: Compiler flags, including -Wall for all warnings and -g for debugging information.
* **INCLUDES**: Include directories for header files.
* **LIBDIRS**: Library directories for linking.
* **LIBS**: Libraries to link against, including GLFW, OpenGL (GL), GLEW, and the math library (m).
* **SRCS**: Source files.
* **OBJS**: Object files corresponding to the source files.
* **EXEC**: The name of the executable to be generated.
* **all**: The default target that builds the executable.
* **$(EXEC)**: Links the object files to create the executable.
* **%.o: %.c**: Compiles source files to object files.
* **clean**: Removes the object files and the executable.
* **.PHONY**: Specifies phony targets that do not correspond to actual files.



how to use the makefile:
* `make` run command in terminal
* `./3d_game` run the generated executable
* `make clean` clean build files
