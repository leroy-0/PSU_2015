/*
** node.h for node structure in /home/poinss_y/Documents/PSU/PSU_2015_42sh
**
** Made by Yan Poinssot
** Login   <poinss_y@epitech.net>
**
** Started on  Thu May 12 10:55:41 2016 Yan Poinssot
** Last update Wed Jun  1 14:52:22 2016 bruere_s
*/

#ifndef		NODE_H_
# define	NODE_H_

typedef struct	s_tree
{
  struct s_tree	*previous;
  struct s_tree	*left;
  struct s_tree	*right;
  struct s_node	*node;
}		t_tree;

typedef int	(*t_function)(t_tree		*node,
			      char		***env);

typedef struct	s_node
{
  char		*line;
  char		priority;
  t_function	func;
}		t_node;

typedef int	(*t_split)(t_tree		*tree,
			   t_node		*node,
			   int			pos);

typedef struct	s_analyse
{
  struct s_node	*op[8];
  t_split	split[8];
  char		select[9];
}		t_analyse;

t_tree		*create_branch(t_tree		*previous,
			       t_node		*info);

int		analyse_branch(t_tree		*tree,
			       t_analyse	*analyse);

t_analyse	*set_analyse();

int		split(t_tree			*tree,
		      t_node			*node,
		      int			pos);

int		split_redir(t_tree		*tree,
			    t_node		*node,
			    int			pos);

t_node		*create_node(char		*line,
			     char		id,
			     t_function		function);

void		free_node(t_node		**node);

void		reset_priorities(t_analyse	*parse);

void		set_priorities(t_analyse	*priorities,
			       int		index);

t_tree		*parse(char			*line);

#endif		/* !NODE_H_ */
