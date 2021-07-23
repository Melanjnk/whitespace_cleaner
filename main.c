#include <stdio.h>
#include <string.h>

#define DUPLICATE_CHAR '_'

#define BASE_CASE "_On__my___home_world"
#define CASE_WHITESPACE_IN_THE_END "_On__my___home_world_"
#define CASE_WHITESPACES_IN_THE_END "_On__my___home_world___"
#define CASE_WHITESPACE_AT_THE_BEGGINING "___On__my___home_world"
#define CASE_WHITESPACES_AT_THE_BEGGINING_AND_IN_THE_END "___On__my___home_world____"

char *shiftLeftToIndent(char str[], int pos, int indent)
{
    int len = strlen(str);
    int lenSubStr = len-(pos+2) ;
    for (int j=0; j <= lenSubStr; j++)
    {
        str[pos+j] = str[pos+j+(indent - pos-1)];
    }
    str[len-1] = '\0';
}

int getFirstNotDuplicateChar(char str[], int indent)
{
    int k = 0;
    int len = strlen(str);
    for(k=indent; k<=len; k++)
    {
        if (DUPLICATE_CHAR != str[k]) {
            break;
        }
    }
    return k;
}

char *cleaner(char str[])
{

    if (DUPLICATE_CHAR == str[0]){
        int startIndent = getFirstNotDuplicateChar(str, 0);
        shiftLeftToIndent(str, 0, startIndent + 1);
    }
    int len = strlen(str);
    for(int i=0; i <= len;i++)
    {
        if (DUPLICATE_CHAR == str[i] && DUPLICATE_CHAR == str[i+1] ){
            int k2 = getFirstNotDuplicateChar(str, i);
            shiftLeftToIndent(str, i, k2);
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



