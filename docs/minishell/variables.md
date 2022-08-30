# Variables

### Hash Table

- https://en.wikipedia.org/wiki/Hash_table
- https://www.digitalocean.com/community/tutorials/hash-table-in-c-plus-plus
- https://medium.com/omarelgabrys-blog/hash-tables-2fec6870207f
- https://stackoverflow.com/questions/730620/how-does-a-hash-table-work
- https://benhoyt.com/writings/hash-table-in-c/

```json
md5("abc") => soma() => % TAMANHO_HASH_TABLE => 2
md5("def") => soma() => % TAMANHO_HASH_TABLE => 2

Inserção:
"abc", "42"
"def", "44"
"fgw", "46"

Recuperação
"fgw"

Deleção:
"def"

{
  0: lista_linkada{
    chave,
    valor
  },
  1: lista_linkada{
    chave,
    valor
  },
  2: lista_linkada: {
    {
      chave: "abc",
      valor "42"
    },
    {
      chave: "def",
      valor "44"
    },
    {
      chave: "fgw",
      valor "46"
    }
  },

  ...

  9997: lista_linkada{
    chave,
    valor
  },
  9998: lista_linkada{
    chave,
    valor
  },
  9999: lista_linkada{
    chave,
    valor
  },
}
```

```c
void	ft_dlst_pluck_free(t_dlist **list, int index)
{
	t_dlist	*target;

	target = ft_dlst_pluck(list, index);
	free(target->content);
	free(target);
}
```

### Hash Functions

- https://en.wikipedia.org/wiki/One-way_function
- https://en.wikipedia.org/wiki/Cryptographic_hash_function
- https://en.wikipedia.org/wiki/Comparison_of_cryptographic_hash_functions
- https://en.wikipedia.org/wiki/SHA-1
- https://en.wikipedia.org/wiki/SHA-2

### MD5

- https://en.wikipedia.org/wiki/MD5#Pseudocode
- https://md5calc.com/hash/md5/I+like+turtles
- https://referencesource.microsoft.com/#System.Workflow.Runtime/MD5HashHelper.cs,5a97802b6014fccc,references
- https://github.com/Zunawe/md5-c/blob/main/md5.c
- https://medium.com/a-42-journey/implementing-the-sha256-and-md5-hash-functions-in-c-78c17e657794
- https://rosettacode.org/wiki/MD5#C
- https://github.com/ryankurte/cryptlib/blob/master/context/ctx_md5.c

```bash
$ md5sum
Homesickness became contagious in the young campers' cabin.CTRL+D
d9f45b8d75b8dda1f4d8976e6eea0483
```

### Bit Endianess vs. Byte Endianess

- https://stackoverflow.com/questions/8859604/confused-with-endianess-bits-or-bytes
- https://en.wikipedia.org/wiki/Endianness
