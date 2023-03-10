#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv){
    int i =0;
    while(i++ < argc-1)
        printf("%s\n", argv[i]);

}

//int main(void){
  //  char buf[317];
    //int fd= open("correct.c", O_RDONLY); or "argv[1]"
    //int nb_read= read(fd, buf, 317);
    //printf("%s\n", buf);
    //printf("%i\n", nb_read);
    //buf[317] = '\0';
    //close(fd);
//}