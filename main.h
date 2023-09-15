#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>


/* READ_BUF_SIZE */
#define MY_READ_BUF_SIZESHLL 1024
/* WRITE_BUF_SIZE */
#define MY_WRITE_BUF_SIZESHLL 1024
/* BUF_FLUSH */
#define MY_BUF_FLUSHSHLL -1


/*This part is for command chain*/
#define MY_CMD_NORMSHLL	0
#define MY_CMD_ORSHLL		1
#define MY_CMD_ANDSHLL		2
#define MY_CMD_CHAINSHLL	3

/* This part is  for convert_number() */
#define MY_CONVERT_UNSIGNEDSHLL	2
#define MY_CONVERT_LOWERCASESHLL	1

/* This part is  for: IF USING SYSTEM getline()*/
#define MY_USE_GETLINESHLL	0
#define MY_USE_STRTOKSHLL	0

#define MY_HIST_MAXSHLL	4096
#define MY_HIST_FILESHLL	".simple_shell_history"

extern char **my_environShll;

/**
 * struct my_liststrShll - singly linked list
 * @my_numShll: number field
 * @my_strShll: string
 * @my_nextShll: pointer to next node
 */
typedef struct my_liststrShll
{
	int my_numShll;
	char *my_strShll;
	struct my_liststr *my_nextShll;
} my_list_stShll;

/**
 * struct my_passinfoShll - it contains :  pseudo-arguments to pass into a function
 * allowing uniform prototype function pointer struct
 * @my_argShll: a string generated from getline containing arguments
 * @my_argvShll: an array of string
 * @my_pathShll: a string path for the current command
 * @my_argcShll: argument count
 * @my_line_countShll: error count
 * @my_err_numShll: error code for exit()s
 * @my_linecount_flagShll: if on count this line of input
 * @my_fnameShll: program file name
 * @my_envShll: linked list local copy of environ
 * @my_environShll: custom modified copy of environ from ll env
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
	char **my_environShll;
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
 * struct builtin - have built in string and related functions
 * @my_typeShll: variable for the builting command flag
 * @my_funcShll: function
 */
typedef struct my_builtinShll
{
	char *my_typeShll;
	int (*my_funcShll)(my_info_stShll *);
} my_builtin_tableShll;

void my_exe_cmdShll(char **my_argvShll); 
void my_get_locationShll(info_st *my_infoShll); 

/* This file is created by EL HAKIK Amina and Mehdi Belaazri string.c */
int _strlenShll(char *my_sShll);
char *_strcatShll(char *my_destShll, char *my_srcShll);
char *_strdupShll(const char *my_strShll);
char *_strcpyShll(char *my_destShll, char *my_srcShll);
char *my_starts_withShll(const char *my_haystackShll, const char *my_needleShll);

/* This file is created by EL HAKIK Amina and Mehdi Belaazri string_1.c*/
int _putcharShll(char my_cShll);
void _putsShll(char *my_strShll);
int _strcmpShll(char *my_s1Shll, char *my_s2Shll);

/* This file is created by EL HAKIK Amina and Mehdi Belaazri string_2.c*/
char *_strchrShll(char *my_sShll, char my_cShll);
char *_strncatShll(char *my_destShll, char *my_srcShll, int my_nShll);
char *_strncpyShll(char *my_destShll, char *my_srcShll, int my_nShll);

/* This file is created by EL HAKIK Amina and Mehdi Belaazri enviroment_var.c*/
char *_getenvShll(my_info_stShll *my_infoShll, const char *my_nameShll);
int _myenvShll(my_info_stShll *my_infoShll);
char **my_get_environShll(my_info_stShll *my_infoShll);
int my_populate_env_listShll(my_info_stShll *my_infoShll);
int _mysetenvShll(my_info_stShll *);

/* This file is created by EL HAKIK Amina and Mehdi Belaazri  enviroment_var1.c*/
int _setenvShll(my_info_stShll *my_infoShll, char *my_varShll, char *my_valueShll);
int _unsetenvShll(my_info_st *my_infoShll, char *my_varShll);
int _myunsetenvShll(my_info_stShll *my_infoShll);

/* This file is created by EL HAKIK Amina and Mehdi Belaazri list_string.c*/
size_t my_print_liststrShll(const my_list_st *my_hShll);
list_st *my_add_nodeShll(my_list_st **my_headShll, const char *my_strShll, int my_numShll);
list_st *my_add_node_endShll(my_list_st **my_headShll, const char *my_strShll, int my_numShll);
size_t my_print_listShll(const my_list_st *my_hShll);
list_st *my_node_starts_withShll(my_list_st *my_nodeShll, char *my_prefixShll, char my_cShll);

/* This file is created by EL HAKIK Amina and Mehdi Belaazri  list_string1.c*/
int my_delete_node_at_indexShll(my_list_st **my_headShll, unsigned int my_indexShll);
ssize_t my_get_node_indexShll(my_list_st *my_headShll, list_st *my_nodeShll);
char **my_list_to_stringsShll(my_list_st *my_headShll);
size_t my_list_lenShll(const my_list_st *my_hShll);

/* This file is created by EL HAKIK Amina and Mehdi Belaazri  path.c*/
char *my_dup_charsShll(char *my_pathstrShll, int my_startShll, int my_stopShll);
char *my_get_pathShll(my_info_st *my_infoShll, char *my_pathstrShll, char *my_cmdShll);
int my_is_cmdShll(my_info_st *my_infoShll, char *my_pathShll);

/* This file is created by EL HAKIK Amina and Mehdi Belaazri  function1.c*/
void my_print_errorShll(my_info_st *my_infoShll, char *my_estrShll);
int my_print_dShll(int my_inputShll, int my_fdShll);
int my_is_delimShll(char my_cShll, char *my_delimShll);
int my_interactiveShll(my_info_st *my_infoShll);
char *my_convert_numberShll(long int my_numShll, int my_baseShll, int my_flagsShll);

/* This file is created by EL HAKIK Amina and Mehdi Belaazri  function2.c*/
void my_remove_commentsShll(char *my_bufShll);
int _erratoiShll(char *my_sShll);

/* This file is created by EL HAKIK Amina and Mehdi Belaazri  errstr_func.c*/
int _eputcharShll(char my_cShll);
void _eputsShll(char *my_strShll);
int _putfdShll(char my_cShll, int my_fdShll);
int _putsfdShll(char *my_strShll, int my_fdShll);

/* This file is created by EL HAKIK Amina and Mehdi Belaazri  fork.c*/
void my_fork_cmdShll(my_info_stShll *my_infoShll);

/* This file is created by EL HAKIK Amina and Mehdi Belaazri  info_st.c*/
void my_free_infoShll(my_info_stShll *my_infoShll, int my_allShll);

/* This file is created by EL HAKIK Amina and Mehdi Belaazri  memory_func.c*/
int my_bfreeShll(void **my_ptrShll);
void my_ffreeShll(char **_pp);
void my_free_listShll(list_stShll **my_head_ptrShll);
void *_reallocShll(void *my_ptrShll, unsigned int my_old_sizeShll, unsigned int my_new_sizeShll);
char *_memsetShll(char *my_sShll, char my_bShll, unsigned int my_nShll);

/* This file is created by EL HAKIK Amina and Mehdi Belaazri  hsh*/
int my_find_builtinShll(info_stShll *my_infoShll);
int my_hshShll(my_info_stShll *my_infoShll, char **my_avShll);

/* This file is created by EL HAKIK Amina and Mehdi Belaazri  builtin_commands.c*/
int _myexitShll(my_info_stShll *my_infoShll);
int _myhelpShll(my_info_stShll *my_infoShll);
int my_print_aliasShll(my_list_stShll *my_nodeShll);
int _myaliasShll(my_info_stShll *my_infoShll);
int _mycdShll(my_info_stShll *my_infoShll);

/* This file is created by EL HAKIK Amina and Mehdi Belaazri  builtin_commands2.c*/
int _myhistoryShll(my_info_stShll *my_infoShll);
int my_unset_aliasShll(my_info_stShll *my_infoShll, char *my_strShll);
int my_set_aliasShll(my_info_stShll *my_infoShll, char *my_strShll);

/* This file is created by EL HAKIK Amina and Mehdi Belaazri io_functions.c*/
char *my_get_history_fileShll(my_info_stShll *my_infoShll);
int my_read_historyShll(my_info_stShll *my_infoShll);
int my_build_history_listShll(my_info_stShll *my_infoShll, char *my_buf, int my_linecountShll);
int my_renumber_historyShll(my_info_stShll *my_infoShll);
int my_write_historyShll(my_info_stShll *my_infoShll);

/* This file is created by EL HAKIK Amina and Mehdi Belaazri  stinfo.c*/
void my_set_infoShll(my_info_stShll *my_infoShll, char **my_avShll);
void my_clear_infoShll(my_info_stShll *my_infoShll);

/* This file is created by EL HAKIK Amina and Mehdi Belaazri  chain.c*/
int my_is_chainShll(my_info_stShll *my_infoShll, char *my_bufShll, size_t *my_pShll);
void my_check_chainShll(my_info_stShll *my_infoShll, char *my_bufShll, size_t *my_pShll, size_t my_iShll, size_t my_lenShll);
int my_replace_aliasShll(my_info_stShll *my_infoShll);
int my_replace_varsShll(my_info_stShll *my_infoShll);
int my_replace_stringShll(char **my_oldShll, char *my_newShll);

/* This file is created by EL HAKIK Amina and Mehdi Belaazri  strtok.c*/
char **my_str_tok(char *my_strShll, char *my_dShll);
char **my_str_tok2(char *my_strShll, char my_dShll);

/* This file is created by EL HAKIK Amina and Mehdi Belaazri  getline.c*/
void my_sigintHandlerShll(__attribute__((unused))int my_sig_numShll);
int _getlineShll(my_info_stShll *my_info, char **ptr, size_t *my_lengthShll);
ssize_t my_read_bufShll(my_info_stShll *my_infoShll, char *my_bufShll, size_t *iShll);
ssize_t my_get_inputShll(my_info_stShll *my_infoShll);
ssize_t my_input_bufShll(my_info_stShll *my_infoShll, char **my_bufShll, size_t *my_lenShll);
#endif

