/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:22:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/07 22:56:51 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

t_parse_list *_plist;

void setup(void)
{
	mock_initialize_shell();
}
void teardown(void)
{
	cleanup_shell();
}

MU_TEST(e_tst)
{
	_plist = NULL;

	add_exec(&_plist, (char *[]){"ls", NULL});
	execute_pipeline(_plist);

	// execve("/usr/bin/ls", (char *[]){"ls", NULL}, envht_to_envp());
}

MU_TEST(ls_multiple_arg_tst)
{
	_plist = NULL;
	add_exec(&_plist, (char *[]){"ls", "sources/", "tests/", NULL});
	execute_pipeline(_plist);

	_plist = NULL;
	add_exec(&_plist, (char *[]){"ls", "sources", "tests", NULL});
	execute_pipeline(_plist);
}

MU_TEST(ls_err_tst)
{
	_plist = NULL;

	add_exec(&_plist, (char *[]){"ls", "ls", NULL});
	execute_pipeline(_plist);
}

MU_TEST(ep_e_tst)
{
	_plist = NULL;

	add_exec(&_plist, (char *[]){"ls", "-a", NULL});
	add_pipe(&_plist);
	add_exec(&_plist, (char *[]){"grep", "main", NULL});

	execute_pipeline(_plist);
}

MU_TEST(etpet_e_tst)
{
	_plist = NULL;

	add_truncate(&_plist, "teste");
	add_exec(&_plist, (char *[]){"ls", "-la", NULL});
	add_pipe(&_plist);
	add_truncate(&_plist, "teste");
	add_exec(&_plist, (char *[]){"ls", NULL});
	execute_pipeline(_plist);
}

MU_TEST(etpete_e_tst)
{
	_plist = NULL;

	add_truncate(&_plist, "teste");
	add_exec(&_plist, (char *[]){"ls", "-la", NULL});
	add_pipe(&_plist);

	add_truncate(&_plist, "teste");
	add_exec(&_plist, (char *[]){"ls", NULL});
	add_pipe(&_plist);

	add_truncate(&_plist, "teste");
	add_exec(&_plist, (char *[]){"echo", "wallas", NULL});
	execute_pipeline(_plist);
}

MU_TEST(pera_e_tst)
{
	_plist = NULL;

	add_read_file(&_plist, "teste2");
	add_exec(&_plist, (char *[]){"tr", "w", "a", NULL});
	add_pipe(&_plist);

	add_truncate(&_plist, "teste2");
	add_exec(&_plist, (char *[]){"tr", "w", "b", NULL});
	execute_pipeline(_plist);
}

MU_TEST_SUITE(pipeline_suite)
{
	MU_SUITE_CONFIGURE(&setup, &teardown);

	//MU_RUN_TEST(e_tst);
	//MU_RUN_TEST(ls_multiple_arg_tst);
	//MU_RUN_TEST(ls_err_tst);

	//MU_RUN_TEST(ep_e_tst);
	//MU_RUN_TEST(etpet_e_tst); //acho que a saida esta diferente
	//MU_RUN_TEST(etpete_e_tst); // printou um esq aqui wtf
	//MU_RUN_TEST(pera_e_tst); acho que deveria printar no terminal
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(pipeline_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
