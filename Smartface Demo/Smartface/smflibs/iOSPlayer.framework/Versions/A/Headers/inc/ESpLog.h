#ifndef ESPLOG_H_
#define ESPLOG_H_

#define SPERR 1 // error
#define SPWAR 2 // warning
#define SPDEB 3 // debug
#define SPSYS 4 // system

#define SPTRA 5 // trace

__attribute__ ((visibility ("default"))) void splog(int type,const char *className, const char *msg, ...);

#endif