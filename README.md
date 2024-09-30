* This creates a window with a rotating cube in the center.
* The cube is colored and has a reflective surface.
* The camera can be moved around using the W, A, S, and D keys.


#### Limitations
* This code is a simplified version of a 3D rendering engine and does not include many features that a full engine would have.
* The code is written in **C** and uses the **GLFW** and **GLEW** libraries for window and OpenGL management.
* The code assumes that the user has a basic understanding of 3D graphics programming and OpenGL.

make file explination:
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
