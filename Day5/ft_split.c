/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgalean <asgalean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:08:34 by asgalean          #+#    #+#             */
/*   Updated: 2024/11/29 17:21:34 by asgalean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static char	**create_list(char const *s, char c)
{
	size_t	word_count;
	size_t	i;
	char	**list;

	i = 0;
	word_count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			word_count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	list = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!list)
		return (0);
	list[word_count] = 0;
	return (list);
}

//**************************
//**************************
static void	free_mem(char **word_list, size_t word_i)
{
	while (word_i > 0)
	{
		free(word_list[word_i - 1]);
		word_i--;
	}
	free(word_list);
}
//**************************
//**************************

static int	word_filler(char *s, char c, char **word_list, size_t i)
{
	size_t	word_i;
	size_t	j;

	word_i = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (s[i] == c)
			i++;
		while (s[i + j] != c && s[i + j] != '\0')
			j++;
		if (s[i + j] == '\0' && s[i + j - 1] == c)
			break ;
		word_list[word_i] = (char *)malloc(sizeof(char) * (j + 1));
		if (!word_list[word_i])
		{
			free_mem(word_list, word_i);
			return (0);
		}
		j = 0;
		while (s[i] != c && s[i] != '\0')
			word_list[word_i][j++] = s[i++];
		word_list[word_i++][j] = '\0';
	}
	return (1);
}

//if it crashes or breaks, use calloc instead of malloc and use the new
//free lines to make "if (!(malloc_created_array)) -> return (0);"

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**word_list;

	if (!s)
		return (NULL);
	i = 0;
	word_list = create_list(s, c);
	if (!word_list)
		return (0);
	if (!word_filler((char *)s, c, word_list, i))
		return (0);
	return (word_list);
}
