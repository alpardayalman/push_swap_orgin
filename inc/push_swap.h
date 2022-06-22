/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayalman <ayalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:37:04 by ayalman           #+#    #+#             */
/*   Updated: 2022/06/22 18:36:18 by ayalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include "./libft/include/libft.h"

struct s_stack
{
	int				data;
	int				move;
	int				rotate;
	struct s_stack	*next;
};

struct s_duplicate
{
	int					key;
	struct s_duplicate	*left;
	struct s_duplicate	*right;
};

struct s_mNode
{
	struct s_duplicate	*tree;
	struct s_stack		*a;
	struct s_stack		*b;
	int					count_a;
	int					count_b;
	int					move_a;
	int					move_b;
	int					len_a;
	int					len_b;
	int					min;
	int					med;
	int					max;
	int					mouvement;
	int					buffer;
	int					action;
};

// rules -> for the main rules.
// reverse_rotate
void				reverse_rotate_a(struct s_mNode *head);
void				reverse_rotate_b(struct s_mNode *head);
void				reverse_rotate_rrr(struct s_mNode *head);
void				reverse_rotate_all(struct s_stack **a);
// rotate
void				rotate_a(struct s_mNode *head);
void				rotate_b(struct s_mNode *head);
void				rotate_rr(struct s_mNode *head);
void				rotate_all(struct s_stack **a);

// stack_utilities_1
int					peek(struct s_stack *top);
bool				is_empty(struct s_stack *top);
void				push(struct s_stack **top_ref,
						int new_data, int move, int rotate);
int					*pop(struct s_stack **top_ref);

// void free_all_3(void *a);

// stack_utilities_2
void				insert_at_bottom(struct s_stack **top_ref, int *item);
void				print(struct s_stack *top);
void				free_list(struct s_stack *head);

// swap_push
int					push_a(struct s_mNode *main);
int					push_b(struct s_mNode *main);
int					swap_a(struct s_mNode *main);
int					swap_b(struct s_mNode *main);
int					swap_ss(struct s_mNode *main);
// end of rules.

// control
void				is_no(char *a);
void				is_min_max(char *a);
void				o_n_checker(int ac, char **av);
void				ft_exit_fail(void);
void				ft_kill(struct s_mNode *head);

// tree -> for the lolz
// avl_tree_utilities
int					max_num(int a, int b);
struct s_duplicate	*min_value(struct s_duplicate *node);
int					find_min_value(struct s_duplicate *node);
int					find_max_value(struct s_duplicate *node);

// insert
struct s_duplicate	*new_node(int key);
void				deallocate(struct s_duplicate *node);
struct s_duplicate	*insert(struct s_mNode *head,
						struct s_duplicate *node, int key);

// median_search.c
int					counter(struct s_duplicate *root);
void				get_elements(struct s_duplicate *root,
						int *auxiliary, int *index);
int					find_median(struct s_duplicate *root);
// end of tree.

// sort a lot
// sort 3
int					lastpeek(struct s_stack **a);
bool				checker(struct s_stack *a);
struct s_mNode		*sort3(struct s_mNode *node);

// sort 5
struct s_mNode		*sort5(struct s_mNode *node);

// general sort
void				ft_prepere_stacks(struct s_mNode *head);
struct s_mNode		*general_sort_baby(struct s_mNode *head);
void				ft_commence(struct s_mNode *head);

// general sort utilities
void				ft_stepn_b(struct s_mNode *head);
void				ft_stepn_a(struct s_mNode *head);
bool				is_there_next_min(struct s_mNode *head);
int					count_min_index(struct s_mNode *head);

// find_mouvement
void				ft_mouvement(struct s_mNode *head);
void				find_minimum_move(struct s_mNode *head);
void				ft_help_aquire_place(struct s_mNode *head);
int					ft_aquire_place(struct s_mNode *head);

// instructions_do
void				do_instruct(struct s_mNode *head);
// sort end
#endif