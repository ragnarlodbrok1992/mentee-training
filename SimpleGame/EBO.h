/* Definition: do not open the file twice */
#ifndef EBO_CLASS_H
#define EBO_CLASS_H

#include<glad/glad.h>
/*
* Element Buffer Objects
* Uses indexed drawing solution.
* A buffer that stores only the unique vertices and then
* specifies the order in which we want to draw these vertices.
*/
class EBO
{
	public:
		GLuint ID;
		/**
		* A constructor.
		* @param indices an GLuint - unsigned binary integer
		* @param size an GLsizeiptr - non-negative binary integer size, for memory offsets and ranges
		*/
		EBO(GLuint* indices, GLsizeiptr size);

		void Bind();
		void Unbind();
		void Delete();
};

#endif
