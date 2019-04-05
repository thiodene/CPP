#include <stdio.h>
#include <stdlib.h>
#include </usr/include/mysql/mysql.h>

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
  if (mysql_query(conn, "INSERT INTO small_data_test (lat,lon,timestamp,session_dt) VALUES ('43.8344','-79.333013','1554485606',NOW() )") != 0)
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
