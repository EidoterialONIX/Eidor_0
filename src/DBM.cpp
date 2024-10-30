#include "DBM.h"



DB::DB() {
    try {

        this->connection_properties["hostName"] = "localhost";
        this->connection_properties["userName"] = "root";
        this->connection_properties["password"] = "Eido_12_terial_78";
        this->connection_properties["schema"] = "eidor_0";
        this->connection_properties["port"] = 3306;
        this->connection_properties["OPT_RECONNECT"] = true;

        this->driver = sql::mysql::get_mysql_driver_instance();
        this->con = driver->connect(connection_properties);

        con->setSchema("eidor_0"); // your database name

    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }
    
}

void DB::generateWorldVariable(GraphicInterface* grph_interface, Vector2D_f size) {

    try {
        sql::Statement* stmt;
        stmt = this->con->createStatement();

        // SQL query to retrieve data from the table
        std::string selectDataSQL = "SELECT * FROM `worlds`";

        sql::ResultSet* res
            = stmt->executeQuery(selectDataSQL);

        grph_interface->takeInterfaceUnit().setGraphicBackgroundUnit(
            &grph_interface->getGraphicResource()->getGraphicResourceUnit(0),
            Vector2D_f(size.x, size.y),
            Vector2D_f(size.x / 128.0f, size.y / 128.0f)
        );

        int count_x = 0;
        int count_y = 0;
        while (res->next()) {


           
            grph_interface->takeInterfaceUnit().addGraphicObjectUnit(
                &grph_interface->getGraphicResource()->getGraphicResourceUnit(2),
                Vector2D_f(0.0f * count_x, 100.0f * count_y),
                Vector2D_f(128.0f, 32.0f),
                grph_interface->getGraphicResource()->getFont()
            );
            grph_interface->takeInterfaceUnit().setTextfromGraphicObjectUnit(
                count_y,
                "World " + res->getString("world_id_key"),
                Vector2D_f(130.0f * count_x + 10.0f, 100.0f * count_y + 8),
                16.0f
            );


            count_y++;
        }

        delete res;
        delete stmt;
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }
    

}

void DB::generateWorld(World* world, GLuint id, Vector2D_f size) {

    try {
        sql::Statement* stmt;
        stmt = this->con->createStatement();

        // SQL query to retrieve data from the table
        std::string selectDataSQL = "SELECT * FROM `worlds` inner join `worlds_object` on `worlds`.`world_id_key` = `worlds_object`.`world_id_key` where `worlds`.`world_id_key` = ";
        selectDataSQL += std::to_string(id + 1);

        sql::ResultSet* res
            = stmt->executeQuery(selectDataSQL);

        world->setWorldBackgroundUnit(
            &world->getGraphicResource()->getGraphicResourceUnit(0),
            Vector2D_f(size.x, size.y),
            Vector2D_f(size.x / 128.0f, size.y / 128.0f)
        );

        while (res->next()) {

            world->addWorldObjectUnit(
                &world->getGraphicResource()->getGraphicResourceUnit(1),
                Vector2D_f(std::stoi(res->getString("position_axisX")), std::stoi(res->getString("position_axisY"))),
                Vector2D_f(64.0f, 64.0f)
            );
        }   

        delete res;
        delete stmt;
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }

}

void DB::playerDop(World* world, GLuint id, std::vector<GLuint>& players_id, GLuint player_id) {
    try {
        sql::Statement* stmt;
        stmt = this->con->createStatement();

        // SQL query to retrieve data from the table
       

        std::string selectDataSQL = "Select * from `worlds_players` where `world_id_key` = ";
        selectDataSQL += std::to_string(id + 1);
        
        sql::ResultSet* res
            = stmt->executeQuery(selectDataSQL);


        if (players_id.size() == 0) {
            while (res->next()) {

                selectDataSQL = "Select * from `players` where `player_id_key` = ";
                selectDataSQL += res->getString("player_id_key");

                sql::ResultSet* res2
                    = stmt->executeQuery(selectDataSQL);

                while (res2->next()) {

                    if (std::stoi(res->getString("player_id_key")) == player_id + 1) continue;

                    if (std::stoi(res2->getString("player_status"))) {
                        players_id.resize(players_id.size() + 1);
                        players_id[players_id.size() - 1] = std::stoi(res->getString("player_id_key"));

                        world->addWorldObjectUnit(
                            &world->getGraphicResource()->getGraphicResourceUnit(2),
                            Vector2D_f(std::stoi(res2->getString("position_axisX")), std::stoi(res2->getString("position_axisY"))),
                            Vector2D_f(32.0f, 32.0f)
                        );

                    }

                }

                delete res2;

            }

        }
        else {

            int count = 0;

            while (res->next()) {

                selectDataSQL = "Select * from `players` where `player_id_key` = ";
                selectDataSQL += res->getString("player_id_key");

                sql::ResultSet* res2
                    = stmt->executeQuery(selectDataSQL);

                while (res2->next()) {

                    if (count > players_id.size()) {

                        if (std::stoi(res2->getString("player_status"))) {
                            players_id.resize(players_id.size() + 1);
                            players_id[players_id.size() - 1] = std::stoi(res->getString("player_id_key"));

                            world->addWorldObjectUnit(
                                &world->getGraphicResource()->getGraphicResourceUnit(2),
                                Vector2D_f(std::stoi(res2->getString("position_axisX")), std::stoi(res2->getString("position_axisY"))),
                                Vector2D_f(32.0f, 32.0f)
                            );

                        }

                    }
                    count++;

                }

                delete res2;

            }

        }
       


        delete res;
        delete stmt;
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }

}

void DB::generatePlayerVariable(GraphicInterface* grph_interface, Vector2D_f size) {

    try {
        sql::Statement* stmt;
        stmt = this->con->createStatement();

        // SQL query to retrieve data from the table
        std::string selectDataSQL = "SELECT * FROM `players`";

        sql::ResultSet* res
            = stmt->executeQuery(selectDataSQL);

        grph_interface->takeInterfaceUnit().setGraphicBackgroundUnit(
            &grph_interface->getGraphicResource()->getGraphicResourceUnit(0),
            Vector2D_f(size.x, size.y),
            Vector2D_f(size.x / 128.0f, size.y / 128.0f)
        );

        int count_x = 1;
        int count_y = 0;
        while (res->next()) {

            grph_interface->takeInterfaceUnit().addGraphicObjectUnit(
                &grph_interface->getGraphicResource()->getGraphicResourceUnit(2),
                Vector2D_f(400.0f * count_x, 100.0f * count_y),
                Vector2D_f(140.0f, 32.0f),
                grph_interface->getGraphicResource()->getFont()
            );
            grph_interface->takeInterfaceUnit().setTextfromGraphicObjectUnit(
                count_y,
                "Player " + res->getString("player_id_key"),
                Vector2D_f(400.0f * count_x + 10.0f, 100.0f * count_y + 8),
                16.0f
            );


            count_y++;
        }

        std::cout << 10 << std::endl;

        delete res;
        delete stmt;
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }


}

void DB::generatePlayer(World* world, Player* player, GLuint id) {

    try {
        sql::Statement* stmt;
        stmt = this->con->createStatement();

        // SQL query to retrieve data from the table
        std::string selectDataSQL = "SELECT * FROM `players` inner join `players_characteristics` on `players`.`player_id_key` = `players_characteristics`.`player_id_key` where `players`.`player_id_key` = ";
        selectDataSQL += std::to_string(id + 1);
        sql::ResultSet* res
            = stmt->executeQuery(selectDataSQL);

        std::string updatePlayerStatus = "Update `players` set `player_status` = 1 where `player_id_key` = ";
        updatePlayerStatus += std::to_string(id + 1);

        stmt->execute(updatePlayerStatus);

        this->con->commit();

        while (res->next()) {

            player->setPosition(Vector2D_f(std::stoi(res->getString("position_axisX")), std::stoi(res->getString("position_axisY"))));
            world->addWorldObjectUnit(
                &world->getGraphicResource()->getGraphicResourceUnit(2),
                Vector2D_f(std::stoi(res->getString("position_axisX")), std::stoi(res->getString("position_axisY"))),
                Vector2D_f(32.0f, 32.0f)
            );

        }

        delete res;
        delete stmt;
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }

}

void DB::playerMove(Vector2D_f position, GLuint id) {

    try {
        sql::Statement* stmt;
        stmt = this->con->createStatement();

        // SQL query to retrieve data from the table

        std::string updatePlayerStatus = "Update `players` set `position_axisX` = ";
        updatePlayerStatus += std::to_string(position.x);
        updatePlayerStatus += ", `position_axisY` = ";
        updatePlayerStatus += std::to_string(position.y);
        updatePlayerStatus += " where `player_id_key` = ";
        updatePlayerStatus += std::to_string(id + 1);

        stmt->execute(updatePlayerStatus);

        this->con->commit();

        delete stmt;
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }


}

void DB::updatePlayer(World* world, GLuint id, std::vector<GLuint>& player_id) {

    try {
        sql::Statement* stmt;
        stmt = this->con->createStatement();

        // SQL query to retrieve data from the table
        std::string selectDataSQL = "Select * from `worlds_players` where `world_id_key` = ";
        selectDataSQL += std::to_string(id + 1);
        sql::ResultSet* res
            = stmt->executeQuery(selectDataSQL);

        while (res->next()) {


            selectDataSQL = "Select * from `players` where `player_id_key` = ";
            selectDataSQL += res->getString("player_id_key");

            sql::ResultSet* res2
                = stmt->executeQuery(selectDataSQL);

            int count = 0;
            while (res2->next()) {
                
                world->updateDinamicObjectUnit(
                    world->pullWorldObjectUnit().size() - (player_id.size() + count),
                    Vector2D_f(std::stoi(res2->getString("position_axisX")), std::stoi(res2->getString("position_axisY")))
                );

                count++;

            }

            delete res2;

        }

        delete res;
        delete stmt;
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }


}

void DB::playerDisconect(GLuint player_id) {

    try {
        sql::Statement* stmt;
        stmt = this->con->createStatement();

        // SQL query to retrieve data from the table

        std::string updatePlayerStatus = "Update `players` set `player_status` = 0 where `player_id_key` = ";
        updatePlayerStatus += std::to_string(player_id + 1);

        stmt->execute(updatePlayerStatus);

        this->con->commit();

        delete stmt;
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }


}