/*
 * Copyright (c) 2015 Abel Abraham Camarillo Ojeda <acamari@verlet.org>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <err.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <util.h>
#include <string.h>

extern	const char *__progname;
void	usage(void);

int
main(int argc, char *argv[])
{
	char	*p;
	int	fd;

	if (argc != 2 || *argv[1] == '\0')
		usage();
	if ((fd = opendev(argv[1], O_RDONLY, 0, &p)) == -1)
		err(1, "opendev");
	printf("%s\n", p);
	return 0;
}

void
usage(void)
{
	fprintf(stderr, "usage: %s { devname | duid }\n", __progname);
	exit(1);
}
