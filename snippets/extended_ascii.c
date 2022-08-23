/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extended_ascii.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:07:46 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 14:40:17 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// There is no such thing as extended ASCII...
// gcc extended_ascii.c && ./a.out

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <limits.h>

size_t ft_strlen(const char *s)
{
	size_t length;

	if (s == NULL)
		return (0);
	length = 0;
	while (s[length])
		length++;
	return (length);
}

void _print_bits_uc(unsigned char c)
{
	int i;

	printf("|");
	i = (sizeof(char) * 8) - 1;
	while (i >= 0)
	{
		if (c & (1u << i))
			printf("1");
		else
			printf("0");
		i--;
	}
}

void ft_inspect_cstr(char *str)
{
	while (*str != '\0')
		_print_bits_uc(*str++);
	_print_bits_uc(*str);
	printf("|");
	printf("\n");
}

static void divider(void)
{
	printf("\n==================================================\n");
}

#define EMOJI "🪔"

int main(void)
{
	char c;

	c = CHAR_MIN;
	while (c < CHAR_MAX)
		printf("'%c': %d, ", c, c++);
	divider();

	char **not_ascii = (char *[]){
		"€", "", "", "‚", "ƒ", "„", "…", "†", "‡", "ˆ", "‰", "Š", "‹", "Œ", "",
		"", "Ž", "", "", "", "", "‘", "’", "“", "”", "•", "–", "—", "˜", "™",
		"š", "›", "œ", "", "", "ž", "Ÿ", "", "", "¡", "¢", "£", "¤", "¥", "¦",
		"§", "¨", "©", "ª", "«", "¬", "­", "®", "¯", "°", "±", "²", "³", "´",
		"µ", "¶", "·", "¸", "¹", "º", "»", "¼", "½", "¾", "¿", "À", "Á", "Â",
		"Ã", "Ä", "Å", "Æ", "Ç", "È", "É", "Ê", "Ë", "Ì", "Í", "Î", "Ï", "Ð",
		"Ñ", "Ò", "Ó", "Ô", "Õ", "Ö", "×", "Ø", "Ù", "Ú", "Û", "Ü", "Ý", "Þ",
		"ß", "à", "á", "â", "ã", "ä", "å", "æ", "ç", "è", "é", "ê", "ë", "ì",
		"í", "î", "ï", "ð", "ñ", "ò", "ó", "ô", "õ", "ö", "÷", "ø", "ù", "ú",
		"û", "ü", "ý", "þ", "ÿ", EMOJI, NULL};
	// Segfaults with strlen for some reason.
	while (*not_ascii != NULL)
		printf("\"%s\" (length %d): %d, ", *not_ascii, (int)ft_strlen(*not_ascii), **not_ascii++);
	divider();

	char *utf8_str = malloc(sizeof(char) * (ft_strlen(EMOJI) + 1));
	strcpy(utf8_str, EMOJI);
	printf("%s: ", utf8_str);
	ft_inspect_cstr(utf8_str);
	divider();

	utf8_str[0] = 'A';
	// utf8_str[1] = utf8_str[1] + 4;
	printf("%s: ", utf8_str);
	ft_inspect_cstr(utf8_str);
	divider();

	return (0);
}
