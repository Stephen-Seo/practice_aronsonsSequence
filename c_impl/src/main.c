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
