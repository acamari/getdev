PROG=getdev
NOMAN=noman
LDADD+=-lutil
DPADD+=${LIBUTIL}
CFLAGS+=-Wall
BINDIR?=/usr/local/bin

.include <bsd.prog.mk>
