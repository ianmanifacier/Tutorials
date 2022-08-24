#include "shaderClass.h"


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

Shader::Shader(const char* vertexFile, const char* fragmentFile)
{
	std::string vertexCode = get_file_contents(vertexFile);
	std::string fragmentCode = get_file_contents(fragmentFile);

	const char* vertexSource = vertexCode.c_str();
	const char* fragmentSource = fragmentCode.c_str();

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER); // we create a variable that will be used as a reference for our vertex shader
	glShaderSource(vertexShader, 1, &vertexSource, NULL); // we assign the source code of the vertex shader to the vertexShader variable
	glCompileShader(vertexShader); // we then compile the shader

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER); // we create a variable that will be used as a reference for our fragment shader
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL); // we assign the source code to the fragment shader shader
	glCompileShader(fragmentShader); // we then compile the fragment shader

	ID = glCreateProgram(); // we then create a shader program which will bundle the shaders into a single pipeline
	glAttachShader(ID, vertexShader); // here we attatch the vertex shader to the shader program
	glAttachShader(ID, fragmentShader); // here we attach the fragment shader to the shader program

	glLinkProgram(ID); // we then link the shader program so that it can be sent to the GPU

	glDeleteShader(vertexShader); // we delete the vertexShader since it is already contained in the shader program
	glDeleteShader(fragmentShader); // we delete the fragmentShader since it is already contained in the shader program
}

void Shader::Activate()
{
	glUseProgram(ID);// we tell OpenGL which shader program to run
}

void Shader::Delete()
{
	glDeleteProgram(ID);// we tell OpenGL to delete the program
}