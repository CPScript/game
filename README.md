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
