//
// apue: advamced programming in the UNIX Enviromment.
//

#ifndef APUE_APUE_H
#define APUE_APUE_H

#include <sys/types.h>     /* some system still requires this */
#include <sys/stat.h>      /*  */

#include <stdio.h>         /* for convenience */
#include <stdlib.h>        /* for convenience */
#include <stddef.h>        /* for offsetof */
#include <string.h>        /* for convenience */
#include <unistd.h>        /* for convenience */
#include <signal.h>        /* for SIG_ERR */

#define MAXLINE     4096       /* max line length */

/*
 * Default file access permissions for new files.
 */
#define FILE_MODE   (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

/*
 * Default permissions for new directiories.
 */
#define DIR_MODE    (FILE_MODE | S_IXUSR | S_IXGRP | S_IXOTH)
typedef void Sigfunc(int);  /* for signal handlers */

#define min(a,b)        ((a) < (b) ? (a) : (b))
#define max(a,b)        ((a) > (b) ? (a) : (b))

/*
 * Prototypes for our own functions.
 */

char *path_alloc(size_t *);        /* Figure 2.16 */
long  open_max(void);              /* Figure 2.17 */




#endif //_APUE_H
