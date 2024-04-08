#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include "shaderClass.h"
#include "EBO.h"
#include "VBO.h"
#include "VAO.h"

#define WINDOW_TITLE_PREFIX "Shapes"

int
	CurrentWidth = 800,
	CurrentHeight = 800,
	WindowHandle = 0;

/* 
* Geometric figures with vertices corner coordinates
* 
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
/* One big triangle and small one inside using vertices & indices corner coordinates
* 
float vertices[] = {
	- 0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower left corner
	0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower right corner
	0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f, // Upper corner
	-0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f, // Inner left
	0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f, // Inner right
	0.0f, -0.5f * float(sqrt(3)) / 3, 0.0f // Inner down
};
GLuint indices[] =
{
	0, 3, 5, // Lower left triangle
	3, 2, 4, // Lower right triangle
	5, 4, 1 // Upper triangle
};
*/

/*
* Square with vertices & indices
*/
GLfloat vertices[] = {
	-0.8f, -0.8f, 0.0f, // Lower left
	0.8f,  -0.8f, 0.0f, // Lower right
	-0.8f,  0.8f, 0.0f, // Upper left
	0.8f,  0.8f, 0.0f, // Upper right
};
GLuint indices[] =
{
	0, 1, 2, // Lower left triangle
	2, 1, 3, // Upper right triangle
};

int main() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // Use version OpelGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // Use version OpelGL 3.3
	// Use CORE profile with modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(CurrentWidth, CurrentHeight, WINDOW_TITLE_PREFIX, NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	gladLoadGL();
	glViewport(0, 0, CurrentWidth, CurrentHeight);

	Shader shaderProgram("default.vert", "default.frag");

	VAO VAO1;
	VAO1.Bind();

	VBO VBO1(vertices, sizeof(vertices));
	EBO EBO1(indices, sizeof(indices));

	VAO1.LinkVBO(VBO1, 0);

	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();

	/*
	Shuffle BG colors
		float prev_time = float(glfwGetTime());
		float angle = 0.0f;
	*/

	while (!glfwWindowShouldClose(window))
	{
	/*
	* Shuffle BG colors
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

		shaderProgram.Activate();
		VAO1.Bind();

		// Draw the triangle using the GL_TRIANGLES primitive
		// glDrawArrays(GL_TRIANGLES, 0, 3);
		// Draw a square using the GL_TRIANGLES primitive
		// glDrawArrays(GL_TRIANGLES, 0, 6);
		// Draw primitives, number of indices, datatype of indices, index of indices
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	shaderProgram.Delete();

	// Delete window and terminate GLFW before program ends
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}