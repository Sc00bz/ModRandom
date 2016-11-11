/**
 * Secure random source and no modulo bias.
 *
 * @param int max: The maximum random value to output. Valid values 0 <= max <= 0x7fffffff
 * @returns A random value 0 to max, or -1 on invalid max
 */
function secureRandom(max)
{
	var rand = new Uint32Array(1);
	var result;

	max = max | 0;
	if (max < 0 || max > 0x7fffffff)
	{
		return -1;
	}

	// If max+1 is a nice base 2 int (ie 2**n)
	if (((max + 1) & max) === 0)
	{
		window.crypto.getRandomValues(rand);
		result = rand[0] & max;
	}
	else
	{
		// skip is "n*(max+1)" for the largest n such that "n*(max+1) < 2**31"
		var skip = 0x7fffffff - 0x7fffffff % (max + 1);

		// Loop until random number is less than skip then modulo.
		// Note worst case is max is 2**30+1 and chances of looping are just less
		// than 50%. The chances of looping 128 times is so low (<1 in 2**128)
		// that the heat death of the universe would happen before this.
		do
		{
			window.crypto.getRandomValues(rand);
			result = rand[0] & 0x7fffffff;
		} while (result >= skip);
		result %= max + 1;
	}
	return result;
}
