/* Definition: do not open the file twice */
#ifndef VAO_CLASS_H
#define VAO_CLASS_H

#include<glad/glad.h>
#include"VBO.h"
/*
* Vertex Array Object
* Can be bound with corresponding VBOs and attribute pointers
* just like a vertex buffer object and any subsequent vertex attribute calls
* all will be stored inside the VAO.
* Thanks to the binding, it allows to make calls once and whenever there is 
* a need to draw the object bound with the corresponding VAO.
*/
class VAO
{
	public:
		GLuint ID;
		/**
		* A constructor.
		*/
		VAO();
		/*
		* @param VBO
		* @param layout
		*/
		void LinkVBO(VBO VBO, GLuint layout);
		void Bind();
		void Unbind();
		void Delete();
};

#endif
