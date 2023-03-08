#include <iostream>
#include <mysqlx/xdevapi.h>

using std::cout;
using std::endl;
using std::vector;
using namespace mysqlx;

void test() {

    cout << "creating session..." << endl;

    try {
        SessionSettings option("127.0.0.1",
                               33060,
                               "root",
                               "123456");
        Session sess(option);
        cout << "Done!" << endl;
        cout << "Session has been established, creating collection..." << endl;
        sess.sql("use snooker").execute();

        RowResult res = sess.sql("select name, age from player").execute();
        for (auto it = res.begin(); it != res.end(); ++it) {
            cout << (*it).get(0).get<string>() << " ";
            cout << (*it).get(1).get<int>() << " ";
            cout << endl;
        }
    } catch (const Error& e) {
        cout << e.what() << endl;
    }
}

int main() {
    test();
    return 0;
}
