#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "EAGL/vectors.h"
#include "EAGL/render.h"
#include "EAGL/sprite.h"

#include "camera.h"
#include "location_object.h"



//#include "player.h"

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

 



    Shader_Program shader = Shader_Program(
        "E:/C++ projects/Eidor_0/Shaders/Basic_Shader/Vertex.txt",
        "E:/C++ projects/Eidor_0/Shaders/Basic_Shader/Fragment.txt");
    Shader_Program shader_bg(
        "E:/C++ projects/Eidor_0/Shaders/Background_Shader/Vertex.txt",
        "E:/C++ projects/Eidor_0/Shaders/Background_Shader/Fragment.txt");

    Texture_Manager _texture_manager;
    Sprite_Manager _sprite_manager;

    Location_Object_Manager _location_object_manager(&_sprite_manager);

    
    _texture_manager.add_Texture(
        "E:/C++ projects/Eidor_0/bgg_3.jpg",
        "Background",
        "JPG"
    );
    _texture_manager.add_Texture(
        "E:/C++ projects/Eidor_0/rock.jpg",
        "Rock",
        "JPG"
    );
    _texture_manager.add_Texture(
        "E:/C++ projects/Eidor_0/slot.jpg",
        "Slot",
        "JPG"
    );
    _texture_manager.add_Texture(
        "E:/C++ projects/Eidor_0/icon_personal.jpg",
        "Icon_Personal",
        "JPG"
    );

    _sprite_manager.add_Sptite(
        &_texture_manager,
        "Sprite_Rock",
        Vector2D_f(100.f, 100.f),
        Vector2D_f(100.f, 100.f),
        Vector3D_f(1.0f, 1.0f, 1.0f),
        Vector2D_f(0.0f, 1.0f),
        Vector2D_f(1.0f, 1.0f),
        Vector2D_f(1.0f, 0.0f),
        Vector2D_f(0.0f, 0.0f)
    );

    _location_object_manager.add_Location_Object(
        "Sprite_Rock",
        Vector2D_f(30.f, 50.f),
        Vector2D_f(100.f, 120.f),
        true
    );


    _texture_manager.show_Info();
    _sprite_manager.show_Info();
    _location_object_manager.show_Info();
    _camera.show_Info_Camera();

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(pWindow))
    {

        _camera.move_Camera();

        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        
        /// Render background ----

        render.Draw(background, shader_bg, _texture_manager.get_Texture("Background"));
        render.Draw(slot, shader_bg, _texture_manager.get_Texture("Slot"));


        /// Render object ----

        std::vector<Rect> render_object = _camera.pull_Object(_location_object_manager.pull_Location_Object());


        render.Draw(
            _sprite_manager.get_Sprite("Sprite_Rock").get_Surface(),
            shader,
            _sprite_manager.get_Sprite("Sprite_Rock").get_Texture_Manager()->get_Texture("Rock")
        );
        

        /* Swap front and back buffers */
        glfwSwapBuffers(pWindow);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}