#include <iostream>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <exception>
#include <string.h>
#include <errno.h>
using namespace std;


int main(int argc, char const *argv[])
{
	int listen_fd, connect_fd;
	struct sockaddr_in server_addr, client_addr;
	socklen_t client_len;
	pid_t child_pid;
	ssize_t n;
	char buff[50];

	try{

		if( (listen_fd=socket(AF_INET, SOCK_STREAM, 0))<0 )
			throw "socket err!!";

		bzero(&server_addr, sizeof(server_addr));
		server_addr.sin_family = AF_INET;
		server_addr.sin_addr.s_addr = htonl(INADDR_ANY);//通配地址
		server_addr.sin_port = htons(6000);

		if( bind(listen_fd, (struct sockaddr*) &server_addr, sizeof(server_addr) )<0 )
			throw "bind err!!";

		if( listen(listen_fd, 5)<0 )
			throw "listen err!!";

		cout << "wait client connect ..." << endl;
		

		while(1){
			client_len = sizeof(client_addr);
			//accept会堵塞，因此不用循环
			if( (connect_fd=accept(listen_fd, (struct sockaddr*) &client_addr, &client_len)) <0 )
				throw "accept err!!";

			if( (child_pid = fork()) ==0){ //==0为子进程
				close(listen_fd);

				char* client_ip = inet_ntoa(client_addr.sin_addr);
				cout << "your client's ip is " << client_ip << endl;
				while( (n=read(connect_fd, buff, 50)) >0 )
					write(connect_fd, buff, n);
				if(n<0)
					throw "read err!";
				exit(0);
			}
			close(connect_fd);
		}

		exit(0);//关闭所有描述符

	}
	catch(const char* msg){
		cerr << msg << endl;
	}
	return 0;
}






