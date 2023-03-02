#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cppconn/driver.h>
#include <cppconn/connection.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <cppconn/metadata.h>
#include <cppconn/resultset_metadata.h>
#include <cppconn/exception.h>

using std::cout;
using std::endl;
using namespace sql;

#define HOST "tcp://127.0.0.1:3306"
#define USER "root"
#define PASSWORD "123456"
const char *sqlStr = "select * from player where age < 30 order by age";

/* Interface of Connector/C++ is mainly based on JDBC, which implements classes:
 *
 * Driver
 * Connection
 * Statement
 * PreparedStatement
 * ResultSet
 * Savepoint
 * DatabaseMetaData
 * ResultSetMetaData
 * ParameterMetaData
 *
 * Before this, C++ Programmer can only connect to MySQL server via
 * non-standard, procedural MySQL C API or MySQL++ API.
 */

static void show_dbMetadata(Connection* conn) {

    if (conn->isClosed()) {
      throw std::runtime_error("Database connection closed.");
    }

    DatabaseMetaData *dbmeta;
    dbmeta = conn->getMetaData();
    cout << "database: " << dbmeta->getDatabaseProductName() << " "
                         << dbmeta->getDatabaseProductVersion() << endl;
    cout << "driver: " << dbmeta->getDriverName() << " "
                       << dbmeta->getDriverVersion() << endl;
    cout << "user: " << dbmeta->getUserName() << endl;
    cout << "max connections: " << dbmeta->getMaxConnections() << endl << endl;
}

static void show_resMetadata(ResultSet* res) {

    if (res->isClosed()) {
        throw std::runtime_error("ResultSet closed.");
    }

    ResultSetMetaData *resmeta = res->getMetaData();
    resmeta = res->getMetaData();
    cout << "table: " << resmeta->getSchemaName(1) << "."
                      << resmeta->getTableName(1) << endl;
    unsigned int columns = resmeta->getColumnCount();
    cout << "total columns: " << columns << endl;
    int i = 1;
    while (i <= columns) {
        cout << i << ": "
             << resmeta->getColumnName(i) << " "
             << resmeta->getColumnTypeName(i++) << endl;
    }
    cout << endl;
}

int test() {

    try {
        Driver *driver;
        Connection *conn;
        Statement *stmt;
        PreparedStatement *prestmt;
        ResultSet *res;
        Savepoint *savept;

        /*
            0. instantiate a Driver object
        */
        driver = get_driver_instance();

        /*
            1. connect to MySQL server by call connect() method of driver, 
               which holds 2 overloads as
               connect(const sql::SQLString& hostName,
                       const sql::SQLString& userName,
                       const sql::SQLString& password)
               and
               connect(ConnectOptionsMap & options)
        */
        conn = driver->connect(HOST, USER, PASSWORD);
        conn->setAutoCommit(0);

        /*
            2. choose the database schema, narrowly
               that is to say, the name of database
        */
        conn->setSchema("snooker");

        /*
            3. show database metadata via DatabaseMetaData object
        */
        show_dbMetadata(conn);

        /*
            4. execute sql using Statement
        */
        stmt = conn->createStatement();
        res = stmt->executeQuery(sqlStr);
        while (res->next()) {
            cout << res->getString("name") << " ";
            cout << res->getString("age") << endl;
        }
        cout << res->rowsCount() << " row(s) in set\n" << endl;
        show_resMetadata(res);

        /*
            5. execute sql using PreparedStatement, which extends from Statement
               class, supporting precompiled sql that allows accepting parameters
               so it is faster than plain Statement when interacting with server
        */
        prestmt = conn->prepareStatement("insert into player values (?, ?)");
        prestmt->setString(1, "Ma Hailong");
        prestmt->setInt(2, 18);
        prestmt->executeUpdate();

        /*
            6. set savepoint via setSavepoint method, which can be used for rollback
               note that space is forbidden inner the name of savepoint, or it will
               raise SQLException (MySQL error code: 1064, SQLState: 42000)
        */
        savept = conn->setSavepoint("savept_1");

        prestmt->setString(1, "test Player");
        prestmt->setInt(2, 6);
        prestmt->executeUpdate();

        /*
            7. rollback to the predefined savepoint savept_1, then the "test Player 6"
               is invisible in the result set of the sql query below
        */
        conn->rollback(savept);
        conn->releaseSavepoint(savept);

        prestmt = conn->prepareStatement(sqlStr);
        res = prestmt->executeQuery();
        while (res->next()) {
            cout << res->getString("name") << " ";
            cout << res->getInt("age") << endl;
        }
        cout << res->rowsCount() << " row(s) in set\n" << endl;

        delete res;
        delete prestmt;
        delete stmt;
        conn->close();
        delete conn;

    } catch (SQLException &e) {

        cout << "ERROR: SQLException in " << __FILE__;
        cout << " (" << __func__ << ") on line " << __LINE__ << endl;
        cout << "ERROR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << ")" << endl;
        return EXIT_FAILURE;

    } catch (std::runtime_error &e) {

        cout << "ERROR: runtime_error in " << __FILE__;
        cout << " (" << __func__ << ") on line " << __LINE__ << endl;
        cout << "ERROR: " << e.what() << endl;
        return EXIT_FAILURE;

    }

    return EXIT_SUCCESS;
}

int main() {
    test();
    return 0;
}
