#include "numberToString.h"

#include <stdio.h>

void doubleBufSize(char **buf, size_t *buf_size) {
    char *newBuf = calloc(2, *buf_size);
    memcpy(newBuf, *buf, *buf_size);
    free(*buf);
    *buf = newBuf;
    *buf_size *= 2;
}

NumToken * doubleTokensBuf(NumToken *tokens, size_t *tokens_size) {
    NumToken *newTokens = calloc(sizeof(NumToken), *tokens_size * 2);
    memcpy(newTokens + *tokens_size, tokens, sizeof(NumToken) * *tokens_size);
    free(tokens);
    *tokens_size *= 2;
    return newTokens;
}

NumToken * numberToTokens(unsigned long long n, size_t *tokens_size_out) {
    size_t tokens_size = INIT_SEQ_NUM_TOKENS_SIZE;
    *tokens_size_out = tokens_size;
    NumToken *tokens = calloc(sizeof(NumToken), tokens_size);
    size_t ridx = tokens_size - 1;
    if(ridx >= tokens_size) {
        puts("ERROR: Should not be in invalid state");
        free(tokens);
        return NULL; 
    }

    unsigned long long temp;
    unsigned long long temp_suffix = 0;
    char is_first = 1;
    while(n > 0) {
        temp = n % 1000;
        if(temp % 10 > 0) {
            tokens[ridx].suffix = temp_suffix;
            tokens[ridx].value = temp % 10;
            if(is_first) {
                tokens[ridx].flags |= 1;
                is_first = 0;
            }
            if(ridx > 0) {
                --ridx;
            } else {
                tokens = doubleTokensBuf(tokens, &tokens_size);
                ridx = tokens_size / 2 - 1;
                *tokens_size_out = tokens_size;
            }
        }
        if((temp / 10) % 10 > 0) {
            if(ridx + 1 < tokens_size
                    && (temp / 10) % 10 == 1
                    && tokens[ridx + 1].value > 0
                    && tokens[ridx + 1].value <= 9) {
                tokens[ridx + 1].value += 10;
            } else {
                tokens[ridx].suffix = temp_suffix;
                tokens[ridx].value = ((temp / 10) % 10) * 10;
                if(is_first) {
                    tokens[ridx].flags |= 1;
                    is_first = 0;
                }
                if(ridx > 0) {
                    --ridx;
                } else {
                    tokens = doubleTokensBuf(tokens, &tokens_size);
                    ridx = tokens_size / 2 - 1;
                    *tokens_size_out = tokens_size;
                }
            }
        }
        if((temp / 100) % 10 > 0) {
            tokens[ridx].suffix = temp_suffix;
            tokens[ridx].value = ((temp / 100) % 10) * 100;
            if(is_first) {
                tokens[ridx].flags |= 1;
                is_first = 0;
            }
            if(ridx > 0) {
                --ridx;
            } else {
                tokens = doubleTokensBuf(tokens, &tokens_size);
                ridx = tokens_size / 2 - 1;
                *tokens_size_out = tokens_size;
            }
        }
        if(temp_suffix == 0) {
            temp_suffix = 1000;
        } else {
            temp_suffix *= 1000;
        }
        n /= 1000;
    }

    return tokens;
}

void appendStringToBuf(char **buf, size_t *buf_idx, size_t *buf_size, const char *str) {
    size_t str_size = strlen(str);
    while(*buf_idx + str_size + 1 >= *buf_size) {
        doubleBufSize(buf, buf_size);
    }

    memcpy((*buf) + *buf_idx, str, str_size);
    *buf_idx += str_size;
}

const char * tokensToString(NumToken *tokens, size_t tokens_size) {
    char *buf = calloc(1, INIT_SEQ_BUF_SIZE);
    size_t buf_size = INIT_SEQ_BUF_SIZE;
    size_t buf_idx = 0;
    for(size_t i = 0; i < tokens_size; ++i) {
        if(tokens[i].value == 0 && tokens[i].suffix == 0) {
            continue;
        }
        if(i > 0 && tokens[i].suffix != tokens[i - 1].suffix) {
            if(tokens[i - 1].suffix != 0) {
                switch(tokens[i - 1].suffix) {
                case 1000000000000:
                    appendStringToBuf(&buf, &buf_idx, &buf_size, TRILLION);
                    break;
                case 1000000000:
                    appendStringToBuf(&buf, &buf_idx, &buf_size, BILLION);
                    break;
                case 1000000:
                    appendStringToBuf(&buf, &buf_idx, &buf_size, MILLION);
                    break;
                case 1000:
                    appendStringToBuf(&buf, &buf_idx, &buf_size, THOUSAND);
                    break;
                default:
                    puts("ERROR: Unreachable");
                    free(buf);
                    return NULL;
                }
            }
        }
        if(i + 1 == tokens_size && (tokens[i].flags & 1)) {
            switch(tokens[i].value) {
            case 1:
                appendStringToBuf(&buf, &buf_idx, &buf_size, FIRST);
                break;
            case 2:
                appendStringToBuf(&buf, &buf_idx, &buf_size, SECOND);
                break;
            case 3:
                appendStringToBuf(&buf, &buf_idx, &buf_size, THIRD);
                break;
            case 4:
                appendStringToBuf(&buf, &buf_idx, &buf_size, FOURTH);
                break;
            case 5:
                appendStringToBuf(&buf, &buf_idx, &buf_size, FIFTH);
                break;
            case 6:
                appendStringToBuf(&buf, &buf_idx, &buf_size, SIXTH);
                break;
            case 7:
                appendStringToBuf(&buf, &buf_idx, &buf_size, SEVENTH);
                break;
            case 8:
                appendStringToBuf(&buf, &buf_idx, &buf_size, EIGHTH);
                break;
            case 9:
                appendStringToBuf(&buf, &buf_idx, &buf_size, NINTH);
                break;
            case 10:
                appendStringToBuf(&buf, &buf_idx, &buf_size, TENTH);
                break;
            case 11:
                appendStringToBuf(&buf, &buf_idx, &buf_size, ELEVENTH);
                break;
            case 12:
                appendStringToBuf(&buf, &buf_idx, &buf_size, TWELFTH);
                break;
            case 13:
                appendStringToBuf(&buf, &buf_idx, &buf_size, THIRTEENTH);
                break;
            case 14:
                appendStringToBuf(&buf, &buf_idx, &buf_size, FOURTEENTH);
                break;
            case 15:
                appendStringToBuf(&buf, &buf_idx, &buf_size, FIFTEENTH);
                break;
            case 16:
                appendStringToBuf(&buf, &buf_idx, &buf_size, SIXTEENTH);
                break;
            case 17:
                appendStringToBuf(&buf, &buf_idx, &buf_size, SEVENTEENTH);
                break;
            case 18:
                appendStringToBuf(&buf, &buf_idx, &buf_size, EIGHTEENTH);
                break;
            case 19:
                appendStringToBuf(&buf, &buf_idx, &buf_size, NINETEENTH);
                break;
            case 20:
                appendStringToBuf(&buf, &buf_idx, &buf_size, TWENTIETH);
                break;
            case 30:
                appendStringToBuf(&buf, &buf_idx, &buf_size, THIRTIETH);
                break;
            case 40:
                appendStringToBuf(&buf, &buf_idx, &buf_size, FOURTIETH);
                break;
            case 50:
                appendStringToBuf(&buf, &buf_idx, &buf_size, FIFTIETH);
                break;
            case 60:
                appendStringToBuf(&buf, &buf_idx, &buf_size, SIXTIETH);
                break;
            case 70:
                appendStringToBuf(&buf, &buf_idx, &buf_size, SEVENTIETH);
                break;
            case 80:
                appendStringToBuf(&buf, &buf_idx, &buf_size, EIGHTIETH);
                break;
            case 90:
                appendStringToBuf(&buf, &buf_idx, &buf_size, NINETIETH);
                break;
            case 100:
                appendStringToBuf(&buf, &buf_idx, &buf_size, ONE HUNDREDTH);
                break;
            case 200:
                appendStringToBuf(&buf, &buf_idx, &buf_size, TWO HUNDREDTH);
                break;
            case 300:
                appendStringToBuf(&buf, &buf_idx, &buf_size, THREE HUNDREDTH);
                break;
            case 400:
                appendStringToBuf(&buf, &buf_idx, &buf_size, FOUR HUNDREDTH);
                break;
            case 500:
                appendStringToBuf(&buf, &buf_idx, &buf_size, FIVE HUNDREDTH);
                break;
            case 600:
                appendStringToBuf(&buf, &buf_idx, &buf_size, SIX HUNDREDTH);
                break;
            case 700:
                appendStringToBuf(&buf, &buf_idx, &buf_size, SEVEN HUNDREDTH);
                break;
            case 800:
                appendStringToBuf(&buf, &buf_idx, &buf_size, EIGHT HUNDREDTH);
                break;
            case 900:
                appendStringToBuf(&buf, &buf_idx, &buf_size, NINE HUNDREDTH);
                break;
            default:
                puts("ERROR: Unreachable");
                free(buf);
                return NULL;
            }
        } else {
            switch(tokens[i].value) {
            case 1:
                appendStringToBuf(&buf, &buf_idx, &buf_size, ONE);
                break;
            case 2:
                appendStringToBuf(&buf, &buf_idx, &buf_size, TWO);
                break;
            case 3:
                appendStringToBuf(&buf, &buf_idx, &buf_size, THREE);
                break;
            case 4:
                appendStringToBuf(&buf, &buf_idx, &buf_size, FOUR);
                break;
            case 5:
                appendStringToBuf(&buf, &buf_idx, &buf_size, FIVE);
                break;
            case 6:
                appendStringToBuf(&buf, &buf_idx, &buf_size, SIX);
                break;
            case 7:
                appendStringToBuf(&buf, &buf_idx, &buf_size, SEVEN);
                break;
            case 8:
                appendStringToBuf(&buf, &buf_idx, &buf_size, EIGHT);
                break;
            case 9:
                appendStringToBuf(&buf, &buf_idx, &buf_size, NINE);
                break;
            case 10:
                appendStringToBuf(&buf, &buf_idx, &buf_size, TEN);
                break;
            case 11:
                appendStringToBuf(&buf, &buf_idx, &buf_size, ELEVEN);
                break;
            case 12:
                appendStringToBuf(&buf, &buf_idx, &buf_size, TWELVE);
                break;
            case 13:
                appendStringToBuf(&buf, &buf_idx, &buf_size, THIRTEEN);
                break;
            case 14:
                appendStringToBuf(&buf, &buf_idx, &buf_size, FOURTEEN);
                break;
            case 15:
                appendStringToBuf(&buf, &buf_idx, &buf_size, FIFTEEN);
                break;
            case 16:
                appendStringToBuf(&buf, &buf_idx, &buf_size, SIXTEEN);
                break;
            case 17:
                appendStringToBuf(&buf, &buf_idx, &buf_size, SEVENTEEN);
                break;
            case 18:
                appendStringToBuf(&buf, &buf_idx, &buf_size, EIGHTEEN);
                break;
            case 19:
                appendStringToBuf(&buf, &buf_idx, &buf_size, NINETEEN);
                break;
            case 20:
                appendStringToBuf(&buf, &buf_idx, &buf_size, TWENTY);
                break;
            case 30:
                appendStringToBuf(&buf, &buf_idx, &buf_size, THIRTY);
                break;
            case 40:
                appendStringToBuf(&buf, &buf_idx, &buf_size, FOURTY);
                break;
            case 50:
                appendStringToBuf(&buf, &buf_idx, &buf_size, FIFTY);
                break;
            case 60:
                appendStringToBuf(&buf, &buf_idx, &buf_size, SIXTY);
                break;
            case 70:
                appendStringToBuf(&buf, &buf_idx, &buf_size, SEVENTY);
                break;
            case 80:
                appendStringToBuf(&buf, &buf_idx, &buf_size, EIGHTY);
                break;
            case 90:
                appendStringToBuf(&buf, &buf_idx, &buf_size, NINETY);
                break;
            case 100:
                appendStringToBuf(&buf, &buf_idx, &buf_size, ONE HUNDRED);
                break;
            case 200:
                appendStringToBuf(&buf, &buf_idx, &buf_size, TWO HUNDRED);
                break;
            case 300:
                appendStringToBuf(&buf, &buf_idx, &buf_size, THREE HUNDRED);
                break;
            case 400:
                appendStringToBuf(&buf, &buf_idx, &buf_size, FOUR HUNDRED);
                break;
            case 500:
                appendStringToBuf(&buf, &buf_idx, &buf_size, FIVE HUNDRED);
                break;
            case 600:
                appendStringToBuf(&buf, &buf_idx, &buf_size, SIX HUNDRED);
                break;
            case 700:
                appendStringToBuf(&buf, &buf_idx, &buf_size, SEVEN HUNDRED);
                break;
            case 800:
                appendStringToBuf(&buf, &buf_idx, &buf_size, EIGHT HUNDRED);
                break;
            case 900:
                appendStringToBuf(&buf, &buf_idx, &buf_size, NINE HUNDRED);
                break;
            default:
                puts("ERROR: Unreachable");
                free(buf);
                return NULL;
            }
        }
    }

    if(tokens[tokens_size - 1].suffix > 0) {
        switch(tokens[tokens_size - 1].suffix) {
        case 1000000000000:
            appendStringToBuf(&buf, &buf_idx, &buf_size, TRILLIONTH);
            break;
        case 1000000000:
            appendStringToBuf(&buf, &buf_idx, &buf_size, BILLIONTH);
            break;
        case 1000000:
            appendStringToBuf(&buf, &buf_idx, &buf_size, MILLIONTH);
            break;
        case 1000:
            appendStringToBuf(&buf, &buf_idx, &buf_size, THOUSANDTH);
            break;
        default:
            puts("ERROR: Unreachable");
            free(buf);
            return NULL;
        }
    }

    return buf;
}

const char * numberToString(unsigned long long n) {
    size_t tokens_size;
    NumToken *tokens = numberToTokens(n, &tokens_size);
    const char *str = tokensToString(tokens, tokens_size);
    free(tokens);
    return str;
}
