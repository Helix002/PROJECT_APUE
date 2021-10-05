//
// Created by suzol on 2021/10/5.
//

#ifndef APUE_FILEIO_H
#define APUE_FILEIO_H

#include "apue.h"
#include "err_log.h"
#include <fcntl.h>

int test_lseek();     /* figure 3-1 */

int create_hole_file(); /* figure 3-2 */

#define BUFFSIZE 4096
int efficientIO(); /* figure 3-5*/

#endif //APUE_FILEIO_H
