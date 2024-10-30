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
                Vector2D_f(130.0f * count_x, 100.0f * count_y),
                Vector2D_f(128.0f, 32.0f),
                grph_interface->getGraphicResource()->getFont()
            );
            grph_interface->takeInterfaceUnit().setTextfromGraphicObjectUnit(
                count_x + (count_y * 3),
                "World " + res->getString("world_id_key"),
                Vector2D_f(130.0f * count_x + 10.0f, 100.0f * count_y + 8),
                16.0f
            );

            if (count_x == 2) {
                count_x = 0;
                count_y++;
            }
            else {
                count_x++;
            }
            
            //std::cout << " World " << ++count << ": "
            //   << res->getString("size_axisX") << std::endl;
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

        std::cout << selectDataSQL;

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
            //std::cout << " World " << ++count << ": "
            //   << res->getString("size_axisX") << std::endl;
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

        int count_x = 0;
        int count_y = 0;
        while (res->next()) {

            grph_interface->takeInterfaceUnit().addGraphicObjectUnit(
                &grph_interface->getGraphicResource()->getGraphicResourceUnit(2),
                Vector2D_f(170.0f * count_x, 100.0f * count_y),
                Vector2D_f(140.0f, 32.0f),
                grph_interface->getGraphicResource()->getFont()
            );
            grph_interface->takeInterfaceUnit().setTextfromGraphicObjectUnit(
                count_x + (count_y * 3),
                "Player " + res->getString("player_id_key"),
                Vector2D_f(170.0f * count_x + 10.0f, 100.0f * count_y + 8),
                16.0f
            );

            if (count_x == 2) {
                count_x = 0;
                count_y++;
            }
            else {
                count_x++;
            }

            //std::cout << " World " << ++count << ": "
            //   << res->getString("size_axisX") << std::endl;
        }

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

        std::string updatePlayerStatus = "Update `players` set `player_status` = 0 where `player_id_key` = ";
        updatePlayerStatus += std::to_string(id + 1);

        stmt->execute(updatePlayerStatus);

        this->con->commit();

        while (res->next()) {

            player->setPosition(Vector2D_f(std::stoi(res->getString("position_axisX")), std::stoi(res->getString("position_axisY"))));
            world->addWorldObjectUnit(
                &world->getGraphicResource()->getGraphicResourceUnit(1),
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
