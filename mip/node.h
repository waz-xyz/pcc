/*	$Id: node.h,v 1.2 2003/05/31 10:34:47 ragge Exp $	*/


/*	ndu.h	4.2	87/12/10	*/

typedef unsigned int TWORD;
#define NIL (NODE *)0

/*
 * The node structure is the basic element in the compiler.
 * Depending on the operator, it may be one of several types.
 */

typedef struct node {
	int	n_op;
	int	n_rall;
	TWORD	n_type;
	int	n_su;
	union {
		char *	_name;
		int	_label;
		int	_stsize;
		int	_cdim;
	} n_5;
	union {
		int	_stalign;
		int	_csiz;
	} n_6;
	union {
		struct { struct node *_left, *_right; } n_p;
		struct { CONSZ _lval; int _rval; } n_v;
		float	_fcon;
		double	_dcon;
		long	_lcon;
		long long _llcon;
	} n_f;
} NODE;

#define	n_name	n_5._name
#define	n_label	n_5._label
#define	n_stsize n_5._stsize
#define	n_cdim	n_5._cdim

#define	n_csiz	n_6._csiz
#define	n_stalign n_6._stalign

#define	n_left	n_f.n_p._left
#define	n_right	n_f.n_p._right
#define	n_lval	n_f.n_v._lval
#define	n_rval	n_f.n_v._rval
#define	n_fcon	n_f._fcon
#define	n_dcon	n_f._dcon
#define	n_lcon	n_f._lcon
#define	n_llcon	n_f._llcon

/*
 * Node types.
 *
 * MAXOP is the highest number used by the backend.
 */

#define FREE	1
/*
 * Value nodes.
 */
#define NAME	2
#define STRING	3
#define ICON	4
#define FCON	5
#define REG	6
#define OREG	7
#define	DCON	8	/* XXX */

/*
 * Arithmetic nodes.
 */
#define PLUS	10
#define PLUSEQ	11
#define MINUS	12
#define MINUSEQ	13
#define UMINUS	14
#define DIV	15
#define DIVEQ	16
#define MOD	17
#define MODEQ	18
#define MUL	19
#define MULEQ	20
#define UMUL	21
#define INCR	22
#define DECR	23

/*
 * Bitwise operations.
 */
#define AND	24
#define ANDEQ	25
#define	UAND	26
#define OR	27
#define OREQ	28
#define ER	29
#define EREQ	30
#define LS	31
#define LSEQ	32
#define RS	33
#define RSEQ	34
#define COMPL	35

/*
 * Logical compare nodes.
 */
#define EQ	36
#define NE	37
#define LE	38
#define LT	39
#define GE	40
#define GT	41
#define ULE	42
#define ULT	43
#define UGE	44
#define UGT	45
#define ANDAND	46
#define OROR	47
#define NOT	48

/*
 * Branch nodes.
 */
#define CBRANCH	49
#define QUEST	50
#define COLON	51

/*
 * Convert types.
 */
#define FLD	52
#define SCONV	53
#define PCONV	54
#define PMCONV	55
#define PVCONV	56

/*
 * Function calls.
 */
#define CALL	57
/* #define CALLEQ 58 */
#define	UCALL	59
#define FORTCALL 60
/* #define FORTCALLEQ 61 */
#define UFORTCALL 62
#define STCALL	63
/* #define STCALLEQ 64 */
#define USTCALL	65

/*
 *  Other used nodes.
 */
#define CCODES	66
#define CM	67
#define COMOP	68
#define ASSIGN	69
#define STASG	70
#define STARG	71
#define FORCE	72
#define INIT	73
#define	GOTO	74
#define	TYPE	75
#define	RETURN	76
#define LB	77
#define CAST	78
#define STREF	79

#define	MAXOP	79

/*
 * Converter ops.
 */
#define ASG	1+
#define UNARY	2+
#define NOASG	(-1)+
#define NOUNARY	(-2)+
