#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

// Vertex Shader source code
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
//Fragment Shader source code
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
"}\n\0";

int main() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // Use version OpelGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // Use version OpelGL 3.3
	// Use CORE profile with modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Vertices corner coordinates

	/*
	GLfloat vertices[] = { // equilateral triangle
		-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
		0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
		0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f
	};
	GLfloat vertices[] = { // right triangle
		-0.3f, -0.3f, 0.0f, // Lower left
		0.3f, -0.3f, 0.0f, // Lower right
		-0.3f, 0.3f, 0.0f // Upper left
	};
	*/

	GLfloat vertices[] = { // square
		-0.8f,  0.8f, 0.0f,
		0.8f,  0.8f, 0.0f,
		-0.8f, -0.8f, 0.0f,

		-0.8f, -0.8f, 0.0f,
		0.8f,  0.8f, 0.0f,
		0.8f, -0.8f, 0.0f,
	};

	GLFWwindow* window = glfwCreateWindow(800, 800, "Shapes", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	gladLoadGL();
	glViewport(0, 0, 800, 800);

	// Create unsigned binary integer shader of vertex type
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	// Returns the concatenation of the source code strings from the shader object specified by shader
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader); // compile to machine code

	// create unsigned binary integer shader of vertex type
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	// Use both shaders by wrapping them up into shader program
	GLuint shaderProgram = glCreateProgram();
	// Attach both shaders
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	// clear memo
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	GLuint
		VAO, // Vertex Array Object - pointers to VBO
		VBO; // Vertex Buffer Object

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	/*
	Shuffle BG colors
		float prev_time = float(glfwGetTime());
		float angle = 0.0f;
	*/

	while (!glfwWindowShouldClose(window))
	{
	/*
	Shuffle BG colors
		float time = float(glfwGetTime());
		if (time - prev_time >= 0.1f) // Every 0.1 sec it's true 
		{
			angle += 0.1f; // Change angle with color
			prev_time = time;
		}
		// Trigonometry to change colors
		glClearColor(float(sin(angle)), float(cos(angle)), float(tan(angle)), 1.0f);

		// Change visability of colors
		glClear(GL_COLOR_BUFFER_BIT);
		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all events
		glfwPollEvents();
	*/
		// Specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// Clean the back buffer and assign the new color to it
		glClear(GL_COLOR_BUFFER_BIT);
		// Tell OpenGL which Shader Program we want to use
		glUseProgram(shaderProgram);
		// Bind the VAO so OpenGL knows to use it
		glBindVertexArray(VAO);
		// Draw the triangle using the GL_TRIANGLES primitive
		//glDrawArrays(GL_TRIANGLES, 0, 3);

		// Draw a square using the GL_TRIANGLES primitive
		glDrawArrays(GL_TRIANGLES, 0, 6);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// Delete all objects
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteProgram(shaderProgram);

	// Delete window and terminate GLFW before program ends
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}