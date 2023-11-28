/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:57:14 by mlow              #+#    #+#             */
/*   Updated: 2023/09/18 20:50:07 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
// ->is an operator in C called the "arrow operator,"
// used to access variables or functions of struct
// or a pointer to a struct
// looks at content which has the value "content".
// next pointer will be NULL.
// basically, new_node will have both content and next
//
//
// I do have one question through, how does 
// new_node->content work? i know how next works,
// But what about content?
