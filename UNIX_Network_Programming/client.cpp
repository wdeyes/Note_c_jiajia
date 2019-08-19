#include <iostream>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <exception>
#include <string.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int client_fd;
	struct sockaddr_in server_addr;

	try{

		if( (client_fd=socket(AF_INET, SOCK_STREAM, 0)) < 0 )
			throw "socket err!!";

		bzero(&server_addr, sizeof(server_addr));
		server_addr.sin_family = AF_INET;
		server_addr.sin_port = htons(6000);
		const char* server_ip = "192.168.0.182";
		if( inet_aton(server_ip, &server_addr.sin_addr) <0 )
			throw "inet_aton err!!";

		if( connect(client_fd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0)
			throw "connect err!!";

		char buff[50];
		while(cin >> buff){
			write(client_fd, buff, strlen(buff));
			char temp[50];
			ssize_t n = read(client_fd, temp, 50);
			temp[n]='\0';
			cout << temp << endl;
		}

		exit(0);

	}catch(const char* msg){
		cerr << msg << endl;
	}


	return 0;
}