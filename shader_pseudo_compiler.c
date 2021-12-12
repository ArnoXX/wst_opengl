#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char* source_name = argv[1];
    char result_name[strlen(source_name)+2]; 
    for(int i = 0; i < strlen(source_name); i++)
    {
        result_name[i] = source_name[i];
    }
    result_name[strlen(source_name)] = '.';
    result_name[strlen(source_name)+1] = 'h';
    result_name[strlen(source_name)+2] = '\0';

    FILE *source = fopen(source_name, "r+");
    FILE *result = fopen("result_name.txt", "w");
    if(source == NULL || result == NULL) 
    {
        printf("Fail");
        return 0;
    }
    char buf[] = "const char* "; 
    char c;
    strncat(buf, source_name, strlen(source_name)-3);
    strcat(buf, " = \"");
    
    for(int i = 0; i < strlen(buf); i++)
    {
        printf("putting %d", strlen(buf));
        fputc(buf[i], result);
    }



    fclose(source);
    fclose(result);

    return 0;
}