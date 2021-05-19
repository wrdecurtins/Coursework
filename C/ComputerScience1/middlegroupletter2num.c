void letter2num( struct convert pairs[], int NumPair, char msg[][25], int many )
{
	int k, h;
	for( k = 0; k < many; k++ )
	{
		for( h = 0; h < NumPair; h++ )
		{
			if ( strcmp(pairs[h].words, msg[k]) == 0)
			{
				printf("%dâ", pairs[h].num);
			}
		}
	}
	printf("\n");
}

