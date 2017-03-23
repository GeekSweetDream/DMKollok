
#include <stdlib.h>
#include <stdio.h>
#include "numbQ.h"

/*

INT_Q_B

‘ÛÌÍˆËˇ ÔÓ‚ÂˇÂÚ Ì‡ˆÂÎÓÂ,ÂÒÎË ‡ˆËÓÌ‡Î¸ÌÓÂ ˜ËÒÎÓ ˆÂÎÓÂ, ÚÓ "ƒ‡", ËÌ‡˜Â "ÕÂÚ".

œ‡‡ÏÂÚ˚:
1) q - ˜ËÒÎÓ

‘ÛÌÍˆËˇ ‚ÓÁ‚‡˘‡ÂÚ ÂÁÛÎ¸Ú‡Ú ÚËÔ‡ - char

*/

int INT_Q_B(NUMBQ q)
    {
        int answer = 0 ;
        if (q.b.A && q.a.A)
            answer = q.b.A == 1
        else
            {
                printf("Œ¯Ë·Í‡! ¬˚ ÌÂ ‚‚ÂÎË ˜ËÒÎÓ");
                answer = -1;
            }
        return answer;
    }
