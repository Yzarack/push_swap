/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fitoa_nbspe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 15:17:58 by jthierce          #+#    #+#             */
/*   Updated: 2019/07/04 15:20:54 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_fiota_nbspe(long double nb)
{
	if (nb == 1.0 / 0.0)
		return (ft_strdup("inf"));
	if (nb == -1.0 / 0.0)
		return (ft_strdup("-inf"));
	return (NULL);
}
