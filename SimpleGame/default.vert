#version 330 core
// Written in OpenGL Shading Language (GLSL)
// Specify the input variables with location metadata 
// to configure the vertex attributes on the CPU
// On the 0th layout there is a vec3 datatype for positions
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

// Outputs the color for the Fragment Shader
out vec3 color;
// A uniform is a global Shader variable declared with the
// "uniform" storage qualifier (stored in a program object)
// that is shared between a shader and the OpenGL ES environment
// Uniforms are used to specify properties of the object that is rendered
// Uniform scale controls the scale of the vertices
uniform float scale;

void main()
{
	// Vertex shader receives its input straight from the vertex data
	// Assign a vec4 with all vertices positions to "gl_Position"
	// All positions are scaled by value declareted in Main glUniform
	gl_Position = vec4(aPos.x + aPos.x * scale, aPos.y + aPos.y * scale, aPos.z + aPos.z * scale, 1.0);
	// Assign the colors from Vertex Data
	color = aColor;
}
