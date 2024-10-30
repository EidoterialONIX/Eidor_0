#pragma once

/*
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <mysql_connection.h>
#include <mysql_driver.h>
*/

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
