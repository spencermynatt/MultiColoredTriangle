#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
using namespace std;
const char* vertex_shader =
"#version 430 core\n"
"layout(location = 0) in vec3 position;\n" //locaion 0 is where
//positions are
"layout(location = 1) in vec3 colors;\n"
"out vec3 color_fragment;\n" //out putting color fragment
"void main()\n"
"{\n"
"   gl_Position = vec4(position, 1.0);\n"
 "color_fragment = colors;\n" //setting color fragment
	//= to colors
"}\n";
const char* fragment_shader =
"#version 430 core\n"
"out vec4 fragcolors;\n"
"in vec3 color_fragment;\n"//input our color_fragment
"void main()\n"
"{\n"
"fragcolors = vec4(color_fragment, 1.0f);\n"
"}\n";
int main() {
	glfwInit();
	GLFWwindow* window = glfwCreateWindow(800, 600, "Spencer's triangle", NULL, NULL);
	if (window == NULL)
	{
		cout << "error";
	}
	glfwMakeContextCurrent(window);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	glViewport(0, 0, 800, 600);
	
	int vertex = glCreateShader(GL_VERTEX_SHADER);
	int fragment = glCreateShader(GL_FRAGMENT_SHADER);
	const char* pointer_to_shaders[1];
	pointer_to_shaders[0] = vertex_shader;
	glShaderSource(vertex, 1, pointer_to_shaders, 0);
	pointer_to_shaders[0] = fragment_shader;
	glShaderSource(fragment, 1, pointer_to_shaders, 0);
	glCompileShader(vertex);
	glCompileShader(fragment);
	int program = glCreateProgram();
	glAttachShader(program, vertex);
	glAttachShader(program, fragment);

	glLinkProgram(program);
	//glUseProgram(program);

	float points[]{
	0.5f, -0.5f, 0.0f,  
		-0.5f, -0.5f, 0.4f,    
		 0.0f,  0.5f, 0.0f,     
		 //third row of numbers are colors
	};
	
	unsigned int space;
	
	glGenVertexArrays(1, &space); //change color of each
	//verts
	glGenBuffers(1, &space);
	glBindVertexArray(space); //bind color

	
	glBindBuffer(GL_ARRAY_BUFFER, space);
	glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);
	
	
	
	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,0,0);
	glEnableVertexAttribArray(0);


	
	//location of where color buffer is
	
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(1);




	while (!glfwWindowShouldClose(window))
	{

		
		
		
			
			glUseProgram(program);
			glBindVertexArray(space);
			glDrawArrays(GL_TRIANGLES, 0, 3);

			glfwSwapBuffers(window);
			glfwPollEvents();


			
		//	glfwSwapInterval(20);

	}
	glfwTerminate();
	return 0;
}