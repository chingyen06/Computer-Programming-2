#include <cstdlib>
#include <gtest/gtest.h>
#include "type.h"

TEST( multest , HandleNonZeroInput ) {
	EXPECT_STREQ("rate - Identifier\nR2D2 - Identifier\n-22 - Negative Integer\n555666 - Positive Integer\n0.23 - Positive Floating\n-1.2 - Negative Floating\n5a - Error\n", mul("rate R2D2 -22 555666 0.23 -1.2 5a #"));
    EXPECT_STREQ("0.123 - Positive Floating\n0.1 - Positive Floating\n1.123 - Positive Floating\n3.2 - Positive Floating\n15.123 - Positive Floating\n33.2 - Positive Floating\n", mul("0.123 0.1 1.123 3.2 15.123 33.2 #"));
    EXPECT_STREQ("-0.456 - Error\n-0.2 - Error\n-1.456 - Negative Floating\n-7.4 - Negative Floating\n-7.43 - Negative Floating\n-783.17 - Negative Floating\n-783.176 - Negative Floating\n-389.5 - Negative Floating\n-38.5 - Negative Floating\n-123.456 - Negative Floating\n-0.123 - Error\n-9.876 - Negative Floating\n", mul("-0.456 -0.2 -1.456 -7.4 -7.43 -783.17 -783.176 -389.5 -38.5 -123.456 -0.123 -9.876 #"));
    EXPECT_STREQ("0 - Positive Integer\n1 - Positive Integer\n17 - Positive Integer\n845 - Positive Integer\n123 - Positive Integer\n4567 - Positive Integer\n", mul("0 1 17 845 123 4567 #"));
	EXPECT_STREQ("-297 - Negative Integer\n-6 - Negative Integer\n-92 - Negative Integer\n-3495 - Negative Integer\n-99999 - Negative Integer\n-1 - Negative Integer\n-17 - Negative Integer\n-845 - Negative Integer\n-123 - Negative Integer\n-4567 - Negative Integer\n", mul("-297 -6 -92 -3495 -99999 -1 -17 -845 -123 -4567 #"));
	EXPECT_STREQ("_ewe2 - Identifier\nAweDds3 - Identifier\naSDFE_ - Identifier\naS87E_ - Identifier\n___ - Identifier\n__abc - Identifier\na_ - Identifier\nAT - Identifier\nAa - Identifier\nA2 - Identifier\nb3 - Identifier\nbb - Identifier\nbU - Identifier\n_9 - Identifier\n_ - Identifier\nC - Identifier\nz - Identifier\na - Identifier\n_a - Identifier\nz9 - Identifier\na_b - Identifier\nA_ - Identifier\n", mul("_ewe2 AweDds3 aSDFE_ aS87E_ ___ __abc a_ AT Aa A2 b3 bb bU _9 _ C z a _a z9 a_b A_ #"));
	EXPECT_STREQ("342Abs - Error\n@dsikw - Error\n2342. - Error\n.34we - Error\n0.3we - Error\n@ - Error\n- - Error\nA@ - Error\ni@ - Error\n_@ - Error\n@_ - Error\n9abc - Error\n-0001 - Error\n. - Error\n-. - Error\n0. - Error\n0..1 - Error\n[ - Error\n~ - Error\nA! - Error\nb; - Error\nA] - Error\nb~ - Error\n-a - Error\n12.3.4 - Error\n-1..23 - Error\n", mul("342Abs @dsikw 2342. .34we 0.3we @ - A@ i@ _@ @_ 9abc -0001 . -. 0. 0..1 [ ~ A! b; A] b~ -a 12.3.4 -1..23 #"));
}

int main( int argc , char **argv ){
    testing :: InitGoogleTest( &argc , argv ) ;
    return RUN_ALL_TESTS( ) ;
}
