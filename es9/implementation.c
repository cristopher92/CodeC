#include "cl_list.h"
#include "stdio.h"

int main(){
    struct cl_list *list = create_list();
    char cf[16];
    int input = -1, empty;
    struct client *new_client;
    while (input != 0){
        printf("\nInsert the operation\n"
               "0 to terminate\n"
               "1 to add a new client\n"
               "2 to print the list\n"
               "3 to remove a client\n"
               "4 to the count of the list\n"
               "5 to know if the list is empty\n\n");
        while (scanf("%d", &input) != 1) {
                printf("Invalid input. Please insert a valid integer: \n");
                scanf("%*[^\n]"); // discard the rest of the line
        }
        printf("\n");

        switch (input) {
            case 0:
                break;
            case 1:
                new_client = add_new_client();
                list = add_cl(list, new_client);
                break;
            case 2:
                print_list(list);
                break;
            case 3:
                printf("Insert the CF of the client to remove: \n");
                scanf("%s", cf);
                list = rem_cl(list, cf );
                break;
            case 4:
                printf("%d\n", list_length(list));
                break;
            case 5:
                empty = list_is_empty(list);
                if(empty){
                    printf("The list is empty\n");
                } else{
                    printf("The list is not empty\n");
                }
                break;
            default:
                printf("Insert a number between 0 and 5\n");
        }

    }

}