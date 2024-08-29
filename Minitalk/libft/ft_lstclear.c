/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelikan <avelikan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:59:42 by avelikan          #+#    #+#             */
/*   Updated: 2024/01/05 11:59:45 by avelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*l;
	t_list	*n;

	if (lst == NULL || del == NULL)
		return ;
	l = *lst;
	while (l != NULL)
	{
		n = l->next;
		ft_lstdelone(l, del);
		l = n;
	}
	*lst = NULL;
}
