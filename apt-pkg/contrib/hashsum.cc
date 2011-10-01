// Cryptographic API Base

#include <unistd.h>
#include "hashsum_template.h"

// Summation::AddFD - Add content of file into the checksum		/*{{{*/
// ---------------------------------------------------------------------
/* */
bool SummationImplementation::AddFD(int const Fd, unsigned long Size) {
   unsigned char Buf[64 * 64];
   int Res = 0;
   int ToEOF = (Size == 0);
   while (Size != 0 || ToEOF)
   {
      unsigned n = sizeof(Buf);
      if (!ToEOF) n = min(Size,(unsigned long)n);
      Res = read(Fd, Buf, n);
      if (Res < 0 || (!ToEOF && (unsigned) Res != n)) // error, or short read
	 return false;
      if (ToEOF && Res == 0) // EOF
	 break;
      Size -= Res;
      Add(Buf,Res);
   }
   return true;
}
									/*}}}*/
