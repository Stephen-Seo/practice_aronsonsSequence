#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INIT_SEQ_BUF_SIZE 1024
#define INIT_SEQ_IND_SIZE 256
#define INIT_SEQ_NUM_TO_STR_SIZE 128
#define STARTING_SEQ "tisthefirstfourtheleventh"

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

void doubleBufSize(char **buf, size_t *buf_size) {
    char *newBuf = calloc(2, *buf_size);
    memcpy(newBuf, *buf, *buf_size);
    free(*buf);
    *buf = newBuf;
    *buf_size *= 2;
}

// TODO logic is convoluted here
void thousandToString(char **buf, size_t *buf_idx, size_t *buf_size, unsigned long long t, int last) {
    t = t % 1000;
    if(t == 0) {
        return;
    }

    size_t size;
    if(t >= 100) {
        switch(t / 100) {
        case 1:
            size = strlen(ONE HUNDRED);
            if(size >= *buf_idx + *buf_size) {
                doubleBufSize(buf, buf_size);
            }
            memcpy((*buf) + *buf_idx, ONE HUNDRED, size);
            *buf_idx += size;
            break;
        case 2:
            size = strlen(TWO HUNDRED);
            if(size >= *buf_idx + *buf_size) {
                doubleBufSize(buf, buf_size);
            }
            memcpy((*buf) + *buf_idx, TWO HUNDRED, size);
            *buf_idx += size;
            break;
        case 3:
            size = strlen(THREE HUNDRED);
            if(size >= *buf_idx + *buf_size) {
                doubleBufSize(buf, buf_size);
            }
            memcpy((*buf) + *buf_idx, THREE HUNDRED, size);
            *buf_idx += size;
            break;
        case 4:
            size = strlen(FOUR HUNDRED);
            if(size >= *buf_idx + *buf_size) {
                doubleBufSize(buf, buf_size);
            }
            memcpy((*buf) + *buf_idx, FOUR HUNDRED, size);
            *buf_idx += size;
            break;
        case 5:
            size = strlen(FIVE HUNDRED);
            if(size >= *buf_idx + *buf_size) {
                doubleBufSize(buf, buf_size);
            }
            memcpy((*buf) + *buf_idx, FIVE HUNDRED, size);
            *buf_idx += size;
            break;
        case 6:
            size = strlen(SIX HUNDRED);
            if(size >= *buf_idx + *buf_size) {
                doubleBufSize(buf, buf_size);
            }
            memcpy((*buf) + *buf_idx, SIX HUNDRED, size);
            *buf_idx += size;
            break;
        case 7:
            size = strlen(SEVEN HUNDRED);
            if(size >= *buf_idx + *buf_size) {
                doubleBufSize(buf, buf_size);
            }
            memcpy((*buf) + *buf_idx, SEVEN HUNDRED, size);
            *buf_idx += size;
            break;
        case 8:
            size = strlen(EIGHT HUNDRED);
            if(size >= *buf_idx + *buf_size) {
                doubleBufSize(buf, buf_size);
            }
            memcpy((*buf) + *buf_idx, EIGHT HUNDRED, size);
            *buf_idx += size;
            break;
        case 9:
            size = strlen(NINE HUNDRED);
            if(size >= *buf_idx + *buf_size) {
                doubleBufSize(buf, buf_size);
            }
            memcpy((*buf) + *buf_idx, NINE HUNDRED, size);
            *buf_idx += size;
            break;
        default:
            break;
        }
    }
    if((t % 100) >= 10) {
        switch((t % 100) / 10) {
        case 1:
            if(t % 10 > 0) {
                if((t % 10) > 0) {
                    switch(t % 10) {
                    case 1:
                        size = strlen(ELEVENTH);
                        if(size >= *buf_idx + *buf_size) {
                            doubleBufSize(buf, buf_size);
                        }
                        memcpy((*buf) + *buf_idx, ELEVENTH, size);
                        *buf_idx += size;
                        break;
                    case 2:
                        size = strlen(TWELFTH);
                        if(size >= *buf_idx + *buf_size) {
                            doubleBufSize(buf, buf_size);
                        }
                        memcpy((*buf) + *buf_idx, TWELFTH, size);
                        *buf_idx += size;
                        break;
                    case 3:
                        size = strlen(THIRTEENTH);
                        if(size >= *buf_idx + *buf_size) {
                            doubleBufSize(buf, buf_size);
                        }
                        memcpy((*buf) + *buf_idx, THIRTEENTH, size);
                        *buf_idx += size;
                        break;
                    case 4:
                        size = strlen(FOURTEENTH);
                        if(size >= *buf_idx + *buf_size) {
                            doubleBufSize(buf, buf_size);
                        }
                        memcpy((*buf) + *buf_idx, FOURTEENTH, size);
                        *buf_idx += size;
                        break;
                    case 5:
                        size = strlen(FIFTEENTH);
                        if(size >= *buf_idx + *buf_size) {
                            doubleBufSize(buf, buf_size);
                        }
                        memcpy((*buf) + *buf_idx, FIFTEENTH, size);
                        *buf_idx += size;
                        break;
                    case 6:
                        size = strlen(SIXTEENTH);
                        if(size >= *buf_idx + *buf_size) {
                            doubleBufSize(buf, buf_size);
                        }
                        memcpy((*buf) + *buf_idx, SIXTEENTH, size);
                        *buf_idx += size;
                        break;
                    case 7:
                        size = strlen(SEVENTEENTH);
                        if(size >= *buf_idx + *buf_size) {
                            doubleBufSize(buf, buf_size);
                        }
                        memcpy((*buf) + *buf_idx, SEVENTEENTH, size);
                        *buf_idx += size;
                        break;
                    case 8:
                        size = strlen(EIGHTEENTH);
                        if(size >= *buf_idx + *buf_size) {
                            doubleBufSize(buf, buf_size);
                        }
                        memcpy((*buf) + *buf_idx, EIGHTEENTH, size);
                        *buf_idx += size;
                        break;
                    case 9:
                        size = strlen(NINETEENTH);
                        if(size >= *buf_idx + *buf_size) {
                            doubleBufSize(buf, buf_size);
                        }
                        memcpy((*buf) + *buf_idx, NINETEENTH, size);
                        *buf_idx += size;
                        break;
                    default:
                        puts("ERROR: Unreachable");
                        break;
                    }
                }
                return;
            } else {
                size = strlen(TEN);
                if(size >= *buf_idx + *buf_size) {
                    doubleBufSize(buf, buf_size);
                }
                memcpy((*buf) + *buf_idx, TEN, size);
                *buf_idx += size;
            }
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        default:
            puts("ERROR: Unreachable");
            break;
        }
    }
    if((t % 10) > 0) {
        switch(t % 10) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        default:
            break;
        }
    }
}

const char * numberToString(unsigned long long n) {
    char *buf = calloc(1, INIT_SEQ_NUM_TO_STR_SIZE);
    size_t buf_idx = 0;
    size_t buf_size = INIT_SEQ_NUM_TO_STR_SIZE;

    if(n / 1000000000000 > 0) {
    }
    if((n % 1000000000000) / 1000000000 > 0) {
    }
    if((n % 1000000000) / 1000000 > 0) {
    }
    if((n % 1000000) / 1000 > 0) {
    }
    if((n % 1000) / 100 > 0) {
    }
    if((n % 100) / 10 > 0) {
    }
    if(n % 10) {
    }
}

void printHelp() {
    puts("-h | --help - prints this help");
    puts("-c <count> | --count <count> - number of sequence numbers to print");
}

typedef struct Sequence {
    unsigned long long idx;
    unsigned char *buf;
    size_t buf_size;
    size_t buf_end;
    unsigned long long *indices;
    size_t indices_size;
    size_t indices_end;
} Sequence;

void doubleSeqBuf(Sequence *seq) {
    unsigned char *newBuf = calloc(seq->buf_size, 2);
    memcpy(newBuf, seq->buf, seq->buf_end);
    free(seq->buf);
    seq->buf = newBuf;
    seq->buf_size *= 2;
}

void doubleIndBuf(Sequence *seq) {
    unsigned long long *newBuf = malloc(sizeof(unsigned long long) * seq->indices_size * 2);
    memcpy(newBuf, seq->indices, sizeof(unsigned long long) * seq->indices_end);
    free(seq->indices);
    seq->indices = newBuf;
    seq->indices_size *= 2;
}

void nextSeqItem(Sequence *seq) {
    if(seq->buf_end > seq->buf_size) {
        puts("ERROR: Sequence in invalid state!");
        return;
    } else if(seq->buf_end == seq->buf_size) {
        doubleSeqBuf(seq);
    }

    if(seq->buf_end == 0 || seq->indices_end == 0) {
        puts("ERROR: Sequence is zero sized, this should not be possible!");
        return;
    }
}

Sequence initSequence() {
    Sequence seq;
    seq.idx = 0;
    seq.buf = calloc(INIT_SEQ_BUF_SIZE, 1);
    seq.buf_size = INIT_SEQ_BUF_SIZE;
    seq.buf_end = 0;
    seq.indices = malloc(sizeof(unsigned long long) * INIT_SEQ_IND_SIZE);
    seq.indices_size = INIT_SEQ_IND_SIZE;

    while(seq.indices_size < 3) {
        doubleIndBuf(&seq);
    }
    seq.indices[0] = 1;
    seq.indices[1] = 4;
    seq.indices[2] = 11;
    seq.indices_end = 3;

    size_t startingLength = strlen(STARTING_SEQ);
    while(startingLength >= seq.buf_size) {
        doubleSeqBuf(&seq);
    }
    memcpy(seq.buf, STARTING_SEQ, startingLength);
    seq.buf_end = startingLength;

    return seq;
}

void cleanupSequence(Sequence *seq) {
    free(seq->buf);
    seq->buf = NULL;
    seq->buf_size = 0;
    seq->buf_end = 0;
    free(seq->indices);
    seq->indices = NULL;
    seq->indices_size = 0;
    seq->indices_end = 0;
}

int main(int argc, char **argv) {
    unsigned long long count = 10;

    --argc; ++argv;

    while(argc > 0) {
        if(strcmp("-h", argv[0]) == 0 || strcmp("--help", argv[0]) == 0) {
            printHelp();
            return 0;
        } else if((strcmp("-c", argv[0]) == 0 || strcmp("--count", argv[0]) == 0)
                && argc > 1) {
            count = strtoull(argv[1], NULL, 10);
            if(count == 0) {
                puts("ERROR: Failed to get count input");
                printHelp();
                return 1;
            }
            --argc; ++argv;
        } else {
            puts("ERROR: Got invalid input");
            printHelp();
            return 2;
        }
        --argc; ++argv;
    }

    printf("Got input count == %llu\n", count);

    return 0;
}
