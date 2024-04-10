#version 330 core
// Written in OpenGL Shading Language (GLSL)
// Output a color to the fragment shader
out vec4 FragColor;

in vec3 color;

void main()
{
	// Set FragColor to the input color of the vertex data
	FragColor = vec4(color, 1.0f);
}