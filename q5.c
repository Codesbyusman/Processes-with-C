/*

    ----------------------------------------------------
    ------------ Muhammad Usman Shahid -----------------
    -------------------- 20I-1797 ----------------------
    ------------------------ T -------------------------
    ----------------------------------------------------

*/


#include <stdio.h>
#include <unistd.h>   //maintaining standards
#include <sys/wait.h> 
#include <sys/types.h>//pid_t  creation
#include <stdlib.h>   //memory allocation

void main()
{

    // the main parent process
    // creating the first child for the parent
    pid_t mainChild1 = fork(); /// created the child;

    if (mainChild1 >= 0) // checking whther child made or not
    {

        // if child then making another child according to the given hirearchray
        if (mainChild1 == 0)
        {
            // the child of main
            pid_t grandchild = fork();

            if (grandchild >= 0) // checking whther child mde or not
            {
                if (grandchild == 0)
                {
                    // the child of p2 -- p4 in diagram
                    printf("\n\n\t I am P4 with ID : %d \n", getpid());
                    printf("\t I am P4 with Parent ID : %d \n", getppid());
                }
                else
                {
                    // else for the second child
                    printf("\n\n\t I am P2 with ID : %d \n", getpid());
                    printf("\t I am P2 with Parent ID : %d \n", getppid());
                    wait(NULL);
                }
            }
            else
            {
                // if unable to make the child
                printf("\n\t\t Can't make the child processes P4 of P2--- error \n\n");
            }
        }
        else
        {
            // the first main
            printf("\t I am P1 with ID : %d \n", getpid());
            printf("\t I am P1 with Parent ID : %d \n", getppid());

            // and then making another child
            pid_t mainChild2 = fork(); // the other child

            if (mainChild2 >= 0) // checking whther child mde or not
            {
                // the child p3
                if (mainChild2 == 0)
                {
                    // the other child of main
                    printf("\n\n\t I am P3 with ID : %d \n", getpid());
                    printf("\t I am P3 with Parent ID : %d \n", getppid());
                }
            }
            else
            {
                // if unable to make the child
                printf("\n\t\t Can't make the child processes P3 of P1--- error \n\n");
            }

            wait(NULL); // wait till the whole is executed child
        }
    }
    else
    {
        // if unable to make the child
        printf("\n\t\t Can't make the child processes --- error \n\n");
    }
}
 