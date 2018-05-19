#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "log.h"
#include "color.h"

static void print_level(FILE *fp, log_level_ten log_lev)
{
	switch(log_lev)
	{
		case LOG_EMERG :
			if(stderr == fp )
				fprintf(fp, BOLD_RED_TEXT("<LOG_EMERG> \t"));
			else		
				fprintf(fp, "<LOG_EMERG> \t");
			break;
		case LOG_ALERT :
			if(stderr == fp )
				fprintf(fp, BOLD_MAGENTA_TEXT("<LOG_ALERT> \t"));
			else
				fprintf(fp, "<LOG_ALERT> \t");
			break;
		case LOG_CRITICAL :
			if(stderr == fp )
				fprintf(fp, MAGENTA_TEXT("<LOG_CRITICAL>\t"));
			else 
				fprintf(fp , "<LOG_CRITICAL>\t");
			break;
		case LOG_ERR :
			if(stderr == fp )
				fprintf(fp, RED_TEXT("<LOG_ERR> \t"));
			else
				fprintf(fp, "<LOG_ERR> \t");
			break;
		case LOG_WARN :
			if(stderr == fp )
				fprintf(fp, BOLD_YELLOW_TEXT("<LOG_WARN> \t"));
			else
				fprintf(fp, "<LOG_WARM> \t");
			break;
		case LOG_NOTICE :
			if(stderr == fp )
				fprintf(fp, YELLOW_TEXT("<LOG_NOTICE> \t"));
			else
				fprintf(fp, "<LOG_NOTICE> \t");
			break;
		case LOG_INFO :
			if(stderr == fp )
				fprintf(fp, CYAN_TEXT("<LOG_INFO> \t"));
			else
				fprintf(fp, "<LOG_INFO>\t");
			break;
		case LOG_DEBUG :
			if(stderr == fp )
				fprintf(fp, GREEN_TEXT("<LOG_DEBUG> \t"));
			else
				fprintf(fp, "<LOG_DEBUG>\t");
			break;
	}
}
void print_log(log_level_ten log_lev, FILE *fp,  const char *fmt, ...)
{
	FILE *fptr = NULL;
	va_list list;
	if(NULL == fp)
		fptr = fopen("/var/log/app_log.log", "a+");
	else 
		fptr = fp;
	if (log_lev > g_log_st.log_level_en)
	{
		return;
	}
#ifdef TIME_STAMP
	if(PRINT_TIME == g_log_st.time_stamp)
		print_time(fptr);
#endif/* TIME_STAMP */
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
#endif/* TIME_STAMP */
