#include <iostream>
#include <occiControl.h>

int main() {

    oracle::occi::Environment *environment = oracle::occi::Environment::createEnvironment(
            oracle::occi::Environment::DEFAULT);


    const std::string &username = "SYSTEM";
    const std::string &password = "root3358";
    const std::string& connectionString = "//localhost:1521/XE";
    //const std::string &connectionString = "(DESCRIPTION=(ADDRESS=(PROTOCOL=TCP)(HOST=127.0.0.1)(PORT=1521))(CONNECT_DATA=(SERVER=DEDICATED)(SERVICE_NAME=XE)))";
    oracle::occi::Connection *connection = environment->createConnection(username, password, connectionString);

    oracle::occi::Statement *statement = connection->createStatement("SELECT * FROM DBA_TABLES");
    oracle::occi::ResultSet *resultSet = statement->executeQuery();

    while (resultSet->next()) {
        std::string owner = resultSet->getString(1);
        std::string table_name = resultSet->getString(2);

        std::cout << owner << " " << table_name << std::endl;
    }

    environment->terminateConnection(connection);
    oracle::occi::Environment::terminateEnvironment(environment);

    return 0;
}
