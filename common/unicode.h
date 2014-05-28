/*	$Id: unicode.h,v 1.2 2014/05/28 06:58:58 plunky Exp $	*/

#ifndef _UNICODE_H
#define _UNICODE_H

extern char *cp2u8(char *p,unsigned int c);
extern unsigned int u82cp(char **q);
extern int u8len(char *t);
extern unsigned int esc2char(char **q);
extern void u8error(const char *fmt, ...);

#endif
