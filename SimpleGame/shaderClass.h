/* Definition: do not open the file twice */ 
#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H

#include<glad/glad.h>
#include<iostream>
#include<fstream>
#include<sstream>
#include<cerrno>

/**
* @param filename an constant character shader text file
* @return content of the file as a string
*/
std::string get_file_contents(const char* filename);

class Shader
{
	public:
		GLuint ID;
		/** 
		* A constructor.
		* Requires the file paths of the source code of the vertex and fragment shader
		* @param vertexFile an constant character
		* @param fragmentFile an constant character
		*/
		Shader(const char* vertexFile, const char* fragmentFile);

		void Activate();
		void Delete();
};

#endif