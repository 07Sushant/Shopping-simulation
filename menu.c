#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ITEMS 50


typedef struct
{
    char name[100];
    float price;
} Item;

int main()
{
    FILE *fp_menu, *fp_items, *fp_prices;
    char line[200];
    char category[100], sub_item[100], price_str[10];
    Item items[MAX_ITEMS];
    int count = 0, i, sub_count = 0, selection;
    float total_price = 0;

    fp_menu = fopen("data/menu.txt", "r");
    if (fp_menu == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }
    while (fgets(line, sizeof(line), fp_menu))
    {
        printf("%s", line);
    }
    fclose(fp_menu);

    printf("\nEnter a category: ");
    scanf("%s", category);

    char filename[100];
    sprintf(filename, "data/%s.txt", category);
    fp_items = fopen(filename, "r");
    if (fp_items == NULL)
    {
        printf("data/%s.txt", category);
        printf("Error opening file.\n");
        return 1;
    }

    char price_filename[100];
    sprintf(price_filename, "data/%s_price.txt", category);
    fp_prices = fopen(price_filename, "r");
    if (fp_prices == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

   
    printf("\nSelect a sub-item:\n");
    while (fgets(line, sizeof(line), fp_items))
    {
        sub_count++;
        printf("%d. %s", sub_count, line);
    }
    fseek(fp_prices, 0, SEEK_SET);
    sub_count = 0;
    while (fgets(line, sizeof(line), fp_prices))
    {
        sub_count++;
        sscanf(line, "%s", price_str);
        items[count].price = atof(price_str);
        count++;
    }

 
    printf("\nEnter a selection: ");
    scanf("%d", &selection);
    if (selection < 1 || selection > sub_count)
    {
        printf("Invalid selection.\n");
        return 1;
    }
    fseek(fp_items, 0, SEEK_SET);
    fseek(fp_prices, 0, SEEK_SET);
    for (i = 1; i <= selection; i++)
    {
        fgets(sub_item, sizeof(sub_item), fp_items);
        fgets(price_str, sizeof(price_str), fp_prices);
        if (i == selection)
        {
            sscanf(price_str, "%s", price_str);
            items[count].name[strlen(sub_item) - 1] = '\0';
            strcpy(items[count].name, sub_item);
            items[count].price = atof(price_str);
            count++;
            total_price += atof(price_str);
            break;
        }
    }

    fclose(fp_items);
    fclose(fp_prices);

    char choice;
    do
    {
        printf("Do you want to buy another item? (Y/N): ");
        scanf(" %c", &choice);
        if (choice == 'Y' || choice == 'y')
        {
            printf("Enter a category: ");
            scanf("%s", category);

            sprintf(filename, "data/%s.txt", category);
            fp_items = fopen(filename, "r");
            if (fp_items == NULL)
            {
                printf("Error opening file.\n");
                return 1;
            }

            sprintf(price_filename, "data/%s_price.txt", category);
            fp_prices = fopen(price_filename, "r");
            if (fp_prices == NULL)
            {
                printf("Error opening file.\n");
                return 1;
            }

            printf("Select a sub-item:\n");
            sub_count = 0;
            while (fgets(line, sizeof(line), fp_items))
            {
                sub_count++;
                printf("%d. %s", sub_count, line);
            }
            fseek(fp_prices, 0, SEEK_SET);
            sub_count = 0;
            while (fgets(line, sizeof(line), fp_prices))
            {
                sub_count++;
                sscanf(line, "%s", price_str);
                items[count].price = atof(price_str);
                count++;
            }

            printf("Enter a selection: ");
            scanf("%d", &selection);
            if (selection < 1 || selection > sub_count)
            {
                printf("Invalid selection.\n");
                return 1;
            }
            fseek(fp_items, 0, SEEK_SET);
            fseek(fp_prices, 0, SEEK_SET);
            for (i = 1; i <= selection; i++)
            {
                fgets(sub_item, sizeof(sub_item), fp_items);
                fgets(price_str, sizeof(price_str), fp_prices);
                if (i == selection)
                {
                    sscanf(price_str, "%s", price_str);
                    items[count].name[strlen(sub_item) - 1] = '\0';
                    strcpy(items[count].name, sub_item);
                    items[count].price = atof(price_str);
                    count++;
                    total_price += atof(price_str);
                    break;
                }
            }

            fclose(fp_items);
            fclose(fp_prices);
        }
        else if (choice == 'N' || choice == 'n')
        {
            break;
        }
    } while (1);

    printf("Selected items:\n");
    for (i = 0; i < count; i++)
    {
        printf("%s - %.2f\n", items[i].name, items[i].price);
    }
    printf("Total price: %.2f\n", total_price); 
    system("pause");
    return 0;
}