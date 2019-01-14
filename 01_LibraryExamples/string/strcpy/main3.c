// Used in Lexical Analysis of A Compiler
/* https://github.com/xarts19/CCompiler/blob/b2195bc1b2c773daf262de6bdfbfebe60ec56baa/src/lexer.c */

/*
 * Scan for various operators.
 * Return pointer to the last symbol of the operator.
 */
token *scan_operator(buffered_reader *file_reader) {
    char buf[OPERATOR_LENGTH+1];
    token_type token_t = e_operator;
    char *forward = br_get_base(file_reader);

    switch (*forward) {
        case '+':
            forward = br_get_next_char(file_reader);
            switch (*forward) {
                case '+':
                    br_get_next_char(file_reader);
                    strcpy(buf, "++");
                    token_t = e_incr_pre;
                    break;
                case '=':
                    br_get_next_char(file_reader);
                    strcpy(buf, "+=");
                    token_t = e_plus_assign;
                    break;
                default:
                    strcpy(buf, "+");
                    token_t = e_plus;
                    break;
            }
            break;
        case '-':
            forward = br_get_next_char(file_reader);
            switch (*forward) {
                case '-':
                    br_get_next_char(file_reader);
                    strcpy(buf, "--");
                    token_t = e_decr_pre;
                    break;
                case '=':
                    br_get_next_char(file_reader);
                    strcpy(buf, "-=");
                    token_t = e_minus_assign;
                    break;
                case '>':
                    forward = br_get_next_char(file_reader);
                    if (*forward == '*') {
                        br_get_next_char(file_reader);
                        strcpy(buf, "->*");
                        token_t = e_arrow_star;
                    } else {
                        strcpy(buf, "->");
                        token_t = e_arrow;
                    }
                    break;
                default:
                    strcpy(buf, "-");
                    token_t = e_minus;
                    break;
            }
            break;
        case '*':
            forward = br_get_next_char(file_reader);
            switch (*forward) {
                case '=':
                    br_get_next_char(file_reader);
                    strcpy(buf, "*=");
                    token_t = e_mult_assign;
                    break;
                default:
                    strcpy(buf, "*");
                    token_t = e_mult;
                    break;
            }
            break;
        case '/':
            forward = br_get_next_char(file_reader);
            switch (*forward) {
                case '=':
                    br_get_next_char(file_reader);
                    strcpy(buf, "/=");
                    token_t = e_div_assign;
                    break;
                default:
                    strcpy(buf, "/");
                    token_t = e_div;
                    break;
            }
            break;
        case '%':
            forward = br_get_next_char(file_reader);
            switch (*forward) {
                case '=':
                    br_get_next_char(file_reader);
                    strcpy(buf, "%=");
                    token_t = e_mod_assign;
                    break;
                default:
                    strcpy(buf, "%");
                    token_t = e_mod;
                    break;
            }
            break;
        case '=':
            forward = br_get_next_char(file_reader);
            switch (*forward) {
                case '=':
                    br_get_next_char(file_reader);
                    strcpy(buf, "==");
                    token_t = e_eq;
                    break;
                default:
                    strcpy(buf, "=");
                    token_t = e_assign;
                    break;
            }
            break;
        case '!':
            forward = br_get_next_char(file_reader);
            switch (*forward) {
                case '=':
                    br_get_next_char(file_reader);
                    strcpy(buf, "!=");
                    token_t = e_noteq;
                    break;
                default:
                    strcpy(buf, "!");
                    token_t = e_not;
                    break;
            }
            break;
        case '>':
            forward = br_get_next_char(file_reader);
            switch (*forward) {
                case '=':
                    br_get_next_char(file_reader);
                    strcpy(buf, ">=");
                    token_t = e_moreeq;
                    break;
                case '>':
                    forward = br_get_next_char(file_reader);
                    switch (*forward) {
                        case '=':
                            br_get_next_char(file_reader);
                            strcpy(buf, ">>=");
                            token_t = e_shift_r_assign;
                            break;
                        default:
                            strcpy(buf, ">>");
                            token_t = e_shift_r;
                            break;
                    }
                    break;
                default:
                    strcpy(buf, ">");
                    token_t = e_more;
                    break;
            }
            break;
        case '<':
            forward = br_get_next_char(file_reader);
            switch (*forward) {
                case '=':
                    br_get_next_char(file_reader);
                    strcpy(buf, "<=");
                    token_t = e_lesseq;
                    break;
                case '<':
                    forward = br_get_next_char(file_reader);
                    switch (*forward) {
                        case '=':
                            br_get_next_char(file_reader);
                            strcpy(buf, "<<=");
                            token_t = e_shift_l_assign;
                            break;
                        default:
                            strcpy(buf, "<<");
                            token_t = e_shift_l;
                            break;
                    }
                    break;
                default:
                    strcpy(buf, "<");
                    token_t = e_less;
                    break;
            }
            break;
        case '&':
            forward = br_get_next_char(file_reader);
            switch (*forward) {
                case '&':
                    br_get_next_char(file_reader);
                    strcpy(buf, "&&");
                    token_t = e_and;
                    break;
                case '=':
                    br_get_next_char(file_reader);
                    strcpy(buf, "&=");
                    token_t = e_and_assign;
                    break;
                default:
                    strcpy(buf, "&");
                    token_t = e_addr;
                    break;
            }
            break;
        case '|':
            forward = br_get_next_char(file_reader);
            switch (*forward) {
                case '|':
                    br_get_next_char(file_reader);
                    strcpy(buf, "||");
                    token_t = e_or;
                    break;
                case '=':
                    br_get_next_char(file_reader);
                    strcpy(buf, "|=");
                    token_t = e_or_assign;
                    break;
                default:
                    strcpy(buf, "|");
                    token_t = e_or_bitwise;
                    break;
            }
            break;
        case '^':
            forward = br_get_next_char(file_reader);
            switch (*forward) {
                case '=':
                    br_get_next_char(file_reader);
                    strcpy(buf, "^=");
                    token_t = e_xor_assign;
                    break;
                default:
                    strcpy(buf, "^");
                    token_t = e_xor_bitwise;
                    break;
            }
            break;
        case '~':
            br_get_next_char(file_reader);
            strcpy(buf, "~");
            token_t = e_not_bitwise;
            break;
        case '.':
            forward = br_get_next_char(file_reader);
            if (*forward == '*') {
                br_get_next_char(file_reader);
                strcpy(buf, ".*");
                token_t = e_dot_star;
            } else {
                strcpy(buf, ".");
                token_t = e_dot;
            }
            break;
        case ',':
            br_get_next_char(file_reader);
            strcpy(buf, ",");
            token_t = e_comma;
            break;
        case '[':
            br_get_next_char(file_reader);
            strcpy(buf, "[");
            token_t = e_open_bracket;
            break;
        case ']':
            br_get_next_char(file_reader);
            strcpy(buf, "]");
            token_t = e_close_bracket;
            break;
        case ';':
            br_get_next_char(file_reader);
            strcpy(buf, ";");
            token_t = e_semicolon;
            break;
        case ':':
            br_get_next_char(file_reader);
            strcpy(buf, ":");
            token_t = e_colon;
            break;
        case '?':
            br_get_next_char(file_reader);
            token_t = e_question;
            strcpy(buf, "?");
            break;
        case '(':
            br_get_next_char(file_reader);
            strcpy(buf, "(");
            token_t = e_open_paren;
            break;
        case ')':
            br_get_next_char(file_reader);
            strcpy(buf, ")");
            token_t = e_close_paren;
            break;
        case '{':
            br_get_next_char(file_reader);
            strcpy(buf, "{");
            token_t = e_open_curly;
            break;
        case '}':
            br_get_next_char(file_reader);
            strcpy(buf, "}");
            token_t = e_close_curly;
            break;
        case '#':
            br_get_next_char(file_reader);
            strcpy(buf, "#");
            token_t = e_preproc_operator;
            break;
        default:
            buf[0] = *forward;
            buf[1] = '\0';
            return error("Unknows operator: ", buf);
            break;
    }
    br_set_base(file_reader);
    return token_new(token_t, buf);
}

