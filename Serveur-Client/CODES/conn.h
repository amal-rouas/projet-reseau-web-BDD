#include <stdio.h>
#include <stdlib.h>
#include "/usr/include/postgresql/libpq-fe.h"
#ifndef CONN_H
#define CONN_H

void do_exit(PGconn *conn, PGresult *res) {
    
    fprintf(stderr, "%s\n", PQerrorMessage(conn));    

    PQclear(res);
    PQfinish(conn);    
    
    exit(1);
   
}

PGconn* connexion_bdd(){
 PGconn *conn = PQconnectdb("dbname=etudb host=localhost port=5432 user=etu password=A123456*");

    if (PQstatus(conn) == CONNECTION_BAD) {
        
        fprintf(stderr, "Connection to database failed: %s\n",
            PQerrorMessage(conn));
         PQfinish(conn);
    }
    return conn;
}

#endif


                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            #include <stdio.h>
#include <stdlib.h>
#include "/usr/include/postgresql/libpq-fe.h"
#ifndef CONN_H
#define CONN_H

void do_exit(PGconn *conn, PGresult *res) {
    
    fprintf(stderr, "%s\n", PQerrorMessage(conn));    

    PQclear(res);
    PQfinish(conn);    
    
    exit(1);
   
}

PGconn* connexion_bdd(){
 PGconn *conn = PQconnectdb("dbname=etudb host=localhost port=5432 user=etu password=A123456*");

    if (PQstatus(conn) == CONNECTION_BAD) {
        
        fprintf(stderr, "Connection to database failed: %s\n",
            PQerrorMessage(conn));
         PQfinish(conn);
    }
    return conn;
}

#endif


