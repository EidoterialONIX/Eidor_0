#pragma once


#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <mysql_connection.h>
#include <mysql_driver.h>

#include "interface.h"
#include "World.h"
#include "Player.h"


class DB {
private:
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* con;
    sql::ConnectOptionsMap connection_properties;

public:

    DB();

    void generateWorldVariable(GraphicInterface* grph_interface, Vector2D_f size);

    void generateWorld(World* world, GLuint id, Vector2D_f size);

    void playerDop(World* world, GLuint id, std::vector<GLuint>& players_id, GLuint player_id);

    void generatePlayerVariable(GraphicInterface* grph_interface, Vector2D_f size);

    void generatePlayer(World* world, Player* player, GLuint id);

    void playerMove(Vector2D_f position, GLuint id);

    void updatePlayer(World* world, GLuint id, std::vector<GLuint>& player_id);

    void playerDisconect(GLuint player_id);

};
