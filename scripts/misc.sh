echo -e "echo hello world\n" | ../minishell 2> /dev/null | sed -r "s:\x1B\[[0-9;]*[mK]::g" | grep -vF "$PROMPT" | grep -v ^exit$

make re && echo -e "echo hello world\n" | ../minishell
echo -e "echo hello world\n" | ../minishell

make re && echo -e "echo hello world\n" | ./minishell
echo -e "echo hello world\n" | ./minishell

make re && ./minishell
