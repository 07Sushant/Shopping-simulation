#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

int main()
{

    int option;
    char customer_name[100];
    char mobile_number[20];
    char browse_menu[4];
    char line[200];
    char category[50];
    int found = 0;
    char item[20];

    FILE *file;

    printf("\n");
    printf("\n");
    printf("+--------------------------------------------------------+\n");
    printf("|                 \033[1mWelcome To LPU Billing System\033[0m          |\n");
    printf("+--------------------------------------------------------+\n");
    printf("|                      \033[4mOn Going Offers\033[0m                   |\n");
    printf("+--------------------------------------------------------+\n");
    printf("|       < 5000 buy - \033[3m\033[32m0%%\033[0m\033[0m discount                         |\n");
    printf("|       5000 + buy - \033[3m\033[32m5%%\033[0m\033[0m discount                         |\n");
    printf("|       10000 + buy - \033[3m\033[32m10%%\033[0m\033[0m discount                       |\n");
    printf("|       15000 + buy - \033[3m\033[32m15%%\033[0m\033[0m discount                       |\n");
    printf("+--------------------------------------------------------+\n");

    printf("\n");
    printf("\n");
    printf("\033[1m+-----------------------Dashboard------------------------+\033[0m\n");

    printf("\033[1m| 1. New Customer | | 2. Existing Customer | | 3. Employee|\033[0m\n");
    printf("\nSelect an option: ");
    
    scanf("%d", &option);

    if (option == 1)
    {
        printf("Enter customer name: ");
        scanf("%s", customer_name);
        printf("Enter mobile number: ");
        scanf("%s", mobile_number);

        file = fopen("data/customer_name.txt", "a");
        fprintf(file, "Customer Name: %s\nMobile Number: %s\n\n", customer_name, mobile_number);
        fclose(file);

        printf("Customer details saved successfully.\n");
    }
    else if (option == 2)
    {
        printf("Enter the registered mobile number: ");
        scanf("%s", mobile_number);

        file = fopen("data/customer_name.txt", "r");
        if (file == NULL)
        {
            printf("Error: Unable to open file.\n");
            exit(1);
        }

        char line[200];
        int found = 0;
        while (fgets(line, sizeof(line), file))
        {
            if (strstr(line, mobile_number) != NULL)
            {
                printf("Since you are an existing customer, you are eligible for exclusive offers.\n\n");
                found = 1;
                break;
            }
        }

        fclose(file);

        if (!found)
        {
            printf("No customer found with the given mobile number.\n");
        }
    }
    else if (option == 3)
    {
        printf("\033[1m Employee Mode.\033[0m\n");
    }
    else
    {
        printf("Invalid option selected.\n");
    }

    printf("\n");
    printf("\033[1mDo you want to browse the menu? (YES/NO):\033[0m ");
    scanf(" %3s", browse_menu);

    // convert browse_menu to uppercase for validation
    for (int i = 0; browse_menu[i]; i++)
    {
        browse_menu[i] = toupper(browse_menu[i]);
    }

    if (strcmp(browse_menu, "YES") == 0)
    {
        // run menu.c file here
        int ret = system("menu.exe");
    }
    return 0;
}


