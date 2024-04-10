/* Definition: do not open the file twice */
#ifndef VBO_CLASS_H
#define VBO_CLASS_H

#include<glad/glad.h>
/*
* Vertex Buffer Object
* store a large number of vertices in the GPU's memory,
* send large batches of data all at once to the graphics card,
* keep it there if there's enough memory left,
* no need to send data one vertex at a time
*/
class VBO
{
	public:
		GLuint ID;
		/**
		* A constructor.
		* @param vertices an GLfloat - 32bit RBGA color, cross platform, 8bit array
		* @param size an GLsizeiptr - non-negative binary integer size, for memory offsets and ranges
		*/
		VBO(GLfloat* vertices, GLsizeiptr size);

		void Bind();
		void Unbind();
		void Delete();
};

#endif
