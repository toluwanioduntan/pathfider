#include "libmx.h"

int mx_read_line(char **lineptr, int buf_size, char delim, const int fd){
    if (buf_size >= 1 && buf_size <= 2147483647){
        char *buf = mx_strnew(buf_size);
        char *str = mx_strnew(buf_size);
        size_t type;
        if (fd > 0){
            while ((type = read(fd,buf,buf_size)) > 0) {
                mx_strcat(str, buf);
            }
            if(type < 0){
                return -1;
            }
            int index = mx_get_char_index(str, delim);
            if (index != -1) {
                mx_strncpy(*lineptr, str, index);
            }
            else{
                *lineptr = str;
                return -1;
            }
            close(fd);
            free(buf);
            free(str);
            return index;
        }
    }
    return -2;
}
