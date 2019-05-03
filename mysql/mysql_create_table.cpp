#include <stdio.h>
#include <stdlib.h>
#include </usr/include/mysql/mysql.h>
#include <iostream>

int main(void)
{
  MYSQL *conn;

  if ((conn = mysql_init(NULL)) == NULL)
  {
    fprintf(stderr, "Could not init DB\n");
    return EXIT_FAILURE;
  }
  if (mysql_real_connect(conn, "localhost", "phpmyadmin", "EQ$ua.12", "utoronto", 0, NULL, 0) == NULL)
  {
    fprintf(stderr, "DB Connection Error\n");
    return EXIT_FAILURE;
  }
  if (mysql_query(conn, "CREATE TABLE IF NOT EXISTS `USERS` ("
    + "`ID` int(11) unsigned NOT NULL auto_increment,"
    + "`ID` int(11) unsigned NOT NULL auto_increment,"
    + "`EMAIL` varchar(255) NOT NULL default '',"
    + "`PASSWORD` varchar(255) NOT NULL default '',"
    + "`PERMISSION_LEVEL` tinyint(1) unsigned NOT NULL default '1',"
    + "`APPLICATION_COMPLETED` boolean NOT NULL default '0',"
    + "`APPLICATION_IN_PROGRESS` boolean NOT NULL default '0',"
    + "PRIMARY KEY  (`ID`)"
    + ")") != 0)
  {
    fprintf(stderr, "Query Failure\n");
    return EXIT_FAILURE;
  }
  else
  {
         printf("Query OK\n");
  }
  mysql_close(conn);
  return EXIT_SUCCESS;
}
