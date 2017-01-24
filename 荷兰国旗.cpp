while£¨current <= end£©
{
	if (array[current] == 0)
	{
		swap(array[current], array[begin]);
		current++;
		begin++;
	}
	else if (array[current] == 1)
	{
		current++;
	}
	else
	{
		swap(array[current], array[end]);
		end--;
	}
}