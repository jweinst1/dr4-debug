#include "row_info.h"
#include <string.h>

#define HANDLE_UNKNOWN_SIZER(row) \
               fprintf(stderr, "Internal Error: Got unrecognized size type %u for row\n", row->size_type); \
               exit(3)

void row_info_init_row(dr4_row_t* row)
{
	switch(row->size_type)
	{
		case DR4_SIZER_8:
		     ((dr4_row_8b_t*)row)->size = DR4_ROW_INFO_DEFAULT;
		     ((dr4_row_8b_t*)row)->content = malloc(DR4_ROW_INFO_DEFAULT);
		     break;
		case DR4_SIZER_16:
		     ((dr4_row_16b_t*)row)->size = DR4_ROW_INFO_DEFAULT;
		     ((dr4_row_16b_t*)row)->content = malloc(DR4_ROW_INFO_DEFAULT);
		     break;
		case DR4_SIZER_32:
		     ((dr4_row_32b_t*)row)->size = DR4_ROW_INFO_DEFAULT;
		     ((dr4_row_32b_t*)row)->content = malloc(DR4_ROW_INFO_DEFAULT);
		     break;
		default:
		     HANDLE_UNKNOWN_SIZER(row);
	}
}

void row_info_free_row(dr4_row_t* row)
{
	switch(row->size_type)
	{
		case DR4_SIZER_8:
		     free(((dr4_row_8b_t*)row)->content);
		     break;
		case DR4_SIZER_16:
		     free(((dr4_row_16b_t*)row)->content);
		     break;
		case DR4_SIZER_32:
		     free(((dr4_row_32b_t*)row)->content);
		     break;
		default:
		    HANDLE_UNKNOWN_SIZER(row);
	}
}
