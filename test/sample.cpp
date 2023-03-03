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

    DatabaseMetaData *dbmeta = conn->getMetaData();
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

static void show_resultset(ResultSet* res) {

    if (res->isClosed()) {
        throw std::runtime_error("Result closed.");
    }

    ResultSetMetaData *resmeta = res->getMetaData();
    unsigned int columns = resmeta->getColumnCount();
    while (res->next()) {
        for (int i = 1; i <= columns; i++) {
            cout << res->getString(i) << " ";
        }
        cout << endl;
    }
    cout << res->rowsCount() << " row(s) in set\n" << endl;
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
            0. instantiate a sql::Driver object
        */
        driver = get_driver_instance();

        /*
            1. connect to MySQL server by calling connect() method of driver,
               which holds 2 overloads as
                    connect(const sql::SQLString& hostName,
                            const sql::SQLString& userName,
                            const sql::SQLString& password)
               and
                    connect(ConnectOptionsMap & options)
               syntax of url is like "tcp://[hostName[:port]][/schemaName]"
               then, returns a sql::Connection object
        */
        conn = driver->connect(HOST, USER, PASSWORD);
        conn->setAutoCommit(0);

        /*
            2. choose the database schema if not being set when connecting
        */
        conn->setSchema("snooker");

        /*
            3. show database metadata via sql::DatabaseMetaData object
        */
        show_dbMetadata(conn);

        /*
            4. create sql::Statement object, which excludes parameters
               that is to say, it can only be used to execute static sql

               as for how to execute sql, there are 3 methods being supported
                    ResultSet * executeQuery(const sql::SQLString& sql)
               returns a sql::ResultSet object

                    int executeUpdate(const sql::SQLString& sql)
               returns sum of affected row(s)

                    bool execute(const sql::SQLString& sql)
               returns true  when executing query
                       false when executing insert、 delete、 update or SQL DDL
        */
        stmt = conn->createStatement();

        res = stmt->executeQuery(sqlStr);
        show_resMetadata(res);
        show_resultset(res);

        /*
            5. sql::PreparedStatement object, which extends from Statement class,
               compared to sql::Statement, its advantages embody as following:
               1) reduce SQL compile errors and enhance security(as: SQL injection)
               2) support precompiled SQL that allow accepting parameters
               3) based on 2, precompiled SQL would be cached by MySQL server, which
                  leads to rather faster efficiency for the reason that there is no
                  need to compile SQL again or generate the execution plans
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

        res = stmt->executeQuery(sqlStr);
        show_resMetadata(res);
        show_resultset(res);

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
