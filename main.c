#include <stdio.h>
#include <string.h>

#define DUPLICATE_CHAR '_'

#define BASE_CASE "_On__my___home_world"
#define CASE_WHITESPACE_IN_THE_END "_On__my___home_world_"
#define CASE_WHITESPACES_IN_THE_END "_On__my___home_world___"
#define CASE_WHITESPACE_AT_THE_BEGGINING "___On__my___home_world"
#define CASE_WHITESPACES_AT_THE_BEGGINING_AND_IN_THE_END "___On__my___home_world____"

char *shiftLeftToOne(char str[], int pos)
{
    int len = strlen(str);
    int lenSubStr = len-(pos+2) ;
    for (int j=0; j <= lenSubStr; j++)
    {
        str[pos+j] = str[pos+j+1];    
    }
    str[len-1] = '\0';
}

char *cleaner(char str[])
{
    int len = strlen(str);
    if (DUPLICATE_CHAR == str[0]){
        shiftLeftToOne(str, 0);
    }
    for(int i=0; i <= len;i++)
    {
        if (DUPLICATE_CHAR == str[i] && str[i] == str[i+1] ){
            shiftLeftToOne(str, i);
        }
        if (DUPLICATE_CHAR == str[i] && DUPLICATE_CHAR == str[i+1]) 
        {
            cleaner(str);
        }
    }
    
    int lenAfter = strlen(str);
    
    if(DUPLICATE_CHAR == str[lenAfter-1]) 
    {
        str[lenAfter-1] = '\0';
    }
    return str;
}

void testCleaner(char * caseTitle, char * before, char * after)
{
    cleaner(after);
    printf("%s: [Before: \"%s\", After: \"%s\"] \n", caseTitle, before, after);
}

int main()
{
    char base_case_string[] = BASE_CASE;
    char string_with_whitespace_in_the_end[] = CASE_WHITESPACE_IN_THE_END;
    char string_with_whitespaces_at_the_beggining[] = CASE_WHITESPACE_AT_THE_BEGGINING;
    char string_with_whitespaces_in_the_end[] = CASE_WHITESPACES_IN_THE_END;
    char string_with_whitespaces_at_the_beggining_and_in_the_end[] = CASE_WHITESPACES_AT_THE_BEGGINING_AND_IN_THE_END;
    
    testCleaner("BASE_CASE", BASE_CASE, base_case_string);
    testCleaner("CASE_WHITESPACE_IN_THE_END", CASE_WHITESPACE_IN_THE_END, string_with_whitespace_in_the_end);
    testCleaner("CASE_WHITESPACES_IN_THE_END", CASE_WHITESPACES_IN_THE_END, base_case_string);
    testCleaner("CASE_WHITESPACE_AT_THE_BEGGINING", CASE_WHITESPACE_AT_THE_BEGGINING, string_with_whitespaces_at_the_beggining);
    testCleaner("CASE_WHITESPACES_AT_THE_BEGGINING_AND_IN_THE_END", CASE_WHITESPACES_AT_THE_BEGGINING_AND_IN_THE_END, string_with_whitespaces_at_the_beggining_and_in_the_end);
    
    return 0;
}

