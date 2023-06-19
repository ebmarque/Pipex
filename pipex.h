/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque < ebmarque@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:03:30 by ebmarque          #+#    #+#             */
/*   Updated: 2023/05/27 13:27:28 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "ft_printf/ft_printf.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

/**
 * @brief Funcao chamada em caso de erro de abertura ou leitura 
 * de algum ficheiro, a funcao chama exit() com a flag
 * EXIT_FAILURE reponsavel por encerrar o programa com um return
 * associado a uma falha. 
 */
void	std_error(void);

/**
 * @brief Essa funcao percorre todas as variaveis ambientes
 * contida no array de arrays envp[] ate encontrar a variavel
 * "PATH=", em seguida a funcao faz uso da fT_split para separar
 * cada caminho contido na variavel PATH separados por ':'.
 * 
 * @param cmd String que contem o comando shell solicitado 
 * @param envp Array de arrays que contem as variaveis ambientes
 * do sistema.
 * @return char* 
 * A funcao devolve o PATH absoluto para o comando solicitado, caso
 * este comando exista.
 */
char	*get_path(char *cmd, char *envp[]);

/**
 * @brief Esta funcao e responsavel por por criar um processo filho
 * "child process" com a finalidade de executar o comando shell em
 * questao, a funcao faz uso da funcao dup2() afim de redirecionar
 * a entrada e saida padrao do processo [STDIN_FILENO, STDOUT_NFILENO].
 * 
 * @param argv Argumentos passados pela linha de comando no terminal.
 * @param envp Variaveis ambientes contidas no sistema.
 * @param fd Array com os fd devolvdos pela funcao pipe(), nomeadamente
 * fd[0] para read() e fd[1] para write().
 */
void	child_process(char *argv[], char *envp[], int *fd);

/**
 * @brief Funcao responsavel por executar o o ultimo comando passado
 * pelo terminal, faz uso da funcao dup2() para redirecionar de maneira
 * logica a entrada e saida padrao do processo [STDIN_FILENO, STDOUT_NFILENO]
 * 
 * @param argv Argumentos passados pela linha de comando no terminal
 * @param envp Variaveis ambientes contidas no sistema
 * @param fd Array com os fd devolvdos pela funcao pipe(), nomeadamente
 * fd[0] para read() e fd[1] para write().
 */
void	parent_process(char *argv[], char *envp[], int *fd);

/**
 * @brief Funcao responsavel por executar os 
 * comandos passados (programas de fato)
 * a funcao faz uso da funcao execve(), sendo necessario passar 
 * o path absoluto
 * para o programa, o vetor da variavel ambiente contendo os 
 * comandos solicitados
 * e o array de arrays contendo as variaveis ambientes 
 * do sistema (envp[][]).
 * 
 * @param argv Argumentos passados pela linha de comando no terminal.
 * @param envp Variaveis ambientes contidas no sistema.
 */
void	run(char *argv, char *envp[]);

/**
 * @brief Esta funcao e responsavel por riar child process para cada comando
 * passado pelo terminal (exceto o ultimo), a funcao tambem 
 * trata corretamente o redirecionamento de cara stdin e stdout
 * do processo criado, afim de obeter o resultado correto
 * 
 * @param argv Argumentos passados pela linha de comando no terminal.
 * @param envp Variaveis ambientes contidas no sistema.
 */
void	child_process_bonus(char *argv, char **envp);

/**
 * @brief Essa funcao e utilizada caso o primeiro parametro passado seja o 
 * "here_doc", a funcao utiliza uma vesao simples do "get_next_line" que ira
 * ler do da entrada padrao do sistema cada linha digitada pelo usuario,
 * isto e: read(0, caractere, 1); ate que seja encontrado o LIMITER definido
 * pelo proprio usuario no segundo parametro :ARGV[2].
 * 
 * @param limiter String definida pelo usurario no segundo parametro "ARGV[2]"
 * como encerramento do "here_doc".
 * @param argc Quantidade todal de paramentros passados pela linha de comando.
 */
void	doc_append(char *limiter, int argc);

/**
 * @brief Mensagem de erro passada em caso de erro nos parametros passados pela
 * linha de comando
 * 
 */
void	bad_args(void);

/**
 * @brief Versao simples da funcao getnext line, a 
 * funcao le cada caractere presente
 * na entrada padrao do processo, isto e, FD = 0, e em s
 * eguida escreve esta 
 * esta informacao na variavel "line" passada pela funcao 
 * "doc_append".
 * 
 * @param line Variavel utilizada para retornar o texto 
 * contido em cada linha do "here_doc".
 * @return int A funcao retorna o numero de bytes lidos 
 * durante sua execucao.
 */
int		get_next_line(char **line);

/**
 * @brief Funcao que permite uma mensagem custumizada de erro. 
 * Utilizada caso a funcao "access" retorne falso para a existencia
 * do comando em questao.
 * 
 * @param header String que contem o comando passado pelo usuario.
 * @param msg Mensagem de erro caso o comando nao exista.
 */
void	custom_error(char *header, char *msg);

#endif