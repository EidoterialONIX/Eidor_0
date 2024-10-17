#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "EAGL/vectors.h"
#include "EAGL/render.h"
#include "EAGL/sprite.h"
#include "EAGL/time.h"
#include "EAGL/font.h"
#include "EAGL/color.h"

#include "collision.h"

#include "camera.h"
#include "location_object.h"

#include "load_assets.h"
#include "interface.h"
#include "animation.h"


//#include "player.h"

#include <iostream>


struct Option {

    int WINDOW_SIZE[2] = { 640, 480 };
    double CURSOR_POSITION[2] = { 0.0f, 0.0f };

};

Option _option;

void glfwWindowSizeCallback(GLFWwindow* pWindow, int width, int height)
{
    _option.WINDOW_SIZE[0] = width;
    _option.WINDOW_SIZE[1] = height;
    glViewport(0, 0, _option.WINDOW_SIZE[0], _option.WINDOW_SIZE[1]);
}

void glfwKeyCallback(GLFWwindow* pWindow, int key, int scancode, int action, int mode)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(pWindow, GL_TRUE);
    }
}

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {


}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
       
}


int main(void)
{
    /* Initialize the library */
    if (!glfwInit())
    {
        std::cout << "glfwInit failed!" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);


    /* Create a windowed mode window and its OpenGL context */
    GLFWwindow* pWindow = glfwCreateWindow(_option.WINDOW_SIZE[0], _option.WINDOW_SIZE[1], "OGL_P", nullptr, nullptr);
    if (!pWindow)
    {
        std::cout << "glfwCreateWindow failed!" << std::endl;
        glfwTerminate();
        return -1;
    }


    glfwSetWindowSizeCallback(pWindow, glfwWindowSizeCallback);

    glfwSetKeyCallback(pWindow, glfwKeyCallback);

    glfwSetCursorPosCallback(pWindow, cursor_position_callback);
    glfwSetMouseButtonCallback(pWindow, mouse_button_callback);



    /* Make the window's context current */
    glfwMakeContextCurrent(pWindow);



    if (!gladLoadGL())
    {
        std::cout << "Can't load GLAD!" << std::endl;
    }
    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;

    Color a(
        255, 255,
        255, 255
    );

    Color b(
       5, 3,
        17, 10
    );

    a = a / b;

    a.out_Information();

    Time _time;

    glClearColor(1.0f, 1.0f, 0.0f, 0.0f);
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(pWindow))
    {
        _time.update();


        /// Game Rendering
        while (_time.get_Delta_Time() >= 1.0f) {
            _time.increment_Updates();
            _time.decrement_Delta_Time();

            _time.increment_Frames();

            /* Render here */
            glClear(GL_COLOR_BUFFER_BIT);

               

            /* Swap front and back buffers */
            glfwSwapBuffers(pWindow);

            /* Poll for and process events */
            glfwPollEvents();
            

        }

        

        if (glfwGetTime() - _time.get_Timer() >= 1.0f) {
            _time.increment_Timer();

            /*
            std::cout
                << "FPS: "
                << _time.get_Frames()
                << " Updates: "
                << _time.get_Updates()
                << " Timer: "
                << _time.get_Timer()
                << std::endl;
            */
            /*
            std::cout
                << "Now time: "
                << _time.get_Now_Time()
                << " Last time: "
                << _time.get_Last_Time()
                << " Delta time: "
                << _time.get_Delta_Time()
                << std::endl;
            */
            

            _time.reset_Frames();
            _time.reset_Updates();

        }

    }

    glfwTerminate();
    return 0;
}