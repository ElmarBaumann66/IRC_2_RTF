#include <IdSync.hpp>
#include "Unit1.h"

#include "Unit7.h"
#include "Unit8.h"

#include <System.StrUtils.hpp>
#include <System.Notification.hpp>
#include <mmsystem.h>

// This is Code from BSIRC Original using Indy10 to synchronize some Functions
// while a Network-Connection is given - this is not needed here but Ok!

class TMemoLog : public TIdSync
{
  private:
	UnicodeString FStr;

  public:

	__fastcall TMemoLog(const UnicodeString &AStr):TIdSync()
	  {
	   FStr = AStr;
	  }

	  virtual void __fastcall DoSynchronize()
	  {
	   Form1->ResultMemo->Lines->Add(FStr);
	  }

	  static void __fastcall Add(const UnicodeString &AStr)
	  {
	   TMemoLog *Sync = new TMemoLog(AStr);

	   try
	   {
		Sync->Synchronize();
	   }
	   __finally
	   {
		delete Sync;
	   }
 }
};

class TRTFLine : public TIdSync
{
  private:
	UnicodeString Line;
	TColorParser *Cp;              // incoming Messages ColorParser
	unsigned __int64 offset;       //changed from   int offset 10.02.2019

  public:

	__fastcall TRTFLine(const UnicodeString &Str):TIdSync()
	  {
	   Line = Str;
	  }

	  virtual void __fastcall DoSynchronize()
	  {
	   int a, start, next, count, pos, diff, pt, len;
	   UnicodeString Dummy, Start, Next, Col, Mirrors, Buff;
	   bool NoStyle, bold, underline, italic, strikeout;

	   offset = 0;

	   try
	   {
		Dummy =  Cp->PrepareLine(Line);      // Pass1
		Form1->ResultMemo->Lines->Add("Pass1: "+Dummy);

		Dummy = Cp->RemoveBackColors(Dummy); // Pass2
		Form1->ResultMemo->Lines->Add("Pass2: "+Dummy);

		Dummy = Cp->PrepareLine_(Dummy);     // Pass3
		Form1->ResultMemo->Lines->Add("Pass3: "+Dummy);

		Form1->ResultMemo->Lines->Add(" ");
		Form1->ResultMemo->Lines->Add("Color & Style Scan:");
		Form1->ResultMemo->Lines->Add(" ");

		bold = false;
		underline = false;
		italic = false;
		strikeout = false;
		NoStyle = false;

		Form1->str->BeginUpdate();
		Form1->str->Clear();
		Form1->str->EndUpdate();

		Form1->TestRTF->ClearSelection();
		len = Dummy.Length();

		//Prepare the Color Section
		for(a = 1; a < Dummy.Length(); a++)
		{
		 Application->ProcessMessages();

		 // Prepare the Style Section
		 if(Dummy.SubString(a, 1) == "\x0F")
		 {
		  //Terminate Styles & Color
		  if(a == 0)
		  {
		   if(Dummy.SubString(2,1) == "\x03" || Dummy.SubString(2,1) == "\x1F" ||
			  Dummy.SubString(2,1) == "\x1D" || Dummy.SubString(2,1) == "\x1E" ||
			  Dummy.SubString(2,1) == "\x02")
		   {
			int len1,len2;

			//check if deleted
			len1 = Dummy.Length();
			Dummy.Delete(a, 1);
			len2 = Dummy.Length();

			if(len1 == len2) //nothing was deleted
			{
			 Dummy.Delete(1,1);
			}
		   }
		   else
		   {
			Dummy.Delete(1,1);
		   }

		   Form1->UpdateFormatList(a,1);

		   if(Dummy.Pos("\x0F") > 0)
		   {
			Form1->str->Add("1 clTerminate "+UnicodeString(Dummy.Pos("\x0F")));
		   }
		   else
		   {
			Form1->str->Add("1 clTerminate 00");
		   }
		  }
		  else
		  {
		   Dummy.Delete(a,1);                   //
		   Form1->UpdateFormatList(a,1);

		   if(Dummy.Pos("\x0F") > 0)
		   {
			Form1->str->Add(UnicodeString(a)+" clTerminate "+UnicodeString(Dummy.Pos("\x0F")));
		   }
		   else
		   {
			Form1->str->Add(UnicodeString(a)+" clTerminate 00");
		   }

		   a = a - 1;
		  }
		 }

		 if(Dummy.SubString(a, 1) == "\x02")
		 {
		  // bold
		  if(a == 0)
		  {
		   if(Dummy.SubString(2,1) == "\x03" || Dummy.SubString(2,1) == "\x1F" ||
			  Dummy.SubString(2,1) == "\x1D" || Dummy.SubString(2,1) == "\x1E" ||
			  Dummy.SubString(2,1) == "\x0F")
		   {
			int len1,len2;

			//check if deleted
			len1 = Dummy.Length();
			Dummy.Delete(a, 1);
			len2 = Dummy.Length();

			if(len1 == len2) //nothing was deleted
			{
			 Dummy.Delete(1,1);
			}
		   }
		   else
		   {
			Dummy.Delete(1,1);
		   }

		   Form1->UpdateFormatList(a, 1);

		   if(Dummy.Pos("\x02") > 0)
		   {
			Form1->str->Add("1 bold "+IntToStr(Dummy.Pos("\x02")));
		   }
		   else
		   {
			Form1->str->Add("1 bold 00");
		   }
		  }
		  else
		  {
		   Dummy.Delete(a, 1);
		   Form1->UpdateFormatList(a, 1);

		   if(Dummy.Pos("\x02") > 0)
		   {
			Form1->str->Add(UnicodeString(a)+" bold "+IntToStr(Dummy.Pos("\x02")));
		   }
		   else
		   {
			Form1->str->Add(UnicodeString(a)+" bold 00");
		   }

		   a = a - 1;
		  }
		 }

		 if(Dummy.SubString(a, 1) == "\x1F")
		 {
		  //Underlined
		  if(a == 0)
		  {
		   if(Dummy.SubString(2,1) == "\x03" || Dummy.SubString(2,1) == "\x02" ||
			  Dummy.SubString(2,1) == "\x1D" || Dummy.SubString(2,1) == "\x1E" ||
			  Dummy.SubString(2,1) == "\x0F")
		   {
			int len1,len2;

			//check if deleted
			len1 = Dummy.Length();
			Dummy.Delete(a, 1);
			len2 = Dummy.Length();

			if(len1 == len2) //nothing was deleted
			{
			 Dummy.Delete(1,1);
			}
		   }
		   else
		   {
			Dummy.Delete(1,1);
		   }

		   Form1->UpdateFormatList(a,1);

		   if(Dummy.Pos("\x1F") > 0)
		   {
			Form1->str->Add("1 clUnderline "+UnicodeString(Dummy.Pos("\x1F")));
		   }
		   else
		   {
			Form1->str->Add("1 clUnderline 00");
		   }
		  }
		  else
		  {
		   Dummy.Delete(a,1);
		   Form1->UpdateFormatList(a,1);

		   if(Dummy.Pos("\x1F") > 0)
		   {
			Form1->str->Add(UnicodeString(a)+" clUnderline "+UnicodeString(Dummy.Pos("\x1F")));
		   }
		   else
		   {
			Form1->str->Add(UnicodeString(a)+" clUnderline 00");
		   }

		   a = a - 1;
		  }
		 }

		 if(Dummy.SubString(a, 1) == "\x1E")
		 {
		  //Strikeout
		  if(a == 0)
		  {
		   if(Dummy.SubString(2,1) == "\x03" || Dummy.SubString(2,1) == "\x02" ||
			  Dummy.SubString(2,1) == "\x1D" || Dummy.SubString(2,1) == "\x1F" ||
			  Dummy.SubString(2,1) == "\x0F")
		   {
			int len1,len2;

			//check if deleted
			len1 = Dummy.Length();
			Dummy.Delete(a, 1);
			len2 = Dummy.Length();

			if(len1 == len2) //nothing was deleted
			{
			 Dummy.Delete(1,1);
			}
		   }
		   else
		   {
			Dummy.Delete(1,1);
		   }

		   Form1->UpdateFormatList(a, 1);

		   if(Dummy.Pos("\x1E") > 0)
		   {
			Form1->str->Add("1 clStrikeout "+UnicodeString(Dummy.Pos("\x1E")));
		   }
		   else
		   {
			Form1->str->Add("1 clStrikeout 00");
		   }
		  }
		  else
		  {
		   Dummy.Delete(a, 1);
		   Form1->UpdateFormatList(a, 1);

		   if(Dummy.Pos("\x1E") > 0)
		   {
			Form1->str->Add(UnicodeString(a)+" clStrikeout "+UnicodeString(Dummy.Pos("\x1E")));
		   }
		   else
		   {
			Form1->str->Add(UnicodeString(a)+" clStrikeout 00");
		   }

		   a = a - 1;
		  }
		 }

		 if(Dummy.SubString(a, 1) == "\x1D")
		 {
		  //Italic
		  if(a == 0)
		  {
		   if(Dummy.SubString(2,1) == "\x03" || Dummy.SubString(2,1) == "\x02" ||
			  Dummy.SubString(2,1) == "\x1F" || Dummy.SubString(2,1) == "\x1E" ||
			  Dummy.SubString(2,1) == "\x0F")
		   {
			int len1,len2;

			//check if deleted
			len1 = Dummy.Length();
			Dummy.Delete(a, 1);
			len2 = Dummy.Length();

			if(len1 == len2) //nothing was deleted
			{
			 Dummy.Delete(1,1);
			}
		   }
		   else
		   {
			Dummy.Delete(1,1);
		   }

		   Form1->UpdateFormatList(a, 1);

		   if(Dummy.Pos("\x1D") > 0)
		   {
			Form1->str->Add("1 clItalic "+UnicodeString(Dummy.Pos("\x1D")));
		   }
		   else
		   {
			Form1->str->Add("1 clItalic 00");
		   }
		  }
		  else
		  {
		   Dummy.Delete(a, 1);
		   Form1->UpdateFormatList(a, 1);

		   if(Dummy.Pos("\x1D") > 0)
		   {
			Form1->str->Add(UnicodeString(a)+" clItalic "+UnicodeString(Dummy.Pos("\x1D")));
		   }
		   else
		   {
			Form1->str->Add(UnicodeString(a)+" clItalic 00");
		   }

		   a = a - 1;
		  }
		 }

		 if(Dummy.SubString(a, 3) == "00")
		 {
		  // white
		  if(a == 0)
		  {
		   Dummy.Delete(1, 3);
		   Form1->UpdateFormatList (1, 3);

		   if(Dummy.Pos("00") > 0)
		   {
			Form1->str->Add(UnicodeString(1)+" clWhite "+UnicodeString(Dummy.Pos("00")-1));
		   }
		   else
		   {
			Form1->str->Add(UnicodeString(1)+" clWhite 00");
		   }
		  }
		  else
		  {
		   Dummy.Delete(a, 3);
		   Form1->UpdateFormatList(a, 3);

		   if(Dummy.Pos("00") > 0)
		   {
			Form1->str->Add(UnicodeString(a)+" clWhite "+UnicodeString(Dummy.Pos("00")-1)); // add next pos
		   }
		   else
		   {
			Form1->str->Add(UnicodeString(a)+" clWhite 00");
		   }

		   a = a - 3;
		  }
		 }

		 if(Dummy.SubString(a, 3) == "01")
		 {
		  // black
		  if(a == 0)
		  {
		   Dummy.Delete(1, 3);
		   Form1->UpdateFormatList(1, 3);

		   if(Dummy.Pos("01") > 0)
		   {
			Form1->str->Add(UnicodeString(1)+" clBlack "+UnicodeString(Dummy.Pos("01")-1)); // add next pos
		   }
		   else
		   {
			Form1->str->Add(UnicodeString(1)+" clBlack 00");
		   }
		  }
		  else
		  {
		   Dummy.Delete(a, 3);
		   Form1->UpdateFormatList(a, 3);

		   if(Dummy.Pos("01") > 0)
		   {
			Form1->str->Add(UnicodeString(a)+" clBlack "+UnicodeString(Dummy.Pos("01")-1)); // add next pos
		   }
		   else
		   {
			Form1->str->Add(UnicodeString(a)+" clBlack 00");
		   }

		   a = a - 3;
		  }
		 }

		 if(Dummy.SubString(a, 3) == "02")
		 {
		  // blue
		  if(a == 0)
		  {
		   Dummy.Delete(1, 3);
		   Form1->UpdateFormatList(1, 3);

		   if(Dummy.Pos("02") > 0)
		   {
			Form1->str->Add(UnicodeString(1)+" clBlue "+UnicodeString(Dummy.Pos("02") - 1)); // add nextpos
		   }
		   else
		   {
			Form1->str->Add(UnicodeString(1)+" clBlue 00");
		   }
		  }
		  else
		  {
		   Dummy.Delete(a, 3);
		   Form1->UpdateFormatList(a, 3);

		   if(Dummy.Pos("02") > 0)
		   {
			Form1->str->Add(UnicodeString(a)+" clBlue "+UnicodeString(Dummy.Pos("02") - 1)); // add nextpos
		   }
		   else
		   {
			Form1->str->Add(UnicodeString(a)+" clBlue 00");
		   }

		   a = a - 3;
		  }
		 }

		 if(Dummy.SubString(a, 3) == "03")
		 {
		  // green
		  if(a == 0)
		  {
		   Dummy.Delete(1, 3);
		   Form1->UpdateFormatList(1, 3);

		   if(Dummy.Pos("03") > 0)
		   {
			Form1->str->Add(UnicodeString(1)+" clGreen "+UnicodeString(Dummy.Pos("03") - 1)); // add next pos
		   }
		   else
		   {
			Form1->str->Add(UnicodeString(1)+" clGreen 00");
		   }
		  }
		  else
		  {
		   Dummy.Delete(a, 3);
		   Form1->UpdateFormatList(a, 3);

		   if(Dummy.Pos("03") > 0)
		   {
			Form1->str->Add(UnicodeString(a)+" clGreen "+UnicodeString(Dummy.Pos("03") - 1)); // add next pos
		   }
		   else
		   {
			Form1->str->Add(UnicodeString(a)+" clGreen 00");
		   }

		   a = a - 3;
		  }
		 }

		 if(Dummy.SubString(a, 3) == "04")
		 {
		  // red
		  if(a == 0)
		  {
		   Dummy.Delete(1, 3);
		   Form1->UpdateFormatList(1, 3);

		   if(Dummy.Pos("04") > 0)
		   {
			Form1->str->Add(UnicodeString(1)+" clRed "+UnicodeString(Dummy.Pos("04") - 1)); // add next pos
		   }
		   else
		   {
			Form1->str->Add(UnicodeString(1)+" clRed 00");
		   }
		  }
		  else
		  {
		   Dummy.Delete(a, 3);
		   Form1->UpdateFormatList(a, 3);

		   if(Dummy.Pos("04") > 0)
		   {
			Form1->str->Add(UnicodeString(a)+" clRed "+UnicodeString(Dummy.Pos("04") - 1)); // add next pos
		   }
		   else
		   {
			Form1->str->Add(UnicodeString(a)+" clRed 00");
		   }

		   a = a - 3;
		  }
		 }

		 if(Dummy.SubString(a, 3) == "05")
		 {
		  // brown
		  if(a == 0)
		  {
		   Dummy.Delete(1, 3);
		   Form1->UpdateFormatList(1, 3);

		   if(Dummy.Pos("05") > 0)
		   {
			Form1->str->Add(UnicodeString(1)+" clBrown "+UnicodeString(Dummy.Pos("05") - 1)); // add next pos
		   }
		   else
		   {
			Form1->str->Add(UnicodeString(1)+" clBrown 00");
		   }
		  }
		  else
		  {
		   Dummy.Delete(a, 3);
		   Form1->UpdateFormatList(a, 3);

		   if(Dummy.Pos("05") > 0)
		   {
			Form1->str->Add(UnicodeString(a)+" clBrown "+UnicodeString(Dummy.Pos("05") - 1)); // add next pos
		   }
		   else
		   {
			Form1->str->Add(UnicodeString(a)+" clBrown 00");
		   }

		   a = a - 3;
		  }
		 }

		 if(Dummy.SubString(a, 3) == "06")
		 {
		  // purple
		  if(a == 0)
		  {
		   Dummy.Delete(1, 3);
		   Form1->UpdateFormatList(1, 3);

		   if(Dummy.Pos("06") > 0)
		   {
			Form1->str->Add(UnicodeString(1)+" clPurple "+UnicodeString(Dummy.Pos("06") - 1)); // add next pos
		   }
		   else
		   {
			Form1->str->Add(UnicodeString(1)+" clPurple 00");
		   }
		  }
		  else
		  {
		   Dummy.Delete(a, 3);
		   Form1->UpdateFormatList(a, 3);

		   if(Dummy.Pos("06") > 0)
		   {
			Form1->str->Add(UnicodeString(a)+" clPurple "+UnicodeString(Dummy.Pos("06") - 1)); // add next pos
		   }
		   else
		   {
			Form1->str->Add(UnicodeString(a)+" clPurple 00");
		   }

		   a = a - 3;
		  }
		 }

		 if(Dummy.SubString(a, 3) == "07")
		 {
		  // orange
		  if(a == 0)
		  {
		   Dummy.Delete(1, 3);
		   Form1->UpdateFormatList(1, 3);

		   if(Dummy.Pos("07") > 0)
		   {
			Form1->str->Add(UnicodeString(1)+" clOrange "+UnicodeString(Dummy.Pos("07") -1)); // add next pos
		   }
		   else
		   {
			Form1->str->Add(UnicodeString(1)+" clOrange 00");
		   }
		  }
		  else
		  {
		   Dummy.Delete(a, 3);
		   Form1->UpdateFormatList(a, 3);

		   if(Dummy.Pos("07") > 0)
		   {
			Form1->str->Add(UnicodeString(a)+" clOrange "+UnicodeString(Dummy.Pos("07") -1)); // add next pos
		   }
		   else
		   {
			Form1->str->Add(UnicodeString(a)+" clOrange 00");
		   }

		   a = a - 3;
		  }
		 }

		 if(Dummy.SubString(a, 3) == "08")
		 {
		  // yellow
		  if(a == 0)
		  {
		   Dummy.Delete(1, 3);
		   Form1->UpdateFormatList(1, 3);

		   if(Dummy.Pos("08") > 0)
		   {
			Form1->str->Add(UnicodeString(1)+" clYellow "+UnicodeString(Dummy.Pos("08") - 1)); // add next pos
		   }
		   else
		   {
			Form1->str->Add(UnicodeString(1)+" clYellow 00");
		   }
		  }
		  else
		  {
		   Dummy.Delete(a, 3);
		   Form1->UpdateFormatList(a, 3);

		   if(Dummy.Pos("08") > 0)
		   {
			Form1->str->Add(UnicodeString(a)+" clYellow "+UnicodeString(Dummy.Pos("08") - 1)); // add next pos
		   }
		   else
		   {
			Form1->str->Add(UnicodeString(a)+" clYellow 00");
		   }

		   a = a - 3;
		  }
		 }

		 if(Dummy.SubString(a, 3) == "09")
		 {
		  // lightgreen
		  if(a == 0)
		  {
		   Dummy.Delete(1, 3);
		   Form1->UpdateFormatList(1, 3);

		   if(Dummy.Pos("09") > 0)
		   {
			Form1->str->Add(UnicodeString(1)+" clLightGreen "+UnicodeString(Dummy.Pos("09") - 1)); // add next pos
		   }
		   else
		   {
			Form1->str->Add(UnicodeString(1)+" clLightGreen 00");
		   }
		  }
		  else
		  {
		   Dummy.Delete(a, 3);
		   Form1->UpdateFormatList(a, 3);

		   if(Dummy.Pos("09") > 0)
		   {
			Form1->str->Add(UnicodeString(a)+" clLightGreen "+UnicodeString(Dummy.Pos("09") - 1)); // add next pos
		   }
		   else
		   {
			Form1->str->Add(UnicodeString(a)+" clLightGreen 00");
		   }

		   a = a - 3;
		  }
		 }

		 if(Dummy.SubString(a, 3) == "10")
		 {
		  // cyan
		  if(a == 0)
		  {
		   Dummy.Delete(1, 3);
		   Form1->UpdateFormatList(1, 3);

		   if(Dummy.Pos("10") > 0)
		   {
			Form1->str->Add(UnicodeString(1)+" clTeal "+UnicodeString(Dummy.Pos("10") - 1)); // add next pos
		   }
		   else
		   {
			Form1->str->Add(UnicodeString(1)+" clTeal 00");
		   }
		  }
		  else
		  {
		   Dummy.Delete(a, 3);
		   Form1->UpdateFormatList(a, 3);

		   if(Dummy.Pos("10") > 0)
		   {
			Form1->str->Add(UnicodeString(a)+" clTeal "+UnicodeString(Dummy.Pos("10") - 1)); // add next pos
		   }
		   else
		   {
			Form1->str->Add(UnicodeString(a)+" clTeal 00");
		   }

		   a = a - 3;
		  }
		 }

		 if(Dummy.SubString(a, 3) == "11")
		 {
		  // lightcyan
		  if(a == 0)
		  {
		   Dummy.Delete(1, 3);
		   Form1->UpdateFormatList(1, 3);

		   if(Dummy.Pos("11") > 0)
		   {
			Form1->str->Add(UnicodeString(1)+" clAqua "+UnicodeString(Dummy.Pos("11") - 1)); // add next pos
		   }
		   else
		   {
			Form1->str->Add(UnicodeString(1)+" clAqua 00");
		   }
		  }
		  else
		  {
		   Dummy.Delete(a, 3);
		   Form1->UpdateFormatList(a, 3);

		   if(Dummy.Pos("11") > 0)
		   {
			Form1->str->Add(UnicodeString(a)+" clAqua "+UnicodeString(Dummy.Pos("11") - 1)); // add next pos
		   }
		   else
		   {
			Form1->str->Add(UnicodeString(a)+" clAqua 00");
		   }

		   a = a - 3;
		  }
		 }

		 if(Dummy.SubString(a, 3) == "12")
		 {
		  // lightblue
		  if(a == 0)
		  {
		   Dummy.Delete(1, 3);
		   Form1->UpdateFormatList(1, 3);

		   if(Dummy.Pos("12") > 0)
		   {
			Form1->str->Add(UnicodeString(1)+" clLightblue "+UnicodeString(Dummy.Pos("12") - 1)); // add next pos
		   }
		   else
		   {
			Form1->str->Add(UnicodeString(1)+" clLightblue 00");
		   }
		  }
		  else
		  {
		   Dummy.Delete(a, 3);
		   Form1->UpdateFormatList(a, 3);

		   if(Dummy.Pos("12") > 0)
		   {
			Form1->str->Add(UnicodeString(a)+" clLightblue "+UnicodeString(Dummy.Pos("12") - 1)); // add next pos
		   }
		   else
		   {
			Form1->str->Add(UnicodeString(a)+" clLightblue 00");
		   }

		   a = a - 3;
		  }
		 }

		 if(Dummy.SubString(a, 3) == "13")
		 {
		  // pink
		  if(a == 0)
		  {
		   Dummy.Delete(1, 3);
		   Form1->UpdateFormatList(1, 3);

		   if(Dummy.Pos("13") > 0)
		   {
			Form1->str->Add(UnicodeString(1)+" clPink "+UnicodeString(Dummy.Pos("13") - 1)); // add next pos
		   }
		   else
		   {
			Form1->str->Add(UnicodeString(1)+" clPink 00");
		   }
		  }
		  else
		  {
		   Dummy.Delete(a, 3);
		   Form1->UpdateFormatList(a, 3);

		   if(Dummy.Pos("13") > 0)
		   {
			Form1->str->Add(UnicodeString(a)+" clPink "+UnicodeString(Dummy.Pos("13") - 1)); // add next pos
		   }
		   else
		   {
			Form1->str->Add(UnicodeString(a)+" clPink 00");
		   }

		   a = a - 3;
		  }
		 }

		 if(Dummy.SubString(a, 3) == "14")
		 {
		  // grey
		  if(a == 0)
		  {
		   Dummy.Delete(1, 3);
		   Form1->UpdateFormatList(1, 3);

		   if(Dummy.Pos("14") > 0)
		   {
			Form1->str->Add(UnicodeString(1)+" clGrey "+UnicodeString(Dummy.Pos("14") - 1)); // add next pos
		   }
		   else
		   {
			Form1->str->Add(UnicodeString(1)+" clGrey 00");
		   }
		  }
		  else
		  {
		   Dummy.Delete(a, 3);
		   Form1->UpdateFormatList(a, 3);

		   if(Dummy.Pos("14") > 0)
		   {
			Form1->str->Add(UnicodeString(a)+" clGrey "+UnicodeString(Dummy.Pos("14") - 1)); // add next pos
		   }
		   else
		   {
			Form1->str->Add(UnicodeString(a)+" clGrey 00");
		   }

		   a = a - 3;
		  }
		 }

		 if(Dummy.SubString(a, 3) == "15")
		 {
		  // lightgrey
		  if(a == 0)
		  {
		   Dummy.Delete(1, 3);
		   Form1->UpdateFormatList(1, 3);

		   if(Dummy.Pos("15") > 0)
		   {
			Form1->str->Add(UnicodeString(1)+" clLightgrey "+UnicodeString(Dummy.Pos("15") - 1)); // add next pos
		   }
		   else
		   {
			Form1->str->Add(UnicodeString(1)+" clLightgrey 00");
		   }
		  }
		  else
		  {
		   Dummy.Delete(a, 3);
		   Form1->UpdateFormatList(a, 3);

		   if(Dummy.Pos("15") > 0)
		   {
			Form1->str->Add(UnicodeString(a)+" clLightgrey "+UnicodeString(Dummy.Pos("15") - 1)); // add next pos
		   }
		   else
		   {
			Form1->str->Add(UnicodeString(a)+" clLightgrey 00");
		   }

		   a = a - 3;
		  }
		 }

		 if(Dummy.SubString(a, 1) == "\x03")
		 {
		  //NoColor
		  if(Dummy.SubString(a,3) == "00" || Dummy.SubString(a,3) == "01" ||
			 Dummy.SubString(a,3) == "02" || Dummy.SubString(a,3) == "03" ||
			 Dummy.SubString(a,3) == "04" || Dummy.SubString(a,3) == "05" ||
			 Dummy.SubString(a,3) == "06" || Dummy.SubString(a,3) == "07" ||
			 Dummy.SubString(a,3) == "08" || Dummy.SubString(a,3) == "09" ||
			 Dummy.SubString(a,3) == "10" || Dummy.SubString(a,3) == "11" ||
			 Dummy.SubString(a,3) == "12" || Dummy.SubString(a,3) == "13" ||
			 Dummy.SubString(a,3) == "14" || Dummy.SubString(a,3) == "15")
		  {
		   // do nothing
		  }
		  else
		  {
		   if(a == 0)
		   {
			if(Dummy.SubString(2,1) == "\x1F" || Dummy.SubString(2,1) == "\x02" ||
			   Dummy.SubString(2,1) == "\x1D" || Dummy.SubString(2,1) == "\x1E" ||
			   Dummy.SubString(2,1) == "\x0F")
			{
			 int len1,len2;

			 //check if deleted
			 len1 = Dummy.Length();
			 Dummy.Delete(1, 1);
			 len2 = Dummy.Length();

			 if(len1 == len2) //nothing was deleted
			 {
			  Dummy.Delete(1,1);
			 }
			}
			else
			{
			 Dummy.Delete(1,1);
			}

			Form1->UpdateFormatList(1, 1);

			if(Dummy.Pos("\x03") > 0)
			{
			 Form1->str->Add("1 clNoColor "+UnicodeString(Dummy.Pos("\x03")));
			}
			else
			{
			 Form1->str->Add("1 clNoColor 00"); // add end pos
			}
		   }
		   else
		   {
			Dummy.Delete(a, 1);
			Form1->UpdateFormatList(a, 1);

			if(Dummy.Pos("\x03") > 0)
			{
			 Form1->str->Add(UnicodeString(a)+" clNoColor "+UnicodeString(Dummy.Pos("\x03")));
			}
			else
			{
			 Form1->str->Add(UnicodeString(a) + " clNoColor 00"); // add end pos
			}

			a = a - 1;
		   }
		  }
		 }
		}

		Dummy =  Cp->RemoveLastChars(Dummy);
	   }
	   catch(Exception &exception)
	   {
		//
	   }

	   Form1->ResultMemo->Lines->Add("Line after ColorParser: "+Dummy);
	   offset = Form1->TestRTF->Text.Length() - Form1->TestRTF->Lines->Count;

	   Form1->ResultMemo->Lines->Add(" ");
	   Form1->ResultMemo->Lines->Add(" ");
	   Form1->ResultMemo->Lines->Add("Format List:");
	   Form1->ResultMemo->Lines->Add(" ");
	   Form1->ResultMemo->Lines->AddStrings(Form1->str);

	   if(Dummy.Length() > 0)
	   {
		try
		{
		 Form1->TestRTF->ClearSelection();
		 Form1->TestRTF->Lines->Add(Dummy);
		 // this Line raises sometimes an exception in riched20.dll
		}
		catch(Exception &exception)
		{
		 //
		}

		try
		{
		 Form1->TestRTF->SelStart = offset;
		 Form1->TestRTF->SelLength = Dummy.Pos(Form1->NBL) - 1; // changed 22.02.2013
		 Form1->TestRTF->SelAttributes->Color = clBlue; //Timecolor
		 Form1->TestRTF->SelAttributes->Size = Form1->TestRTF->Font->Size;
		 Form1->TestRTF->SelAttributes->Style = Form1->TestRTF->SelAttributes->Style >> fsBold >> fsItalic >> fsUnderline >> fsStrikeOut;
		}
		catch(Exception &exception)
		{
		 //
		}

		try
		{
		 Form1->TestRTF->SelStart = Dummy.Pos(Form1->NBL) - 1 + offset; // changed 22.02.2013
		 Form1->TestRTF->SelLength = Dummy.Pos(Form1->NBR + " ") + 1 - Dummy.Pos(Form1->NBL);
		 Form1->TestRTF->SelAttributes->Color = clRed; //Form1->IRCNickColor;
		 Form1->TestRTF->SelAttributes->Size = Form1->TestRTF->Font->Size;
		 Form1->TestRTF->SelAttributes->Style = Form1->TestRTF->SelAttributes->Style >> fsBold >> fsItalic >> fsUnderline >> fsStrikeOut;
		}
		catch(Exception &exception)
		{
		 //
		}

		try
		{
		 Form1->TestRTF->SelStart = Dummy.Pos(Form1->NBR + " ") + offset;
		 Form1->TestRTF->SelLength = Dummy.Length() - Dummy.Pos(Form1->NBR + " ") + offset;
		 Form1->TestRTF->SelAttributes->Style = Form1->TestRTF->Font->Style;
		 Form1->TestRTF->SelAttributes->Color = Form1->TestRTF->Font->Color;
		 Form1->TestRTF->SelAttributes->Size = Form1->TestRTF->Font->Size;
		}
		catch(Exception &exception)
		{
		 //
		}
	   }

	   Buff = Dummy;

	   try
	   {
		for(a = 0; a < Form1->str->Count; a++)
		{
		 Start = "";
		 Dummy = "";
		 Col = "";
		 Next = "";

		 Start = Form1->str->Strings[a].SubString(0, Form1->str->Strings[a].Pos(" ") - 1);
		 Dummy = Form1->str->Strings[a].SubString(Form1->str->Strings[a].Pos(" ") + 1,Form1->str->Strings[a].Length() - Form1->str->Strings[a].Pos(" ") + 1);
		 Col = Dummy.SubString(0, Dummy.Pos(" ") - 1);
		 Next = Dummy.SubString(Dummy.Pos(" ") + 1,Dummy.Length() - Dummy.Pos(" ") + 1);

		 if(Next == "clWhite" || Next == "clBlack" || Next == "clBlue" ||
			Next == "clGreen" || Next == "clRed" || Next == "clBrown" ||
			Next == "clPurple" || Next == "clOrange" ||
			Next == "clYellow" || Next == "clLightgreen" || Next == "Ubold" ||
			Next == "clTeal" || Next == "clAqua" || Next == "clLightblue" ||
			Next == "clPink" || Next == "clGrey" || Next == "clLightgrey" ||
			Next == "bold" || Next == "clNoColor" || Next == "clUnderline" ||
			Next == "clItalic" || Next == "clTerminate" || Next == "clNoStyle" ||
			Next == "clStrikeout" || Next == "00" ||Col == Next)
		 {
		  Next = Buff.Length() + 1;
		 }

		 start = Start.ToInt() + offset - 1;
		 next = Next.ToInt() + offset; // +1 removed
		 count = next - start;

		 Form1->TestRTF->SelStart = start;
		 Form1->TestRTF->SelLength = count;

		 if(Col == "clWhite") // 00
		 {
		  if(Form1->colortype == true)
		  {
		   int rgb = ColorToRGB(Form1->TestRTF->Color);
		   int r = GetRValue(rgb);
		   int g = GetGValue(rgb);
		   int b = GetBValue(rgb);

		   if(r+g+b > 600) //ColorRTF is lighter than RGB(200,200,200)
		   {
			Form1->TestRTF->SelAttributes->Color = clBlack;
			Form1->TestRTF->SelAttributes->Size = Form1->TestRTF->Font->Size;
		   }
		   else
		   {
			Form1->TestRTF->SelAttributes->Color = clWhite;
			Form1->TestRTF->SelAttributes->Size = Form1->TestRTF->Font->Size;
		   }
		  }
		  else
		  {
		   Form1->TestRTF->SelAttributes->Color = clWhite;
		   Form1->TestRTF->SelAttributes->Size = Form1->TestRTF->Font->Size;
		  }
		 }

		 if(Col == "clBlack") // 01
		 {
		  if(Form1->colortype == true)
		  {
		   int rgb = ColorToRGB(Form1->TestRTF->Color);
		   int r = GetRValue(rgb);
		   int g = GetGValue(rgb);
		   int b = GetBValue(rgb);

		   if(r+g+b < 80)  //darker than RGB(0,0,80);
		   {
			Form1->TestRTF->SelAttributes->Color = clWhite;
			Form1->TestRTF->SelAttributes->Size = Form1->TestRTF->Font->Size;
		   }
		   else
		   {
			Form1->TestRTF->SelAttributes->Color = clBlack;
			Form1->TestRTF->SelAttributes->Size = Form1->TestRTF->Font->Size;
		   }
		  }
		  else
		  {
		   Form1->TestRTF->SelAttributes->Color = clBlack;
		   Form1->TestRTF->SelAttributes->Size = Form1->TestRTF->Font->Size;
		  }
		 }

		 if(Col == "clBlue") // 02
		 {
		  Form1->TestRTF->SelAttributes->Color = clBlue;
		  Form1->TestRTF->SelAttributes->Size = Form1->TestRTF->Font->Size;
		 }

		 if(Col == "clGreen") // 03
		 {
		  Form1->TestRTF->SelAttributes->Color = clGreen;
		  Form1->TestRTF->SelAttributes->Size = Form1->TestRTF->Font->Size;
		 }

		 if(Col == "clRed") // 04
		 {
		  Form1->TestRTF->SelAttributes->Color = clRed;
		  Form1->TestRTF->SelAttributes->Size = Form1->TestRTF->Font->Size;
		 }

		 if(Col == "clBrown") // 05
		 {
		  Form1->TestRTF->SelAttributes->Color = TColor(RGB(128, 64, 0));
		  Form1->TestRTF->SelAttributes->Size = Form1->TestRTF->Font->Size;
		 }

		 if(Col == "clPurple") // 06
		 {
		  Form1->TestRTF->SelAttributes->Color = clPurple;
		  Form1->TestRTF->SelAttributes->Size = Form1->TestRTF->Font->Size;
		 }

		 if(Col == "clOrange") // 07
		 {
		  Form1->TestRTF->SelAttributes->Color = TColor(RGB(255, 128, 0));
		  Form1->TestRTF->SelAttributes->Size = Form1->TestRTF->Font->Size;
		 }

		 if(Col == "clYellow") // 08
		 {
		  Form1->TestRTF->SelAttributes->Color = clYellow;
		  Form1->TestRTF->SelAttributes->Size = Form1->TestRTF->Font->Size;
		 }

		 if(Col == "clLightGreen") // 09
		 {
		  Form1->TestRTF->SelAttributes->Color = TColor(RGB(128, 255, 0));
		  Form1->TestRTF->SelAttributes->Size = Form1->TestRTF->Font->Size;
		 }

		 if(Col == "clTeal") // 10
		 {
		  Form1->TestRTF->SelAttributes->Color = clTeal;
		  Form1->TestRTF->SelAttributes->Size = Form1->TestRTF->Font->Size;
		 }

		 if(Col == "clAqua") // 11
		 {
		  Form1->TestRTF->SelAttributes->Color = clAqua;
		  Form1->TestRTF->SelAttributes->Size = Form1->TestRTF->Font->Size;
		 }

		 if(Col == "clLightblue") // 12
		 {
		  Form1->TestRTF->SelAttributes->Color = TColor(RGB(0, 128, 255));
		  Form1->TestRTF->SelAttributes->Size = Form1->TestRTF->Font->Size;
		 }

		 if(Col == "clPink") // 13
		 {
		  Form1->TestRTF->SelAttributes->Color = TColor(RGB(255, 0, 255));
		  Form1->TestRTF->SelAttributes->Size = Form1->TestRTF->Font->Size;
		 }

		 if(Col == "clGrey") // 14
		 {
		  Form1->TestRTF->SelAttributes->Color = TColor(RGB(128, 128, 128));
		  Form1->TestRTF->SelAttributes->Size = Form1->TestRTF->Font->Size;
		 }

		 if(Col == "clLightgrey") // 15
		 {
		  Form1->TestRTF->SelAttributes->Color = TColor(RGB(192, 192, 192));
		  Form1->TestRTF->SelAttributes->Size = Form1->TestRTF->Font->Size;
		 }

		 if(Col == "clNoColor")
		 {
		  Form1->TestRTF->SelAttributes->Color = Form1->TestRTF->Font->Color;
		  Form1->TestRTF->SelAttributes->Size = Form1->TestRTF->Font->Size;
		 }

		 if(Col == "clNoStyle")
		 {
		  Form1->TestRTF->SelAttributes->Style = Form1->TestRTF->SelAttributes->Style >> fsBold;
		  Form1->TestRTF->SelAttributes->Style = Form1->TestRTF->SelAttributes->Style >> fsUnderline;
		  Form1->TestRTF->SelAttributes->Style = Form1->TestRTF->SelAttributes->Style >> fsItalic;
		  Form1->TestRTF->SelAttributes->Style = Form1->TestRTF->SelAttributes->Style >> fsStrikeOut;

		  italic = false;
		  underline = false;
		  strikeout = false;
		  bold = false;
		 }

		 if(Col == "bold")
		 {
		  if(bold == true)
		  {
		   Form1->TestRTF->SelAttributes->Style = Form1->TestRTF->SelAttributes->Style >> fsBold;
		   bold = false;
		  }
		  else
		  {
		   Form1->TestRTF->SelAttributes->Style = Form1->TestRTF->SelAttributes->Style << fsBold;
		   bold = true;
		  }
		 }

		 if(Col == "clUnderline")
		 {
		  if(underline == true)
		  {
		   Form1->TestRTF->SelAttributes->Style = Form1->TestRTF->SelAttributes->Style >> fsUnderline;
		   underline = false;
		  }
		  else
		  {
		   Form1->TestRTF->SelAttributes->Style = Form1->TestRTF->SelAttributes->Style << fsUnderline;
		   underline = true;
		  }
		 }

		 if(Col == "clItalic")
		 {
		  if(italic == true)
		  {
		   Form1->TestRTF->SelAttributes->Style = Form1->TestRTF->SelAttributes->Style >> fsItalic;
		   italic = false;
		  }
		  else
		  {
		   Form1->TestRTF->SelAttributes->Style = Form1->TestRTF->SelAttributes->Style << fsItalic;
		   italic = true;
		  }
		 }

		 if(Col == "clStrikeout")
		 {
		  if(strikeout == true)
		  {
		   Form1->TestRTF->SelAttributes->Style = Form1->TestRTF->SelAttributes->Style >> fsStrikeOut;
		   strikeout = false;
		  }
		  else
		  {
		   Form1->TestRTF->SelAttributes->Style = Form1->TestRTF->SelAttributes->Style << fsStrikeOut;
		   strikeout = true;
		  }
		 }

		 if(Col == "clTerminate")
		 {
		  Form1->TestRTF->SelAttributes->Color = Form1->TestRTF->Font->Color;
		  Form1->TestRTF->SelAttributes->Size = Form1->TestRTF->Font->Size;

		  Form1->TestRTF->SelAttributes->Style = Form1->TestRTF->SelAttributes->Style >> fsBold;
		  bold = false;

		  Form1->TestRTF->SelAttributes->Style = Form1->TestRTF->SelAttributes->Style >> fsUnderline;
		  underline = false;

		  Form1->TestRTF->SelAttributes->Style = Form1->TestRTF->SelAttributes->Style >> fsItalic;
		  italic = false;

		  Form1->TestRTF->SelAttributes->Style = Form1->TestRTF->SelAttributes->Style >> fsStrikeOut;
		  strikeout = false;
		 }
		}
	   }
	   catch(Exception &exception)
	   {
		//
	   }

	   Form1->TestRTF->ClearSelection();
	  }

	  static void __fastcall Add(const UnicodeString &Str)
	  {
	   TRTFLine *Sync = new TRTFLine(Str);

	   try
	   {
		Sync->Synchronize();
	   }
	   __finally
	   {
		delete Sync;
	   }
 }
};


