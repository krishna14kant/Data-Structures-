// URL : https://leetcode.com/problems/bulb-switcher/

/*
* Solution 1 - O(1)
* =========
*
* We notice that for every light bulb on position i there will be one toggle for every
* one of its divisors, given that you toggle all of the multiples of one number. The
* total number of toggles is irrelevant, because there are only 2 possible positions(on,
* off). We quickly find that 2 toggles cancel each other so given that the start position
* is always off a light bulb will be in if it has been toggled an odd number of times.
* The only integers with an odd number of divisors are perfect squares(because the square
* root only appears once, not like the other divisors that form pairs). The problem comes
* down to finding the number of perfect squares <= n. That number is the integer part of
* the square root of n.
*
*/
class Solution {
public:
	int bulbSwitch(int n) {
		return (int)sqrt(n);
	}
};
