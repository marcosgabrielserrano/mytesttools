
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


void write_byte(char *val)
{
    int fd = open("/tmp/.test_bytes", O_CREAT | O_APPEND | O_WRONLY, 0666);
    if(fd < 0)
    {
        _exit(1);
    }
    if(write(fd, val, strlen(val)) < 0)
    {
        _exit(1);
    }
    close(fd);
}

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        _exit(1);
    }
    while(1)
    {
        sleep(1);
        write_byte(argv[1]);
    }
    return 0;
}
