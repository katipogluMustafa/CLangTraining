#include <regex.h>

bool match(regex_t *pexp, char *sz) {
    regmatch_t matches[MAX_MATCHES];                            //A list of the matches in the string (a list of 1)
    bool rv;

    //Compare the string to the expression
    //regexec() returns 0 on match, otherwise REG_NOMATCH
    if (regexec(pexp, sz, MAX_MATCHES, matches, 0) == 0) {
        printf("\"%s\" matches characters %d - %d\n", sz, matches[0].rm_so, matches[0].rm_eo);
        rv = TRUE;
    } else {
        printf("\"%s\" does not match\n", sz);
        rv = FALSE;
    }

    return rv;
}



bool regex_match(char* str, char* regex) {
    bool rv;
    regex_t exp;                                                    //Our compiled expression

    //Compile our expression.
    if ( regcomp(&exp, regex, REG_EXTENDED) != 0) {           // REG_EXTENDED is so that we can use Extended regular expressions
        fprintf(stderr,"regex_match()::regcomp failed with %d\n");
        exit(1);
    }

    //2. run reguler expression no str
    rv = match(&exp, str);

    //3. Free it
    regfree(&exp);
    return rv;
}

//if( regex_match(buffer, "^ls*") )
//  run_ls_with_params(buffer);