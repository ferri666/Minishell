#include "minishell.h"
#include "libft.h"
#include "colors.h"

static int ft_count_word2(char const *s, char c)
{
    int index_s = 0;
    int word = 0;
    int inside_quotes = 0;

    while (s && s[index_s])
    {
        if (s[index_s] == '\"')
        {
            inside_quotes = 1; // Toggle inside quotes flag
        }
        if (inside_quotes)
        {
            // If inside quotes, consider everything as one word
            word++;
            while (s[index_s] && s[index_s] != '\"')
            {
                index_s++;
            }
			if (s[index_s] == '\"')
				inside_quotes = 0;
        }
        else if (s[index_s] != c)
        {
            // If not inside quotes and not a delimiter, consider it a word
            word++;

            // Skip the entire word, including the delimiter
            while (s[index_s] && s[index_s] != c)
            {
                index_s++;
            }
        }
        else
        {
            index_s++;
        }
    }

    return word;
}

static int	ft_size_word2(char const *s, char c, int index_s)
{
	int	size;

	size = 0;
	while (s[index_s] != c && s[index_s])
	{
		size++;
		index_s++;
	}
	return (size);
}

static void	ft_free2(char **strs, int index_strs)
{
	while (index_strs--)
		free(strs[index_strs]);
	free(strs);
}

char	**ft_split_args(char const *s, char c)
{
	int		index_s;
	char	**strs;
	int		size;
	int		index_strs;

	index_s = 0;
	index_strs = -1;
	strs = (char **)malloc((ft_count_word2(s, c) + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	while (++index_strs < ft_count_word2(s, c))
	{
		while (s[index_s] == c)
			index_s++;
		size = ft_size_word2(s, c, index_s);
		strs[index_strs] = ft_substr(s, index_s, size);
		if (!strs[index_strs])
		{
			ft_free2(strs, index_strs);
			return (NULL);
		}
		index_s = size + index_s;
	}
	strs[index_strs] = NULL;
	return (strs);
}