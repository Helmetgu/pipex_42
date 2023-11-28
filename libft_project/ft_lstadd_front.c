/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 20:58:43 by mlow              #+#    #+#             */
/*   Updated: 2023/09/19 17:56:57 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}
// Objective:  modify the pointers such that 
// "new" becomes the new head of the list
// @ beginning
//
//Simple really (Updated note):
// make the current *lst the lst[1], using
// new->next = *lst.
//After that, make the current lst(lst[0])
// into value new.
// Thats all.
//
// 1) the pointer *lst points to the first node
// in the list.
//
// 2) *new is the new node to add to front of list
//
// 3) make "next" pointer of new node "(new->next)"
// point to the current head of list "*lst".
//
//** basically you start with lst[0]-[2], then after
//adding the new, its lst[0]- lst[3].
//
// 4) after setting new->next = *lst, make new node's
// next pointer point to the previous head of list.
// (skip since we don't have a previous head).
// (but its the same as step 3).
//
// 5) Finally, update head pointer "*lst" to point to
// "new node" and make it the new head of list.
//
// "Q1")if (!lst || !new) //refer to question
//                return;
// if list/new is empty, lst & new is NULL? why? 
// "A1")if lst is NULL, it means there's no list to add to,
// & if new is NULL, there's nothing to add.
//
// *new = *lst[0];
// *new->*lst = *lst[0]; this is wrong as it does
// not make sense, lst is not the next node.
// also if you use arrowhead -> you do not add
// * as the arrowhead does it for you: works like
// *new.next.
//
// before adding new:
// *lst ---> Node A   Node B   Node C
//         [Data_A] [Data_B] [Data_C]
//         [Next_A] [Next_B] [Next_C]
//
// after adding new:
// *lst ---> new      Node A   Node B   Node C
//         [Data_N] [Data_A] [Data_B] [Data_C]
//         [Next_A] [Next_B] [Next_C] [Next_N]
//
// Why new->next = *lst; and not *lst = new->next;?
// 1) new->next = *lst what it does is, reassign the
// pointer lst to *new.next(new head node).
// 2) but if you it as stated :*lst = new->next;
// then you are replacing lst[0] with new->next instead.
// if you do it this way, you are setting pointer lst
// to *new.next which isnt pointing anywhere.
//
// remember, every node consist of node->content &
// node->next. they DONT come from libft.h
// also rmb, i am assigning *lst to ->next and next is a 
//pointer to a structure. Which in this case is lst.
//which is in a strcuture called new.
