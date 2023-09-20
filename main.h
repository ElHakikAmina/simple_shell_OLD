#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>


/* READ_BUF_SIZE */
#define MY_READ_BUF_SIZESHLL 1024
/* WRITE_BUF_SIZE */
#define MY_WRITE_BUF_SIZESHLL 1024
/* BUF_FLUSH */
#define MY_BUF_FLUSHSHLL -1


/* This part is for command chain*/
#define MY_CMD_NORMSHLL		0
#define MY_CMD_ORSHLL		1
#define MY_CMD_ANDSHLL		2
#define MY_CMD_CHAINSHLL	3

/* This part is for convert_number() */
#define MY_CONVERT_UNSIGNEDSHLL		2
#define MY_CONVERT_LOWERCASESHLL	1

/* This part is for: IF USING SYSTEM getline()*/
#define MY_USE_GETLINESHLL	0
#define MY_USE_STRTOKSHLL	0

#define MY_HIST_MAXSHLL	4096
#define MY_HIST_FILESHLL	".simple_shell_history"

extern char **environ;

/**
 * struct my_liststrShll - singly linked list
 *
 * @my_numShll: number field
 * @my_strShll: a string input
 * @my_nextShll: pointer to the next node
*/

typedef struct my_liststrShll
{
	int my_numShll;
	char *my_strShll;
	struct my_liststr *my_nextShll;
} my_list_stShll;

/**
 * struct my_passinfoShll - it contains :  pseudo-arguments to pass into a function
 *                          allowing uniform prototype function pointer struct
 *
 * @my_argShll: a string generated from getline containing arguments
 * @my_argvShll: an array of string
 * @my_pathShll: a string path for the current command
 * @my_argcShll: argument count
 * @my_line_countShll: error count
 * @my_err_numShll: error code for exit()s
 * @my_linecount_flagShll: if on count this line of input
 * @my_fnameShll: program file name
 * @my_envShll: linked list local copy of environ
 * @environ: custom modified copy of environ from ll env
 * @my_historyShll: history node
 * @my_aliasShll: alias node
 * @my_env_changedShll: on if environ changed
 * @my_statusShll: return status of the last executed command
 * @my_cmd_bufShll: address of pointer to cmd_buf, on if chain
 * @my_cmd_buf_typeShll: CMD_type ||, &&, ;
 * @my_readfdShll: fd from which to read the line input
 * @my_histcountShll: history line count
*/

typedef struct my_passinfoShll
{
	char *my_argShll;
	char **my_argvShll;
	char *my_pathShll;
	int my_argcShll;
	unsigned int my_line_countShll;
	int my_err_numShll;
	int my_linecount_flagShll;
	char *my_fnameShll;
	my_list_stShll *my_envShll;
	my_list_stShll *my_historyShll;
	my_list_stShll *my_aliasShll;
	char **environ;
	int my_env_changedShll;
	int my_statusShll;

	char **my_cmd_bufShll;
	int my_cmd_buf_typeShll;
	int my_readfdShll;
	int my_histcountShll;
} my_info_stShll;

#define MY_INFO_INITSHLL \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 * struct my_builtinShll - have built in string and related functions
 *
 * @my_typeShll: variable for the builting command flag
 * @my_funcShll: function
*/

typedef struct my_builtinShll
{
	char *my_typeShll;
	int (*my_funcShll)(my_info_stShll *);
} my_builtin_tableShll;

void my_exe_cmdShll(char **my_argvShll);
void my_get_locationShll(my_info_stShll *my_infoShll);

/* This file is created by EL HAKIK Amina and Mehdi Belaazri my_stringShll.c */
char *_strcpyShll(char *my_destShll, char *my_srcShll);
char *my_starts_withShll(const char *my_haystackShll, const char *my_needleShll);
char *_strdupShll(const char *my_strShll);
int _strlenShll(char *my_sShll);
char *_strcatShll(char *my_destShll, char *my_srcShll);

/* This file is created by EL HAKIK Amina and Mehdi Belaazri my_enviroment_var1Shll.c*/
int _unsetenvShll(my_info_stShll *my_infoShll);
int _setenvShll(my_info_stShll *my_infoShll, char *my_varShll, char *my_valueShll);
int _unsetenvShll(my_info_st *my_infoShll, char *my_varShll);

/* This file is created by EL HAKIK Amina and Mehdi Belaazri my_string_2Shll.c*/
char *_strncpyShll(char *my_destShll, char *my_srcShll, int my_nShll);
char *_strncatShll(char *my_destShll, char *my_srcShll, int my_nShll);
char *_strchrShll(char *my_sShll, char my_cShll);

/* This file is created by EL HAKIK Amina and Mehdi Belaazri my_string_1Shll.c*/
void _putsShll(char *my_strShll);
int _strcmpShll(char *my_s1Shll, char *my_s2Shll);
int _putcharShll(char my_cShll);

/* This file is created by EL HAKIK Amina and Mehdi Belaazri my_enviroment_varShll.c*/
char **my_get_environShll(my_info_stShll *my_infoShll);
int _setenvShll(my_info_stShll *);
char *_getenvShll(my_info_stShll *my_infoShll, const char *my_nameShll);
int my_populate_env_listShll(my_info_stShll *my_infoShll);
int _envShll(my_info_stShll *my_infoShll);

/* This file is created by EL HAKIK Amina and Mehdi Belaazri my_pathShll.c*/
int my_is_cmdShll(my_info_stShll *my_infoShll, char *my_pathShll);
char *my_get_pathShll(my_info_stShll *my_infoShll, char *my_pathstrShll, char *my_cmdShll);
char *my_dup_charsShll(char *my_pathstrShll, int my_startShll, int my_stopShll);

/* This file is created by EL HAKIK Amina and Mehdi Belaazri my_list_stringShll.c*/
my_list_stShll *my_add_nodeShll(my_list_stShll **my_headShll, const char *my_strShll, int my_numShll);
size_t my_print_liststrShll(const my_list_stShll *my_hShll);
size_t my_print_listShll(const my_list_stShll *my_hShll);
my_list_stShll *my_node_starts_withShll(my_list_stShll *my_nodeShll, char *my_prefixShll, char my_cShll);
my_list_stShll *my_add_node_endShll(my_list_stShll **my_headShll, const char *my_strShll, int my_numShll);

/* This file is created by EL HAKIK Amina and Mehdi Belaazri my_list_string1Shll.c*/
char **my_list_to_stringsShll(my_list_stShll *my_headShll);
int my_delete_node_at_indexShll(my_list_stShll **my_headShll, unsigned int my_indexShll);
size_t my_list_lenShll(const my_list_stShll *my_hShll);
ssize_t my_get_node_indexShll(my_list_stShll *my_headShll, my_list_stShll *my_nodeShll);

/* This file is created by EL HAKIK Amina and Mehdi Belaazri my_forkShll.c*/
void my_fork_cmdShll(my_info_stShll *my_infoShll);

/* This file is created by EL HAKIK Amina and Mehdi Belaazri my_info_stShll.c*/
void my_free_infoShll(my_info_stShll *my_infoShll, int my_allShll);

/* This file is created by EL HAKIK Amina and Mehdi Belaazri my_function1Shll.c*/
int my_interactiveShll(my_info_stShll *my_infoShll);
int my_print_dShll(int my_inputShll, int my_fdShll);
char *my_convert_numberShll(long int my_numShll, int my_baseShll, int my_flagsShll);
void my_print_errorShll(my_info_stShll *my_infoShll, char *my_estrShll);
int my_is_delimShll(char my_cShll, char *my_delimShll);

/* This file is created by EL HAKIK Amina and Mehdi Belaazri my_hshShll.c*/
int my_hshShll(my_info_stShll *my_infoShll, char **my_avShll);
int my_find_builtinShll(my_info_stShll *my_infoShll);

/* This file is created by EL HAKIK Amina and Mehdi Belaazri my_stinfoShll.c*/
void my_clear_infoShll(my_info_stShll *my_infoShll);
void my_set_infoShll(my_info_stShll *my_infoShll, char **my_avShll);

/* This file is created by EL HAKIK Amina and Mehdi Belaazri my_memory_funcShll.c*/
void my_free_listShll(list_stShll **my_head_ptrShll);
int my_bfreeShll(void **my_ptrShll);
void *_reallocShll(void *my_ptrShll, unsigned int my_old_sizeShll, unsigned int my_new_sizeShll);
char *_memsetShll(char *my_sShll, char my_bShll, unsigned int my_nShll);
void my_ffreeShll(char **_ppShll);

/* This file is created by EL HAKIK Amina and Mehdi Belaazri my_function2Shll.c*/
int _erratoiShll(char *my_sShll);
void my_remove_commentsShll(char *my_bufShll);

/* This file is created by EL HAKIK Amina and Mehdi Belaazri my_io_functionsShll.c*/
int my_build_history_listShll(my_info_stShll *my_infoShll, char *my_bufShll, int my_linecountShll);
int my_renumber_historyShll(my_info_stShll *my_infoShll);
char *my_get_history_fileShll(my_info_stShll *my_infoShll);
int my_read_historyShll(my_info_stShll *my_infoShll);
int my_write_historyShll(my_info_stShll *my_infoShll);

/* This file is created by EL HAKIK Amina and Mehdi Belaazri my_errstr_funcShll.c*/
int _putsfdShll(char *my_strShll, int my_fdShll);
int _eputcharShll(char my_cShll);
void _eputsShll(char *my_strShll);
int _putfdShll(char my_cShll, int my_fdShll);

/* This file is created by EL HAKIK Amina and Mehdi Belaazri  my_chainShll.c*/
int my_replace_aliasShll(my_info_stShll *my_infoShll);
int my_is_chainShll(my_info_stShll *my_infoShll, char *my_bufShll, size_t *my_pShll);
int my_replace_varsShll(my_info_stShll *my_infoShll);
int my_replace_stringShll(char **my_oldShll, char *my_newShll);
void my_check_chainShll(my_info_stShll *my_infoShll, char *my_bufShll, size_t *my_pShll, size_t my_iShll, size_t my_lenShll);

/* This file is created by EL HAKIK Amina and Mehdi Belaazri my_builtin_commandsShll.c, 2nd, 3rd and 4th*/
int _aliasShll(my_info_stShll *my_infoShll);
int _cdShll(my_info_stShll *my_infoShll);
int my_set_aliasShll(my_info_stShll *my_infoShll, char *my_strShll);
int my_unset_aliasShll(my_info_stShll *my_infoShll, char *my_strShll);
int _historyShll(my_info_stShll *my_infoShll);
int _exitShll(my_info_stShll *my_infoShll);
int my_print_aliasShll(my_list_stShll *my_nodeShll);
int _helpShll(my_info_stShll *my_infoShll);

/* This file is created by EL HAKIK Amina and Mehdi Belaazri  my_getlineShll.c*/
ssize_t my_input_bufShll(my_info_stShll *my_infoShll, char **my_bufShll, size_t *my_lenShll);
void my_sigintHandlerShll(__attribute__((unused))int my_sig_numShll);
ssize_t my_read_bufShll(my_info_stShll *my_infoShll, char *my_bufShll, size_t *my_iShll);
ssize_t my_get_inputShll(my_info_stShll *my_infoShll);
int _getlineShll(my_info_stShll *my_infoShll, char **my_ptrShll, size_t *my_lengthShll);

/* This file is created by EL HAKIK Amina and Mehdi Belaazri my_strtokShll.c*/
char **my_str_tok2(char *my_strShll, char my_dShll);
char **my_str_tok(char *my_strShll, char *my_dShll);

#endif

