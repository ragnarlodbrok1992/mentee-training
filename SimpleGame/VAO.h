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
		* A constructor that generates VAO.
		*/
		VAO();
		/*
		* @param VBO
		* @param layout - the location of the layout
		*  defined in default.vert 0 for coordinates/position and 1 for color
		* @param numComponents - the number of components per layout
		*  defined in Main.cpp three floats per position and three for color
		* @param type - type of the component
		*  defined in Main.cpp vertices GLfloat type
		* @param stride - coordinates stride, the distance in bytes between the begining
		*  of one vertex and end of another (each vertex has 6 floats times the foat size)
		* @param offset - the initial ofset of layout in bytes,
		*  0 for coordinates and 12 for color in first vertex
		*/
		void LinkAttrib(VBO& VBO, GLuint layout, GLuint numComponents,
			GLenum type, GLsizeiptr stride, void* offset);
		void Bind();
		void Unbind();
		void Delete();
};

#endif
