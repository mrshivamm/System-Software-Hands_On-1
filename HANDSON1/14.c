#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    struct stat st;

    if (argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    if (lstat(argv[1], &st) == -1)
    {
        perror("lstat");
        return 1;
    }

    if (S_ISREG(st.st_mode))
        printf("%s : Regular file\n", argv[1]);

    else if (S_ISDIR(st.st_mode))
        printf("%s : Directory\n", argv[1]);

    else if (S_ISLNK(st.st_mode))
        printf("%s : Symbolic link\n", argv[1]);

    else if (S_ISFIFO(st.st_mode))
        printf("%s : FIFO (named pipe)\n", argv[1]);

    else if (S_ISSOCK(st.st_mode))
        printf("%s : Socket\n", argv[1]);

    else if (S_ISCHR(st.st_mode))
        printf("%s : Character device\n", argv[1]);

    else if (S_ISBLK(st.st_mode))
        printf("%s : Block device\n", argv[1]);

    else
        printf("%s : Unknown file type\n", argv[1]);

    return 0;
}
