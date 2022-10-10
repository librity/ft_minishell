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
