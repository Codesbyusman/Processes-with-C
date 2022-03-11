/*

    ----------------------------------------------------
    ------------ Muhammad Usman Shahid -----------------
    -------------------- 20I-1797 ----------------------
    ------------------------ T -------------------------
    ----------------------------------------------------

*/

#include <stdio.h>
#include <unistd.h> //maintaining standards
#include <sys/wait.h>
#include <sys/types.h> //pid_t  creation
#include <stdlib.h>    //memory allocation
#include <errno.h>

void main()
{

    // for making the child
    pid_t firstChild = fork(); // the child has been created

    // checking the child proccess created or not
    if (firstChild >= 0)
    {

        // ccreating anoher child in the child
        if (firstChild == 0)
        {
            // the child
            pid_t secondChild = fork(); // another child forked

            if (secondChild >= 0) // validating the child has made or not
            {
                if (secondChild == 0)
                {
                    // the path array is the vector,list that contains command name and parameters
                    char *path[] = {"ls", "-l", NULL};

                    printf("\n\t :::::: The ls for current directory :::::: \n\n");

                    // the child of child doing the desired thing in it
                    // using the ecexvp to ls the current directory
                    if (execvp("ls", path) == -1) // ls command will be searched automaticallay as execvp and path contains name and parameters
                    {
                        // mean failed thus
                        printf("\n\n\t\t :::::: child failed :::::: \n\n");
                        exit(1); // exiting that failed telling parent not to print successfull
                    }
                }
                else
                {
                    int x = 0; // to recieve the exit value
                    // parent
                    wait(&x); // the parent waiting for child
                    x /= 255; // mapping correctly

                    // if failed then not print this message else print this
                    if (x != 1)
                    {
                        printf("\n\n\t\t :::::: child Successful :::::: \n\n");
                    }
                }
            }
            else
            {
                // the error message
                printf("\n\t\t Error --- child proccesses can't be made \n\n");
            }
        }
        else
        {
            // parent
            wait(NULL); // the parent waiting for child
        }
    }
    else
    {
        // the error message
        printf("\n\t\t Error --- child proccesses can't be made \n\n");
    }
}
 