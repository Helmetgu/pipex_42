/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:38:34 by mlow              #+#    #+#             */
/*   Updated: 2023/09/20 19:23:12 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	*lst = NULL;
}
//Based on c operator priority,
// -> is Precedence 1 while
// * is Precedence 2. That means
// -> will go first, without 
// pointer going through first.
// It becomes *(lst->content).
// 
// temp exist to keep the value to
// do (*lst)->next because after
// ft_lstdelone, lst was free(), 
// and cannot be used.
//
// ft_lstdelone bascially removes 
// content inside of lst. and 
// frees the node, thus cannot
// be used anymore.
//
// here, we use temp to bascially i++,
// to the next part of the list.
//
// *lst = NULL; because the last node
// might have garbage value.
