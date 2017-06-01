#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <wchar.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft.h"
# define PRINT_LL "dDioOuUxX"

typedef struct		flags
{
		int			zero;
		int			ht;
		int			ls;
		int			mr;
		int			h;
		int			hh;
		int			l;
		int			ll;
		int			j;
		int			z;
}					flags;

char	*apply_list(char c, va_list ap, flags flags);
char	*apply_s(wchar_t *str);
char	*apply_d(long long nb);
int		ft_printf(const char *format, ...);

#endif
