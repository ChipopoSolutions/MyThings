#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>



char* read_from_file (const char* filename, size_t length)
{
    char* buffer;
    int fd;
    ssize_t bytes_read;

    /* Allocate the buffer. */
    buffer = (char*) malloc (length);

    if (buffer == NULL)
        return NULL;

    /* Open the file. */
    fd = open (filename, O_RDONLY);

    if (fd == -1) { /* open failed. Deallocate buffer before returning. */
        free (buffer);
        return NULL;
    }

    /* Read the data. */
    bytes_read = read (fd, buffer, length);

    if (bytes_read != length) {
    /* read failed. Deallocate buffer and close fd before returning.*/
    free (buffer);
    close (fd);
    return NULL;
    }
    /* Everything’s fine. Close the file and return the buffer. */
    close (fd);
    return buffer;

}

int main (int argc, char* argv[])
{
    char* arr = (char*)malloc(27);
    const char* file_name = "./temp.txt";

    printf("call to read_from_file(./non-exist.txt,27); - ");
    arr=read_from_file( "./non-exist.txt",27);
    check_arr_and_print(arr);

    printf("call to read_from_file(./temp.txt,-1); - ");
    arr=read_from_file(file_name,-1);
    check_arr_and_print(arr);

    printf("call to read_from_file(./temp.txt,8888); - ");
    arr=read_from_file(file_name,8888);
    check_arr_and_print(arr);

    printf("call to read_from_file(./temp.txt,27); - ");
    arr=read_from_file(file_name,27);
    check_arr_and_print(arr);
}

void check_arr_and_print(char* ptr)
{
        if(ptr==NULL)
            printf("NULL \n");
        else
            printf("SUCCESS \n");
}