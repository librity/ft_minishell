/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extended_ascii.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:07:46 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/22 16:24:55 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// There is no such thing as extended ASCII...
// gcc extended_ascii.c && ./a.out €   ‚ ƒ „ … † ‡ ˆ ‰ Š ‹ Œ   Ž     ‘ ’ “ ” • – — ˜ ™ š › œ   ž Ÿ   ¡ ¢ £ ¤ ¥ ¦ § ¨ © ª « ¬ ­ ® ¯ ° ± ² ³ ´ µ ¶ · ¸ ¹ º » ¼ ½ ¾ ¿ À Á Â Ã Ä Å Æ Ç È É Ê Ë Ì Í Î Ï Ð Ñ Ò Ó Ô Õ Ö × Ø Ù Ú Û Ü Ý Þ ß à á â ã ä å æ ç è é ê ë ì í î ï ð ñ ò ó ô õ ö ÷ ø ù ú û ü ý þ ÿ

#include <stdio.h>
#include <strings.h>
#include <limits.h>

static void divider(void)
{
	printf("\n==================================================\n");
}

int main(int argc, char **argv)
{
	char c;

	c = CHAR_MIN;
	while (c < CHAR_MAX)
		printf("'%c': %d, ", c, c++);
	divider();
	while (*argv != NULL)
		printf("'%s' (length %d): %d, ",  *argv, strlen(*argv), **argv++);
	divider();
	return (0);
}
