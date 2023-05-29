#include "mysql_conn.h"
#include "connection_pool.h"
#include <iostream>
#include <thread>
#include <memory>

using namespace std;

// 1. single-thread
// 2. multi-thread

void op1(int begin, int end) {
    for (int i = begin; i < end; ++i) {
        MysqlConn conn;
        conn.connect("root", "root", "snooker", "192.168.80.30");
        char sql[1024] = {0};
        sprintf(sql, "insert into player values(%d, 28, 'Belgium', 'Luca Brecel')", i);
        conn.update(sql);
    }
}

void op2(ConnectionPool *pool, int begin, int end) {
    for (int i = begin; i < end; ++i) {
        shared_ptr<MysqlConn> conn = pool->getConnection();
        char sql[1024] = {0};
        sprintf(sql, "insert into player values(%d, 39, 'England', 'Mark Selby')", i);
        conn->update(sql);
    }
}

void test1() {
#if 1
    // single-thread, consume : 21037278300 ns, 21037 ms
    steady_clock::time_point begin = steady_clock::now();
    op1(0, 5000);
    steady_clock::time_point end = steady_clock::now();
    auto length = end - begin;
    cout << "single-thread, consume : " << length.count() << " ns, " << length.count() / 1000000 << " ms" << endl;
#else
    // single-thread with pool, consume : 8838406500 ns, 8838 ms
    ConnectionPool *pool = ConnectionPool::getConnectPool();
    steady_clock::time_point begin = steady_clock::now();
    op2(pool, 0, 5000);
    steady_clock::time_point end = steady_clock::now();
    auto length = end - begin;
    cout << "single-thread with pool, consume : " << length.count() << " ns, " << length.count() / 1000000 << " ms" << endl;
#endif
}

void test2() {
#if 0
    // multi-thread, consume : 13277417000 ns, 13277 ms
    MysqlConn conn;
    conn.connect("root", "root", "snooker", "192.168.80.30");
    steady_clock::time_point begin = steady_clock::now();
    thread t1(op1, 0, 1000);
    thread t2(op1, 1000, 2000);
    thread t3(op1, 2000, 3000);
    thread t4(op1, 3000, 4000);
    thread t5(op1, 4000, 5000);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    steady_clock::time_point end = steady_clock::now();
    auto length = end - begin;
    cout << "multi-thread, consume : " << length.count() << " ns, " << length.count() / 1000000 << " ms" << endl;

#else
    // multi-thread with pool, consume : 3938502100 ns, 3938 ms
    ConnectionPool *pool = ConnectionPool::getConnectPool();
    steady_clock::time_point begin = steady_clock::now();
    thread t1(op2, pool, 0, 1000);
    thread t2(op2, pool, 1000, 2000);
    thread t3(op2, pool, 2000, 3000);
    thread t4(op2, pool, 3000, 4000);
    thread t5(op2, pool, 4000, 5000);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    steady_clock::time_point end = steady_clock::now();
    auto length = end - begin;
    cout << "multi-thread with pool, consume : " << length.count() << " ns, " << length.count() / 1000000 << " ms" << endl;
#endif
}

int query() {
    MysqlConn conn;
    conn.connect("root", "root", "snooker", "192.168.80.30");
    string sql = "insert into player values(6, 25, 'China', 'Ding Junhui')";
    bool flag = conn.update(sql);
    cout << "flag value:  " << flag << endl;

    sql = "select * from player";
    conn.query(sql);
    while (conn.next()) {
        cout << conn.value(0) << ", " << conn.value(1) << ", " << conn.value(2) << ", " << conn.value(3) << endl;
    }
    return 0;
}

int main() {
    test1();
    // test2();
    return 0;
}
