/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 20:50:02 by mlow              #+#    #+#             */
/*   Updated: 2023/09/21 17:31:21 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			if (new_content)
				del(new_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
// need to create condition if lst || f || del(maybe?) is empty
// perharps del not needed cause "if needed" only?
//
// content = f(lst->content) is because we need to
// apply function "f" on each node.
//
// we require a new node for new list, thus ft_lstnew.
//
// if ft_lstnew returns "NULL", you need to return NULL 
// & free content inside node:
//                if (!new_node)
//                {
//                        if (content)
//                                del(content);
//                        return (NULL);
//               }
//
// While lst is true, you need to make node till lst is false.
// thus, use the ft_lstadd_back.
//
//refer to original ft_lstadd_back.
// ft_lstadd_back is bascially doing maths working on spot,
// it gave both new_list & new_node the new values.
// ft_lstadd_back if new_list == "NULL", new_list = new_node.
// else
// adding that new_node to the new_list "AFTER" the last node.
// "Thus", new_node becomes the end of the list.
//
//refer to original ft_lstclear
// new_list need to be freed even through it is NULL, because
// we are no longer using new_list we need to clear all 
// previous nodes. we don't need to clear current node cause
// current node failed.
//
//even through new_content is deteled, new_list must still be
// cleared. 
// We can't give a half completed list since we failed to
// complete the list.
