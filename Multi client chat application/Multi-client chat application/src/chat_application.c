#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <stdbool.h>
#include "../include/logger.h"
#include "../include/global.h"
#include "FINDIP.h"

#define BUFSIZE 1024
#define BACKLOG 5
#define STDIN 0
#define TRUE 1
#define CMD_SIZE 100
#define BUFFER_SIZE 1024
#define TRUE 1
#define FALSE 0

int port2; 
char *ip_addr;
char port_no[30];
char send2[100];
char IPADDRS[10][10];
char PORTNOS[10][300];
char host2[BUFFER_SIZE]; 
char portnos2[10][300];
int ports[10];
int port3[10];
char ipaddr[10][300];
char host[BUFFER_SIZE];
char port_char[10][300];
char sendmsg2[1000];
int portno[10];
int sockno[10];
int portori[10];
int ip_int[10];
int sockcount=1;
int port;
int counter=1;

void swap(int* a, int* b)
{
    int t  = *a;
    *a     = *b;
    *b     = t;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
 
    
    for (i = 1; i <=n; i++)
    {
        
        min_idx    = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx= j;
 
        
        swap(&arr[min_idx], &arr[i]);
    }
}

int findindex(int arr[], int value, int n)
{
    int i;
    for(i =1;i<=n;i++)
    {
        if(arr[i]==value)
        {
            return i;
        }
    }
}

void printlist(int index2)
{
  int i3;
  for(i3=1;i3<index2;i3++)
  {
    ports[i3]=atoi(PORTNOS[i3]);
    port3[i3]=atoi(PORTNOS[i3]);
  }
  selectionSort(ports,index2);
  int color2=1;
  for(i3=1;i3<index2;i3++)
  {
  	/*printf("PORTS ARE %d %d \n", ports[i3], port3[i3]);*/
    if((ports[i3]!=99999) && (ports[i3]!=0)) 
    {
    int val2=ports[i3];
    int in_value3=findindex(port3,val2,index2);
    strcpy(host2, IPADDRS[in_value3]);
    struct sockaddr_in sa2;
    sa2.sin_family = AF_INET;
    inet_pton(AF_INET, host2, &sa2.sin_addr);

    char node2[NI_MAXHOST];
    int res2 = getnameinfo((struct sockaddr*)&sa2, sizeof(sa2), node2, sizeof(node2), NULL, 0, 0);
    if (res2)
    {       
    exit(1);
    }
    int y=atoi(PORTNOS[in_value3]);
	
    printf("%-5d%-20s%-8s\n", color2,  IPADDRS[i3], PORTNOS[i3]);
    color2++;
  }
}
}

char print_cmd2(char *command)
{
	char * pch, *store[30];
  int i,counter=0;
  for(i=0;i<30;i++)
    {
    	store[i]=malloc(sizeof(char)*100);
    }
    
  pch = strtok (command," ");
  while (pch != NULL)
    {
    
    	store[counter]=pch;
      counter++;
      pch = strtok (NULL, " ");    
    }
  char *cmd=malloc(sizeof(char)*CMD_SIZE);
  cmd=store[0];

  /*scanf("%s",cmd);*/
  if(strcmp(cmd,"AUTHOR\n")==0)
    {
       /* cse4589_print_and_log("[AUTHOR:SUCCESS]\n");
        cse4589_print_and_log("I, VKANNAN5, have read and understood the course academic integrity policy.\n");
        cse4589_print_and_log("[AUTHOR:END]\n");
*/
char your_ubit_name[50]="vkannan5";
                        cse4589_print_and_log("[AUTHOR:SUCCESS]\n");
                        cse4589_print_and_log("I, %s, have read and understood the course academic integrity policy.\n", your_ubit_name);
                        //cse4589_print_and_log("I, VKANNAN5, have read and understood the course academic integrity policy.\n");
                        cse4589_print_and_log("[AUTHOR:END]\n");
    }

  else if(strcmp(cmd, "IP\n")==0)
    {
    	cse4589_print_and_log("[IP:SUCCESS]\n");
    	int z = printip();
    	cse4589_print_and_log("[IP:END]\n");
      
    }
  else if(strcmp(cmd,"PORT\n")==0)
    {
    	int y=atoi(port_no);
    	cse4589_print_and_log("[PORT:SUCCESS]\n");
    	cse4589_print_and_log("PORT:%d\n", y);
    	cse4589_print_and_log("[PORT:END]\n");    	
    }
   /* else if(strcmp(cmd,"LIST\n")==0)
 *     {
 *         	
 *         	    	printf("%s", port_no);
 *         	    	    } */
    else if(strcmp(cmd,"SEND")==0)
    {
    	strcpy(send2,store[1]);
      return 3;
    }
    else if (strcmp(cmd,"BROADCAST")==0)
    {
      return 4;
    }
    else if(strcmp(cmd, "LIST\n")==0 || (strcmp(cmd, "REFRESH\n"))==0)
    {
      /*printf("returning 5\n");*/
      return 5;
    }
    else if(strcmp(cmd, "EXIT\n")==0)
    {
      return 6;
    }
  return 0;
}


int print_cmd(char *command)
{
  char * pch, *store[30];
  int i,c1=0;
  for(i=0;i<30;i++)
  {
  	store[i]=malloc(sizeof(char)*100);
  }
  
  pch = strtok (command," ");
  while (pch != NULL)
  {
  
  	store[c1]=pch;
    c1++;
    pch = strtok (NULL, " ");    
  }
  char *cmd=malloc(sizeof(char)*CMD_SIZE);
  cmd=store[0];
     /*scanf("%s",cmd);*/
    if(strcmp(cmd,"AUTHOR\n")==0)
    {
       /* cse4589_print_and_log("[AUTHOR:SUCCESS]\n");
        cse4589_print_and_log("I, VKANNAN5, have read and understood the course academic integrity policy.\n");
        cse4589_print_and_log("[AUTHOR:END]\n");*/
	char your_ubit_name[50]="vkannan5";
                        cse4589_print_and_log("[AUTHOR:SUCCESS]\n");
                        cse4589_print_and_log("I, %s, have read and understood the course academic integrity policy.\n", your_ubit_name);
                        //cse4589_print_and_log("I, VKANNAN5, have read and understood the course academic integrity policy.\n");
                         cse4589_print_and_log("[AUTHOR:END]\n");
    }

    else if(strcmp(cmd, "IP\n")==0)
    {
     	cse4589_print_and_log("[IP:SUCCESS]\n");
    	int z = printip();
    	cse4589_print_and_log("[IP:END]\n");
      
      
    }
     else if(strcmp(cmd, "PORT\n")==0)
    {
        int y=atoi(port_no);
    	cse4589_print_and_log("[PORT:SUCCESS]\n");
    	cse4589_print_and_log("PORT:%d\n", y);
    	cse4589_print_and_log("[PORT:END]\n");
    }
    else if(strcmp(cmd, "LIST\n")==0)
    {   int iter;
               
        selectionSort(portori,sockcount);  
        int color=1;    
        for(iter=1;iter<sockcount;iter++)
        {   
            if(counter==0)
            {
                printf("No clients logged in\n");
                break;
            }
            if((portori[iter]!=99999) && (portori[iter]!=0))
            {
                int val=portori[iter];
                int in_value=findindex(portno,val,sockcount);
                strcpy(host, ipaddr[in_value]);
                struct sockaddr_in sa;
        		sa.sin_family = AF_INET;
        		inet_pton(AF_INET, host, &sa.sin_addr);
        		char node[NI_MAXHOST];
        		int res = getnameinfo((struct sockaddr*)&sa, sizeof(sa), node, sizeof(node), NULL, 0, 0);
        		cse4589_print_and_log("%-5d%-35s%-20s%-20d\n", color, ipaddr[in_value], node, portno[in_value]);
                color++;
                /*memset(node, 0, strlen(node));*/
           }
            else
            {
                continue;
            }
    	}

    }

    else
    {
        cse4589_print_and_log("No input\n");
    }
    return 0;
}

void broadcast(fd_set *list, int head_s, int server_s, int sock_i, char *buf,int bytes_r, char *buf2)
 { //printf("Reached Broadcast\n");
    int j=0;
    for(j=0;j<=head_s;j++)
    {
        if(FD_ISSET(j,list))
        {
            if(j!=server_s && j!=sock_i && j!=STDIN)
            {
                if(send(j,buf2,256,0)==-1)
                {
                 perror("Send Error");
                }   
		
		if(send(j,buf,bytes_r,0)==-1)
                {
                    perror("Send Error");
                }/*
		if(send(j,buf2,256,0)==-1)
		{
		 perror("Send Error");
		}*/	
            }
        }
    }
    return;

 }

int findipc(char ipr[])
{
    int i;
    for(i=0;i<10;i++)
    {
        if(strcmp(ipr,ipaddr[i])==0)
        {
            return sockno[i];
        }
    }
}

int main(int argc, char **argv)
{
    
	/*Init. Logger*/
	        cse4589_init_log(argv[2]);

	        /* Clear LOGFILE*/
	    fclose(fopen(LOGFILE, "w"));

    if(argc != 3)
    {
       // printf("Usage:%s [port]\n", argv[2]);
        exit(-1);
    }

    int server_socket, head_socket, selret, sock_index, fdaccept=0, caddr_len;
    struct sockaddr_in server_addr, client_addr;
    fd_set master_list, watch_list;
    struct sockaddr_in remote_server_addr;
    char *iphost[10];
    char broadip[256];
    int ip_index=0;
    FD_ZERO(&master_list);
    FD_ZERO(&watch_list);

    if(strcmp(argv[1],"s")==0)
    {
    	server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket < 0)
    {
        perror("Cannot create socket");
    }

    port = atoi(argv[2]);
    strcpy(port_no,argv[2]);
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(port);
    int yes=1;

    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
        perror("setsockopt");
        exit(1);
    }

      if(bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) ==-1)
        {
            perror("Bind failed");
        }

    if(listen(server_socket, BACKLOG) == -1)
        {
            perror("Unable to listen on port");
        }
    /*printf("\nTCPServer Waiting for client on the port\n");*/
    fflush(stdout);

    FD_SET(server_socket, &master_list);
    FD_SET(STDIN, &master_list);
    head_socket = server_socket;

    while(TRUE)
    {
        memcpy(&watch_list, &master_list, sizeof(master_list));
        watch_list=master_list;


        selret = select(head_socket + 1, &watch_list, NULL, NULL, NULL);
        if(selret < 0)
            {
                /*printf("In SELECT: \n ");*/
                perror("select failed.");
                exit(4);
            }

            for(sock_index=0; sock_index<=head_socket; sock_index+=1)
            {


                if(FD_ISSET(sock_index, &watch_list))
                {

                   if (sock_index==0)
                    {   char *cmd = (char*) malloc(sizeof(char)*CMD_SIZE);

                        memset(cmd, '\0', CMD_SIZE);
                        if(fgets(cmd, CMD_SIZE-1, stdin) == NULL)
                            exit(-1);
                        print_cmd(cmd);
                        free(cmd);
                        continue;
                    }
                  
                  if(sock_index == server_socket)
                    {
                        caddr_len = sizeof(struct sockaddr_in);
                        fdaccept = accept(server_socket, (struct sockaddr *)&client_addr, &caddr_len);
                        if(fdaccept < 0)
                            {
                                perror("Accept failed.");
                                exit(1);
                            }

                        else
                        {

                        char *buffer2=malloc(sizeof(char)*BUFFER_SIZE);
                        memset(buffer2, '\0', BUFFER_SIZE);
                        FD_SET(fdaccept, &master_list);
                        if(fdaccept > head_socket)
                            head_socket = fdaccept;
                      //  printf("\nRemote Host connected!\n");
                        if(recv(fdaccept, buffer2, BUFFER_SIZE, 0)<=0)
                        {
                            cse4589_print_and_log("Error receiving data from client \n");
                        }
                        char storeaddr[50];
                        /*printf("counter is %d\n", counter);*/
                        strcpy(ipaddr[sockcount],inet_ntoa(client_addr.sin_addr));
                        strcpy(port_char[sockcount],buffer2);
                        portno[sockcount]=atoi(buffer2);
                        sockno[sockcount]=fdaccept;
                        portori[sockcount]=atoi(buffer2);
                       // printf("new connection from %s  and %s on port %d \n",ipaddr[sockcount], buffer2, portno[sockcount]);
                        /*
 *                         int k;
 *                                                 for(k=0;k<=counter;k++)
 *                                                                         {
 *                                                                                                     printf("IP 1 and 2 %s",ipaddr[counter]);
 *                                                                                                                             }*/
                        counter++;
                        sockcount++;
                        continue;
                        
                        }

                    }
                    
                    else
                    {                     
                        char buffer[BUFFER_SIZE],buf[BUFFER_SIZE], buf2[BUFFER_SIZE], buf3[BUFFER_SIZE], buf4[BUFFER_SIZE];
                        memset(buffer, '\0', BUFFER_SIZE);
                        int bytes_recvd, bytes_recvd2, bytes_recvd3, bytes_recvd4, bytes_recvd5;
                       
                        if((bytes_recvd =recv(sock_index, buffer, BUFFER_SIZE, 0)) <= 0)
                        {
                            close(sock_index);

                            if(sock_index!=0 && sock_index!=1)
                            {
                                printf("Remote Host terminated connection!\n");
                            }
                            int val=sock_index;
                            int in_value=findindex(sockno,val,sockcount);
                            sockno[in_value]=-1;
                            portno[in_value]=-1;
                            portori[in_value]=-1;
                            strcpy(ipaddr[in_value],"NULL");
                            strcpy(port_char[in_value],"NULL");

                            FD_CLR(sock_index, &master_list);
                            /*counter--;*/
                            
                            continue;
                        }

                        else if(strcmp(buffer,"EXIT")==0 && sock_index!=0 && sock_index!=1)
                        {
                           /* if(sock_index!=0 && sock_index!=1)
                            {
                               printf("Remote Host Exited!\n");
                            }*/
			    //printf("Client existed\n");
                            int val=sock_index;
                            int in_value=findindex(sockno,val,sockcount);
                            
                            sockno[in_value]=99999;
                            portno[in_value]=99999;
                           
                            portori[in_value]=99999;
                            strcpy(ipaddr[in_value],"NULL");
                            strcpy(port_char[in_value],"NULL");
                            counter--;
                            FD_CLR(sock_index, &master_list);
                            close(sock_index);
                            
                            /*continue;*/
                        }

                        else if(strcmp(buffer,"LIST")==0 || strcmp(buffer,"REFRESH")==0)
                        {
                            /*SEND ALL PACKETS HERE*/
                            int iter1=0;
                           char z[256];
				sprintf(z,"%d",sockcount);
                           /* //printf("sending sockcount %d\n", z);
 *                             //printf("sockcount is %d\n", ntohl(z));*/
                            send(sock_index, z,256,0);
                            for(iter1=1;iter1<sockcount;iter1++)
                            {
                                char sendad[256];
                                strcpy(sendad,ipaddr[iter1]);
                                printf("sending IP %s\n",sendad);
                                send(sock_index, sendad, sizeof(sendad),0);
                                
                            }
                            char buf5[BUFFER_SIZE];
                            for(iter1=1;iter1<sockcount;iter1++)
                            { 
                                
                                strcpy(buf5, port_char[iter1]);
                               printf("sending port number %s\n",buf5); 
                                send(sock_index, buf5,BUFFER_SIZE,0);
                                
                            }
                            continue;
                        }

                        else if(strcmp(buffer,"BROADCAST")!=0)
                        {   strcpy(sendmsg2,buffer);
                            if((bytes_recvd2 =recv(sock_index, buf2, BUFFER_SIZE, 0)) <= 0)
                            {
                                cse4589_print_and_log("No message received\n");
                                
                            }
                            else
                            {
                                char ip[256];
                                strcpy(ip,sendmsg2);
                                int send_to=findipc(ip);
				char buf4[256];
			//	char broadip[256];
                                int y=ntohl(sock_index);
                                int in_value4=findindex(sockno, sock_index, sockcount);
				strcpy(buf4,ipaddr[in_value4]);
				send(send_to, buf4, 256, 0);
                                send(send_to, buf2, bytes_recvd2, 0);  /* was sizeof(buf2)*/
                                cse4589_print_and_log("[RELAYED:SUCCESS]\n");
                               // int in_value4=findindex(sockno, sock_index, sockcount);
                                cse4589_print_and_log("msg from:%s, to:%s\n[msg]:%s\n", ipaddr[in_value4],ip,buf2);
                                cse4589_print_and_log("[RELAYED:END]\n");
                                /*printf("sending %s to %s\n",buf2, ip);*/
                               // send(send_to, buf2, bytes_recvd2, 0);  /* was sizeof(buf2)*/
                            }
                            continue;
                        }
                        else if(strcmp(buffer,"BROADCAST")==0)
                        {
                            if((bytes_recvd3 =recv(sock_index, buf3, BUFFER_SIZE, 0)) <= 0) //buf3 contains the message
                            {
                                cse4589_print_and_log("No message received\n");
                                
                            }
                            else
                            {
                               cse4589_print_and_log("[RELAYED:SUCCESS]\n");
                              int in_value4=findindex(sockno, sock_index, sockcount);
                              cse4589_print_and_log("msg from:%s, to:255.255.255.255\n[msg]:%s\n", ipaddr[in_value4],buf3);
                              cse4589_print_and_log("[RELAYED:END]\n");
			      strcpy(broadip,ipaddr[in_value4]);
                              broadcast(&master_list,head_socket,server_socket,sock_index, buf3, bytes_recvd3,broadip);
                            }
                            continue;
                        }                     

                    }
                }

            }
        }
    }


    		else if(strcmp(argv[1],"c")==0)
    		{
    			int listening_port=atoi(argv[2]);
    			strcpy(port_no,argv[2]);
		    bool login=FALSE;
		    char *input[30];
		    /* Take input and tokenize */
		 JUMP:  while(login==FALSE)
		    { 
		    char *str;
		      str=(char *)malloc(sizeof(char)*CMD_SIZE); 
		      
		      memset(str, '\0', CMD_SIZE);
		      if(fgets(str, CMD_SIZE-1, stdin) == NULL)
		        {
		        	exit(-1);
		        }

		      char * pch, *store[30];
		      int i,counter4=0;
		      for(i=0;i<30;i++)
		      {
		      	store[i]=malloc(sizeof(char)*100);
		      }
		      
		      pch = strtok (str," ");
		      while (pch != NULL)
		      {
		      
		      	store[counter4]=pch;
		        counter4++;
		        pch = strtok (NULL, " ");    
		      }
		        
		      if(strcmp(store[0], "AUTHOR\n")==0)
		      { char your_ubit_name[50]="vkannan5";
		      	cse4589_print_and_log("[AUTHOR:SUCCESS]\n");
			cse4589_print_and_log("I, %s, have read and understood the course academic integrity policy.\n", your_ubit_name);
        		//cse4589_print_and_log("I, VKANNAN5, have read and understood the course academic integrity policy.\n");
        		cse4589_print_and_log("[AUTHOR:END]\n");
		      }
		      else if(strcmp(store[0],"IP\n")==0)
		      {
		      	cse4589_print_and_log("[IP:SUCCESS]\n");
    			int z = printip();
    			cse4589_print_and_log("[IP:END]\n");
		      }
		      else if(strcmp(store[0],"PORT\n")==0)
		      {
		      	int y=atoi(port_no);
    			cse4589_print_and_log("[PORT:SUCCESS]\n");
    			cse4589_print_and_log("PORT:%d\n", y);
    			cse4589_print_and_log("[PORT:END]\n");
		      }
		      else if(strcmp(store[0],"LOGIN")==0)
		      {
		      	login=TRUE;
		      	//printf("In login\n");
		      	port2=atoi(store[2]);
		      	ip_addr=(char*) malloc(sizeof(char)*CMD_SIZE);
		      	ip_addr=store[1];
		      	break;
		      }
			else if(strcmp(store[0],"EXIT\n")==0)
                      {/*
			cse4589_print_and_log("[EXIT:SUCCESS]\n");
                       // cse4589_print_and_log("PORT:%d\n", y);
                        cse4589_print_and_log("[EXIT:END]\n");
			*/
			exit(1);	
			return 0;		
                      } 
		    }


		    while(login==TRUE)
		    {
		    	
		    int client_socket, head_socket, i;
		    struct sockaddr_in remote_server_addr;
		    fd_set master_list;
		    fd_set watch_list;

		    /*Create client socket*/
		    client_socket=socket(AF_INET,SOCK_STREAM,0);
		    if(client_socket==-1)
		    {
		    //    perror("Socket Error");
		        exit(1);
		    }

		    remote_server_addr.sin_family=AF_INET;
		    remote_server_addr.sin_port=htons(port2);
		    remote_server_addr.sin_addr.s_addr=inet_addr(ip_addr);
		    memset(remote_server_addr.sin_zero,'\0',sizeof(remote_server_addr.sin_zero));


		    int res2 =connect(client_socket,(struct sockaddr *)&remote_server_addr,sizeof(remote_server_addr));
		    
			if(res2<0)
			{
		       cse4589_print_and_log("[LOGIN:ERROR]\n");
		       cse4589_print_and_log("[LOGIN:END]\n");	
		       login=false;
			goto JUMP;//exit(1);
		    }
		    else if(res2>=0)
		{  
          	     cse4589_print_and_log("[LOGIN:SUCCESS]\n");
		     cse4589_print_and_log("[LOGIN:END]\n");
		 }   

		    FD_ZERO(&master_list);
		    FD_ZERO(&watch_list);
		    FD_SET(0, &master_list);
		    FD_SET(client_socket, &master_list);
		    head_socket = client_socket;

		    char *buffer2=malloc(sizeof(char)*BUFSIZE);
		    memset(buffer2, '\0', BUFSIZE);

		    buffer2=port_no;
		    if(send(client_socket, buffer2, strlen(buffer2), 0)<=0)
		    {
		    	cse4589_print_and_log("error while sending\n");
		    }

		    while(1)
		    {
		        watch_list = master_list;
		        if(select(head_socket+1, &watch_list, NULL, NULL, NULL) == -1)
		        {
		                perror("select");
		                exit(4);
		        }

		        for(i=0; i <= head_socket; i++ )
		        if(FD_ISSET(i, &watch_list))
		        {

		            char send_buf[BUFSIZE];
		            char recv_buf[BUFSIZE];
		            char recv_buf2[BUFSIZE];
		            char recv_buf4[BUFSIZE];

                            int bytesrecvd,bytes_recvd2;   
		           // int bytesrecvd;

		            if (i == 0)
		            {
		        	/* process commands here */
		              fgets(send_buf, BUFSIZE, stdin);
		              char * pch1, *store1[30];
		              int i1,counter1=0;
		              for(i1=0;i1<30;i1++)
		              {
		                store1[i1]=malloc(sizeof(char)*100);
		              }
		              
		              pch1 = strtok (send_buf," ");
		              while (pch1 != NULL)
		              {
		              
		                store1[counter1]=pch1;
		                counter1++;
		                pch1 = strtok (NULL, " ");    
		              }
				char command5[600];
				char command6[600];
                              strcpy(command5,store1[21]);
				strcpy(command6,store1[1]);
				strcat(command6," ");
				strcat(command6,store1[2]);
                              int i5;
							  for(i5=3;i5<counter1;i5++)
							  {    
							    strcat(command6," ");
                                                            strcat(command6, store1[i5]);	
							    strcat(command5," ");
							    strcat(command5, store1[i5]);
							  }		
		              int y =print_cmd2(send_buf);
		                //       printf("To send %s\n",command5); 
		    	        if(y==3)
		    	        {
		                /*printf("Need to send %s to %s\n",store1[2], store1[1]);*/
		               cse4589_print_and_log("[SEND:SUCCESS]\n");
				 send(client_socket, store1[1], strlen(store1[1]),0);
		                send(client_socket, command5, strlen(command5), 0);
				cse4589_print_and_log("[SEND:END]\n");
		              } 

		              if(y==4)
		              {
		                /*printf("Need to send %s to everyone",store1[2]);*/
		                strcpy(store1[0],"BROADCAST");
		                send(client_socket, store1[0], strlen(store1[0]),0);
		                send(client_socket, command6, strlen(command6), 0);
		              } 

		              if(y==5)
		              {
		                /*printf("In LIST\n");*/
		                char list[256]="LIST";
		               char recv2[256];
		                char list2[10][256];
		                char list3[10][256];
		                strcpy(store1[0],"LIST");
		                send(client_socket, store1[0], strlen(store1[0]),0);
		                recv(client_socket,recv2, sizeof(int),0);
		                int sock_no=atoi(recv2);
		                printf("No of sockets : %d\n", sock_no);
		                int i7;
		                for(i7=1;i7<sock_no;i7++)
		                {
		                  recv(client_socket,list2[i7],256,0);
		                  strcpy(IPADDRS[i7],list2[i7]);
		                 printf("Received IP%s\n", list2[i7]);
				 
  		                // memset(list2, 0, 256);
		                }
		                /*int y[10];*/
				int i8;
		                for(i8=1;i8<sock_no;i8++)
		                { 
		                  recv(client_socket, list3[i8],256,0);
		                  strcpy(PORTNOS[i8],list3[i8]);
		                  printf("Received Port no %s\n", list3[i8]);
		                }
		              //  printlist(sock_no);
		              }

		              if(y==6)
		              {
		                strcpy(store1[0],"EXIT");
		                send(client_socket, store1[0], strlen(store1[0]),0);
		               // printf("client-quited\n");
		            //   	cse4589_print_and_log("[EXIT:SUCCESS]\n");
                                   // cse4589_print_and_log("msg from:%s\n[msg]:%s\n", recv_buf4, recv_buf);
                              //      cse4589_print_and_log("[EXIT:END]\n"); 
		                close(client_socket);
		                return 0;
		              }
		            }

		                else
		                {
				    bytes_recvd2=recv(client_socket, recv_buf4, BUFSIZE, 0);
		                    bytesrecvd = recv(client_socket, recv_buf, BUFSIZE, 0);
		                    recv_buf[bytesrecvd] = '\0';
				   
                                    cse4589_print_and_log("[RECEIVED:SUCCESS]\n");
                                    cse4589_print_and_log("msg from:%s\n[msg]:%s\n", recv_buf4, recv_buf);
                                    cse4589_print_and_log("[RECEIVED:END]\n");
		                    //cse4589_print_and_log("%s\n" , recv_buf);
		                    fflush(stdout);
		                }

				        }
				    }

						    login=false;
						    cse4589_print_and_log("client-quited\n");
						    close(client_socket);
		    			}
					}
	return 0;
}


