#include "shell.h"

/**
 * compr_term - compares env variables names
 * with the name passed.
 * @env: name of the environment variable in the func
 * @term: name passed in the func
 *
 * Return: 0 if aren't equal and Another value if they be.
 */
int compr_term(const char *env, const char *term)
{
	int p;

	for (p = 0; env[p] != '='; p++)
	{
		if (env[p] != term[p])
		{
			return (0);
		}
	}

	return (p + 1);
}

/**
 * gets_env - gets an environment variable in the func
 * @term: name of the environment variable in the func
 * @_envs: environment variable passes
 *
 * Return: value of the environment variable ifseen.
 * If not, return NULL
 */
char *gets_env(const char *term, char **_envs)
{
	char *ptr_env;
	int p, mov;

	/* Initialize ptr_env value */
	ptr_env = NULL;
	mov = 0;
	/* Compare all environment variables */
	/* environ is declared in the header file */
	for (p = 0; _envs[p]; p++)
	{
		/* If name and env are equal */
		mov = compr_term(_envs[p], term);
		if (mov)
		{
			ptr_env = _envs[p];
			break;
		}
	}

	return (ptr_env + mov);
}

/**
 * print_env - prints evironment variables seen
 *
 * @facts: data useful.
 * Return: int value on success.
 */
int print_env(Data *facts)
{
	char **env_var;

	facts->status = EXIT_SUCCESS;

	for (env_var = facts->_envs; *env_var; env_var++)
	{
		write(STDOUT_FILENO, *env_var, strlen(*env_var));
		write(STDOUT_FILENO, "\n", 1);
	}
	return (facts->status);
}

