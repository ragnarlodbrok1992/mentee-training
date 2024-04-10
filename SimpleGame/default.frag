#version 330 core
// Written in OpenGL Shading Language (GLSL)
// Output a color to the fragment shader
out vec4 FragColor;

in vec3 color;
uniform float scale;

void main()
{
	// Set FragColor to the input color of the vertex data
	FragColor = vec4(color.x * scale, color.y * scale, color.z * scale, 1.0f);
}