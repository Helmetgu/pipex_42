/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:49:49 by mlow              #+#    #+#             */
/*   Updated: 2023/09/20 17:19:03 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst)
	{
		del(lst->content);
		free (lst);
		lst = NULL;
	}
}
// Objective:
// free memory associated with a single node
// in a linked list while preserving memory of
// the "next" pointer.
//
// the void (*del)(void*) function pointer
// is a parameter of the ft_lstdelone function.
// It allows you to pass a function as an 
// argument to ft_lstdelone.
//
// ft_lstdelone bascially removes 
// content inside of lst. and 
// frees the node, thus cannot
// be used anymore.
//
// #include "libft.h"
//
//void    ft_lstdelone(t_list *lst, void (*del)(void*))
//{
//       t_list  *node;
//
//        node = lst;
//        if (node)
//        {
//                del(node->content);
//                free (node);
//                node = NULL;
//        }
//}
// we dont do the following above because we
// want the original lst(list) content to be
// free(). By using node, lst still would
// have content and is not free.
//
