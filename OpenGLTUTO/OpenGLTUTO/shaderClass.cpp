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
/*
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER); // we create a variable that will be used as a reference for our vertex shader
	glShaderSource(vertexShader, 1, &vertexSource, NULL); // we assign the source code of the vertex shader to the vertexShader variable
	glCompileShader(vertexShader); // we then compile the shader

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER); // we create a variable that will be used as a reference for our fragment shader
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL); // we assign the source code to the fragment shader shader
	glCompileShader(fragmentShader); // we then compile the fragment shader

	GLuint shaderProgram = glCreateProgram(); // we then create a shader program which will bundle the shaders into a single pipeline
	glAttachShader(shaderProgram, vertexShader); // here we attatch the vertex shader to the shader program
	glAttachShader(shaderProgram, fragmentShader); // here we attach the fragment shader to the shader program

	glLinkProgram(shaderProgram); // we then link the shader program so that it can be sent to the GPU

	glDeleteShader(vertexShader); // we delete the vertexShader since it is already contained in the shader program
	glDeleteShader(fragmentShader); // we delete the fragmentShader since it is already contained in the shader program

	// sending stuff between the CPU and the GPU is kind of slow so we need to send them by big batches called buffers
	GLuint VAO, VBO, EBO; // Here we create a Vertex Attribute Obeject, a Vertex Buffer Object and an Element Buffer Object (EBO)

	// the VAO must be created before the VBO

	glGenVertexArrays(1, &VAO); // we generate a Vertex Attribue Object to tell GL what vertex to render
	glGenBuffers(1, &VBO); // here we generate the Vertex Buffer Object
	glGenBuffers(1, &EBO); // we generate the Element Buffer Object

	glBindVertexArray(VAO); // we bind the vertex attribute Object to the GL thus making it the current attribute

	glBindBuffer(GL_ARRAY_BUFFER, VBO); // Here we bind the VBO to the buffer
	// this means that we make it the current buffer object of type GL_ARRAY_BUFFER that will be modified when we work on glBindBuffer

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); // we indicated the type of data we are transfering (GL_arry_buffer, the size of the vertex array, the we provide the vertex array it self and to conclude indicate how it is going to be used. Here we say that it is static. 

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// We bind the VBO, VAO and EBO to 0 so that we don't accidentally modify the VAO, VBO and EBO we create
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);



	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	// We swap the front and back buffer so that the back one can be displayed
	glfwSwapBuffers(window);


	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f); // we create a background with a blue color
		glClear(GL_COLOR_BUFFER_BIT); // we apply the background color to window
		glUseProgram(shaderProgram); // we tell OpenGL wich shader program to run
		glBindVertexArray(VAO); // we bind the Vertex Array Object so that OpenGl knows that it is the current one
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);//glDrawArrays(GL_TRIANGLES, 0, 3); // we tell OpenGL that our array that the primitive type of our vertex array is triangles
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	glDeleteProgram(shaderProgram);
	*/
}