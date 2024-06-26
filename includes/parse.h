/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:16:58 by rcortes-          #+#    #+#             */
/*   Updated: 2024/04/02 17:58:45 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "minishell.h"

typedef struct s_env
{
	char			*key;
	char			*value;
	int				only_exp;
	int				trigger_utils;
	struct s_env	*next;
}					t_env;

//ESTO ES SPLIT
int		copy_quotes(char *word, char *line, int *i, int *index);
int		iterate_quote(char *line, int *index, char c, int *size);
int		do_operator(char *line, int *index, t_operators *data, int *size);
int		split_word_symbol(char **word, char *line,
			int *index, t_operators *data);
char	**ft_split(char *line, const char *set, t_operators *data);

//ESTO ES ORDER FLAGS && PARSE UTILS
void	init_data(t_operators *data, char **envp);
int		is_symbol(t_operators *data, char c);
void	order_split(char **split, t_operators *data);
char	*delete_quotes(char *str, char *new_str);

//ESTO ES CATEGORIZE && TOKENIZATION
int		categorize(char **words, t_word **lst);
int		is_operator(char *new_split, int is_inquote);
void	tokenization(t_word **lst, t_operators *data);
void	parse_operators(t_word **words);
char	*new_operator(char *str, char lead);

//ESTO ES ENVIRONMENT

t_env	*ft_newenv(void);
void	ft_envadd_back(t_env **env_lst, t_env *new_env);
t_env	*parse_environment(t_env **env_lst, char **envp);
int		ft_strcmp(char *s1, char *s2);
t_env	*get_env(t_env **env_lst, char *get_key);
void	init_env(t_env **env, char **envp);
int		ft_envsize(t_env *lst);
char	**renew_env(t_env **env);
void	renew_env_aux(char **new_env, char **new_aux, t_env *env_aux, int *i);

#endif
