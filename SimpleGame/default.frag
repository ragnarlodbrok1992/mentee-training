#version 330 core
// Output a color to the fragment shader
out vec4 FragColor;

void main()
{
	// Set FragColor to the input color of the vertex data
	FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f); 
}