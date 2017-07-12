/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 17:06:49 by gvandeve          #+#    #+#             */
/*   Updated: 2017/03/22 18:55:56 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <wchar.h>

# define FD 1
# define BUFF_SIZE 1000
# define TRUE 1
# define FALSE 0

typedef char			t_bool;

typedef struct			s_ans
{
	unsigned char		buff[BUFF_SIZE];
	int					i_b;
	t_bool				plus;
	t_bool				moins;
	t_bool				zero;
	t_bool				sharp;
	t_bool				j_flag;
	t_bool				z_flag;
	t_bool				sp_flag;
	t_bool				upper;
	int					h_flag;
	int					l_flag;
	int					digit;
	int					prec;
	char				sign;
	int					rtn;
}						t_ans;

typedef struct			s_tabflag
{
	char				c;
	void				(*f)(t_ans *ans);
}						t_tabflag;

typedef struct			s_tabconv
{
	char				conv;
	void				(*f)(t_ans *ans, va_list arg);
}						t_tabconv;

int						ft_printf(const char *format, ...);
t_ans					*ft_create_ans(void);
void					ft_safe_cpy(t_ans *ans, unsigned char c);
t_bool					ft_is_flag(char c);
void					ft_init_digit(char **str, t_ans *ans);
void					ft_exec_init(char **str, t_ans *ans);
void					ft_proceed_conv(char c, t_ans *ans, va_list arg);
void					ft_prct(t_ans *ans, va_list arg);
void					ft_init_plus(t_ans *ans);
void					ft_init_moins(t_ans *ans);
void					ft_init_zero(t_ans *ans);
void					ft_safe_str(t_ans *ans, char *str);
void					ft_safe_str_iter(t_ans *ans, char *str, int i);
void					ft_safe_iter(t_ans *ans, char c, int nb);
void					ft_digit(t_ans *ans, char *str);
void					ft_digit_zero(t_ans *ans, char *str);
void					ft_digit_zero_prec_str(t_ans *ans, char *str);
void					ft_digit_zero_prec_dgt_d(t_ans *ans, char *str);
void					ft_d(t_ans *ans, va_list arg);
void					ft_s(t_ans *ans, va_list arg);
void					ft_init_prec(t_ans *ans, char **frm);
void					ft_clean(t_ans *ans);
void					ft_init_sharp(t_ans *ans);
void					ft_init_sp(t_ans *ans);
void					ft_init_h(t_ans *ans);
void					ft_init_l(t_ans *ans);
void					ft_init_j(t_ans *ans);
void					ft_init_z(t_ans *ans);
int						ft_wmask(int nb, t_ans *ans);
char					*ft_rm_minus(char *str);
void					ft_o(t_ans *ans, va_list arg);
void					ft_x(t_ans *ans, va_list arg);
char					*ft_add_0x(char *str);
void					ft_xu(t_ans *ans, va_list arg);
void					ft_digit_zero_prec_dgt_o(t_ans *ans, char *str);
void					ft_digit_zero_prec_dgt_x(t_ans *ans, char *str);
void					ft_digit_zero_prec_str_c(t_ans *ans, char *str);
void					ft_du(t_ans *ans, va_list arg);
void					ft_ou(t_ans *ans, va_list arg);
void					ft_u(t_ans *ans, va_list arg);
void					ft_uu(t_ans *ans, va_list arg);
void					ft_c(t_ans *ans, va_list arg);
void					ft_cu(t_ans *ans, va_list arg);
void					ft_p(t_ans *ans, va_list arg);
void					ft_digit_zero_c0(t_ans *ans);
void					ft_digit_zero_prec_wstr(t_ans *ans, wchar_t *str);
void					ft_safe_wstr(t_ans *ans, wchar_t *str);
void					ft_safe_wstr_iter(t_ans *ans, wchar_t *str, int i);
int						ft_wstrlen(wchar_t *str);
void					ft_su(t_ans *ans, va_list arg);
void					ft_b(t_ans *ans, va_list arg);
wchar_t					*ft_null(wchar_t *str);
t_bool					ft_is_conv(char c);

#endif
