#include "VAO.h"
// Vertex Array Object - pointers to EBO
VAO::VAO()
{
	glGenVertexArrays(1, &ID);
}

void VAO::LinkAttrib(VBO& VBO, GLuint layout, GLuint numComponents,
	GLenum type, GLsizeiptr stride, void* offset)
{
	VBO.Bind();
	/*
	* Bind the VAO so OpenGL knows how to use it
	*/
	glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
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
