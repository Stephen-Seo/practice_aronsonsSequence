#ifndef ARONSONSSEQUENCE_NUMBER_TO_STRING_H
#define ARONSONSSEQUENCE_NUMBER_TO_STRING_H

#include <string.h>
#include <stdlib.h>

#define INIT_SEQ_NUM_TO_STR_SIZE 128

#define FIRST "first"
#define SECOND "second"
#define THIRD "third"
#define FOURTH "fourth"
#define FIFTH "fifth"
#define SIXTH "sixth"
#define SEVENTH "seventh"
#define EIGHTH "eighth"
#define NINTH "ningth"
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

#define TWENTY "twenty"
#define THIRTY "thirty"
#define FOURTY "fourty"
#define FIFTY "fifty"
#define SIXTY "sixty"
#define SEVENTY "seventy"
#define EIGHTY "eighty"
#define NINETY "ninety"

#define TWENTIETH "twentieth"
#define THRITIETH "thirtieth"
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

void doubleBufSize(char **buf, size_t *buf_size);

void thousandToString(char **buf, size_t *buf_idx, size_t *buf_size, unsigned long long t, int last);

/*!
 * \brief Returns a word-based number string from the input number.
 *
 * \warning The returned pointer must be free'd eventually.
 */
const char * numberToString(unsigned long long n);

#endif
