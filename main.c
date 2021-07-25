#include <stdio.h>
#include <string.h>

#define DUPLICATE_CHAR '_'

#define ONLY_WHITESPACE_CASE "_"
#define ONLY_WHITESPACES_CASE "_________"
#define BASE_CASE "_On__my___home_world"
#define BASE_CASE_CHAR_AT_THE_BEGGING "On__my___home_world"
#define ALL_GOOD_CASE "On_my_home_world"
#define CASE_WHITESPACE_IN_THE_END "_On__my___home_world_"
#define CASE_WHITESPACES_IN_THE_END "_On__my___home_world___"
#define CASE_WHITESPACE_AT_THE_BEGINNING "___On__my___home_world"
#define CASE_WHITESPACES_AT_THE_BEGINNING_AND_IN_THE_END "___On__my___home_world____"

#define EXPECTED_RESULT "On_my_home_world"


void normalize(char str[])
{
    int i = 1, j;
    if (DUPLICATE_CHAR == str[0])
    {
        for ( ; DUPLICATE_CHAR == str[i]; ++i);
        if ('\0' == str[i])
        {
            str[0] = '\0';
            return;
        }
        j = 0;
    } else {
        do {
            if ('\0' == str[++i])
            {
                return;
            }
        } while(DUPLICATE_CHAR != str[i] || DUPLICATE_CHAR != str[i + 1]);
        j = i;
    }
    for ( ; ; )
    {
        while (DUPLICATE_CHAR != str[i])
        {
            if('\0' == (str[j++] = str[i++]))
            {
                return;
            }
        }
        if (DUPLICATE_CHAR == str[++i])
        {
            while (DUPLICATE_CHAR == str[++i]);
            if ('\0' == str[i]) {
                str[j] = '\0';
                return;
            }
        }
        str[j++] = DUPLICATE_CHAR;
    }
}

void testNormalize(char title[], char str[], char expected[])
{
    printf("Before[%s]: '%s'\n", title, str);
    normalize(str);

    if(0 == strcmp(str, expected))
    {
        printf("success %s: [Result: \"%s\", ExpectedResult: \"%s\"] \n", title, str, expected);
    } else {
        printf("failure %s: [Result: \"%s\", ExpectedResult: \"%s\"] \n", title, str, expected);
    }
}

int main()
{
    char onlyWhitespaceCase[] = ONLY_WHITESPACE_CASE;
    char onlyWhitespacesCase[] = ONLY_WHITESPACES_CASE;
    char baseCase[] = BASE_CASE;
    char allGoodCase[] = ALL_GOOD_CASE;
    char homeWorld[] = "my___home_world";
    char baseCaseCharAtTheBegging[] = BASE_CASE_CHAR_AT_THE_BEGGING;
    char string_with_whitespace_in_the_end[] = CASE_WHITESPACE_IN_THE_END;
    char string_with_whitespaces_at_the_beginning[] = CASE_WHITESPACE_AT_THE_BEGINNING;
    char string_with_whitespaces_in_the_end[] = CASE_WHITESPACES_IN_THE_END;
    char string_with_whitespaces_at_the_beginning_and_in_the_end[] = CASE_WHITESPACES_AT_THE_BEGINNING_AND_IN_THE_END;

    testNormalize("ONLY_WHITESPACE_CASE", onlyWhitespaceCase, "");
    testNormalize("ONLY_WHITESPACES_CASE", onlyWhitespacesCase, "");
    testNormalize("BASE_CASE", baseCase, EXPECTED_RESULT);
    testNormalize("ALL_GOOD_CASE", allGoodCase, EXPECTED_RESULT);
    testNormalize("my___home_world", homeWorld, "my_home_world");
    testNormalize("BASE_CASE_CHAR_AT_THE_BEGGING", baseCaseCharAtTheBegging, EXPECTED_RESULT);
    testNormalize("CASE_WHITESPACE_IN_THE_END", string_with_whitespace_in_the_end, EXPECTED_RESULT);
    testNormalize("CASE_WHITESPACES_IN_THE_END", string_with_whitespaces_in_the_end, EXPECTED_RESULT);
    testNormalize("CASE_WHITESPACE_AT_THE_BEGINNING", string_with_whitespaces_at_the_beginning, EXPECTED_RESULT);
    testNormalize("CASE_WHITESPACES_AT_THE_BEGINNING_AND_IN_THE_END", string_with_whitespaces_at_the_beginning_and_in_the_end, EXPECTED_RESULT);
    return 0;
}
