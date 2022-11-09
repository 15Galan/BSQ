#include <caption.h>
#include <args_processing.h>
#include <ft_str.h>

int	calculate_rows(char *raw)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (raw[i] != '\n')
		i++;
	i++;
	while (raw[i++] != '\n')
		count++;
	return (count);
}

// raw is the raw text in the file or the stdin in the form
// NCCC ...(next part of the map);
// where N is number of lines
// C is a character meaning something in the map
// TODO: chech ft_is_printable of caption
t_caption	fill_caption(char *raw, int *flag_error)
{
	t_caption	new_caption;
	int			displacement;

	displacement = get_base(ft_atoi(raw));
	new_caption.rows = ft_atoi(raw);
	new_caption.cols = calculate_rows(raw);
	new_caption.empty = raw[displacement + 0];
	new_caption.obst = raw[displacement + 1];
	new_caption.full = raw[displacement + 2];
	if (raw[displacement + 4] != '\n')
		*flag_error = 1;
	else if (ft_is_printable(new_caption.empty) == 0)
		*flag_error = 1;
	else if (ft_is_printable(new_caption.obst) == 0)
		*flag_error = 1;
	else if (ft_is_printable(new_caption.full) == 0)
		*flag_error = 1;
	else if (new_caption.empty != new_caption.obst)
		*flag_error = 1;
	else if (new_caption.obst != new_caption.full)
		*flag_error = 1;
	else if (new_caption.full != new_caption.empty)
		*flag_error = 1;
	return (new_caption);
}
