/*
** analyse_func.c for analyse functions in /home/poinss_y/Documents/PSU/PSU_2015_42sh/parsing
**
** Made by Yan Poinssot
** Login   <poinss_y@epitech.net>
**
** Started on  Thu May 12 14:30:41 2016 Yan Poinssot
** Last update Wed Jun  8 20:31:08 2016 Yan Poinssot
*/

#include	<stdlib.h>
#include	"node.h"
#include	"exec_tree.h"
#include	"my.h"

static void	set_split(t_analyse *analyse)
{
  analyse->split[0] = &split;
  analyse->split[1] = &split;
  analyse->split[2] = &split;
  analyse->split[3] = &split;
  analyse->split[4] = &split_redir;
  analyse->split[5] = &split_redir;
  analyse->split[6] = &split_redir;
  analyse->split[7] = &split_redir;
}

void		reset_priorities(t_analyse *parse)
{
  size_t	count;

  count = 0;
  while (count < 8)
    {
      parse->select[count] = 0;
      count++;
    }
  parse->select[count] = '\0';
}

void		set_priorities(t_analyse *parse, int index)
{
  size_t	count;

  count = 0;
  reset_priorities(parse);
  while (count < 8)
    {
      if (parse->op[count]->priority == index)
	parse->select[count] = 1;
      count++;
    }
  parse->select[count] = '\0';
}

t_analyse	*set_analyse()
{
  t_analyse	*back;

  if ((back = my_x_malloc(sizeof(t_analyse))) == NULL)
    {
      my_puterr("Error : Memory allocation failed\n");
      return (NULL);
    }
  reset_priorities(back);
  back->op[2] = create_node(";", 1, &seperate);
  back->op[0] = create_node("&&", 2, &and);
  back->op[1] = create_node("||", 2, &or);
  back->op[3] = create_node("|", 3, &my_pipe);
  back->op[4] = create_node("<<", 4, &left_dredir);
  back->op[5] = create_node(">>", 5, &right_dredir);
  back->op[6] = create_node(">", 5, &right_redir);
  back->op[7] = create_node("<", 5, &left_redir);
  set_split(back);
  return (back);
}
