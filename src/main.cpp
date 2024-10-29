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


/*
#include <cppconn/driver.h> 
#include <cppconn/exception.h> 
#include <cppconn/statement.h> 
#include <mysql_connection.h> 
#include <mysql_driver.h> 
*/

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



    /// MYSQL //
    /*
    try {
        sql::mysql::MySQL_Driver* driver;
        sql::Connection* con;
        sql::ConnectOptionsMap connection_properties;

        connection_properties["hostName"] = "localhost";
        connection_properties["userName"] = "root";
        connection_properties["password"] = "Eido_12_terial_78";
        connection_properties["schema"] = "eidor_0";
        connection_properties["port"] = 3306;
        connection_properties["OPT_RECONNECT"] = true;

        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect(connection_properties);

        con->setSchema("eidor_0"); // your database name

        sql::Statement* stmt;
        stmt = con->createStatement();

        // SQL query to retrieve data from the table
        std::string selectDataSQL = "SELECT * FROM `players_characteristics`";

        sql::ResultSet* res
            = stmt->executeQuery(selectDataSQL);

        // Loop through the result set and display data
        int count = 0;
        while (res->next()) {
            std::cout << " Player life " << ++count << ": "
                << res->getString("life_point_correct") << std::endl;
        }

        delete res;
        delete stmt;
        delete con;
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
        return 0;
    }
    */
    /// ////////////////////////////////////////////////

    GraphicResource grph_resource(
        "E:../src/assets/"
    );

    grph_resource.addGraphicResourceUnit(
        "Background/main_background_menu.jpg",
        3,
        Vector2D_f(128.0f, 128.0f),
        1
    );
    grph_resource.addGraphicResourceUnit(
        "Spell/icon_spell_croul.png",
        4,
        Vector2D_f(32.0f, 32.0f),
        1
    );
    grph_resource.addGraphicResourceUnit(
        "Button/button_in_menu.png",
        4,
        Vector2D_f(128.0f, 32.0f),
        1
    );

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
        &grph_interface.getGraphicResource()->getGraphicResourceUnit(1),
        Vector2D_f(100.0f, 100.0f),
        Vector2D_f(32.0f, 32.0f)
    );
    grph_interface.takeInterfaceUnit().addGraphicObjectUnit(
        &grph_interface.getGraphicResource()->getGraphicResourceUnit(2),
        Vector2D_f(250.0f, 100.0f),
        Vector2D_f(128.0f, 32.0f)
    );
    grph_interface.takeInterfaceUnit().addGraphicObjectUnit(
        &grph_interface.getGraphicResource()->getGraphicResourceUnit(2),
        Vector2D_f(250.0f, 300.0f),
        Vector2D_f(128.0f, 32.0f)
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

            _camera.renderGraphicInterface(shader, shader_bg);

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