#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include "structure.h"
#include#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include "structure.h"
#include "/usr/include/postgresql/libpq-fe.h"

#ifndef LESFONCTIONS_H
#define LESFONCTIONS_H
#define PRIX "300"
#define TAILLE 11400


     	
int notclientexiste(PGconn* conn,char mail[TAILLE],char password[TAILLE]){

	char str1[TAILLE],str2[TAILLE],str3[TAILLE],str4[TAILLE],str5[TAILLE];
	strcpy(str1,"SELECT * FROM client where adrs_mail_cl='");
        strcpy(str2,mail);
        strcpy(str3,"' and password_cl='");
        strcpy(str4,password);
        strcpy(str5,"';");
        strcat(str1,str2);
        strcat(str1,str3);    
        strcat(str4,str5);
        strcat(str1,str4);

         PGresult *res = PQexec(conn,str1);
         
	return PQresultStatus(res) == PGRES_TUPLES_OK & !PQntuples(res);

}

int notemployerexiste(PGconn* conn,char num_id[TAILLE]){

	char str1[TAILLE],str2[TAILLE],str3[TAILLE],str4[TAILLE],str5[TAILLE];
	strcpy(str1,"SELECT * FROM personne where id_emp='");
        strcpy(str2,num_id);
        strcpy(str3,"';");
        strcat(str1,str2);
        strcat(str1,str3);    
       

         PGresult *res = PQexec(conn,str1);
         printf("%s",str1);
	return PQresultStatus(res) == PGRES_TUPLES_OK & !PQntuples(res);

}

void insertpersonne(PGconn* conn,char num_id[TAILLE],char nom[TAILLE],char prenom[TAILLE],char adrs[TAILLE],char tel[TAILLE],char age[TAILLE]){

	char str1[TAILLE],str2[TAILLE],str3[TAILLE],str4[TAILLE],str5[TAILLE],str6[TAILLE],str7[TAILLE],
	str8[TAILLE],str9[TAILLE],str10[TAILLE],str11[TAILLE],str12[TAILLE],str13[TAILLE];
	PGresult *res;
	
	strcpy(str1,"INSERT INTO personne VALUES ('");
        strcpy(str2,num_id);
        strcpy(str3,"','");
        strcpy(str4,nom);
        strcpy(str5,"','");
        strcpy(str6,prenom);
        strcpy(str7,"','");
        strcpy(str8,adrs);
        strcpy(str9,"','");
        strcpy(str10,tel);
        strcpy(str11,"','");
        strcpy(str12,age);
        strcpy(str13,"');");
        strcat(str1,str2);strcat(str1,str3);strcat(str1,str4);strcat(str1,str5);strcat(str1,str6);strcat(str1,str7);strcat(str1,str8);
        strcat(str1,str9);strcat(str1,str10);strcat(str1,str11);strcat(str1,str12);strcat(str1,str13);

         res = PQexec(conn,str1);
         
         printf("%s",str1);
         if(PQresultStatus(res) == PGRES_COMMAND_OK){ 
         printf("commande okey");
        
         } else {
         printf("commande not okey");
          fprintf(stderr, "Connection to database failed: %s\n",
            PQerrorMessage(conn));
         }

}


void insertclient(PGconn* conn,char num_id[TAILLE],char mail[TAILLE],char password[TAILLE]){

	char str1[TAILLE],str2[TAILLE],str3[TAILLE],str4[TAILLE],str5[TAILLE],str6[TAILLE],str7[TAILLE];
	strcpy(str1,"INSERT INTO client VALUES ('");
        strcpy(str2,num_id);
        strcpy(str3,"','");
        strcpy(str4,mail);
        strcpy(str5,"','");
        strcpy(str6,password);
        strcpy(str7,"');");
       
        strcat(str1,str2);strcat(str1,str3);strcat(str1,str4);strcat(str1,str5);strcat(str1,str6);strcat(str1,str7);
        PGresult *res = PQexec(conn,str1);
        
        printf("%s",str1);
        
	if(PQresultStatus(res) == PGRES_COMMAND_OK){ printf("commande okey");} else {printf("commande not okey");fprintf(stderr, "Connection to database failed: %s\n",
            PQerrorMessage(conn));}

}

char* proposeoffre(PGconn* conn,char *bufferS){
	
    char str1[111140];
    strcpy(str1,"SELECT nom_offre FROM offre");		
    PGresult *res = PQexec(conn,str1);
    int rows = PQntuples(res);
    
    for(int i=0; i<rows; i++) {
    strcat(bufferS, PQgetvalue(res, i, 0));        
    }
    
   // printf("bufferS dans proposeoffre %s",bufferS);
    
    return bufferS;


}

int choixexiste(PGconn* conn,char choix[TAILLE]){

char str1[TAILLE],str2[TAILLE],str3[TAILLE];
PGresult *res;
strcpy(str1,"SELECT id_offre,pourcentage_reduc from offre where nom_offre='");
	printf("%s\n",str1);
        strcpy(str2,choix);
        printf("%s\n",str2);
        strcpy(str3,"';");
        printf("%s\n",str3);
       
        strcat(str1,str2);strcat(str1,str3);
        printf("%s\n",str1);
        
           
        res = PQexec(conn,str1);
        
        
          if(PQresultStatus(res) == PGRES_TUPLES_OK){ printf("commande okey");} else {printf("commande not okey");fprintf(stderr, "Connection to database failed: %s\n",
            PQerrorMessage(conn));}
  return PQntuples(res);
}




FILE * remplirbillet(PGconn* conn,FILE * fbillet,char choix[TAILLE],char mail[TAILLE]){

    
    char str1[TAILLE],str2[TAILLE],str3[TAILLE],str4[TAILLE],str5[TAILLE],str6[TAILLE],
    str7[TAILLE],str8[TAILLE],str9[TAILLE],str10[TAILLE],
    id_cl[TAILLE],nom[TAILLE],prenom[TAILLE],num_bil[TAILLE],
    date_achat[TAILLE],date_expir[TAILLE],prix_bil[TAILLE],pourcentage_reduc[TAILLE],age_cl[TAILLE],id_offre[TAILLE];
    Personne p;
    Client cl;
    Billet bil;
    PGresult *res;
    
     printf(" choix pas null val first %s\n",choix);
     
    time_t now=time(NULL);
    struct tm * tm=localtime(&now);
    char date[64];

    strftime(date,sizeof date,"%A,%B %d,%Y %H:%M:%S",tm);
    
    fprintf(stderr,"Date = %s\n",ctime(&now));
    
    strcpy(str1,"SELECT id_cl,age_pers FROM client inner join personne  on id_cl=num_ident  and adrs_mail_cl='");	
     strcpy(str2,mail);
     strcpy(str3,"';");
    strcat(str1,str2);strcat(str1,str3);
    
      res = PQexec(conn,str1);
        
        printf("%s\n",str1);
         
        strcpy(id_cl,PQgetvalue(res,0,0));
        strcpy(age_cl,PQgetvalue(res,0,1));
        PQclear(res);
        
       
        
        if(!strcmp(choix,"employer(parc)") && notemployerexiste(conn,id_cl)){
        return NULL; 
        }
        
         double d2; char *end;
        
        d2=strtod(age_cl,&end);
        printf("age_cl %f\n",d2);
        
        if(d2>16 && !strcmp(choix,"enfant")){
        return NULL; 
        }
        
        
        //-------------------------------------------------
        strcpy(str1,"");	
     strcpy(str2,"");
     strcpy(str3,"");
        
        strcpy(str1,"SELECT nom_pers,prenom_pers,num_ident FROM personne where num_ident='");	
        printf(" p.num_id ---> %s",id_cl);
     strcpy(str2,id_cl);
     printf(" p.num_id apres personne---> %s",id_cl);
     strcpy(str3,"';");
    strcat(str1,str2);strcat(str1,str3);
    
      res = PQexec(conn,str1);
        
        printf("%s\n",str1);
        strcpy(nom,PQgetvalue(res,0,0));
        printf("%s\n",p.nom);
        strcpy(prenom,PQgetvalue(res,0,1));
        printf("%s\n",p.prenom);
        strcpy(id_cl,PQgetvalue(res,0,2));
        printf("%s\n",id_cl);
        PQclear(res);
        
        

        
          //-------------------------------------------------
        strcpy(str1,"");	
     strcpy(str2,"");
      strcpy(str3,"");
      strcpy(str4,"");	
     strcpy(str5,"");
      strcpy(str6,"");
      strcpy(str7,"");
      
	strcpy(str1,"INSERT INTO billet (id_cl,date_achat,prix_bil)  VALUES ('");
	printf(" p.num_id ---> %s",id_cl);
        strcpy(str2,id_cl);
        strcpy(str3,"','");
        strcpy(str4,date);
        strcpy(str5,"',");
        strcpy(str6,PRIX);
        strcpy(str7,");");
        
         printf("%s\n",str1);
       
        strcat(str1,str2);strcat(str1,str3);
        strcat(str1,str4);strcat(str1,str5);
        strcat(str1,str6);strcat(str1,str7);
          
        res = PQexec(conn,str1);
        
        if(PQresultStatus(res) == PGRES_COMMAND_OK){ printf("commande okey");} else {printf("commande not okey");fprintf(stderr, "Connection to database failed: %s\n",
            PQerrorMessage(conn));}
        
      PQclear(res);
        
         //-------------------------------------------------
         strcpy(str1,"");	
     strcpy(str2,"");
      strcpy(str3,"");
      
	strcpy(str1,"SELECT num_bil,date_achat,prix_bil from billet where id_cl='");
        strcpy(str2,id_cl);
        strcpy(str3,"';");
        
       
        strcat(str1,str2);strcat(str1,str3);
        res = PQexec(conn,str1);
        
         if(PQresultStatus(res) == PGRES_TUPLES_OK){ printf("commande okey");} else {printf("commande not okey");fprintf(stderr, "Connection to database failed: %s\n",
            PQerrorMessage(conn));}
        
        
        printf("%s",str1);
        
        strcpy(num_bil,PQgetvalue(res,0,0));
        printf("%s\n",num_bil);
        
        strcpy(date_achat,PQgetvalue(res,0,1));
        printf("%s\n",date_achat);
        
        
         strcpy(prix_bil,PQgetvalue(res,0,2));
        printf("prix bil like in bdd %s \n",prix_bil);
        
        double d1; 
        d1=strtod(prix_bil,&end);
        printf(" choix pas null val ;:!;:! %s\n",choix);
        printf("nombre %f\n",d1);
         
        
        PQclear(res);
        
          if(!strcmp(choix,"fete(Noel)") && strcmp(date_achat,"2020-12-25")){
        return NULL; 
        }
        
         //-------------------------------------------------
         printf(" choix pas null val ;:!;:! %s\n",choix);
         
         if(strcmp(choix,"")){
         printf(" choix pas null val %s\n",choix);
         
          strcpy(str1,"");	
     strcpy(str2,"");
      strcpy(str3,"");
      
	strcpy(str1,"SELECT id_offre,pourcentage_reduc from offre where nom_offre='");
	printf("%s\n",str1);
        strcpy(str2,choix);
        printf("%s\n",str2);
        strcpy(str3,"';");
        printf("%s\n",str3);
       
        strcat(str1,str2);strcat(str1,str3);
        printf("%s\n",str1);
        
           
        res = PQexec(conn,str1);
        
        
          if(PQresultStatus(res) == PGRES_TUPLES_OK){ printf("commande okey");} else {printf("commande not okey");fprintf(stderr, "Connection to database failed: %s\n",
            PQerrorMessage(conn));}
            
              printf(" rows in offre %d\n",PQntuples(res));
        
 
        printf(" (0.0) %s\n",PQgetvalue(res,0,0));
        printf(" (0.1) %s\n",PQgetvalue(res,0,1));
        strcpy(id_offre,PQgetvalue(res,0,0));
        strcpy(pourcentage_reduc,PQgetvalue(res,0,1));
       
        double d,prix_apres_reduc;
        
        d=strtod(pourcentage_reduc,&end);
        printf("nombre %f\n",d);
        
        prix_apres_reduc=d1-d*d1;
        
        printf("prix apres reduc :%f\n",prix_apres_reduc);
        
        PQclear(res);
        
         //-------------------------------------------------
         
          strcpy(str1,"");	
     strcpy(str2,"");
      strcpy(str3,"");
      strcpy(str4,"");	
     strcpy(str5,"");
      strcpy(str6,"");
      strcpy(str7,"");
   
            
    char prix_apres_reduc_s[10];
    sprintf(prix_apres_reduc_s, "%f",prix_apres_reduc);
    printf ("\nvaleur en trame: %s", prix_apres_reduc_s);
         
         strcpy(prix_bil,prix_apres_reduc_s);
         
         
          strcpy(str1,"");	
     strcpy(str2,"");
      strcpy(str3,"");
      
	strcpy(str1,"UPDATE billet SET prix_bil=");
	 strcpy(str2,prix_bil);
	 strcpy(str3,",id_offre='");
	 strcpy(str4,id_offre);
        strcpy(str6,"' WHERE id_cl='");
         strcpy(str7,id_cl);
         strcpy(str8,"' and num_bil='");
         strcpy(str9,num_bil);
         strcpy(str10,"';");
         
         
          printf("%s\n",str1);
       
        strcat(str1,str2);strcat(str1,str3);
        strcat(str1,str4);strcat(str1,str5);
        strcat(str1,str6);strcat(str1,str7);
        strcat(str1,str8);strcat(str1,str9);
        strcat(str1,str10);
          
        res = PQexec(conn,str1);
        
        if(PQresultStatus(res) == PGRES_COMMAND_OK){ printf("commande okey");} else {printf("commande not okey");fprintf(stderr, "Connection to database failed: %s\n",
            PQerrorMessage(conn));}
            
        
      PQclear(res);
         
         }else{
         
         strcpy(prix_bil,PRIX);
         
         }
         
         
         //------------------------------------------------------
         
         
   
    
    fbillet=fopen("filebillet","w");
    if(fbillet !=NULL){
    
    
    fprintf(fbillet,"Identifiant_billet :");
     fwrite(num_bil,sizeof(char),strlen(num_bil),fbillet);
     fprintf(fbillet,"\n");
     
     fprintf(fbillet,"Nom_client        :");
     fwrite(nom,sizeof(char),strlen(nom),fbillet);
      fprintf(fbillet,"\n");
     
     fprintf(fbillet,"Prenom_client     :");
     fwrite(prenom,sizeof(char),strlen(prenom),fbillet);
      fprintf(fbillet,"\n");
      
      fprintf(fbillet,"Date_Achat       :");
     fwrite(date_achat,sizeof(char),strlen(date_achat),fbillet);
      fprintf(fbillet,"\n");
     

      
      fprintf(fbillet,"Prix             :");
     fwrite(prix_bil,sizeof(char),strlen(prix_bil),fbillet);
      fprintf(fbillet,"\n");


    fclose(fbillet);
    }else{
    perror("filebillet");
    }

return fbillet;
}

#endif
