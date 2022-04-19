// Copyright 2021 - 2022 Preda Diana 314CA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "function.h"

#define BMAX 10

// check for invalid commands
int check() {
    char trash[BMAX];
    int check = 1;

    fgets(trash, sizeof(trash), stdin);
    if (strcmp(trash, "\n") != 0) {
        check = 0;
    }

    return check;
}
