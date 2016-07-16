#include <stdio.h>
#include <stdlib.h>

// Uncomment to disable assertion
// Production / Marking
//#define NDEBUG

#ifndef NDEBUG
	// ANSI Colour escape codes
	#define ANSI_RED     "\x1b[31m"
	#define ANSI_GREEN   "\x1b[32m"
	#define ANSI_YELLOW  "\x1b[33m"
	#define ANSI_BLUE    "\x1b[34m"
	#define ANSI_MAGENTA "\x1b[35m"
	#define ANSI_CYAN    "\x1b[36m"
	#define ANSI_RESET   "\x1b[0m"
	/*
		Coloured 'Info' printfs.
		Using the colours of the ANSI rainbow.
		NDEBUG will disable these at compile time.

	*/
	#define infoMagenta(s) (printf(ANSI_MAGENTA s ANSI_RESET))
	#define infoRed(s) (printf(ANSI_RED s ANSI_RESET))
	#define infoGreen(s) (printf(ANSI_GREEN s ANSI_RESET))
	#define infoYellow(s) (printf(ANSI_YELLOW s ANSI_RESET))
	#define infoBlue(s) (printf(ANSI_BLUE s ANSI_RESET))
	#define infoCyan(s) (printf(ANSI_CYAN s ANSI_RESET))

	/*
		Coloured Asserion.
		Key informatoin is highlighted for easier
		late night debugging.
	*/
	#define cAssert( e ) ( e == 1 ) ? : \
	({\
	printf(\
		ANSI_RED    "Assertion %s failed\n"\
		ANSI_RESET\
		, __STRING(e));\
	printf(\
		ANSI_CYAN   "\tBlame: "\
		ANSI_YELLOW "%s"\
		ANSI_CYAN   " => function: "\
		ANSI_YELLOW "%s"\
		ANSI_CYAN   " => line: "\
		ANSI_YELLOW "%d\n"\
		ANSI_RESET,\
		__FILE__, __func__, __LINE__);\
	exit(0);\
	})

	/*
		Coloured Asserion with info message.
		Info message should be somehting insightful
		to the condition being tested.
	*/
	#define cAssertMsg( e, m ) ( e == 1 ) ? : \
	({\
	printf(\
		ANSI_RED    "Assertion %s failed\n"\
		ANSI_RESET\
		, __STRING(e));\
	printf(\
		ANSI_CYAN   "\tBlame: "\
		ANSI_YELLOW "%s"\
		ANSI_CYAN   " => function: "\
		ANSI_YELLOW "%s"\
		ANSI_CYAN   " => line: "\
		ANSI_YELLOW "%d\n"\
		ANSI_RESET,\
		__FILE__, __func__, __LINE__);\
	printf(\
		ANSI_CYAN   "\tAssociated Info: "\
		ANSI_YELLOW m\
		ANSI_RESET);\
	exit(0);\
	})

#else
	// No assert MACROS
	#define cAssertMsg( e, m )  ((void)0)
	#define cAssert( e )        ((void)0)
	// No info MACROS
	#define infoMagenta(s)      ((void)0)
	#define infoRed(s)          ((void)0)
	#define infoGreen(s)        ((void)0)
	#define infoYellow(s)       ((void)0)
	#define infoBlue(s)         ((void)0)
	#define infoCyan(s)         ((void)0)
#endif
