#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <signal.h>

#include <sys/select.h>
#include <errno.h>

#include <fcntl.h>

#include <async/async.h>

#define socket_name "/home/globik/fuck"
#define buffer_size 512
int abba=0;
fd_set write_fds;
int data_socket;

void shutdown_properly(int b){

exit(b);
}
typedef  void(*on_suka)(int d);
void suka(int bc){
printf("SUKA!\n");
//sleep(10);
printf("AFTER SUKA\n");
}
void dow(int s, on_suka suk){
char buf[512];int ret;int moo=0;
	printf("before moo\n");
	if(moo==0){
strcpy(buf,"Hallo world!");
			int leni=strlen(buf)+1;
	        ret=send(s,buf, leni,  MSG_DONTWAIT | MSG_EOR);
	       if(ret==-1){
	        perror("write2");
		    exit(EXIT_FAILURE);
	        }
			printf("leni: %d, ret: %d\n",leni,ret);
			abba=1;
	//suka(4);
	}
	//else{return;}
	//abba=0;
	//suka(4);
	//printf("after moo\n");
}
void waiting(){
printf("waiting\n");
}
int br=0;
void HANI(int f){
printf("HANI\n");
//FD_SET(data_socket, &write_fds);
}
int main(int argc,char*argv[]){
struct sockaddr_un addr;

	int i;
	int ret;
	//int data_socket;
	char buffer[buffer_size];
	data_socket=socket(AF_UNIX,SOCK_SEQPACKET | O_NONBLOCK,0);
	if(data_socket==-1){
	perror("socket");
		exit(EXIT_FAILURE);
	}
	memset(&addr,0,sizeof(struct sockaddr_un));
	addr.sun_family=AF_UNIX;
	strncpy(addr.sun_path,socket_name,sizeof(addr.sun_path)-1);
	ret=connect(data_socket,(const struct sockaddr*)&addr,sizeof(struct sockaddr_un));
if(ret==-1){
fprintf(stderr,"the server is down\n");
	exit(EXIT_FAILURE);
}
	
	fd_set read_fds;
  fd_set except_fds;
	signal(SIGUSR1,HANI);
	
	while(1){
		br++;
		printf("BR_BR: %d\n",br);
		//if(br==3)abba=0;
	
FD_ZERO(&read_fds);
//  FD_SET(STDIN_FILENO, read_fds);
  FD_SET(data_socket, &read_fds);
  
  FD_ZERO(&write_fds);
  // there is smth to send, set up write_fd for server socket
	//printf("SERVER->SEND_BUFFER.CURRENT => %d\n",server->send_buffer.current);
  if (abba == 1){ 
	  printf("there is smth to send, set up write_fd for server socket!!!\n");
	  FD_SET(data_socket, &write_fds);
  }
  
  FD_ZERO(&except_fds);
 // FD_SET(STDIN_FILENO, except_fds);
  FD_SET(data_socket, &except_fds);
	//while(1){
  printf("BEFORE ACTIVITY\n");
		//sleep(5);
		raise(SIGUSR1);
		abba=0;
		printf("mu\n");
		//if(br==3){printf("HAHA!\n");abba==0; FD_SET(data_socket, &write_fds);}
	 int activity = select(data_socket + 1, &read_fds, &write_fds, &except_fds, NULL);
	  
    printf("ACTIVITY: %d\n",activity);
	
	switch (activity) {
      case -1:
        perror("select()");
		close(data_socket);
        shutdown_properly(EXIT_FAILURE);

      case 0:
        // you should never get here
        printf("select() returns 0.\n");
		close(data_socket);
        shutdown_properly(EXIT_FAILURE);

      default:
        /* All fd_set's should be checked. */
			/*
        if (FD_ISSET(STDIN_FILENO, &read_fds)) {
			printf("STDIN READ_FDS!!!!!!!!\n");
          if (handle_read_from_stdin(&server, client_name) != 0)
            shutdown_properly(EXIT_FAILURE);
        }
*/
        if (FD_ISSET(data_socket, &read_fds)) {
			 printf("SERVER READ_FDS!!!!!!!!!!!\n");
          //if (receive_from_peer(&server, &handle_received_message) != 0)
          //  shutdown_properly(EXIT_FAILURE);
	ret=read(data_socket,buffer,buffer_size);
	if(ret==-1){
	perror("read");
		exit(EXIT_FAILURE);
	}
	buffer[ret-1]=0;
	printf("result => %s\n",buffer);
		//abba=0;	
        }

        if (FD_ISSET(data_socket, &write_fds)) {
			printf("SERVER WRITE_FDS!!!!!!!!!!!!!!!!\n");
			int i=0;int bu=0;
			/*do{i++;
			   //59095
			  printf("do: %d",i);
			  // if(i==59095){i==0;break;}
			  }while(1);
			  */
			//while(bu =0){
		//	printf("suka");
			//}
			printf("a\n");
			//alarm(1);
			printf("b\n");
			//pause();
		//	wait(20);
			//i=0;
			printf("I$$$$$$$$$$= %d\n",i);
			
			dow(data_socket,suka);
			
           }

        if (FD_ISSET(data_socket, &except_fds)) {
          printf("except_fds for server.\n");
			close(data_socket);
          shutdown_properly(EXIT_FAILURE);
        }
    }
    
	printf("end of while\n");
}
exit(EXIT_SUCCESS);
}