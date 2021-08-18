#include "numberToString.h"

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