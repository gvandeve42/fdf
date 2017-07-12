/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 12:28:35 by gvandeve          #+#    #+#             */
/*   Updated: 2017/03/22 18:49:33 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_init_flags(char **tmp, t_ans *ans)
{
	if (ft_is_flag(**tmp) || ft_isdigit(**tmp))
	{
		if (ft_isdigit(**tmp) && **tmp != '0')
			ft_init_digit(tmp, ans);
		else
		{
			if (**tmp == '.')
				ft_init_prec(ans, tmp);
			else
			{
				ft_exec_init(tmp, ans);
				*tmp += 1;
			}
		}
		ft_init_flags(tmp, ans);
	}
}

static void	ft_proceed_ptf(const char *format, t_ans *ans, va_list arg)
{
	char	*tmp;

	(void)arg;
	tmp = (char*)format;
	while (*tmp != '\0')
	{
		if (*tmp != '%')
			ft_safe_cpy(ans, *tmp++);
		else
		{
			tmp += 1;
			if (*tmp == '\0')
				break ;
			ft_init_flags(&tmp, ans);
			if (ft_is_conv(*tmp))
				ft_proceed_conv(*tmp++, ans, arg);
			ft_clean(ans);
		}
	}
	write(1, (ans->buff), ans->i_b);
	ans->rtn += ans->i_b;
}

int			ft_printf(const char *format, ...)
{
	va_list arg;
	t_ans	*ans;
	int		rtn;

	ans = ft_create_ans();
	va_start(arg, format);
	ft_proceed_ptf(format, ans, arg);
	rtn = ans->rtn;
	free(ans);
	va_end(arg);
	return (rtn);
}
