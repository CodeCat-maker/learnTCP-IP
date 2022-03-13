//
// Created by 王泽鹏 on 2022/3/13.
//

#include <stdlib.h>
#include <util.h>
#include <stdlib.h>

void errif(bool condition,const char *errmsg){
    if(condition){
        puts(errmsg);
        exit(EXIT_FAILURE);
    }
};