/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <ppassos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 11:50:45 by ppassos           #+#    #+#             */
/*   Updated: 2024/10/02 16:06:35 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_words(char	**words)
{
	int	i;

	i = 0;
	while (words[i])
	{
		free(words[i]);
		i++;
	}
	free(words);
}

char	*ft_strncpy(char	*s1, char	*s2, int n)
{
	int	i;

	i = -1;
	while (++i < n && s2[i])
		s1[i] = s2[i];
	s1[i] = '\0';
	return (s1);
}

int	ft_countw(char *str)
{
	int	i;
	int	wc;

	i = 0;
	wc = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if (str[i])
			wc++;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
	}
	return (wc);
}

char	**ft_sstr(char *str, int i, int wc, char **new_str)
{
	int	j;

	j = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		j = i;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
		if (i > j)
		{
			new_str[wc] = (char *)malloc(sizeof(char) * ((i - j) + 1));
			if (!new_str[wc])
			{
				free_words(new_str);
				return (NULL);
			}
			ft_strncpy(new_str[wc++], &str[j], i - j);
		}
	}
	new_str[wc] = NULL;
	return (new_str);
}

char	**ft_split(char *str)
{
	int		i;
	int		wc;
	char	**new_str;

	i = 0;
	if (str == NULL)
		return (0);
	wc = ft_countw(str);
	new_str = (char **)malloc(sizeof(char *) * (wc + 1));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	wc = 0;
	new_str = ft_sstr(str, i, wc, new_str);
	return (new_str);
}
/*int main()
{
	int i = 0;
	int j = 0;
	char **ola = ft_split("52gd4 25 5g25");
	while (ola[i])
	{	
		printf("%s\n", ola[i]);
		i++;
	}
	free_words(ola);
	return(0);
}*/
