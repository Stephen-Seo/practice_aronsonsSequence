#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "numberToString.h"

#define INIT_SEQ_BUF_SIZE 1024
#define INIT_SEQ_IND_SIZE 256
#define STARTING_SEQ "tisthefirstfourtheleventh"

void printHelp() {
    puts("-h | --help - prints this help");
    puts("-c <count> | --count <count> - number of sequence numbers to print");
}

typedef struct Sequence {
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

int nextSeqItem(Sequence *seq) {
    if(seq->indices[seq->indices_end] == 0) {
        size_t idx = seq->indices[seq->indices_end - 1] + 1;
        for(; idx < seq->buf_size && seq->buf[idx] != 0; ++idx) {
            if(seq->buf[idx] == 't' || seq->buf[idx] == 'T') {
                break;
            }
        }
        if(seq->buf[idx] != 't' && seq->buf[idx] != 'T') {
            puts("ERROR: Invalid state!");
            return 1;
        }

        seq->indices[seq->indices_end++] = idx;
        const char *next_str = numberToString(idx + 1);
        size_t next_str_size = strlen(next_str);
        while(seq->buf_end + next_str_size + 1 >= seq->buf_size) {
            doubleSeqBuf(seq);
        }
        memcpy(seq->buf + seq->buf_end, next_str, next_str_size);
        seq->buf_end += next_str_size;
        free((void*)next_str);
    }

    return 0;
}

Sequence initSequence() {
    Sequence seq;
    seq.buf = calloc(INIT_SEQ_BUF_SIZE, 1);
    seq.buf_size = INIT_SEQ_BUF_SIZE;
    seq.buf_end = 0;
    seq.indices = calloc(sizeof(unsigned long long), INIT_SEQ_IND_SIZE);
    seq.indices_size = INIT_SEQ_IND_SIZE;
//    seq.indices_end = 0; initialized later on

    while(seq.indices_size < 3) {
        doubleIndBuf(&seq);
    }
    seq.indices[0] = 0;
    seq.indices[1] = 3;
    seq.indices[2] = 10;
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

//    const char *nString = numberToString(count);
//    printf("Test string of number is %s\n", nString);
//    free((void*)nString);

    Sequence seq = initSequence();
    while(seq.indices_end < count) {
        nextSeqItem(&seq);
    }

    printf("String is %s\n", seq.buf);

    for(size_t i = 0; i < seq.indices_end; ++i) {
        printf("%llu ", seq.indices[i] + 1);
    }
    puts("");

    cleanupSequence(&seq);
    return 0;
}
