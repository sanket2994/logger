#include<stdio.h>
#include<stdlib.h>
#include "log.h"
int main()
{
	g_log.log_level = LOG_DEBUG;
	g_log.time_stamp = PRINT_TIME;
	int a = 10;
	double d = 25.326;
	float f = 10.2;
	APP_LOG(LOG_EMERG, NULL , "macro: a = %d\n", a);
	APP_LOG(LOG_INFO, NULL , "macro: d = %lf\n", d);
	APP_LOG(LOG_CRITICAL, NULL , "macro: f = %f\n", f);
	APP_LOG(LOG_DEBUG, NULL, "STRING: %s\n", "Hi PPL");
	APP_LOG(LOG_INFO, NULL, "HI HELLO HOW ARE YOU");

	return 0;
}
