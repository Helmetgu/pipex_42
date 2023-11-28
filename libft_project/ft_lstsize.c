/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:57:12 by mlow              #+#    #+#             */
/*   Updated: 2023/09/19 19:45:46 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count_node;
	t_list	*node;

	count_node = 0;
	node = lst;
	while (node)
	{
		count_node++;
		node = node->next;
	}
	return (count_node);
}
// objective : To return length of *lst
// to count how many nodes are inside.
//
//side note: check if lst is not NULL*
//
// 1) to count total no of nodes, we
// need an int to count them, we use
// "int	count_node" for this.
//
// 2) 
// while (list)
// {
//  count++;
//  list++; <-this is wrong*"E1"
// }
// *"E1" you are trying to increment the 
// entire list structure as if it were an array.
// In linked lists, you should move from one node
// to the next by updating the pointer to the next node,
// "Q1") Why do you make list = lst?
