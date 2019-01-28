int open_listener_socket();
void bind_to_port(int socket, int port);
int say(int socket, char* s);
int read_in(int socket, char* buf, int len);
void error(char* msg);
void handle_shutdown(int sig);
int catch_signal( int sig, void(*handler)(int) );

