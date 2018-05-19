#ifndef __COLOR_H__
#define __COLOR_H__
#include <stdio.h>
#include <stdlib.h>

#define RED_TEXT(x) 		"\033[31;2m" x "\033[0m" /* ERR      */
#define BOLD_RED_TEXT(x) 	"\033[31;1m" x "\033[0m" /* EMERG    */
#define GREEN_TEXT(x)		"\033[32;2m" x "\033[0m" /* DEBUG    */
#define YELLOW_TEXT(x)		"\033[33;2m" x "\033[0m" /* NOTICE   */
#define BOLD_YELLOW_TEXT(x)	"\033[33;1m" x "\033[0m" /* WARN     */
#define MAGENTA_TEXT(x)		"\033[35;2m" x "\033[0m" /* CRITICAL */
#define BOLD_MAGENTA_TEXT(x)	"\033[35;1m" x "\033[0m" /* ALERT    */
#define CYAN_TEXT(x)		"\033[36;2m" x "\033[0m" /* INFO     */
#endif /*__COLOR_H__*/

