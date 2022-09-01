/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 00:47:46 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/28 00:57:21 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// SOURCE: https://rosettacode.org/wiki/MD5#C
// gcc md5.c -lm && ./a.out

#include <stdlib.h>

#include <stdio.h>
#include <string.h>
#include <math.h>

typedef union uwb
{

   unsigned w;
   unsigned char b[4];
} WBunion;

typedef unsigned Digest[4];

static u_int32_t s[] = {7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
                        5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
                        4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
                        6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21};

static u_int32_t k[] = {0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
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

unsigned f0(unsigned abcd[])
{
   return (abcd[1] & abcd[2]) | (~abcd[1] & abcd[3]);
}
unsigned f1(unsigned abcd[])
{

   return (abcd[3] & abcd[1]) | (~abcd[3] & abcd[2]);
}
unsigned f2(unsigned abcd[])
{

   return abcd[1] ^ abcd[2] ^ abcd[3];
}
unsigned f3(unsigned abcd[])
{

   return abcd[2] ^ (abcd[1] | ~abcd[3]);
}
typedef unsigned (*DgstFctn)(unsigned a[]);

unsigned *calcKs(unsigned *k)
{

   double s, pwr;
   int i;
   pwr = pow(2, 32);
   for (i = 0; i < 64; i++)
   {
      s = fabs(sin(1 + i));
      k[i] = (unsigned)(s * pwr);
   }
   return k;
}

// ROtate v Left by amt bits
unsigned rol(unsigned v, short amt)
{
   unsigned msk1 = (1 << amt) - 1;
   return ((v >> (32 - amt)) & msk1) | ((v << amt) & ~msk1);
}

unsigned *md5(const char *msg, int mlen)
{

   static Digest h0 = {0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476};
   // static Digest h0 = { 0x01234567, 0x89ABCDEF, 0xFEDCBA98, 0x76543210 };

   static DgstFctn ff[] = {&f0, &f1, &f2, &f3};
   static short M[] = {1, 5, 3, 7};
   static short O[] = {0, 1, 5, 0};
   static short rot0[] = {7, 12, 17, 22};
   static short rot1[] = {5, 9, 14, 20};
   static short rot2[] = {4, 11, 16, 23};
   static short rot3[] = {6, 10, 15, 21};
   static short *rots[] = {rot0, rot1, rot2, rot3};
   static unsigned kspace[64];
   static unsigned *k;
   static Digest h;
   Digest abcd;
   DgstFctn fctn;
   short m, o, g;
   unsigned f;
   short *rotn;
   union
   {
      unsigned w[16];
      char b[64];
   } mm;
   int os = 0;
   int grp, grps, q, p;
   unsigned char *msg2;

   if (k == NULL)
      k = calcKs(kspace);
   for (q = 0; q < 4; q++)
      h[q] = h0[q]; // initialize

   {
      grps = 1 + (mlen + 8) / 64;
      msg2 = malloc(64 * grps);
      memcpy(msg2, msg, mlen);
      msg2[mlen] = (unsigned char)0x80;
      q = mlen + 1;
      while (q < 64 * grps)
      {
         msg2[q] = 0;
         q++;
      }
      {
         // unsigned char t;

         WBunion u;
         u.w = 8 * mlen;
         // t = u.b[0]; u.b[0] = u.b[3]; u.b[3] = t; // t = u.b[1]; u.b[1] = u.b[2]; u.b[2] = t;

         q -= 8;
         memcpy(msg2 + q, &u.w, 4);
      }
   }

   for (grp = 0; grp < grps; grp++)
   {
      memcpy(mm.b, msg2 + os, 64);
      for (q = 0; q < 4; q++)
         abcd[q] = h[q];
      for (p = 0; p < 4; p++)
      {
         fctn = ff[p];
         rotn = rots[p];
         m = M[p];
         o = O[p];
         for (q = 0; q < 16; q++)
         {
            g = (m * q + o) % 16;
            f = abcd[1] + rol(abcd[0] + fctn(abcd) + k[q + 16 * p] + mm.w[g], rotn[q % 4]);
            abcd[0] = abcd[3];
            abcd[3] = abcd[2];
            abcd[2] = abcd[1];
            abcd[1] = f;
         }
      }
      for (p = 0; p < 4; p++)
         h[p] += abcd[p];
      os += 64;
   }
   if (msg2)
      free(msg2);
   return h;
}

int main(int argc, char *argv[])
{

   int j, k;
   //    const char *msg = "";
   const char *msg = "The quick brown fox jumps over the lazy dog";
   //    const char *msg = "The quick brown fox jumps over the lazy dog.";
   unsigned *d = md5(msg, strlen(msg));
   WBunion u;
   printf("'%s' => ", msg);
   for (j = 0; j < 4; j++)
   {
      u.w = d[j];
      for (k = 0; k < 4; k++)
         printf("%02x", u.b[k]);
   }
   printf("\n");
   return 0;
}
