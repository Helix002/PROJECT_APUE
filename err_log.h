//
// Created by suzol on 2021/10/5.
//

#ifndef APUE_ERR_LOG_H
#define APUE_ERR_LOG_H

#include "apue.h"
#include <errno.h>
#include <stdarg.h>


static void err_doit(int, int, const char *, va_list);

/*
 * Fatal error related to a system call.
 * Print a message and terminate.
 */
void err_sys(const char * fmt, ...);






#endif //APUE_ERR_LOG_H
