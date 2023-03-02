# mysql-connector-ace

This is the first commit.

A client library for communication with MySQL server based on C++ ACE.

Here is the structure & contents of sample table snooker.player.

mysql> desc player;
+-------+-------------+------+-----+---------+-------+
| Field | Type        | Null | Key | Default | Extra |
+-------+-------------+------+-----+---------+-------+
| name  | varchar(40) | NO   | PRI | NULL    |       |
| age   | int         | YES  |     | NULL    |       |
+-------+-------------+------+-----+---------+-------+

mysql> select * from player;
+--------------------+------+
| name               | age  |
+--------------------+------+
| Allister Carter    |   44 |
| Barry Hawkins      |   44 |
| Ding Junhui        |   36 |
| Jimmy White        |   60 |
| Joe Perry          |   49 |
| John Higgins       |   48 |
| Judd Trump         |   34 |
| Kyren Wilson       |   32 |
| Luca Brecel        |   28 |
| Mark Allen         |   37 |
| Mark Selby         |   40 |
| Mark Williams      |   48 |
| Neil Robertson     |   41 |
| Robert Milkins     |   47 |
| Ronnie O'Sullivian |   48 |
| Shaun Murphy       |   41 |
| Wu Yize            |   20 |
| Yan Bingtao        |   23 |
| Zhao Xintong       |   26 |
+--------------------+------+
