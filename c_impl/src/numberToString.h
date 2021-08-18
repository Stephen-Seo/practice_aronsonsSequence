#ifndef ARONSONSSEQUENCE_NUMBER_TO_STRING_H
#define ARONSONSSEQUENCE_NUMBER_TO_STRING_H

#include <string.h>
#include <stdlib.h>

#define INIT_SEQ_BUF_SIZE 1024
#define INIT_SEQ_NUM_TO_STR_SIZE 128
#define INIT_SEQ_NUM_TOKENS_SIZE 8

#define FIRST "first"
#define SECOND "second"
#define THIRD "third"
#define FOURTH "fourth"
#define FIFTH "fifth"
#define SIXTH "sixth"
#define SEVENTH "seventh"
#define EIGHTH "eighth"
#define NINTH "ninth"
#define TENTH "tenth"

#define ELEVENTH "eleventh"
#define TWELFTH "twelfth"
#define THIRTEENTH "thirteenth"
#define FOURTEENTH "fourteenth"
#define FIFTEENTH "fifteenth"
#define SIXTEENTH "sixteenth"
#define SEVENTEENTH "seventeenth"
#define EIGHTEENTH "eighteenth"
#define NINETEENTH "nineteenth"
#define TWENTIETH "twentieth"

#define ONE "one"
#define TWO "two"
#define THREE "three"
#define FOUR "four"
#define FIVE "five"
#define SIX "six"
#define SEVEN "seven"
#define EIGHT "eight"
#define NINE "nine"
#define TEN "ten"

#define ELEVEN "eleven"
#define TWELVE "twelve"
#define THIRTEEN "thirteen"
#define FOURTEEN "fourteen"
#define FIFTEEN "fifteen"
#define SIXTEEN "sixteen"
#define SEVENTEEN "seventeen"
#define EIGHTEEN "eighteen"
#define NINETEEN "nineteen"

#define TWENTY "twenty"
#define THIRTY "thirty"
#define FORTY "forty"
#define FIFTY "fifty"
#define SIXTY "sixty"
#define SEVENTY "seventy"
#define EIGHTY "eighty"
#define NINETY "ninety"

#define TWENTIETH "twentieth"
#define THIRTIETH "thirtieth"
#define FOURTIETH "fourtieth"
#define FIFTIETH "fiftieth"
#define SIXTIETH "sixtieth"
#define SEVENTIETH "seventieth"
#define EIGHTIETH "eighteith"
#define NINETIETH "ninetieth"

#define HUNDRED "hundred"
#define THOUSAND "thousand"
#define MILLION "million"
#define BILLION "billion"
#define TRILLION "trillion"

#define HUNDREDTH "hundredth"
#define THOUSANDTH "thousandth"
#define MILLIONTH "millionth"
#define BILLIONTH "billionth"
#define TRILLIONTH "trillionth"

typedef struct NumToken {
    unsigned long long value;
    unsigned long long suffix;
    char flags; // 0b0001 - last value
} NumToken;

/*!
 * \brief Convert a number to tokens
 *
 * \warning The returned pointer must be eventually free'd
 */
NumToken * numberToTokens(unsigned long long n, size_t *tokens_size);

/*!
 * \brief Convert tokens to a string
 *
 * \warning The returned pointer must be eventually free'd
 */
const char * tokensToString(NumToken *tokens, size_t tokens_size);

/*!
 * \brief Convert a number to a string
 *
 * \warning The returned pointer must be eventually free'd
 */
const char * numberToString(unsigned long long n);

#endif
