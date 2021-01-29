#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h> 
#include "structure.h"

#define PORT 4455

#define TAILLE 11400



void main(){
	int ClientSocket;
	struct sockaddr_in serverAddr;
        char messageclient[TAILLE],messageserveur[TAILLE],reponse[TAILLE];
        Personne p;
        Client cl;
        FILE *fbillet;

	ClientSocket=socket(PF_INET, SOCK_STREAM,0);
        memset(&serverAddr,'\0',sizeof(serverAddr));
       
        serverAddr.sin_family=AF_INET;
        serverAddr.sin_port=htons(PORT);
        serverAddr.sin_addr.s_addr=inet_addr("127.0.0.1");
        
        connect(ClientSocket,(struct sockaddr *)&serverAddr,sizeof(serverAddr));
        
        printf("Etes Vous client \n");
        
        printf("tapez o='OUI'/n='NON':");
        
        scanf("%s",reponse);
        
         if(!strcmp(reponse,"o")){
         
         send(ClientSocket,reponse,strlen(reponse),0);
         
         char *cs="@gmail.";
          
          printf("Saisissez votre mail     :");
         scanf("%s",cl.mail);
         printf("\n");
         
         if(strspn (cs,cl.mail)!=strlen(cs)){

         do{
        printf("donner une adresse mail VALIDE! SVP:");
        scanf("%s",cl.mail);
        
        }while(strspn (cs,cl.mail)!=strlen(cs));
        
        }
         
           char *cm="drop",*cm1="alter",*cm2="update";
         
          printf("Saisissez votre password :");
         scanf("%s",cl.password);
         printf("\n");
         
         if(strspn (cm,cl.password)==strlen(cm) || strspn (cm1,cl.password)==strlen(cm1) || strspn (cm2,cl.password)==strlen(cm2)){   
         
         do{
        printf("donner un password VALIDE! SVP:");
        scanf("%s",cl.password);
        
        }while(strspn (cm,cl.password)==strlen(cm) || strspn (cm1,cl.password)==strlen(cm1) || strspn (cm2,cl.password)==strlen(cm2));
         }
         
         send(ClientSocket,&cl,TAILLE,0);
         
         recv(ClientSocket,messageserveur,TAILLE,0);
       //printf(" les donnes recu du serveur sont: %s \n",messageserveur);
       
       if(!strcmp(messageserveur,"notclient")){
       
       printf("Erreur vous n'etes pas client veuillez vous inscrire SVP merci !\n");
       
       }else{
       
         char d[] ="      ";
         char *p;
         char temp[TAILLE];
         
         char choix[10];
         
          printf("Vous etes bien identifier: \n");   
          printf("voici NOS offres, choisissez une offre puis --> ENTREE \n");
          printf("Tapez 'n' si aucune OFFRE ne vous convient --> ENTREE \n");
          
          
          strcpy(temp,messageserveur);
          
         p=strtok(messageserveur, d);
         
      
       do{
         printf("'%s'                 \n", p); 
         p=strtok(NULL, d);
         }while(p != NULL);
         
        
         
         scanf("%s",choix);
         
         printf("choix avant la boucle  %s                \n", choix); 
         

         
         if(choix==NULL){
           do{
         printf("Erreur faite un choix valide SVP! merci\n");
          scanf("%s",choix);
          }while(choix==NULL);
          send(ClientSocket,choix,strlen(choix),0);
         }else{
          //printf("choix avant envoi  %s                \n", choix); 
          send(ClientSocket,choix,strlen(choix),0);
          //printf("choix apres envoi  %s                \n", choix); 
         }
         
         recv(ClientSocket,&fbillet,TAILLE,0);
         
         if(fbillet==NULL){
       printf(" Erreur de fabrication du billet SAISIE D'UN CHAMPS 'INCORRECTE/INCOHERENT' \n");
       }else{
       printf(" Fichier Reçu \n");
       char infos1[TAILLE];
       char infos2[TAILLE];
       
       fbillet=fopen("filebillet","r");
       printf("les informations relatives a votre billet merci de nous avoir fait confiance a tres bientot :\n");
       
       while(!feof(fbillet)){
       
       fscanf(fbillet, "%s %s ",infos1,infos2);
        printf("%s  %s", infos1, infos2);
        printf("\n");
        
        }
        fclose(fbillet);
       
       }
         
         }
         
         
         }else{
        send(ClientSocket,reponse,strlen(reponse),0);
     
            printf("------------------------inscription-------------------\n");
        printf("donner un numero d'identité:");
        scanf("%s",p.num_id);
        //send(ClientSocket,p.num_id,strlen(p.num_id),0);
        
        printf("donner un nom a envoyer:");
        scanf("%s",p.nom);
        //send(ClientSocket,p.nom,strlen(p.nom),0);
       
       
        printf("donner un prenom:");
        scanf("%s",p.prenom);
        //send(ClientSocket,p.prenom,strlen(p.prenom),0);
       
       
        printf("donner une adresse postale:");
        scanf("%s",p.adr);
        //send(ClientSocket,p.adr,strlen(p.adr),0);
       
       
        printf("donner un numero de tel:");
        scanf("%s",p.tel);
        //send(ClientSocket,p.tel,strlen(p.tel),0);
        
        printf("donner votre age:");
        scanf("%s",p.age);
        send(ClientSocket,&p,TAILLE,0);
       
        
        printf("donner un mail:");
        scanf("%s",cl.mail);
        //send(ClientSocket,cl.mail,strlen(cl.mail),0);
        
        printf("donner un password:");
        scanf("%s",cl.password);
        
        send(ClientSocket,&cl,TAILLE,0);
        
             strcpy(messageserveur,"");
             recv(ClientSocket,messageserveur,TAILLE,0);
       //printf(" les donnes recu du serveur sont: %s \n",messageserveur);
       
       if(!strcmp(messageserveur,"VOUS ETES DÉJA CLIENT")){
       
       printf("VOUS ETES DÉJA CLIENT merci !\n");
       
       }else{
       
         printf("VOUS ETES DESORMER CLIENT merci de vous re connecter a nouveau avec vos EDENTIFIANTS pour réservé VOTRE BILLET !\n");
       
       }
         
          
         }
         
         

       
        

     close(ClientSocket);
}

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h> 
#include "structure.h"

#define PORT 4455

#define TAILLE 11400



void main(){
	int ClientSocket;
	struct sockaddr_in serverAddr;
        char messageclient[TAILLE],messageserveur[TAILLE],reponse[TAILLE];
        Personne p;
        Client cl;
        FILE *fbillet;

	ClientSocket=socket(PF_INET, SOCK_STREAM,0);
        memset(&serverAddr,'\0',sizeof(serverAddr));
       
        serverAddr.sin_family=AF_INET;
        serverAddr.sin_port=htons(PORT);
        serverAddr.sin_addr.s_addr=inet_addr("127.0.0.1");
        
        connect(ClientSocket,(struct sockaddr *)&serverAddr,sizeof(serverAddr));
        
        printf("Etes Vous client \n");
        
        printf("tapez o='OUI'/n='NON':");
        
        scanf("%s",reponse);
        
         if(!strcmp(reponse,"o")){
         
         send(ClientSocket,reponse,strlen(reponse),0);
         
         char *cs="@gmail.";
          
          printf("Saisissez votre mail     :");
         scanf("%s",cl.mail);
         printf("\n");
         
         if(strspn (cs,cl.mail)!=strlen(cs)){

         do{
        printf("donner une adresse mail VALIDE! SVP:");
        scanf("%s",cl.mail);
        
        }while(strspn (cs,cl.mail)!=strlen(cs));
        
        }
         
           char *cm="drop",*cm1="alter",*cm2="update";
         
          printf("Saisissez votre password :");
         scanf("%s",cl.password);
         printf("\n");
         
         if(strspn (cm,cl.password)==strlen(cm) || strspn (cm1,cl.password)==strlen(cm1) || strspn (cm2,cl.password)==strlen(cm2)){   
         
         do{
        printf("donner un password VALIDE! SVP:");
        scanf("%s",cl.password);
        
        }while(strspn (cm,cl.password)==strlen(cm) || strspn (cm1,cl.password)==strlen(cm1) || strspn (cm2,cl.password)==strlen(cm2));
         }
         
         send(ClientSocket,&cl,TAILLE,0);
         
         recv(ClientSocket,messageserveur,TAILLE,0);
       //printf(" les donnes recu du serveur sont: %s \n",messageserveur);
       
       if(!strcmp(messageserveur,"notclient")){
       
       printf("Erreur vous n'etes pas client veuillez vous inscrire SVP merci !\n");
       
       }else{
       
         char d[] ="      ";
         char *p;
         char temp[TAILLE];
         
         char choix[10];
         
          printf("Vous etes bien identifier: \n");   
          printf("voici NOS offres, choisissez une offre puis --> ENTREE \n");
          printf("Tapez 'n' si aucune OFFRE ne vous convient --> ENTREE \n");
          
          
          strcpy(temp,messageserveur);
          
         p=strtok(messageserveur, d);
         
      
       do{
         printf("'%s'                 \n", p); 
         p=strtok(NULL, d);
         }while(p != NULL);
         
        
         
         scanf("%s",choix);
         
         printf("choix avant la boucle  %s                \n", choix); 
         

         
         if(choix==NULL){
           do{
         printf("Erreur faite un choix valide SVP! merci\n");
          scanf("%s",choix);
          }while(choix==NULL);
          send(ClientSocket,choix,strlen(choix),0);
         }else{
          //printf("choix avant envoi  %s                \n", choix); 
          send(ClientSocket,choix,strlen(choix),0);
          //printf("choix apres envoi  %s                \n", choix); 
         }
         
         recv(ClientSocket,&fbillet,TAILLE,0);
         
         if(fbillet==NULL){
       printf(" Erreur de fabrication du billet SAISIE D'UN CHAMPS 'INCORRECTE/INCOHERENT' \n");
       }else{
       printf(" Fichier Reçu \n");
       char infos1[TAILLE];
       char infos2[TAILLE];
       
       fbillet=fopen("filebillet","r");
       printf("les informations relatives a votre billet merci de nous avoir fait confiance a tres bientot :\n");
       
       while(!feof(fbillet)){
       
       fscanf(fbillet, "%s %s ",infos1,infos2);
        printf("%s  %s", infos1, infos2);
        printf("\n");
        
        }
        fclose(fbillet);
       
       }
         
         }
         
         
         }else{
        send(ClientSocket,reponse,strlen(reponse),0);
     
            printf("------------------------inscription-------------------\n");
        printf("donner un numero d'identité:");
        scanf("%s",p.num_id);
        //send(ClientSocket,p.num_id,strlen(p.num_id),0);
        
        printf("donner un nom a envoyer:");
        scanf("%s",p.nom);
        //send(ClientSocket,p.nom,strlen(p.nom),0);
       
       
        printf("donner un prenom:");
        scanf("%s",p.prenom);
        //send(ClientSocket,p.prenom,strlen(p.prenom),0);
       
       
        printf("donner une adresse postale:");
        scanf("%s",p.adr);
        //send(ClientSocket,p.adr,strlen(p.adr),0);
       
       
        printf("donner un numero de tel:");
        scanf("%s",p.tel);
        //send(ClientSocket,p.tel,strlen(p.tel),0);
        
        printf("donner votre age:");
        scanf("%s",p.age);
        send(ClientSocket,&p,TAILLE,0);
       
        
        printf("donner un mail:");
        scanf("%s",cl.mail);
        //send(ClientSocket,cl.mail,strlen(cl.mail),0);
        
        printf("donner un password:");
        scanf("%s",cl.password);
        
        send(ClientSocket,&cl,TAILLE,0);
        
             strcpy(messageserveur,"");
             recv(ClientSocket,messageserveur,TAILLE,0);
       //printf(" les donnes recu du serveur sont: %s \n",messageserveur);
       
       if(!strcmp(messageserveur,"VOUS ETES DÉJA CLIENT")){
       
       printf("VOUS ETES DÉJA CLIENT merci !\n");
       
       }else{
       
         printf("VOUS ETES DESORMER CLIENT merci de vous re connecter a nouveau avec vos EDENTIFIANTS pour réservé VOTRE BILLET !\n");
       
       }
         
          
         }
         
         

       
        

     close(ClientSocket);
}

