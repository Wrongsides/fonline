#include "./test_group.hpp"

namespace c4 {
namespace yml {

#define NESTED_SEQX4_CASES \
    "nested seq x4, explicit", \
    "nested seq x4"


CASE_GROUP(NESTED_SEQX4)
{
    APPEND_CASES(

C("nested seq x4, explicit",
R"([
[[[0000, 0001, 0002], [0010, 0011, 0012], [0020, 0021, 0022]],
 [[0100, 0101, 0102], [0110, 0111, 0112], [0120, 0121, 0122]],
 [[0200, 0201, 0202], [0210, 0211, 0212], [0220, 0221, 0222]]],

[[[1000, 1001, 1002], [1010, 1011, 1012], [1020, 1021, 1022]],
 [[1100, 1101, 1102], [1110, 1111, 1112], [1120, 1121, 1122]],
 [[1200, 1201, 1202], [1210, 1211, 1212], [1220, 1221, 1222]]],

[[[2000, 2001, 2002], [2010, 2011, 2012], [2020, 2021, 2022]],
 [[2100, 2101, 2102], [2110, 2111, 2112], [2120, 2121, 2122]],
 [[2200, 2201, 2202], [2210, 2211, 2212], [2220, 2221, 2222]]],
])",
    L{
      N{L{N{L{N{L{N{"0000"}, N{"0001"}, N{"0002"}}}, N{L{N{"0010"}, N{"0011"}, N{"0012"}}}, N{L{N{"0020"}, N{"0021"}, N{"0022"}}}}}, N{L{N{L{N{"0100"}, N{"0101"}, N{"0102"}}}, N{L{N{"0110"}, N{"0111"}, N{"0112"}}}, N{L{N{"0120"}, N{"0121"}, N{"0122"}}}}}, N{L{N{L{N{"0200"}, N{"0201"}, N{"0202"}}}, N{L{N{"0210"}, N{"0211"}, N{"0212"}}}, N{L{N{"0220"}, N{"0221"}, N{"0222"}}}}}}},
      N{L{N{L{N{L{N{"1000"}, N{"1001"}, N{"1002"}}}, N{L{N{"1010"}, N{"1011"}, N{"1012"}}}, N{L{N{"1020"}, N{"1021"}, N{"1022"}}}}}, N{L{N{L{N{"1100"}, N{"1101"}, N{"1102"}}}, N{L{N{"1110"}, N{"1111"}, N{"1112"}}}, N{L{N{"1120"}, N{"1121"}, N{"1122"}}}}}, N{L{N{L{N{"1200"}, N{"1201"}, N{"1202"}}}, N{L{N{"1210"}, N{"1211"}, N{"1212"}}}, N{L{N{"1220"}, N{"1221"}, N{"1222"}}}}}}},
      N{L{N{L{N{L{N{"2000"}, N{"2001"}, N{"2002"}}}, N{L{N{"2010"}, N{"2011"}, N{"2012"}}}, N{L{N{"2020"}, N{"2021"}, N{"2022"}}}}}, N{L{N{L{N{"2100"}, N{"2101"}, N{"2102"}}}, N{L{N{"2110"}, N{"2111"}, N{"2112"}}}, N{L{N{"2120"}, N{"2121"}, N{"2122"}}}}}, N{L{N{L{N{"2200"}, N{"2201"}, N{"2202"}}}, N{L{N{"2210"}, N{"2211"}, N{"2212"}}}, N{L{N{"2220"}, N{"2221"}, N{"2222"}}}}}}},
          }
),

C("nested seq x4",
R"(
- - - - 0000
      - 0001
      - 0002
    - - 0010
      - 0011
      - 0012
    - - 0020
      - 0021
      - 0022
  - - - 0100
      - 0101
      - 0102
    - - 0110
      - 0111
      - 0112
    - - 0120
      - 0121
      - 0122
  - - - 0200
      - 0201
      - 0202
    - - 0210
      - 0211
      - 0212
    - - 0220
      - 0221
      - 0222
- - - - 1000
      - 1001
      - 1002
    - - 1010
      - 1011
      - 1012
    - - 1020
      - 1021
      - 1022
  - - - 1100
      - 1101
      - 1102
    - - 1110
      - 1111
      - 1112
    - - 1120
      - 1121
      - 1122
  - - - 1200
      - 1201
      - 1202
    - - 1210
      - 1211
      - 1212
    - - 1220
      - 1221
      - 1222
- - - - 2000
      - 2001
      - 2002
    - - 2010
      - 2011
      - 2012
    - - 2020
      - 2021
      - 2022
  - - - 2100
      - 2101
      - 2102
    - - 2110
      - 2111
      - 2112
    - - 2120
      - 2121
      - 2122
  - - - 2200
      - 2201
      - 2202
    - - 2210
      - 2211
      - 2212
    - - 2220
      - 2221
      - 2222
)",
    L{
      N{L{N{L{N{L{N{"0000"}, N{"0001"}, N{"0002"}}}, N{L{N{"0010"}, N{"0011"}, N{"0012"}}}, N{L{N{"0020"}, N{"0021"}, N{"0022"}}}}}, N{L{N{L{N{"0100"}, N{"0101"}, N{"0102"}}}, N{L{N{"0110"}, N{"0111"}, N{"0112"}}}, N{L{N{"0120"}, N{"0121"}, N{"0122"}}}}}, N{L{N{L{N{"0200"}, N{"0201"}, N{"0202"}}}, N{L{N{"0210"}, N{"0211"}, N{"0212"}}}, N{L{N{"0220"}, N{"0221"}, N{"0222"}}}}}}},
      N{L{N{L{N{L{N{"1000"}, N{"1001"}, N{"1002"}}}, N{L{N{"1010"}, N{"1011"}, N{"1012"}}}, N{L{N{"1020"}, N{"1021"}, N{"1022"}}}}}, N{L{N{L{N{"1100"}, N{"1101"}, N{"1102"}}}, N{L{N{"1110"}, N{"1111"}, N{"1112"}}}, N{L{N{"1120"}, N{"1121"}, N{"1122"}}}}}, N{L{N{L{N{"1200"}, N{"1201"}, N{"1202"}}}, N{L{N{"1210"}, N{"1211"}, N{"1212"}}}, N{L{N{"1220"}, N{"1221"}, N{"1222"}}}}}}},
      N{L{N{L{N{L{N{"2000"}, N{"2001"}, N{"2002"}}}, N{L{N{"2010"}, N{"2011"}, N{"2012"}}}, N{L{N{"2020"}, N{"2021"}, N{"2022"}}}}}, N{L{N{L{N{"2100"}, N{"2101"}, N{"2102"}}}, N{L{N{"2110"}, N{"2111"}, N{"2112"}}}, N{L{N{"2120"}, N{"2121"}, N{"2122"}}}}}, N{L{N{L{N{"2200"}, N{"2201"}, N{"2202"}}}, N{L{N{"2210"}, N{"2211"}, N{"2212"}}}, N{L{N{"2220"}, N{"2221"}, N{"2222"}}}}}}},
          }
),
    )
}

INSTANTIATE_GROUP(NESTED_SEQX4);

} // namespace yml
} // namespace c4
