#ifndef __COMMON__
#define __COMMON__

int compareInt(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

const int target = 10358;

#endif  // __COMMON__