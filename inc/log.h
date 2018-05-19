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

#define APP_LOG(LOG_LEVEL, file_fp, fmt, ...) print_log(LOG_LEVEL, file_fp, fmt, ##__VA_ARGS__ )

typedef enum log_level{
	LOG_EMERG 	= 0,
	LOG_ALERT	= 1,
	LOG_CRITICAL 	= 2,
	LOG_ERR		= 3,
	LOG_WARN	= 4,
	LOG_NOTICE	= 5,
	LOG_INFO 	= 6,
	LOG_DEBUG	= 7,
}log_level_ten;

typedef struct log{
	log_level_ten log_level_en;
#ifdef TIME_STAMP
	uint8_t time_stamp;
#endif /*TIME_STAMP*/
}log_tst;

log_tst g_log_st;

/* Function Declaration */
void print_log(log_level_ten log_lev, FILE *fp,  const char *fmt, ...);

#ifdef TIME_STAMP
void print_time(FILE *fp);
#endif/*  TIME_STAMP */

#endif /*__LOGGING_H__*/
