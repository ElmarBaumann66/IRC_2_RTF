
#include <vcl.h>
#include <System.Classes.hpp>

#pragma hdrstop
#include "Unit1.h"
#include "Unit8.h"

// PrepareClass 2 mainly a Wrapper

#pragma package(smart_init)


UnicodeString __fastcall TColorRemover::FormatContent(UnicodeString Source)
{
 int pos; //a
 UnicodeString FInput;
 FInput = Source;

 do
 {
  if(FInput.Pos("\003"))
  {
   int Mode,pMode,rMode;
   UnicodeString Check,OneDig,TwoDig,ThreeDig,FourDig,CommaTry,ACommaTry;

   pos = FInput.Pos("\003");

   Mode = 0;
   pMode = 0;
   rMode = 0;

   //Check 6 possible Formats x3 - x30 - x300 - x30,0 - x300,0 - x30,00 - x300,00
   //                   Mode: 0  - 1   - 2    - 3     - 4      - 5      - 6

   //get the maximal Format
   Check = FInput.SubString(pos+1,5);

   if(Check.Pos(",") > 0)
   {
	//Check if there is One or Two Digits before Comma
	int t;

	CommaTry = Check.SubString(1,Check.Pos(",")-1);
	ACommaTry = Check.SubString(Check.Pos(",")+1,2);

	OneDig   = CommaTry.SubString(1,1);
	TwoDig   = CommaTry.SubString(1,2);
	ThreeDig = ACommaTry.SubString(1,1);
	FourDig  = ACommaTry.SubString(1,2);

	if(CommaTry.Length() == 0)
	{
	 pMode = 0;
	}

	if(CommaTry.Length() == 1)
	{
	 pMode = 1;
	}

	if(CommaTry.Length() == 2)
	{
	 pMode = 2;
	}

	if(CommaTry.Length() > 2)
	{
	 pMode = 0;
	}
	//
	//
	if(ACommaTry.Length() == 0)
	{
	 rMode = 0;
	}

	if(ACommaTry.Length() == 1)
	{
	 rMode = 1;
	}

	if(ACommaTry.Length() == 2)
	{
	 try
	 {
	  rMode = 2;
	  t = FourDig.ToInt();
	 }
	 catch(Exception &exception)
	 {
	  try
	  {
	   rMode = 1;
	   t = ThreeDig.ToInt();
	   //One Digit after x3
	  }
	  catch(Exception &exception)
	  {
	   rMode = 0;
	   //NoColor - no Digit after x3
	  }
	 }
	}

	if(pMode == 2 && rMode == 2)
	{
	 Mode = 6;
	 FInput.Delete(pos,6);
	}

	if(pMode == 2 && rMode == 1)
	{
	 Mode = 4;
	 FInput.Delete(pos,5);
	}

	if(pMode == 1 && rMode == 2)
	{
	 Mode = 5;
	 FInput.Delete(pos,5);
	}

	if(pMode == 1 && rMode == 1)
	{
	 Mode = 3;
	 FInput.Delete(pos,4);
	}

	if(pMode == 0 || rMode == 0)
	{
	 //Mode = 0;
	 FInput.Delete(pos,1);
	}
   }
   else
   {
	int t;

	OneDig = Check.SubString(1,1);
	TwoDig = Check.SubString(1,2);

	try
	{
	 Mode = 2;
	 t = TwoDig.ToInt();
	 //TwoDigits after x3
	}
	catch(Exception &exception)
	{
	 try
	 {
	  Mode = 1;
	  t = OneDig.ToInt();
	  //One Digit after x3
	 }
	 catch(Exception &exception)
	 {
	  Mode = 0;
	  //NoColor - no Digit after x3
	 }
	}

	if(Mode == 0)
	{
	 FInput.Delete(pos,1);
	}

	if(Mode == 1)
	{
	 FInput.Delete(pos,2);
	}

	if(Mode == 2)
	{
	 FInput.Delete(pos,3);
	}
   }
  }

 }
 while(FInput.Pos("\003") > NULL);


 // Remove Format Chars
 do
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\x0F") > NULL)
  {
   pos = FInput.Pos("\x0F");
   FInput.Delete(pos, 1);
  }
 }
 while(FInput.Pos("\x0F") > NULL);

 do
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\x1D") > NULL)
  {
   pos = FInput.Pos("\x1D");
   FInput.Delete(pos, 1);
  }
 }
 while(FInput.Pos("\x1D") > NULL);

 do
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\x1E") > NULL)
  {
   pos = FInput.Pos("\x1E");
   FInput.Delete(pos, 1);
  }
 }
 while(FInput.Pos("\x1E") > NULL);

 do
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\x1F") > NULL)
  {
   pos = FInput.Pos("\x1F");
   FInput.Delete(pos, 1);
  }
 }
 while(FInput.Pos("\x1F") > NULL);

 do
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\x2") > NULL)
  {
   pos = FInput.Pos("\x2");
   FInput.Delete(pos, 1);
  }
 }
 while(FInput.Pos("\x2") > NULL);


 do
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\011") > NULL) // esc \11 removed
  {
   pos = FInput.Pos("\011");
   FInput.Delete(pos, 1);
  }
 }
 while(FInput.Pos("\011") > NULL);

 do
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\016") > NULL) // esc \16 removed
  {
   pos = FInput.Pos("\016");
   FInput.Delete(pos, 1);
  }
 }
 while(FInput.Pos("\016") > NULL);

 do
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\017") > NULL) // esc \17 removed
  {
   pos = FInput.Pos("\017");
   FInput.Delete(pos, 1);
  }
 }
 while(FInput.Pos("\017") > NULL);

 do
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\n") > NULL) // esc \17 removed
  {
   pos = FInput.Pos("\n");
   FInput.Delete(pos, 1);
  }
 }
 while(FInput.Pos("\n") > NULL);

 return FInput;
}


UnicodeString __fastcall TColorRemover::RemoveEscapes(UnicodeString Source)
{
 int pos; //a
 UnicodeString FInput;
 FInput = Source;

 do
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\x2") > NULL)
  {
   pos = FInput.Pos("\x2");
   FInput.Delete(pos, 1);
  }
 }
 while(FInput.Pos("\x2") > NULL);

 do
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\x3") > NULL)
  {
   pos = FInput.Pos("\x3");
   FInput.Delete(pos, 1);
  }
 }
 while(FInput.Pos("\x3") > NULL);

 do
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\x0F") > NULL)
  {
   pos = FInput.Pos("\x0F");
   FInput.Delete(pos, 1);
  }
 }
 while(FInput.Pos("\x0F") > NULL);

 do
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\x1F") > NULL)
  {
   pos = FInput.Pos("\x1F");
   FInput.Delete(pos, 1);
  }
 }
 while(FInput.Pos("\x1F") > NULL);

 do
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\x1D") > NULL)
  {
   pos = FInput.Pos("\x1D");
   FInput.Delete(pos, 1);
  }
 }
 while(FInput.Pos("\x1D") > NULL);


 do
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\x1E") > NULL)
  {
   pos = FInput.Pos("\x1E");
   FInput.Delete(pos, 1);
  }
 }
 while(FInput.Pos("\x1E") > NULL);

 do
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\011") > NULL)
  {
   pos = FInput.Pos("\011");
   FInput.Delete(pos, 1);
  }
 }
 while(FInput.Pos("\011") > NULL);


 do
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\016") > NULL)
  {
   pos = FInput.Pos("\016");
   FInput.Delete(pos, 1);
  }
 }
 while(FInput.Pos("\016") > NULL);


 do
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\017") > NULL)
  {
   pos = FInput.Pos("\017");
   FInput.Delete(pos, 1);
  }
 }
 while(FInput.Pos("\017") > NULL);

 do
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\n") > NULL)
  {
   pos = FInput.Pos("\n");
   FInput.Delete(pos, 1);
  }
 }
 while(FInput.Pos("\n") > NULL);

 do //remove  Unicodes (Decimal 12) that produce a new line
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\x0C") > NULL)
  {
   pos = FInput.Pos("\x0C");
   FInput.Delete(pos, 1);
  }
 }
 while(FInput.Pos("\x0C") > NULL);

 return FInput;
}


UnicodeString __fastcall TColorRemover::WrapText(UnicodeString Source)
{
 int pos;
 UnicodeString FInput;
 FInput = Source;

 do
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\n") > NULL)
  {
   pos = FInput.Pos("\n");
   FInput.Delete(pos, 1);
  }
 }
 while(FInput.Pos("\n") > NULL);


 do //remove (Decimal 13) that produce a carriage return
 {
  //Application->ProcessMessages();
                       //:D︍︍︍a︍︍︍t︍︍︍i︍n︍︍︍g︍︍︍-C︍︍h︍︍a︍t︍︍r︍︍au︍︍m
  if(FInput.Pos("\uFE0D") > NULL)
  {
   pos = FInput.Pos("\uFE0D");
   FInput.Delete(pos, 1);
  }
 }
 while(FInput.Pos("\uFE0D") > NULL);      //U+FE0D

 /*
 do //remove (Decimal 13) that produce a carriage return
 {
  //Application->ProcessMessages();
                       //:D︍︍︍a︍︍︍t︍︍︍i︍n︍︍︍g︍︍︍-C︍︍h︍︍a︍t︍︍r︍︍au︍︍m
  if(FInput.Pos("︍") > NULL)
  {
   pos = FInput.Pos("︍");
   FInput.Delete(pos, 1);
  }
 }
 while(FInput.Pos("︍") > NULL);
 */

 do //remove  Unicodes (Decimal 12) that produce a new line
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\x0C") > NULL)
  {
   pos = FInput.Pos("\x0C");
   FInput.Delete(pos, 1);
  }
 }
 while(FInput.Pos("\x0C") > NULL);

 return FInput;
}

UnicodeString __fastcall TColorRemover::ReplaceAlphabet(UnicodeString Source,int Mode)
{

 return Source;
}
