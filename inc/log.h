#ifndef __LOGGING_H__
#define __LOGGING_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdint.h>
#define PRINT_TIME 1
#define NO_PRINT_TIME 2
#define LOG_FILE "/var/log/app_log.log"
void print_log(uint8_t log_lev, FILE *fp,  const char *fmt, ...);

#define APP_LOG(LOG_LEVEL, file_fp, fmt, ...) print_log(LOG_LEVEL, file_fp, fmt, ##__VA_ARGS__ )

typedef struct log{
	uint8_t log_level;
#ifdef TIME_STAMP
	uint8_t time_stamp;
#endif /*TIME_STAMP*/
}log_t;

log_t g_log;


typedef enum log_level{
	LOG_EMERG 	= 0,
	LOG_CRITICAL 	= 1,
	LOG_INFO 	= 2,
	LOG_DEBUG	= 3,
}log_level_t;

#ifdef TIME_STAMP
void print_time(FILE *fp);
#endif

#endif /*__LOGGING_H__*/
