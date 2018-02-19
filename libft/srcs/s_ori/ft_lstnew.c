/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 00:21:33 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/09 00:30:02 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "ft_ori.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *yolo;

	yolo = (t_list *)malloc(sizeof(t_list));
	if (!yolo)
		return (0);
	if (content_size == 0 || !content)
	{
		yolo->content = NULL;
		yolo->content_size = 0;
	}
	else
	{
		yolo->content = malloc(sizeof(yolo->content));
		if (yolo->content == NULL)
		{
			free(yolo);
			return (NULL);
		}
		yolo->content = ft_memcpy(yolo->content, content, content_size);
		yolo->content_size = content_size;
	}
	yolo->next = NULL;
	return (yolo);
}
