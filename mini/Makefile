SERVER = server
CLIENT = client

CFLAGS = -Wall -Wextra -Werror


all :
		@gcc $(FLAGS) server.c utils.c -o $(SERVER)
		@gcc $(FLAGS) client.c utils.c -o $(CLIENT) 

clean :
	@rm -rf $(SERVER) $(CLIENT)

re : clean all