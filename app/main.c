#include<stdio.h>
#include<stdlib.h>
#include "log.h"
#include "color.h"
int main(void)
{
	int 	a = 100;
	double 	d = 25.326;
	float 	f = 10.2f;
	short 	s = 10;
	long	l = 1000000;
	g_log_st.log_level_en = LOG_DEBUG;
	g_log_st.time_stamp = PRINT_TIME;
	APP_LOG(LOG_ALERT, NULL , "macro: d = %lf\n", d);
	APP_LOG(LOG_CRITICAL, NULL , "macro: f = %f\n", f);
	APP_LOG(LOG_ERR, NULL, "STRING: %s\n", "Hi PPL");
	APP_LOG(LOG_WARN, NULL, " macro: s = %d\n", s);
	APP_LOG(LOG_NOTICE, NULL, "macro: l= %d\n", l);
	APP_LOG(LOG_INFO, NULL, "HI HELLO HOW ARE YOU \n");
	APP_LOG(LOG_DEBUG, NULL , "macro: a = %d\n", a);
	APP_LOG(LOG_EMERG, stderr, "WASSUP ??\n");

	printf(BOLD_RED_TEXT("EMERG\n"));
	printf(BOLD_MAGENTA_TEXT("ALERT\n"));
	printf(MAGENTA_TEXT("CRITICAL\n"));
	printf(RED_TEXT("ERR\n"));
	printf(BOLD_YELLOW_TEXT("WARN\n"));
	printf(YELLOW_TEXT("NOTICE\n"));
	printf(CYAN_TEXT("INFO\n"));
	printf(GREEN_TEXT("DEBUG\n"));

	return 0;
}
