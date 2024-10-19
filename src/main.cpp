#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "EAGL/vectors.h"
#include "EAGL/render.h"
#include "EAGL/rect.h"
#include "EAGL/texture.h"
#include "EAGL/sprite.h"
#include "EAGL/time.h"
#include "EAGL/color.h"

#include "collision.h"

#include "camera.h"

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


    Shader_Program shader(
        "E:/C++ projects/Eidor_0/Shaders/Basic_Shader/Vertex.txt",
        "E:/C++ projects/Eidor_0/Shaders/Basic_Shader/Fragment.txt"
    );



    Texture _texture1, _texture2;

    Font _font;
    _font.load_Font(
        "E:/C++ projects/Eidor_0/src/assets/Font/Number_FONT.png",
        Vector2D_f(160, 16),
        Vector2D_f(16, 16)
    );

    Text text(&_font);

    text.set_Text("54335433");
    text.set_Color(Color(255, 255, 255, 255));
    text.set_Start_Position(Vector2D_f(100, 30));
    text.set_Text_Size(16.0f);

    _texture1.load_Texture(
        "E:/C++ projects/Eidor_0/src/assets/Background/main_background_menu.jpg",
        3
    );
    _texture2.load_Texture(
        "E:/C++ projects/Eidor_0/src/assets/spell/animation/spell_Crous.png",
        4
    );

    Sprite spell_crous;

    spell_crous.set_Sprite(
        Color(255, 255, 255, 255),
        Vector2D_f(), Vector2D_f(),
        Vector2D_f(), Vector2D_f()
    );
    spell_crous.bind_Texture(&_texture2);
    spell_crous.init_Animation_Unit(
        6,
        32,
        32
    );

    Render _render(Vector2D_f(_option.WINDOW_SIZE[0], _option.WINDOW_SIZE[1]));
    Time _time;

    Camera _camera(
        &_render,
        &_time,
        Vector2D_f(_option.WINDOW_SIZE[0], _option.WINDOW_SIZE[1]),
        Vector2D_f(3000.0f, 5000.0f)
    );

    Rect rect1, rect2;

    Vector2D_f _texture_points[4] = {
        Vector2D_f(0.0f, 1.0f),
        Vector2D_f(1.0f, 1.0f),
        Vector2D_f(1.0f, 0.0f),
        Vector2D_f(0.0f, 0.0f),
    };

    rect1.set_Position(Vector2D_f(0.0f, 0.0f));
    rect1.set_Size(Vector2D_f(32, 32));
    rect1.set_Color(Color(255, 0, 0, 255));
    rect1.set_Texture_Points(_texture_points);

    rect2.set_Position(Vector2D_f(100.0f, 100.0f));
    rect2.set_Size(Vector2D_f(32, 32));
    rect2.set_Color(Color(255, 255, 255, 255));
    rect2.set_Texture_Points(_texture_points);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
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

            text.set_Text(std::to_string(_time.get_Frames()));

            rect2.set_Position(rect2.get_Position() + Vector2D_f(0.2, 0.2));

            _camera.render_Sprite(
                rect2,
                shader,
                _texture2,
                spell_crous
            );

            _camera.render_Text(
                text,
                shader
            );

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