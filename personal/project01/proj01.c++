#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

using namespace glm;

int main(void){

    if (!glfwInit){
        fprintf(stderr, "Error initing glfw\n");
        return -1;
    }
    glfwWindowHint(GLFW_SAMPLES, 4); // 4x anti ailiasing
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // open gl 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_ANY_PROFILE); // not old open gl

    GLFWwindow* window;
    window = glfwCreateWindow(1024, 768, "Tutorial 1", NULL, NULL); // make window 
    if (window == NULL){
        fprintf(stderr, "Failed to Open the GLFW window, if you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window); // init glew
    glewExperimental = true;
    if (glewInit() != GLEW_OK){
        fprintf(stderr, "Failed to init glew");
        return -1;
    }

    // to capture user input
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    do{
        glClear( GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();

    } while(glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);
}