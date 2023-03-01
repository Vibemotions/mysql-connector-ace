#include <stdlib.h>
#include <iostream>


#include <cppconn/driver.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <cppconn/exception.h>

using std::cout;
using std::endl;
using namespace sql;

int test() {

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
       * Before this, C++ Programmer can only connect to MySQL server via non-standard,
       * procedural MySQL C API or MySQL++ API.
      */

    try {
        Driver *driver;
        Connection *conn;
        Statement *stmt;
        ResultSet *res;

        driver = get_driver_instance();
        conn = driver->connect("tcp://127.0.0.1", "root", "123456");
        conn->setSchema("snooker");

        stmt = conn->createStatement();
        res = stmt->executeQuery("select name, age from player");
        while (res->next()) {
            cout << res->getString(1) << " ";
            cout << res->getInt(2) << endl;
        }

        delete res;
        delete stmt;
        delete conn;
    }
    catch (SQLException &e)
    {
        cout << "# ERR: SQLException in " << __FILE__ << endl;
        cout << "# ERR: " << e.what();
        cout << "MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << endl;
    }

    return EXIT_SUCCESS;
}

int main() {
    test();
    return 0;
}
