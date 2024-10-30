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
#include "interface.h"
#include "GraphicResource.h"
#include "World.h"

#include "DBM.h"

#include <iostream>


struct Option {

    int WINDOW_SIZE[2] = { 640, 480 };
    double CURSOR_POSITION[2] = { 0.0f, 0.0f };

};

Option _option;
GraphicInterface* ptr_grph_interface;
Player* ptr_player;
World* ptr_world;
Collision collision;
DB* ptr_DB;

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
    else if (key == GLFW_KEY_D && action == GLFW_PRESS) {
        ptr_player->changeVelosity(Vector2D_f(ptr_player->getSpeed(), 0.0f));
    }
    else if (key == GLFW_KEY_A && action == GLFW_PRESS) {
        ptr_player->changeVelosity(Vector2D_f(-ptr_player->getSpeed(), 0.0f));
    }
    else if (key == GLFW_KEY_W && action == GLFW_PRESS) {
        ptr_player->changeVelosity(Vector2D_f(0.0f, -ptr_player->getSpeed()));
    }
    else if (key == GLFW_KEY_S && action == GLFW_PRESS) {
        ptr_player->changeVelosity(Vector2D_f(0.0f, ptr_player->getSpeed()));
    }

    else if (key == GLFW_KEY_D && action == GLFW_RELEASE) {
        ptr_player->changeVelosity(Vector2D_f(0.0f, 0.0f));
    }
    else if (key == GLFW_KEY_A && action == GLFW_RELEASE) {
        ptr_player->changeVelosity(Vector2D_f(0.0f, 0.0f));
    }
    else if (key == GLFW_KEY_W && action == GLFW_RELEASE) {
        ptr_player->changeVelosity(Vector2D_f(0.0f, 0.0f));
    }
    else if (key == GLFW_KEY_S && action == GLFW_RELEASE) {
        ptr_player->changeVelosity(Vector2D_f(0.0f, 0.0f));
    }
}

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
    glfwGetCursorPos(window, &_option.CURSOR_POSITION[0], &_option.CURSOR_POSITION[1]);

}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {

    /// Main menu 
    if (ptr_grph_interface->getActiveInterfaceUnit() == 0) {
        if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
            for (int i{ 0 }; i < ptr_grph_interface->takeInterfaceUnit().pullGraphicObjectUnit().size(); i++) {

                if (i == 0) {
                    if (collision.check_Interface_Collision(
                        ptr_grph_interface->takeInterfaceUnit().pullGraphicObjectUnit()[i].cl_graphic_unit.get_Position(),
                        ptr_grph_interface->takeInterfaceUnit().pullGraphicObjectUnit()[i].cl_graphic_unit.get_Size(),
                        _option.CURSOR_POSITION[0],
                        _option.CURSOR_POSITION[1]
                    )) {
                        ptr_grph_interface->changeActiveInterfaceUnit(1);

                        ptr_world->setWorldBackgroundUnit(
                            &ptr_world->getGraphicResource()->getGraphicResourceUnit(0),
                            Vector2D_f(_option.WINDOW_SIZE[0], _option.WINDOW_SIZE[1]),
                            Vector2D_f(_option.WINDOW_SIZE[0] / 128.0f, _option.WINDOW_SIZE[1] / 128.0f)
                        );
                        ptr_world->addWorldObjectUnit(
                            &ptr_world->getGraphicResource()->getGraphicResourceUnit(2),
                            ptr_player->getBody().get_Position(),
                            ptr_player->getBody().get_Size()
                        );
                    }
                }
                else if (i == 1) {
                    if (collision.check_Interface_Collision(
                        ptr_grph_interface->takeInterfaceUnit().pullGraphicObjectUnit()[i].cl_graphic_unit.get_Position(),
                        ptr_grph_interface->takeInterfaceUnit().pullGraphicObjectUnit()[i].cl_graphic_unit.get_Size(),
                        _option.CURSOR_POSITION[0],
                        _option.CURSOR_POSITION[1]
                    )) {
                        ptr_grph_interface->changeActiveInterfaceUnit(2);
                    }
                }
                

            }
        }

    }
    else if (ptr_grph_interface->getActiveInterfaceUnit() == 2) {
        for (int i{ 0 }; i < ptr_grph_interface->takeInterfaceUnit().pullGraphicObjectUnit().size(); i++) {


            if (collision.check_Interface_Collision(
                ptr_grph_interface->takeInterfaceUnit().pullGraphicObjectUnit()[i].cl_graphic_unit.get_Position(),
                ptr_grph_interface->takeInterfaceUnit().pullGraphicObjectUnit()[i].cl_graphic_unit.get_Size(),
                _option.CURSOR_POSITION[0],
                _option.CURSOR_POSITION[1]
            )) {
                ptr_DB->generateWorld(ptr_world, i, Vector2D_f(_option.WINDOW_SIZE[0], _option.WINDOW_SIZE[1]));
                ptr_grph_interface->changeActiveInterfaceUnit(3);
                
            }

        }

    }
    else if (ptr_grph_interface->getActiveInterfaceUnit() == 3) {
        for (int i{ 0 }; i < ptr_grph_interface->takeInterfaceUnit().pullGraphicObjectUnit().size(); i++) {

            if (collision.check_Interface_Collision(
                ptr_grph_interface->takeInterfaceUnit().pullGraphicObjectUnit()[i].cl_graphic_unit.get_Position(),
                ptr_grph_interface->takeInterfaceUnit().pullGraphicObjectUnit()[i].cl_graphic_unit.get_Size(),
                _option.CURSOR_POSITION[0],
                _option.CURSOR_POSITION[1]
            )) {
               ptr_DB->generatePlayer(ptr_world, ptr_player, i);
               ptr_grph_interface->changeActiveInterfaceUnit(1);

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

    DB db;
    ptr_DB = &db;

    /// Interface ////////////////////
    //////////////////////////////////////////////////////
    //////////////////////////////////////////////////////
    GraphicResource grph_resource(
        "E:../src/assets/"
    );

    grph_resource.loadFont(
        "Font/Font_EAGL.png",
        Vector2D_f(1184.0f, 16.0f),
        Vector2D_f(16.0f, 16.0f)
    );

    grph_resource.addGraphicResourceUnit(
        "Background/main_background_menu.jpg",
        3,
        Vector2D_f(128.0f, 128.0f),
        1
    ); // 0
    grph_resource.addGraphicResourceUnit(
        "Spell/icon_spell_croul.png",
        4,
        Vector2D_f(32.0f, 32.0f),
        1
    ); // 1
    grph_resource.addGraphicResourceUnit(
        "Button/button_in_menu.png",
        4,
        Vector2D_f(128.0f, 32.0f),
        1
    ); // 2
    grph_resource.addGraphicResourceUnit(
        "Game_Interface/action_panel.png",
        4,
        Vector2D_f(256.0f, 32.0f),
        1
    ); // 3
    grph_resource.addGraphicResourceUnit(
        "Game_Interface/life_bar.png",
        4,
        Vector2D_f(128.0f, 16.0f),
        1
    ); // 4
    grph_resource.addGraphicResourceUnit(
        "Game_Interface/mana_bar.png",
        4,
        Vector2D_f(128.0f, 16.0f),
        1
    ); // 5
    grph_resource.addGraphicResourceUnit(
        "Game_Interface/energi_bar.png",
        4,
        Vector2D_f(128.0f, 16.0f),
        1
    ); // 6

    GraphicInterface grph_interface(
        &grph_resource
    );

    grph_interface.addNewInterfaceUnit();

    grph_interface.takeInterfaceUnit().setGraphicBackgroundUnit(
        &grph_interface.getGraphicResource()->getGraphicResourceUnit(0),
        Vector2D_f(_option.WINDOW_SIZE[0], _option.WINDOW_SIZE[1]),
        Vector2D_f(_option.WINDOW_SIZE[0] / 128.0f, _option.WINDOW_SIZE[1] / 128.0f)
    );
    grph_interface.takeInterfaceUnit().addGraphicObjectUnit(
        &grph_interface.getGraphicResource()->getGraphicResourceUnit(2),
        Vector2D_f(250.0f, 100.0f),
        Vector2D_f(210.0f, 32.0f),
        grph_interface.getGraphicResource()->getFont()
    );
    grph_interface.takeInterfaceUnit().addGraphicObjectUnit(
        &grph_interface.getGraphicResource()->getGraphicResourceUnit(2),
        Vector2D_f(250.0f, 300.0f),
        Vector2D_f(210.0f, 32.0f),
        grph_interface.getGraphicResource()->getFont()
    );
    grph_interface.takeInterfaceUnit().setTextfromGraphicObjectUnit(
        0,
        "Single Play",
        Vector2D_f(270.0f, 110.0f),
        16.0f
    );
    grph_interface.takeInterfaceUnit().setTextfromGraphicObjectUnit(
        1,
        "Online Play",
        Vector2D_f(270.0f, 310.0f),
        16.0f
    );

    grph_interface.addNewInterfaceUnit();
    grph_interface.changeActiveInterfaceUnit(1);
    grph_interface.takeInterfaceUnit().setGraphicBackgroundUnit(
        &grph_interface.getGraphicResource()->getGraphicResourceUnit(0),
        Vector2D_f(0.0f, 0.0f),
        Vector2D_f(1.0f, 1.0f)
    );
    grph_interface.takeInterfaceUnit().addGraphicObjectUnit(
        &grph_interface.getGraphicResource()->getGraphicResourceUnit(3),
        Vector2D_f(190.0f, 450.0f),
        Vector2D_f(256.0f, 32.0f),
        grph_interface.getGraphicResource()->getFont()
    );
    grph_interface.takeInterfaceUnit().addGraphicObjectUnit(
        &grph_interface.getGraphicResource()->getGraphicResourceUnit(4),
        Vector2D_f(100.0f, 430.0f),
        Vector2D_f(128.0f, 16.0f),
        grph_interface.getGraphicResource()->getFont()
    );
    grph_interface.takeInterfaceUnit().addGraphicObjectUnit(
        &grph_interface.getGraphicResource()->getGraphicResourceUnit(5),
        Vector2D_f(250.0f, 430.0f),
        Vector2D_f(128.0f, 16.0f),
        grph_interface.getGraphicResource()->getFont()
    );
    grph_interface.takeInterfaceUnit().addGraphicObjectUnit(
        &grph_interface.getGraphicResource()->getGraphicResourceUnit(6),
        Vector2D_f(400.0f, 430.0f),
        Vector2D_f(128.0f, 16.0f),
        grph_interface.getGraphicResource()->getFont()
    );
    grph_interface.changeActiveInterfaceUnit(0);


    grph_interface.addNewInterfaceUnit();
    grph_interface.changeActiveInterfaceUnit(2);
    db.generateWorldVariable(&grph_interface, Vector2D_f(_option.WINDOW_SIZE[0], _option.WINDOW_SIZE[1]));

    grph_interface.addNewInterfaceUnit();
    grph_interface.changeActiveInterfaceUnit(3);
    db.generatePlayerVariable(&grph_interface, Vector2D_f(_option.WINDOW_SIZE[0], _option.WINDOW_SIZE[1]));

    grph_interface.changeActiveInterfaceUnit(0);

    ptr_grph_interface = &grph_interface;
    //////////////////////////////////////////////////////
    //////////////////////////////////////////////////////

     /// World ////////////////////
    //////////////////////////////////////////////////////
    //////////////////////////////////////////////////////

    Player player;
    ptr_player = &player;
    Structure rock;

    rock.createStructure(
        Vector2D_f(100.0f, 100.0f),
        1
    );

    player.createPlayer(
        Vector2D_f(100.0f, 100.0f), Characteristic()
    );

    GraphicResource grph_resource_world(
        "E:../src/assets/"
    );
    grph_resource_world.addGraphicResourceUnit(
        "Background/main_background_game.jpg",
        3,
        Vector2D_f(128.0f, 128.0f),
        1
    );
    grph_resource_world.addGraphicResourceUnit(
        "Struct/rock.png",
        4,
        Vector2D_f(128.0f, 128.0f),
        1
    );
    grph_resource_world.addGraphicResourceUnit(
        "Player/player.png",
        4,
        Vector2D_f(64.0f, 64.0f),
        1
    );

    World world(
        &grph_resource_world
    );

    ptr_world = &world;

    world.setWorldBackgroundUnit(
        &world.getGraphicResource()->getGraphicResourceUnit(0),
        Vector2D_f(_option.WINDOW_SIZE[0], _option.WINDOW_SIZE[1]),
        Vector2D_f(_option.WINDOW_SIZE[0] / 128.0f, _option.WINDOW_SIZE[1] / 128.0f)
    );



    ///  Shader /////////////////////////////////////////////////////
    Shader_Program shader(
        "E:/C++ projects/Eidor_0/Shaders/Basic_Shader/Vertex.txt",
        "E:/C++ projects/Eidor_0/Shaders/Basic_Shader/Fragment.txt"
    );

    Shader_Program shader_bg(
        "E:/C++ projects/Eidor_0/Shaders/Background_Shader/Vertex.txt",
        "E:/C++ projects/Eidor_0/Shaders/Background_Shader/Fragment.txt"
    );
    /// /////////////////////////////////////////////////////////////
 

    Render _render(Vector2D_f(_option.WINDOW_SIZE[0], _option.WINDOW_SIZE[1]));
    Time _time;

    Camera _camera(
        &world,
        &grph_interface,
        &_render,
        &_time,
        Vector2D_f(_option.WINDOW_SIZE[0], _option.WINDOW_SIZE[1]),
        Vector2D_f(3000.0f, 5000.0f)
    );

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



            /// Hunt error ///////////////////////////////////
            GLenum err;
            while ((err = glGetError()) != GL_NO_ERROR) {
                std::cout << "OpenGL error: " << err << std::endl;
            }
            /// ///////////////////////////////////////////////

            _time.increment_Frames();

            /* Render here */
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


            if (grph_interface.getActiveInterfaceUnit() == 1) {

                _camera.renderWorld(shader, shader_bg);
                player.movePlayer();
                world.updateDinamicObjectUnit(
                    world.pullWorldObjectUnit().size() - 1,
                    player.getBody().get_Position()
                );

                _camera.renderGraphicInterface(shader, shader_bg);

                db.playerMove(player.getBody().get_Position(), 0);
            }
            else {
                _camera.renderGraphicInterface(shader, shader_bg);
            }
            

            /* Swap front and back buffers */
            glfwSwapBuffers(pWindow);

            /* Poll for and process events */
            glfwPollEvents();
            

        }

        if (glfwGetTime() - _time.get_Timer() >= 1.0f) {
            _time.increment_Timer();

            
            std::cout
                << "FPS: "
                << _time.get_Frames()
                << " Updates: "
                << _time.get_Updates()
                << " Timer: "
                << _time.get_Timer()
                << std::endl;
            
            
            std::cout
                << "Now time: "
                << _time.get_Now_Time()
                << " Last time: "
                << _time.get_Last_Time()
                << " Delta time: "
                << _time.get_Delta_Time()
                << std::endl;
            
            _time.reset_Frames();
            _time.reset_Updates();

        }

    }

    glfwTerminate();
    return 0;
}