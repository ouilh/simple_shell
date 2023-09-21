#include "shell.h"

/**
 * mexit - exits the shell
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: exits with a given exit status
 * (0) if info.argv[0] != "exit"
 */
int mexit(info_t *info)
{
	int exit;
	int numbers[4] = {1, -1, 2, -2};

	if (info->argv[numbers[0]]) /* If there is an exit arguement */
	{
		exit = _erratoi(info->argv[numbers[0]]);
		if (exit == numbers[1])
		{
			info->status = numbers[2];
			print_error(info, "Illegal number: ");
			_eputs(info->argv[numbers[0]]);
			_eputchar('\n');
			return (numbers[0]);
		}
		info->err_num = _erratoi(info->argv[numbers[0]]);
		return (numbers[3]);
	}
	info->err_num = numbers[1];
	return (numbers[3]);
}

/**
 * _cd - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _cd(info_t *info)
{
	char *s, *di, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		di = _getenv(info, "HOME=");
		if (!di)
			chdir_ret = /* TODO: what should this be? */
				chdir((di = _getenv(info, "PWD=")) ? di : "/");
		else
			chdir_ret = chdir(di);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret = /* TODO: what should this be? */
			chdir((di = _getenv(info, "OLDPWD=")) ? di : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _help - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _help(info_t *info)
{
	char **arg_ar;

	arg_ar = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_ar); /* temp att_unused workaround */
	return (0);
}
