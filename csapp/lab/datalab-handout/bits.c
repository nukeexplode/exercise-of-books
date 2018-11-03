/* 

 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* 
 * absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int absVal(int x) {
  return ((x>>31)^(x+(x>>31)));
}
/* 
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) {
  int sx=x>>31;
  int sy=y>>31;
  int ss=(x+y)>>31;

  // return !(0x00000001 ^ ((sx ^ sy)&((sx&sy) ^ ss)));
  return !(~(sx^sy) & (ss^sx));
}
/* 
 * allEvenBits - return 1 if all even-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allEvenBits(0xFFFFFFFE) = 0, allEvenBits(0x55555555) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allEvenBits(int x) {
  int a = 0xaa;
  a |= a<<8;
  a |= a<<16;
  return !~(a|x);
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  int a = 0x55;
  a |= a<<8;
  a |= a<<16;
  return !~(a|x);
}
/* 
 * anyEvenBit - return 1 if any even-numbered bit in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples anyEvenBit(0xA) = 0, anyEvenBit(0xE) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyEvenBit(int x) {
  int a = 0x55;
  a |= a<<8;
  a |= a<<16;
  
  return !!(a&x);
}
/* 
 * anyOddBit - return 1 if any odd-numbered bit in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples anyOddBit(0x5) = 0, anyOddBit(0x7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyOddBit(int x) {
  int a = 0xaa;
  a |= a<<8;
  a |= a<<16;
    return !!(a&x);
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
  return (~((~x+1)|x)>>31)&1;//(((~x+1)^x)>>31)^0x00000001
}
	// int a = (x>>16) | x;
  // a = (a>>8) | a;
  // a = (a>>4) | a;
  // a = (a>>2) | a;
  // a = (a>>1) | a;
	// printf("%d", 0x0000001^(a&1));
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
  return ~(~x|~y);
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
    //to get mask1 0x55555555
    int tmp_mask1=(0x55)|(0x55<<8);
    int mask1=(tmp_mask1)|(tmp_mask1<<16);
    //to get mask2 0x33333333
    int tmp_mask2=(0x33)|(0x33<<8);
    int mask2=(tmp_mask2)|(tmp_mask2<<16);
    //to get mask3 0x0f0f0f0f
    int tmp_mask3=(0x0f)|(0x0f<<8);
    int mask3=(tmp_mask3)|(tmp_mask3<<16);
    //to get mask4 0x00ff00ff
    int mask4=(0xff)|(0xff<<16);
    //to get mask5 0x0000ffff
    int mask5=(0xff)|(0xff<<8);
  int count = (x&mask1) + ((x>>1)&mask1);
  count = (count&mask2) + ((count>>2)&mask2);
  count = (count&mask3) + ((count>>4)&mask3);
  count = (count&mask4) + ((count>>8)&mask4);
  count = (count&mask5) + ((count>>16)&mask5);
  return count;
}
/* 
 * bitMask - Generate a mask consisting of all 1's 
 *   lowbit and highbit
 *   Examples: bitMask(5,3) = 0x38
 *   Assume 0 <= lowbit <= 31, and 0 <= highbit <= 31
 *   If lowbit > highbit, then mask should be all 0's
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int bitMask(int highbit, int lowbit) {
  int a = ~0;

  return ((a<<lowbit)^(a<<highbit<<1))&(a<<lowbit);
}
/* 
 * bitMatch - Create mask indicating which bits in x match those in y
 *            using only ~ and & 
 *   Example: bitMatch(0x7, 0xE) = 0x6
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitMatch(int x, int y) {
  return ~((~x&y)|(x&~y));
}
/* 
 * bitNor - ~(x|y) using only ~ and & 
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitNor(int x, int y) {
  return ~x&~y;
}
/* 
 * bitOr - x|y using only ~ and & 
 *   Example: bitOr(6, 5) = 7
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitOr(int x, int y) {
  return ~(~x&~y);
}
/*
 * bitParity - returns 1 if x contains an odd number of 0's
 *   Examples: bitParity(5) = 0, bitParity(7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int bitParity(int x) {
  int a = (x>>16) ^ x;
  a = (a>>8) ^ a;
  a = (a>>4) ^ a;
  a = (a>>2) ^ a;
  a = (a>>1) ^ a;
  return a&1;
}
/*
 * bitReverse - Reverse bits in a 32-bit word
 *   Examples: bitReverse(0x80000002) = 0x40000001
 *             bitReverse(0x89ABCDEF) = 0xF7D3D591
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 45
 *   Rating: 4
 */
int bitReverse(int x) {
    //to get mask1 0x55555555
    int tmp_mask1=(0x55)|(0x55<<8);
    int mask1=(tmp_mask1)|(tmp_mask1<<16);
    //to get mask2 0x33333333
    int tmp_mask2=(0x33)|(0x33<<8);
    int mask2=(tmp_mask2)|(tmp_mask2<<16);
    //to get mask3 0x0f0f0f0f
    int tmp_mask3=(0x0f)|(0x0f<<8);
    int mask3=(tmp_mask3)|(tmp_mask3<<16);
    //to get mask4 0x00ff00ff
    int mask4=(0xff)|(0xff<<16);
    //to get mask5 0x0000ffff
    int mask5=(0xff)|(0xff<<8);

  x = ((x>>1)&mask1) | (x&mask1)<<1;
  x = ((x>>2)&mask2) | (x&mask2)<<2;
  x = ((x>>4)&mask3) | (x&mask3)<<4;
  x = ((x>>8)&mask4) | (x&mask4)<<8;
  x = ((x>>16)&mask5) | (x&mask5)<<16;

    return x;
}
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  return ~(x&y)&~(~x&~y);
}
/* 
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwap(int x, int n, int m) {
    // int n_shift =  n << 3;
	  // int m_shift =  m << 3;
    // int p = ( ( x >> m_shift ) ^ ( x >> n_shift) ) & 0xFF;
    // return x ^ ( ( p << m_shift ) | ( p  << n_shift ) );
  int a = 0x000000ff,x_a_n,x_a_m,clean_x,c, d;
	c = m<<3;
	d = n<<3;
  // int x_a_n,x_a_m,clean_x;
	// a_n = x>>n&a;
	// a_m = x>>m&a;
	x_a_n = (x>>d&a)<<c;
  x_a_m = (x>>c&a)<<d;
  clean_x = x&(~(a<<c)&~(a<<d));
  return clean_x | x_a_n | x_a_m;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  	x = ~!x + 1;
	//x += 0xffffffff;
  //x = !x>>31;
  return (x&z) | (~x&y);
}
/* 
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int copyLSB(int x) {
  return (x<<31)>>31;
}
/*
 * distinctNegation - returns 1 if x != -x.
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 5
 *   Rating: 2
 */
int distinctNegation(int x) {
  return !!((~x+1)^x);
  //!(x+x)
}
/* 
 * dividePower2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: dividePower2(15,1) = 7, dividePower2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int dividePower2(int x, int n) {
  int mask = x>>31;
    return (x+((mask&~(~0<<n)) | (~mask & 0)))>>n;
}
/* 
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int evenBits(void) {
  int mask = 0x55;
  mask = mask | 0x55<<8;
  mask = mask | mask<<16;
  return mask;
}
/*
 * ezThreeFourths - multiplies by 3/4 rounding toward 0,
 *   Should exactly duplicate effect of C expression (x*3/4),
 *   including overflow behavior.
 *   Examples: ezThreeFourths(11) = 8
 *             ezThreeFourths(-9) = -6
 *             ezThreeFourths(1073741824) = -268435456 (overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 3
 */
int ezThreeFourths(int x) {
  int result = (x<<1)+x;
  // int result = (x<<2)+(~x+1);遮这样写是错的,不清楚为什么
	int mask = result>>31&3; 
  return (result+mask)>>2;

  
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
  int m = x<<(33+~n);
  return !((m>>(33+~n))^x);
}
/* 
 * fitsShort - return 1 if x can be represented as a 
 *   16-bit, two's complement integer.
 *   Examples: fitsShort(33000) = 0, fitsShort(-32768) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int fitsShort(int x) {
  return !((x<<16>>16)^x);
}
/* 
 * floatAbsVal - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned floatAbsVal(unsigned uf) {
  int x = 0x7fffffff & uf;
	int mask = 0x7f800000;
	if (((x&mask)==mask) && mask^x)
		return uf;
	return x;
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  
	int frac_uf = uf & ((1<<23)-1);
    int exp_uf = (uf>>23) & 0xff;
    int exp = exp_uf - 127;
    int sign = uf>>31;
//    printf("%#d %#d %#d\n", frac_uf, exp, sign);
	if ( exp > 31 ){
		return 0x80000000;
	}else if(exp < 0){
		return 0;
	}
	
	int ans = frac_uf | 1<<23;
	int ans_exp = exp - 23;
	if (ans_exp < 0){
		ans = ans >> (23-exp);
	}else{
		ans = ans << ans_exp;
	} 
	if (sign == 1){
		ans = ~ans+1;
	}

  return ans;
	// int s_    = uf>>31;
  // int exp_  = ((uf&0x7f800000)>>23)-127;
  // int frac_ = (uf&0x007fffff)|0x00800000; 
  // if(!(uf&0x7fffffff)) return 0;
  
  // if(exp_ > 31) return 0x80000000;
  // if(exp_ < 0) return 0;
  
  // if(exp_ > 23) frac_ <<= (exp_-23);
  // else frac_ >>= (23-exp_);

  // if(!((frac_>>31)^s_)) return frac_;
  // // else if(frac_>>31) return 0x80000000;
  // else return ~frac_+1;

}
/* 
 * floatInt2Float - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatInt2Float(int x) {
  int sign = (x>>31)&1;
  if (x == 0){
		return 0;
	}
	if (x == 0x80000000){
		return 0xcf000000;
	}
	if (sign == 1){
		x = ~x+1;
	}
	int n = 30, exp;
	while(! (x&(1<<n))) n--;
	if (n <= 23 ){
		x <<= (23-n);
	}else{
		x +=1<<(n-24);
		if (x<<(31-(n-23-1))) ;else x &= 0xffffffff<<(n-23+1);
		if (x&(1<<(n+1))) n++;
		x >>= (n-23);
	}
		exp = 127 + n;

  return (sign<<31) | (x&0x007fffff) | exp << 23;
}
/* 
 * floatIsEqual - Compute f == g for floating point arguments f and g.
 *   Both the arguments are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   If either argument is NaN, return 0.
 *   +0 and -0 are considered equal.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 25
 *   Rating: 2
 */
int floatIsEqual(unsigned uf, unsigned ug) {
  //   unsigned m = uf & (~0>>1);
  //   unsigned n = ug & (~0>>1); 
  //   if ( !m && !n ){
  //   	return 1;
	// }
	// int exp = 0x7f800000;
	// int x = exp & ug;
	// int y = exp & uf;
	// int frac = (1<<23)-1;
	// int a = ug & frac;
	// int b = uf & frac;
	// if ( (!(x^exp) && (n ^ exp)) || (!(y^exp) && (m^exp)) ){
	// 	return 0;
	// }
	
	// return !(ug ^ uf);

  if (!(uf&0x7fffffff) && !(ug&0x7fffffff)) return 1;
  if ((uf & 0x7fffffff) > 0x7f800000) return 0;
  if ((ug & 0x7fffffff) > 0x7f800000) return 0;
  
  return ug == uf;
}
/* 
 * floatIsLess - Compute f < g for floating point arguments f and g.
 *   Both the arguments are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   If either argument is NaN, return 0.
 *   +0 and -0 are considered equal.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 3
 */
int floatIsLess(unsigned uf, unsigned ug) {
// int result = !floatIsEqual(uf, ug);
	
// 	if (result != 0){
// 		int exp = 0x7f800000;
// 		int f = uf & exp;
// 		int g = ug & exp;
// 		int frac = (1<<23)-1;
// 		int a = ug & frac;
// 		int b = uf & frac;
// 		if ( (!(f^exp) && (a^0) ) || (!(g^exp) && (b^0)) ){
// 				return 0;
// 		}
// 	}
//     return result;
//     return 2;
  int sign_uf = uf >>31 & 1;
	int sign_ug = ug >>31 & 1;
	int exp_uf = uf >> 23 & 0xff;
	int exp_ug = ug >>23 & 0xff;
	int frac_uf = uf & ((1<<23)-1);
	int frac_ug = ug & ((1<<23)-1);
	if (!(uf & 0x7fffffff) && !(ug & 0x7fffffff )) return 0;
	if ((exp_uf==0xff && frac_uf) || (exp_ug==0xff && frac_ug)) return 0;
	if (sign_uf != sign_ug) return sign_uf & 1;
	if (exp_uf ^ exp_ug) return (exp_uf < exp_ug) ^ sign_uf;
	if (frac_uf ^ frac_ug ) return (frac_uf < frac_ug) ^ sign_uf;

  return 0;
}
/* 
 * floatNegate - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned floatNegate(unsigned uf) {
  if ((uf&0x7fffffff)>0x7f800000) return uf;
 return 0x80000000 ^ uf;
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
  if (x<-127) return 0;
  if (x>128) return 0x7f800000;
  x = x + 127;
  x = x<<23;

    return x;
}
/* 
 * floatScale1d2 - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale1d2(unsigned uf) {
  
  // int sign = uf & 0x80000000;
  // int exp = uf & 0x7f800000;
  // int frac = uf & 0x007fffff;
  // if ( (uf&0x7fffffff) > exp ){
  // 	return uf;
  // }
  // if (!exp){
  // 	frac >>= 1;
  // 	return sign|exp|frac;
  // }
  // exp >>= 1;
  // return sign|exp|frac;

  int exp_uf = (uf >> 23)&0xff;
	int frac_uf = uf & ((1<<23)-1);
	int sign_uf = uf&0x80000000;
	if ((uf & 0x7fffffff) >= 0x7f800000) {
		return uf;
	}
	if (exp_uf > 1) return sign_uf | (exp_uf-1)<<23 | frac_uf;
	if ((frac_uf & 0x3) == 0x3) uf += 0x2;
	return (uf>>1)&0x007fffff | sign_uf;
}
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  int exp_uf = uf>>23 & 0xff;
	int sign_uf = uf & 0x80000000;
	if (exp_uf == 0){
		return uf << 1 | sign_uf;
	}
	if (exp_uf == 255){
		return uf;
	}
	exp_uf++;
	if(exp_uf == 255){
		return 0x7f800000 | sign_uf;
	}
	return exp_uf<<23 | sign_uf | uf & 0x007fffff;
}
/* 
 * floatScale64 - Return bit-level equivalent of expression 64*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 35
 *   Rating: 4
 */
unsigned floatScale64(unsigned uf) {
  int exp_ = (uf&0x7f800000)>>23;
  int s_ = uf&0x80000000;
  int cnt_ = 22;
  if(exp_ == 0) {
    if(!(uf&0x007e0000)) return (uf<<6)|s_;
    while(!(uf&(1<<cnt_))) cnt_--;
    uf <<= (23-cnt_);
    return s_ | (uf&0x807fffff) | ((cnt_-16)<<23);
  }
  if(exp_ == 255) return uf;
  exp_+=6;
  if(exp_ >= 255) return 0x7f800000|s_;
  return (uf&0x807fffff)|(exp_<<23);
}
/* 
 * floatUnsigned2Float - Return bit-level equivalent of expression (float) u
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatUnsigned2Float(unsigned u) {
  if (u == 0){
		return 0;
	}
	int n = 31, exp;
	while(! (u&(1<<n))) n--;
	if (n <= 23 ){
		u <<= (23-n);
	}else{
		u +=1<<(n-24);
		if (u<<(31-(n-23-1))) ;else u &= 0xffffffff<<(n-23+1);
		if (u&(1<<(n+1))) n++;
		u >>= (n-23);
	}
		exp = 127 + n;

  return (u&0x007fffff) | exp << 23;
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (least significant) to 3 (most significant)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
  return (x>>(n<<3)) & 0xff;
}
/* 
 * greatestBitPos - return a mask that marks the position of the
 *               most significant 1 bit. If x == 0, return 0
 *   Example: greatestBitPos(96) = 0x40
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 70
 *   Rating: 4 
 */
int greatestBitPos(int x) {
  x = x>>1 | x;
  x = x>>2 | x;
  x = x>>4 | x;
  x = x>>8 | x;
  x = x>>16 | x;
  x = x^(x>>1&~(1<<31));
  return x;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  
  int n = 0;
  x ^= (x<<1);
  n += ((!!(x&((~0)<<(n+16)))) << 4);
  n += ((!!(x&((~0)<<(n+8)))) << 3);
  n += ((!!(x&((~0)<<(n+4)))) << 2);
  n += ((!!(x&((~0)<<(n+2)))) << 1);
  n += (!!(x&((~0)<<(n+1))));

  return n+1;
  // int y = x>>1 | x;
  // y = y>>2 | y;
  // y = y>>4 | y;
  // y = y>>8 | y;
  // y = y>>16 | y;

  // int tmpMask1 = (0x55)|(0x55<<8);
  // int mask1 = (tmpMask1)|(tmpMask1<<16);
  // int tmpMask2 = (0x33)|(0x33<<8);
  // int mask2 = (tmpMask2)|(tmpMask2<<16);
  // int tmpMask3 = (0x0f)|(0x0f<<8);
  // int mask3 = (tmpMask3)|(tmpMask3<<16);
  // int mask4 = (0xff)|(0xff<<16);
  // int mask5 = (0xff)|(0xff<<8);     
  // int count = (y&mask1) + ((y>>1)&mask1);
  // count = (count&mask2) + ((count>>2)&mask2);
  // count = (count&mask3) + ((count>>4)&mask3);
  // count = (count&mask4) + ((count>>8)&mask4);
  // count = (count&mask5) + ((count>>16)&mask5);
  // return count;

  //  int temp=x^(x>>31);//get positive of x;
  //   int isZero=!temp;
  //   //notZeroMask is 0xffffffff
  //   int notZeroMask=(!(!temp)<<31)>>31;
  //   int bit_16,bit_8,bit_4,bit_2,bit_1;
  //   bit_16=!(!(temp>>16))<<4;
  //   //see if the high 16bits have value,if have,then we need at least 16 bits
  //   //if the highest 16 bits have value,then rightshift 16 to see the exact place of  
  //   //if not means they are all zero,right shift nothing and we should only consider the low 16 bits
  //   temp=temp>>bit_16;
  //   bit_8=!(!(temp>>8))<<3;
  //   temp=temp>>bit_8;
  //   bit_4=!(!(temp>>4))<<2;
  //   temp=temp>>bit_4;
  //   bit_2=!(!(temp>>2))<<1;
  //   temp=temp>>bit_2;
  //   bit_1=!(!(temp>>1));
  //   temp=bit_16+bit_8+bit_4+bit_2+bit_1+2;//at least we need one bit for 1 to tmax,
  //   //and we need another bit for sign
  //   return isZero|(temp&notZeroMask);
}
/* 
 * implication - return x -> y in propositional logic - 0 for false, 1
 * for true
 *   Example: implication(1,1) = 1
 *            implication(1,0) = 0
 *   Legal ops: ! ~ ^ |
 *   Max ops: 5
 *   Rating: 2
 */
int implication(int x, int y) {
    return (!x)|y;
}
/*
 * intLog2 - return floor(log base 2 of x), where x > 0
 *   Example: intLog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int intLog2(int x) {
  // int y = x>>1 | x;
  // y = y>>2 | y;
  // y = y>>4 | y;
  // y = y>>8 | y;
  // y = y>>16 | y;

  // int tmpMask1 = (0x55)|(0x55<<8);
  // int mask1 = (tmpMask1)|(tmpMask1<<16);
  // int tmpMask2 = (0x33)|(0x33<<8);
  // int mask2 = (tmpMask2)|(tmpMask2<<16);
  // int tmpMask3 = (0x0f)|(0x0f<<8);
  // int mask3 = (tmpMask3)|(tmpMask3<<16);
  // int mask4 = (0xff)|(0xff<<16);
  // int mask5 = (0xff)|(0xff<<8);     
  // int count = (y&mask1) + ((y>>1)&mask1);
  // count = (count&mask2) + ((count>>2)&mask2);
  // count = (count&mask3) + ((count>>4)&mask3);
  // count = (count&mask4) + ((count>>8)&mask4);
  // count = (count&mask5) + ((count>>16)&mask5);
  // return ~((~count+1)+1)+1;
  int n = 0;
  n += ((!!(x&((~0)<<(n+16)))) << 4);
  n += ((!!(x&((~0)<<(n+8)))) << 3);
  n += ((!!(x&((~0)<<(n+4)))) << 2);
  n += ((!!(x&((~0)<<(n+2)))) << 1);
  n += (!!(x&((~0)<<(n+1))));
  return n;
// }
}
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  int m = x+~(0x2f);
	m = m>>31;
	
	int n = 0x39+(~x+1);
	n = n>>31;

  return !(m|n);
}
/* 
 * isEqual - return 1 if x == y, and 0 otherwise 
 *   Examples: isEqual(5,5) = 1, isEqual(4,5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int isEqual(int x, int y) {
  return !(x^y);
}
/* 
 * isGreater - if x > y  then return 1, else return 0 
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {
  // int mask = x^y;
	// mask = mask | (mask>>1);
	// mask = mask | (mask>>2);
	// mask = mask | (mask>>4);
	// mask = mask | (mask>>8);
	// mask = mask | (mask>>16);
  // int a= mask;
	// mask = mask ^ (mask>>1 & ~(1<<31));
	// mask = !((x|mask) ^ x);
  // return !a & mask;

  int x1 = x>>31;
  int y1 = y>>31;
  int w = x1^y1;
  int sum = x+~y; 

  return (w&(x1+1))|(~w&((sum>>31)+1));
}
/* 
 * isLess - if x < y  then return 1, else return 0 
 *   Example: isLess(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLess(int x, int y) {
	// int mask = x^y;
	// mask = mask | (mask>>1);
	// mask = mask | (mask>>2);
	// mask = mask | (mask>>4);
	// mask = mask | (mask>>8);
	// mask = mask | (mask>>16);
	// mask = mask ^ (mask>>1 & ~(1<<31));
	// mask = (x|mask) ^ x;

  // return mask;

  int x1 = x>>31;
  int y1 = y>>31;
  int w = x1^y1;
  int sum = x + ~y + 1;

  return (w&(x1&1))|(~w&((sum>>31)&1));
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  // int mask = x^y;
	// mask = mask | (mask>>1);
	// mask = mask | (mask>>2);
	// mask = mask | (mask>>4);
	// mask = mask | (mask>>8);
	// mask = mask | (mask>>16);
	// mask = mask ^ (mask>>1 & ~(1<<31));
	// mask = (((x|mask) ^ x) | !((y|mask) ^ y));

  // return mask;

  int x1 = x>>31;
  int y1 = y>>31;
  int w = x1^y1;
  int sum = y+~x+1;

  return (w&(x1&1))|(~w&((sum>>31)+1));
}
/* 
 * isNegative - return 1 if x < 0, return 0 otherwise 
 *   Example: isNegative(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNegative(int x) {
  return !!(x>>31);
}
/* 
 * isNonNegative - return 1 if x >= 0, return 0 otherwise 
 *   Example: isNonNegative(-1) = 0.  isNonNegative(0) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNonNegative(int x) {
  return !(x>>31);
}
/* 
 * isNonZero - Check whether x is nonzero using
 *              the legal operators except !
 *   Examples: isNonZero(3) = 1, isNonZero(0) = 0
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4 
 */
int isNonZero(int x) {
  return (((~x+1)|x)>>31)&1;
}
/* 
 * isNotEqual - return 0 if x == y, and 1 otherwise 
 *   Examples: isNotEqual(5,5) = 0, isNotEqual(4,5) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNotEqual(int x, int y) {
  return !!(x^y);
}
/*
 * isPallindrome - Return 1 if bit pattern in x is equal to its mirror image
 *   Example: isPallindrome(0x01234567E6AC2480) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 45
 *   Rating: 4
 */
int isPallindrome(int x) {
	int tmpMask1 = (0x55)|(0x55<<8);
  int mask1 = (tmpMask1)|(tmpMask1<<16);
  int tmpMask2 = (0x33)|(0x33<<8);
  int mask2 = (tmpMask2)|(tmpMask2<<16);
  int tmpMask3 = (0x0f)|(0x0f<<8);
  int mask3 = (tmpMask3)|(tmpMask3<<16);
  int mask4 = (0xff)|(0xff<<16);
  int mask5 = (0xff)|(0xff<<8);

	int y = (x>>1&mask1) | (x&mask1)<<1;
	y = (y>>2&mask2) | (y&mask2)<<2;
	y = (y>>4&mask3) | (y&mask3)<<4;
	y = (y>>8&mask4) | (y&mask4)<<8;
	y = (y>>16&mask5) | (y&mask5)<<16;

  return !(y^x);
}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 2
 */
int isPositive(int x) {
  return !!x&!(x>>31);
}
/*
 * isPower2 - returns 1 if x is a power of 2, and 0 otherwise
 *   Examples: isPower2(5) = 0, isPower2(8) = 1, isPower2(0) = 0
 *   Note that no negative number is a power of 2.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int isPower2(int x) {
  
  int sign = x>>31&1;
  return !!x&!sign & !(x&(x+~0));
}
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  return !(x+1+x+1) & !!(x+1);
}
/*
 * isTmin - returns 1 if x is the minimum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmin(int x) {
  return !!x&!((~x+1)^x);
}
/*
 * isZero - returns 1 if x == 0, and 0 otherwise 
 *   Examples: isZero(5) = 0, isZero(0) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int isZero(int x) {
  return !x;
}
/* 
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2 
 */
int leastBitPos(int x) {
  return x&(~x+1);
}
/*
 * leftBitCount - returns count of number of consective 1's in
 *     left-hand (most significant) end of word.
 *   Examples: leftBitCount(-1) = 32, leftBitCount(0xFFF0F0F0) = 12
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 50
 *   Rating: 4
 */
int leftBitCount(int x) {
  int a16 = !((x>>16) + 1);
	int b16 = a16 << 4;//0x80000000出错
	int c16 = x<<b16;
	
	int a8 = !((c16>>24) + 1);
	int b8 = a8 << 3;
	int c8 = c16<<b8;
	
	int a4 = !((c8>>28) + 1);
	int b4 = a4 << 2;
	int c4 = c8<<b4;
	
	int a2 = !((c4>>30) + 1);
	int b2 = a2 << 1;
	int c2 = c4<<b2;
	
	int a1 = !((c2>>31) + 1);
	int b1 = a1;
	int c1 = c2<<b1;
  
  int a0 = !((c1>>31) + 1);
	int b0 = a0;
	int c0 = c1<<b0;

  return b1+b2+b4+b8+b16+b0;

  // int n = 0;
  // n += ((!!(x&((~0)<<(n+16)))) << 4);
  // n += ((!!(x&((~0)<<(n+8)))) << 3);
  // n += ((!!(x&((~0)<<(n+4)))) << 2);
  // n += ((!!(x&((~0)<<(n+2)))) << 1);
  // n += (!!(x&((~0)<<(n+1))));
  // return n;
}
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  

  return (~(~x+1) & ~x) >>31 & 1;
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
  return (x>>n)&~(((1<<31)>>n)<<1);
}
/* 
 * minusOne - return a value of -1 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int minusOne(void) {
  return ~0;
}
/*
 * multFiveEighths - multiplies by 5/8 rounding toward 0.
 *   Should exactly duplicate effect of C expression (x*5/8),
 *   including overflow behavior.
 *   Examples: multFiveEighths(77) = 48
 *             multFiveEighths(-22) = -13
 *             multFiveEighths(1073741824) = 13421728 (overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 3
 */
int multFiveEighths(int x) {
  int add;
  x = (x<<2) + x;
  add = 0x7&x>>31;
  return (x+add)>>3;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x+1;
}
/* 
 * oddBits - return word with all odd-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 2
 */
int oddBits(void) {
  int u = 0xAA;
  return u + (u << 8) + (u << 16) + (u << 24);
}
/* 
 * remainderPower2 -remainderPower2, for 0 <= n <= 30
 *   Negative arguments should yield negative remainders
 *   Examples: remainderPower2(15,2) = 3, remainderPower2(-35,3) = -3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int remainderPower2(int x, int n) {
  int y = (x>>31) ^ (x+(x>>31)); 
	int a = 1<<n;
	a = (a+~0)&y;
    return (x>>31) ^ (a+(x>>31));
}
/* 
 * replaceByte(x,n,c) - Replace byte n in x with c
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: replaceByte(0x12345678,1,0xab) = 0x1234ab78
 *   You can assume 0 <= n <= 3 and 0 <= c <= 255
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 3
 */
int replaceByte(int x, int n, int c) {
  n = n<<3;
  int y = 0xff<<n;
  x = (x&~y)|(c<<n);
  return x;
}
/* 
 * rotateLeft - Rotate x to the left by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateLeft(0x87654321,4) = 0x76543218
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3 
 */
int rotateLeft(int x, int n) {
  int y = x>>(32+~n+1);
	y = y & ~(~0<<n);
  return x<<n|y;
}
/* 
 * rotateRight - Rotate x to the right by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateRight(0x87654321,4) = 0x76543218
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3 
 */
int rotateRight(int x, int n) {
    int y = x>>n;
	y = y & ~(~0<<(32+~n+1));
  return x<<(32+~n+1)|y;
}
/*
 * satAdd - adds two numbers but when positive overflow occurs, returns
 *          maximum possible value, and when negative overflow occurs,
 *          it returns minimum positive value.
 *   Examples: satAdd(0x40000000,0x40000000) = 0x7fffffff
 *             satAdd(0x80000000,0xffffffff) = 0x80000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 30
 *   Rating: 4
 */
int satAdd(int x, int y) {
  int ans = x+y;
  // int overflow = ((x ^ ans)&(y^ans))>>31;
  int overflow = (~(x^y)&(x^ans))>>31;
  return (ans>>(overflow&0x1f))+ (overflow << 0x1f);
}
/*
 * satMul2 - multiplies by 2, saturating to Tmin or Tmax if overflow
 *   Examples: satMul2(0x30000000) = 0x60000000
 *             satMul2(0x40000000) = 0x7FFFFFFF (saturate to TMax)
 *             satMul2(0x80000001) = 0x80000000 (saturate to TMin)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int satMul2(int x) {
  int y=x;
  int ans = x+y;
  int overflow = ((x ^ ans)&(y^ans))>>31;
  return (ans>>(overflow&0x1f))+ (overflow << 0x1f);
}
/*
 * satMul3 - multiplies by 3, saturating to Tmin or Tmax if overflow
 *  Examples: satMul3(0x10000000) = 0x30000000
 *            satMul3(0x30000000) = 0x7FFFFFFF (Saturate to TMax)
 *            satMul3(0x70000000) = 0x7FFFFFFF (Saturate to TMax)
 *            satMul3(0xD0000000) = 0x80000000 (Saturate to TMin)
 *            satMul3(0xA0000000) = 0x80000000 (Saturate to TMin)
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 3
 */
int satMul3(int x) {
    int sigx = (x>>31 & 1);
    int suma = x + x;
    int siga = (suma>>31 & 1);
    int sumb = suma + x;
    int sigb = (sumb>>31 & 1);
    int sigbad = ((((sigx ^ siga) | (sigx ^ sigb)) << 31) >> 31);
    int min_int = 1 << 31;
    sigx = (sigx << 31) >> 31;
    return (sumb & ~sigbad) | (sigbad & ((~sigx & (~min_int))|(sigx & min_int)));
}
/* 
 * sign - return 1 if positive, 0 if zero, and -1 if negative
 *  Examples: sign(130) = 1
 *            sign(-23) = -1
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 2
 */
int sign(int x) {
    int sig = x>>31;
	  sig = sig + ((~sig)&(!!x)); 
    return sig;
}
/* 
 * signMag2TwosComp - Convert from sign-magnitude to two's complement
 *   where the MSB is the sign bit
 *   Example: signMag2TwosComp(0x80000005) = -5.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 4
 */
int signMag2TwosComp(int x) {
  int sig = x>>31;
	x = x & ~(1<<31);
  return sig ^ (x+sig);
}
/* 
 * specialBits - return bit pattern 0xffca3fff
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 3
 *   Rating: 1
 */
int specialBits(void) {
  int x = 0xD7 << 14;
  return ~x;
}
/* 
 * subtractionOK - Determine if can compute x-y without overflow
 *   Example: subtractionOK(0x80000000,0x80000000) = 1,
 *            subtractionOK(0x80000000,0x70000000) = 0, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int subtractionOK(int x, int y) {
  int s = x + (~y + 1);

  int xy = x ^ y;
  int xs = x ^ s;

  return !(((xy & xs) >> 31) & 0x1);
}
/* 
 * thirdBits - return word with every third bit (starting from the LSB) set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int thirdBits(void) {
  int r = 0x49 | (0x49 << 9);
  r |= r << 18;
  return r;
}
/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {
  return ~(1<<31);
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return 1<<31;
}
/*
 * trueFiveEighths - multiplies by 5/8 rounding toward 0,
 *  avoiding errors due to overflow
 *  Examples: trueFiveEighths(11) = 6
 *            trueFiveEighths(-9) = -5
 *            trueFiveEighths(0x30000000) = 0x1E000000 (no overflow)
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 4
 */
int trueFiveEighths(int x)
{
  int y = x & 0x7;
	x = x >> 3;
	return ( x<< 2 )+ x + (( (y<<2) + y + ( (x >> 0x1F) & 0x7 )) >> 3 );
}
/*
 * trueThreeFourths - multiplies by 3/4 rounding toward 0,
 *   avoiding errors due to overflow
 *   Examples: trueThreeFourths(11) = 8
 *             trueThreeFourths(-9) = -6
 *             trueThreeFourths(1073741824) = 805306368 (no overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int trueThreeFourths(int x)
{
  // int add, sym;
  // sym = x>>31;
  // x = (x<<2) + (~x+1);
  // add = 3&sym;
  // return (x+add)>>2;

  int y = x & 0x3;
	x = x >> 2;
	return ( x<< 1 )+ x + ( ( y + y + y + ( (x >> 0x1F) & 0x3 )) >> 2 );
}
/* 
 * twosComp2SignMag - Convert from two's complement to sign-magnitude 
 *   where the MSB is the sign bit
 *   You can assume that x > TMin
 *   Example: twosComp2SignMag(-5) = 0x80000005.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 4
 */
int twosComp2SignMag(int x) {
  int sig = x>>31;
	x = x & ~(1<<31);
  return sig ^ (x+sig);
}
/* 
 * upperBits - pads n upper bits with 1's
 *  You may assume 0 <= n <= 32
 *  Example: upperBits(4) = 0xF0000000
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 1
 */
int upperBits(int n) {
  int x = !!n<<31;
  return x>>(n+~0);
}
