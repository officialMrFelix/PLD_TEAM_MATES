#include <stdio.h>
#include <unistd.h>

/**
 * main - PID
 *
 * Return: Always 0.
 */

int main(void)
{
    pid_t my_name;
    pid_t my_pname;

    my_name = getpid();
    my_pname = getppid();

    printf("My id is : %u\n\n", my_name);
    printf("My father's id is: %u\n", my_pname);
    return (0);
}


