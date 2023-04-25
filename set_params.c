#include "main.h"

/**
 * init_params - set all fields to initial values
 * @prm: struct
 * Return: void
 */

void init_params(params *prm)
{
	prm->unsign_f = 0;
	prm->plus_f = 0;
	prm->space_f = 0;
	prm->hashtag_f = 0;
	prm->zero_f = 0;
	prm->minus_f = 0;

	prm->width = 0;
	prm->precision = UINT_MAX;

	prm->h_modifier = 0;
	prm->l_modifier = 0;
}
