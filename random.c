#include <stdint.h>

uint8_t  randomUint8();
uint16_t randomUint16();
uint32_t randomUint32();
uint64_t randomUint64();

uint8_t  randomUint8 (uint8_t  max);
uint16_t randomUint16(uint16_t max);
uint32_t randomUint32(uint32_t max);
uint64_t randomUint64(uint64_t max);

/**
 * Shit random source.
 *
 * @returns A "random" uint8_t (0 to 2**8-1)
 */
uint8_t randomUint8()
{
#error "TODO implement good random"
	return (uint8_t) 4; // Chosen by fair dice roll.
	                    // Guaranteed to be random.
}

/**
 * Generates a random uint16_t uses randomUint8().
 *
 * @returns A random uint16_t (0 to 2**16-1)
 */
uint16_t randomUint16()
{
	uint16_t ret;

	ret  =  (uint16_t) randomUint8();
	ret |= ((uint16_t) randomUint8()) << 8;
	return ret;
}

/**
 * Generates a random uint32_t uses randomUint8().
 *
 * @returns A random uint32_t (0 to 2**32-1)
 */
uint32_t randomUint32()
{
	uint32_t ret;

	ret  =  (uint32_t) randomUint8();
	ret |= ((uint32_t) randomUint8()) << 8;
	ret |= ((uint32_t) randomUint8()) << 16;
	ret |= ((uint32_t) randomUint8()) << 24;
	return ret;
}

/**
 * Generates a random uint64_t uses randomUint8().
 *
 * @returns A random uint64_t (0 to 2**64-1)
 */
uint64_t randomUint64()
{
	return randomUint32() | (((uint64_t) randomUint32()) << 32);
}

/**
 * Random uint8_t with no modulo bias.
 *
 * @param uint8_t max: The maximum random value to output.
 * @returns A random value 0 to max
 */
uint8_t randomUint8(uint8_t max)
{
	uint8_t ret;

	// If nice base 2 modulo (ie 2**n)
	if (((max + 1) & max) == 0)
	{
		ret = randomUint8() & max;
	}
	else
	{
		// skip is "n*(max+1)" for the largest n such that "n*(max+1) < 2**8"
		uint8_t skip = UINT8_MAX - UINT8_MAX % (max + 1);

		// Loop until random number is less than skip then modulo.
		// Note worst case is max is 2**7+1 and chances of looping are just less
		// than 50%. The chances of looping 128 times is so low (<1 in 2**128)
		// that the heat death of the universe would happen before this.
		do
		{
			ret = randomUint8();
		} while (ret >= skip);
		ret %= max + 1;
	}
	return ret;
}

/**
 * Random uint16_t with no modulo bias.
 *
 * @param uint16_t max: The maximum random value to output.
 * @returns A random value 0 to max
 */
uint16_t randomUint16(uint16_t max)
{
	uint16_t ret;

	// If nice base 2 modulo (ie 2**n)
	if (((max + 1) & max) == 0)
	{
		ret = randomUint16() & max;
	}
	else
	{
		// skip is "n*(max+1)" for the largest n such that "n*(max+1) < 2**16"
		uint16_t skip = UINT16_MAX - UINT16_MAX % (max + 1);

		// Loop until random number is less than skip then modulo.
		// Note worst case is max is 2**15+1 and chances of looping are just less
		// than 50%. The chances of looping 128 times is so low (<1 in 2**128)
		// that the heat death of the universe would happen before this.
		do
		{
			ret = randomUint16();
		} while (ret >= skip);
		ret %= max + 1;
	}
	return ret;
}

/**
 * Random uint32_t with no modulo bias.
 *
 * @param uint32_t max: The maximum random value to output.
 * @returns A random value 0 to max
 */
uint32_t randomUint32(uint32_t max)
{
	uint32_t ret;

	// If nice base 2 modulo (ie 2**n)
	if (((max + 1) & max) == 0)
	{
		ret = randomUint32() & max;
	}
	else
	{
		// skip is "n*(max+1)" for the largest n such that "n*(max+1) < 2**32"
		uint32_t skip = UINT32_MAX - UINT32_MAX % (max + 1);

		// Loop until random number is less than skip then modulo.
		// Note worst case is max is 2**31+1 and chances of looping are just less
		// than 50%. The chances of looping 128 times is so low (<1 in 2**128)
		// that the heat death of the universe would happen before this.
		do
		{
			ret = randomUint32();
		} while (ret <= skip);
		ret %= max + 1;
	}
	return ret;
}

/**
 * Random uint64_t with no modulo bias.
 *
 * @param uint64_t max: The maximum random value to output.
 * @returns A random value 0 to max
 */
uint64_t randomUint64(uint64_t max)
{
	uint64_t ret;

	// If nice base 2 modulo (ie 2**n)
	if (((max + 1) & max) == 0)
	{
		ret = randomUint64() & max;
	}
	else
	{
		// skip is "n*(max+1)" for the largest n such that "n*(max+1) < 2**64"
		uint64_t skip = UINT64_MAX - UINT64_MAX % (max + UINT64_C(1));

		// Loop until random number is less than skip then modulo.
		// Note worst case is max is 2**63+1 and chances of looping are just less
		// than 50%. The chances of looping 128 times is so low (<1 in 2**128)
		// that the heat death of the universe would happen before this.
		do
		{
			ret = randomUint64();
		} while (ret >= skip);
		ret %= max + 1;
	}
	return ret;
}
