/* This program is a refactoring of example 5, chapter 8,
 * from the TLDP NCURSES Programming HOWTO. */

#include <ncurses.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////
// Structures
////////////////////////////////////////////////////////////////////////////////

struct comment
{
	int b_c; // Block comment.
	int l_c; // Line comment.
};

////////////////////////////////////////////////////////////////////////////////
// Function headers
////////////////////////////////////////////////////////////////////////////////

void u_err( char *argv[] ); // Usage error.

void init(); // Ncurses initialization functions.

void page_end(); // When cursor reaches the lowest display row, i.e. the end of a displayed page.

int in_comment( struct comment *p_c, int pp_ch, int p_ch, int c_ch, int n_ch ); // Determines if the char is in a comment.

void mod_font( 	int c_ch ); // Modify font.

////////////////////////////////////////////////////////////////////////////////
// Functions
////////////////////////////////////////////////////////////////////////////////

void u_err( char *argv[] )
{
	printf( "Usage: %s < a C file name >\n", argv[ 0 ] );
	exit( 1 );
}

void init()
{
	initscr();
}

void page_end()
{
	printw( "<-Press Any Key->");
	getch();
	clear();
	move( 0, 0 );
	refresh();
}

int in_comment( struct comment *p_c, int pp_ch, int p_ch, int c_ch, int n_ch )
{
	// Block comments
	if ( p_c->b_c == 0 && p_c->l_c == 0 && c_ch == '/' && n_ch == '*' )
		p_c->b_c = 1;
	else if ( p_c->b_c == 1 && p_c->l_c == 0 && pp_ch == '*' && p_ch == '/' )
		p_c->b_c = 0;

	// Line comments
	if ( p_c->b_c == 0 && p_c->l_c == 0 && c_ch == '/' && n_ch == '/' )
		p_c->l_c = 1;
	else if ( p_c->l_c == 1 && c_ch == '\n' )
		p_c->l_c = 0;

	return ( p_c->l_c || p_c->b_c );
}

void mod_font( int c_ch )
{
	addch( c_ch | A_BOLD );
}

////////////////////////////////////////////////////////////////////////////////
// Main
////////////////////////////////////////////////////////////////////////////////

int main( int argc, char *argv[] )
{ 
	int t_r; // Total row number.
	int t_c; // Total column number.
	int c_r; // Current row number.
	int c_c; // Current column number.

	int pp_ch = '\0'; // Previous previous character.
	int p_ch = '\0'; // Previous character.
	int c_ch; // Current character.
	int n_ch; // Next character.

	FILE *p_f; // Pointer to file.

	struct comment c_t_s = { 0, 0 }; // Comment type boolean states.

	if ( ( p_f = fopen( argv[ 1 ], "r" ) ) == NULL )
		u_err( argv );

	init();

	getmaxyx( stdscr, t_r, t_c );

	while ( ( c_ch = fgetc ( p_f ) ) != EOF )
	{
		n_ch = fgetc( p_f );
		ungetc( n_ch, p_f);

		getyx( stdscr, c_r, c_c );
		if ( c_r == t_r - 1 )
			page_end();

		if ( in_comment( &c_t_s, pp_ch, p_ch, c_ch, n_ch ) == 1 )
			mod_font( c_ch );
		else
			printw( "%c", c_ch );

		pp_ch = p_ch;
		p_ch = c_ch;
	}
	refresh();
	
	printw( "<-Press Any Key To Close->" );
	getch();
	endwin();
	fclose( p_f );

	return 0;
}
