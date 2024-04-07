#include "VAO.h"
// Vertex Array Object - pointers to EBO
VAO::VAO()
{
	glGenVertexArrays(1, &ID);
}

void VAO::LinkVBO(VBO VBO, GLuint layout)
{
	VBO.Bind();
	/*
	* Bind the VAO so OpenGL knows how to use it
	*/
	glBindVertexArray(ID);
	glVertexAttribPointer(layout, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	/*
	* Enable the vertex attr
	*/
	glEnableVertexAttribArray(layout);
	VBO.Unbind();
}

void VAO::Bind()
{
	glBindVertexArray(ID);
}

void VAO::Unbind()
{
	glBindVertexArray(0);
}

void VAO::Delete()
{
	/*
	* Delete all objects
	*/
	glDeleteVertexArrays(1, &ID);
}
