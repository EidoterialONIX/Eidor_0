#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "EAGL/vectors.h"
#include "EAGL/render.h"
#include "EAGL/sprite.h"

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

Collision _collision;

Option _option;

Camera _camera;

Interface* _pinterface;

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
        _camera.change_Velosity(1);
        _camera.show_Info_Camera();
    }
    else if (key == GLFW_KEY_S && action == GLFW_PRESS) {
        _camera.change_Velosity(3);
        _camera.show_Info_Camera();
    }
    else if (key == GLFW_KEY_A && action == GLFW_PRESS) {
        _camera.change_Velosity(0);
        _camera.show_Info_Camera();
    }
    else if (key == GLFW_KEY_D && action == GLFW_PRESS) {
        _camera.change_Velosity(2);
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

    if (key == GLFW_KEY_A && action == GLFW_RELEASE) {
        _camera.reset_velosity();
    }
    else if (key == GLFW_KEY_W && action == GLFW_RELEASE) {
        _camera.reset_velosity();
    }
    else if (key == GLFW_KEY_D && action == GLFW_RELEASE) {
        _camera.reset_velosity();
    }
    else if (key == GLFW_KEY_S && action == GLFW_RELEASE) {
        _camera.reset_velosity();
    }
}

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {

    glfwGetCursorPos(window, &_option.CURSOR_POSITION[0], &_option.CURSOR_POSITION[1]);

    for (int i{ 0 }; i < _pinterface->get_Main_Menu_Interface().size(); i++) {
        if (_pinterface->get_Main_Menu_Interface()[i].get_Status_Collision()) {
            if (_collision.check_Interface_Collision(
                _pinterface->get_Main_Menu_Interface()[i].get_Position(),
                _pinterface->get_Main_Menu_Interface()[i].get_Size(),
                _option.CURSOR_POSITION[0],
                _option.CURSOR_POSITION[1]
            )) {
                if (_pinterface->get_Main_Menu_Interface()[i].get_Name_Link_Sprite() == "Sprite_Default") {
                    _pinterface->get_Main_Menu_Interface()[i].set_Name_Link_Sprite("Sprite_Hover");
                }
                else if (_pinterface->get_Main_Menu_Interface()[i].get_Name_Link_Sprite() == "Sprite_Hover"){
                    _pinterface->get_Main_Menu_Interface()[i].set_Name_Link_Sprite("Sprite_Default");
                }
            }
        }
    }

}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{

    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS) {
        glfwGetCursorPos(window, &_option.CURSOR_POSITION[0], &_option.CURSOR_POSITION[1]);

        
        for (int i{ 0 }; i < _pinterface->get_Main_Menu_Interface().size(); i++) {
            if (_pinterface->get_Main_Menu_Interface()[i].get_Status_Collision()) {
                if (_collision.check_Interface_Collision(
                    _pinterface->get_Main_Menu_Interface()[i].get_Position(),
                    _pinterface->get_Main_Menu_Interface()[i].get_Size(),
                    _option.CURSOR_POSITION[0],
                    _option.CURSOR_POSITION[1]
                )) {
                    if (_pinterface->get_Main_Menu_Interface()[i].get_Name_Link_Sprite() == "Sprite_Hover") {
                        _pinterface->get_Main_Menu_Interface()[i].set_Name_Link_Sprite("Sprite_Active");
                    }
                }
            }
        }
        
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

    Render render(Vector3D_f(_option.WINDOW_SIZE[0], _option.WINDOW_SIZE[1], 0.0f));
    _camera = Camera(&render, Vector2D_f(_option.WINDOW_SIZE[0], _option.WINDOW_SIZE[1]), Vector2D_f(3000, 5000));


    Shader_Program shader = Shader_Program(
        "E:/C++ projects/Eidor_0/Shaders/Basic_Shader/Vertex.txt",
        "E:/C++ projects/Eidor_0/Shaders/Basic_Shader/Fragment.txt");
    Shader_Program shader_bg(
        "E:/C++ projects/Eidor_0/Shaders/Background_Shader/Vertex.txt",
        "E:/C++ projects/Eidor_0/Shaders/Background_Shader/Fragment.txt");


    

    Assets _assets("E:../src/assets/");
    //Assets _assets("E:../Debug/assets/");

    Interface _interface(&_assets);
    Animation _animation(&_assets);

    _interface.get_Texture().show_Info();
    _interface.get_Sprite().show_Info();

    _animation.get_Texture().show_Info();
    _animation.get_Sprite().show_Info();

    _pinterface = &_interface;

    _camera.show_Info_Camera();

    int frame_detector = 0;

    

    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(pWindow))
    {
        glfwSetWindowTitle(pWindow, "12");
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);


        /// RENDER MAIN MENU
        _camera.camera_Vision(&_interface, shader);


        /// ////////////////////////////


        _camera.move_Camera();

        

        
        /// Render background ----




        /// Render object ----

       


        /// Render interface ----
        

        /* Swap front and back buffers */
        glfwSwapBuffers(pWindow);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}