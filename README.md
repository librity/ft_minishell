<h3 align="center">42 São Paulo - minishell</h3>

<div align="center">

![42 São Paulo](https://img.shields.io/badge/42-SP-1E2952)
![License](https://img.shields.io/github/license/librity/ft_minishell?color=yellow)
![Code size in bytes](https://img.shields.io/github/languages/code-size/librity/ft_minishell?color=blue)
![Lines of code](https://img.shields.io/tokei/lines/github/librity/ft_minishell?color=blueviolet)
![Top language](https://img.shields.io/github/languages/top/librity/ft_minishell?color=ff69b4)
![Last commit](https://img.shields.io/github/last-commit/librity/ft_minishell?color=orange)

</div>

<div align="center">

[![Build](https://github.com/librity/ft_minishell/actions/workflows/build.yml/badge.svg)](https://github.com/librity/ft_minishell/actions/workflows/build.yml)
[![Tests](https://github.com/librity/ft_minishell/actions/workflows/tests.yml/badge.svg)](https://github.com/librity/ft_minishell/actions/workflows/tests.yml)
[![Norminette v3](https://github.com/librity/ft_minishell/actions/workflows/norminette_v3.yml/badge.svg)](https://github.com/librity/ft_minishell/actions/workflows/norminette_v3.yml)
[![LucasKuhn Tester](https://github.com/librity/ft_minishell/actions/workflows/LucasKuhn-tester.yml/badge.svg)](https://github.com/librity/ft_minishell/actions/workflows/LucasKuhn-tester.yml)

</div>

<p align="center">  The most hellish shell to ever shell in pure C.
  <br>
</p>

---

## 📜 Table of Contents

- [🐚 Cone Snails](#cone_snails)
- [🧐 About](#about)
- [🏁 Getting Started](#getting_started)
- [🧪 Tests](#tests)
- [📝 Notes](#notes)
- [🛸 42 São Paulo](#ft_sp)
- [📚 Resources](#resources)

## 🐚 Cone Snails <a name = "cone_snails"></a>

[Cone snails, cone shells, or cones](https://wikiless.org/wiki/Cone_snail?lang=en)
are a large group of small- to large-sized
**extremely venomous predatory**
sea snails, marine gastropod molluscs.

![A group of shells of various species of cone snails](https://wikiless.org/media/wikipedia/commons/7/7f/Sto%C5%BCki2.jpg)

The intricate color patterns of cones have made them one of the most popular collectible shells.

Most of the cone snails that hunt worms rather than fish
are probably not a risk to humans, with the possible exception of larger species.
Symptoms of a more serious cone snail sting include intense,
localized pain, swelling, numbness and tingling and vomiting.
Symptoms can start immediately or can be delayed for days.
Severe cases involve muscle paralysis, changes in vision,
and respiratory failure that can lead to death.

<sup>SOURCE: https://wikiless.org/wiki/Cone_snail?lang=en</sup>

As deadly as they may be, Cone Snails got nothing on minishells.

## 🧐 About <a name = "about"></a>

```elixir
/-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\
|                                                                                                    |
|                                                                                                    |
|                                                            ....:^~^:::..                           |
|                                                       ..:~~7?JP#PP?!7YY5J~^.                       |
|                                                     .^~77?JYJ??5PJ?7!!?5P5Y?7^^.                   |
|                                                  .^^!7???55J7!?J77J5G55GPJ7??~Y5Y7^:..             |
|                                               ..~75P?!!!7Y??JYY7!7!5PP5J7!?YYJJ7??5J7!!7~^^::...   |
|                                             ..~!7J??7~!7?Y~!~~7~!?7??JJ77!^7??7?YJJ7J7P?!?!77777.  |
|                                           ..:!7?!P?!~~~!?5~~~?7^!77!^~?7P?!^:^!??JJ!!!~!^^::::~.   |
|                                        .::~!57???Y7!!^^~?5?~^!!~!~!???Y!7J?~:^~^~^~~^:..!~:::^:    |
|                                      .^^~!?PG577?YJ7!!!~~7Y?~55~??^~557~^7^^^:~~::.:^^:..:^~~:     |
|                                    .:^^!!!J7??~??7!7!!~~^~Y7~~~!!?~^^..^~~~!~:^:^::^^....^!~^.     |
|                                  .7::^~~7?!^~^^!?YJJ!~^:~~^7~~J7~^^!!!^~~:!^.::^77:.....^77::      |
|                                ..:~^^777?J^::^:7Y7777!::^^:Y5?~.:!^^!~::^:~^^...::...:~!7?7^~      |
|                              ..::^~YY!~7?!^::::^~!YJ5J!^:.:~!5Y^.!?~^.^!^7!7?~^..:^.:^7?7?!77      |
|                            .:^::::^~!~^J!~!!P?!^J75PPP5Y^^::.!!~^.^^^:^^..:JJ!~..:^^^~?7~~5?7      |
|                           .!?^..::^!?B7YJ7PP!JP?!5BB##&B7...:::^^.~^^^.::.:!~~:.:^~755Y~^77?~      |
|                         .^!!!^.^~^:J5Y77~7Y!:!!?7?GY5PB@P~.:...:~~^::. ^^^:^....:!7!PP~~~~!?:      |
|                       .:7Y77J!::J#J7!Y?!~!7^::77^:!!!!7GY!:.:.^:..:~!!:::~::..::^^^~!!~~^~7~:      |
|                      .~!!!7?57?~B#5^:?7~YPJ^^!!~^:~^:..:^:..^!^.  ..:!~^JY^.. ::^~Y??7~^7!!~.      |
|                    ..~!?!^~GY7PY#B?~:..:^7!^:~~!~^......:::^~?^::...   .^!~~~^^~~7Y!~7~^!^??       |
|                  ....:75YY~7?7777Y^..:^::!^.:^7?~7:....:.:.~~?7~~^::... .:..^!^~J!!~~~^:~~7^       |
|                 .:...:~5J~!7?~^J77^:.::..^:^7!?::7J~:::!J!~~J57~77^~~:..^^:..:^^~~!!^:.^5?^        |
|               .^^::.::^57!J?Y7:~^:!~::.::^.^?7J7^YY7~~~:7Y!:!!~^::..^^^:::::::^^:^~~!~:7J^         |
|              :~::^^^:^7!~^^~~:^^!7J5!7:^^^^!!!7^~!!!^:.^~!!^^^:.....::.....:::^~!!!!!~~~:          |
|            .~!~7P?^!?:^..^:^~^7~:7??YY~!7:.~~!~^:~!!^~7!!7!~~^^^^^^^^~~~~!!77777!!~!7^:.           |
|           .~^~PP?!7!J:.:...:.:~Y?Y5JJJ7!J!^~!~!!^^^~^^~^^~~~~!77777??????777!7777!^^^.             |
|         .^^!7~Y!:^~7:::..:..:7~^!!!7?!^~~~!!!~~7!!~~~~!!77????JJ????777!!!!7J7?!!^:.               |
|        ^!~J7J?~?:~!?7!:!^~77J77~~~???7!!7??JJJJYYYYYYYJJJJ????7777!!!!~!!!~!7^:..                  |
|      .7Y77J?7!~!!!JYY??JJJYJJJ?JJJJY55PPGGGPPP555YYJJ???77777!77?!!!~~^^^^^..                      |
|     .5BG5YJ55YY7??J5GGB############BBBBGGP55YYJJJ???7!!~^^^~^:77~^:::.....                         |
|    .5&&###BBB#&&@@@@@@@@@&&&&###BBGGPPP55YJJJJJJJ?~^:...         .                                 |
|   .JYYJJP#&&&@@@@@@@&&&&&&###BGGGPPPP5YYJP?!~!^~~::::..... ..                                      |
|        :55GB#&&&&&&&&&&##BBGGPP5J?7!^^^!~^:..:..:......                                            |
|         .~?YB###&&####BGP5YYJ^:...............                                                     |
|          ~77YGBBBGP57!!^^^^~!:....                                                                 |
|         .~!7!~~~^::::^:......                                                                      |
|       ..:~^... ..                                                                                  |
|                                                                                                    |
|-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|
|                                                                                                    |
|                                __        __        /\            __   __                           |
|                         _____ |__| ____ |__| ______  |__   ____ |  | |  |                          |
|                        /     \|  |/    \|  |/  ___/  |  \_/ __ \|  | |  |                          |
|                       |  | |  \  |   |  \  |\___ \|      \  ___/_  |__  |__                        |
|                       |__|_|  /__|___|  /__|____  \___|  /\___  /____/____/                        |
|                             \/        \/        \/     \/     \/                                   |
|                                                                                                    |
|                                 - CONTROL+C: Reads new line                                        |
|                                 - CONTROL+D: Exits program cleanly                                 |
|                                                                                                    |
\-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=/
```

A fully featured shell based on bash.
It reads a command from the user, lexes it, parses it, and executes it.
It can handle pipes, file redirections and heredocs.
It has a working history and responds to signals.
It also took 12 years to make (🤭).

For more details and examples you can read
the [Docs](./docs) and the [Checklist](./docs/checklist.md).

## 🏁 Getting Started <a name = "getting_started"></a>

### 📦 Dependencies

You will need to install `libreadline-dev`.
You can get it through apt-get (recommended):

```bash
$ sudo apt-get install libreadline-dev
```

Or you could build it yourself if you're into that:

- https://git.savannah.gnu.org/cgit/readline.git?h=devel

### 🖥️ Installing

Clone the repo and build with `make`:

```bash
$ git clone --recurse-submodules https://github.com/librity/ft_minishell.git
$ cd ft_minishell
$ make
```

Run the examples with:

```bash
$ ./scripts/run.sh
```

## 🧪 Tests <a name = "tests"></a>

You can run all tests with:

```bash
$ make -s tests
```

Or individual tests with:

```bash
$ make -s test t=lexer
```

## 📝 Notes <a name = "notes"></a>

- [Docs](./docs)

## 🛸 42 São Paulo <a name = "ft_sp"></a>

Part of the larger [42 Network](https://www.42.fr/42-network/),
[42 São Paulo](https://www.42sp.org.br/) is a software engineering school
that offers a healthy alternative to traditional education:

- It doesn't have any teachers and classes.
- Students learn by cooperating
  and correcting each other's work (peer-to-peer learning).
- Its focus is as much on social skills as it is on technical skills.
- It's completely free to anyone that passes its selection process -
  [**The Piscine**](https://42.fr/en/admissions/42-piscine/)

It's an amazing school, and I'm grateful for the opportunity.

## 📚 Resources <a name = "resources"></a>

- [Docs](./docs)
