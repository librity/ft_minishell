/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   virtual_table_oop.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:24:53 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/22 17:24:55 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc virtual_table_oop.c && ./a.out

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_animal		t_animal;
typedef struct s_animal_vt	t_animal_vt;

struct						s_animal
{
	char					*name;
	int						treats;
	t_animal_vt				*vt;
};

typedef						void(t_animal_call)(t_animal *self);
typedef						void(t_animal_give_treats)(t_animal *self,
								int treats);
typedef						void(t_animal_destroy)(t_animal *self);
typedef						void(t_animal_free)(t_animal *self);

typedef struct s_animal_vt
{
	t_animal_call			*call;
	t_animal_give_treats	*give_treats;
	t_animal_destroy		*destroy;
	t_animal_free			*free;
}							t_animal_vt;

static void	_call(t_animal *self)
{
	printf("Come here %s!\n", self->name);
}

static void	_give_treats(t_animal *self, int treats)
{
	self->treats += treats;
}

static void	_destroy(t_animal *self)
{
	free(self->name);
}

static void	_free(t_animal *self)
{
	free(self);
}

static t_animal_vt			_animal_vt;
static bool					_animal_vt_initialized = false;

static void	_init_animal_vt(void)
{
	if (_animal_vt_initialized)
		return ;
	_animal_vt.destroy = _destroy;
	_animal_vt.free = _free;
	_animal_vt.give_treats = _give_treats;
	_animal_vt.call = _call;
	_animal_vt_initialized = true;
}

typedef struct s_animal_new_params
{
	char					*name;
}							t_animal_params;

void	init_animal(t_animal *self, const t_animal_params *params)
{
	bzero(self, sizeof(t_animal));
	_init_animal_vt();
	self->vt = &_animal_vt;
	self->name = strdup(params->name);
	self->treats = 0;
}

static inline void	deinit_animal(t_animal *self)
{
	self->vt->destroy(self);
}

static inline void	animal_give_treats(t_animal *self, int treats)
{
	self->vt->give_treats(self, treats);
}

static inline void	animal_call(t_animal *self)
{
	self->vt->call(self);
}

t_animal	*new_animal(const t_animal_params *p_params)
{
	t_animal	*me;

	me = (t_animal *)malloc(sizeof(t_animal));
	init_animal(me, p_params);
	return (me);
}

void	delete_animal(t_animal *self)
{
	deinit_animal(self);
	self->vt->free(self);
}

int	main(void)
{
	t_animal	beygle;
	t_animal	*sparky;

	// Stack
	t_animal_params beygle_params = {
		.name = "Beygle"};
	init_animal(&beygle, &beygle_params);
	animal_call(&beygle);
	animal_give_treats(&beygle, 1);
	deinit_animal(&beygle);
	// Heap
	t_animal_params sparky_params = {
		.name = "Sparky"};
	sparky = new_animal(&sparky_params);
	animal_call(sparky);
	animal_give_treats(sparky, 1);
	delete_animal(sparky);
	return (0);
}
