#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include<stdio.h>
const GLint WIDTH = 800, HEIGHT = 600;

int main() 
{
	// glfw INITIALISATION 
	if (!glfwInit()) {
		printf("hey initialization failed");
		glfwTerminate();
		return 1;
	}
	// Setup glfw window properties 
	// set up the version 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
	// this code is used to know that deprecated version will not be used
	// only core profile is used 
	// NO BACKWARD COMPATIBILITY
	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
	// ALLOW FORWARD COMPATIBLE 
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	

	// create window 

	GLFWwindow *mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Test Window", NULL, NULL);
	// check if window is created or not 
	if (!mainWindow) {
		//GLFWwindow* mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Test Window", NULL, NULL);
		printf("window is not yet created");
		glfwTerminate();
		return 1;
	}

	// get buffer of window appear 
	int bufferwidth, bufferheight;
	glfwGetFramebufferSize(mainWindow, &bufferwidth, &bufferheight);


	// set context for glew to use 

	glfwMakeContextCurrent(mainWindow);

	// Allow modern extension features 

	glewExperimental = GL_TRUE;

	if (glewInit() !=GLEW_OK) {
		printf("glew initialitation is failed ");
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;

	}
	// view port size 
	glViewport(0, 0, bufferwidth,bufferheight );

	// loop until window closed

	while (!glfwWindowShouldClose(mainWindow)) {

		// get + Handle input events
		glfwPollEvents();

		//clear window
		glClearColor(1.0f, 1.0f,0.0f,1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(mainWindow);

	}

	return 0; 
}