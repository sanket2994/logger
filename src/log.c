#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "log.h"
#include "color.h"

static void print_level(FILE *fp, uint8_t log_lev)
{
	switch(log_lev)
	{
		case LOG_EMERG :
			if(fp == stderr)
				fprintf(fp, RED_TEXT("<LOG_EMERG> \t"));
			else		
				fprintf(fp, "<LOG_EMERG> \t");
			break;
		case LOG_CRITICAL :
			if(fp == stderr)
				fprintf(fp, YELLOW_TEXT("<LOG_CRITICAL>\t"));
			else 
				fprintf(fp , "<LOG_CRITICAL>\t");
			break;
		case LOG_INFO :
			if(fp == stderr)
				fprintf(fp, BLUE_TEXT("<LOG_INFO> \t"));
			else
				fprintf(fp, "<LOG_INFO>\t");
			break;
		case LOG_DEBUG :
			if(fp == stderr)
				fprintf(fp, GREEN_TEXT("<LOG_DEBUG> \t"));
			else
				fprintf(fp, "<LOG_DEBUG>\t");
			break;
	}
}
void print_log(uint8_t log_lev, FILE *fp,  const char *fmt, ...)
{
	FILE *fptr = NULL;
	va_list list;
	if(fp == NULL)
		fptr = fopen("/var/log/app_log.log", "a+");
	else 
		fptr = fp;
	if (log_lev > g_log.log_level)
	{
		return;
	}
#ifdef TIME_STAMP
	if(g_log.time_stamp == PRINT_TIME)
		print_time(fptr);
#endif
	print_level(fptr, log_lev);
	va_start(list, fmt);
	vfprintf(fptr, fmt, list);
	fflush(fptr);
	va_end(list);
	fclose(fptr);
		
	
}

#ifdef TIME_STAMP
void print_time(FILE *fp)
{
	time_t timer;
	int len;
	struct tm tmr;
	char pTime[50];
	timer = time(&timer);
	ctime_r(&timer, pTime);
	len = strlen(pTime);
	/*since ctime return a string with charcter \n we need to remove that charcter */
	pTime[len-1] = '\0';
	fprintf(fp, "%s ", pTime);

}
#endif
