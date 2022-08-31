# Valgrind

- https://wiki.wxwidgets.org/Valgrind_Suppression_File_Howto
- https://stackoverflow.com/questions/16847385/valgrind-to-detect-memory-leak-in-child-process

### Valgrind Readline Leaks Supression

Publicado pelo Denny no Discord, link pra msg original:

- https://discord.com/channels/706206701598277681/805218563194355732/923621489079615489

Para ajudar na verificação dos leaks no myshell com o Valgrind,
eu montei um arquivo de supressão que limpa os erros que vêm do Readline.
À princípio está suprimindo 100% dos leaks do Readline no nosso myshell,
mas se ainda retornar algum leak nas funções dessa família,
me mandem pra gente ir atualizando esse arquivo e deixá-lo mais completo.
O uso é bem simples, só salvar o arquivo como **readline.supp** no diretório
do myshell e adicionar a flag abaixo quando chamar o valgrind:
**`--suppressions=readline.supp`**

```bash
{
   <Readline>
   Memcheck:Leak
   match-leak-kinds: reachable
   ...
   fun:readline
   ...
}
{
   <Readline>
   Memcheck:Leak
   match-leak-kinds: definite
   fun:malloc
   fun:xmalloc
   fun:rl_add_undo
   fun:rl_insert_text
   fun:_rl_insert_char
   fun:rl_insert
   fun:_rl_dispatch_subseq
   fun:readline_internal_char
   fun:readline
   ...
}
{
   <AddHistory>
   Memcheck:Leak
   match-leak-kinds: reachable
   fun:malloc
   fun:xmalloc
   fun:add_history
   ...
}
```

Quem tiver interesse em entender como funciona a supressão, segue um HowTo:

- https://wiki.wxwidgets.org/Valgrind_Suppression_File_Howto

### `--max-stackframe=`

- https://stackoverflow.com/questions/10057443/explain-the-concept-of-a-stack-frame-in-a-nutshell
- https://man7.org/linux/man-pages/man1/valgrind.1.html
- https://stackoverflow.com/questions/23307110/valgrind-gives-an-error-for-nearly-everything-warning-client-switching-stacks
