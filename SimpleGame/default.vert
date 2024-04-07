#version 330 core
// Specify the input variables with location metadata 
// to configure the vertex attributes on the CPU
// The position variable has attribute position 0
layout (location = 0) in vec3 aPos;

void main()
{
	// Vertex shader receives its input straight from the vertex data
	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
}
