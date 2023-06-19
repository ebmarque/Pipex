/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque < ebmarque@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 10:52:36 by ebmarque          #+#    #+#             */
/*   Updated: 2023/05/24 13:35:05 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct stct_print
{
	va_list	args;
	int		hstg;
	int		zero;
	int		dash;
	int		space;
	int		plus;
	int		dot;
	int		tlen;
	int		error;
}	t_print;

/**
 * @brief write the output under the control of a format 
 * string that specifies how
	 subsequent arguments (or arguments accessed via  the  
	 variable-length  argument  facilities  of
	 stdarg(3)) are converted for output.
 * 
 * @param format The format string is a character string, beginning 
 * and ending in its initial  shift  state,  if
	 any.   The  format  string is composed of zero or more directives: 
	 ordinary characters (not %),
	 which are copied unchanged to the output stream; and conversion 
	 specifications, each  of  which
	 results in fetching zero or more subsequent arguments.  
	 Each conversion specification is intro‐
	 duced by the character %, and ends with a conversion specifier.  
	 In between there  may  be  (in
	 this  order)  zero or more flags, an optional 
	 minimum field width, an optional precision and an
	 optional length modifier.
	 The arguments must correspond properly (after type promotion) 
	 with  the  conversion  specifier.
	 By default, the arguments are used in the order given, 
	 where each '*' (see Field width and Pre‐
	 cision below) and each conversion specifier asks 
	 for the next argument (and it is an  error  if
	 insufficiently  many  arguments  are given).  
	 One can also specify explicitly which argument is
	 taken, at each place where an argument is required, 
	 by writing "%m$" instead of '%'  and  "*m$"
	 instead  of  '*',  where the decimal integer m denotes 
	 the position in the argument list of the
	 desired argument, indexed starting from 1.
 * @param ... 
 * @return int Upon successful return, these functions return 
 * the number of characters printed (excluding  the
	 null byte used to end output to strings).
 */
int		ft_printf(const char *format, ...);

/**
 * @brief Esta funcao recebe o ponteiro para a variavel do tipo 
 * estrutura "t_print" e redefine todos os seus parametros (flags)
 * para 0.
 * 
 * @param tab 
 * Endereco da variavel do tipo estrutura "t_print" 
 * @return 
 * t_print* Retorna o ponteiro com seus valores inicializados
 * em 0.
 */
void	ft_init_tab(t_print *tab);

/**
 * @brief Esta funcao verifica se o caractere passado e uma
 * das flags admissiveis nesse projeto ('-', '+', ' ', '.', '0', '#')
 * 
 * @param c Caractere passado como parametro para verificao.
 * @return int Afuncao retorna 1 caso o caractere seja uma flag
 * ou 0 caso contrario.
 */
int		ft_is_flag(char c);

/**
 * @brief Esta funcao e responsavel por atualizar a estrutura do ponteiro
 * 'tab' passado como parametro, alerando o valor de suas variaveis para
 * cada flag correspondente encontrada. A funcao chama pela
 * funcao ft_check_specifier() para que as devidas formatacoes sejam
 * feitas.
 * 
 * @param tab Ponteiro para estrutura do tipo 't_print'.
 * @param format String de referencia passada como parametro pela ft_printf().
 * @param i Variavel Idex utilizada para percorrer a string a partir
 * do ponto de interesse.
 * @return int Esta funcao retorna o valor da variavel i que informa 
 * quantos caracteres da string "format" ja foram verificados.
 */
int		ft_action_sign(t_print *tab, const char *format, int i);

/**
 * @brief Esta funcao verifica se o caractere atual e um specifier
 * chamando a funcao relativa ao caractere indicado.
 * 
 * @param tab Ponteiro para a estrutura tipo "t_print"
 * @param format String passada como parametro na funcao ft_printf()
 * @param i Index do caractere atual lido em "format"
 * @return int A funcao retorna 0 em caso de erro e um valor 
 * positvo do tamanho (tab->tlen) caso contrario.
 */
int		ft_check_specifier(t_print *tab, const char *format, int i);

int		ft_print_char(t_print *tab);
int		ft_print_int(t_print *tab);
int		ft_print_lowhex(t_print *tab);
int		ft_print_mem(t_print *tab);
int		ft_print_percent(void);
int		ft_print_str(t_print *tab);
int		ft_print_upperhex(t_print *tab);
int		ft_print_usgdec(t_print *tab);

#endif