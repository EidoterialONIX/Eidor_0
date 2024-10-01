#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "EAGL/vectors.h"
#include "EAGL/render.h"

#include "camera.h"

#include <iostream>


struct Option {

    int WINDOW_SIZE[2] = { 640, 480 };

};

Option _option;

Camera _camera(Vector2D_f(_option.WINDOW_SIZE[0], _option.WINDOW_SIZE[1]), Vector2D_f(3000, 5000));

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
    else if (key == GLFW_KEY_W && action == GLFW_PRESS) {
        _camera.move_Camera(Vector2D_f(
            0.0f,
            -_camera.get_Permament_Speed()
        ));
        _camera.show_Info_Camera();
    }
    else if (key == GLFW_KEY_S && action == GLFW_PRESS) {
        _camera.move_Camera(Vector2D_f(
            0.0f,
            _camera.get_Permament_Speed()
        ));
        _camera.show_Info_Camera();
    }
    else if (key == GLFW_KEY_A && action == GLFW_PRESS) {
        _camera.move_Camera(Vector2D_f(
            -_camera.get_Permament_Speed(),
            0.0f
        ));
        _camera.show_Info_Camera();
    }
    else if (key == GLFW_KEY_D && action == GLFW_PRESS) {
        _camera.move_Camera(Vector2D_f(
            _camera.get_Permament_Speed(),
            0.0f
        ));
        _camera.show_Info_Camera();
    }
    else if (key == GLFW_KEY_R && action == GLFW_PRESS) {
        _camera.reset_zoom();
        _camera.show_Info_Camera();
    }
    else if (key == GLFW_KEY_U && action == GLFW_PRESS) {
        _camera.up_zoom();
        _camera.show_Info_Camera();
    }
    else if (key == GLFW_KEY_Y && action == GLFW_PRESS) {
        _camera.down_zoom();
        _camera.show_Info_Camera();
    }

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



    /* Make the window's context current */
    glfwMakeContextCurrent(pWindow);



    if (!gladLoadGL())
    {
        std::cout << "Can't load GLAD!" << std::endl;
    }
    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;

    glClearColor(1, 1, 0, 1);



    Render render(Vector3D_f(_option.WINDOW_SIZE[0], _option.WINDOW_SIZE[1], 0.0f));

    Rect rect;

    rect.set_Position(Vector3D_f(100.0f, 100.0f, 0.0f));
    rect.set_Size(Vector3D_f(200.0f, 100.0f, 0.0f));
    rect.set_Color(Vector3D_f(1.0f, 0.0f, 0.0f));
    rect.set_Texture_Points(Vector2D_f(0.0f, 1.0f), Vector2D_f(1.0f, 1.0f), Vector2D_f(1.0f, 0.0f), Vector2D_f(0.0f, 0.0f));

    Shader_Program shader = Shader_Program(
        "E:/project/Si_Or/src/Render/Shaders/Basic_vertex.txt",
        "E:/project/Si_Or/src/Render/Shaders/Basic_fragment.txt");

    Texture texture = Texture("E:/Project/Eidor_0/Texture_2.jpg");

    _camera.show_Info_Camera();

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(pWindow))
    {

        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        render.Draw(rect, shader, texture);

        /* Swap front and back buffers */
        glfwSwapBuffers(pWindow);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}