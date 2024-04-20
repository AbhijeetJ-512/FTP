all: Server Client

Server: Server.c
	gcc Server.c -o server

Client: Client.c
	gcc Client.c -o client

clean:
	rm server client
