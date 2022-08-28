/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:10:48 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/28 13:36:18 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <stdint.h>

#define ONE_BIT 0b10000000
#define NULL_BYTE 0b00000000

static int *bit_shifts(void)
{
	static int _bit_shifts[] = {
		7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
		5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
		4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
		6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21};

	return (_bit_shifts);
}

static int *sines(void)
{
	static int _sines[] = {
		0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
		0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
		0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
		0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
		0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
		0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
		0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
		0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
		0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
		0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
		0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
		0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
		0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
		0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
		0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
		0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391};

	return (_sines);
}

typedef union u_byte_word_ui32
{
	uint32_t	word;
	uint8_t		bytes[4];
} t_byte_word_ui32;

void print_md5(uint32_t *digest)
{
	int j;
	int k;
	t_byte_word_ui32 bw;


	for (j = 0; j < 4; j++)
	{
		bw.word = digest[j];
		for (k = 0; k < 4; k++)
			ft_printf("%02x", bw.bytes[k]);
	}
}

void inspect_md5(char *message, uint32_t *digest)
{
	ft_printf("\'%s\' => ", message);
	print_md5(digest);
	ft_printf("\n");
}

typedef union uwb
{

   unsigned w;
   unsigned char b[4];
} WBunion;


uint32_t *md5(char *message)
{

	uint32_t chunks;
	uint32_t q;
	uint8_t *_message;
	size_t org_length;
	org_length = ft_strlen(message);


	chunks = 1 + (org_length + 8) / 64;
	_message = ft_salloc(64 * chunks);
	ft_memcpy(_message, message, org_length);
	_message[org_length] = ONE_BIT;
	q = org_length + 1;

	while (q < 64 * chunks)
	{
		_message[q] = NULL_BYTE;
		q++;
	}

	uint64_t length_bits;
	length_bits = 8 * org_length % ULLONG_MAX;
	q -= 8;
	ft_memcpy(_message + q, &length_bits, 8);

	uint32_t a0 = 0x67452301;
	uint32_t b0 = 0xefcdab89;
	uint32_t c0 = 0x98badcfe;
	uint32_t d0 = 0x10325476;

	uint32_t chunk;
	unsigned char *chunk_start;
	uint32_t a;
	uint32_t b;
	uint32_t c;
	uint32_t d;
	uint32_t words[16];
	uint32_t f;
	uint32_t g;
	uint32_t i;

	chunk = 0;
	while (chunk < chunks)
	{
		chunk_start = _message + chunk * 64;
		ft_memcpy(words, chunk_start, 64);

		a = a0;
		b = b0;
		c = c0;
		d = d0;

		i = 0;
		while (i < 64)
		{
			if (i <= 15)
			{
				f = (b & c) | ((~b) & d);
				g = i;
			}
			else if (i >= 16 && i <= 31)
			{

				f = (d & b) | ((~d) & c);
				g = (5 * i + 1) % 16;
			}
			else if (i >= 32 && i <= 47)
			{

				f = b ^ c ^ d;
				g = (3 * i + 5) % 16;
			}
			else if (i >= 48 && i <= 63)
			{
				f = c ^ (b | (~d));
				g = (7 * i) % 16;
			}
			f = f + a + sines()[i] + words[g];
			a = d;
			d = c;
			c = b;
			b = b + ft_rotate_left_ui32(f, bit_shifts()[i]);
			i++;
		}

		a0 += a;
		b0 += b;
		c0 += c;
		d0 += d;
		chunk++;
	}
	free(_message);

	uint32_t *digest;
	digest = ft_salloc(sizeof(uint32_t) * 4);
	ft_memcpy(digest + 0, &a0, 4);
	ft_memcpy(digest + 1, &b0, 4);
	ft_memcpy(digest + 2, &c0, 4);
	ft_memcpy(digest + 3, &d0, 4);

	inspect_md5(message, digest);

	return (digest);
}


char		*md5_hex(char *message)
{
	md5(message);
	return ("BAD MD5 HEX");
}
