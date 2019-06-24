
#include <stdio.h>
#include <string.h>

typedef struct
{
	char serie_calculator[45];
	// ...
} Calculator;

size_t remove_all( Calculator c[], size_t n, const char *s )
{
	size_t i = 0;

	for ( size_t j = 0; j < n; j++ )
	{
		if ( !( strcmp( c[j].serie_calculator, s ) == 0 ) )
		{
			if ( i != j ) c[i] = c[j];
			++i;
		}
	}

	return i;
}

int main(void)
{
	Calculator c[] = { { "A" }, { "B" }, { "C" }, { "A" }, { "D" }, { "E" }, { "A" } };
	const size_t N = sizeof( c ) / sizeof( *c );

	for ( size_t i = 0; i < N; i++ ) printf( "%s ", c[i].serie_calculator );
	printf( "\n" );

	size_t n = remove_all( c, N, "A" );

	for ( size_t i = 0; i < n; i++ ) printf( "%s ", c[i].serie_calculator );
	printf( "\n" );

	return 0;
}
