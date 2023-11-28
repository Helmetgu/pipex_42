/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:34:14 by mlow              #+#    #+#             */
/*   Updated: 2023/09/20 15:48:48 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	node = ft_lstlast(*lst);
	if (!node)
		*lst = new;
	else
		node->next = new;
}
//consider what happens if lst = NULL
//e.g begin = NULL
//ft_lstadd_back(&begin, elem);
//
// Remember, ft_lstlast reads the last node.
//
//ft_lstadd_back checks if last node
// has value or is a NULL.
// if its NULL, it makes current list
// take new as the last node.
// else
// it will add "new" after the last
// node.
