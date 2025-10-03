//Note : Computer stores negative numbers in 2’s complement form.
//Then how is negative number restored from its 2’s complement form? Solution: Take 2’s complement again.

AND (&) : all true -> true
          1 false -> false

OR  (|) : all false -> false
          1 true -> true

XOR (^) : odd number of 1s -> true
          even number of 1s -> false

NOT (~) : step 1) inverts bits
          step 2) check if negative number : convert to 2's complement form otherwise stop


Left Shift (<<) : shifts bits to left, fills with 0s on right
                    multiplies number by 2 for each shift

                 : num << k = num *(2^k)

Right Shift (>>) : shifts bits to right, fills with 0s on left for unsigned numbers
                    fills with sign bit (0 for positive, 1 for negative) for signed numbers
                    divides number by 2 for each shift

                    : num >> k = num /(2^k)

Range of int : (-2^31 to 2^31 - 1)
Range of unsigned int : (0 to 2^32 - 1)
Range of long long : (-2^63 to 2^63 - 1)
Range of unsigned long long : (0 to 2^64 - 1)
Range of char : (-128 to 127) or (0 to 255) if unsigned
Range of short : (-2^15 to 2^15 - 1) or (0 to 2^16 - 1) if unsigned
Range of long : same as long long
Range of float : (-2^128 to 2^128) (approx)
Range of double : (-2^1024 to 2^1024) (approx)
Range of long double : (-2^16384 to 2^16384) (approx)
Range of bool : (0 to 1)
