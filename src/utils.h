#ifndef _DECODE
#define _DECODE
#define BUFF_SIZE 1024

typedef int (*operation_t)(int, int, int);
typedef enum {FALSE,TRUE} Boolean;

/*! \brief print tab of int.
 *
 * \param tab to print.
 * \param tailletab tenth of tab.
 */
void afficheint(int * tab,int tailletab);

/*! \brief convert a sting to int tab.
 *
 * \param tab to convert.
 * \param alaphabet.
 */
void string_to_int(char * tab, char * alaphabet, int * itab);

/*! \brief convert a char to int.
 *
 * \param l cahr to convert.
 * \param alaphabet.
 */
int alpha_to_int(char l,char * alaphabet);

/*! \brief add or substract tab and key.
 *
 * \param iclef int tab and iclef int tab.
 * \param tailletab tailleclef lenth of int tab.
 * \operation_t operation pointer to fuction in main.
 */
void codclef (int * iclef,int * itab,int tailletab,int tailleclef,int taillalpha, operation_t operation);

/*! \brief convert int tab to char tab.
 *
 * \param itab tab of result in int.
 * \param tab result tab in char.
 * \param alphabet.
 * \param tailletab lenth of itab.
 */
void int_to_alpha(int * itab, char * tab, char * alphabet,int tailletab);

/*! \brief read a string from file.
 *
 * \param read_file name of the file to read.
 * \return the content of the file.
 */
char * file_to_string(char * read_file);

/*! \brief write a string in a file.
 *
 * \param file name.
 * \param var result tab.
 */
void write_file(char * file, char * var);

/*! \brief remove uknow char from tab.
 *
 * \param tab tab of key.
 * \param alphabet 
 */
void rm_unknown_char(char * tab, char * alphabet);

/*! \brief error fuction.
 *
 * \param e option of error.
 */
void error(int e);

/*! \brief test if char is in alphabet.
 *
 * \param tab of int.
 * \param lenth of the int tab. 
 */
void testclef(int * itab, int tailleclef);

/*! \brief programme manual.
 *
 * \param option for the man. 
 */
void print_man(Boolean option);
#endif