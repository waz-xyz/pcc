/*
 * Map pass2 nodes to pass1 dito.
 */
#include "node.h"


#define P2BAD -1
#define P2NAME NAME
#define P2ICON ICON
#define P2PLUS PLUS
#define P2PLUSEQ 7
#define P2MINUS MINUS
#define P2NEG UMINUS
#define P2STAR 11
#define P2STAREQ 12
#define P2INDIRECT 13
#define P2BITAND AND
#define P2BITOR OR
#define P2BITXOR ER
#define P2QUEST 21
#define P2COLON 22
#define P2ANDAND 23
#define P2OROR 24
#define P2GOTO GOTO
#define P2LISTOP 56
#define P2ASSIGN ASSIGN
#define P2COMOP 59
#define P2SLASH DIV
#define P2MOD MOD
#define P2LSHIFT LS
#define P2RSHIFT RS
#define P2CALL 70
#define P2CALL0 72

#define P2NOT 76
#define P2BITNOT 77
#define P2EQ EQ
#define P2NE NE
#define P2LE LE
#define P2LT LT
#define P2GE GE
#define P2GT GT
#define P2REG REG
#define P2OREG OREG
#define P2CONV SCONV
#define P2FORCE FORCE
#define P2CBRANCH CBRANCH

/* special operators included only for fortran's use */

#define P2PASS 200
#define P2STMT 201
#define P2SWITCH 202
#define P2LBRACKET 203
#define P2RBRACKET 204
#define P2EOF 205
#define P2ARIF 206
#define P2LABEL 207

#ifdef pdp11
#	define P2SHORT 4
#	define P2INT 4
#	define P2LONG 5
#else
#	define P2SHORT 3
#	define P2INT 4
#	define P2LONG 4
#endif

#define P2CHAR 2
#define P2REAL 6
#define P2DREAL 7
#define P2PTR 020
#define P2FUNCT 040
