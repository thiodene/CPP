#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>
#include <iostream>
#include <string>

#include </usr/include/mysql/mysql.h>

using namespace std;

int main ()
{
    MYSQL *conn; /* pointer to connection handler */
    MYSQL_RES *res; /* holds the result set */
    MYSQL_ROW row;



    /* INITIALIZE CONNECTION HANDLER, DO NOT CHANGE */
    conn = mysql_init (NULL);

    /* THIS CONNECTS TO SERVER, DO NOT CHANGE ANYTHING HERE */
    mysql_real_connect (conn, "localhost", "phpmyadmin", "EQ$ua.12",
    "utoronto", 0, NULL, 0);
    /* show tables in the database (test for errors also) */
    mysql_query(conn, "SELECT * FROM small_data_test");
    res = mysql_store_result(conn);


    // get the number of the columns
    int num_fields = mysql_num_fields(res);
    // Fetch all rows from the result
    while ((row = mysql_fetch_row(res)))
    {
       // Print all columns
       for(int i = 0; i < num_fields; i++)
       {
           // Make sure row[i] is valid!
           if(row[i] != NULL)
                cout << row[i] << endl;
           else
                cout << "NULL" << endl;

           // Also, you can use ternary operator here instead of if-else
           // cout << row[i] ? row[i] : "NULL" << endl;
       }
    }

    // DON'T FORGET TO CLEAN RESULT AFTER YOU DON'T NEED IT
    // ANYMORE

    if(res != NULL)
       mysql_free_result(res);

    /* disconnect from server */
    mysql_close (conn);

    //system("pause");
    return 0;
}
/* end main function */
/* end main function */
