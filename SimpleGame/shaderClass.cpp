#include "shaderClass.h"
/*
* Reads a text file using io streams 
* Outputs a string with everything in the text file
*/
std::string get_file_contents(const char* filename)
{
	std::ifstream in(filename, std::ios::binary);
	if (in)
	{
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return(contents);
	}
	throw(errno);
}
/*
* A Shader class
*/
Shader::Shader(const char* vertexFile, const char* fragmentFile) 
{
	/*
	* Take vertex and fragment source code as a string
	*/
	std::string vertexCode = get_file_contents(vertexFile);
	std::string fragmentCode = get_file_contents(fragmentFile);

	/*
	* Convert and store shaders into character arrays
	*/
	const char* vertexSource = vertexCode.c_str();
	const char* fragmentSource = fragmentCode.c_str();

	/*
	* Create unsigned binary integer shader of vertex type
	*/
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	/*
	* Return the concatenation of the source code strings from the shader object specified by shader
	*/
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader); // Compile the shader into machine code
	/*
	* Create unsigned binary integer shader of fragment type
	*/
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);
	/*
	* Use both shaders by wrapping them up into shader program
	*/
	ID = glCreateProgram();
	/*
	* Attach both shaders to the shader program
	*/
	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);
	/*
	* Link all shaders into the shader program
	*/
	glLinkProgram(ID);
	/*
	* Clear memory from unnecessary shaders
	*/
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Shader::Activate()
{
	/*
	* Tell OpenGL which Shader Program we want to use
	*/
	glUseProgram(ID);
}

void Shader::Delete()
{
	/*
	* Delete Shader Program
	*/
	glDeleteProgram(ID);
}