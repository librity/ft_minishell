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

![A group of shells of various species of cone snails](https://upload.wikimedia.org/wikipedia/commons/thumb/b/b4/12_Conidae_seashells.webp/1200px-12_Conidae_seashells.webp.png)

The intricate color patterns of cones have made them one of the most popular collectible shells.

Most of the cone snails that hunt worms rather than fish
are probably not a risk to humans, with the possible exception of larger species.
Symptoms of a more serious cone snail sting include intense,
localized pain, swelling, numbness and tingling and vomiting.
Symptoms can start immediately or can be delayed for days.
Severe cases involve muscle paralysis, changes in vision,
and respiratory failure that can lead to death.

<sup>SOURCE: https://wikiless.org/wiki/Cone_snail?lang=en</sup>

As deadly as they may be, cone snails ain't got nothing on minishells.

## 🧐 About <a name = "about"></a>

```elixir
/-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\
|                                                                                |
|                                                                                |
|                                              .:~!?5J7!!?7!:.                   |
|                                          .:~!7JY??P5J7!7YG5J7^:.               |
|                                       .:~!!?7Y5J??J77YG55PJ?J!JY?!^:..         |
|                                     .:!?5Y~77J777?!!7?55Y!!7YY?7?YJ77?77!~~^:  |
|                                   ..!?7J7~~!7Y~~!7~!?7!7?77~^~!?JY7777^~^~^!.  |
|                                .:^!J???J!!~^!Y?~~7~~~77P?!J7^:~~~~~^::~^::^:   |
|                              .^^~75GJ7?J77!!~!Y77Y!?7^J?!^!^~^~^:.:^:..:~~:    |
|                            .::^!!7!7~!?J77!~^~7!~~7!!~~::~^~~:^^!^::..:!!^.    |
|                          .:!:~7!?7^^^~J?J7~::~:J77^^^^!~^~^~:..:~:..:^!?~^.    |
|                        ..::~Y7~77^:::^!7JYJ~:::!JY^:7~^:^^!!7!^.:^..~77?!?.    |
|                      .^^:::^~!~J!!7P?!7?PGGP?::.:!~:.~^:^:.^J7~..^~~7?~!Y7.    |
|                     .~7^.::^JPJ?7YY~JY!5GB#&B~..:.:^::::.:.:~::.^!7G5~^!7!     |
|                   .!?!7^:~5!?J7~^?~:~7~!?7?5#?:...:::^^:.:~:...::~~?7~~~7^     |
|                  ^!!7757~Y&Y:7?!YY^^!!^:~^::^^:.~~: ..:7^!J^:.:^^??7!^!!~^     |
|                .:!77^JY?YGB7:..:!!^:^7!^.....:.^!!::..  .:!^~^^~!Y!!!^~^J:     |
|              ....^557!7!777^.::::^:^!!^!^:..~^:!??~!~^^...:..^^~7~!^^:!!~      |
|            .:^:.::Y7!?J~^!^~:...:::777^YJ~~^!J!^?7^^^:^^:^^:::^^^~~~:^Y!.      |
|           :^:^:^:!7~^~!^^~!JJ!:^^^!77!^!7~^:^!!^~^....:::...::^~!!!!~!^        |
|          ^!7JY~77^..::^^7^7JJ5!!!:^~!^:~!~~7!!!~~^^~~~~~~!!77777!~!!:.         |
|        .^~~Y!~!!~......^!J?JP?!~7~!!~!~^^^^~^~!!7????????77777777^:.           |
|      .^~7?7?~^~7~^::^^77~^~7?7~~!7777??????JJJJJ???777!!!!!~?7~^:.             |
|     :?77J?7~!~7YJ7JJJYJ?JJ?JY555PPPP555YYJJ???777777!!~~~^^^:.                 |
|    ^GBP5YP5YJY5GB##&#######BBBGGP55YJJJ?77!~^::^:^!^:.                         |
|   ^G&BB###&@@@@@@@@&&&&#BBGGPP55YJJ??7?!::.                                    |
|   :..:YG#&&&&&&&&&&##BBGP55Y?77?!~^::.^                                        |
|       :!JG##&&&##BBP55Y!^:::^                                                  |
|        ~7JPGGP5J!~^^:^                                                         |
|       .~~^:::                                                                  |
|                                                                                |
|                                                                                |
|-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|
|                                                                                |
|                      __        __        /\            __   __                 |
|               _____ |__| ____ |__| ______  |__   ____ |  | |  |                |
|              /     \|  |/    \|  |/  ___/  |  \_/ __ \|  | |  |                |
|             |  | |  \  |   |  \  |\___ \|      \  ___/_  |__  |__              |
|             |__|_|  /__|___|  /__|____  \___|  /\___  /____/____/              |
|                   \/        \/        \/     \/     \/                         |
|                                            by lpaulo-m & wwallas-              |
|                                                                                |
|              - CONTROL+C: Reads new line                                       |
|              - CONTROL+D: Exits program cleanly                                |
|              - help: Print help message                                        |
|                                                                                |
\-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=/
```

A fully featured shell based on bash.
It reads a command from the user, lexes it, parses it, and executes it.
It handles pipes, file redirections and heredocs.
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

This should create a `minishell` executable in the root folder:

```bash
./minishell
```

You can also run it in debug mode with the flag `-d`:

```bash
./minishell -d
```

## 🧪 Tests <a name = "tests"></a>

You can run all tests with:

```bash
$ make -s tests
```

Or individual tests with:

```bash
$ make -s test t=lexer/tokens
```

You can also run them with `valgrind`:

```bash
$ make -s vgtests
$ make -s vgtest t=lexer/tokens
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
