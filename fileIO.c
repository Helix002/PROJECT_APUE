//
// Created by suzol on 2021/10/5.
//

#include "fileIO.h"

int test_lseek()
{
    if (-1 == lseek(STDIN_FILENO, 0, SEEK_CUR))
        printf("cannot seek\n");
    else
        printf("seek OK\n");

    exit(0);
}

int create_hole_file()
{
    char buf1[] = "abcdefghij";
    char buf2[] = "ABCDEFGHIJ";

    int fd;
    if(0 > (fd = creat("file.hole", FILE_MODE)))
        err_sys("create error");

    if(10 != write(fd, buf1, 10))
        err_sys("buf1 write error");

    if(-1 == lseek(fd, 54321, SEEK_SET))
        err_sys("lseek error");

    if(10 != write(fd, buf2,10))
        err_sys("buf2 write error");

    exit(0);
}

int efficientIO()
{
    int n;
    char buf[BUFFSIZE];

    while (0 < (n = read(STDIN_FILENO, buf, BUFFSIZE)))
        if (n != write(STDOUT_FILENO, buf, n))
            err_sys("write error");

    if (n < 0)
        err_sys("read error");

    exit(0);
}