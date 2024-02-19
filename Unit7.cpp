#include <vcl.h>
#include <System.Classes.hpp>
#include <System.StrUtils.hpp>
#include "sync.h"
#include "Unit1.h"
#include "Unit7.h"

#pragma hdrstop
#pragma package(smart_init)

//This Class is needed to prepare the Parser, we have to remove all Backgroundcolors
//"\x3 03,01 to \x3 03" , "\x3 3 to \x3 03" and so on . . .


UnicodeString __fastcall TColorParser::RemoveLastChars(UnicodeString FInput)
{
 UnicodeString FOutput,Dummy;

 //Delete controlchars at the end of the string
 Dummy = ReverseString(FInput);

 do
 {
  //Application->ProcessMessages();

  if(Dummy.Pos("\x2") == 1)
  {
   Dummy.Delete(Dummy.Pos("\x2"),1);
  }

  if(Dummy.Pos("\x3") == 1)
  {
   Dummy.Delete(Dummy.Pos("\x3"),1);
  }

  if(Dummy.Pos("\x1D") == 1)
  {
   Dummy.Delete(Dummy.Pos("\x1D"),1);
  }

  if(Dummy.Pos("\x1E")  == 1)
  {
   Dummy.Delete(Dummy.Pos("\x1E"),1);
  }

  if(Dummy.Pos("\x1F") == 1)
  {
   Dummy.Delete(Dummy.Pos("\x1F"),1);
  }

  if(Dummy.Pos("\x0F") == 1)
  {
   Dummy.Delete(Dummy.Pos("\x0F"),1);
  }
 }
 while(Dummy.Pos("\x2") == 1 || Dummy.Pos("\x3") == 1 || Dummy.Pos("\x0F") == 1 ||
	   Dummy.Pos("\x1F") == 1 || Dummy.Pos("\x1E") == 1 || Dummy.Pos("\x1D") == 1);

 FOutput = ReverseString(Dummy);
 return FOutput;
}


UnicodeString __fastcall TColorParser::RemoveBackColors(UnicodeString FInput)
{
 int pos, a; // r;
 //int count;
 //__int64 x2;

 UnicodeString check, first, last, s, chk, Dummy;
 UnicodeString ctrlU,ctrlS,ctrlB,ctrlI,ctrlC,ctrlR,ctrlG,ctrlT;
 UnicodeString White,Black,Blue,Green,Red,Brown,Purple,Orange,Yellow,LightGreen;
 UnicodeString Cyan,LightCyan,LightBlue,Pink,Gray,LightGray;

 //
 ctrlB = "\x02";    //Bold ControlChar
 ctrlC = "\x03";    //Color ControlChar
 ctrlI = "\x1D";    //Italic ControlChar
 ctrlS = "\x1E";    //Strikeout ControlChar
 ctrlU = "\x1F";    //Underlined ControlChar
 ctrlT = "\x0F";    //Terminate Color&Style
 //
 ctrlR = "\017";    //BackGround just remove this
 ctrlG = "\016";    //ReverseBackground just remove this
 //
 White =        ctrlC + "00";
 Black =        ctrlC + "01";
 Blue =         ctrlC + "02";
 Green =        ctrlC + "03";
 Red =          ctrlC + "04";
 Brown =        ctrlC + "05";
 Purple =       ctrlC + "06";
 Orange =       ctrlC + "07";
 Yellow =       ctrlC + "08";
 LightGreen =   ctrlC + "09";
 Cyan =         ctrlC + "10";
 LightCyan =    ctrlC + "11";
 LightBlue =    ctrlC + "12";
 Pink =         ctrlC + "13";
 Gray =         ctrlC + "14";
 LightGray =    ctrlC + "15";

 //
 do // 28.07.2011
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\x02\x02\x02")) // remove wrong bolds
  {
   pos = FInput.Pos("\x02\x02\x02");
   FInput.Delete(pos, 2);
  }
 }
 while(FInput.Pos("\x02\x02\x02") > NULL);


 do
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\x02\x02")) // remove wrong bolds
  {
   pos = FInput.Pos("\x02\x02");
   FInput.Delete(pos, 1);
  }
 }
 while(FInput.Pos("\x02\x02") > NULL);


 do // 28.07.2011
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\x03\x03\x03"))
  {
   pos = FInput.Pos("\x03\x03\x03");
   FInput.Delete(pos, 2);
  }
 }
 while (FInput.Pos("\x03\x03\x03") > NULL);


 do
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\x03\x03"))
  {
   pos = FInput.Pos("\x03\x03");
   FInput.Delete(pos, 1);
  }
 }
 while(FInput.Pos("\x03\x03") > NULL);

 do
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\x1F\x1F\x1F"))
  {
   pos = FInput.Pos("\x1F\x1F\x1F");
   FInput.Delete(pos, 2);
  }
 }
 while (FInput.Pos("\x1F\x1F\x1F") > NULL);


 do
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\x1F\x1F"))
  {
   pos = FInput.Pos("\x1F\x1F");
   FInput.Delete(pos, 1);
  }
 }
 while(FInput.Pos("\x1F\x1F") > NULL);

 do
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\x1D\x1D\x1D"))
  {
   pos = FInput.Pos("\x1D\x1D\x1D");
   FInput.Delete(pos, 2);
  }
 }
 while (FInput.Pos("\x1D\x1D\x1D") > NULL);

 do
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\x1D\x1D"))
  {
   pos = FInput.Pos("\x1D\x1D");
   FInput.Delete(pos, 1);
  }
 }
 while(FInput.Pos("\x1D\x1D") > NULL);

 do
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\x1E\x1E\x1E"))
  {
   pos = FInput.Pos("\x1E\x1E\x1E");
   FInput.Delete(pos, 2);
  }
 }
 while (FInput.Pos("\x1E\x1E\x1E") > NULL);

 do
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\x1E\x1E"))
  {
   pos = FInput.Pos("\x1E\x1E");
   FInput.Delete(pos, 1);
  }
 }
 while(FInput.Pos("\x1E\x1E") > NULL);

 do
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\x0F\x0F\x0F"))
  {
   pos = FInput.Pos("\x0F\x0F\x0F");
   FInput.Delete(pos, 2);
  }
 }
 while (FInput.Pos("\x0F\x0F\x0F") > NULL);

 do
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\x0F\x0F"))
  {
   pos = FInput.Pos("\x0F\x0F");
   FInput.Delete(pos,1);
  }
 }
 while(FInput.Pos("\x0F\x0F") > NULL);

 // delete style controls directly after \x0F
 do
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\x0F\x03"))
  {
   pos = FInput.Pos("\x0F\x03");
   FInput.Delete(pos,1);
   //FInput.Insert("\x03",pos);
  }
 }
 while(FInput.Pos("\x0F\x03") > NULL);

 do
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\x0F\x1D"))
  {
   pos = FInput.Pos("\x0F\x1D");
   FInput.Delete(pos,1);
   //FInput.Insert("\x1D",pos);
  }
 }
 while(FInput.Pos("\x0F\x1D") > NULL);

 do
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\x0F\x1E"))
  {
   pos = FInput.Pos("\x0F\x1E");
   FInput.Delete(pos,1);
   //FInput.Insert("\x1E",pos);
  }
 }
 while(FInput.Pos("\x0F\x1E") > NULL);

 do
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\x0F\x1F"))
  {
   pos = FInput.Pos("\x0F\x1F");
   FInput.Delete(pos,1);
   //FInput.Insert(" ",pos+1);
  }
 }
 while(FInput.Pos("\x0F\x1F") > NULL);

 do
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\x0F\x02"))
  {
   pos = FInput.Pos("\x0F\x02");
   FInput.Delete(pos,1);
   //FInput.Insert("\x02",pos);
  }
 }
 while(FInput.Pos("\x0F\x02") > NULL);

 do
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\x02\x1F\x0F"))
  {
   pos = FInput.Pos("\x02\x1F\x0F");
   FInput.Delete(pos,2);
   //FInput.Insert("\x0F",pos);
  }
 }
 while(FInput.Pos("\x02\x1F\x0F") > NULL);

 do
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\x1F\x02\x0F"))
  {
   pos = FInput.Pos("\x1F\x02\x0F");
   FInput.Delete(pos,2);
   //FInput.Insert("\x0F",pos);
  }
 }
 while(FInput.Pos("\x1F\x02\x0F") > NULL);


 do
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\x02\x0F"))
  {
   pos = FInput.Pos("\x02\x0F");
   FInput.Delete(pos,1);
   //FInput.Insert("\x0F",pos);
  }
 }
 while(FInput.Pos("\x02\x0F") > NULL);

 do
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\x1F\x0F"))
  {
   pos = FInput.Pos("\x1F\x0F");
   FInput.Delete(pos,1);
   //FInput.Insert("\x0F",pos);
  }
 }
 while(FInput.Pos("\x1F\x0F") > NULL);

 do
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\x1E\x0F"))
  {
   pos = FInput.Pos("\x1E\x0F");
   FInput.Delete(pos,1);
   //FInput.Insert("\x0F",pos);
  }
 }
 while(FInput.Pos("\x1E\x0F") > NULL);

 do
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\x1D\x0F"))
  {
   pos = FInput.Pos("\x1D\x0F");
   FInput.Delete(pos,1);
   //FInput.Insert("\x0F",pos);
  }
 }
 while(FInput.Pos("\x1D\x0F") > NULL);

 // remove unused controls in BSIRC
 do //remove \x04 completely
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\x04"))	//
  {
   pos = FInput.Pos("\x04");
   FInput.Delete(pos, 1);
  }
 }
 while(FInput.Pos("\x04") > NULL);

 do //remove \011 completely
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\x11"))	//
  {
   pos = FInput.Pos("\x11");
   FInput.Delete(pos, 1);
  }
 }
 while(FInput.Pos("\x11") > NULL);


 do //remove \016 completely
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\x16"))	//
  {
   pos = FInput.Pos("\x16");
   FInput.Delete(pos, 1);
  }
 }
 while(FInput.Pos("\x16") > NULL);

 do //remove \017 completely
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\x17"))	//
  {
   pos = FInput.Pos("\x17");
   FInput.Delete(pos,1);
  }
 }
 while(FInput.Pos("\x17") > NULL);



	do // change into mirc colorformat above 16 colors
	{
		//Application->ProcessMessages();

		if (FInput.Pos("\00316")) {
			pos = FInput.Pos("\00316");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("00", pos + 1);
		}

		if (FInput.Pos("\00332")) {
			pos = FInput.Pos("\00332");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("00", pos + 1);
		}

		if (FInput.Pos("\00348")) {
			pos = FInput.Pos("\00348");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("00", pos + 1);
		}

		if (FInput.Pos("\00364")) {
			pos = FInput.Pos("\00364");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("00", pos + 1);
		}

		if (FInput.Pos("\00380")) {
			pos = FInput.Pos("\00380");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("00", pos + 1);
		}

		if (FInput.Pos("\00396")) {
			pos = FInput.Pos("\00396");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("00", pos + 1);
		}

		if (FInput.Pos("\00399")) {
			pos = FInput.Pos("\00399");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("00", pos + 1);
		}
	}
	while (FInput.Pos("\00316") > NULL || FInput.Pos("\00332") >
		NULL || FInput.Pos("\00348") > NULL || FInput.Pos("\00364") >
		NULL || FInput.Pos("\00380") > NULL || FInput.Pos("\00396") >
		NULL || FInput.Pos("\00399") > NULL);

	do // change into mirc colorformat above 16 colors
	{
		//Application->ProcessMessages();

		if (FInput.Pos("\00317")) {
			pos = FInput.Pos("\00317");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("01", pos + 1);
		}

		if (FInput.Pos("\00333")) {
			pos = FInput.Pos("\00333");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("01", pos + 1);
		}

		if (FInput.Pos("\00349")) {
			pos = FInput.Pos("\00349");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("01", pos + 1);
		}

		if (FInput.Pos("\00365")) {
			pos = FInput.Pos("\00365");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("01", pos + 1);
		}

		if (FInput.Pos("\00381")) {
			pos = FInput.Pos("\00381");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("01", pos + 1);
		}

		if (FInput.Pos("\00397")) {
			pos = FInput.Pos("\00397");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("01", pos + 1);
		}
	}
	while (FInput.Pos("\00317") > NULL || FInput.Pos("\00333") >
		NULL || FInput.Pos("\00349") > NULL || FInput.Pos("\00365") >
		NULL || FInput.Pos("\00381") > NULL || FInput.Pos("\00397") > NULL);

	do // change into mirc colorformat above 16 colors
	{
		//Application->ProcessMessages();

		if (FInput.Pos("\00318")) {
			pos = FInput.Pos("\00318");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("02", pos + 1);
		}

		if (FInput.Pos("\00334")) {
			pos = FInput.Pos("\00334");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("02", pos + 1);
		}

		if (FInput.Pos("\00350")) {
			pos = FInput.Pos("\00350");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("02", pos + 1);
		}

		if (FInput.Pos("\00366")) {
			pos = FInput.Pos("\00366");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("02", pos + 1);
		}

		if (FInput.Pos("\00382")) {
			pos = FInput.Pos("\00382");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("02", pos + 1);
		}

		if (FInput.Pos("\00398")) {
			pos = FInput.Pos("\00398");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("02", pos + 1);
		}
	}
	while (FInput.Pos("\00318") > NULL || FInput.Pos("\00334") >
		NULL || FInput.Pos("\00350") > NULL || FInput.Pos("\00366") >
		NULL || FInput.Pos("\00382") > NULL || FInput.Pos("\00398") > NULL);

	do // change into mirc colorformat above 16 colors
	{
		//Application->ProcessMessages();

		if (FInput.Pos("\00319")) {
			pos = FInput.Pos("\00319");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("03", pos + 1);
		}

		if (FInput.Pos("\00335")) {
			pos = FInput.Pos("\00335");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("03", pos + 1);
		}

		if (FInput.Pos("\00351")) {
			pos = FInput.Pos("\00351");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("03", pos + 1);
		}

		if (FInput.Pos("\00367")) {
			pos = FInput.Pos("\00367");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("03", pos + 1);
		}

		if (FInput.Pos("\00383")) {
			pos = FInput.Pos("\00383");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("03", pos + 1);
		}
	}
	while (FInput.Pos("\00319") > NULL || FInput.Pos("\00335") >
		NULL || FInput.Pos("\00351") > NULL || FInput.Pos("\00367") >
		NULL || FInput.Pos("\00383") > NULL);

	do // change into mirc colorformat above 16 colors
	{
		//Application->ProcessMessages();

		if (FInput.Pos("\00320")) {
			pos = FInput.Pos("\00320");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("04", pos + 1);
		}

		if (FInput.Pos("\00336")) {
			pos = FInput.Pos("\00336");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("04", pos + 1);
		}

		if (FInput.Pos("\00352")) {
			pos = FInput.Pos("\00352");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("04", pos + 1);
		}

		if (FInput.Pos("\00368")) {
			pos = FInput.Pos("\00368");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("04", pos + 1);
		}

		if (FInput.Pos("\00384")) {
			pos = FInput.Pos("\00384");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("04", pos + 1);
		}
	}
	while (FInput.Pos("\00320") > NULL || FInput.Pos("\00336") >
		NULL || FInput.Pos("\00352") > NULL || FInput.Pos("\00368") >
		NULL || FInput.Pos("\00384") > NULL);

	do // change into mirc colorformat above 16 colors
	{
		//Application->ProcessMessages();

		if (FInput.Pos("\00321")) {
			pos = FInput.Pos("\00321");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("05", pos + 1);
		}

		if (FInput.Pos("\00337")) {
			pos = FInput.Pos("\00337");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("05", pos + 1);
		}

		if (FInput.Pos("\00353")) {
			pos = FInput.Pos("\00353");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("05", pos + 1);
		}

		if (FInput.Pos("\00369")) {
			pos = FInput.Pos("\00369");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("05", pos + 1);
		}

		if (FInput.Pos("\00385")) {
			pos = FInput.Pos("\00385");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("05", pos + 1);
		}
	}
	while (FInput.Pos("\00321") > NULL || FInput.Pos("\00337") >
		NULL || FInput.Pos("\00353") > NULL || FInput.Pos("\00369") >
		NULL || FInput.Pos("\00385") > NULL);

	do // change into mirc colorformat above 16 colors
	{
		//Application->ProcessMessages();

		if (FInput.Pos("\00322")) {
			pos = FInput.Pos("\00322");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("06", pos + 1);
		}

		if (FInput.Pos("\00338")) {
			pos = FInput.Pos("\00338");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("06", pos + 1);
		}

		if (FInput.Pos("\00354")) {
			pos = FInput.Pos("\00354");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("06", pos + 1);
		}

		if (FInput.Pos("\00370")) {
			pos = FInput.Pos("\00370");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("06", pos + 1);
		}

		if (FInput.Pos("\00386")) {
			pos = FInput.Pos("\00386");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("06", pos + 1);
		}
	}
	while (FInput.Pos("\00322") > NULL || FInput.Pos("\00338") >
		NULL || FInput.Pos("\00354") > NULL || FInput.Pos("\00370") >
		NULL || FInput.Pos("\00386") > NULL);

	do // change into mirc colorformat above 16 colors
	{
		//Application->ProcessMessages();

		if (FInput.Pos("\00323")) {
			pos = FInput.Pos("\00323");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("07", pos + 1);
		}

		if (FInput.Pos("\00339")) {
			pos = FInput.Pos("\00339");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("07", pos + 1);
		}

		if (FInput.Pos("\00355")) {
			pos = FInput.Pos("\00355");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("07", pos + 1);
		}

		if (FInput.Pos("\00371")) {
			pos = FInput.Pos("\00371");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("07", pos + 1);
		}

		if (FInput.Pos("\00387")) {
			pos = FInput.Pos("\00387");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("07", pos + 1);
		}
	}
	while (FInput.Pos("\00323") > NULL || FInput.Pos("\00339") >
		NULL || FInput.Pos("\00355") > NULL || FInput.Pos("\00371") >
		NULL || FInput.Pos("\00387") > NULL);

	do // change into mirc colorformat above 16 colors
	{
		//Application->ProcessMessages();

		if (FInput.Pos("\00324")) {
			pos = FInput.Pos("\00324");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("08", pos + 1);
		}

		if (FInput.Pos("\00340")) {
			pos = FInput.Pos("\00340");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("08", pos + 1);
		}

		if (FInput.Pos("\00356")) {
			pos = FInput.Pos("\00356");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("08", pos + 1);
		}

		if (FInput.Pos("\00372")) {
			pos = FInput.Pos("\00372");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("08", pos + 1);
		}

		if (FInput.Pos("\00388")) {
			pos = FInput.Pos("\00388");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("08", pos + 1);
		}
	}
	while (FInput.Pos("\00324") > NULL || FInput.Pos("\00340") >
		NULL || FInput.Pos("\00356") > NULL || FInput.Pos("\00372") >
		NULL || FInput.Pos("\00388") > NULL);

	do // change into mirc colorformat above 16 colors
	{
		//Application->ProcessMessages();

		if (FInput.Pos("\00325")) {
			pos = FInput.Pos("\00325");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("09", pos + 1);
		}

		if (FInput.Pos("\00341")) {
			pos = FInput.Pos("\00341");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("09", pos + 1);
		}

		if (FInput.Pos("\00357")) {
			pos = FInput.Pos("\00357");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("09", pos + 1);
		}

		if (FInput.Pos("\00373")) {
			pos = FInput.Pos("\00373");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("09", pos + 1);
		}

		if (FInput.Pos("\00389")) {
			pos = FInput.Pos("\00389");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("09", pos + 1);
		}
	}
	while (FInput.Pos("\00325") > NULL || FInput.Pos("\00341") >
		NULL || FInput.Pos("\00357") > NULL || FInput.Pos("\00373") >
		NULL || FInput.Pos("\00389") > NULL);

	do // change into mirc colorformat above 16 colors
	{
		//Application->ProcessMessages();

		if (FInput.Pos("\00326")) {
			pos = FInput.Pos("\00326");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("10", pos + 1);
		}

		if (FInput.Pos("\00342")) {
			pos = FInput.Pos("\00342");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("10", pos + 1);
		}

		if (FInput.Pos("\00358")) {
			pos = FInput.Pos("\00358");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("10", pos + 1);
		}

		if (FInput.Pos("\00374")) {
			pos = FInput.Pos("\00374");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("10", pos + 1);
		}

		if (FInput.Pos("\00390")) {
			pos = FInput.Pos("\00390");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("10", pos + 1);
		}
	}
	while (FInput.Pos("\00326") > NULL || FInput.Pos("\00342") >
		NULL || FInput.Pos("\00358") > NULL || FInput.Pos("\00374") >
		NULL || FInput.Pos("\00390") > NULL);

	do // change into mirc colorformat above 16 colors
	{
		//Application->ProcessMessages();

		if (FInput.Pos("\00327")) {
			pos = FInput.Pos("\00327");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("11", pos + 1);
		}

		if (FInput.Pos("\00343")) {
			pos = FInput.Pos("\00343");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("11", pos + 1);
		}

		if (FInput.Pos("\00359")) {
			pos = FInput.Pos("\00359");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("11", pos + 1);
		}

		if (FInput.Pos("\00375")) {
			pos = FInput.Pos("\00375");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("11", pos + 1);
		}

		if (FInput.Pos("\00391")) {
			pos = FInput.Pos("\00391");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("11", pos + 1);
		}
	}
	while (FInput.Pos("\00327") > NULL || FInput.Pos("\00343") >
		NULL || FInput.Pos("\00359") > NULL || FInput.Pos("\00375") >
		NULL || FInput.Pos("\00391") > NULL);

	do // change into mirc colorformat above 16 colors
	{
		//Application->ProcessMessages();

		if (FInput.Pos("\00328")) {
			pos = FInput.Pos("\00328");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("12", pos + 1);
		}

		if (FInput.Pos("\00344")) {
			pos = FInput.Pos("\00344");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("12", pos + 1);
		}

		if (FInput.Pos("\00360")) {
			pos = FInput.Pos("\00360");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("12", pos + 1);
		}

		if (FInput.Pos("\00376")) {
			pos = FInput.Pos("\00376");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("12", pos + 1);
		}

		if (FInput.Pos("\00392")) {
			pos = FInput.Pos("\00392");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("12", pos + 1);
		}
	}
	while (FInput.Pos("\00328") > NULL || FInput.Pos("\00344") >
		NULL || FInput.Pos("\00360") > NULL || FInput.Pos("\00376") >
		NULL || FInput.Pos("\00392") > NULL);

	do // change into mirc colorformat above 16 colors
	{
		//Application->ProcessMessages();

		if (FInput.Pos("\00329")) {
			pos = FInput.Pos("\00329");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("13", pos + 1);
		}

		if (FInput.Pos("\00345")) {
			pos = FInput.Pos("\00345");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("13", pos + 1);
		}

		if (FInput.Pos("\00361")) {
			pos = FInput.Pos("\00361");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("13", pos + 1);
		}

		if (FInput.Pos("\00377")) {
			pos = FInput.Pos("\00377");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("13", pos + 1);
		}

		if (FInput.Pos("\00393")) {
			pos = FInput.Pos("\00393");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("13", pos + 1);
		}
	}
	while (FInput.Pos("\00329") > NULL || FInput.Pos("\00345") >
		NULL || FInput.Pos("\00361") > NULL || FInput.Pos("\00377") >
		NULL || FInput.Pos("\00393") > NULL);

	do // change into mirc colorformat above 16 colors
	{
		//Application->ProcessMessages();

		if (FInput.Pos("\00330")) {
			pos = FInput.Pos("\00330");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("14", pos + 1);
		}

		if (FInput.Pos("\00346")) {
			pos = FInput.Pos("\00346");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("14", pos + 1);
		}

		if (FInput.Pos("\00362")) {
			pos = FInput.Pos("\00362");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("14", pos + 1);
		}

		if (FInput.Pos("\00378")) {
			pos = FInput.Pos("\00378");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("14", pos + 1);
		}

		if (FInput.Pos("\00394")) {
			pos = FInput.Pos("\00394");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("14", pos + 1);
		}
	}
	while (FInput.Pos("\00330") > NULL || FInput.Pos("\00346") >
		NULL || FInput.Pos("\00362") > NULL || FInput.Pos("\00378") >
		NULL || FInput.Pos("\00394") > NULL);

	do // change into mirc colorformat above 16 colors
	{
		//Application->ProcessMessages();

		if (FInput.Pos("\00331")) {
			pos = FInput.Pos("\00331");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("15", pos + 1);
		}

		if (FInput.Pos("\00347")) {
			pos = FInput.Pos("\00347");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("15", pos + 1);
		}

		if (FInput.Pos("\00363")) {
			pos = FInput.Pos("\00363");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("15", pos + 1);
		}

		if (FInput.Pos("\00379")) {
			pos = FInput.Pos("\00379");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("15", pos + 1);
		}

		if (FInput.Pos("\00395")) {
			pos = FInput.Pos("\00395");
			FInput.Delete(pos + 1, 2);
			FInput.Insert("15", pos + 1);
		}
	}
	while (FInput.Pos("\00331") > NULL || FInput.Pos("\00347") >
		NULL || FInput.Pos("\00363") > NULL || FInput.Pos("\00379") >
		NULL || FInput.Pos("\00395") > NULL);

	do {
		//Application->ProcessMessages();

		if (FInput.Pos("\00300,00")) {
			pos = FInput.Pos("\00300,00");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00301,00")) {
			pos = FInput.Pos("\00301,00");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00302,00")) {
			pos = FInput.Pos("\00302,00");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00303,00")) {
			pos = FInput.Pos("\00303,00");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00304,00")) {
			pos = FInput.Pos("\00304,00");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00305,00")) {
			pos = FInput.Pos("\00305,00");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00306,00")) {
			pos = FInput.Pos("\00306,00");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00307,00")) {
			pos = FInput.Pos("\00307,00");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00308,00")) {
			pos = FInput.Pos("\00308,00");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00309,00")) {
			pos = FInput.Pos("\00309,00");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00310,00")) {
			pos = FInput.Pos("\00310,00");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00311,00")) {
			pos = FInput.Pos("\00311,00");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00312,00")) {
			pos = FInput.Pos("\00312,00");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00313,00")) {
			pos = FInput.Pos("\00313,00");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00314,00")) {
			pos = FInput.Pos("\00314,00");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00315,00")) {
			pos = FInput.Pos("\00315,00");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00300,01")) {
			pos = FInput.Pos("\00300,01");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00301,01")) {
			pos = FInput.Pos("\00301,01");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00302,01")) {
			pos = FInput.Pos("\00302,01");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00303,01")) {
			pos = FInput.Pos("\00303,01");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00304,01")) {
			pos = FInput.Pos("\00304,01");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00305,01")) {
			pos = FInput.Pos("\00305,01");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00306,01")) {
			pos = FInput.Pos("\00306,01");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00307,01")) {
			pos = FInput.Pos("\00307,01");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00308,01")) {
			pos = FInput.Pos("\00308,01");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00309,01")) {
			pos = FInput.Pos("\00309,01");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00310,01")) {
			pos = FInput.Pos("\00310,01");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00311,01")) {
			pos = FInput.Pos("\00311,01");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00312,01")) {
			pos = FInput.Pos("\00312,01");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00313,01")) {
			pos = FInput.Pos("\00313,01");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00314,01")) {
			pos = FInput.Pos("\00314,01");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00315,01")) {
			pos = FInput.Pos("\00315,01");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00300,02")) {
			pos = FInput.Pos("\00300,02");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00301,02")) {
			pos = FInput.Pos("\00301,02");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00302,02")) {
			pos = FInput.Pos("\00302,02");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00303,02")) {
			pos = FInput.Pos("\00303,02");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00304,02")) {
			pos = FInput.Pos("\00304,02");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00305,02")) {
			pos = FInput.Pos("\00305,02");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00306,02")) {
			pos = FInput.Pos("\00306,02");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00307,02")) {
			pos = FInput.Pos("\00307,02");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00308,02")) {
			pos = FInput.Pos("\00308,02");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00309,02")) {
			pos = FInput.Pos("\00309,02");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00310,02")) {
			pos = FInput.Pos("\00310,02");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00311,02")) {
			pos = FInput.Pos("\00311,02");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00312,02")) {
			pos = FInput.Pos("\00312,02");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00313,02")) {
			pos = FInput.Pos("\00313,02");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00314,02")) {
			pos = FInput.Pos("\00314,02");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00315,02")) {
			pos = FInput.Pos("\00315,02");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00300,03")) {
			pos = FInput.Pos("\00300,03");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00301,03")) {
			pos = FInput.Pos("\00301,03");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00302,03")) {
			pos = FInput.Pos("\00302,03");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00303,03")) {
			pos = FInput.Pos("\00303,03");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00304,03")) {
			pos = FInput.Pos("\00304,03");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00305,03")) {
			pos = FInput.Pos("\00305,03");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00306,03")) {
			pos = FInput.Pos("\00306,03");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00307,03")) {
			pos = FInput.Pos("\00307,03");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00308,03")) {
			pos = FInput.Pos("\00308,03");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00309,03")) {
			pos = FInput.Pos("\00309,03");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00310,03")) {
			pos = FInput.Pos("\00310,03");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00311,03")) {
			pos = FInput.Pos("\00311,03");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00312,03")) {
			pos = FInput.Pos("\00312,03");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00313,03")) {
			pos = FInput.Pos("\00313,03");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00314,03")) {
			pos = FInput.Pos("\00314,03");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00315,03")) {
			pos = FInput.Pos("\00315,03");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00300,04")) {
			pos = FInput.Pos("\00300,04");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00301,04")) {
			pos = FInput.Pos("\00301,04");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00302,04")) {

			pos = FInput.Pos("\00302,04");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00303,04")) {
			pos = FInput.Pos("\00303,04");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00304,04")) {
			pos = FInput.Pos("\00304,04");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00305,04")) {
			pos = FInput.Pos("\00305,04");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00306,04")) {
			pos = FInput.Pos("\00306,04");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00307,04")) {
			pos = FInput.Pos("\00307,04");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00308,04")) {
			pos = FInput.Pos("\00308,04");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00309,04")) {
			pos = FInput.Pos("\00309,04");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00310,04")) {
			pos = FInput.Pos("\00310,04");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00311,04")) {
			pos = FInput.Pos("\00311,04");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00312,04")) {
			pos = FInput.Pos("\00312,04");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00313,04")) {
			pos = FInput.Pos("\00313,04");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00314,04")) {
			pos = FInput.Pos("\00314,04");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00315,04")) {
			pos = FInput.Pos("\00315,04");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00300,05")) {
			pos = FInput.Pos("\00300,05");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00301,05")) {
			pos = FInput.Pos("\00301,05");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00302,05")) {
			pos = FInput.Pos("\00302,05");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00303,05")) {
			pos = FInput.Pos("\00303,05");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00304,05")) {
			pos = FInput.Pos("\00304,05");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00305,05")) {
			pos = FInput.Pos("\00305,05");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00306,05")) {
			pos = FInput.Pos("\00306,05");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00307,05")) {
			pos = FInput.Pos("\00307,05");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00308,05")) {
			pos = FInput.Pos("\00308,05");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00309,05")) {
			pos = FInput.Pos("\00309,05");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00310,05")) {
			pos = FInput.Pos("\00310,05");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00311,05")) {
			pos = FInput.Pos("\00311,05");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00312,05")) {
			pos = FInput.Pos("\00312,05");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00313,05")) {
			pos = FInput.Pos("\00313,05");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00314,05")) {
			pos = FInput.Pos("\00314,05");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00315,05")) {
			pos = FInput.Pos("\00315,05");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00300,06")) {
			pos = FInput.Pos("\00300,06");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00301,06")) {
			pos = FInput.Pos("\00301,06");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00302,06")) {
			pos = FInput.Pos("\00302,06");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00303,06")) {
			pos = FInput.Pos("\00303,06");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00304,06")) {
			pos = FInput.Pos("\00304,06");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00305,06")) {
			pos = FInput.Pos("\00305,06");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00306,06")) {
			pos = FInput.Pos("\00306,06");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00307,06")) {
			pos = FInput.Pos("\00307,06");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00308,06")) {
			pos = FInput.Pos("\00308,06");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00309,06")) {
			pos = FInput.Pos("\00309,06");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00310,06")) {
			pos = FInput.Pos("\00310,06");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00311,06")) {
			pos = FInput.Pos("\00311,06");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00312,06")) {
			pos = FInput.Pos("\00312,06");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00313,06")) {
			pos = FInput.Pos("\00313,06");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00314,06")) {
			pos = FInput.Pos("\00314,06");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00315,06")) {
			pos = FInput.Pos("\00315,06");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00300,07")) {
			pos = FInput.Pos("\00300,07");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00301,07")) {
			pos = FInput.Pos("\00301,07");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00302,07")) {
			pos = FInput.Pos("\00302,07");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00303,07")) {
			pos = FInput.Pos("\00303,07");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00304,07")) {
			pos = FInput.Pos("\00304,07");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00305,07")) {
			pos = FInput.Pos("\00305,07");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00306,07")) {
			pos = FInput.Pos("\00306,07");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00307,07")) {
			pos = FInput.Pos("\00307,07");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00308,07")) {
			pos = FInput.Pos("\00308,07");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00309,07")) {
			pos = FInput.Pos("\00309,07");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00310,07")) {
			pos = FInput.Pos("\00310,07");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00311,07")) {
			pos = FInput.Pos("\00311,07");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00312,07")) {
			pos = FInput.Pos("\00312,07");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00313,07")) {
			pos = FInput.Pos("\00313,07");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00314,07")) {
			pos = FInput.Pos("\00314,07");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00315,07")) {
			pos = FInput.Pos("\00315,07");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00300,08")) {
			pos = FInput.Pos("\00300,08");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00301,08")) {
			pos = FInput.Pos("\00301,08");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00302,08")) {
			pos = FInput.Pos("\00302,08");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00303,08")) {
			pos = FInput.Pos("\00303,08");
			FInput.Delete(pos + 3, 3);
		}

		if(FInput.Pos("\00304,08"))
		{
		 pos = FInput.Pos("\00304,08");
		 FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00305,08")) {
			pos = FInput.Pos("\00305,08");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00306,08")) {
			pos = FInput.Pos("\00306,08");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00307,08")) {
			pos = FInput.Pos("\00307,08");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00308,08")) {
			pos = FInput.Pos("\00308,08");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00309,08")) {
			pos = FInput.Pos("\00309,08");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00310,08")) {
			pos = FInput.Pos("\00310,08");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00311,08")) {
			pos = FInput.Pos("\00311,08");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00312,08")) {
			pos = FInput.Pos("\00312,08");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00313,08")) {
			pos = FInput.Pos("\00313,08");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00314,08")) {
			pos = FInput.Pos("\00314,08");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00315,08")) {
			pos = FInput.Pos("\00315,08");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00300,09")) {
			pos = FInput.Pos("\00300,09");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00301,09")) {
			pos = FInput.Pos("\00301,09");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00302,09")) {
			pos = FInput.Pos("\00302,09");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00303,09")) {
			pos = FInput.Pos("\00303,09");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00304,09")) {
			pos = FInput.Pos("\00304,09");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00305,09")) {
			pos = FInput.Pos("\00305,09");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00306,09")) {
			pos = FInput.Pos("\00306,09");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00307,09")) {
			pos = FInput.Pos("\00307,09");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00308,09")) {
			pos = FInput.Pos("\00308,09");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00309,09")) {
			pos = FInput.Pos("\00309,09");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00310,09")) {
			pos = FInput.Pos("\00310,09");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00311,09")) {
			pos = FInput.Pos("\00311,09");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00312,09")) {
			pos = FInput.Pos("\00312,09");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00313,09")) {
			pos = FInput.Pos("\00313,09");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00314,09")) {
			pos = FInput.Pos("\00314,09");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00315,09")) {
			pos = FInput.Pos("\00315,09");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00300,10")) {
			pos = FInput.Pos("\00300,10");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00301,10")) {
			pos = FInput.Pos("\00301,10");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00302,10")) {
			pos = FInput.Pos("\00302,10");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00303,10")) {
			pos = FInput.Pos("\00303,10");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00304,10")) {
			pos = FInput.Pos("\00304,10");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00305,10")) {
			pos = FInput.Pos("\00305,10");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00306,10")) {
			pos = FInput.Pos("\00306,10");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00307,10")) {
			pos = FInput.Pos("\00307,10");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00308,10")) {
			pos = FInput.Pos("\00308,10");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00309,10")) {
			pos = FInput.Pos("\00309,10");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00310,10")) {
			pos = FInput.Pos("\00310,10");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00311,10")) {
			pos = FInput.Pos("\00311,10");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00312,10")) {
			pos = FInput.Pos("\00312,10");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00313,10")) {
			pos = FInput.Pos("\00313,10");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00314,10")) {
			pos = FInput.Pos("\00314,10");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00315,10")) {
			pos = FInput.Pos("\00315,10");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00300,11")) {
			pos = FInput.Pos("\00300,11");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00301,11")) {
			pos = FInput.Pos("\00301,11");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00302,11")) {
			pos = FInput.Pos("\00302,11");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00303,11")) {
			pos = FInput.Pos("\00303,11");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00304,11")) {
			pos = FInput.Pos("\00304,11");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00305,11")) {
			pos = FInput.Pos("\00305,11");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00306,11")) {
			pos = FInput.Pos("\00306,11");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00307,11")) {
			pos = FInput.Pos("\00307,11");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00308,11")) {
			pos = FInput.Pos("\00308,11");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00309,11")) {
			pos = FInput.Pos("\00309,11");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00310,11")) {
			pos = FInput.Pos("\00310,11");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00311,11")) {
			pos = FInput.Pos("\00311,11");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00312,11")) {
			pos = FInput.Pos("\00312,11");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00313,11")) {
			pos = FInput.Pos("\00313,11");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00314,11")) {
			pos = FInput.Pos("\00314,11");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00315,11")) {
			pos = FInput.Pos("\00315,11");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00300,12")) {
			pos = FInput.Pos("\00300,12");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00301,12")) {
			pos = FInput.Pos("\00301,12");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00302,12")) {
			pos = FInput.Pos("\00302,12");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00303,12")) {
			pos = FInput.Pos("\00303,12");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00304,12")) {
			pos = FInput.Pos("\00304,12");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00305,12")) {
			pos = FInput.Pos("\00305,12");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00306,12")) {
			pos = FInput.Pos("\00306,12");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00307,12")) {
			pos = FInput.Pos("\00307,12");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00308,12")) {
			pos = FInput.Pos("\00308,12");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00309,12")) {
			pos = FInput.Pos("\00309,12");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00310,12")) {
			pos = FInput.Pos("\00310,12");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00311,12")) {
			pos = FInput.Pos("\00311,12");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00312,12")) {
			pos = FInput.Pos("\00312,12");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00313,12")) {
			pos = FInput.Pos("\00313,12");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00314,12")) {
			pos = FInput.Pos("\00314,12");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00315,12")) {
			pos = FInput.Pos("\00315,12");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00300,13")) {
			pos = FInput.Pos("\00300,13");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00301,13")) {
			pos = FInput.Pos("\00301,13");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00302,13")) {
			pos = FInput.Pos("\00302,13");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00303,13")) {
			pos = FInput.Pos("\00303,13");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00304,13")) {
			pos = FInput.Pos("\00304,13");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00305,13")) {
			pos = FInput.Pos("\00305,13");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00306,13")) {
			pos = FInput.Pos("\00306,13");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00307,13")) {
			pos = FInput.Pos("\00307,13");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00308,13")) {
			pos = FInput.Pos("\00308,13");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00309,13")) {
			pos = FInput.Pos("\00309,13");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00310,13")) {
			pos = FInput.Pos("\00310,13");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00311,13")) {
			pos = FInput.Pos("\00311,13");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00312,13")) {
			pos = FInput.Pos("\00312,13");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00313,13")) {
			pos = FInput.Pos("\00313,13");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00314,13")) {
			pos = FInput.Pos("\00314,13");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00315,13")) {
			pos = FInput.Pos("\00315,13");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00300,14")) {
			pos = FInput.Pos("\00300,14");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00301,14")) {
			pos = FInput.Pos("\00301,14");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00302,14")) {
			pos = FInput.Pos("\00302,14");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00303,14")) {
			pos = FInput.Pos("\00303,14");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00304,14")) {
			pos = FInput.Pos("\00304,14");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00305,14")) {
			pos = FInput.Pos("\00305,14");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00306,14")) {
			pos = FInput.Pos("\00306,14");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00307,14")) {
			pos = FInput.Pos("\00307,14");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00308,14")) {
			pos = FInput.Pos("\00308,14");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00309,14")) {
			pos = FInput.Pos("\00309,14");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00310,14")) {
			pos = FInput.Pos("\00310,14");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00311,14")) {
			pos = FInput.Pos("\00311,14");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00312,14")) {
			pos = FInput.Pos("\00312,14");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00313,14")) {
			pos = FInput.Pos("\00313,14");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00314,14")) {
			pos = FInput.Pos("\00314,14");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00315,14")) {
			pos = FInput.Pos("\00315,14");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00300,15")) {
			pos = FInput.Pos("\00300,15");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00301,15")) {
			pos = FInput.Pos("\00301,15");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00302,15")) {
			pos = FInput.Pos("\00302,15");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00303,15")) {
			pos = FInput.Pos("\00303,15");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00304,15")) {
			pos = FInput.Pos("\00304,15");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00305,15")) {
			pos = FInput.Pos("\00305,15");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00306,15")) {
			pos = FInput.Pos("\00306,15");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00307,15")) {
			pos = FInput.Pos("\00307,15");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00308,15")) {
			pos = FInput.Pos("\00308,15");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00309,15")) {
			pos = FInput.Pos("\00309,15");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00310,15")) {
			pos = FInput.Pos("\00310,15");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00311,15")) {
			pos = FInput.Pos("\00311,15");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00312,15")) {
			pos = FInput.Pos("\00312,15");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00313,15")) {
			pos = FInput.Pos("\00313,15");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00314,15")) {
			pos = FInput.Pos("\00314,15");
			FInput.Delete(pos + 3, 3);
		}

		if (FInput.Pos("\00315,15")) {
			pos = FInput.Pos("\00315,15");
			FInput.Delete(pos + 3, 3);
		}
	}
	while (FInput.Pos("\00300,00") > NULL || FInput.Pos("\00301,00") >
		NULL || FInput.Pos("\00302,00") > NULL || FInput.Pos("\00303,00") >
		NULL || FInput.Pos("\00304,00") > NULL || FInput.Pos("\00305,00") >
		NULL || FInput.Pos("\00306,00") > NULL || FInput.Pos("\00307,00") >
		NULL || FInput.Pos("\00308,00") > NULL || FInput.Pos("\00309,00") >
		NULL || FInput.Pos("\00310,00") > NULL || FInput.Pos("\00311,00") >
		NULL || FInput.Pos("\00312,00") > NULL || FInput.Pos("\00313,00") >
		NULL || FInput.Pos("\00314,00") > NULL || FInput.Pos("\00315,00") >
		NULL || FInput.Pos("\00300,01") > NULL || FInput.Pos("\00301,01") >
		NULL || FInput.Pos("\00302,01") > NULL || FInput.Pos("\00303,01") >
		NULL || FInput.Pos("\00304,01") > NULL || FInput.Pos("\00305,01") >
		NULL || FInput.Pos("\00306,01") > NULL || FInput.Pos("\00307,01") >
		NULL || FInput.Pos("\00308,01") > NULL || FInput.Pos("\00309,01") >
		NULL || FInput.Pos("\00310,01") > NULL || FInput.Pos("\00311,01") >
		NULL || FInput.Pos("\00312,01") > NULL || FInput.Pos("\00313,01") >
		NULL || FInput.Pos("\00314,01") > NULL || FInput.Pos("\00315,01") >
		NULL || FInput.Pos("\00300,02") > NULL || FInput.Pos("\00301,02") >
		NULL || FInput.Pos("\00302,02") > NULL || FInput.Pos("\00303,02") >
		NULL || FInput.Pos("\00304,02") > NULL || FInput.Pos("\00305,02") >
		NULL || FInput.Pos("\00306,02") > NULL || FInput.Pos("\00307,02") >
		NULL || FInput.Pos("\00308,02") > NULL || FInput.Pos("\00309,02") >
		NULL || FInput.Pos("\00310,02") > NULL || FInput.Pos("\00311,02") >
		NULL || FInput.Pos("\00312,02") > NULL || FInput.Pos("\00313,02") >
		NULL || FInput.Pos("\00314,02") > NULL || FInput.Pos("\00315,02") >
		NULL || FInput.Pos("\00300,03") > NULL || FInput.Pos("\00301,03") >
		NULL || FInput.Pos("\00302,03") > NULL || FInput.Pos("\00303,03") >
		NULL || FInput.Pos("\00304,03") > NULL || FInput.Pos("\00305,03") >
		NULL || FInput.Pos("\00306,03") > NULL || FInput.Pos("\00307,03") >
		NULL || FInput.Pos("\00308,03") > NULL || FInput.Pos("\00309,03") >
		NULL || FInput.Pos("\00310,03") > NULL || FInput.Pos("\00311,03") >
		NULL || FInput.Pos("\00312,03") > NULL || FInput.Pos("\00313,03") >
		NULL || FInput.Pos("\00314,03") > NULL || FInput.Pos("\00315,03") >
		NULL || FInput.Pos("\00300,04") > NULL || FInput.Pos("\00301,04") >
		NULL || FInput.Pos("\00302,04") > NULL || FInput.Pos("\00303,04") >
		NULL || FInput.Pos("\00304,04") > NULL || FInput.Pos("\00305,04") >
		NULL || FInput.Pos("\00306,04") > NULL || FInput.Pos("\00307,04") >
		NULL || FInput.Pos("\00308,04") > NULL || FInput.Pos("\00309,04") >
		NULL || FInput.Pos("\00310,04") > NULL || FInput.Pos("\00311,04") >
		NULL || FInput.Pos("\00312,04") > NULL || FInput.Pos("\00313,04") >
		NULL || FInput.Pos("\00314,04") > NULL || FInput.Pos("\00315,04") >
		NULL || FInput.Pos("\00300,05") > NULL || FInput.Pos("\00301,05") >
		NULL || FInput.Pos("\00302,05") > NULL || FInput.Pos("\00303,05") >
		NULL || FInput.Pos("\00304,05") > NULL || FInput.Pos("\00305,05") >
		NULL || FInput.Pos("\00306,05") > NULL || FInput.Pos("\00307,05") >
		NULL || FInput.Pos("\00308,05") > NULL || FInput.Pos("\00309,05") >
		NULL || FInput.Pos("\00310,05") > NULL || FInput.Pos("\00311,05") >
		NULL || FInput.Pos("\00312,05") > NULL || FInput.Pos("\00313,05") >
		NULL || FInput.Pos("\00314,05") > NULL || FInput.Pos("\00315,05") >
		NULL || FInput.Pos("\00300,06") > NULL || FInput.Pos("\00301,06") >
		NULL || FInput.Pos("\00302,06") > NULL || FInput.Pos("\00303,06") >
		NULL || FInput.Pos("\00304,06") > NULL || FInput.Pos("\00305,06") >
		NULL || FInput.Pos("\00306,06") > NULL || FInput.Pos("\00307,06") >
		NULL || FInput.Pos("\00308,06") > NULL || FInput.Pos("\00309,06") >
		NULL || FInput.Pos("\00310,06") > NULL || FInput.Pos("\00311,06") >
		NULL || FInput.Pos("\00312,06") > NULL || FInput.Pos("\00313,06") >
		NULL || FInput.Pos("\00314,06") > NULL || FInput.Pos("\00315,06") >
		NULL || FInput.Pos("\00300,07") > NULL || FInput.Pos("\00301,07") >
		NULL || FInput.Pos("\00302,07") > NULL || FInput.Pos("\00303,07") >
		NULL || FInput.Pos("\00304,07") > NULL || FInput.Pos("\00305,07") >
		NULL || FInput.Pos("\00306,07") > NULL || FInput.Pos("\00307,07") >
		NULL || FInput.Pos("\00308,07") > NULL || FInput.Pos("\00309,07") >
		NULL || FInput.Pos("\00310,07") > NULL || FInput.Pos("\00311,07") >
		NULL || FInput.Pos("\00312,07") > NULL || FInput.Pos("\00313,07") >
		NULL || FInput.Pos("\00314,07") > NULL || FInput.Pos("\00315,07") >
		NULL || FInput.Pos("\00300,08") > NULL || FInput.Pos("\00301,08") >
		NULL || FInput.Pos("\00302,08") > NULL || FInput.Pos("\00303,08") >
		NULL || FInput.Pos("\00304,08") > NULL || FInput.Pos("\00305,08") >
		NULL || FInput.Pos("\00306,08") > NULL || FInput.Pos("\00307,08") >
		NULL || FInput.Pos("\00308,08") > NULL || FInput.Pos("\00309,08") >
		NULL || FInput.Pos("\00310,08") > NULL || FInput.Pos("\00311,08") >
		NULL || FInput.Pos("\00312,08") > NULL || FInput.Pos("\00313,08") >
		NULL || FInput.Pos("\00314,08") > NULL || FInput.Pos("\00315,08") >
		NULL || FInput.Pos("\00300,09") > NULL || FInput.Pos("\00301,09") >
		NULL || FInput.Pos("\00302,09") > NULL || FInput.Pos("\00303,09") >
		NULL || FInput.Pos("\00304,09") > NULL || FInput.Pos("\00305,09") >
		NULL || FInput.Pos("\00306,09") > NULL || FInput.Pos("\00307,09") >
		NULL || FInput.Pos("\00308,09") > NULL || FInput.Pos("\00309,09") >
		NULL || FInput.Pos("\00310,09") > NULL || FInput.Pos("\00311,09") >
		NULL || FInput.Pos("\00312,09") > NULL || FInput.Pos("\00313,09") >
		NULL || FInput.Pos("\00314,09") > NULL || FInput.Pos("\00315,09") >
		NULL || FInput.Pos("\00300,10") > NULL || FInput.Pos("\00301,10") >
		NULL || FInput.Pos("\00302,10") > NULL || FInput.Pos("\00303,10") >
		NULL || FInput.Pos("\00304,10") > NULL || FInput.Pos("\00305,10") >
		NULL || FInput.Pos("\00306,10") > NULL || FInput.Pos("\00307,10") >
		NULL || FInput.Pos("\00308,10") > NULL || FInput.Pos("\00309,10") >
		NULL || FInput.Pos("\00310,10") > NULL || FInput.Pos("\00311,10") >
		NULL || FInput.Pos("\00312,10") > NULL || FInput.Pos("\00313,10") >
		NULL || FInput.Pos("\00314,10") > NULL || FInput.Pos("\00315,10") >
		NULL || FInput.Pos("\00300,11") > NULL || FInput.Pos("\00301,11") >
		NULL || FInput.Pos("\00302,11") > NULL || FInput.Pos("\00303,11") >
		NULL || FInput.Pos("\00304,11") > NULL || FInput.Pos("\00305,11") >
		NULL || FInput.Pos("\00306,11") > NULL || FInput.Pos("\00307,11") >
		NULL || FInput.Pos("\00308,11") > NULL || FInput.Pos("\00309,11") >
		NULL || FInput.Pos("\00310,11") > NULL || FInput.Pos("\00311,11") >
		NULL || FInput.Pos("\00312,11") > NULL || FInput.Pos("\00313,11") >
		NULL || FInput.Pos("\00314,11") > NULL || FInput.Pos("\00315,11") >
		NULL || FInput.Pos("\00300,12") > NULL || FInput.Pos("\00301,12") >
		NULL || FInput.Pos("\00302,12") > NULL || FInput.Pos("\00303,12") >
		NULL || FInput.Pos("\00304,12") > NULL || FInput.Pos("\00305,12") >
		NULL || FInput.Pos("\00306,12") > NULL || FInput.Pos("\00307,12") >
		NULL || FInput.Pos("\00308,12") > NULL || FInput.Pos("\00309,12") >
		NULL || FInput.Pos("\00310,12") > NULL || FInput.Pos("\00311,12") >
		NULL || FInput.Pos("\00312,12") > NULL || FInput.Pos("\00313,12") >
		NULL || FInput.Pos("\00314,12") > NULL || FInput.Pos("\00315,12") >
		NULL || FInput.Pos("\00300,13") > NULL || FInput.Pos("\00301,13") >
		NULL || FInput.Pos("\00302,13") > NULL || FInput.Pos("\00303,13") >
		NULL || FInput.Pos("\00304,13") > NULL || FInput.Pos("\00305,13") >
		NULL || FInput.Pos("\00306,13") > NULL || FInput.Pos("\00307,13") >
		NULL || FInput.Pos("\00308,13") > NULL || FInput.Pos("\00309,13") >
		NULL || FInput.Pos("\00310,13") > NULL || FInput.Pos("\00311,13") >
		NULL || FInput.Pos("\00312,13") > NULL || FInput.Pos("\00313,13") >
		NULL || FInput.Pos("\00314,13") > NULL || FInput.Pos("\00315,13") >
		NULL || FInput.Pos("\00300,14") > NULL || FInput.Pos("\00301,14") >
		NULL || FInput.Pos("\00302,14") > NULL || FInput.Pos("\00303,14") >
		NULL || FInput.Pos("\00304,14") > NULL || FInput.Pos("\00305,14") >
		NULL || FInput.Pos("\00306,14") > NULL || FInput.Pos("\00307,14") >
		NULL || FInput.Pos("\00308,14") > NULL || FInput.Pos("\00309,14") >
		NULL || FInput.Pos("\00310,14") > NULL || FInput.Pos("\00311,14") >
		NULL || FInput.Pos("\00312,14") > NULL || FInput.Pos("\00313,14") >
		NULL || FInput.Pos("\00314,14") > NULL || FInput.Pos("\00315,14") >
		NULL || FInput.Pos("\00300,15") > NULL || FInput.Pos("\00301,15") >
		NULL || FInput.Pos("\00302,15") > NULL || FInput.Pos("\00303,15") >
		NULL || FInput.Pos("\00304,15") > NULL || FInput.Pos("\00305,15") >
		NULL || FInput.Pos("\00306,15") > NULL || FInput.Pos("\00307,15") >
		NULL || FInput.Pos("\00308,15") > NULL || FInput.Pos("\00309,15") >
		NULL || FInput.Pos("\00310,15") > NULL || FInput.Pos("\00311,15") >
		NULL || FInput.Pos("\00312,15") > NULL || FInput.Pos("\00313,15") >
		NULL || FInput.Pos("\00314,15") > NULL || FInput.Pos("\00315,15") >
		NULL);

	// removing colors
	do {
		//Application->ProcessMessages();

		if (FInput.Pos("\00300,0")) {
			pos = FInput.Pos("\00300,0");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00301,0")) {
			pos = FInput.Pos("\00301,0");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00302,0")) {
			pos = FInput.Pos("\00302,0");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00303,0")) {
			pos = FInput.Pos("\00303,0");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00304,0")) {
			pos = FInput.Pos("\00304,0");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00305,0")) {
			pos = FInput.Pos("\00305,0");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00306,0")) {
			pos = FInput.Pos("\00306,0");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00307,0")) {
			pos = FInput.Pos("\00307,0");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00308,0")) {
			pos = FInput.Pos("\00308,0");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00309,0")) {
			pos = FInput.Pos("\00309,0");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00310,0")) {
			pos = FInput.Pos("\00310,0");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00311,0")) {
			pos = FInput.Pos("\00311,0");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00312,0")) {
			pos = FInput.Pos("\00312,0");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00313,0")) {
			pos = FInput.Pos("\00313,0");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00314,0")) {
			pos = FInput.Pos("\00314,0");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00315,0")) {
			pos = FInput.Pos("\00315,0");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00300,1")) {
			pos = FInput.Pos("\00300,1");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00301,1")) {
			pos = FInput.Pos("\00301,1");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00302,1")) {
			pos = FInput.Pos("\00302,1");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00303,1")) {
			pos = FInput.Pos("\00303,1");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00304,1")) {
			pos = FInput.Pos("\00304,1");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00305,1")) {
			pos = FInput.Pos("\00305,1");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00306,1")) {
			pos = FInput.Pos("\00306,1");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00307,1")) {
			pos = FInput.Pos("\00307,1");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00308,1")) {
			pos = FInput.Pos("\00308,1");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00309,1")) {
			pos = FInput.Pos("\00309,1");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00310,1")) {
			pos = FInput.Pos("\00310,1");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00311,1")) {
			pos = FInput.Pos("\00311,1");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00312,1")) {
			pos = FInput.Pos("\00312,1");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00313,1")) {
			pos = FInput.Pos("\00313,1");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00314,1")) {
			pos = FInput.Pos("\00314,1");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00315,1")) {
			pos = FInput.Pos("\00315,1");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00300,2")) {
			pos = FInput.Pos("\00300,2");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00301,2")) {
			pos = FInput.Pos("\00301,2");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00302,2")) {
			pos = FInput.Pos("\00302,2");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00303,2")) {
			pos = FInput.Pos("\00303,2");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00304,2")) {
			pos = FInput.Pos("\00304,2");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00305,2")) {
			pos = FInput.Pos("\00305,2");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00306,2")) {
			pos = FInput.Pos("\00306,2");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00307,2")) {
			pos = FInput.Pos("\00307,2");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00308,2")) {
			pos = FInput.Pos("\00308,2");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00309,2")) {
			pos = FInput.Pos("\00309,2");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00310,2")) {
			pos = FInput.Pos("\00310,2");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00311,2")) {
			pos = FInput.Pos("\00311,2");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00312,2")) {
			pos = FInput.Pos("\00312,2");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00313,2")) {
			pos = FInput.Pos("\00313,2");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00314,2")) {
			pos = FInput.Pos("\00314,2");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00315,2")) {
			pos = FInput.Pos("\00315,2");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00300,3")) {
			pos = FInput.Pos("\00300,3");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00301,3")) {
			pos = FInput.Pos("\00301,3");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00302,3")) {
			pos = FInput.Pos("\00302,3");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00303,3")) {
			pos = FInput.Pos("\00303,3");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00304,3")) {
			pos = FInput.Pos("\00304,3");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00305,3")) {
			pos = FInput.Pos("\00305,3");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00306,3")) {
			pos = FInput.Pos("\00306,3");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00307,3")) {
			pos = FInput.Pos("\00307,3");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00308,3")) {
			pos = FInput.Pos("\00308,3");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00309,3")) {
			pos = FInput.Pos("\00309,3");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00310,3")) {
			pos = FInput.Pos("\00310,3");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00311,3")) {
			pos = FInput.Pos("\00311,3");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00312,3")) {
			pos = FInput.Pos("\00312,3");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00313,3")) {
			pos = FInput.Pos("\00313,3");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00314,3")) {
			pos = FInput.Pos("\00314,3");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00315,3")) {
			pos = FInput.Pos("\00315,3");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00300,4")) {
			pos = FInput.Pos("\00300,4");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00301,4")) {
			pos = FInput.Pos("\00301,4");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00302,4")) {
			pos = FInput.Pos("\00302,4");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00303,4")) {
			pos = FInput.Pos("\00303,4");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00304,4")) {
			pos = FInput.Pos("\00304,4");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00305,4")) {
			pos = FInput.Pos("\00305,4");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00306,4")) {
			pos = FInput.Pos("\00306,4");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00307,4")) {
			pos = FInput.Pos("\00307,4");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00308,4")) {
			pos = FInput.Pos("\00308,4");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00309,4")) {
			pos = FInput.Pos("\00309,4");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00310,4")) {
			pos = FInput.Pos("\00310,4");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00311,4")) {
			pos = FInput.Pos("\00311,4");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00312,4")) {
			pos = FInput.Pos("\00312,4");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00313,4")) {
			pos = FInput.Pos("\00313,4");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00314,4")) {
			pos = FInput.Pos("\00314,4");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00315,4")) {
			pos = FInput.Pos("\00315,4");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00300,5")) {
			pos = FInput.Pos("\00300,5");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00301,5")) {
			pos = FInput.Pos("\00301,5");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00302,5")) {
			pos = FInput.Pos("\00302,5");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00303,5")) {
			pos = FInput.Pos("\00303,5");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00304,5")) {
			pos = FInput.Pos("\00304,5");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00305,5")) {
			pos = FInput.Pos("\00305,5");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00306,5")) {
			pos = FInput.Pos("\00306,5");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00307,5")) {
			pos = FInput.Pos("\00307,5");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00308,5")) {
			pos = FInput.Pos("\00308,5");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00309,5")) {
			pos = FInput.Pos("\00309,5");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00310,5")) {
			pos = FInput.Pos("\00310,5");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00311,5")) {
			pos = FInput.Pos("\00311,5");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00312,5")) {
			pos = FInput.Pos("\00312,5");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00313,5")) {
			pos = FInput.Pos("\00313,5");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00314,5")) {
			pos = FInput.Pos("\00314,5");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00315,5")) {
			pos = FInput.Pos("\00315,5");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00300,6")) {
			pos = FInput.Pos("\00300,6");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00301,6")) {
			pos = FInput.Pos("\00301,6");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00302,6")) {
			pos = FInput.Pos("\00302,6");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00303,6")) {
			pos = FInput.Pos("\00303,6");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00304,6")) {
			pos = FInput.Pos("\00304,6");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00305,6")) {
			pos = FInput.Pos("\00305,6");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00306,6")) {
			pos = FInput.Pos("\00306,6");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00307,6")) {
			pos = FInput.Pos("\00307,6");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00308,6")) {
			pos = FInput.Pos("\00308,6");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00309,6")) {
			pos = FInput.Pos("\00309,6");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00310,6")) {
			pos = FInput.Pos("\00310,6");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00311,6")) {
			pos = FInput.Pos("\00311,6");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00312,6")) {
			pos = FInput.Pos("\00312,6");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00313,6")) {
			pos = FInput.Pos("\00313,6");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00314,6")) {
			pos = FInput.Pos("\00314,6");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00315,6")) {
			pos = FInput.Pos("\00315,6");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00300,7")) {
			pos = FInput.Pos("\00300,7");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00301,7")) {
			pos = FInput.Pos("\00301,7");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00302,7")) {
			pos = FInput.Pos("\00302,7");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00303,7")) {
			pos = FInput.Pos("\00303,7");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00304,7")) {
			pos = FInput.Pos("\00304,7");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00305,7")) {
			pos = FInput.Pos("\00305,7");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00306,7")) {
			pos = FInput.Pos("\00306,7");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00307,7")) {
			pos = FInput.Pos("\00307,7");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00308,7")) {
			pos = FInput.Pos("\00308,7");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00309,7")) {
			pos = FInput.Pos("\00309,7");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00310,7")) {
			pos = FInput.Pos("\00310,7");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00311,7")) {
			pos = FInput.Pos("\00311,7");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00312,7")) {
			pos = FInput.Pos("\00312,7");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00313,7")) {
			pos = FInput.Pos("\00313,7");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00314,7")) {
			pos = FInput.Pos("\00314,7");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00315,7")) {
			pos = FInput.Pos("\00315,7");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00300,8")) {
			pos = FInput.Pos("\00300,8");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00301,8")) {
			pos = FInput.Pos("\00301,8");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00302,8")) {
			pos = FInput.Pos("\00302,8");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00303,8")) {
			pos = FInput.Pos("\00303,8");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00304,8")) {
			pos = FInput.Pos("\00304,8");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00305,8")) {
			pos = FInput.Pos("\00305,8");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00306,8")) {
			pos = FInput.Pos("\00306,8");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00307,8")) {
			pos = FInput.Pos("\00307,8");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00308,8")) {
			pos = FInput.Pos("\00308,8");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00309,8")) {
			pos = FInput.Pos("\00309,8");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00310,8")) {
			pos = FInput.Pos("\00310,8");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00311,8")) {
			pos = FInput.Pos("\00311,8");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00312,8")) {
			pos = FInput.Pos("\00312,8");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00313,8")) {
			pos = FInput.Pos("\00313,8");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00314,8")) {
			pos = FInput.Pos("\00314,8");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00315,8")) {
			pos = FInput.Pos("\00315,8");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00300,9")) {
			pos = FInput.Pos("\00300,9");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00301,9")) {
			pos = FInput.Pos("\00301,9");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00302,9")) {
			pos = FInput.Pos("\00302,9");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00303,9")) {
			pos = FInput.Pos("\00303,9");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00304,9")) {
			pos = FInput.Pos("\00304,9");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00305,9")) {
			pos = FInput.Pos("\00305,9");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00306,9")) {
			pos = FInput.Pos("\00306,9");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00307,9")) {
			pos = FInput.Pos("\00307,9");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00308,9")) {
			pos = FInput.Pos("\00308,9");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00309,9")) {
			pos = FInput.Pos("\00309,9");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00310,9")) {
			pos = FInput.Pos("\00310,9");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00311,9")) {
			pos = FInput.Pos("\00311,9");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00312,9")) {
			pos = FInput.Pos("\00312,9");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00313,9")) {
			pos = FInput.Pos("\00313,9");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00314,9")) {
			pos = FInput.Pos("\00314,9");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\00315,9")) {
			pos = FInput.Pos("\00315,9");
			FInput.Delete(pos + 3, 2);
		}

		if (FInput.Pos("\0030,00")) {
			pos = FInput.Pos("\0030,00");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0031,00")) {
			pos = FInput.Pos("\0031,00");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0032,00")) {
			pos = FInput.Pos("\0032,00");
			FInput.Delete(pos + 2, 3);
		}

		if (FInput.Pos("\0033,00")) {
			pos = FInput.Pos("\0033,00");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0034,00")) {
			pos = FInput.Pos("\0034,00");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0035,00")) {
			pos = FInput.Pos("\0035,00");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0036,00")) {
			pos = FInput.Pos("\0036,00");
			FInput.Delete(pos + 2, 3);
		}

		if (FInput.Pos("\0037,00")) {
			pos = FInput.Pos("\0037,00");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0038,00")) {
			pos = FInput.Pos("\0038,00");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0039,00")) {
			pos = FInput.Pos("\0039,00");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0030,01")) {
			pos = FInput.Pos("\0030,01");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0031,01")) {
			pos = FInput.Pos("\0031,01");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0032,01")) {
			pos = FInput.Pos("\0032,01");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0033,01")) {
			pos = FInput.Pos("\0033,01");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0034,01")) {
			pos = FInput.Pos("\0034,01");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0035,01")) {
			pos = FInput.Pos("\0035,01");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0036,01")) {
			pos = FInput.Pos("\0036,01");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0037,01")) {
			pos = FInput.Pos("\0037,01");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0038,01")) {
			pos = FInput.Pos("\0038,01");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0039,01")) {
			pos = FInput.Pos("\0039,01");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0030,02")) {
			pos = FInput.Pos("\0030,02");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0031,02")) {
			pos = FInput.Pos("\0031,02");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0032,02")) {
			pos = FInput.Pos("\0032,02");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0033,02")) {
			pos = FInput.Pos("\0033,02");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0034,02")) {
			pos = FInput.Pos("\0034,02");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0035,02")) {
			pos = FInput.Pos("\0035,02");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0036,02")) {
			pos = FInput.Pos("\0036,02");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0037,02")) {
			pos = FInput.Pos("\0037,02");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0038,02")) {
			pos = FInput.Pos("\0038,02");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0039,02")) {
			pos = FInput.Pos("\0039,02");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0030,03")) {
			pos = FInput.Pos("\0030,03");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0031,03")) {
			pos = FInput.Pos("\0031,03");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0032,03")) {
			pos = FInput.Pos("\0032,03");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0033,03")) {
			pos = FInput.Pos("\0033,03");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0034,03")) {
			pos = FInput.Pos("\0034,03");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0035,03")) {
			pos = FInput.Pos("\0035,03");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0036,03")) {
			pos = FInput.Pos("\0036,03");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0037,03")) {
			pos = FInput.Pos("\0037,03");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0038,03")) {
			pos = FInput.Pos("\0038,03");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0039,03")) {
			pos = FInput.Pos("\0039,03");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0030,04")) {
			pos = FInput.Pos("\0030,04");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0031,04")) {
			pos = FInput.Pos("\0031,04");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0032,04")) {
			pos = FInput.Pos("\0032,04");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0033,04")) {
			pos = FInput.Pos("\0033,04");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0034,04")) {
			pos = FInput.Pos("\0034,04");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0035,04")) {
			pos = FInput.Pos("\0035,04");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0036,04")) {
			pos = FInput.Pos("\0036,04");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0037,04")) {
			pos = FInput.Pos("\0037,04");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0038,04")) {
			pos = FInput.Pos("\0038,04");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0039,04")) {
			pos = FInput.Pos("\0039,04");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0030,05")) {
			pos = FInput.Pos("\0030,05");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0031,05")) {
			pos = FInput.Pos("\0031,05");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0032,05")) {
			pos = FInput.Pos("\0032,05");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0033,05")) {
			pos = FInput.Pos("\0033,05");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0034,05")) {
			pos = FInput.Pos("\0034,05");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0035,05")) {
			pos = FInput.Pos("\0035,05");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0036,05")) {
			pos = FInput.Pos("\0036,05");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0037,05")) {
			pos = FInput.Pos("\0037,05");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0038,05")) {
			pos = FInput.Pos("\0038,05");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0039,05")) {
			pos = FInput.Pos("\0039,05");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0030,06")) {
			pos = FInput.Pos("\0030,06");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0031,06")) {
			pos = FInput.Pos("\0031,06");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0032,06")) {
			pos = FInput.Pos("\0032,06");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0033,06")) {
			pos = FInput.Pos("\0033,06");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0034,06")) {
			pos = FInput.Pos("\0034,06");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0035,06")) {
			pos = FInput.Pos("\0035,06");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0036,06")) {
			pos = FInput.Pos("\0036,06");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0037,06")) {
			pos = FInput.Pos("\0037,06");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0038,06")) {
			pos = FInput.Pos("\0038,06");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0039,06")) {
			pos = FInput.Pos("\0039,06");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0030,07")) {
			pos = FInput.Pos("\0030,07");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0031,07")) {
			pos = FInput.Pos("\0031,07");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0032,07")) {
			pos = FInput.Pos("\0032,07");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0033,07")) {
			pos = FInput.Pos("\0033,07");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0034,07")) {
			pos = FInput.Pos("\0034,07");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0035,07")) {
			pos = FInput.Pos("\0035,07");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0036,07")) {
			pos = FInput.Pos("\0036,07");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0037,07")) {
			pos = FInput.Pos("\0037,07");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0038,07")) {
			pos = FInput.Pos("\0038,07");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0039,07")) {
			pos = FInput.Pos("\0039,07");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0030,08")) {
			pos = FInput.Pos("\0030,08");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0031,08")) {
			pos = FInput.Pos("\0031,08");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0032,08")) {
			pos = FInput.Pos("\0032,08");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0033,08")) {
			pos = FInput.Pos("\0033,08");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0034,08")) {
			pos = FInput.Pos("\0034,08");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0035,08")) {
			pos = FInput.Pos("\0035,08");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0036,08")) {
			pos = FInput.Pos("\0036,08");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0037,08")) {
			pos = FInput.Pos("\0037,08");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0038,08")) {
			pos = FInput.Pos("\0038,08");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0039,08")) {
			pos = FInput.Pos("\0039,08");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0030,09")) {
			pos = FInput.Pos("\0030,09");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0031,09")) {
			pos = FInput.Pos("\0031,09");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0032,09")) {
			pos = FInput.Pos("\0032,09");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0033,09")) {
			pos = FInput.Pos("\0033,09");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0034,09")) {
			pos = FInput.Pos("\0034,09");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0035,09")) {
			pos = FInput.Pos("\0035,09");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0036,09")) {
			pos = FInput.Pos("\0036,09");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0037,09")) {
			pos = FInput.Pos("\0037,09");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0038,09")) {
			pos = FInput.Pos("\0038,09");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0039,09")) {
			pos = FInput.Pos("\0039,09");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0030,10")) {
			pos = FInput.Pos("\0030,10");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0031,10")) {
			pos = FInput.Pos("\0031,10");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0032,10")) {
			pos = FInput.Pos("\0032,10");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0033,10")) {
			pos = FInput.Pos("\0033,10");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0034,10")) {
			pos = FInput.Pos("\0034,10");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0035,10")) {
			pos = FInput.Pos("\0035,10");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0036,10")) {
			pos = FInput.Pos("\0036,10");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0037,10")) {
			pos = FInput.Pos("\0037,10");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0038,10")) {
			pos = FInput.Pos("\0038,10");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0039,10")) {
			pos = FInput.Pos("\0039,10");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0030,11")) {
			pos = FInput.Pos("\0030,11");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0031,11")) {
			pos = FInput.Pos("\0031,11");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0032,11")) {
			pos = FInput.Pos("\0032,11");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0033,11")) {
			pos = FInput.Pos("\0033,11");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0034,11")) {
			pos = FInput.Pos("\0034,11");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0035,11")) {
			pos = FInput.Pos("\0035,11");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0036,11")) {
			pos = FInput.Pos("\0036,11");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0037,11")) {
			pos = FInput.Pos("\0037,11");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0038,11")) {
			pos = FInput.Pos("\0038,11");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0039,11")) {
			pos = FInput.Pos("\0039,11");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0030,12")) {
			pos = FInput.Pos("\0030,12");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0031,12")) {
			pos = FInput.Pos("\0031,12");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0032,12")) {
			pos = FInput.Pos("\0032,12");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0033,12")) {
			pos = FInput.Pos("\0033,12");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0034,12")) {
			pos = FInput.Pos("\0034,12");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0035,12")) {
			pos = FInput.Pos("\0035,12");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0036,12")) {
			pos = FInput.Pos("\0036,12");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0037,12")) {
			pos = FInput.Pos("\0037,12");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0038,12")) {
			pos = FInput.Pos("\0038,12");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0039,12")) {
			pos = FInput.Pos("\0039,12");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0030,13")) {
			pos = FInput.Pos("\0030,13");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0031,13")) {
			pos = FInput.Pos("\0031,13");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0032,13")) {
			pos = FInput.Pos("\0032,13");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0033,13")) {
			pos = FInput.Pos("\0033,13");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0034,13")) {
			pos = FInput.Pos("\0034,13");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0035,13")) {
			pos = FInput.Pos("\0035,13");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0036,13")) {
			pos = FInput.Pos("\0036,13");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0037,13")) {
			pos = FInput.Pos("\0037,13");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0038,13")) {
			pos = FInput.Pos("\0038,13");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0039,13")) {
			pos = FInput.Pos("\0039,13");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0030,14")) {
			pos = FInput.Pos("\0030,14");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0031,14")) {
			pos = FInput.Pos("\0031,14");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0032,14")) {
			pos = FInput.Pos("\0032,14");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0033,14")) {
			pos = FInput.Pos("\0033,14");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0034,14")) {
			pos = FInput.Pos("\0034,14");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0035,14")) {
			pos = FInput.Pos("\0035,14");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0036,14")) {
			pos = FInput.Pos("\0036,14");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0037,14")) {
			pos = FInput.Pos("\0037,14");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0038,14")) {
			pos = FInput.Pos("\0038,14");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0039,14")) {
			pos = FInput.Pos("\0039,14");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0030,15")) {
			pos = FInput.Pos("\0030,15");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0031,15")) {
			pos = FInput.Pos("\0031,15");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0032,15")) {
			pos = FInput.Pos("\0032,15");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0033,15")) {
			pos = FInput.Pos("\0033,15");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0034,15")) {
			pos = FInput.Pos("\0034,15");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0035,15")) {
			pos = FInput.Pos("\0035,15");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0036,15")) {
			pos = FInput.Pos("\0036,15");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0037,15")) {
			pos = FInput.Pos("\0037,15");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0038,15")) {
			pos = FInput.Pos("\0038,15");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0039,15")) {
			pos = FInput.Pos("\0039,15");
			FInput.Delete(pos + 2, 3);
			FInput.Insert("0", pos + 1);
		}
	}
	while (FInput.Pos("\00300,0") > NULL || FInput.Pos("\00301,0") >
		NULL || FInput.Pos("\00302,0") > NULL || FInput.Pos("\00303,0") >
		NULL || FInput.Pos("\00304,0") > NULL || FInput.Pos("\00305,0") >
		NULL || FInput.Pos("\00306,0") > NULL || FInput.Pos("\00307,0") >
		NULL || FInput.Pos("\00308,0") > NULL || FInput.Pos("\00309,0") >
		NULL || FInput.Pos("\00310,0") > NULL || FInput.Pos("\00311,0") >
		NULL || FInput.Pos("\00312,0") > NULL || FInput.Pos("\00313,0") >
		NULL || FInput.Pos("\00314,0") > NULL || FInput.Pos("\00315,0") >
		NULL || FInput.Pos("\00300,1") > NULL || FInput.Pos("\00301,1") >
		NULL || FInput.Pos("\00302,1") > NULL || FInput.Pos("\00303,1") >
		NULL || FInput.Pos("\00304,1") > NULL || FInput.Pos("\00305,1") >
		NULL || FInput.Pos("\00306,1") > NULL || FInput.Pos("\00307,1") >
		NULL || FInput.Pos("\00308,1") > NULL || FInput.Pos("\00309,1") >
		NULL || FInput.Pos("\00310,1") > NULL || FInput.Pos("\00311,1") >
		NULL || FInput.Pos("\00312,1") > NULL || FInput.Pos("\00313,1") >
		NULL || FInput.Pos("\00314,1") > NULL || FInput.Pos("\00315,1") >
		NULL || FInput.Pos("\00300,2") > NULL || FInput.Pos("\00301,2") >
		NULL || FInput.Pos("\00302,2") > NULL || FInput.Pos("\00303,2") >
		NULL || FInput.Pos("\00304,2") > NULL || FInput.Pos("\00305,2") >
		NULL || FInput.Pos("\00306,2") > NULL || FInput.Pos("\00307,2") >
		NULL || FInput.Pos("\00308,2") > NULL || FInput.Pos("\00309,2") >
		NULL || FInput.Pos("\00310,2") > NULL || FInput.Pos("\00311,2") >
		NULL || FInput.Pos("\00312,2") > NULL || FInput.Pos("\00313,2") >
		NULL || FInput.Pos("\00314,2") > NULL || FInput.Pos("\00315,2") >
		NULL || FInput.Pos("\00300,3") > NULL || FInput.Pos("\00301,3") >
		NULL || FInput.Pos("\00302,3") > NULL || FInput.Pos("\00303,3") >
		NULL || FInput.Pos("\00304,3") > NULL || FInput.Pos("\00305,3") >
		NULL || FInput.Pos("\00306,3") > NULL || FInput.Pos("\00307,3") >
		NULL || FInput.Pos("\00308,3") > NULL || FInput.Pos("\00309,3") >
		NULL || FInput.Pos("\00310,3") > NULL || FInput.Pos("\00311,3") >
		NULL || FInput.Pos("\00312,3") > NULL || FInput.Pos("\00313,3") >
		NULL || FInput.Pos("\00314,3") > NULL || FInput.Pos("\00315,3") >
		NULL || FInput.Pos("\00300,4") > NULL || FInput.Pos("\00301,4") >
		NULL || FInput.Pos("\00302,4") > NULL || FInput.Pos("\00303,4") >
		NULL || FInput.Pos("\00304,4") > NULL || FInput.Pos("\00305,4") >
		NULL || FInput.Pos("\00306,4") > NULL || FInput.Pos("\00307,4") >
		NULL || FInput.Pos("\00308,4") > NULL || FInput.Pos("\00309,4") >
		NULL || FInput.Pos("\00310,4") > NULL || FInput.Pos("\00311,4") >
		NULL || FInput.Pos("\00312,4") > NULL || FInput.Pos("\00313,4") >
		NULL || FInput.Pos("\00314,4") > NULL || FInput.Pos("\00315,4") >
		NULL || FInput.Pos("\00300,5") > NULL || FInput.Pos("\00301,5") >
		NULL || FInput.Pos("\00302,5") > NULL || FInput.Pos("\00303,5") >
		NULL || FInput.Pos("\00304,5") > NULL || FInput.Pos("\00305,5") >
		NULL || FInput.Pos("\00306,5") > NULL || FInput.Pos("\00307,5") >
		NULL || FInput.Pos("\00308,5") > NULL || FInput.Pos("\00309,5") >
		NULL || FInput.Pos("\00310,5") > NULL || FInput.Pos("\00311,5") >
		NULL || FInput.Pos("\00312,5") > NULL || FInput.Pos("\00313,5") >
		NULL || FInput.Pos("\00314,5") > NULL || FInput.Pos("\00315,5") >
		NULL || FInput.Pos("\00300,6") > NULL || FInput.Pos("\00301,6") >
		NULL || FInput.Pos("\00302,6") > NULL || FInput.Pos("\00303,6") >
		NULL || FInput.Pos("\00304,6") > NULL || FInput.Pos("\00305,6") >
		NULL || FInput.Pos("\00306,6") > NULL || FInput.Pos("\00307,6") >
		NULL || FInput.Pos("\00308,6") > NULL || FInput.Pos("\00309,6") >
		NULL || FInput.Pos("\00310,6") > NULL || FInput.Pos("\00311,6") >
		NULL || FInput.Pos("\00312,6") > NULL || FInput.Pos("\00313,6") >
		NULL || FInput.Pos("\00314,6") > NULL || FInput.Pos("\00315,6") >
		NULL || FInput.Pos("\00300,7") > NULL || FInput.Pos("\00301,7") >
		NULL || FInput.Pos("\00302,7") > NULL || FInput.Pos("\00303,7") >
		NULL || FInput.Pos("\00304,7") > NULL || FInput.Pos("\00305,7") >
		NULL || FInput.Pos("\00306,7") > NULL || FInput.Pos("\00307,7") >
		NULL || FInput.Pos("\00308,7") > NULL || FInput.Pos("\00309,7") >
		NULL || FInput.Pos("\00310,7") > NULL || FInput.Pos("\00311,7") >
		NULL || FInput.Pos("\00312,7") > NULL || FInput.Pos("\00313,7") >
		NULL || FInput.Pos("\00314,7") > NULL || FInput.Pos("\00315,7") >
		NULL || FInput.Pos("\00300,8") > NULL || FInput.Pos("\00301,8") >
		NULL || FInput.Pos("\00302,8") > NULL || FInput.Pos("\00303,8") >
		NULL || FInput.Pos("\00304,8") > NULL || FInput.Pos("\00305,8") >
		NULL || FInput.Pos("\00306,8") > NULL || FInput.Pos("\00307,8") >
		NULL || FInput.Pos("\00308,8") > NULL || FInput.Pos("\00309,8") >
		NULL || FInput.Pos("\00310,8") > NULL || FInput.Pos("\00311,8") >
		NULL || FInput.Pos("\00312,8") > NULL || FInput.Pos("\00313,8") >
		NULL || FInput.Pos("\00314,8") > NULL || FInput.Pos("\00315,8") >
		NULL || FInput.Pos("\00300,9") > NULL || FInput.Pos("\00301,9") >
		NULL || FInput.Pos("\00302,9") > NULL || FInput.Pos("\00303,9") >
		NULL || FInput.Pos("\00304,9") > NULL || FInput.Pos("\00305,9") >
		NULL || FInput.Pos("\00306,9") > NULL || FInput.Pos("\00307,9") >
		NULL || FInput.Pos("\00308,9") > NULL || FInput.Pos("\00309,9") >
		NULL || FInput.Pos("\00310,9") > NULL || FInput.Pos("\00311,9") >
		NULL || FInput.Pos("\00312,9") > NULL || FInput.Pos("\00313,9") >
		NULL || FInput.Pos("\00314,9") > NULL || FInput.Pos("\00315,9") >
		NULL || FInput.Pos("\0030,00") > NULL || FInput.Pos("\0031,00") >
		NULL || FInput.Pos("\0032,00") > NULL || FInput.Pos("\0033,00") >
		NULL || FInput.Pos("\0034,00") > NULL || FInput.Pos("\0035,00") >
		NULL || FInput.Pos("\0036,00") > NULL || FInput.Pos("\0037,00") >
		NULL || FInput.Pos("\0038,00") > NULL || FInput.Pos("\0039,00") >
		NULL || FInput.Pos("\0030,01") > NULL || FInput.Pos("\0031,01") >
		NULL || FInput.Pos("\0032,01") > NULL || FInput.Pos("\0033,01") >
		NULL || FInput.Pos("\0034,01") > NULL || FInput.Pos("\0035,01") >
		NULL || FInput.Pos("\0036,01") > NULL || FInput.Pos("\0037,01") >
		NULL || FInput.Pos("\0038,01") > NULL || FInput.Pos("\0039,01") >
		NULL || FInput.Pos("\0030,02") > NULL || FInput.Pos("\0031,02") >
		NULL || FInput.Pos("\0032,02") > NULL || FInput.Pos("\0033,02") >
		NULL || FInput.Pos("\0034,02") > NULL || FInput.Pos("\0035,02") >
		NULL || FInput.Pos("\0036,02") > NULL || FInput.Pos("\0037,02") >
		NULL || FInput.Pos("\0038,02") > NULL || FInput.Pos("\0039,02") >
		NULL || FInput.Pos("\0030,03") > NULL || FInput.Pos("\0031,03") >
		NULL || FInput.Pos("\0032,03") > NULL || FInput.Pos("\0033,03") >
		NULL || FInput.Pos("\0034,03") > NULL || FInput.Pos("\0035,03") >
		NULL || FInput.Pos("\0036,03") > NULL || FInput.Pos("\0037,03") >
		NULL || FInput.Pos("\0038,03") > NULL || FInput.Pos("\0039,03") >
		NULL || FInput.Pos("\0030,04") > NULL || FInput.Pos("\0031,04") >
		NULL || FInput.Pos("\0032,04") > NULL || FInput.Pos("\0033,04") >
		NULL || FInput.Pos("\0034,04") > NULL || FInput.Pos("\0035,04") >
		NULL || FInput.Pos("\0036,04") > NULL || FInput.Pos("\0037,04") >
		NULL || FInput.Pos("\0038,04") > NULL || FInput.Pos("\0039,04") >
		NULL || FInput.Pos("\0030,05") > NULL || FInput.Pos("\0031,05") >
		NULL || FInput.Pos("\0032,05") > NULL || FInput.Pos("\0033,05") >
		NULL || FInput.Pos("\0034,05") > NULL || FInput.Pos("\0035,05") >
		NULL || FInput.Pos("\0036,05") > NULL || FInput.Pos("\0037,05") >
		NULL || FInput.Pos("\0038,05") > NULL || FInput.Pos("\0039,05") >
		NULL || FInput.Pos("\0030,06") > NULL || FInput.Pos("\0031,06") >
		NULL || FInput.Pos("\0032,06") > NULL || FInput.Pos("\0033,06") >
		NULL || FInput.Pos("\0034,06") > NULL || FInput.Pos("\0035,06") >
		NULL || FInput.Pos("\0036,06") > NULL || FInput.Pos("\0037,06") >
		NULL || FInput.Pos("\0038,06") > NULL || FInput.Pos("\0039,06") >
		NULL || FInput.Pos("\0030,07") > NULL || FInput.Pos("\0031,07") >
		NULL || FInput.Pos("\0032,07") > NULL || FInput.Pos("\0033,07") >
		NULL || FInput.Pos("\0034,07") > NULL || FInput.Pos("\0035,07") >
		NULL || FInput.Pos("\0036,07") > NULL || FInput.Pos("\0037,07") >
		NULL || FInput.Pos("\0038,07") > NULL || FInput.Pos("\0039,07") >
		NULL || FInput.Pos("\0030,08") > NULL || FInput.Pos("\0031,08") >
		NULL || FInput.Pos("\0032,08") > NULL || FInput.Pos("\0033,08") >
		NULL || FInput.Pos("\0034,08") > NULL || FInput.Pos("\0035,08") >
		NULL || FInput.Pos("\0036,08") > NULL || FInput.Pos("\0037,08") >
		NULL || FInput.Pos("\0038,08") > NULL || FInput.Pos("\0039,08") >
		NULL || FInput.Pos("\0030,09") > NULL || FInput.Pos("\0031,09") >
		NULL || FInput.Pos("\0032,09") > NULL || FInput.Pos("\0033,09") >
		NULL || FInput.Pos("\0034,09") > NULL || FInput.Pos("\0035,09") >
		NULL || FInput.Pos("\0036,09") > NULL || FInput.Pos("\0037,09") >
		NULL || FInput.Pos("\0038,09") > NULL || FInput.Pos("\0039,09") >
		NULL || FInput.Pos("\0030,10") > NULL || FInput.Pos("\0031,10") >
		NULL || FInput.Pos("\0032,10") > NULL || FInput.Pos("\0033,10") >
		NULL || FInput.Pos("\0034,10") > NULL || FInput.Pos("\0035,10") >
		NULL || FInput.Pos("\0036,10") > NULL || FInput.Pos("\0037,10") >
		NULL || FInput.Pos("\0038,10") > NULL || FInput.Pos("\0039,10") >
		NULL || FInput.Pos("\0030,11") > NULL || FInput.Pos("\0031,11") >
		NULL || FInput.Pos("\0032,11") > NULL || FInput.Pos("\0033,11") >
		NULL || FInput.Pos("\0034,11") > NULL || FInput.Pos("\0035,11") >
		NULL || FInput.Pos("\0036,11") > NULL || FInput.Pos("\0037,11") >
		NULL || FInput.Pos("\0038,11") > NULL || FInput.Pos("\0039,11") >
		NULL || FInput.Pos("\0030,12") > NULL || FInput.Pos("\0031,12") >
		NULL || FInput.Pos("\0032,12") > NULL || FInput.Pos("\0033,12") >
		NULL || FInput.Pos("\0034,12") > NULL || FInput.Pos("\0035,12") >
		NULL || FInput.Pos("\0036,12") > NULL || FInput.Pos("\0037,12") >
		NULL || FInput.Pos("\0038,12") > NULL || FInput.Pos("\0039,12") >
		NULL || FInput.Pos("\0030,13") > NULL || FInput.Pos("\0031,13") >
		NULL || FInput.Pos("\0032,13") > NULL || FInput.Pos("\0033,13") >
		NULL || FInput.Pos("\0034,13") > NULL || FInput.Pos("\0035,13") >
		NULL || FInput.Pos("\0036,13") > NULL || FInput.Pos("\0037,13") >
		NULL || FInput.Pos("\0038,13") > NULL || FInput.Pos("\0039,13") >
		NULL || FInput.Pos("\0030,14") > NULL || FInput.Pos("\0031,14") >
		NULL || FInput.Pos("\0032,14") > NULL || FInput.Pos("\0033,14") >
		NULL || FInput.Pos("\0034,14") > NULL || FInput.Pos("\0035,14") >
		NULL || FInput.Pos("\0036,14") > NULL || FInput.Pos("\0037,14") >
		NULL || FInput.Pos("\0038,14") > NULL || FInput.Pos("\0039,14") >
		NULL || FInput.Pos("\0030,15") > NULL || FInput.Pos("\0031,15") >
		NULL || FInput.Pos("\0032,15") > NULL || FInput.Pos("\0033,15") >
		NULL || FInput.Pos("\0034,15") > NULL || FInput.Pos("\0035,15") >
		NULL || FInput.Pos("\0036,15") > NULL || FInput.Pos("\0037,15") >
		NULL || FInput.Pos("\0038,15") > NULL || FInput.Pos("\0039,15") >
		NULL);

	// removing colors
	do
	{
		//Application->ProcessMessages();

		if(FInput.Pos("\0030,0"))
		{
		 pos = FInput.Pos("\0030,0");
		 FInput.Delete(pos + 2, 2);
		 FInput.Insert("0", pos + 1); // make it to \00300
		}

		if(FInput.Pos("\0031,0"))
		{
		 pos = FInput.Pos("\0031,0");
		 FInput.Delete(pos + 2, 2);
		 FInput.Insert("0", pos + 1); // make it to \00301
		}

		if(FInput.Pos("\0032,0"))
		{
		 pos = FInput.Pos("\0032,0");
		 FInput.Delete(pos + 2, 2);
		 FInput.Insert("0", pos + 1);
		}

		if(FInput.Pos("\0033,0"))
		{
		 pos = FInput.Pos("\0033,0");
		 FInput.Delete(pos + 2, 2);
		 FInput.Insert("0", pos + 1);
		}

		if(FInput.Pos("\0034,0"))
		{
		 pos = FInput.Pos("\0034,0");
		 FInput.Delete(pos + 2, 2);
		 FInput.Insert("0", pos + 1);
		}

		if(FInput.Pos("\0035,0"))
		{
		 pos = FInput.Pos("\0035,0");
		 FInput.Delete(pos + 2, 2);
		 FInput.Insert("0", pos + 1);
		}

		if(FInput.Pos("\0036,0"))
		{
		 pos = FInput.Pos("\0036,0");
		 FInput.Delete(pos + 2, 2);
		 FInput.Insert("0", pos + 1);
		}

		if(FInput.Pos("\0037,0"))
		{
		 pos = FInput.Pos("\0037,0");
		 FInput.Delete(pos + 2, 2);
		 FInput.Insert("0", pos + 1);
		}

		if(FInput.Pos("\0038,0"))
		{
		 pos = FInput.Pos("\0038,0");
		 FInput.Delete(pos + 2, 2);
		 FInput.Insert("0", pos + 1);
		}

		if(FInput.Pos("\0039,0"))
		{
		 pos = FInput.Pos("\0039,0");
		 FInput.Delete(pos + 2, 2);
		 FInput.Insert("0", pos + 1);
		}

		if(FInput.Pos("\0030,1"))
		{
		 pos = FInput.Pos("\0030,1");
		 FInput.Delete(pos + 2, 2);
		 FInput.Insert("0", pos + 1);
		}

		if(FInput.Pos("\0031,1"))
		{
		 pos = FInput.Pos("\0031,1");
		 FInput.Delete(pos + 2, 2);
		 FInput.Insert("0", pos + 1);
		}

		if(FInput.Pos("\0032,1"))
		{
		 pos = FInput.Pos("\0032,1");
		 FInput.Delete(pos + 2, 2);
		 FInput.Insert("0", pos + 1);
		}

		if(FInput.Pos("\0033,1"))
		{
		 pos = FInput.Pos("\0033,1");
		 FInput.Delete(pos + 2, 2);
		 FInput.Insert("0", pos + 1);
		}

		if(FInput.Pos("\0034,1"))
		{
		 pos = FInput.Pos("\0034,1");
		 FInput.Delete(pos + 2, 2);
		 FInput.Insert("0", pos + 1);
		}

		if(FInput.Pos("\0035,1"))
		{
		 pos = FInput.Pos("\0035,1");
		 FInput.Delete(pos + 2, 2);
		 FInput.Insert("0", pos + 1);
		}

		if(FInput.Pos("\0036,1"))
		{
		 pos = FInput.Pos("\0036,1");
		 FInput.Delete(pos + 2, 2);
		 FInput.Insert("0", pos + 1);
		}

		if(FInput.Pos("\0037,1"))
		{
		 pos = FInput.Pos("\0037,1");
		 FInput.Delete(pos + 2, 2);
		 FInput.Insert("0", pos + 1);
		}

		if(FInput.Pos("\0038,1"))
		{
		 pos = FInput.Pos("\0038,1");
		 FInput.Delete(pos + 2, 2);
		 FInput.Insert("0", pos + 1);
		}

		if(FInput.Pos("\0039,1"))
		{
		 pos = FInput.Pos("\0039,1");
		 FInput.Delete(pos + 2, 2);
		 FInput.Insert("0", pos + 1);
		}

		if(FInput.Pos("\0030,2"))
		{
		 pos = FInput.Pos("\0030,2");
		 FInput.Delete(pos + 2, 2);
		 FInput.Insert("0", pos + 2);
		}

		if(FInput.Pos("\0031,2"))
		{
		 pos = FInput.Pos("\0031,2");
		 FInput.Delete(pos + 2, 2);
		 FInput.Insert("0", pos + 1);
		}

		if(FInput.Pos("\0032,2"))
		{
		 pos = FInput.Pos("\0032,2");
		 FInput.Delete(pos + 2, 2);
		 FInput.Insert("0", pos + 1);
		}

		if(FInput.Pos("\0033,2"))
		{
		 pos = FInput.Pos("\0033,2");
		 FInput.Delete(pos + 2, 2);
		 FInput.Insert("0", pos + 1);
		}

		if(FInput.Pos("\0034,2"))
		{
		 pos = FInput.Pos("\0034,2");
		 FInput.Delete(pos + 2, 2);
		 FInput.Insert("0", pos + 1);
		}

		if(FInput.Pos("\0035,2"))
		{
		 pos = FInput.Pos("\0035,2");
		 FInput.Delete(pos + 2, 2);
		 FInput.Insert("0", pos + 1);
		}

		if(FInput.Pos("\0036,2"))
		{
		 pos = FInput.Pos("\0036,2");
		 FInput.Delete(pos + 2, 2);
		 FInput.Insert("0", pos + 1);
		}

		if(FInput.Pos("\0037,2"))
		{
		 pos = FInput.Pos("\0037,2");
		 FInput.Delete(pos + 2, 2);
		 FInput.Insert("0", pos + 1);
		}

		if(FInput.Pos("\0038,2"))
		{
		 pos = FInput.Pos("\0038,2");
		 FInput.Delete(pos + 2, 2);
		 FInput.Insert("0", pos + 1);
		}

		if(FInput.Pos("\0039,2"))
		{
		 pos = FInput.Pos("\0039,2");
		 FInput.Delete(pos + 2, 2);
		 FInput.Insert("0", pos + 1);
		}

		if(FInput.Pos("\0030,3"))
		{
		 pos = FInput.Pos("\0030,3");
		 FInput.Delete(pos + 2, 2);
		 FInput.Insert("0", pos+1);
		}

		if (FInput.Pos("\0031,3")) {
			pos = FInput.Pos("\0031,3");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0032,3")) {
			pos = FInput.Pos("\0032,3");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0033,3")) {
			pos = FInput.Pos("\0033,3");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0034,3")) {
			pos = FInput.Pos("\0034,3");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0035,3")) {
			pos = FInput.Pos("\0035,3");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0036,3")) {
			pos = FInput.Pos("\0036,3");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0037,3")) {
			pos = FInput.Pos("\0037,3");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0038,3")) {
			pos = FInput.Pos("\0038,3");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0039,3")) {
			pos = FInput.Pos("\0039,3");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0030,4")) {
			pos = FInput.Pos("\0030,4");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0031,4")) {
			pos = FInput.Pos("\0031,4");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0032,4")) {
			pos = FInput.Pos("\0032,4");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0033,4")) {
			pos = FInput.Pos("\0033,4");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0034,4")) {
			pos = FInput.Pos("\0034,4");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0035,4")) {
			pos = FInput.Pos("\0035,4");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0036,4")) {
			pos = FInput.Pos("\0036,4");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0037,4")) {
			pos = FInput.Pos("\0037,4");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0038,4")) {
			pos = FInput.Pos("\0038,4");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0039,4")) {
			pos = FInput.Pos("\0039,4");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0030,5")) {
			pos = FInput.Pos("\0030,5");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0031,5")) {
			pos = FInput.Pos("\0031,5");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0032,5")) {
			pos = FInput.Pos("\0032,5");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0033,5")) {
			pos = FInput.Pos("\0033,5");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0034,5")) {
			pos = FInput.Pos("\0034,5");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0035,5")) {
			pos = FInput.Pos("\0035,5");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0036,5")) {
			pos = FInput.Pos("\0036,5");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0037,5")) {
			pos = FInput.Pos("\0037,5");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0038,5")) {
			pos = FInput.Pos("\0038,5");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0039,5")) {
			pos = FInput.Pos("\0039,5");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0030,6")) {
			pos = FInput.Pos("\0030,6");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0031,6")) {
			pos = FInput.Pos("\0031,6");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0032,6")) {
			pos = FInput.Pos("\0032,6");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0033,6")) {
			pos = FInput.Pos("\0033,6");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0034,6")) {
			pos = FInput.Pos("\0034,6");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0035,6")) {
			pos = FInput.Pos("\0035,6");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0036,6")) {
			pos = FInput.Pos("\0036,6");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0037,6")) {
			pos = FInput.Pos("\0037,6");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0038,6")) {
			pos = FInput.Pos("\0038,6");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0039,6")) {
			pos = FInput.Pos("\0039,6");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0030,7")) {
			pos = FInput.Pos("\0030,7");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0031,7")) {
			pos = FInput.Pos("\0031,7");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0032,7")) {
			pos = FInput.Pos("\0032,7");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0033,7")) {
			pos = FInput.Pos("\0033,7");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0034,7")) {
			pos = FInput.Pos("\0034,7");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0035,7")) {
			pos = FInput.Pos("\0035,7");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0036,7")) {
			pos = FInput.Pos("\0036,7");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0037,7")) {
			pos = FInput.Pos("\0037,7");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0038,7")) {
			pos = FInput.Pos("\0038,7");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0039,7")) {
			pos = FInput.Pos("\0039,7");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0030,8")) {
			pos = FInput.Pos("\0030,8");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0031,8")) {
			pos = FInput.Pos("\0031,8");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0032,8")) {
			pos = FInput.Pos("\0032,8");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0033,8")) {
			pos = FInput.Pos("\0033,8");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0034,8")) {
			pos = FInput.Pos("\0034,8");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0035,8")) {
			pos = FInput.Pos("\0035,8");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0036,8")) {
			pos = FInput.Pos("\0036,8");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0037,8")) {
			pos = FInput.Pos("\0037,8");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0038,8")) {
			pos = FInput.Pos("\0038,8");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0039,8")) {
			pos = FInput.Pos("\0039,8");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0030,9")) {
			pos = FInput.Pos("\0030,9");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0031,9")) {
			pos = FInput.Pos("\0031,9");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0032,9")) {
			pos = FInput.Pos("\0032,9");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0033,9")) {
			pos = FInput.Pos("\0033,9");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0034,9")) {
			pos = FInput.Pos("\0034,9");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0035,9")) {
			pos = FInput.Pos("\0035,9");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0036,9")) {
			pos = FInput.Pos("\0036,9");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0037,9")) {
			pos = FInput.Pos("\0037,9");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0038,9")) {
			pos = FInput.Pos("\0038,9");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0039,9")) {
			pos = FInput.Pos("\0039,9");
			FInput.Delete(pos + 2, 2);
			FInput.Insert("0", pos + 1);
		}
	}
	while (FInput.Pos("\0030,0") > NULL || FInput.Pos("\0031,0") >
		NULL || FInput.Pos("\0032,0") > NULL || FInput.Pos("\0033,0") >
		NULL || FInput.Pos("\0034,0") > NULL || FInput.Pos("\0035,0") >
		NULL || FInput.Pos("\0036,0") > NULL || FInput.Pos("\0037,0") >
		NULL || FInput.Pos("\0038,0") > NULL || FInput.Pos("\0039,0") >
		NULL || FInput.Pos("\0030,1") > NULL || FInput.Pos("\0031,1") >
		NULL || FInput.Pos("\0032,1") > NULL || FInput.Pos("\0033,1") >
		NULL || FInput.Pos("\0034,1") > NULL || FInput.Pos("\0035,1") >
		NULL || FInput.Pos("\0036,1") > NULL || FInput.Pos("\0037,1") >
		NULL || FInput.Pos("\0038,1") > NULL || FInput.Pos("\0039,1") >
		NULL || FInput.Pos("\0030,2") > NULL || FInput.Pos("\0031,2") >
		NULL || FInput.Pos("\0032,2") > NULL || FInput.Pos("\0033,2") >
		NULL || FInput.Pos("\0034,2") > NULL || FInput.Pos("\0035,2") >
		NULL || FInput.Pos("\0036,2") > NULL || FInput.Pos("\0037,2") >
		NULL || FInput.Pos("\0038,2") > NULL || FInput.Pos("\0039,2") >
		NULL || FInput.Pos("\0030,3") > NULL || FInput.Pos("\0031,3") >
		NULL || FInput.Pos("\0032,3") > NULL || FInput.Pos("\0033,3") >
		NULL || FInput.Pos("\0034,3") > NULL || FInput.Pos("\0035,3") >
		NULL || FInput.Pos("\0036,3") > NULL || FInput.Pos("\0037,3") >
		NULL || FInput.Pos("\0038,3") > NULL || FInput.Pos("\0039,3") >
		NULL || FInput.Pos("\0030,4") > NULL || FInput.Pos("\0031,4") >
		NULL || FInput.Pos("\0032,4") > NULL || FInput.Pos("\0033,4") >
		NULL || FInput.Pos("\0034,4") > NULL || FInput.Pos("\0035,4") >
		NULL || FInput.Pos("\0036,4") > NULL || FInput.Pos("\0037,4") >
		NULL || FInput.Pos("\0038,4") > NULL || FInput.Pos("\0039,4") >
		NULL || FInput.Pos("\0030,5") > NULL || FInput.Pos("\0031,5") >
		NULL || FInput.Pos("\0032,5") > NULL || FInput.Pos("\0033,5") >
		NULL || FInput.Pos("\0034,5") > NULL || FInput.Pos("\0035,5") >
		NULL || FInput.Pos("\0036,5") > NULL || FInput.Pos("\0037,5") >
		NULL || FInput.Pos("\0038,5") > NULL || FInput.Pos("\0039,5") >
		NULL || FInput.Pos("\0030,6") > NULL || FInput.Pos("\0031,6") >
		NULL || FInput.Pos("\0032,6") > NULL || FInput.Pos("\0033,6") >
		NULL || FInput.Pos("\0034,6") > NULL || FInput.Pos("\0035,6") >
		NULL || FInput.Pos("\0036,6") > NULL || FInput.Pos("\0037,6") >
		NULL || FInput.Pos("\0038,6") > NULL || FInput.Pos("\0039,6") >
		NULL || FInput.Pos("\0030,7") > NULL || FInput.Pos("\0031,7") >
		NULL || FInput.Pos("\0032,7") > NULL || FInput.Pos("\0033,7") >
		NULL || FInput.Pos("\0034,7") > NULL || FInput.Pos("\0035,7") >
		NULL || FInput.Pos("\0036,7") > NULL || FInput.Pos("\0037,7") >
		NULL || FInput.Pos("\0038,7") > NULL || FInput.Pos("\0039,7") >
		NULL || FInput.Pos("\0030,8") > NULL || FInput.Pos("\0031,8") >
		NULL || FInput.Pos("\0032,8") > NULL || FInput.Pos("\0033,8") >
		NULL || FInput.Pos("\0034,8") > NULL || FInput.Pos("\0035,8") >
		NULL || FInput.Pos("\0036,8") > NULL || FInput.Pos("\0037,8") >
		NULL || FInput.Pos("\0038,8") > NULL || FInput.Pos("\0039,8") >
		NULL || FInput.Pos("\0030,9") > NULL || FInput.Pos("\0031,9") >
		NULL || FInput.Pos("\0032,9") > NULL || FInput.Pos("\0033,9") >
		NULL || FInput.Pos("\0034,9") > NULL || FInput.Pos("\0035,9") >
		NULL || FInput.Pos("\0036,9") > NULL || FInput.Pos("\0037,9") >
		NULL || FInput.Pos("\0038,9") > NULL || FInput.Pos("\0039,9") >
		NULL);

	// removing doubles
	do {
		//Application->ProcessMessages();

		if (FInput.Pos("\00300\00300")) {
			pos = FInput.Pos("\00300\00300");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00301\00300")) {
			pos = FInput.Pos("\00301\00300");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00302\00300")) {
			pos = FInput.Pos("\00302\00300");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00303\00300")) {
			pos = FInput.Pos("\00303\00300");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00304\00300")) {
			pos = FInput.Pos("\00304\00300");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00305\00300")) {
			pos = FInput.Pos("\00305\00300");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00306\00300")) {
			pos = FInput.Pos("\00306\00300");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00307\00300")) {
			pos = FInput.Pos("\00307\00300");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00308\00300")) {
			pos = FInput.Pos("\00308\00300");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00309\00300")) {
			pos = FInput.Pos("\00309\00300");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00310\00300")) {
			pos = FInput.Pos("\00310\00300");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00311\00300")) {
			pos = FInput.Pos("\00311\00300");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00312\00300")) {
			pos = FInput.Pos("\00312\00300");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00313\00300")) {
			pos = FInput.Pos("\00313\00300");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00314\00300")) {
			pos = FInput.Pos("\00314\00300");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00315\00300")) {
			pos = FInput.Pos("\00315\00300");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00300\00301")) {
			pos = FInput.Pos("\00300\00301");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00301\00301")) {
			pos = FInput.Pos("\00301\00301");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00302\00301")) {
			pos = FInput.Pos("\00302\00301");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00303\00301")) {
			pos = FInput.Pos("\00303\00301");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00304\00301")) {
			pos = FInput.Pos("\00304\00301");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00305\00301")) {
			pos = FInput.Pos("\00305\00301");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00306\00301")) {
			pos = FInput.Pos("\00306\00301");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00307\00301")) {
			pos = FInput.Pos("\00307\00301");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00308\00301")) {
			pos = FInput.Pos("\00308\00301");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00309\00301")) {
			pos = FInput.Pos("\00309\00301");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00310\00301")) {
			pos = FInput.Pos("\00310\00301");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00311\00301")) {
			pos = FInput.Pos("\00311\00301");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00312\00301")) {
			pos = FInput.Pos("\00312\00301");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00313\00301")) {
			pos = FInput.Pos("\00313\00301");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00314\00301")) {
			pos = FInput.Pos("\00314\00301");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00315\00301")) {
			pos = FInput.Pos("\00315\00301");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00300\00302")) {
			pos = FInput.Pos("\00300\00302");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00301\00302")) {
			pos = FInput.Pos("\00301\00302");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00302\00302")) {
			pos = FInput.Pos("\00302\00302");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00303\00302")) {
			pos = FInput.Pos("\00303\00302");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00304\00302")) {
			pos = FInput.Pos("\00304\00302");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00305\00302")) {
			pos = FInput.Pos("\00305\00302");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00306\00302")) {
			pos = FInput.Pos("\00306\00302");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00307\00302")) {
			pos = FInput.Pos("\00307\00302");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00308\00302")) {
			pos = FInput.Pos("\00308\00302");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00309\00302")) {
			pos = FInput.Pos("\00309\00302");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00310\00302")) {
			pos = FInput.Pos("\00310\00302");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00311\00302")) {
			pos = FInput.Pos("\00311\00302");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00312\00302")) {
			pos = FInput.Pos("\00312\00302");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00313\00302")) {
			pos = FInput.Pos("\00313\00302");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00314\00302")) {
			pos = FInput.Pos("\00314\00302");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00315\00302")) {
			pos = FInput.Pos("\00315\00302");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00300\00303")) {
			pos = FInput.Pos("\00300\00303");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00301\00303")) {
			pos = FInput.Pos("\00301\00303");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00302\00303")) {
			pos = FInput.Pos("\00302\00303");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00303\00303")) {
			pos = FInput.Pos("\00303\00303");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00304\00303")) {
			pos = FInput.Pos("\00304\00303");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00305\00303")) {
			pos = FInput.Pos("\00305\00303");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00306\00303")) {
			pos = FInput.Pos("\00306\00303");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00307\00303")) {
			pos = FInput.Pos("\00307\00303");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00308\00303")) {
			pos = FInput.Pos("\00308\00303");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00309\00303")) {
			pos = FInput.Pos("\00309\00303");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00310\00303")) {
			pos = FInput.Pos("\00310\00303");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00311\00303")) {
			pos = FInput.Pos("\00311\00303");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00312\00303")) {
			pos = FInput.Pos("\00312\00303");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00313\00303")) {
			pos = FInput.Pos("\00313\00303");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00314\00303")) {
			pos = FInput.Pos("\00314\00303");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00315\00303")) {
			pos = FInput.Pos("\00315\00303");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00300\00304")) {
			pos = FInput.Pos("\00300\00304");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00301\00304")) {
			pos = FInput.Pos("\00301\00304");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00302\00304")) {
			pos = FInput.Pos("\00302\00304");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00303\00304")) {
			pos = FInput.Pos("\00303\00304");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00304\00304")) {
			pos = FInput.Pos("\00304\00304");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00305\00304")) {
			pos = FInput.Pos("\00305\00304");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00306\00304")) {
			pos = FInput.Pos("\00306\00304");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00307\00304")) {
			pos = FInput.Pos("\00307\00304");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00308\00304")) {
			pos = FInput.Pos("\00308\00304");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00309\00304")) {
			pos = FInput.Pos("\00309\00304");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00310\00304")) {
			pos = FInput.Pos("\00310\00304");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00311\00304")) {
			pos = FInput.Pos("\00311\00304");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00312\00304")) {
			pos = FInput.Pos("\00312\00304");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00313\00304")) {
			pos = FInput.Pos("\00313\00304");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00314\00304")) {
			pos = FInput.Pos("\00314\00304");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00315\00304")) {
			pos = FInput.Pos("\00315\00304");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00300\00305")) {
			pos = FInput.Pos("\00300\00305");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00301\00305")) {
			pos = FInput.Pos("\00301\00305");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00302\00305")) {
			pos = FInput.Pos("\00302\00305");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00303\00305")) {
			pos = FInput.Pos("\00303\00305");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00304\00305")) {
			pos = FInput.Pos("\00304\00305");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00305\00305")) {
			pos = FInput.Pos("\00305\00305");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00306\00305")) {
			pos = FInput.Pos("\00306\00305");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00307\00305")) {
			pos = FInput.Pos("\00307\00305");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00308\00305")) {
			pos = FInput.Pos("\00308\00305");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00309\00305")) {
			pos = FInput.Pos("\00309\00305");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00310\00305")) {
			pos = FInput.Pos("\00310\00305");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00311\00305")) {
			pos = FInput.Pos("\00311\00305");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00312\00305")) {
			pos = FInput.Pos("\00312\00305");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00313\00305")) {
			pos = FInput.Pos("\00313\00305");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00314\00305")) {
			pos = FInput.Pos("\00314\00305");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00315\00305")) {
			pos = FInput.Pos("\00315\00305");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00300\00306")) {
			pos = FInput.Pos("\00300\00306");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00301\00306")) {
			pos = FInput.Pos("\00301\00306");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00302\00306")) {
			pos = FInput.Pos("\00302\00306");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00303\00306")) {
			pos = FInput.Pos("\00303\00306");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00304\00306")) {
			pos = FInput.Pos("\00304\00306");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00305\00306")) {
			pos = FInput.Pos("\00305\00306");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00306\00306")) {
			pos = FInput.Pos("\00306\00306");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00307\00306")) {
			pos = FInput.Pos("\00307\00306");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00308\00306")) {
			pos = FInput.Pos("\00308\00306");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00309\00306")) {
			pos = FInput.Pos("\00309\00306");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00310\00306")) {
			pos = FInput.Pos("\00310\00306");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00311\00306")) {
			pos = FInput.Pos("\00311\00306");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00312\00306")) {
			pos = FInput.Pos("\00312\00306");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00313\00306")) {
			pos = FInput.Pos("\00313\00306");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00314\00306")) {
			pos = FInput.Pos("\00314\00306");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00315\00306")) {
			pos = FInput.Pos("\00315\00306");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00300\00307")) {
			pos = FInput.Pos("\00300\00307");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00301\00307")) {
			pos = FInput.Pos("\00301\00307");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00302\00307")) {
			pos = FInput.Pos("\00302\00307");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00303\00307")) {
			pos = FInput.Pos("\00303\00307");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00304\00307")) {
			pos = FInput.Pos("\00304\00307");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00305\00307")) {
			pos = FInput.Pos("\00305\00307");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00306\00307")) {
			pos = FInput.Pos("\00306\00307");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00307\00307")) {
			pos = FInput.Pos("\00307\00307");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00308\00307")) {
			pos = FInput.Pos("\00308\00307");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00309\00307")) {
			pos = FInput.Pos("\00309\00307");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00310\00307")) {
			pos = FInput.Pos("\00310\00307");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00311\00307")) {
			pos = FInput.Pos("\00311\00307");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00312\00307")) {
			pos = FInput.Pos("\00312\00307");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00313\00307")) {
			pos = FInput.Pos("\00313\00307");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00314\00307")) {
			pos = FInput.Pos("\00314\00307");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00315\00307")) {
			pos = FInput.Pos("\00315\00307");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00300\00308")) {
			pos = FInput.Pos("\00300\00308");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00301\00308")) {
			pos = FInput.Pos("\00301\00308");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00302\00308")) {
			pos = FInput.Pos("\00302\00308");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00303\00308")) {
			pos = FInput.Pos("\00303\00308");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00304\00308")) {
			pos = FInput.Pos("\00304\00308");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00305\00308")) {
			pos = FInput.Pos("\00305\00308");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00306\00308")) {
			pos = FInput.Pos("\00306\00308");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00307\00308")) {
			pos = FInput.Pos("\00307\00308");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00308\00308")) {
			pos = FInput.Pos("\00308\00308");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00309\00308")) {
			pos = FInput.Pos("\00309\00308");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00310\00308")) {
			pos = FInput.Pos("\00310\00308");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00311\00308")) {
			pos = FInput.Pos("\00311\00308");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00312\00308")) {
			pos = FInput.Pos("\00312\00308");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00313\00308")) {
			pos = FInput.Pos("\00313\00308");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00314\00308")) {
			pos = FInput.Pos("\00314\00308");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00315\00308")) {
			pos = FInput.Pos("\00315\00308");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00300\00309")) {
			pos = FInput.Pos("\00300\00309");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00301\00309")) {
			pos = FInput.Pos("\00301\00309");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00302\00309")) {
			pos = FInput.Pos("\00302\00309");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00303\00309")) {
			pos = FInput.Pos("\00303\00309");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00304\00309")) {
			pos = FInput.Pos("\00304\00309");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00305\00309")) {
			pos = FInput.Pos("\00305\00309");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00306\00309")) {
			pos = FInput.Pos("\00306\00309");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00307\00309")) {
			pos = FInput.Pos("\00307\00309");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00308\00309")) {
			pos = FInput.Pos("\00308\00309");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00309\00309")) {
			pos = FInput.Pos("\00309\00309");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00310\00309")) {
			pos = FInput.Pos("\00310\00309");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00311\00309")) {
			pos = FInput.Pos("\00311\00309");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00312\00309")) {
			pos = FInput.Pos("\00312\00309");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00313\00309")) {
			pos = FInput.Pos("\00313\00309");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00314\00309")) {
			pos = FInput.Pos("\00314\00309");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00315\00309")) {
			pos = FInput.Pos("\00315\00309");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00300\00310")) {
			pos = FInput.Pos("\00300\00310");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00301\00310")) {
			pos = FInput.Pos("\00301\00310");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00302\00310")) {
			pos = FInput.Pos("\00302\00310");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00303\00310")) {
			pos = FInput.Pos("\00303\00310");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00304\00310")) {
			pos = FInput.Pos("\00304\00310");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00305\00310")) {
			pos = FInput.Pos("\00305\00310");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00306\00310")) {
			pos = FInput.Pos("\00306\00310");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00307\00310")) {
			pos = FInput.Pos("\00307\00310");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00308\00310")) {
			pos = FInput.Pos("\00308\00310");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00309\00310")) {
			pos = FInput.Pos("\00309\00310");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00310\00310")) {
			pos = FInput.Pos("\00310\00310");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00311\00310")) {
			pos = FInput.Pos("\00311\00310");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00312\00310")) {
			pos = FInput.Pos("\00312\00310");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00313\00310")) {
			pos = FInput.Pos("\00313\00310");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00314\00310")) {
			pos = FInput.Pos("\00314\00310");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00315\00310")) {
			pos = FInput.Pos("\00315\00310");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00300\00311")) {
			pos = FInput.Pos("\00300\00311");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00301\00311")) {
			pos = FInput.Pos("\00301\00311");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00302\00311")) {
			pos = FInput.Pos("\00302\00311");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00303\00311")) {
			pos = FInput.Pos("\00303\00311");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00304\00311")) {
			pos = FInput.Pos("\00304\00311");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00305\00311")) {
			pos = FInput.Pos("\00305\00311");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00306\00311")) {
			pos = FInput.Pos("\00306\00311");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00307\00311")) {
			pos = FInput.Pos("\00307\00311");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00308\00311")) {
			pos = FInput.Pos("\00308\00311");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00309\00311")) {
			pos = FInput.Pos("\00309\00311");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00310\00311")) {
			pos = FInput.Pos("\00310\00311");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00311\00311")) {
			pos = FInput.Pos("\00311\00311");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00312\00311")) {
			pos = FInput.Pos("\00312\00311");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00313\00311")) {
			pos = FInput.Pos("\00313\00311");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00314\00311")) {
			pos = FInput.Pos("\00314\00311");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00315\00311")) {
			pos = FInput.Pos("\00315\00311");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00300\00312")) {
			pos = FInput.Pos("\00300\00312");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00301\00312")) {
			pos = FInput.Pos("\00301\00312");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00302\00312")) {
			pos = FInput.Pos("\00302\00312");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00303\00312")) {
			pos = FInput.Pos("\00303\00312");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00304\00312")) {
			pos = FInput.Pos("\00304\00312");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00305\00312")) {
			pos = FInput.Pos("\00305\00312");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00306\00312")) {
			pos = FInput.Pos("\00306\00312");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00307\00312")) {
			pos = FInput.Pos("\00307\00312");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00308\00312")) {
			pos = FInput.Pos("\00308\00312");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00309\00312")) {
			pos = FInput.Pos("\00309\00312");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00310\00312")) {
			pos = FInput.Pos("\00310\00312");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00311\00312")) {
			pos = FInput.Pos("\00311\00312");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00312\00312")) {
			pos = FInput.Pos("\00312\00312");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00313\00312")) {
			pos = FInput.Pos("\00313\00312");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00314\00312")) {
			pos = FInput.Pos("\00314\00312");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00315\00312")) {
			pos = FInput.Pos("\00315\00312");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00300\00313")) {
			pos = FInput.Pos("\00300\00313");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00301\00313")) {
			pos = FInput.Pos("\00301\00313");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00302\00313")) {
			pos = FInput.Pos("\00302\00313");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00303\00313")) {
			pos = FInput.Pos("\00303\00313");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00304\00313")) {
			pos = FInput.Pos("\00304\00313");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00305\00313")) {
			pos = FInput.Pos("\00305\00313");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00306\00313")) {
			pos = FInput.Pos("\00306\00313");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00307\00313")) {
			pos = FInput.Pos("\00307\00313");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00308\00313")) {
			pos = FInput.Pos("\00308\00313");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00309\00313")) {
			pos = FInput.Pos("\00309\00313");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00310\00313")) {
			pos = FInput.Pos("\00310\00313");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00311\00313")) {
			pos = FInput.Pos("\00311\00313");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00312\00313")) {
			pos = FInput.Pos("\00312\00313");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00313\00313")) {
			pos = FInput.Pos("\00313\00313");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00314\00313")) {
			pos = FInput.Pos("\00314\00313");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00315\00313")) {
			pos = FInput.Pos("\00315\00313");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00300\00314")) {
			pos = FInput.Pos("\00300\00314");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00301\00314")) {
			pos = FInput.Pos("\00301\00314");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00302\00314")) {
			pos = FInput.Pos("\00302\00314");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00303\00314")) {
			pos = FInput.Pos("\00303\00314");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00304\00314")) {
			pos = FInput.Pos("\00304\00314");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00305\00314")) {
			pos = FInput.Pos("\00305\00314");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00306\00314")) {
			pos = FInput.Pos("\00306\00314");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00307\00314")) {
			pos = FInput.Pos("\00307\00314");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00308\00314")) {
			pos = FInput.Pos("\00308\00314");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00309\00314")) {
			pos = FInput.Pos("\00309\00314");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00310\00314")) {
			pos = FInput.Pos("\00310\00314");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00311\00314")) {
			pos = FInput.Pos("\00311\00314");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00312\00314")) {
			pos = FInput.Pos("\00312\00314");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00313\00314")) {
			pos = FInput.Pos("\00313\00314");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00314\00314")) {
			pos = FInput.Pos("\00314\00314");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00315\00314")) {
			pos = FInput.Pos("\00315\00314");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00300\00315")) {
			pos = FInput.Pos("\00300\00315");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00301\00315")) {
			pos = FInput.Pos("\00301\00315");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00302\00315")) {
			pos = FInput.Pos("\00302\00315");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00303\00315")) {
			pos = FInput.Pos("\00303\00315");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00304\00315")) {
			pos = FInput.Pos("\00304\00315");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00305\00315")) {
			pos = FInput.Pos("\00305\00315");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00306\00315")) {
			pos = FInput.Pos("\00306\00315");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00307\00315")) {
			pos = FInput.Pos("\00307\00315");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00308\00315")) {
			pos = FInput.Pos("\00308\00315");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00309\00315")) {
			pos = FInput.Pos("\00309\00315");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00310\00315")) {
			pos = FInput.Pos("\00310\00315");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00311\00315")) {
			pos = FInput.Pos("\00311\00315");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00312\00315")) {
			pos = FInput.Pos("\00312\00315");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00313\00315")) {
			pos = FInput.Pos("\00313\00315");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00314\00315")) {
			pos = FInput.Pos("\00314\00315");
			FInput.Delete(pos, 3);
		}

		if (FInput.Pos("\00315\00315")) {
			pos = FInput.Pos("\00315\00315");
			FInput.Delete(pos, 3);
		}
	}
	while (FInput.Pos("\00300\00300") > NULL || FInput.Pos("\00301\00300") >
		NULL || FInput.Pos("\00302\00300") > NULL || FInput.Pos("\00303\00300") >
		NULL || FInput.Pos("\00304\00300") > NULL || FInput.Pos("\00305\00300") >
		NULL || FInput.Pos("\00306\00300") > NULL || FInput.Pos("\00307\00300") >
		NULL || FInput.Pos("\00308\00300") > NULL || FInput.Pos("\00309\00300") >
		NULL || FInput.Pos("\00310\00300") > NULL || FInput.Pos("\00311\00300") >
		NULL || FInput.Pos("\00312\00300") > NULL || FInput.Pos("\00313\00300") >
		NULL || FInput.Pos("\00314\00300") > NULL || FInput.Pos("\00315\00300") >
		NULL || FInput.Pos("\00300\00301") > NULL || FInput.Pos("\00301\00301") >
		NULL || FInput.Pos("\00302\00301") > NULL || FInput.Pos("\00303\00301") >
		NULL || FInput.Pos("\00304\00301") > NULL || FInput.Pos("\00305\00301") >
		NULL || FInput.Pos("\00306\00301") > NULL || FInput.Pos("\00307\00301") >
		NULL || FInput.Pos("\00308\00301") > NULL || FInput.Pos("\00309\00301") >
		NULL || FInput.Pos("\00310\00301") > NULL || FInput.Pos("\00311\00301") >
		NULL || FInput.Pos("\00312\00301") > NULL || FInput.Pos("\00313\00301") >
		NULL || FInput.Pos("\00314\00301") > NULL || FInput.Pos("\00315\00301") >
		NULL || FInput.Pos("\00300\00302") > NULL || FInput.Pos("\00301\00302") >
		NULL || FInput.Pos("\00302\00302") > NULL || FInput.Pos("\00303\00302") >
		NULL || FInput.Pos("\00304\00302") > NULL || FInput.Pos("\00305\00302") >
		NULL || FInput.Pos("\00306\00302") > NULL || FInput.Pos("\00307\00302") >
		NULL || FInput.Pos("\00308\00302") > NULL || FInput.Pos("\00309\00302") >
		NULL || FInput.Pos("\00310\00302") > NULL || FInput.Pos("\00311\00302") >
		NULL || FInput.Pos("\00312\00302") > NULL || FInput.Pos("\00313\00302") >
		NULL || FInput.Pos("\00314\00302") > NULL || FInput.Pos("\00315\00302") >
		NULL || FInput.Pos("\00300\00303") > NULL || FInput.Pos("\00301\00303") >
		NULL || FInput.Pos("\00302\00303") > NULL || FInput.Pos("\00303\00303") >
		NULL || FInput.Pos("\00304\00303") > NULL || FInput.Pos("\00305\00303") >
		NULL || FInput.Pos("\00306\00303") > NULL || FInput.Pos("\00307\00303") >
		NULL || FInput.Pos("\00308\00303") > NULL || FInput.Pos("\00309\00303") >
		NULL || FInput.Pos("\00310\00303") > NULL || FInput.Pos("\00311\00303") >
		NULL || FInput.Pos("\00312\00303") > NULL || FInput.Pos("\00313\00303") >
		NULL || FInput.Pos("\00314\00303") > NULL || FInput.Pos("\00315\00303") >
		NULL || FInput.Pos("\00300\00304") > NULL || FInput.Pos("\00301\00304") >
		NULL || FInput.Pos("\00302\00304") > NULL || FInput.Pos("\00303\00304") >
		NULL || FInput.Pos("\00304\00304") > NULL || FInput.Pos("\00305\00304") >
		NULL || FInput.Pos("\00306\00304") > NULL || FInput.Pos("\00307\00304") >
		NULL || FInput.Pos("\00308\00304") > NULL || FInput.Pos("\00309\00304") >
		NULL || FInput.Pos("\00310\00304") > NULL || FInput.Pos("\00311\00304") >
		NULL || FInput.Pos("\00312\00304") > NULL || FInput.Pos("\00313\00304") >
		NULL || FInput.Pos("\00314\00304") > NULL || FInput.Pos("\00315\00304") >
		NULL || FInput.Pos("\00300\00305") > NULL || FInput.Pos("\00301\00305") >
		NULL || FInput.Pos("\00302\00305") > NULL || FInput.Pos("\00303\00305") >
		NULL || FInput.Pos("\00304\00305") > NULL || FInput.Pos("\00305\00305") >
		NULL || FInput.Pos("\00306\00305") > NULL || FInput.Pos("\00307\00305") >
		NULL || FInput.Pos("\00308\00305") > NULL || FInput.Pos("\00309\00305") >
		NULL || FInput.Pos("\00310\00305") > NULL || FInput.Pos("\00311\00305") >
		NULL || FInput.Pos("\00312\00305") > NULL || FInput.Pos("\00313\00305") >
		NULL || FInput.Pos("\00314\00305") > NULL || FInput.Pos("\00315\00305") >
		NULL || FInput.Pos("\00300\00306") > NULL || FInput.Pos("\00301\00306") >
		NULL || FInput.Pos("\00302\00306") > NULL || FInput.Pos("\00303\00306") >
		NULL || FInput.Pos("\00304\00306") > NULL || FInput.Pos("\00305\00306") >
		NULL || FInput.Pos("\00306\00306") > NULL || FInput.Pos("\00307\00306") >
		NULL || FInput.Pos("\00308\00306") > NULL || FInput.Pos("\00309\00306") >
		NULL || FInput.Pos("\00310\00306") > NULL || FInput.Pos("\00311\00306") >
		NULL || FInput.Pos("\00312\00306") > NULL || FInput.Pos("\00313\00306") >
		NULL || FInput.Pos("\00314\00306") > NULL || FInput.Pos("\00315\00306") >
		NULL || FInput.Pos("\00300\00307") > NULL || FInput.Pos("\00301\00307") >
		NULL || FInput.Pos("\00302\00307") > NULL || FInput.Pos("\00303\00307") >
		NULL || FInput.Pos("\00304\00307") > NULL || FInput.Pos("\00305\00307") >
		NULL || FInput.Pos("\00306\00307") > NULL || FInput.Pos("\00307\00307") >
		NULL || FInput.Pos("\00308\00307") > NULL || FInput.Pos("\00309\00307") >
		NULL || FInput.Pos("\00310\00307") > NULL || FInput.Pos("\00311\00307") >
		NULL || FInput.Pos("\00312\00307") > NULL || FInput.Pos("\00313\00307") >
		NULL || FInput.Pos("\00314\00307") > NULL || FInput.Pos("\00315\00307") >
		NULL || FInput.Pos("\00300\00308") > NULL || FInput.Pos("\00301\00308") >
		NULL || FInput.Pos("\00302\00308") > NULL || FInput.Pos("\00303\00308") >
		NULL || FInput.Pos("\00304\00308") > NULL || FInput.Pos("\00305\00308") >
		NULL || FInput.Pos("\00306\00308") > NULL || FInput.Pos("\00307\00308") >
		NULL || FInput.Pos("\00308\00308") > NULL || FInput.Pos("\00309\00308") >
		NULL || FInput.Pos("\00310\00308") > NULL || FInput.Pos("\00311\00308") >
		NULL || FInput.Pos("\00312\00308") > NULL || FInput.Pos("\00313\00308") >
		NULL || FInput.Pos("\00314\00308") > NULL || FInput.Pos("\00315\00308") >
		NULL || FInput.Pos("\00300\00309") > NULL || FInput.Pos("\00301\00309") >
		NULL || FInput.Pos("\00302\00309") > NULL || FInput.Pos("\00303\00309") >
		NULL || FInput.Pos("\00304\00309") > NULL || FInput.Pos("\00305\00309") >
		NULL || FInput.Pos("\00306\00309") > NULL || FInput.Pos("\00307\00309") >
		NULL || FInput.Pos("\00308\00309") > NULL || FInput.Pos("\00309\00309") >
		NULL || FInput.Pos("\00310\00309") > NULL || FInput.Pos("\00311\00309") >
		NULL || FInput.Pos("\00312\00309") > NULL || FInput.Pos("\00313\00309") >
		NULL || FInput.Pos("\00314\00309") > NULL || FInput.Pos("\00315\00309") >
		NULL || FInput.Pos("\00300\00310") > NULL || FInput.Pos("\00301\00310") >
		NULL || FInput.Pos("\00302\00310") > NULL || FInput.Pos("\00303\00310") >
		NULL || FInput.Pos("\00304\00310") > NULL || FInput.Pos("\00305\00310") >
		NULL || FInput.Pos("\00306\00310") > NULL || FInput.Pos("\00307\00310") >
		NULL || FInput.Pos("\00308\00310") > NULL || FInput.Pos("\00309\00310") >
		NULL || FInput.Pos("\00310\00310") > NULL || FInput.Pos("\00311\00310") >
		NULL || FInput.Pos("\00312\00310") > NULL || FInput.Pos("\00313\00310") >
		NULL || FInput.Pos("\00314\00310") > NULL || FInput.Pos("\00315\00310") >
		NULL || FInput.Pos("\00300\00311") > NULL || FInput.Pos("\00301\00311") >
		NULL || FInput.Pos("\00302\00311") > NULL || FInput.Pos("\00303\00311") >
		NULL || FInput.Pos("\00304\00311") > NULL || FInput.Pos("\00305\00311") >
		NULL || FInput.Pos("\00306\00311") > NULL || FInput.Pos("\00307\00311") >
		NULL || FInput.Pos("\00308\00311") > NULL || FInput.Pos("\00309\00311") >
		NULL || FInput.Pos("\00310\00311") > NULL || FInput.Pos("\00311\00311") >
		NULL || FInput.Pos("\00312\00311") > NULL || FInput.Pos("\00313\00311") >
		NULL || FInput.Pos("\00314\00311") > NULL || FInput.Pos("\00315\00311") >
		NULL || FInput.Pos("\00300\00312") > NULL || FInput.Pos("\00301\00312") >
		NULL || FInput.Pos("\00302\00312") > NULL || FInput.Pos("\00303\00312") >
		NULL || FInput.Pos("\00304\00312") > NULL || FInput.Pos("\00305\00312") >
		NULL || FInput.Pos("\00306\00312") > NULL || FInput.Pos("\00307\00312") >
		NULL || FInput.Pos("\00308\00312") > NULL || FInput.Pos("\00309\00312") >
		NULL || FInput.Pos("\00310\00312") > NULL || FInput.Pos("\00311\00312") >
		NULL || FInput.Pos("\00312\00312") > NULL || FInput.Pos("\00313\00312") >
		NULL || FInput.Pos("\00314\00312") > NULL || FInput.Pos("\00315\00312") >
		NULL || FInput.Pos("\00300\00313") > NULL || FInput.Pos("\00301\00313") >
		NULL || FInput.Pos("\00302\00313") > NULL || FInput.Pos("\00303\00313") >
		NULL || FInput.Pos("\00304\00313") > NULL || FInput.Pos("\00305\00313") >
		NULL || FInput.Pos("\00306\00313") > NULL || FInput.Pos("\00307\00313") >
		NULL || FInput.Pos("\00308\00313") > NULL || FInput.Pos("\00309\00313") >
		NULL || FInput.Pos("\00310\00313") > NULL || FInput.Pos("\00311\00313") >
		NULL || FInput.Pos("\00312\00313") > NULL || FInput.Pos("\00313\00313") >
		NULL || FInput.Pos("\00314\00313") > NULL || FInput.Pos("\00315\00313") >
		NULL || FInput.Pos("\00300\00314") > NULL || FInput.Pos("\00301\00314") >
		NULL || FInput.Pos("\00302\00314") > NULL || FInput.Pos("\00303\00314") >
		NULL || FInput.Pos("\00304\00314") > NULL || FInput.Pos("\00305\00314") >
		NULL || FInput.Pos("\00306\00314") > NULL || FInput.Pos("\00307\00314") >
		NULL || FInput.Pos("\00308\00314") > NULL || FInput.Pos("\00309\00314") >
		NULL || FInput.Pos("\00310\00314") > NULL || FInput.Pos("\00311\00314") >
		NULL || FInput.Pos("\00312\00314") > NULL || FInput.Pos("\00313\00314") >
		NULL || FInput.Pos("\00314\00314") > NULL || FInput.Pos("\00315\00314") >
		NULL || FInput.Pos("\00300\00315") > NULL || FInput.Pos("\00301\00315") >
		NULL || FInput.Pos("\00302\00315") > NULL || FInput.Pos("\00303\00315") >
		NULL || FInput.Pos("\00304\00315") > NULL || FInput.Pos("\00305\00315") >
		NULL || FInput.Pos("\00306\00315") > NULL || FInput.Pos("\00307\00315") >
		NULL || FInput.Pos("\00308\00315") > NULL || FInput.Pos("\00309\00315") >
		NULL || FInput.Pos("\00310\00315") > NULL || FInput.Pos("\00311\00315") >
		NULL || FInput.Pos("\00312\00315") > NULL || FInput.Pos("\00313\00315") >
		NULL || FInput.Pos("\00314\00315") > NULL || FInput.Pos("\00315\00315") >
		NULL);

	// removing doubles
	do {
		//Application->ProcessMessages();

		if (FInput.Pos("\00300\0030")) {
			pos = FInput.Pos("\00300\0030");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00301\0030")) {
			pos = FInput.Pos("\00301\0030");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00302\0030")) {
			pos = FInput.Pos("\00302\0030");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00303\0030")) {
			pos = FInput.Pos("\00303\0030");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00304\0030")) {
			pos = FInput.Pos("\00304\0030");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00305\0030")) {
			pos = FInput.Pos("\00305\0030");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00306\0030")) {
			pos = FInput.Pos("\00306\0030");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00307\0030")) {
			pos = FInput.Pos("\00307\0030");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00308\0030")) {
			pos = FInput.Pos("\00308\0030");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00309\0030")) {
			pos = FInput.Pos("\00309\0030");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00310\0030")) {
			pos = FInput.Pos("\00310\0030");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00311\0030")) {
			pos = FInput.Pos("\00311\0030");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00312\0030")) {
			pos = FInput.Pos("\00312\0030");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00313\0030")) {
			pos = FInput.Pos("\00313\0030");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00314\0030")) {
			pos = FInput.Pos("\00314\0030");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00315\0030")) {
			pos = FInput.Pos("\00315\0030");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00300\0031")) {
			pos = FInput.Pos("\00300\0031");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00301\0031")) {
			pos = FInput.Pos("\00301\0031");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00302\0031")) {
			pos = FInput.Pos("\00302\0031");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00303\0031")) {
			pos = FInput.Pos("\00303\0031");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00304\0031")) {
			pos = FInput.Pos("\00304\0031");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00305\0031")) {
			pos = FInput.Pos("\00305\0031");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00306\0031")) {
			pos = FInput.Pos("\00306\0031");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00307\0031")) {
			pos = FInput.Pos("\00307\0031");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00308\0031")) {
			pos = FInput.Pos("\00308\0031");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00309\0031")) {
			pos = FInput.Pos("\00309\0031");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00310\0031")) {
			pos = FInput.Pos("\00310\0031");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00311\0031")) {
			pos = FInput.Pos("\00311\0031");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00312\0031")) {
			pos = FInput.Pos("\00312\0031");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00313\0031")) {
			pos = FInput.Pos("\00313\0031");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00314\0031")) {
			pos = FInput.Pos("\00314\0031");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00315\0031")) {
			pos = FInput.Pos("\00315\0031");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00300\0032")) {
			pos = FInput.Pos("\00300\0032");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00301\0032")) {
			pos = FInput.Pos("\00301\0032");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00302\0032")) {
			pos = FInput.Pos("\00302\0032");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00303\0032")) {
			pos = FInput.Pos("\00303\0032");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00304\0032")) {
			pos = FInput.Pos("\00304\0032");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00305\0032")) {
			pos = FInput.Pos("\00305\0032");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00306\0032")) {
			pos = FInput.Pos("\00306\0032");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00307\0032")) {
			pos = FInput.Pos("\00307\0032");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00308\0032")) {
			pos = FInput.Pos("\00308\0032");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00309\0032")) {
			pos = FInput.Pos("\00309\0032");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00310\0032")) {
			pos = FInput.Pos("\00310\0032");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00311\0032")) {
			pos = FInput.Pos("\00311\0032");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00312\0032")) {
			pos = FInput.Pos("\00312\0032");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00313\0032")) {
			pos = FInput.Pos("\00313\0032");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00314\0032")) {
			pos = FInput.Pos("\00314\0032");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00315\0032")) {
			pos = FInput.Pos("\00315\0032");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00300\0033")) {
			pos = FInput.Pos("\00300\0033");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00301\0033")) {
			pos = FInput.Pos("\00301\0033");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00302\0033")) {
			pos = FInput.Pos("\00302\0033");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00303\0033")) {
			pos = FInput.Pos("\00303\0033");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00304\0033")) {
			pos = FInput.Pos("\00304\0033");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00305\0033")) {
			pos = FInput.Pos("\00305\0033");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00306\0033")) {
			pos = FInput.Pos("\00306\0033");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00307\0033")) {
			pos = FInput.Pos("\00307\0033");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00308\0033")) {
			pos = FInput.Pos("\00308\0033");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00309\0033")) {
			pos = FInput.Pos("\00309\0033");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00310\0033")) {
			pos = FInput.Pos("\00310\0033");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00311\0033")) {
			pos = FInput.Pos("\00311\0033");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00312\0033")) {
			pos = FInput.Pos("\00312\0033");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00313\0033")) {
			pos = FInput.Pos("\00313\0033");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00314\0033")) {
			pos = FInput.Pos("\00314\0033");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00315\0033")) {
			pos = FInput.Pos("\00315\0033");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00300\0034")) {
			pos = FInput.Pos("\00300\0034");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00301\0034")) {
			pos = FInput.Pos("\00301\0034");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00302\0034")) {
			pos = FInput.Pos("\00302\0034");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00303\0034")) {
			pos = FInput.Pos("\00303\0034");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00304\0034")) {
			pos = FInput.Pos("\00304\0034");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00305\0034")) {
			pos = FInput.Pos("\00305\0034");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00306\0034")) {
			pos = FInput.Pos("\00306\0034");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00307\0034")) {
			pos = FInput.Pos("\00307\0034");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00308\0034")) {
			pos = FInput.Pos("\00308\0034");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00309\0034")) {
			pos = FInput.Pos("\00309\0034");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00310\0034")) {
			pos = FInput.Pos("\00310\0034");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00311\0034")) {
			pos = FInput.Pos("\00311\0034");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00312\0034")) {
			pos = FInput.Pos("\00312\0034");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00313\0034")) {
			pos = FInput.Pos("\00313\0034");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00314\0034")) {
			pos = FInput.Pos("\00314\0034");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00315\0034")) {
			pos = FInput.Pos("\00315\0034");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00300\0035")) {
			pos = FInput.Pos("\00300\0035");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00301\0035")) {
			pos = FInput.Pos("\00301\0035");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00302\0035")) {
			pos = FInput.Pos("\00302\0035");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00303\0035")) {
			pos = FInput.Pos("\00303\0035");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00304\0035")) {
			pos = FInput.Pos("\00304\0035");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00305\0035")) {
			pos = FInput.Pos("\00305\0035");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00306\0035")) {
			pos = FInput.Pos("\00306\0035");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00307\0035")) {
			pos = FInput.Pos("\00307\0035");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00308\0035")) {
			pos = FInput.Pos("\00308\0035");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00309\0035")) {
			pos = FInput.Pos("\00309\0035");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00310\0035")) {
			pos = FInput.Pos("\00310\0035");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00311\0035")) {
			pos = FInput.Pos("\00311\0035");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00312\0035")) {
			pos = FInput.Pos("\00312\0035");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00313\0035")) {
			pos = FInput.Pos("\00313\0035");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00314\0035")) {
			pos = FInput.Pos("\00314\0035");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00315\0035")) {
			pos = FInput.Pos("\00315\0035");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00300\0036")) {
			pos = FInput.Pos("\00300\0036");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00301\0036")) {
			pos = FInput.Pos("\00301\0036");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00302\0036")) {
			pos = FInput.Pos("\00302\0036");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00303\0036")) {
			pos = FInput.Pos("\00303\0036");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00304\0036")) {
			pos = FInput.Pos("\00304\0036");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00305\0036")) {
			pos = FInput.Pos("\00305\0036");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00306\0036")) {
			pos = FInput.Pos("\00306\0036");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00307\0036")) {
			pos = FInput.Pos("\00307\0036");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00308\0036")) {
			pos = FInput.Pos("\00308\0036");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00309\0036")) {
			pos = FInput.Pos("\00309\0036");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00310\0036")) {
			pos = FInput.Pos("\00310\0036");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00311\0036")) {
			pos = FInput.Pos("\00311\0036");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00312\0036")) {
			pos = FInput.Pos("\00312\0036");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00313\0036")) {
			pos = FInput.Pos("\00313\0036");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00314\0036")) {
			pos = FInput.Pos("\00314\0036");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00315\0036")) {
			pos = FInput.Pos("\00315\0036");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00300\0037")) {
			pos = FInput.Pos("\00300\0037");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00301\0037")) {
			pos = FInput.Pos("\00301\0037");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00302\0037")) {
			pos = FInput.Pos("\00302\0037");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00303\0037")) {
			pos = FInput.Pos("\00303\0037");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00304\0037")) {
			pos = FInput.Pos("\00304\0037");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00305\0037")) {
			pos = FInput.Pos("\00305\0037");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00306\0037")) {
			pos = FInput.Pos("\00306\0037");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00307\0037")) {
			pos = FInput.Pos("\00307\0037");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00308\0037")) {
			pos = FInput.Pos("\00308\0037");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00309\0037")) {
			pos = FInput.Pos("\00309\0037");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00310\0037")) {
			pos = FInput.Pos("\00310\0037");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00311\0037")) {
			pos = FInput.Pos("\00311\0037");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00312\0037")) {
			pos = FInput.Pos("\00312\0037");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00313\0037")) {
			pos = FInput.Pos("\00313\0037");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00314\0037")) {
			pos = FInput.Pos("\00314\0037");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00315\0037")) {
			pos = FInput.Pos("\00315\0037");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00300\0038")) {
			pos = FInput.Pos("\00300\0038");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00301\0038")) {
			pos = FInput.Pos("\00301\0038");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00302\0038")) {
			pos = FInput.Pos("\00302\0038");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00303\0038")) {
			pos = FInput.Pos("\00303\0038");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00304\0038")) {
			pos = FInput.Pos("\00304\0038");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00305\0038")) {
			pos = FInput.Pos("\00305\0038");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00306\0038")) {
			pos = FInput.Pos("\00306\0038");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00307\0038")) {
			pos = FInput.Pos("\00307\0038");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00308\0038")) {
			pos = FInput.Pos("\00308\0038");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00309\0038")) {
			pos = FInput.Pos("\00309\0038");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00310\0038")) {
			pos = FInput.Pos("\00310\0038");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00311\0038")) {
			pos = FInput.Pos("\00311\0038");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00312\0038")) {
			pos = FInput.Pos("\00312\0038");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00313\0038")) {
			pos = FInput.Pos("\00313\0038");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00314\0038")) {
			pos = FInput.Pos("\00314\0038");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00315\0038")) {
			pos = FInput.Pos("\00315\0038");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00300\0039")) {
			pos = FInput.Pos("\00300\0039");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00301\0039")) {
			pos = FInput.Pos("\00301\0039");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00302\0039")) {
			pos = FInput.Pos("\00302\0039");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00303\0039")) {
			pos = FInput.Pos("\00303\0039");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00304\0039")) {
			pos = FInput.Pos("\00304\0039");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00305\0039")) {
			pos = FInput.Pos("\00305\0039");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00306\0039")) {
			pos = FInput.Pos("\00306\0039");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00307\0039")) {
			pos = FInput.Pos("\00307\0039");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00308\0039")) {
			pos = FInput.Pos("\00308\0039");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00309\0039")) {
			pos = FInput.Pos("\00309\0039");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00310\0039")) {
			pos = FInput.Pos("\00310\0039");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00311\0039")) {
			pos = FInput.Pos("\00311\0039");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00312\0039")) {
			pos = FInput.Pos("\00312\0039");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00313\0039")) {
			pos = FInput.Pos("\00313\0039");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00314\0039")) {
			pos = FInput.Pos("\00314\0039");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\00315\0039")) {
			pos = FInput.Pos("\00315\0039");
			FInput.Delete(pos, 3);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0030\00300")) {
			pos = FInput.Pos("\0030\00300");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0031\00300")) {
			pos = FInput.Pos("\0031\00300");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0032\00300")) {
			pos = FInput.Pos("\0032\00300");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0033\00300")) {
			pos = FInput.Pos("\0033\00300");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0034\00300")) {
			pos = FInput.Pos("\0034\00300");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0035\00300")) {
			pos = FInput.Pos("\0035\00300");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0036\00300")) {
			pos = FInput.Pos("\0036\00300");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0037\00300")) {
			pos = FInput.Pos("\0037\00300");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0038\00300")) {
			pos = FInput.Pos("\0038\00300");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0039\00300")) {
			pos = FInput.Pos("\0039\00300");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0030\00301")) {
			pos = FInput.Pos("\0030\00301");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0031\00301")) {
			pos = FInput.Pos("\0031\00301");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0032\00301")) {
			pos = FInput.Pos("\0032\00301");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0033\00301")) {
			pos = FInput.Pos("\0033\00301");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0034\00301")) {
			pos = FInput.Pos("\0034\00301");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0035\00301")) {
			pos = FInput.Pos("\0035\00301");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0036\00301")) {
			pos = FInput.Pos("\0036\00301");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0037\00301")) {
			pos = FInput.Pos("\0037\00301");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0038\00301")) {
			pos = FInput.Pos("\0038\00301");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0039\00301")) {
			pos = FInput.Pos("\0039\00301");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0030\00302")) {
			pos = FInput.Pos("\0030\00302");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0031\00302")) {
			pos = FInput.Pos("\0031\00302");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0032\00302")) {
			pos = FInput.Pos("\0032\00302");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0033\00302")) {
			pos = FInput.Pos("\0033\00302");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0034\00302")) {
			pos = FInput.Pos("\0034\00302");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0035\00302")) {
			pos = FInput.Pos("\0035\00302");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0036\00302")) {
			pos = FInput.Pos("\0036\00302");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0037\00302")) {
			pos = FInput.Pos("\0037\00302");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0038\00302")) {
			pos = FInput.Pos("\0038\00302");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0039\00302")) {
			pos = FInput.Pos("\0039\00302");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0030\00303")) {
			pos = FInput.Pos("\0030\00303");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0031\00303")) {
			pos = FInput.Pos("\0031\00303");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0032\00303")) {
			pos = FInput.Pos("\0032\00303");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0033\00303")) {
			pos = FInput.Pos("\0033\00303");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0034\00303")) {
			pos = FInput.Pos("\0034\00303");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0035\00303")) {
			pos = FInput.Pos("\0035\00303");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0036\00303")) {
			pos = FInput.Pos("\0036\00303");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0037\00303")) {
			pos = FInput.Pos("\0037\00303");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0038\00303")) {
			pos = FInput.Pos("\0038\00303");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0039\00303")) {
			pos = FInput.Pos("\0039\00303");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0030\00304")) {
			pos = FInput.Pos("\0030\00304");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0031\00304")) {
			pos = FInput.Pos("\0031\00304");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0032\00304")) {
			pos = FInput.Pos("\0032\00304");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0033\00304")) {
			pos = FInput.Pos("\0033\00304");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0034\00304")) {
			pos = FInput.Pos("\0034\00304");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0035\00304")) {
			pos = FInput.Pos("\0035\00304");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0036\00304")) {
			pos = FInput.Pos("\0036\00304");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0037\00304")) {
			pos = FInput.Pos("\0037\00304");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0038\00304")) {
			pos = FInput.Pos("\0038\00304");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0039\00304")) {
			pos = FInput.Pos("\0039\00304");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0030\00305")) {
			pos = FInput.Pos("\0030\00305");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0031\00305")) {
			pos = FInput.Pos("\0031\00305");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0032\00305")) {
			pos = FInput.Pos("\0032\00305");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0033\00305")) {
			pos = FInput.Pos("\0033\00305");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0034\00305")) {
			pos = FInput.Pos("\0034\00305");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0035\00305")) {
			pos = FInput.Pos("\0035\00305");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0036\00305")) {
			pos = FInput.Pos("\0036\00305");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0037\00305")) {
			pos = FInput.Pos("\0037\00305");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0038\00305")) {
			pos = FInput.Pos("\0038\00305");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0039\00305")) {
			pos = FInput.Pos("\0039\00305");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0030\00306")) {
			pos = FInput.Pos("\0030\00306");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0031\00306")) {
			pos = FInput.Pos("\0031\00306");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0032\00306")) {
			pos = FInput.Pos("\0032\00306");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0033\00306")) {
			pos = FInput.Pos("\0033\00306");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0034\00306")) {
			pos = FInput.Pos("\0034\00306");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0035\00306")) {
			pos = FInput.Pos("\0035\00306");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0036\00306")) {
			pos = FInput.Pos("\0036\00306");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0037\00306")) {
			pos = FInput.Pos("\0037\00306");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0038\00306")) {
			pos = FInput.Pos("\0038\00306");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0039\00306")) {
			pos = FInput.Pos("\0039\00306");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0030\00307")) {
			pos = FInput.Pos("\0030\00307");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0031\00307")) {
			pos = FInput.Pos("\0031\00307");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0032\00307")) {
			pos = FInput.Pos("\0032\00307");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0033\00307")) {
			pos = FInput.Pos("\0033\00307");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0034\00307")) {
			pos = FInput.Pos("\0034\00307");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0035\00307")) {
			pos = FInput.Pos("\0035\00307");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0036\00307")) {
			pos = FInput.Pos("\0036\00307");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0037\00307")) {
			pos = FInput.Pos("\0037\00307");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0038\00307")) {
			pos = FInput.Pos("\0038\00307");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0039\00307")) {
			pos = FInput.Pos("\0039\00307");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0030\00308")) {
			pos = FInput.Pos("\0030\00308");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0031\00308")) {
			pos = FInput.Pos("\0031\00308");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0032\00308")) {
			pos = FInput.Pos("\0032\00308");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0033\00308")) {
			pos = FInput.Pos("\0033\00308");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0034\00308")) {
			pos = FInput.Pos("\0034\00308");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0035\00308")) {
			pos = FInput.Pos("\0035\00308");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0036\00308")) {
			pos = FInput.Pos("\0036\00308");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0037\00308")) {
			pos = FInput.Pos("\0037\00308");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0038\00308")) {
			pos = FInput.Pos("\0038\00308");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0039\00308")) {
			pos = FInput.Pos("\0039\00308");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0030\00309")) {
			pos = FInput.Pos("\0030\00309");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0031\00309")) {
			pos = FInput.Pos("\0031\00309");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0032\00309")) {
			pos = FInput.Pos("\0032\00309");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0033\00309")) {
			pos = FInput.Pos("\0033\00309");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0034\00309")) {
			pos = FInput.Pos("\0034\00309");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0035\00309")) {
			pos = FInput.Pos("\0035\00309");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0036\00309")) {
			pos = FInput.Pos("\0036\00309");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0037\00309")) {
			pos = FInput.Pos("\0037\00309");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0038\00309")) {
			pos = FInput.Pos("\0038\00309");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0039\00309")) {
			pos = FInput.Pos("\0039\00309");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0030\00310")) {
			pos = FInput.Pos("\0030\00310");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0031\00310")) {
			pos = FInput.Pos("\0031\00310");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0032\00310")) {
			pos = FInput.Pos("\0032\00310");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0033\00310")) {
			pos = FInput.Pos("\0033\00310");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0034\00310")) {
			pos = FInput.Pos("\0034\00310");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0035\00310")) {
			pos = FInput.Pos("\0035\00310");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0036\00310")) {
			pos = FInput.Pos("\0036\00310");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0037\00310")) {
			pos = FInput.Pos("\0037\00310");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0038\00310")) {
			pos = FInput.Pos("\0038\00310");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0039\00310")) {
			pos = FInput.Pos("\0039\00310");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0030\00311")) {
			pos = FInput.Pos("\0030\00311");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0031\00311")) {
			pos = FInput.Pos("\0031\00311");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0032\00311")) {
			pos = FInput.Pos("\0032\00311");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0033\00311")) {
			pos = FInput.Pos("\0033\00311");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0034\00311")) {
			pos = FInput.Pos("\0034\00311");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0035\00311")) {
			pos = FInput.Pos("\0035\00311");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0036\00311")) {
			pos = FInput.Pos("\0036\00311");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0037\00311")) {
			pos = FInput.Pos("\0037\00311");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0038\00311")) {
			pos = FInput.Pos("\0038\00311");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0039\00311")) {
			pos = FInput.Pos("\0039\00311");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0030\00312")) {
			pos = FInput.Pos("\0030\00312");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0031\00312")) {
			pos = FInput.Pos("\0031\00312");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0032\00312")) {
			pos = FInput.Pos("\0032\00312");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0033\00312")) {
			pos = FInput.Pos("\0033\00312");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0034\00312")) {
			pos = FInput.Pos("\0034\00312");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0035\00312")) {
			pos = FInput.Pos("\0035\00312");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0036\00312")) {
			pos = FInput.Pos("\0036\00312");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0037\00312")) {
			pos = FInput.Pos("\0037\00312");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0038\00312")) {
			pos = FInput.Pos("\0038\00312");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0039\00312")) {
			pos = FInput.Pos("\0039\00312");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0030\00313")) {
			pos = FInput.Pos("\0030\00313");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0031\00313")) {
			pos = FInput.Pos("\0031\00313");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0032\00313")) {
			pos = FInput.Pos("\0032\00313");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0033\00313")) {
			pos = FInput.Pos("\0033\00313");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0034\00313")) {
			pos = FInput.Pos("\0034\00313");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0035\00313")) {
			pos = FInput.Pos("\0035\00313");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0036\00313")) {
			pos = FInput.Pos("\0036\00313");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0037\00313")) {
			pos = FInput.Pos("\0037\00313");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0038\00313")) {
			pos = FInput.Pos("\0038\00313");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0039\00313")) {
			pos = FInput.Pos("\0039\00313");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0030\00314")) {
			pos = FInput.Pos("\0030\00314");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0031\00314")) {
			pos = FInput.Pos("\0031\00314");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0032\00314")) {
			pos = FInput.Pos("\0032\00314");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0033\00314")) {
			pos = FInput.Pos("\0033\00314");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0034\00314")) {
			pos = FInput.Pos("\0034\00314");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0035\00314")) {
			pos = FInput.Pos("\0035\00314");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0036\00314")) {
			pos = FInput.Pos("\0036\00314");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0037\00314")) {
			pos = FInput.Pos("\0037\00314");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0038\00314")) {
			pos = FInput.Pos("\0038\00314");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0039\00314")) {
			pos = FInput.Pos("\0039\00314");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0030\00315")) {
			pos = FInput.Pos("\0030\00315");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0031\00315")) {
			pos = FInput.Pos("\0031\00315");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0032\00315")) {
			pos = FInput.Pos("\0032\00315");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0033\00315")) {
			pos = FInput.Pos("\0033\00315");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0034\00315")) {
			pos = FInput.Pos("\0034\00315");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0035\00315")) {
			pos = FInput.Pos("\0035\00315");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0036\00315")) {
			pos = FInput.Pos("\0036\00315");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0037\00315")) {
			pos = FInput.Pos("\0037\00315");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0038\00315")) {
			pos = FInput.Pos("\0038\00315");
			FInput.Delete(pos, 2);
		}

		if (FInput.Pos("\0039\00315")) {
			pos = FInput.Pos("\0039\00315");
			FInput.Delete(pos, 2);
		}
	}
	while (FInput.Pos("\00300\0030") > NULL || FInput.Pos("\00301\0030") >
		NULL || FInput.Pos("\00302\0030") > NULL || FInput.Pos("\00303\0030") >
		NULL || FInput.Pos("\00304\0030") > NULL || FInput.Pos("\00305\0030") >
		NULL || FInput.Pos("\00306\0030") > NULL || FInput.Pos("\00307\0030") >
		NULL || FInput.Pos("\00308\0030") > NULL || FInput.Pos("\00309\0030") >
		NULL || FInput.Pos("\00310\0030") > NULL || FInput.Pos("\00311\0030") >
		NULL || FInput.Pos("\00312\0030") > NULL || FInput.Pos("\00313\0030") >
		NULL || FInput.Pos("\00314\0030") > NULL || FInput.Pos("\00315\0030") >
		NULL || FInput.Pos("\00300\0031") > NULL || FInput.Pos("\00301\0031") >
		NULL || FInput.Pos("\00302\0031") > NULL || FInput.Pos("\00303\0031") >
		NULL || FInput.Pos("\00304\0031") > NULL || FInput.Pos("\00305\0031") >
		NULL || FInput.Pos("\00306\0031") > NULL || FInput.Pos("\00307\0031") >
		NULL || FInput.Pos("\00308\0031") > NULL || FInput.Pos("\00309\0031") >
		NULL || FInput.Pos("\00310\0031") > NULL || FInput.Pos("\00311\0031") >
		NULL || FInput.Pos("\00312\0031") > NULL || FInput.Pos("\00313\0031") >
		NULL || FInput.Pos("\00314\0031") > NULL || FInput.Pos("\00315\0031") >
		NULL || FInput.Pos("\00300\0032") > NULL || FInput.Pos("\00301\0032") >
		NULL || FInput.Pos("\00302\0032") > NULL || FInput.Pos("\00303\0032") >
		NULL || FInput.Pos("\00304\0032") > NULL || FInput.Pos("\00305\0032") >
		NULL || FInput.Pos("\00306\0032") > NULL || FInput.Pos("\00307\0032") >
		NULL || FInput.Pos("\00308\0032") > NULL || FInput.Pos("\00309\0032") >
		NULL || FInput.Pos("\00310\0032") > NULL || FInput.Pos("\00311\0032") >
		NULL || FInput.Pos("\00312\0032") > NULL || FInput.Pos("\00313\0032") >
		NULL || FInput.Pos("\00314\0032") > NULL || FInput.Pos("\00315\0032") >
		NULL || FInput.Pos("\00300\0033") > NULL || FInput.Pos("\00301\0033") >
		NULL || FInput.Pos("\00302\0033") > NULL || FInput.Pos("\00303\0033") >
		NULL || FInput.Pos("\00304\0033") > NULL || FInput.Pos("\00305\0033") >
		NULL || FInput.Pos("\00306\0033") > NULL || FInput.Pos("\00307\0033") >
		NULL || FInput.Pos("\00308\0033") > NULL || FInput.Pos("\00309\0033") >
		NULL || FInput.Pos("\00310\0033") > NULL || FInput.Pos("\00311\0033") >
		NULL || FInput.Pos("\00312\0033") > NULL || FInput.Pos("\00313\0033") >
		NULL || FInput.Pos("\00314\0033") > NULL || FInput.Pos("\00315\0033") >
		NULL || FInput.Pos("\00300\0034") > NULL || FInput.Pos("\00301\0034") >
		NULL || FInput.Pos("\00302\0034") > NULL || FInput.Pos("\00303\0034") >
		NULL || FInput.Pos("\00304\0034") > NULL || FInput.Pos("\00305\0034") >
		NULL || FInput.Pos("\00306\0034") > NULL || FInput.Pos("\00307\0034") >
		NULL || FInput.Pos("\00308\0034") > NULL || FInput.Pos("\00309\0034") >
		NULL || FInput.Pos("\00310\0034") > NULL || FInput.Pos("\00311\0034") >
		NULL || FInput.Pos("\00312\0034") > NULL || FInput.Pos("\00313\0034") >
		NULL || FInput.Pos("\00314\0034") > NULL || FInput.Pos("\00315\0034") >
		NULL || FInput.Pos("\00300\0035") > NULL || FInput.Pos("\00301\0035") >
		NULL || FInput.Pos("\00302\0035") > NULL || FInput.Pos("\00303\0035") >
		NULL || FInput.Pos("\00304\0035") > NULL || FInput.Pos("\00305\0035") >
		NULL || FInput.Pos("\00306\0035") > NULL || FInput.Pos("\00307\0035") >
		NULL || FInput.Pos("\00308\0035") > NULL || FInput.Pos("\00309\0035") >
		NULL || FInput.Pos("\00310\0035") > NULL || FInput.Pos("\00311\0035") >
		NULL || FInput.Pos("\00312\0035") > NULL || FInput.Pos("\00313\0035") >
		NULL || FInput.Pos("\00314\0035") > NULL || FInput.Pos("\00315\0035") >
		NULL || FInput.Pos("\00300\0036") > NULL || FInput.Pos("\00301\0036") >
		NULL || FInput.Pos("\00302\0036") > NULL || FInput.Pos("\00303\0036") >
		NULL || FInput.Pos("\00304\0036") > NULL || FInput.Pos("\00305\0036") >
		NULL || FInput.Pos("\00306\0036") > NULL || FInput.Pos("\00307\0036") >
		NULL || FInput.Pos("\00308\0036") > NULL || FInput.Pos("\00309\0036") >
		NULL || FInput.Pos("\00310\0036") > NULL || FInput.Pos("\00311\0036") >
		NULL || FInput.Pos("\00312\0036") > NULL || FInput.Pos("\00313\0036") >
		NULL || FInput.Pos("\00314\0036") > NULL || FInput.Pos("\00315\0036") >
		NULL || FInput.Pos("\00300\0037") > NULL || FInput.Pos("\00301\0037") >
		NULL || FInput.Pos("\00302\0037") > NULL || FInput.Pos("\00303\0037") >
		NULL || FInput.Pos("\00304\0037") > NULL || FInput.Pos("\00305\0037") >
		NULL || FInput.Pos("\00306\0037") > NULL || FInput.Pos("\00307\0037") >
		NULL || FInput.Pos("\00308\0037") > NULL || FInput.Pos("\00309\0037") >
		NULL || FInput.Pos("\00310\0037") > NULL || FInput.Pos("\00311\0037") >
		NULL || FInput.Pos("\00312\0037") > NULL || FInput.Pos("\00313\0037") >
		NULL || FInput.Pos("\00314\0037") > NULL || FInput.Pos("\00315\0037") >
		NULL || FInput.Pos("\00300\0038") > NULL || FInput.Pos("\00301\0038") >
		NULL || FInput.Pos("\00302\0038") > NULL || FInput.Pos("\00303\0038") >
		NULL || FInput.Pos("\00304\0038") > NULL || FInput.Pos("\00305\0038") >
		NULL || FInput.Pos("\00306\0038") > NULL || FInput.Pos("\00307\0038") >
		NULL || FInput.Pos("\00308\0038") > NULL || FInput.Pos("\00309\0038") >
		NULL || FInput.Pos("\00310\0038") > NULL || FInput.Pos("\00311\0038") >
		NULL || FInput.Pos("\00312\0038") > NULL || FInput.Pos("\00313\0038") >
		NULL || FInput.Pos("\00314\0038") > NULL || FInput.Pos("\00315\0038") >
		NULL || FInput.Pos("\00300\0039") > NULL || FInput.Pos("\00301\0039") >
		NULL || FInput.Pos("\00302\0039") > NULL || FInput.Pos("\00303\0039") >
		NULL || FInput.Pos("\00304\0039") > NULL || FInput.Pos("\00305\0039") >
		NULL || FInput.Pos("\00306\0039") > NULL || FInput.Pos("\00307\0039") >
		NULL || FInput.Pos("\00308\0039") > NULL || FInput.Pos("\00309\0039") >
		NULL || FInput.Pos("\00310\0039") > NULL || FInput.Pos("\00311\0039") >
		NULL || FInput.Pos("\00312\0039") > NULL || FInput.Pos("\00313\0039") >
		NULL || FInput.Pos("\00314\0039") > NULL || FInput.Pos("\00315\0039") >
		NULL || FInput.Pos("\0030\00301") > NULL || FInput.Pos("\0031\00301") >
		NULL || FInput.Pos("\0032\00301") > NULL || FInput.Pos("\0033\00301") >
		NULL || FInput.Pos("\0034\00301") > NULL || FInput.Pos("\0035\00301") >
		NULL || FInput.Pos("\0036\00301") > NULL || FInput.Pos("\0037\00301") >
		NULL || FInput.Pos("\0038\00301") > NULL || FInput.Pos("\0039\00301") >
		NULL || FInput.Pos("\0030\00302") > NULL || FInput.Pos("\0031\00302") >
		NULL || FInput.Pos("\0032\00302") > NULL || FInput.Pos("\0033\00302") >
		NULL || FInput.Pos("\0034\00302") > NULL || FInput.Pos("\0035\00302") >
		NULL || FInput.Pos("\0036\00302") > NULL || FInput.Pos("\0037\00302") >
		NULL || FInput.Pos("\0038\00302") > NULL || FInput.Pos("\0039\00302") >
		NULL || FInput.Pos("\0030\00303") > NULL || FInput.Pos("\0031\00303") >
		NULL || FInput.Pos("\0032\00303") > NULL || FInput.Pos("\0033\00303") >
		NULL || FInput.Pos("\0034\00303") > NULL || FInput.Pos("\0035\00303") >
		NULL || FInput.Pos("\0036\00303") > NULL || FInput.Pos("\0037\00303") >
		NULL || FInput.Pos("\0038\00303") > NULL || FInput.Pos("\0039\00303") >
		NULL || FInput.Pos("\0030\00304") > NULL || FInput.Pos("\0031\00304") >
		NULL || FInput.Pos("\0032\00304") > NULL || FInput.Pos("\0033\00304") >
		NULL || FInput.Pos("\0034\00304") > NULL || FInput.Pos("\0035\00304") >
		NULL || FInput.Pos("\0036\00304") > NULL || FInput.Pos("\0037\00304") >
		NULL || FInput.Pos("\0038\00304") > NULL || FInput.Pos("\0039\00304") >
		NULL || FInput.Pos("\0030\00305") > NULL || FInput.Pos("\0031\00305") >
		NULL || FInput.Pos("\0032\00305") > NULL || FInput.Pos("\0033\00305") >
		NULL || FInput.Pos("\0034\00305") > NULL || FInput.Pos("\0035\00305") >
		NULL || FInput.Pos("\0036\00305") > NULL || FInput.Pos("\0037\00305") >
		NULL || FInput.Pos("\0038\00305") > NULL || FInput.Pos("\0039\00305") >
		NULL || FInput.Pos("\0030\00306") > NULL || FInput.Pos("\0031\00306") >
		NULL || FInput.Pos("\0032\00306") > NULL || FInput.Pos("\0033\00306") >
		NULL || FInput.Pos("\0034\00306") > NULL || FInput.Pos("\0035\00306") >
		NULL || FInput.Pos("\0036\00306") > NULL || FInput.Pos("\0037\00306") >
		NULL || FInput.Pos("\0038\00306") > NULL || FInput.Pos("\0039\00306") >
		NULL || FInput.Pos("\0030\00307") > NULL || FInput.Pos("\0031\00307") >
		NULL || FInput.Pos("\0032\00307") > NULL || FInput.Pos("\0033\00307") >
		NULL || FInput.Pos("\0034\00307") > NULL || FInput.Pos("\0035\00307") >
		NULL || FInput.Pos("\0036\00307") > NULL || FInput.Pos("\0037\00307") >
		NULL || FInput.Pos("\0038\00307") > NULL || FInput.Pos("\0039\00307") >
		NULL || FInput.Pos("\0030\00308") > NULL || FInput.Pos("\0031\00308") >
		NULL || FInput.Pos("\0032\00308") > NULL || FInput.Pos("\0033\00308") >
		NULL || FInput.Pos("\0034\00308") > NULL || FInput.Pos("\0035\00308") >
		NULL || FInput.Pos("\0036\00308") > NULL || FInput.Pos("\0037\00308") >
		NULL || FInput.Pos("\0038\00308") > NULL || FInput.Pos("\0039\00308") >
		NULL || FInput.Pos("\0030\00309") > NULL || FInput.Pos("\0031\00309") >
		NULL || FInput.Pos("\0032\00309") > NULL || FInput.Pos("\0033\00309") >
		NULL || FInput.Pos("\0034\00309") > NULL || FInput.Pos("\0035\00309") >
		NULL || FInput.Pos("\0036\00309") > NULL || FInput.Pos("\0037\00309") >
		NULL || FInput.Pos("\0038\00309") > NULL || FInput.Pos("\0039\00309") >
		NULL || FInput.Pos("\0030\00310") > NULL || FInput.Pos("\0031\00310") >
		NULL || FInput.Pos("\0032\00310") > NULL || FInput.Pos("\0033\00310") >
		NULL || FInput.Pos("\0034\00310") > NULL || FInput.Pos("\0035\00310") >
		NULL || FInput.Pos("\0036\00310") > NULL || FInput.Pos("\0037\00310") >
		NULL || FInput.Pos("\0038\00310") > NULL || FInput.Pos("\0039\00310") >
		NULL || FInput.Pos("\0030\00311") > NULL || FInput.Pos("\0031\00311") >
		NULL || FInput.Pos("\0032\00311") > NULL || FInput.Pos("\0033\00311") >
		NULL || FInput.Pos("\0034\00311") > NULL || FInput.Pos("\0035\00311") >
		NULL || FInput.Pos("\0036\00311") > NULL || FInput.Pos("\0037\00311") >
		NULL || FInput.Pos("\0038\00311") > NULL || FInput.Pos("\0039\00311") >
		NULL || FInput.Pos("\0030\00312") > NULL || FInput.Pos("\0031\00312") >
		NULL || FInput.Pos("\0032\00312") > NULL || FInput.Pos("\0033\00312") >
		NULL || FInput.Pos("\0034\00312") > NULL || FInput.Pos("\0035\00312") >
		NULL || FInput.Pos("\0036\00312") > NULL || FInput.Pos("\0037\00312") >
		NULL || FInput.Pos("\0038\00312") > NULL || FInput.Pos("\0039\00312") >
		NULL || FInput.Pos("\0030\00313") > NULL || FInput.Pos("\0031\00313") >
		NULL || FInput.Pos("\0032\00313") > NULL || FInput.Pos("\0033\00313") >
		NULL || FInput.Pos("\0034\00313") > NULL || FInput.Pos("\0035\00313") >
		NULL || FInput.Pos("\0036\00313") > NULL || FInput.Pos("\0037\00313") >
		NULL || FInput.Pos("\0038\00313") > NULL || FInput.Pos("\0039\00313") >
		NULL || FInput.Pos("\0030\00314") > NULL || FInput.Pos("\0031\00314") >
		NULL || FInput.Pos("\0032\00314") > NULL || FInput.Pos("\0033\00314") >
		NULL || FInput.Pos("\0034\00314") > NULL || FInput.Pos("\0035\00314") >
		NULL || FInput.Pos("\0036\00314") > NULL || FInput.Pos("\0037\00314") >
		NULL || FInput.Pos("\0038\00314") > NULL || FInput.Pos("\0039\00314") >
		NULL || FInput.Pos("\0030\00315") > NULL || FInput.Pos("\0031\00315") >
		NULL || FInput.Pos("\0032\00315") > NULL || FInput.Pos("\0033\00315") >
		NULL || FInput.Pos("\0034\00315") > NULL || FInput.Pos("\0035\00315") >
		NULL || FInput.Pos("\0036\00315") > NULL || FInput.Pos("\0037\00315") >
		NULL || FInput.Pos("\0038\00315") > NULL || FInput.Pos("\0039\00315") >
		NULL);

	// removing doublecolors
	do {
		//Application->ProcessMessages();

		if (FInput.Pos("\0030\0030")) {
			pos = FInput.Pos("\0030\0030");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0031\0030")) {
			pos = FInput.Pos("\0031\0030");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0032\0030")) {
			pos = FInput.Pos("\0032\0030");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0033\0030")) {
			pos = FInput.Pos("\0033\0030");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0034\0030")) {
			pos = FInput.Pos("\0034\0030");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0035\0030")) {
			pos = FInput.Pos("\0035\0030");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0036\0030")) {
			pos = FInput.Pos("\0036\0030");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0037\0030")) {
			pos = FInput.Pos("\0037\0030");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0038\0030")) {
			pos = FInput.Pos("\0038\0030");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0039\0030")) {
			pos = FInput.Pos("\0039\0030");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0030\0031")) {
			pos = FInput.Pos("\0030\0031");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0031\0031")) {
			pos = FInput.Pos("\0031\0031");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0032\0031")) {
			pos = FInput.Pos("\0032\0031");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0033\0031")) {
			pos = FInput.Pos("\0033\0031");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0034\0031")) {
			pos = FInput.Pos("\0034\0031");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0035\0031")) {
			pos = FInput.Pos("\0035\0031");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0036\0031")) {
			pos = FInput.Pos("\0036\0031");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0037\0031")) {
			pos = FInput.Pos("\0037\0031");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0038\0031")) {
			pos = FInput.Pos("\0038\0031");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0039\0031")) {
			pos = FInput.Pos("\0039\0031");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0030\0032")) {
			pos = FInput.Pos("\0030\0032");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+2);
		}

		if (FInput.Pos("\0031\0032")) {
			pos = FInput.Pos("\0031\0032");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0032\0032")) {
			pos = FInput.Pos("\0032\0032");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0033\0032")) {
			pos = FInput.Pos("\0033\0032");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0034\0032")) {
			pos = FInput.Pos("\0034\0032");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0035\0032")) {
			pos = FInput.Pos("\0035\0032");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0036\0032")) {
			pos = FInput.Pos("\0036\0032");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0037\0032")) {
			pos = FInput.Pos("\0037\0032");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0038\0032")) {
			pos = FInput.Pos("\0038\0032");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0039\0032")) {
			pos = FInput.Pos("\0039\0032");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0030\0033")) {
			pos = FInput.Pos("\0030\0033");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0031\0033")) {
			pos = FInput.Pos("\0031\0033");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0032\0033")) {
			pos = FInput.Pos("\0032\0033");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0033\0033")) {
			pos = FInput.Pos("\0033\0033");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0034\0033")) {
			pos = FInput.Pos("\0034\0033");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0035\0033")) {
			pos = FInput.Pos("\0035\0033");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0036\0033")) {
			pos = FInput.Pos("\0036\0033");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0037\0033")) {
			pos = FInput.Pos("\0037\0033");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0038\0033")) {
			pos = FInput.Pos("\0038\0033");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0039\0033")) {
			pos = FInput.Pos("\0039\0033");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0030\0034")) {
			pos = FInput.Pos("\0030\0034");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0031\0034")) {
			pos = FInput.Pos("\0031\0034");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0032\0034")) {
			pos = FInput.Pos("\0032\0034");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0033\0034")) {
			pos = FInput.Pos("\0033\0034");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0034\0034")) {
			pos = FInput.Pos("\0034\0034");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0035\0034")) {
			pos = FInput.Pos("\0035\0034");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0036\0034")) {
			pos = FInput.Pos("\0036\0034");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0037\0034")) {
			pos = FInput.Pos("\0037\0034");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0038\0034")) {
			pos = FInput.Pos("\0038\0034");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0039\0034")) {
			pos = FInput.Pos("\0039\0034");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0030\0035")) {
			pos = FInput.Pos("\0030\0035");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0031\0035")) {
			pos = FInput.Pos("\0031\0035");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0032\0035")) {
			pos = FInput.Pos("\0032\0035");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0033\0035")) {
			pos = FInput.Pos("\0033\0035");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0034\0035")) {
			pos = FInput.Pos("\0034\0035");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0035\0035")) {
			pos = FInput.Pos("\0035\0035");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0036\0035")) {
			pos = FInput.Pos("\0036\0035");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0037\0035")) {
			pos = FInput.Pos("\0037\0035");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0038\0035")) {
			pos = FInput.Pos("\0038\0035");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0039\0035")) {
			pos = FInput.Pos("\0039\0035");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0030\0036")) {
			pos = FInput.Pos("\0030\0036");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0031\0036")) {
			pos = FInput.Pos("\0031\0036");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0032\0036")) {
			pos = FInput.Pos("\0032\0036");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0033\0036")) {
			pos = FInput.Pos("\0033\0036");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0034\0036")) {
			pos = FInput.Pos("\0034\0036");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0035\0036")) {
			pos = FInput.Pos("\0035\0036");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0036\0036")) {
			pos = FInput.Pos("\0036\0036");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0037\0036")) {
			pos = FInput.Pos("\0037\0036");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0038\0036")) {
			pos = FInput.Pos("\0038\0036");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0039\0036")) {
			pos = FInput.Pos("\0039\0036");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0030\0037")) {
			pos = FInput.Pos("\0030\0037");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0031\0037")) {
			pos = FInput.Pos("\0031\0037");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0032\0037")) {
			pos = FInput.Pos("\0032\0037");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0033\0037")) {
			pos = FInput.Pos("\0033\0037");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0034\0037")) {
			pos = FInput.Pos("\0034\0037");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0035\0037")) {
			pos = FInput.Pos("\0035\0037");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0036\0037")) {
			pos = FInput.Pos("\0036\0037");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0037\0037")) {
			pos = FInput.Pos("\0037\0037");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0038\0037")) {
			pos = FInput.Pos("\0038\0037");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0039\0037")) {
			pos = FInput.Pos("\0039\0037");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0030\0038")) {
			pos = FInput.Pos("\0030\0038");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0031\0038")) {
			pos = FInput.Pos("\0031\0038");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0032\0038")) {
			pos = FInput.Pos("\0032\0038");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0033\0038")) {
			pos = FInput.Pos("\0033\0038");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0034\0038")) {
			pos = FInput.Pos("\0034\0038");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0035\0038")) {
			pos = FInput.Pos("\0035\0038");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0036\0038")) {
			pos = FInput.Pos("\0036\0038");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0037\0038")) {
			pos = FInput.Pos("\0037\0038");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0038\0038")) {
			pos = FInput.Pos("\0038\0038");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0039\0038")) {
			pos = FInput.Pos("\0039\0038");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0030\0039")) {
			pos = FInput.Pos("\0030\0039");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0031\0039")) {
			pos = FInput.Pos("\0031\0039");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0032\0039")) {
			pos = FInput.Pos("\0032\0039");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0033\0039")) {
			pos = FInput.Pos("\0033\0039");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0034\0039")) {
			pos = FInput.Pos("\0034\0039");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0035\0039")) {
			pos = FInput.Pos("\0035\0039");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0036\0039")) {
			pos = FInput.Pos("\0036\0039");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0037\0039")) {
			pos = FInput.Pos("\0037\0039");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0038\0039")) {
			pos = FInput.Pos("\0038\0039");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}

		if (FInput.Pos("\0039\0039")) {
			pos = FInput.Pos("\0039\0039");
			FInput.Delete(pos, 2);
			// FInput.Insert("0",pos+1);
		}
	}
	while (FInput.Pos("\0030\0030") > NULL || FInput.Pos("\0031\0030") >
		NULL || FInput.Pos("\0032\0030") > NULL || FInput.Pos("\0033\0030") >
		NULL || FInput.Pos("\0034\0030") > NULL || FInput.Pos("\0035\0030") >
		NULL || FInput.Pos("\0036\0030") > NULL || FInput.Pos("\0037\0030") >
		NULL || FInput.Pos("\0038\0030") > NULL || FInput.Pos("\0039\0030") >
		NULL || FInput.Pos("\0030\0031") > NULL || FInput.Pos("\0031\0031") >
		NULL || FInput.Pos("\0032\0031") > NULL || FInput.Pos("\0033\0031") >
		NULL || FInput.Pos("\0034\0031") > NULL || FInput.Pos("\0035\0031") >
		NULL || FInput.Pos("\0036\0031") > NULL || FInput.Pos("\0037\0031") >
		NULL || FInput.Pos("\0038\0031") > NULL || FInput.Pos("\0039\0031") >
		NULL || FInput.Pos("\0030\0032") > NULL || FInput.Pos("\0031\0032") >
		NULL || FInput.Pos("\0032\0032") > NULL || FInput.Pos("\0033\0032") >
		NULL || FInput.Pos("\0034\0032") > NULL || FInput.Pos("\0035\0032") >
		NULL || FInput.Pos("\0036\0032") > NULL || FInput.Pos("\0037\0032") >
		NULL || FInput.Pos("\0038\0032") > NULL || FInput.Pos("\0039\0032") >
		NULL || FInput.Pos("\0030\0033") > NULL || FInput.Pos("\0031\0033") >
		NULL || FInput.Pos("\0032\0033") > NULL || FInput.Pos("\0033\0033") >
		NULL || FInput.Pos("\0034\0033") > NULL || FInput.Pos("\0035\0033") >
		NULL || FInput.Pos("\0036\0033") > NULL || FInput.Pos("\0037\0033") >
		NULL || FInput.Pos("\0038\0033") > NULL || FInput.Pos("\0039\0033") >
		NULL || FInput.Pos("\0030\0034") > NULL || FInput.Pos("\0031\0034") >
		NULL || FInput.Pos("\0032\0034") > NULL || FInput.Pos("\0033\0034") >
		NULL || FInput.Pos("\0034\0034") > NULL || FInput.Pos("\0035\0034") >
		NULL || FInput.Pos("\0036\0034") > NULL || FInput.Pos("\0037\0034") >
		NULL || FInput.Pos("\0038\0034") > NULL || FInput.Pos("\0039\0034") >
		NULL || FInput.Pos("\0030\0035") > NULL || FInput.Pos("\0031\0035") >
		NULL || FInput.Pos("\0032\0035") > NULL || FInput.Pos("\0033\0035") >
		NULL || FInput.Pos("\0034\0035") > NULL || FInput.Pos("\0035\0035") >
		NULL || FInput.Pos("\0036\0035") > NULL || FInput.Pos("\0037\0035") >
		NULL || FInput.Pos("\0038\0035") > NULL || FInput.Pos("\0039\0035") >
		NULL || FInput.Pos("\0030\0036") > NULL || FInput.Pos("\0031\0036") >
		NULL || FInput.Pos("\0032\0036") > NULL || FInput.Pos("\0033\0036") >
		NULL || FInput.Pos("\0034\0036") > NULL || FInput.Pos("\0035\0036") >
		NULL || FInput.Pos("\0036\0036") > NULL || FInput.Pos("\0037\0036") >
		NULL || FInput.Pos("\0038\0036") > NULL || FInput.Pos("\0039\0036") >
		NULL || FInput.Pos("\0030\0037") > NULL || FInput.Pos("\0031\0037") >
		NULL || FInput.Pos("\0032\0037") > NULL || FInput.Pos("\0033\0037") >
		NULL || FInput.Pos("\0034\0037") > NULL || FInput.Pos("\0035\0037") >
		NULL || FInput.Pos("\0036\0037") > NULL || FInput.Pos("\0037\0037") >
		NULL || FInput.Pos("\0038\0037") > NULL || FInput.Pos("\0039\0037") >
		NULL || FInput.Pos("\0030\0038") > NULL || FInput.Pos("\0031\0038") >
		NULL || FInput.Pos("\0032\0038") > NULL || FInput.Pos("\0033\0038") >
		NULL || FInput.Pos("\0034\0038") > NULL || FInput.Pos("\0035\0038") >
		NULL || FInput.Pos("\0036\0038") > NULL || FInput.Pos("\0037\0038") >
		NULL || FInput.Pos("\0038\0038") > NULL || FInput.Pos("\0039\0038") >
		NULL || FInput.Pos("\0030\0039") > NULL || FInput.Pos("\0031\0039") >
		NULL || FInput.Pos("\0032\0039") > NULL || FInput.Pos("\0033\0039") >
		NULL || FInput.Pos("\0034\0039") > NULL || FInput.Pos("\0035\0039") >
		NULL || FInput.Pos("\0036\0039") > NULL || FInput.Pos("\0037\0039") >
		NULL || FInput.Pos("\0038\0039") > NULL || FInput.Pos("\0039\0039") >
		NULL);

	do {
		//Application->ProcessMessages();

		if (FInput.Pos("\0032")) {
			pos = FInput.Pos("\0032");
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0033")) {
			pos = FInput.Pos("\0033");
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0034")) {
			pos = FInput.Pos("\0034");
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0035")) {
			pos = FInput.Pos("\0035");
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0036")) {
			pos = FInput.Pos("\0036");
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0037")) {
			pos = FInput.Pos("\0037");
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0038")) {
			pos = FInput.Pos("\0038");
			FInput.Insert("0", pos + 1);
		}

		if (FInput.Pos("\0039")) {
			pos = FInput.Pos("\0039");
			FInput.Insert("0", pos + 1);
		}
	}
	while (FInput.Pos("\0032") > NULL || FInput.Pos("\0033") >
		NULL || FInput.Pos("\0034") > NULL || FInput.Pos("\0035") >
		NULL || FInput.Pos("\0036") > NULL || FInput.Pos("\0037") >
		NULL || FInput.Pos("\0038") > NULL || FInput.Pos("\0039") >
		NULL);

	for (a = 0; a < FInput.Length(); a++) {
		//Application->ProcessMessages();

		if (FInput.SubString(a, 2) == "\0030") // remove rest color doubles
		{
			check = FInput.SubString(a + 2, 1);

			if (check == "0" || check == "1" || check == "2" || check == "3" ||
				check == "4" || check == "5" || check == "6" || check == "7" ||
				check == "8" || check == "9") {
				//
			}
			else {
				FInput.Insert("0", a + 1);
			}
		}

		if (FInput.SubString(a, 2) == "\0031") // remove rest color doubles
		{
			check = FInput.SubString(a + 2, 1);

			if (check == "0" || check == "1" || check == "2" || check == "3" ||
				check == "4" || check == "5") {
				//
			}
			else {
				FInput.Insert("0", a + 1);
			}
		}
	}

 return FInput;
}

UnicodeString __fastcall TColorParser::RemStyles(UnicodeString Source)
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

 return FInput;
}

UnicodeString __fastcall TColorParser::RemEscapes(UnicodeString Source)
{
 int pos; //a
 UnicodeString FInput;
 FInput = Source;

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

  if(FInput.Pos("\x02") > NULL)
  {
   pos = FInput.Pos("\x02");
   FInput.Delete(pos, 1);
  }
 }
 while(FInput.Pos("\x02") > NULL);

 do
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\x03\00") > NULL)
  {
   pos = FInput.Pos("\x03\00");
   FInput.Delete(pos,3);
  }
 }
 while(FInput.Pos("\x03\00") > NULL);

 do
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\x03\01") > NULL)
  {
   pos = FInput.Pos("\x03\01");
   FInput.Delete(pos,3);
  }
 }
 while(FInput.Pos("\x03\01") > NULL);

 do
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\x03\02") > NULL)
  {
   pos = FInput.Pos("\x03\02");
   FInput.Delete(pos,3);
  }
 }
 while(FInput.Pos("\x03\02") > NULL);

 do
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\x03\03") > NULL)
  {
   pos = FInput.Pos("\x03\03");
   FInput.Delete(pos,3);
  }
 }
 while(FInput.Pos("\x03\03") > NULL);

 do
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\x03\04") > NULL)
  {
   pos = FInput.Pos("\x03\04");
   FInput.Delete(pos,3);
  }
 }
 while(FInput.Pos("\x03\04") > NULL);

 do
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\x03\05") > NULL)
  {
   pos = FInput.Pos("\x03\05");
   FInput.Delete(pos,3);
  }
 }
 while(FInput.Pos("\x03\05") > NULL);

 do
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\x03\06") > NULL)
  {
   pos = FInput.Pos("\x03\06");
   FInput.Delete(pos,3);
  }
 }
 while(FInput.Pos("\x03\06") > NULL);

 do
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\x03\07") > NULL)
  {
   pos = FInput.Pos("\x03\07");
   FInput.Delete(pos,3);
  }
 }
 while(FInput.Pos("\x03\07") > NULL);

 do
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\x03\08") > NULL)
  {
   pos = FInput.Pos("\x03\08");
   FInput.Delete(pos,3);
  }
 }
 while(FInput.Pos("\x03\08") > NULL);

 do
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\x03\09") > NULL)
  {
   pos = FInput.Pos("\x03\09");
   FInput.Delete(pos,3);
  }
 }
 while(FInput.Pos("\x03\09") > NULL);

 do
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\x03\10") > NULL)
  {
   pos = FInput.Pos("\x03\10");
   FInput.Delete(pos,3);
  }
 }
 while(FInput.Pos("\x03\10") > NULL);

 do
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\x03\11") > NULL)
  {
   pos = FInput.Pos("\x03\11");
   FInput.Delete(pos,3);
  }
 }
 while(FInput.Pos("\x03\11") > NULL);

 do
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\x03\12") > NULL)
  {
   pos = FInput.Pos("\x03\12");
   FInput.Delete(pos,3);
  }
 }
 while(FInput.Pos("\x03\12") > NULL);

 do
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\x03\13") > NULL)
  {
   pos = FInput.Pos("\x03\13");
   FInput.Delete(pos,3);
  }
 }
 while(FInput.Pos("\x03\13") > NULL);

 do
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\x03\14") > NULL)
  {
   pos = FInput.Pos("\x03\14");
   FInput.Delete(pos,3);
  }
 }
 while(FInput.Pos("\x03\14") > NULL);

 do
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\x03\15") > NULL)
  {
   pos = FInput.Pos("\x03\15");
   FInput.Delete(pos,3);
  }
 }
 while(FInput.Pos("\x03\15") > NULL);

 do
 {
  //Application->ProcessMessages();

  if(FInput.Pos("\x03") > NULL)
  {
   pos = FInput.Pos("\x03");
   FInput.Delete(pos, 1);
  }
 }
 while(FInput.Pos("\x03") > NULL);

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


 return FInput;
}


UnicodeString __fastcall TColorParser::PrepareLine(UnicodeString Line)
{
 int pos,a;
 UnicodeString pre,txt,col;

 //wrap  this unicode "♠" to " "  a space
 //this unicode produce a weird rtf
 Line = Line + " ";  //try to add a space to the end of line 23.01.2021

 do
 {
  if(Line.Pos("\x07") > NULL)
  {
   pos = Line.Pos("\x07");
   Line.Delete(pos,1);
   //Line.Insert("�",pos);
  }
 }
 while(Line.Pos("\x07") > NULL);

 //////////////////////////////
 //new Feb. 2021 parse out pairs befor the 1st letter
 // ColorPairs
 if(Line.Pos("\x03\x02\x03"))
 {
  //check if this pairs are the 1st control chars in a line
  pos = Line.Pos("\x03");

  if(Line.SubString(1,pos-1).Pos("\x02") > 0 || Line.SubString(1,pos-1).Pos("\x03") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x0F") > 0 || Line.SubString(1,pos-1).Pos("\x1D") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x1F") > 0 || Line.SubString(1,pos-1).Pos("\x1E") > 0 ||
	 Line.SubString(1,pos-1).Pos("\016") > 0 || Line.SubString(1,pos-1).Pos("\017") > 0)
  {
   //do nothing
  }
  else
  {
   pos = Line.Pos("\x03\x02\x03");
   Line.Delete(pos,1);
  }
 }

 if(Line.Pos("\x03\x1D\x03"))
 {
  //check if this pairs are the 1st control chars in a line
  pos = Line.Pos("\x03");

  if(Line.SubString(1,pos-1).Pos("\x02") > 0 || Line.SubString(1,pos-1).Pos("\x03") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x0F") > 0 || Line.SubString(1,pos-1).Pos("\x1D") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x1F") > 0 || Line.SubString(1,pos-1).Pos("\x1E") > 0 ||
	 Line.SubString(1,pos-1).Pos("\016") > 0 || Line.SubString(1,pos-1).Pos("\017") > 0)
  {
   //do nothing
  }
  else
  {
   pos = Line.Pos("\x03\x1D\x03");
   Line.Delete(pos,1);
  }
 }

 if(Line.Pos("\x03\x0F\x03"))
 {
  //check if this pairs are the 1st control chars in a line
  pos = Line.Pos("\x03");

  if(Line.SubString(1,pos-1).Pos("\x02") > 0 || Line.SubString(1,pos-1).Pos("\x03") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x0F") > 0 || Line.SubString(1,pos-1).Pos("\x1D") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x1F") > 0 || Line.SubString(1,pos-1).Pos("\x1E") > 0 ||
	 Line.SubString(1,pos-1).Pos("\016") > 0 || Line.SubString(1,pos-1).Pos("\017") > 0)
  {
   //do nothing
  }
  else
  {
   pos = Line.Pos("\x03\x0F\x03");
   Line.Delete(pos,2);
  }
 }

 if(Line.Pos("\x03\x1F\x03"))
 {
  //check if this pairs are the 1st control chars in a line
  pos = Line.Pos("\x03");

  if(Line.SubString(1,pos-1).Pos("\x02") > 0 || Line.SubString(1,pos-1).Pos("\x03") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x0F") > 0 || Line.SubString(1,pos-1).Pos("\x1D") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x1F") > 0 || Line.SubString(1,pos-1).Pos("\x1E") > 0 ||
	 Line.SubString(1,pos-1).Pos("\016") > 0 || Line.SubString(1,pos-1).Pos("\017") > 0)
  {
   //do nothing
  }
  else
  {
   pos = Line.Pos("\x03\x1F\x03");
   Line.Delete(pos,1);
  }
 }

 if(Line.Pos("\x03\x1E\x03"))
 {
  //check if this pairs are the 1st control chars in a line
  pos = Line.Pos("\x03");

  if(Line.SubString(1,pos-1).Pos("\x02") > 0 || Line.SubString(1,pos-1).Pos("\x03") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x0F") > 0 || Line.SubString(1,pos-1).Pos("\x1D") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x1F") > 0 || Line.SubString(1,pos-1).Pos("\x1E") > 0 ||
	 Line.SubString(1,pos-1).Pos("\016") > 0 || Line.SubString(1,pos-1).Pos("\017") > 0)
  {
   //do nothing
  }
  else
  {
   pos = Line.Pos("\x03\x1E\x03");
   Line.Delete(pos,1);
  }
 }

 // ColorPairs
 if(Line.Pos("\x02\x03\x02"))
 {
  //check if this pairs are the 1st control chars in a line
  pos = Line.Pos("\x02");

  if(Line.SubString(1,pos-1).Pos("\x02") > 0 || Line.SubString(1,pos-1).Pos("\x03") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x0F") > 0 || Line.SubString(1,pos-1).Pos("\x1D") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x1F") > 0 || Line.SubString(1,pos-1).Pos("\x1E") > 0 ||
	 Line.SubString(1,pos-1).Pos("\016") > 0 || Line.SubString(1,pos-1).Pos("\017") > 0)
  {
   //do nothing
  }
  else
  {
   pos = Line.Pos("\x02\x03\x02");
   Line.Delete(pos,1);
  }
 }

 if(Line.Pos("\x02\x1D\x02"))
 {
  //check if this pairs are the 1st control chars in a line
  pos = Line.Pos("\x02");

  if(Line.SubString(1,pos-1).Pos("\x02") > 0 || Line.SubString(1,pos-1).Pos("\x03") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x0F") > 0 || Line.SubString(1,pos-1).Pos("\x1D") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x1F") > 0 || Line.SubString(1,pos-1).Pos("\x1E") > 0 ||
	 Line.SubString(1,pos-1).Pos("\016") > 0 || Line.SubString(1,pos-1).Pos("\017") > 0)
  {
   //do nothing
  }
  else
  {
   pos = Line.Pos("\x02\x1D\x02");
   Line.Delete(pos,1);
  }
 }

 if(Line.Pos("\x02\x0F\x02"))
 {
  //check if this pairs are the 1st control chars in a line
  pos = Line.Pos("\x02");

  if(Line.SubString(1,pos-1).Pos("\x02") > 0 || Line.SubString(1,pos-1).Pos("\x03") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x0F") > 0 || Line.SubString(1,pos-1).Pos("\x1D") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x1F") > 0 || Line.SubString(1,pos-1).Pos("\x1E") > 0 ||
	 Line.SubString(1,pos-1).Pos("\016") > 0 || Line.SubString(1,pos-1).Pos("\017") > 0)
  {
   //do nothing
  }
  else
  {
   pos = Line.Pos("\x02\x0F\x02");
   Line.Delete(pos,1);
  }
 }

 if(Line.Pos("\x02\x1F\x02"))
 {
  //check if this pairs are the 1st control chars in a line
  pos = Line.Pos("\x02");

  if(Line.SubString(1,pos-1).Pos("\x02") > 0 || Line.SubString(1,pos-1).Pos("\x03") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x0F") > 0 || Line.SubString(1,pos-1).Pos("\x1D") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x1F") > 0 || Line.SubString(1,pos-1).Pos("\x1E") > 0 ||
	 Line.SubString(1,pos-1).Pos("\016") > 0 || Line.SubString(1,pos-1).Pos("\017") > 0)
  {
   //do nothing
  }
  else
  {
   pos = Line.Pos("\x02\x1F\x02");
   Line.Delete(pos,1);
  }
 }

 if(Line.Pos("\x02\x1E\x02"))
 {
  //check if this pairs are the 1st control chars in a line
  pos = Line.Pos("\x02");

  if(Line.SubString(1,pos-1).Pos("\x02") > 0 || Line.SubString(1,pos-1).Pos("\x03") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x0F") > 0 || Line.SubString(1,pos-1).Pos("\x1D") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x1F") > 0 || Line.SubString(1,pos-1).Pos("\x1E") > 0 ||
	 Line.SubString(1,pos-1).Pos("\016") > 0 || Line.SubString(1,pos-1).Pos("\017") > 0)
  {
   //do nothing
  }
  else
  {
   pos = Line.Pos("\x02\x1E\x02");
   Line.Delete(pos,1);
  }
 }

 // ColorPairs
 if(Line.Pos("\x1D\x03\x1D"))
 {
  //check if this pairs are the 1st control chars in a line
  pos = Line.Pos("\x1D");

  if(Line.SubString(1,pos-1).Pos("\x02") > 0 || Line.SubString(1,pos-1).Pos("\x03") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x0F") > 0 || Line.SubString(1,pos-1).Pos("\x1D") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x1F") > 0 || Line.SubString(1,pos-1).Pos("\x1E") > 0 ||
	 Line.SubString(1,pos-1).Pos("\016") > 0 || Line.SubString(1,pos-1).Pos("\017") > 0)
  {
   //do nothing
  }
  else
  {
   pos = Line.Pos("\x1D\x03\x1D");
   Line.Delete(pos,1);
  }
 }

 if(Line.Pos("\x1D\x02\x1D"))
 {
  //check if this pairs are the 1st control chars in a line
  pos = Line.Pos("\x1D");

  if(Line.SubString(1,pos-1).Pos("\x02") > 0 || Line.SubString(1,pos-1).Pos("\x03") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x0F") > 0 || Line.SubString(1,pos-1).Pos("\x1D") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x1F") > 0 || Line.SubString(1,pos-1).Pos("\x1E") > 0 ||
	 Line.SubString(1,pos-1).Pos("\016") > 0 || Line.SubString(1,pos-1).Pos("\017") > 0)
  {
   //do nothing
  }
  else
  {
   pos = Line.Pos("\x1D\x02\x1D");
   Line.Delete(pos,1);
  }
 }

 if(Line.Pos("\x1D\x0F\x1D"))
 {
  //check if this pairs are the 1st control chars in a line
  pos = Line.Pos("\x1D");

  if(Line.SubString(1,pos-1).Pos("\x02") > 0 || Line.SubString(1,pos-1).Pos("\x03") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x0F") > 0 || Line.SubString(1,pos-1).Pos("\x1D") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x1F") > 0 || Line.SubString(1,pos-1).Pos("\x1E") > 0 ||
	 Line.SubString(1,pos-1).Pos("\016") > 0 || Line.SubString(1,pos-1).Pos("\017") > 0)
  {
   //do nothing
  }
  else
  {
   pos = Line.Pos("\x1D\x0F\x1D");
   Line.Delete(pos,1);
  }
 }

 if(Line.Pos("\x1D\x1F\x1D"))
 {
  //check if this pairs are the 1st control chars in a line
  pos = Line.Pos("\x1D");

  if(Line.SubString(1,pos-1).Pos("\x02") > 0 || Line.SubString(1,pos-1).Pos("\x03") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x0F") > 0 || Line.SubString(1,pos-1).Pos("\x1D") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x1F") > 0 || Line.SubString(1,pos-1).Pos("\x1E") > 0 ||
	 Line.SubString(1,pos-1).Pos("\016") > 0 || Line.SubString(1,pos-1).Pos("\017") > 0)
  {
   //do nothing
  }
  else
  {
   pos = Line.Pos("\x1D\x1F\x1D");
   Line.Delete(pos,1);
  }
 }

 if(Line.Pos("\x1D\x1E\x1D"))
 {
  //check if this pairs are the 1st control chars in a line
  pos = Line.Pos("\x1D");

  if(Line.SubString(1,pos-1).Pos("\x02") > 0 || Line.SubString(1,pos-1).Pos("\x03") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x0F") > 0 || Line.SubString(1,pos-1).Pos("\x1D") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x1F") > 0 || Line.SubString(1,pos-1).Pos("\x1E") > 0 ||
	 Line.SubString(1,pos-1).Pos("\016") > 0 || Line.SubString(1,pos-1).Pos("\017") > 0)
  {
   //do nothing
  }
  else
  {
   pos = Line.Pos("\x1D\x1E\x1D");
   Line.Delete(pos,1);
  }
 }

 // ColorPairs
 if(Line.Pos("\x0F\x03\x0F"))
 {
  //check if this pairs are the 1st control chars in a line
  pos = Line.Pos("\x0F");

  if(Line.SubString(1,pos-1).Pos("\x02") > 0 || Line.SubString(1,pos-1).Pos("\x03") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x0F") > 0 || Line.SubString(1,pos-1).Pos("\x1D") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x1F") > 0 || Line.SubString(1,pos-1).Pos("\x1E") > 0 ||
	 Line.SubString(1,pos-1).Pos("\016") > 0 || Line.SubString(1,pos-1).Pos("\017") > 0)
  {
   //do nothing
  }
  else
  {
   pos = Line.Pos("\x0F\x03\x0F");
   Line.Delete(pos,1);
  }
 }


 if(Line.Pos("\x0F\x02\x0F"))
 {
  //check if this pairs are the 1st control chars in a line
  pos = Line.Pos("\x0F");

  if(Line.SubString(1,pos-1).Pos("\x02") > 0 || Line.SubString(1,pos-1).Pos("\x03") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x0F") > 0 || Line.SubString(1,pos-1).Pos("\x1D") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x1F") > 0 || Line.SubString(1,pos-1).Pos("\x1E") > 0 ||
	 Line.SubString(1,pos-1).Pos("\016") > 0 || Line.SubString(1,pos-1).Pos("\017") > 0)
  {
   //do nothing
  }
  else
  {
   pos = Line.Pos("\x0F\x02\x0F");
   Line.Delete(pos,1);
  }
 }

 if(Line.Pos("\x0F\x1D\x0F"))
 {
  //check if this pairs are the 1st control chars in a line
  pos = Line.Pos("\x0F");

  if(Line.SubString(1,pos-1).Pos("\x02") > 0 || Line.SubString(1,pos-1).Pos("\x03") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x0F") > 0 || Line.SubString(1,pos-1).Pos("\x1D") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x1F") > 0 || Line.SubString(1,pos-1).Pos("\x1E") > 0 ||
	 Line.SubString(1,pos-1).Pos("\016") > 0 || Line.SubString(1,pos-1).Pos("\017") > 0)
  {
   //do nothing
  }
  else
  {
   pos = Line.Pos("\x0F\x1D\x0F");
   Line.Delete(pos,1);
  }
 }

 if(Line.Pos("\x0F\x1F\x0F"))
 {
  //check if this pairs are the 1st control chars in a line
  pos = Line.Pos("\x0F");

  if(Line.SubString(1,pos-1).Pos("\x02") > 0 || Line.SubString(1,pos-1).Pos("\x03") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x0F") > 0 || Line.SubString(1,pos-1).Pos("\x1D") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x1F") > 0 || Line.SubString(1,pos-1).Pos("\x1E") > 0 ||
	 Line.SubString(1,pos-1).Pos("\016") > 0 || Line.SubString(1,pos-1).Pos("\017") > 0)
  {
   //do nothing
  }
  else
  {
   pos = Line.Pos("\x0F\x1F\x0F");
   Line.Delete(pos,1);
  }
 }

 if(Line.Pos("\x0F\x1E\x0F"))
 {
  //check if this pairs are the 1st control chars in a line
  pos = Line.Pos("\x0F");

  if(Line.SubString(1,pos-1).Pos("\x02") > 0 || Line.SubString(1,pos-1).Pos("\x03") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x0F") > 0 || Line.SubString(1,pos-1).Pos("\x1D") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x1F") > 0 || Line.SubString(1,pos-1).Pos("\x1E") > 0 ||
	 Line.SubString(1,pos-1).Pos("\016") > 0 || Line.SubString(1,pos-1).Pos("\017") > 0)
  {
   //do nothing
  }
  else
  {
   pos = Line.Pos("\x0F\x1E\x0F");
   Line.Delete(pos,1);
  }
 }


 // ColorPairs
 if(Line.Pos("\x1F\x03\x1F"))
 {
  //check if this pairs are the 1st control chars in a line
  pos = Line.Pos("\x1F");

  if(Line.SubString(1,pos-1).Pos("\x02") > 0 || Line.SubString(1,pos-1).Pos("\x03") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x0F") > 0 || Line.SubString(1,pos-1).Pos("\x1D") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x1F") > 0 || Line.SubString(1,pos-1).Pos("\x1E") > 0 ||
	 Line.SubString(1,pos-1).Pos("\016") > 0 || Line.SubString(1,pos-1).Pos("\017") > 0)
  {
   //do nothing
  }
  else
  {
   pos = Line.Pos("\x1F\x03\x1F");
   Line.Delete(pos,1);
  }
 }

 if(Line.Pos("\x1F\x02\x1F"))
 {
  //check if this pairs are the 1st control chars in a line
  pos = Line.Pos("\x1F");

  if(Line.SubString(1,pos-1).Pos("\x02") > 0 || Line.SubString(1,pos-1).Pos("\x03") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x0F") > 0 || Line.SubString(1,pos-1).Pos("\x1D") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x1F") > 0 || Line.SubString(1,pos-1).Pos("\x1E") > 0 ||
	 Line.SubString(1,pos-1).Pos("\016") > 0 || Line.SubString(1,pos-1).Pos("\017") > 0)
  {
   //do nothing
  }
  else
  {
   pos = Line.Pos("\x1F\x02\x1F");
   Line.Delete(pos,1);
  }
 }

 if(Line.Pos("\x1F\x1D\x1F"))
 {
  //check if this pairs are the 1st control chars in a line
  pos = Line.Pos("\x1F");

  if(Line.SubString(1,pos-1).Pos("\x02") > 0 || Line.SubString(1,pos-1).Pos("\x03") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x0F") > 0 || Line.SubString(1,pos-1).Pos("\x1D") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x1F") > 0 || Line.SubString(1,pos-1).Pos("\x1E") > 0 ||
	 Line.SubString(1,pos-1).Pos("\016") > 0 || Line.SubString(1,pos-1).Pos("\017") > 0)
  {
   //do nothing
  }
  else
  {
   pos = Line.Pos("\x1F\x1D\x1F");
   Line.Delete(pos,1);
  }
 }

 if(Line.Pos("\x1F\x0F\x1F"))
 {
  //check if this pairs are the 1st control chars in a line
  pos = Line.Pos("\x1F");

  if(Line.SubString(1,pos-1).Pos("\x02") > 0 || Line.SubString(1,pos-1).Pos("\x03") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x0F") > 0 || Line.SubString(1,pos-1).Pos("\x1D") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x1F") > 0 || Line.SubString(1,pos-1).Pos("\x1E") > 0 ||
	 Line.SubString(1,pos-1).Pos("\016") > 0 || Line.SubString(1,pos-1).Pos("\017") > 0)
  {
   //do nothing
  }
  else
  {
   pos = Line.Pos("\x1F\x0F\x1F");
   Line.Delete(pos,1);
  }
 }

 if(Line.Pos("\x1F\x1E\x1F"))
 {
  //check if this pairs are the 1st control chars in a line
  pos = Line.Pos("\x1F");

  if(Line.SubString(1,pos-1).Pos("\x02") > 0 || Line.SubString(1,pos-1).Pos("\x03") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x0F") > 0 || Line.SubString(1,pos-1).Pos("\x1D") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x1F") > 0 || Line.SubString(1,pos-1).Pos("\x1E") > 0 ||
	 Line.SubString(1,pos-1).Pos("\016") > 0 || Line.SubString(1,pos-1).Pos("\017") > 0)
  {
   //do nothing
  }
  else
  {
   pos = Line.Pos("\x1F\x1E\x1F");
   Line.Delete(pos,1);
  }
 }


 // ColorPairs
 if(Line.Pos("\x1E\x03\x1E"))
 {
  //check if this pairs are the 1st control chars in a line
  pos = Line.Pos("\x1E");

  if(Line.SubString(1,pos-1).Pos("\x02") > 0 || Line.SubString(1,pos-1).Pos("\x03") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x0F") > 0 || Line.SubString(1,pos-1).Pos("\x1D") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x1F") > 0 || Line.SubString(1,pos-1).Pos("\x1E") > 0 ||
	 Line.SubString(1,pos-1).Pos("\016") > 0 || Line.SubString(1,pos-1).Pos("\017") > 0)
  {
   //do nothing
  }
  else
  {
   pos = Line.Pos("\x1E\x03\x1E");
   Line.Delete(pos,1);
  }
 }

 if(Line.Pos("\x1E\x02\x1E"))
 {
  //check if this pairs are the 1st control chars in a line
  pos = Line.Pos("\x1E");

  if(Line.SubString(1,pos-1).Pos("\x02") > 0 || Line.SubString(1,pos-1).Pos("\x03") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x0F") > 0 || Line.SubString(1,pos-1).Pos("\x1D") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x1F") > 0 || Line.SubString(1,pos-1).Pos("\x1E") > 0 ||
	 Line.SubString(1,pos-1).Pos("\016") > 0 || Line.SubString(1,pos-1).Pos("\017") > 0)
  {
   //do nothing
  }
  else
  {
   pos = Line.Pos("\x1E\x02\x1E");
   Line.Delete(pos,1);
  }
 }

 if(Line.Pos("\x1E\x1D\x1E"))
 {
  //check if this pairs are the 1st control chars in a line
  pos = Line.Pos("\x1E");

  if(Line.SubString(1,pos-1).Pos("\x02") > 0 || Line.SubString(1,pos-1).Pos("\x03") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x0F") > 0 || Line.SubString(1,pos-1).Pos("\x1D") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x1F") > 0 || Line.SubString(1,pos-1).Pos("\x1E") > 0 ||
	 Line.SubString(1,pos-1).Pos("\016") > 0 || Line.SubString(1,pos-1).Pos("\017") > 0)
  {
   //do nothing
  }
  else
  {
   pos = Line.Pos("\x1E\x1D\x1E");
   Line.Delete(pos,1);
  }
 }

 if(Line.Pos("\x1E\x0F\x1E"))
 {
  //check if this pairs are the 1st control chars in a line
  pos = Line.Pos("\x1E");

  if(Line.SubString(1,pos-1).Pos("\x02") > 0 || Line.SubString(1,pos-1).Pos("\x03") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x0F") > 0 || Line.SubString(1,pos-1).Pos("\x1D") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x1F") > 0 || Line.SubString(1,pos-1).Pos("\x1E") > 0 ||
	 Line.SubString(1,pos-1).Pos("\016") > 0 || Line.SubString(1,pos-1).Pos("\017") > 0)
  {
   //do nothing
  }
  else
  {
   pos = Line.Pos("\x1E\x0F\x1E");
   Line.Delete(pos,1);
  }
 }

 if(Line.Pos("\x1E\x1F\x1E"))
 {
  //check if this pairs are the 1st control chars in a line
  pos = Line.Pos("\x1E");

  if(Line.SubString(1,pos-1).Pos("\x02") > 0 || Line.SubString(1,pos-1).Pos("\x03") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x0F") > 0 || Line.SubString(1,pos-1).Pos("\x1D") > 0 ||
	 Line.SubString(1,pos-1).Pos("\x1F") > 0 || Line.SubString(1,pos-1).Pos("\x1E") > 0 ||
	 Line.SubString(1,pos-1).Pos("\016") > 0 || Line.SubString(1,pos-1).Pos("\017") > 0)
  {
   //do nothing
  }
  else
  {
   pos = Line.Pos("\x1E\x1F\x1E");
   Line.Delete(pos,1);
  }
 }
 //////////////////////////////




	do // change into mirc colorformat above 16 colors
	{
	 bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
	 Application->ProcessMessages();

	 dbl_flag = false;

	 if(Line.Pos("\0030,"))
	 {
	  try
	  {
	   pos = Line.Pos("\0030,");
	   pre = Line.SubString(pos + 3, 2);
	   a = pre.ToInt();
	   dbl_flag = true;
	  }
	  catch(Exception &exception)
	  {
	   //
	   try
	   {
		pos = Line.Pos("\0030,");
		pre = Line.SubString(pos + 3, 1);
		a = pre.ToInt();
	   }
	   catch(Exception &exception)
	   {
		return Line;
	   }
	  }

	  if(a > 9)
	  {
	   Line.Delete(pos + 2,3);
	  }

	  if(a < 10)
	  {
	   if(dbl_flag == false)
	   {
		Line.Delete(pos + 2, 2);
	   }
	   else
	   {
		Line.Delete(pos + 2,3);
		dbl_flag = false;
	   }
	  }
	 }
	}
	while (Line.Pos("\0030,") > NULL);

	do // change into mirc colorformat above 16 colors
	{
	 bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
	 Application->ProcessMessages();

	 dbl_flag = false;

	 if(Line.Pos("\0031,"))
	 {
	  try
	  {
	   pos = Line.Pos("\0031,");
	   pre = Line.SubString(pos + 3, 2);
	   a = pre.ToInt();
	   dbl_flag = true;
	  }
	  catch(Exception &exception)
	  {
	   //
	   try
	   {
		pos = Line.Pos("\0031,");
		pre = Line.SubString(pos + 3, 1);
		a = pre.ToInt();
	   }
	   catch(Exception &exception)
	   {
		return Line;
	   }
	  }

	  if(a > 9)
	  {
	   Line.Delete(pos + 2, 3);
	  }

	  if(a < 10)
	  {
	   if(dbl_flag == false)
	   {
		Line.Delete(pos + 2, 2);
	   }
	   else
	   {
		Line.Delete(pos + 2, 3);
		dbl_flag = false;
	   }
	  }
	 }
	}
	while (Line.Pos("\0031,") > NULL);


	do // change into mirc colorformat above 16 colors
	{
	 bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
	 Application->ProcessMessages();

	 dbl_flag = false;

	 if(Line.Pos("\0032,"))
	 {
	  try
	  {
	   pos = Line.Pos("\0032,");
	   pre = Line.SubString(pos + 3, 2);
	   a = pre.ToInt();
	   dbl_flag = true;
	  }
	  catch(Exception &exception)
	  {
	   //
	   try
	   {
		pos = Line.Pos("\0032,");
		pre = Line.SubString(pos + 3, 1);
		a = pre.ToInt();
	   }
	   catch(Exception &exception)
	   {
		return Line;
	   }
	  }

	  if(a > 9)
	  {
	   Line.Delete(pos + 2, 3);
	  }

	  if(a < 10)
	  {
	   if(dbl_flag == false)
	   {
		Line.Delete(pos + 2, 2);
	   }
	   else
	   {
		Line.Delete(pos + 2, 3);
		dbl_flag = false;
	   }
	  }
	 }
	}
	while (Line.Pos("\0032,") > NULL);


	do // change into mirc colorformat above 16 colors
	{
     bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
	 Application->ProcessMessages();

	 dbl_flag = false;

	 if(Line.Pos("\0033,"))
	 {
	  try
	  {
	   pos = Line.Pos("\0033,");
	   pre = Line.SubString(pos + 3, 2);
	   a = pre.ToInt();
	   dbl_flag = true;
	  }
	  catch(Exception &exception)
	  {
	   //
	   try
	   {
		pos = Line.Pos("\0033,");
		pre = Line.SubString(pos + 3, 1);
		a = pre.ToInt();
	   }
	   catch(Exception &exception)
	   {
		return Line;
	   }
	  }

	  if(a > 9)
	  {
	   Line.Delete(pos + 2, 3);
	  }

	  if(a < 10)
	   {
	   if(dbl_flag == false)
	   {
		Line.Delete(pos + 2, 2);
	   }
	   else
	   {
		Line.Delete(pos + 2, 3);
		dbl_flag = false;
	   }
	  }
	 }
	}
	while(Line.Pos("\0033,") > NULL);


	do // change into mirc colorformat above 16 colors
	{
	 bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
	 Application->ProcessMessages();

	 dbl_flag = false;

	 if(Line.Pos("\0034,"))
	 {
	  pos = Line.Pos("\0034,");
	  pre = Line.SubString(pos + 3,2);

	  try
	  {
	   pos = Line.Pos("\0034,");
	   pre = Line.SubString(pos + 3,2);
	   a = pre.ToInt();
	   dbl_flag = true;
	  }
	  catch(Exception &exception)
	  {
	   try
	   {
		pos = Line.Pos("\0034,");
		pre = Line.SubString(pos + 3, 1);
		a = pre.ToInt();
	   }
	   catch(Exception &exception)
	   {
		return Line;
	   }
	  }

	  if(a > 9)
	  {
	   Line.Delete(pos + 2, 3);
	  }

	  if(a < 10)
	  {
	   if(dbl_flag == false)
	   {
		Line.Delete(pos + 2, 2);
	   }
	   else
	   {
		Line.Delete(pos + 2, 3);
		dbl_flag = false;
	   }
	  }
	 }
	}
	while(Line.Pos("\0034,") > NULL);


	do // change into mirc colorformat above 16 colors
	{
	 bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
	 Application->ProcessMessages();

	 dbl_flag = false;

	 if(Line.Pos("\0035,"))
	 {
	  try
	  {
	   pos = Line.Pos("\0035,");
	   pre = Line.SubString(pos + 3, 2);
	   a = pre.ToInt();
	   dbl_flag = true;
	  }
	  catch (Exception &exception)
	  {
	   //
	   try
	   {
		pos = Line.Pos("\0035,");
		pre = Line.SubString(pos + 3, 1);
		a = pre.ToInt();
	   }
	   catch(Exception &exception)
	   {
		return Line;
	   }
	  }

	  if(a > 9)
	  {
	   Line.Delete(pos + 2, 3);
	  }

	  if(a < 10)
	  {
	   if(dbl_flag == false)
	   {
		Line.Delete(pos + 2, 2);
	   }
	   else
	   {
		Line.Delete(pos + 2, 3);
		dbl_flag = false;
	   }
	  }
	 }
	}
	while (Line.Pos("\0035,") > NULL);

	do // change into mirc colorformat above 16 colors
	{
	 bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
	 Application->ProcessMessages();

	 dbl_flag = false;

	 if(Line.Pos("\0036,"))
	 {
	  try
	  {
	   pos = Line.Pos("\0036,");
	   pre = Line.SubString(pos + 3, 2);
	   a = pre.ToInt();
	   dbl_flag = true;
	  }
	  catch(Exception &exception)
	  {
	   //
	   try
	   {
		pos = Line.Pos("\0036,");
		pre = Line.SubString(pos + 3, 1);
		a = pre.ToInt();
	   }
	   catch(Exception &exception)
	   {
		return Line;
	   }
	  }

	  if(a > 9)
	  {
	   Line.Delete(pos + 2, 3);
	  }

	  if(a < 10)
	  {
	   if(dbl_flag == false)
	   {
		Line.Delete(pos + 2, 2);
	   }
	   else
	   {
		Line.Delete(pos + 2, 3);
		dbl_flag = false;
	   }
	  }
	 }
	}
	while (Line.Pos("\0036,") > NULL);

	do // change into mirc colorformat above 16 colors
	{
	 bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
	 Application->ProcessMessages();

	 dbl_flag = false;

	 if(Line.Pos("\0037,"))
	 {
	  try
	  {
	   pos = Line.Pos("\0037,");
	   pre = Line.SubString(pos + 3, 2);
	   a = pre.ToInt();
	   dbl_flag = true;
	  }
	  catch(Exception &exception)
	  {
	   //
	   try
	   {
		pos = Line.Pos("\0037,");
		pre = Line.SubString(pos + 3, 1);
		a = pre.ToInt();
	   }
	   catch(Exception &exception)
	   {
		return Line;
	   }
	  }

	  if(a > 9)
	  {
	   Line.Delete(pos + 2, 3);
	  }

	  if(a < 10)
	  {
	   if(dbl_flag == false)
	   {
		Line.Delete(pos + 2, 2);
	   }
	   else
	   {
		Line.Delete(pos + 2, 3);
		dbl_flag = false;
	   }
	  }
	 }
	}
	while (Line.Pos("\0037,") > NULL);

	do // change into mirc colorformat above 16 colors
	{
	 bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
	 Application->ProcessMessages();

	 dbl_flag = false;

	 if(Line.Pos("\0038,"))
	 {
	  try
	  {
	   pos = Line.Pos("\0038,");
	   pre = Line.SubString(pos + 3, 2);
	   a = pre.ToInt();
	   dbl_flag = true;
	  }
	  catch(Exception &exception)
	  {
	   //
	   try
	   {
		pos = Line.Pos("\0038,");
		pre = Line.SubString(pos + 3, 1);
		a = pre.ToInt();
	   }
	   catch(Exception &exception)
	   {
		return Line;
	   }
	  }

	  if(a > 9)
	  {
	   Line.Delete(pos + 2, 3);
	  }

	  if(a < 10)
	  {
	   if(dbl_flag == false)
	   {
		Line.Delete(pos + 2, 2);
	   }
	   else
	   {
		Line.Delete(pos + 2, 3);
		dbl_flag = false;
	   }
	  }
	 }
	}
	while (Line.Pos("\0038,") > NULL);

	do // change into mirc colorformat above 16 colors
	{
	 bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
	 Application->ProcessMessages();

	 dbl_flag = false;

	 if (Line.Pos("\0039,"))
	 {
	  try
	  {
	   pos = Line.Pos("\0039,");
	   pre = Line.SubString(pos + 3, 2);
	   a = pre.ToInt();
	   dbl_flag = true;
	  }
	  catch(Exception &exception)
	  {
	   //
	   try
	   {
		pos = Line.Pos("\0039,");
		pre = Line.SubString(pos + 3, 1);
		a = pre.ToInt();
	   }
	   catch(Exception &exception)
	   {
		return Line;
	   }
	  }

	  if(a > 9)
	  {
	   Line.Delete(pos + 2, 3);
	  }

	  if(a < 10)
	  {
	   if(dbl_flag == false)
	   {
		Line.Delete(pos + 2, 2);
	   }
	   else
	   {
		Line.Delete(pos + 2, 3);
		dbl_flag = false;
	   }
	  }
	 }
	}
	while (Line.Pos("\0039,") > NULL);

	//////////

	do // change into mirc colorformat above 16 colors
	{
	 bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
	 //Application->ProcessMessages();

	 dbl_flag = false;

	 if(Line.Pos("\00300,"))
	 {
	  try
	  {
	   pos = Line.Pos("\00300,");
	   pre = Line.SubString(pos + 4, 2);
	   a = pre.ToInt();
	   dbl_flag = true;
	  }
	  catch(Exception &exception)
	  {
	   try
	   {
		pos = Line.Pos("\00300,");
		pre = Line.SubString(pos + 4, 1);
		a = pre.ToInt();
	   }
	   catch(Exception &exception)
	   {
		return Line;
	   }
	  }

	  if (a > 9)
	  {
	   Line.Delete(pos + 3, 3);
	  }

	  if(a < 10)
	  {
	   if(dbl_flag == false)
	   {
		Line.Delete(pos + 3, 2);
	   }
	   else
	   {
		Line.Delete(pos + 3, 3);
		dbl_flag = false;
	   }
	  }
	 }
	}
	while (Line.Pos("\00300,") > NULL);

	do // change into mirc colorformat above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00301,")) {
			try {
				pos = Line.Pos("\00301,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch(Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00301,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00301,") > NULL);

	do // change into mirc colorformat above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00302,")) {
			try {
				pos = Line.Pos("\00302,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch(Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00302,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00302,") > NULL);

	do // change into mirc colorformat above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00303,")) {
			try {
				pos = Line.Pos("\00303,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch(Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00303,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00303,") > NULL);

	do // change into mirc colorformat above 16 colors
	{
	 bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
	 //Application->ProcessMessages();

	 dbl_flag = false;

	 if(Line.Pos("\00304,"))
	 {
	  pos = Line.Pos("\00304,");
	  pre = Line.SubString(pos + 4,2);

	  try
	  {
	   pos = Line.Pos("\00304,");
	   pre = Line.SubString(pos + 4,2);
	   a = pre.ToInt();
	   dbl_flag = true;
	  }
	  catch (Exception &exception)
	  {
	   try
	   {
		pos = Line.Pos("\00304,");
		pre = Line.SubString(pos + 4, 1);
		a = pre.ToInt();
	   }
	   catch(Exception &exception)
	   {
		return Line;
	   }
	  }

	  if(a > 9)
	  {
	   Line.Delete(pos + 3, 3);
	  }

	  if(a < 10)
	  {
	   if(dbl_flag == false)
	   {
		Line.Delete(pos + 3, 2);
	   }
	   else
	   {
		Line.Delete(pos + 3, 3);
		dbl_flag = false;
	   }
	  }
	 }
	}
	while(Line.Pos("\00304,") > NULL);


	do // change into mirc colorformat above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00305,")) {
			try {
				pos = Line.Pos("\00305,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00305,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00305,") > NULL);

	do // change into mirc colorformat above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00306,")) {
			try {
				pos = Line.Pos("\00306,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00306,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00306,") > NULL);

	do // change into mirc colorformat above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00307,")) {
			try {
				pos = Line.Pos("\00307,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00307,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00307,") > NULL);

	do // change into mirc colorformat above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00308,")) {
			try {
				pos = Line.Pos("\00308,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00308,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00308,") > NULL);

	do // change into mirc colorformat above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00309,")) {
			try {
				pos = Line.Pos("\00309,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00309,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00309,") > NULL);

	do // change into mirc colorformat above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00310,")) {
			try {
				pos = Line.Pos("\00310,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00310,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00310,") > NULL);

	do // change into mirc colorformat above 16 colors
	{
	 bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
	 //Application->ProcessMessages();

	 dbl_flag = false;

	 if(Line.Pos("\00311,"))
	 {
	  try
	  {
	   pos = Line.Pos("\00311,");
	   pre = Line.SubString(pos + 4, 2); //"1 "
	   a = pre.ToInt();
	   dbl_flag = true;
	  }
	  catch (Exception &exception)
	  {
	   try
	   {
		pos = Line.Pos("\00311,");
		pre = Line.SubString(pos + 4, 1);
		a = pre.ToInt();
	   }
	   catch(Exception &exception)
	   {
		return Line;
	   }
	  }

	  if (a > 9)
	  {
	   Line.Delete(pos + 3, 3);
	  }

	  if(a < 10)
	  {
	   if(dbl_flag == false)
	   {
		Line.Delete(pos + 3, 2);
	   }
	   else
	   {
		Line.Delete(pos + 3, 3);
		dbl_flag = false;
	   }
	  }
	 }
	}
	while (Line.Pos("\00311,") > NULL);

	do // change into mirc colorformat above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00312,")) {
			try {
				pos = Line.Pos("\00312,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00312,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while(Line.Pos("\00312,") > NULL);

	do // change into mirc colorformat above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00313,")) {
			try {
				pos = Line.Pos("\00313,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00313,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00313,") > NULL);

	do // change into mirc colorformat above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00314,")) {
			try {
				pos = Line.Pos("\00314,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00314,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00314,") > NULL);

	do // change into mirc colorformat above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00315,")) {
			try {
				pos = Line.Pos("\00315,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00315,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00315,") > NULL);

	do // change into mirc colorformat above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00316,")) {
			try {
				pos = Line.Pos("\00316,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00316,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00316,") > NULL);

	do // change into mirc colorformat above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00317,")) {
			try {
				pos = Line.Pos("\00317,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00317,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00317,") > NULL);

	do // change into mirc colorformat above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00318,")) {
			try {
				pos = Line.Pos("\00318,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00318,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00318,") > NULL);

	do // change into mirc colorformat above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00319,")) {
			try {
				pos = Line.Pos("\00319,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00319,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00319,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00320,")) {
			try {
				pos = Line.Pos("\00320,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00320,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00320,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00321,")) {
			try {
				pos = Line.Pos("\00321,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00321,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00321,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00322,")) {
			try {
				pos = Line.Pos("\00322,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00322,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00322,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00323,")) {
			try {
				pos = Line.Pos("\00323,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00323,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00323,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00324,")) {
			try {
				pos = Line.Pos("\00324,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00324,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00324,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00325,")) {
			try {
				pos = Line.Pos("\00325,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00325,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00325,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00326,")) {
			try {
				pos = Line.Pos("\00326,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00326,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00326,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00327,")) {
			try {
				pos = Line.Pos("\00327,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00327,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00327,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00328,")) {
			try {
				pos = Line.Pos("\00328,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00328,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00328,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00329,")) {
			try {
				pos = Line.Pos("\00329,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00329,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00329,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00330,")) {
			try {
				pos = Line.Pos("\00330,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00330,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00330,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00331,")) {
			try {
				pos = Line.Pos("\00331,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00331,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00331,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00332,")) {
			try {
				pos = Line.Pos("\00332,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00332,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00332,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00333,")) {
			try {
				pos = Line.Pos("\00333,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00333,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00333,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00334,")) {
			try {
				pos = Line.Pos("\00334,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00334,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00334,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00335,")) {
			try {
				pos = Line.Pos("\00335,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00335,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00335,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00336,")) {
			try {
				pos = Line.Pos("\00336,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00336,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00336,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00337,")) {
			try {
				pos = Line.Pos("\00337,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00337,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00337,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00338,")) {
			try {
				pos = Line.Pos("\00338,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00338,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00338,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00339,")) {
			try {
				pos = Line.Pos("\00339,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00339,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00339,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00340,")) {
			try {
				pos = Line.Pos("\00340,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00340,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00340,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00341,")) {
			try {
				pos = Line.Pos("\00341,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00341,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00341,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00342,")) {
			try {
				pos = Line.Pos("\00342,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00342,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00342,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00343,")) {
			try {
				pos = Line.Pos("\00343,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00343,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00343,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00344,")) {
			try {
				pos = Line.Pos("\00344,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00344,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00344,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00345,")) {
			try {
				pos = Line.Pos("\00345,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00345,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00345,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00346,")) {
			try {
				pos = Line.Pos("\00346,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00346,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00346,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00347,")) {
			try {
				pos = Line.Pos("\00347,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00347,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while(Line.Pos("\00347,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00348,")) {
			try {
				pos = Line.Pos("\00348,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00348,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00348,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00349,")) {
			try {
				pos = Line.Pos("\00349,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00349,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00349,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00350,")) {
			try {
				pos = Line.Pos("\00350,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00350,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00350,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00351,")) {
			try {
				pos = Line.Pos("\00351,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00351,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00351,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00352,")) {
			try {
				pos = Line.Pos("\00352,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00352,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00352,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00353,")) {
			try {
				pos = Line.Pos("\00353,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00353,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00353,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00354,")) {
			try {
				pos = Line.Pos("\00354,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00354,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00354,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00355,")) {
			try {
				pos = Line.Pos("\00355,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00355,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00355,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00356,")) {
			try {
				pos = Line.Pos("\00356,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00356,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00356,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00357,")) {
			try {
				pos = Line.Pos("\00357,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00357,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00357,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00358,")) {
			try {
				pos = Line.Pos("\00358,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00358,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00358,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00359,")) {
			try {
				pos = Line.Pos("\00359,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00359,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00359,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00360,")) {
			try {
				pos = Line.Pos("\00360,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00360,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00360,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00360,")) {
			try {
				pos = Line.Pos("\00360,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00360,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00360,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00361,")) {
			try {
				pos = Line.Pos("\00361,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00361,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00361,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00362,")) {
			try {
				pos = Line.Pos("\00362,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00362,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00362,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00363,")) {
			try {
				pos = Line.Pos("\00363,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00363,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00363,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00364,")) {
			try {
				pos = Line.Pos("\00364,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00364,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00364,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00365,")) {
			try {
				pos = Line.Pos("\00365,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00365,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00365,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00366,")) {
			try {
				pos = Line.Pos("\00366,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00366,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00366,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00367,")) {
			try {
				pos = Line.Pos("\00367,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00367,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00367,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00368,")) {
			try {
				pos = Line.Pos("\00368,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00368,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00368,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00369,")) {
			try {
				pos = Line.Pos("\00369,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00369,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00369,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00370,")) {
			try {
				pos = Line.Pos("\00370,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00370,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00370,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00371,")) {
			try {
				pos = Line.Pos("\00371,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00371,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00371,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00372,")) {
			try {
				pos = Line.Pos("\00372,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00372,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00372,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00373,")) {
			try {
				pos = Line.Pos("\00373,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00373,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00373,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00374,")) {
			try {
				pos = Line.Pos("\00374,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00374,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00374,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00375,")) {
			try {
				pos = Line.Pos("\00375,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00375,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00375,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00376,")) {
			try {
				pos = Line.Pos("\00376,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00376,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00376,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00377,")) {
			try {
				pos = Line.Pos("\00377,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00377,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00377,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00378,")) {
			try {
				pos = Line.Pos("\00378,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00378,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00378,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00379,")) {
			try {
				pos = Line.Pos("\00379,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00379,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00379,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00380,")) {
			try {
				pos = Line.Pos("\00380,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00380,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00380,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00380,")) {
			try {
				pos = Line.Pos("\00380,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00380,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00380,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00381,")) {
			try {
				pos = Line.Pos("\00381,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00381,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00381,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00382,")) {
			try {
				pos = Line.Pos("\00382,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00382,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00382,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00383,")) {
			try {
				pos = Line.Pos("\00383,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00383,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00383,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00384,")) {
			try {
				pos = Line.Pos("\00384,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00384,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00384,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00385,")) {
			try {
				pos = Line.Pos("\00385,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00385,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00385,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00386,")) {
			try {
				pos = Line.Pos("\00386,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00386,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00386,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00387,")) {
			try {
				pos = Line.Pos("\00387,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00387,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00387,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00388,")) {
			try {
				pos = Line.Pos("\00388,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00388,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00388,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00389,")) {
			try {
				pos = Line.Pos("\00389,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00389,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00389,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00390,")) {
			try {
				pos = Line.Pos("\00390,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00390,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00390,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00391,")) {
			try {
				pos = Line.Pos("\00391,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00391,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00391,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00392,")) {
			try {
				pos = Line.Pos("\00392,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00392,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00392,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00393,")) {
			try {
				pos = Line.Pos("\00393,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00393,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00393,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00394,")) {
			try {
				pos = Line.Pos("\00394,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00394,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00394,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00395,")) {
			try {
				pos = Line.Pos("\00395,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00395,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00395,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00396,")) {
			try {
				pos = Line.Pos("\00396,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00396,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00396,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00397,")) {
			try {
				pos = Line.Pos("\00397,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00397,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00397,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00398,")) {
			try {
				pos = Line.Pos("\00398,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00398,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00398,") > NULL);

	do // remove backgrounds [mirc colorformat] above 16 colors
	{
		bool dbl_flag; // set true if backcolor is 00,01,02,03 etc  double char
		//Application->ProcessMessages();

		dbl_flag = false;

		if (Line.Pos("\00399,")) {
			try {
				pos = Line.Pos("\00399,");
				pre = Line.SubString(pos + 4, 2);
				a = pre.ToInt();
				dbl_flag = true;
			}
			catch (Exception &exception)
			{
			 try
			 {
			  pos = Line.Pos("\00399,");
			  pre = Line.SubString(pos + 4, 1);
			  a = pre.ToInt();
			 }
			 catch(Exception &exception)
			 {
			  return Line;
			 }
			}

			if (a > 9) {
				Line.Delete(pos + 3, 3);
			}

			if (a < 10) {
				if (dbl_flag == false) {
					Line.Delete(pos + 3, 2);
				}
				else {
					Line.Delete(pos + 3, 3);
					dbl_flag = false;
				}
			}
		}
	}
	while (Line.Pos("\00399,") > NULL);

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////

	do // change into mirc colorformat above 16 colors
	{
		//Application->ProcessMessages();

		if (Line.Pos("\0030,")) {
			pos = Line.Pos("\0030,");
			pre = Line.SubString(pos + 3, 2);

			if (pre == "16" || pre == "17" || pre == "18" || pre == "19" ||
				pre == "20" || pre == "21" || pre == "22" || pre == "23" ||
				pre == "24" || pre == "25" || pre == "26" || pre == "27" ||
				pre == "28" || pre == "29" || pre == "30" || pre == "31" ||
				pre == "32" || pre == "33" || pre == "34" || pre == "35" ||
				pre == "36" || pre == "37" || pre == "38" || pre == "39" ||
				pre == "40" || pre == "41" || pre == "42" || pre == "43" ||
				pre == "44" || pre == "45" || pre == "46" || pre == "47" ||
				pre == "48" || pre == "49" || pre == "50" || pre == "51" ||
				pre == "52" || pre == "53" || pre == "54" || pre == "55" ||
				pre == "56" || pre == "57" || pre == "58" || pre == "59" ||
				pre == "60" || pre == "61" || pre == "62" || pre == "63" ||
				pre == "64" || pre == "65" || pre == "66" || pre == "67" ||
				pre == "68" || pre == "69" || pre == "70" || pre == "71" ||
				pre == "72" || pre == "73" || pre == "74" || pre == "75" ||
				pre == "76" || pre == "77" || pre == "78" || pre == "79" ||
				pre == "80" || pre == "81" || pre == "82" || pre == "83" ||
				pre == "84" || pre == "84" || pre == "86" || pre == "87" ||
				pre == "88" || pre == "89" || pre == "90" || pre == "91" ||
				pre == "92" || pre == "93" || pre == "94" || pre == "95" ||
				pre == "96" || pre == "97" || pre == "98" || pre == "99") {
				Line.Delete(pos + 2, 3);
			}
		}
	}
	while (Line.Pos("\0030,16") > NULL || Line.Pos("\0030,17") >
		NULL || Line.Pos("\0030,18") > NULL || Line.Pos("\0030,19") >
		NULL || Line.Pos("\0030,20") > NULL || Line.Pos("\0030,21") >
		NULL || Line.Pos("\0030,22") > NULL || Line.Pos("\0030,23") >
		NULL || Line.Pos("\0030,24") > NULL || Line.Pos("\0030,25") >
		NULL || Line.Pos("\0030,26") > NULL || Line.Pos("\0030,27") >
		NULL || Line.Pos("\0030,28") > NULL || Line.Pos("\0030,29") >
		NULL || Line.Pos("\0030,30") > NULL || Line.Pos("\0030,31") >
		NULL || Line.Pos("\0030,32") > NULL || Line.Pos("\0030,33") >
		NULL || Line.Pos("\0030,34") > NULL || Line.Pos("\0030,35") >
		NULL || Line.Pos("\0030,36") > NULL || Line.Pos("\0030,37") >
		NULL || Line.Pos("\0030,38") > NULL || Line.Pos("\0030,39") >
		NULL || Line.Pos("\0030,40") > NULL || Line.Pos("\0030,41") >
		NULL || Line.Pos("\0030,42") > NULL || Line.Pos("\0030,43") >
		NULL || Line.Pos("\0030,44") > NULL || Line.Pos("\0030,45") >
		NULL || Line.Pos("\0030,46") > NULL || Line.Pos("\0030,47") >
		NULL || Line.Pos("\0030,48") > NULL || Line.Pos("\0030,49") >
		NULL || Line.Pos("\0030,50") > NULL || Line.Pos("\0030,51") >
		NULL || Line.Pos("\0030,52") > NULL || Line.Pos("\0030,53") >
		NULL || Line.Pos("\0030,54") > NULL || Line.Pos("\0030,55") >
		NULL || Line.Pos("\0030,56") > NULL || Line.Pos("\0030,57") >
		NULL || Line.Pos("\0030,58") > NULL || Line.Pos("\0030,59") >
		NULL || Line.Pos("\0030,60") > NULL || Line.Pos("\0030,61") >
		NULL || Line.Pos("\0030,62") > NULL || Line.Pos("\0030,63") >
		NULL || Line.Pos("\0030,64") > NULL || Line.Pos("\0030,65") >
		NULL || Line.Pos("\0030,66") > NULL || Line.Pos("\0030,67") >
		NULL || Line.Pos("\0030,68") > NULL || Line.Pos("\0030,69") >
		NULL || Line.Pos("\0030,70") > NULL || Line.Pos("\0030,71") >
		NULL || Line.Pos("\0030,72") > NULL || Line.Pos("\0030,73") >
		NULL || Line.Pos("\0030,74") > NULL || Line.Pos("\0030,75") >
		NULL || Line.Pos("\0030,76") > NULL || Line.Pos("\0030,77") >
		NULL || Line.Pos("\0030,78") > NULL || Line.Pos("\0030,79") >
		NULL || Line.Pos("\0030,80") > NULL || Line.Pos("\0030,81") >
		NULL || Line.Pos("\0030,82") > NULL || Line.Pos("\0030,83") >
		NULL || Line.Pos("\0030,84") > NULL || Line.Pos("\0030,85") >
		NULL || Line.Pos("\0030,86") > NULL || Line.Pos("\0030,87") >
		NULL || Line.Pos("\0030,88") > NULL || Line.Pos("\0030,89") >
		NULL || Line.Pos("\0030,90") > NULL || Line.Pos("\0030,91") >
		NULL || Line.Pos("\0030,92") > NULL || Line.Pos("\0030,93") >
		NULL || Line.Pos("\0030,94") > NULL || Line.Pos("\0030,95") >
		NULL || Line.Pos("\0030,96") > NULL || Line.Pos("\0030,97") >
		NULL || Line.Pos("\0030,98") > NULL || Line.Pos("\0030,99") >
		NULL);

	do // change into mirc colorformat above 16 colors
	{
		//Application->ProcessMessages();

		if (Line.Pos("\0031,")) {
			pos = Line.Pos("\0031,");
			pre = Line.SubString(pos + 3, 2);

			if (pre == "16" || pre == "17" || pre == "18" || pre == "19" ||
				pre == "20" || pre == "21" || pre == "22" || pre == "23" ||
				pre == "24" || pre == "25" || pre == "26" || pre == "27" ||
				pre == "28" || pre == "29" || pre == "30" || pre == "31" ||
				pre == "32" || pre == "33" || pre == "34" || pre == "35" ||
				pre == "36" || pre == "37" || pre == "38" || pre == "39" ||
				pre == "40" || pre == "41" || pre == "42" || pre == "43" ||
				pre == "44" || pre == "45" || pre == "46" || pre == "47" ||
				pre == "48" || pre == "49" || pre == "50" || pre == "51" ||
				pre == "52" || pre == "53" || pre == "54" || pre == "55" ||
				pre == "56" || pre == "57" || pre == "58" || pre == "59" ||
				pre == "60" || pre == "61" || pre == "62" || pre == "63" ||
				pre == "64" || pre == "65" || pre == "66" || pre == "67" ||
				pre == "68" || pre == "69" || pre == "70" || pre == "71" ||
				pre == "72" || pre == "73" || pre == "74" || pre == "75" ||
				pre == "76" || pre == "77" || pre == "78" || pre == "79" ||
				pre == "80" || pre == "81" || pre == "82" || pre == "83" ||
				pre == "84" || pre == "84" || pre == "86" || pre == "87" ||
				pre == "88" || pre == "89" || pre == "90" || pre == "91" ||
				pre == "92" || pre == "93" || pre == "94" || pre == "95" ||
				pre == "96" || pre == "97" || pre == "98" || pre == "99") {
				Line.Delete(pos + 2, 3);
			}
		}
	}
	while (Line.Pos("\0031,16") > NULL || Line.Pos("\0031,17") >
		NULL || Line.Pos("\0031,18") > NULL || Line.Pos("\0031,19") >
		NULL || Line.Pos("\0031,20") > NULL || Line.Pos("\0031,21") >
		NULL || Line.Pos("\0031,22") > NULL || Line.Pos("\0031,23") >
		NULL || Line.Pos("\0031,24") > NULL || Line.Pos("\0031,25") >
		NULL || Line.Pos("\0031,26") > NULL || Line.Pos("\0031,27") >
		NULL || Line.Pos("\0031,28") > NULL || Line.Pos("\0031,29") >
		NULL || Line.Pos("\0031,30") > NULL || Line.Pos("\0031,31") >
		NULL || Line.Pos("\0031,32") > NULL || Line.Pos("\0031,33") >
		NULL || Line.Pos("\0031,34") > NULL || Line.Pos("\0031,35") >
		NULL || Line.Pos("\0031,36") > NULL || Line.Pos("\0031,37") >
		NULL || Line.Pos("\0031,38") > NULL || Line.Pos("\0031,39") >
		NULL || Line.Pos("\0031,40") > NULL || Line.Pos("\0031,41") >
		NULL || Line.Pos("\0031,42") > NULL || Line.Pos("\0031,43") >
		NULL || Line.Pos("\0031,44") > NULL || Line.Pos("\0031,45") >
		NULL || Line.Pos("\0031,46") > NULL || Line.Pos("\0031,47") >
		NULL || Line.Pos("\0031,48") > NULL || Line.Pos("\0031,49") >
		NULL || Line.Pos("\0031,50") > NULL || Line.Pos("\0031,51") >
		NULL || Line.Pos("\0031,52") > NULL || Line.Pos("\0031,53") >
		NULL || Line.Pos("\0031,54") > NULL || Line.Pos("\0031,55") >
		NULL || Line.Pos("\0031,56") > NULL || Line.Pos("\0031,57") >
		NULL || Line.Pos("\0031,58") > NULL || Line.Pos("\0031,59") >
		NULL || Line.Pos("\0031,60") > NULL || Line.Pos("\0031,61") >
		NULL || Line.Pos("\0031,62") > NULL || Line.Pos("\0031,63") >
		NULL || Line.Pos("\0031,64") > NULL || Line.Pos("\0031,65") >
		NULL || Line.Pos("\0031,66") > NULL || Line.Pos("\0031,67") >
		NULL || Line.Pos("\0031,68") > NULL || Line.Pos("\0031,69") >
		NULL || Line.Pos("\0031,70") > NULL || Line.Pos("\0031,71") >
		NULL || Line.Pos("\0031,72") > NULL || Line.Pos("\0031,73") >
		NULL || Line.Pos("\0031,74") > NULL || Line.Pos("\0031,75") >
		NULL || Line.Pos("\0031,76") > NULL || Line.Pos("\0031,77") >
		NULL || Line.Pos("\0031,78") > NULL || Line.Pos("\0031,79") >
		NULL || Line.Pos("\0031,80") > NULL || Line.Pos("\0031,81") >
		NULL || Line.Pos("\0031,82") > NULL || Line.Pos("\0031,83") >
		NULL || Line.Pos("\0031,84") > NULL || Line.Pos("\0031,85") >
		NULL || Line.Pos("\0031,86") > NULL || Line.Pos("\0031,87") >
		NULL || Line.Pos("\0031,88") > NULL || Line.Pos("\0031,89") >
		NULL || Line.Pos("\0031,90") > NULL || Line.Pos("\0031,91") >
		NULL || Line.Pos("\0031,92") > NULL || Line.Pos("\0031,93") >
		NULL || Line.Pos("\0031,94") > NULL || Line.Pos("\0031,95") >
		NULL || Line.Pos("\0031,96") > NULL || Line.Pos("\0031,97") >
		NULL || Line.Pos("\0031,98") > NULL || Line.Pos("\0031,99") >
		NULL);

	do // change into mirc colorformat above 16 colors
	{
		//Application->ProcessMessages();

		if (Line.Pos("\0032,")) {
			pos = Line.Pos("\0032,");
			pre = Line.SubString(pos + 3, 2);

			if (pre == "16" || pre == "17" || pre == "18" || pre == "19" ||
				pre == "20" || pre == "21" || pre == "22" || pre == "23" ||
				pre == "24" || pre == "25" || pre == "26" || pre == "27" ||
				pre == "28" || pre == "29" || pre == "30" || pre == "31" ||
				pre == "32" || pre == "33" || pre == "34" || pre == "35" ||
				pre == "36" || pre == "37" || pre == "38" || pre == "39" ||
				pre == "40" || pre == "41" || pre == "42" || pre == "43" ||
				pre == "44" || pre == "45" || pre == "46" || pre == "47" ||
				pre == "48" || pre == "49" || pre == "50" || pre == "51" ||
				pre == "52" || pre == "53" || pre == "54" || pre == "55" ||
				pre == "56" || pre == "57" || pre == "58" || pre == "59" ||
				pre == "60" || pre == "61" || pre == "62" || pre == "63" ||
				pre == "64" || pre == "65" || pre == "66" || pre == "67" ||
				pre == "68" || pre == "69" || pre == "70" || pre == "71" ||
				pre == "72" || pre == "73" || pre == "74" || pre == "75" ||
				pre == "76" || pre == "77" || pre == "78" || pre == "79" ||
				pre == "80" || pre == "81" || pre == "82" || pre == "83" ||
				pre == "84" || pre == "84" || pre == "86" || pre == "87" ||
				pre == "88" || pre == "89" || pre == "90" || pre == "91" ||
				pre == "92" || pre == "93" || pre == "94" || pre == "95" ||
				pre == "96" || pre == "97" || pre == "98" || pre == "99") {
				Line.Delete(pos + 2, 3);
			}
		}
	}
	while (Line.Pos("\0032,16") > NULL || Line.Pos("\0032,17") >
		NULL || Line.Pos("\0032,18") > NULL || Line.Pos("\0032,19") >
		NULL || Line.Pos("\0032,20") > NULL || Line.Pos("\0032,21") >
		NULL || Line.Pos("\0032,22") > NULL || Line.Pos("\0032,23") >
		NULL || Line.Pos("\0032,24") > NULL || Line.Pos("\0032,25") >
		NULL || Line.Pos("\0032,26") > NULL || Line.Pos("\0032,27") >
		NULL || Line.Pos("\0032,28") > NULL || Line.Pos("\0032,29") >
		NULL || Line.Pos("\0032,30") > NULL || Line.Pos("\0032,31") >
		NULL || Line.Pos("\0032,32") > NULL || Line.Pos("\0032,33") >
		NULL || Line.Pos("\0032,34") > NULL || Line.Pos("\0032,35") >
		NULL || Line.Pos("\0032,36") > NULL || Line.Pos("\0032,37") >
		NULL || Line.Pos("\0032,38") > NULL || Line.Pos("\0032,39") >
		NULL || Line.Pos("\0032,40") > NULL || Line.Pos("\0032,41") >
		NULL || Line.Pos("\0032,42") > NULL || Line.Pos("\0032,43") >
		NULL || Line.Pos("\0032,44") > NULL || Line.Pos("\0032,45") >
		NULL || Line.Pos("\0032,46") > NULL || Line.Pos("\0032,47") >
		NULL || Line.Pos("\0032,48") > NULL || Line.Pos("\0032,49") >
		NULL || Line.Pos("\0032,50") > NULL || Line.Pos("\0032,51") >
		NULL || Line.Pos("\0032,52") > NULL || Line.Pos("\0032,53") >
		NULL || Line.Pos("\0032,54") > NULL || Line.Pos("\0032,55") >
		NULL || Line.Pos("\0032,56") > NULL || Line.Pos("\0032,57") >
		NULL || Line.Pos("\0032,58") > NULL || Line.Pos("\0032,59") >
		NULL || Line.Pos("\0032,60") > NULL || Line.Pos("\0032,61") >
		NULL || Line.Pos("\0032,62") > NULL || Line.Pos("\0032,63") >
		NULL || Line.Pos("\0032,64") > NULL || Line.Pos("\0032,65") >
		NULL || Line.Pos("\0032,66") > NULL || Line.Pos("\0032,67") >
		NULL || Line.Pos("\0032,68") > NULL || Line.Pos("\0032,69") >
		NULL || Line.Pos("\0032,70") > NULL || Line.Pos("\0032,71") >
		NULL || Line.Pos("\0032,72") > NULL || Line.Pos("\0032,73") >
		NULL || Line.Pos("\0032,74") > NULL || Line.Pos("\0032,75") >
		NULL || Line.Pos("\0032,76") > NULL || Line.Pos("\0032,77") >
		NULL || Line.Pos("\0032,78") > NULL || Line.Pos("\0032,79") >
		NULL || Line.Pos("\0032,80") > NULL || Line.Pos("\0032,81") >
		NULL || Line.Pos("\0032,82") > NULL || Line.Pos("\0032,83") >
		NULL || Line.Pos("\0032,84") > NULL || Line.Pos("\0032,85") >
		NULL || Line.Pos("\0032,86") > NULL || Line.Pos("\0032,87") >
		NULL || Line.Pos("\0032,88") > NULL || Line.Pos("\0032,89") >
		NULL || Line.Pos("\0032,90") > NULL || Line.Pos("\0032,91") >
		NULL || Line.Pos("\0032,92") > NULL || Line.Pos("\0032,93") >
		NULL || Line.Pos("\0032,94") > NULL || Line.Pos("\0032,95") >
		NULL || Line.Pos("\0032,96") > NULL || Line.Pos("\0032,97") >
		NULL || Line.Pos("\0032,98") > NULL || Line.Pos("\0032,99") >
		NULL);

	do // change into mirc colorformat above 16 colors
	{
		//Application->ProcessMessages();

		if (Line.Pos("\0033,")) {
			pos = Line.Pos("\0033,");
			pre = Line.SubString(pos + 3, 2);

			if (pre == "16" || pre == "17" || pre == "18" || pre == "19" ||
				pre == "20" || pre == "21" || pre == "22" || pre == "23" ||
				pre == "24" || pre == "25" || pre == "26" || pre == "27" ||
				pre == "28" || pre == "29" || pre == "30" || pre == "31" ||
				pre == "32" || pre == "33" || pre == "34" || pre == "35" ||
				pre == "36" || pre == "37" || pre == "38" || pre == "39" ||
				pre == "40" || pre == "41" || pre == "42" || pre == "43" ||
				pre == "44" || pre == "45" || pre == "46" || pre == "47" ||
				pre == "48" || pre == "49" || pre == "50" || pre == "51" ||
				pre == "52" || pre == "53" || pre == "54" || pre == "55" ||
				pre == "56" || pre == "57" || pre == "58" || pre == "59" ||
				pre == "60" || pre == "61" || pre == "62" || pre == "63" ||
				pre == "64" || pre == "65" || pre == "66" || pre == "67" ||
				pre == "68" || pre == "69" || pre == "70" || pre == "71" ||
				pre == "72" || pre == "73" || pre == "74" || pre == "75" ||
				pre == "76" || pre == "77" || pre == "78" || pre == "79" ||
				pre == "80" || pre == "81" || pre == "82" || pre == "83" ||
				pre == "84" || pre == "84" || pre == "86" || pre == "87" ||
				pre == "88" || pre == "89" || pre == "90" || pre == "91" ||
				pre == "92" || pre == "93" || pre == "94" || pre == "95" ||
				pre == "96" || pre == "97" || pre == "98" || pre == "99") {
				Line.Delete(pos + 2, 3);
			}
		}
	}
	while (Line.Pos("\0033,16") > NULL || Line.Pos("\0033,17") >
		NULL || Line.Pos("\0033,18") > NULL || Line.Pos("\0033,19") >
		NULL || Line.Pos("\0033,20") > NULL || Line.Pos("\0033,21") >
		NULL || Line.Pos("\0033,22") > NULL || Line.Pos("\0033,23") >
		NULL || Line.Pos("\0033,24") > NULL || Line.Pos("\0033,25") >
		NULL || Line.Pos("\0033,26") > NULL || Line.Pos("\0033,27") >
		NULL || Line.Pos("\0033,28") > NULL || Line.Pos("\0033,29") >
		NULL || Line.Pos("\0033,30") > NULL || Line.Pos("\0033,31") >
		NULL || Line.Pos("\0033,32") > NULL || Line.Pos("\0033,33") >
		NULL || Line.Pos("\0033,34") > NULL || Line.Pos("\0033,35") >
		NULL || Line.Pos("\0033,36") > NULL || Line.Pos("\0033,37") >
		NULL || Line.Pos("\0033,38") > NULL || Line.Pos("\0033,39") >
		NULL || Line.Pos("\0033,40") > NULL || Line.Pos("\0033,41") >
		NULL || Line.Pos("\0033,42") > NULL || Line.Pos("\0033,43") >
		NULL || Line.Pos("\0033,44") > NULL || Line.Pos("\0033,45") >
		NULL || Line.Pos("\0033,46") > NULL || Line.Pos("\0033,47") >
		NULL || Line.Pos("\0033,48") > NULL || Line.Pos("\0033,49") >
		NULL || Line.Pos("\0033,50") > NULL || Line.Pos("\0033,51") >
		NULL || Line.Pos("\0033,52") > NULL || Line.Pos("\0033,53") >
		NULL || Line.Pos("\0033,54") > NULL || Line.Pos("\0033,55") >
		NULL || Line.Pos("\0033,56") > NULL || Line.Pos("\0033,57") >
		NULL || Line.Pos("\0033,58") > NULL || Line.Pos("\0033,59") >
		NULL || Line.Pos("\0033,60") > NULL || Line.Pos("\0033,61") >
		NULL || Line.Pos("\0033,62") > NULL || Line.Pos("\0033,63") >
		NULL || Line.Pos("\0033,64") > NULL || Line.Pos("\0033,65") >
		NULL || Line.Pos("\0033,66") > NULL || Line.Pos("\0033,67") >
		NULL || Line.Pos("\0033,68") > NULL || Line.Pos("\0033,69") >
		NULL || Line.Pos("\0033,70") > NULL || Line.Pos("\0033,71") >
		NULL || Line.Pos("\0033,72") > NULL || Line.Pos("\0033,73") >
		NULL || Line.Pos("\0033,74") > NULL || Line.Pos("\0033,75") >
		NULL || Line.Pos("\0033,76") > NULL || Line.Pos("\0033,77") >
		NULL || Line.Pos("\0033,78") > NULL || Line.Pos("\0033,79") >
		NULL || Line.Pos("\0033,80") > NULL || Line.Pos("\0033,81") >
		NULL || Line.Pos("\0033,82") > NULL || Line.Pos("\0033,83") >
		NULL || Line.Pos("\0033,84") > NULL || Line.Pos("\0033,85") >
		NULL || Line.Pos("\0033,86") > NULL || Line.Pos("\0033,87") >
		NULL || Line.Pos("\0033,88") > NULL || Line.Pos("\0033,89") >
		NULL || Line.Pos("\0033,90") > NULL || Line.Pos("\0033,91") >
		NULL || Line.Pos("\0033,92") > NULL || Line.Pos("\0033,93") >
		NULL || Line.Pos("\0033,94") > NULL || Line.Pos("\0033,95") >
		NULL || Line.Pos("\0033,96") > NULL || Line.Pos("\0033,97") >
		NULL || Line.Pos("\0033,98") > NULL || Line.Pos("\0033,99") >
		NULL);

	do // change into mirc colorformat above 16 colors
	{
		//Application->ProcessMessages();

		if (Line.Pos("\0034,")) {
			pos = Line.Pos("\0034,");
			pre = Line.SubString(pos + 3, 2);

			if (pre == "16" || pre == "17" || pre == "18" || pre == "19" ||
				pre == "20" || pre == "21" || pre == "22" || pre == "23" ||
				pre == "24" || pre == "25" || pre == "26" || pre == "27" ||
				pre == "28" || pre == "29" || pre == "30" || pre == "31" ||
				pre == "32" || pre == "33" || pre == "34" || pre == "35" ||
				pre == "36" || pre == "37" || pre == "38" || pre == "39" ||
				pre == "40" || pre == "41" || pre == "42" || pre == "43" ||
				pre == "44" || pre == "45" || pre == "46" || pre == "47" ||
				pre == "48" || pre == "49" || pre == "50" || pre == "51" ||
				pre == "52" || pre == "53" || pre == "54" || pre == "55" ||
				pre == "56" || pre == "57" || pre == "58" || pre == "59" ||
				pre == "60" || pre == "61" || pre == "62" || pre == "63" ||
				pre == "64" || pre == "65" || pre == "66" || pre == "67" ||
				pre == "68" || pre == "69" || pre == "70" || pre == "71" ||
				pre == "72" || pre == "73" || pre == "74" || pre == "75" ||
				pre == "76" || pre == "77" || pre == "78" || pre == "79" ||
				pre == "80" || pre == "81" || pre == "82" || pre == "83" ||
				pre == "84" || pre == "84" || pre == "86" || pre == "87" ||
				pre == "88" || pre == "89" || pre == "90" || pre == "91" ||
				pre == "92" || pre == "93" || pre == "94" || pre == "95" ||
				pre == "96" || pre == "97" || pre == "98" || pre == "99") {
				Line.Delete(pos + 2, 3);
			}
		}
	}
	while (Line.Pos("\0034,16") > NULL || Line.Pos("\0034,17") >
		NULL || Line.Pos("\0034,18") > NULL || Line.Pos("\0034,19") >
		NULL || Line.Pos("\0034,20") > NULL || Line.Pos("\0034,21") >
		NULL || Line.Pos("\0034,22") > NULL || Line.Pos("\0034,23") >
		NULL || Line.Pos("\0034,24") > NULL || Line.Pos("\0034,25") >
		NULL || Line.Pos("\0034,26") > NULL || Line.Pos("\0034,27") >
		NULL || Line.Pos("\0034,28") > NULL || Line.Pos("\0034,29") >
		NULL || Line.Pos("\0034,30") > NULL || Line.Pos("\0034,31") >
		NULL || Line.Pos("\0034,32") > NULL || Line.Pos("\0034,33") >
		NULL || Line.Pos("\0034,34") > NULL || Line.Pos("\0034,35") >
		NULL || Line.Pos("\0034,36") > NULL || Line.Pos("\0034,37") >
		NULL || Line.Pos("\0034,38") > NULL || Line.Pos("\0034,39") >
		NULL || Line.Pos("\0034,40") > NULL || Line.Pos("\0034,41") >
		NULL || Line.Pos("\0034,42") > NULL || Line.Pos("\0034,43") >
		NULL || Line.Pos("\0034,44") > NULL || Line.Pos("\0034,45") >
		NULL || Line.Pos("\0034,46") > NULL || Line.Pos("\0034,47") >
		NULL || Line.Pos("\0034,48") > NULL || Line.Pos("\0034,49") >
		NULL || Line.Pos("\0034,50") > NULL || Line.Pos("\0034,51") >
		NULL || Line.Pos("\0034,52") > NULL || Line.Pos("\0034,53") >
		NULL || Line.Pos("\0034,54") > NULL || Line.Pos("\0034,55") >
		NULL || Line.Pos("\0034,56") > NULL || Line.Pos("\0034,57") >
		NULL || Line.Pos("\0034,58") > NULL || Line.Pos("\0034,59") >
		NULL || Line.Pos("\0034,60") > NULL || Line.Pos("\0034,61") >
		NULL || Line.Pos("\0034,62") > NULL || Line.Pos("\0034,63") >
		NULL || Line.Pos("\0034,64") > NULL || Line.Pos("\0034,65") >
		NULL || Line.Pos("\0034,66") > NULL || Line.Pos("\0034,67") >
		NULL || Line.Pos("\0034,68") > NULL || Line.Pos("\0034,69") >
		NULL || Line.Pos("\0034,70") > NULL || Line.Pos("\0034,71") >
		NULL || Line.Pos("\0034,72") > NULL || Line.Pos("\0034,73") >
		NULL || Line.Pos("\0034,74") > NULL || Line.Pos("\0034,75") >
		NULL || Line.Pos("\0034,76") > NULL || Line.Pos("\0034,77") >
		NULL || Line.Pos("\0034,78") > NULL || Line.Pos("\0034,79") >
		NULL || Line.Pos("\0034,80") > NULL || Line.Pos("\0034,81") >
		NULL || Line.Pos("\0034,82") > NULL || Line.Pos("\0034,83") >
		NULL || Line.Pos("\0034,84") > NULL || Line.Pos("\0034,85") >
		NULL || Line.Pos("\0034,86") > NULL || Line.Pos("\0034,87") >
		NULL || Line.Pos("\0034,88") > NULL || Line.Pos("\0034,89") >
		NULL || Line.Pos("\0034,90") > NULL || Line.Pos("\0034,91") >
		NULL || Line.Pos("\0034,92") > NULL || Line.Pos("\0034,93") >
		NULL || Line.Pos("\0034,94") > NULL || Line.Pos("\0034,95") >
		NULL || Line.Pos("\0034,96") > NULL || Line.Pos("\0034,97") >
		NULL || Line.Pos("\0034,98") > NULL || Line.Pos("\0034,99") >
		NULL);

	do // change into mirc colorformat above 16 colors
	{
		//Application->ProcessMessages();

		if (Line.Pos("\0035,")) {
			pos = Line.Pos("\0035,");
			pre = Line.SubString(pos + 3, 2);

			if (pre == "16" || pre == "17" || pre == "18" || pre == "19" ||
				pre == "20" || pre == "21" || pre == "22" || pre == "23" ||
				pre == "24" || pre == "25" || pre == "26" || pre == "27" ||
				pre == "28" || pre == "29" || pre == "30" || pre == "31" ||
				pre == "32" || pre == "33" || pre == "34" || pre == "35" ||
				pre == "36" || pre == "37" || pre == "38" || pre == "39" ||
				pre == "40" || pre == "41" || pre == "42" || pre == "43" ||
				pre == "44" || pre == "45" || pre == "46" || pre == "47" ||
				pre == "48" || pre == "49" || pre == "50" || pre == "51" ||
				pre == "52" || pre == "53" || pre == "54" || pre == "55" ||
				pre == "56" || pre == "57" || pre == "58" || pre == "59" ||
				pre == "60" || pre == "61" || pre == "62" || pre == "63" ||
				pre == "64" || pre == "65" || pre == "66" || pre == "67" ||
				pre == "68" || pre == "69" || pre == "70" || pre == "71" ||
				pre == "72" || pre == "73" || pre == "74" || pre == "75" ||
				pre == "76" || pre == "77" || pre == "78" || pre == "79" ||
				pre == "80" || pre == "81" || pre == "82" || pre == "83" ||
				pre == "84" || pre == "84" || pre == "86" || pre == "87" ||
				pre == "88" || pre == "89" || pre == "90" || pre == "91" ||
				pre == "92" || pre == "93" || pre == "94" || pre == "95" ||
				pre == "96" || pre == "97" || pre == "98" || pre == "99") {
				Line.Delete(pos + 2, 3);
			}
		}
	}
	while (Line.Pos("\0035,16") > NULL || Line.Pos("\0035,17") >
		NULL || Line.Pos("\0035,18") > NULL || Line.Pos("\0035,19") >
		NULL || Line.Pos("\0035,20") > NULL || Line.Pos("\0035,21") >
		NULL || Line.Pos("\0035,22") > NULL || Line.Pos("\0035,23") >
		NULL || Line.Pos("\0035,24") > NULL || Line.Pos("\0035,25") >
		NULL || Line.Pos("\0035,26") > NULL || Line.Pos("\0035,27") >
		NULL || Line.Pos("\0035,28") > NULL || Line.Pos("\0035,29") >
		NULL || Line.Pos("\0035,30") > NULL || Line.Pos("\0035,31") >
		NULL || Line.Pos("\0035,32") > NULL || Line.Pos("\0035,33") >
		NULL || Line.Pos("\0035,34") > NULL || Line.Pos("\0035,35") >
		NULL || Line.Pos("\0035,36") > NULL || Line.Pos("\0035,37") >
		NULL || Line.Pos("\0035,38") > NULL || Line.Pos("\0035,39") >
		NULL || Line.Pos("\0035,40") > NULL || Line.Pos("\0035,41") >
		NULL || Line.Pos("\0035,42") > NULL || Line.Pos("\0035,43") >
		NULL || Line.Pos("\0035,44") > NULL || Line.Pos("\0035,45") >
		NULL || Line.Pos("\0035,46") > NULL || Line.Pos("\0035,47") >
		NULL || Line.Pos("\0035,48") > NULL || Line.Pos("\0035,49") >
		NULL || Line.Pos("\0035,50") > NULL || Line.Pos("\0035,51") >
		NULL || Line.Pos("\0035,52") > NULL || Line.Pos("\0035,53") >
		NULL || Line.Pos("\0035,54") > NULL || Line.Pos("\0035,55") >
		NULL || Line.Pos("\0035,56") > NULL || Line.Pos("\0035,57") >
		NULL || Line.Pos("\0035,58") > NULL || Line.Pos("\0035,59") >
		NULL || Line.Pos("\0035,60") > NULL || Line.Pos("\0035,61") >
		NULL || Line.Pos("\0035,62") > NULL || Line.Pos("\0035,63") >
		NULL || Line.Pos("\0035,64") > NULL || Line.Pos("\0035,65") >
		NULL || Line.Pos("\0035,66") > NULL || Line.Pos("\0035,67") >
		NULL || Line.Pos("\0035,68") > NULL || Line.Pos("\0035,69") >
		NULL || Line.Pos("\0035,70") > NULL || Line.Pos("\0035,71") >
		NULL || Line.Pos("\0035,72") > NULL || Line.Pos("\0035,73") >
		NULL || Line.Pos("\0035,74") > NULL || Line.Pos("\0035,75") >
		NULL || Line.Pos("\0035,76") > NULL || Line.Pos("\0035,77") >
		NULL || Line.Pos("\0035,78") > NULL || Line.Pos("\0035,79") >
		NULL || Line.Pos("\0035,80") > NULL || Line.Pos("\0035,81") >
		NULL || Line.Pos("\0035,82") > NULL || Line.Pos("\0035,83") >
		NULL || Line.Pos("\0035,84") > NULL || Line.Pos("\0035,85") >
		NULL || Line.Pos("\0035,86") > NULL || Line.Pos("\0035,87") >
		NULL || Line.Pos("\0035,88") > NULL || Line.Pos("\0035,89") >
		NULL || Line.Pos("\0035,90") > NULL || Line.Pos("\0035,91") >
		NULL || Line.Pos("\0035,92") > NULL || Line.Pos("\0035,93") >
		NULL || Line.Pos("\0035,94") > NULL || Line.Pos("\0035,95") >
		NULL || Line.Pos("\0035,96") > NULL || Line.Pos("\0035,97") >
		NULL || Line.Pos("\0035,98") > NULL || Line.Pos("\0035,99") >
		NULL);

	do // change into mirc colorformat above 16 colors
	{
		//Application->ProcessMessages();

		if (Line.Pos("\0036,")) {
			pos = Line.Pos("\0036,");
			pre = Line.SubString(pos + 3, 2);

			if (pre == "16" || pre == "17" || pre == "18" || pre == "19" ||
				pre == "20" || pre == "21" || pre == "22" || pre == "23" ||
				pre == "24" || pre == "25" || pre == "26" || pre == "27" ||
				pre == "28" || pre == "29" || pre == "30" || pre == "31" ||
				pre == "32" || pre == "33" || pre == "34" || pre == "35" ||
				pre == "36" || pre == "37" || pre == "38" || pre == "39" ||
				pre == "40" || pre == "41" || pre == "42" || pre == "43" ||
				pre == "44" || pre == "45" || pre == "46" || pre == "47" ||
				pre == "48" || pre == "49" || pre == "50" || pre == "51" ||
				pre == "52" || pre == "53" || pre == "54" || pre == "55" ||
				pre == "56" || pre == "57" || pre == "58" || pre == "59" ||
				pre == "60" || pre == "61" || pre == "62" || pre == "63" ||
				pre == "64" || pre == "65" || pre == "66" || pre == "67" ||
				pre == "68" || pre == "69" || pre == "70" || pre == "71" ||
				pre == "72" || pre == "73" || pre == "74" || pre == "75" ||
				pre == "76" || pre == "77" || pre == "78" || pre == "79" ||
				pre == "80" || pre == "81" || pre == "82" || pre == "83" ||
				pre == "84" || pre == "84" || pre == "86" || pre == "87" ||
				pre == "88" || pre == "89" || pre == "90" || pre == "91" ||
				pre == "92" || pre == "93" || pre == "94" || pre == "95" ||
				pre == "96" || pre == "97" || pre == "98" || pre == "99") {
				Line.Delete(pos + 2, 3);
			}
		}
	}
	while (Line.Pos("\0036,16") > NULL || Line.Pos("\0036,17") >
		NULL || Line.Pos("\0036,18") > NULL || Line.Pos("\0036,19") >
		NULL || Line.Pos("\0036,20") > NULL || Line.Pos("\0036,21") >
		NULL || Line.Pos("\0036,22") > NULL || Line.Pos("\0036,23") >
		NULL || Line.Pos("\0036,24") > NULL || Line.Pos("\0036,25") >
		NULL || Line.Pos("\0036,26") > NULL || Line.Pos("\0036,27") >
		NULL || Line.Pos("\0036,28") > NULL || Line.Pos("\0036,29") >
		NULL || Line.Pos("\0036,30") > NULL || Line.Pos("\0036,31") >
		NULL || Line.Pos("\0036,32") > NULL || Line.Pos("\0036,33") >
		NULL || Line.Pos("\0036,34") > NULL || Line.Pos("\0036,35") >
		NULL || Line.Pos("\0036,36") > NULL || Line.Pos("\0036,37") >
		NULL || Line.Pos("\0036,38") > NULL || Line.Pos("\0036,39") >
		NULL || Line.Pos("\0036,40") > NULL || Line.Pos("\0036,41") >
		NULL || Line.Pos("\0036,42") > NULL || Line.Pos("\0036,43") >
		NULL || Line.Pos("\0036,44") > NULL || Line.Pos("\0036,45") >
		NULL || Line.Pos("\0036,46") > NULL || Line.Pos("\0036,47") >
		NULL || Line.Pos("\0036,48") > NULL || Line.Pos("\0036,49") >
		NULL || Line.Pos("\0036,50") > NULL || Line.Pos("\0036,51") >
		NULL || Line.Pos("\0036,52") > NULL || Line.Pos("\0036,53") >
		NULL || Line.Pos("\0036,54") > NULL || Line.Pos("\0036,55") >
		NULL || Line.Pos("\0036,56") > NULL || Line.Pos("\0036,57") >
		NULL || Line.Pos("\0036,58") > NULL || Line.Pos("\0036,59") >
		NULL || Line.Pos("\0036,60") > NULL || Line.Pos("\0036,61") >
		NULL || Line.Pos("\0036,62") > NULL || Line.Pos("\0036,63") >
		NULL || Line.Pos("\0036,64") > NULL || Line.Pos("\0036,65") >
		NULL || Line.Pos("\0036,66") > NULL || Line.Pos("\0036,67") >
		NULL || Line.Pos("\0036,68") > NULL || Line.Pos("\0036,69") >
		NULL || Line.Pos("\0036,70") > NULL || Line.Pos("\0036,71") >
		NULL || Line.Pos("\0036,72") > NULL || Line.Pos("\0036,73") >
		NULL || Line.Pos("\0036,74") > NULL || Line.Pos("\0036,75") >
		NULL || Line.Pos("\0036,76") > NULL || Line.Pos("\0036,77") >
		NULL || Line.Pos("\0036,78") > NULL || Line.Pos("\0036,79") >
		NULL || Line.Pos("\0036,80") > NULL || Line.Pos("\0036,81") >
		NULL || Line.Pos("\0036,82") > NULL || Line.Pos("\0036,83") >
		NULL || Line.Pos("\0036,84") > NULL || Line.Pos("\0036,85") >
		NULL || Line.Pos("\0036,86") > NULL || Line.Pos("\0036,87") >
		NULL || Line.Pos("\0036,88") > NULL || Line.Pos("\0036,89") >
		NULL || Line.Pos("\0036,90") > NULL || Line.Pos("\0036,91") >
		NULL || Line.Pos("\0036,92") > NULL || Line.Pos("\0036,93") >
		NULL || Line.Pos("\0036,94") > NULL || Line.Pos("\0036,95") >
		NULL || Line.Pos("\0036,96") > NULL || Line.Pos("\0036,97") >
		NULL || Line.Pos("\0036,98") > NULL || Line.Pos("\0036,99") >
		NULL);

	do // change into mirc colorformat above 16 colors
	{
		//Application->ProcessMessages();

		if (Line.Pos("\0037,")) {
			pos = Line.Pos("\0037,");
			pre = Line.SubString(pos + 3, 2);

			if (pre == "16" || pre == "17" || pre == "18" || pre == "19" ||
				pre == "20" || pre == "21" || pre == "22" || pre == "23" ||
				pre == "24" || pre == "25" || pre == "26" || pre == "27" ||
				pre == "28" || pre == "29" || pre == "30" || pre == "31" ||
				pre == "32" || pre == "33" || pre == "34" || pre == "35" ||
				pre == "36" || pre == "37" || pre == "38" || pre == "39" ||
				pre == "40" || pre == "41" || pre == "42" || pre == "43" ||
				pre == "44" || pre == "45" || pre == "46" || pre == "47" ||
				pre == "48" || pre == "49" || pre == "50" || pre == "51" ||
				pre == "52" || pre == "53" || pre == "54" || pre == "55" ||
				pre == "56" || pre == "57" || pre == "58" || pre == "59" ||
				pre == "60" || pre == "61" || pre == "62" || pre == "63" ||
				pre == "64" || pre == "65" || pre == "66" || pre == "67" ||
				pre == "68" || pre == "69" || pre == "70" || pre == "71" ||
				pre == "72" || pre == "73" || pre == "74" || pre == "75" ||
				pre == "76" || pre == "77" || pre == "78" || pre == "79" ||
				pre == "80" || pre == "81" || pre == "82" || pre == "83" ||
				pre == "84" || pre == "84" || pre == "86" || pre == "87" ||
				pre == "88" || pre == "89" || pre == "90" || pre == "91" ||
				pre == "92" || pre == "93" || pre == "94" || pre == "95" ||
				pre == "96" || pre == "97" || pre == "98" || pre == "99") {
				Line.Delete(pos + 2, 3);
			}
		}
	}
	while (Line.Pos("\0037,16") > NULL || Line.Pos("\0037,17") >
		NULL || Line.Pos("\0037,18") > NULL || Line.Pos("\0037,19") >
		NULL || Line.Pos("\0037,20") > NULL || Line.Pos("\0037,21") >
		NULL || Line.Pos("\0037,22") > NULL || Line.Pos("\0037,23") >
		NULL || Line.Pos("\0037,24") > NULL || Line.Pos("\0037,25") >
		NULL || Line.Pos("\0037,26") > NULL || Line.Pos("\0037,27") >
		NULL || Line.Pos("\0037,28") > NULL || Line.Pos("\0037,29") >
		NULL || Line.Pos("\0037,30") > NULL || Line.Pos("\0037,31") >
		NULL || Line.Pos("\0037,32") > NULL || Line.Pos("\0037,33") >
		NULL || Line.Pos("\0037,34") > NULL || Line.Pos("\0037,35") >
		NULL || Line.Pos("\0037,36") > NULL || Line.Pos("\0037,37") >
		NULL || Line.Pos("\0037,38") > NULL || Line.Pos("\0037,39") >
		NULL || Line.Pos("\0037,40") > NULL || Line.Pos("\0037,41") >
		NULL || Line.Pos("\0037,42") > NULL || Line.Pos("\0037,43") >
		NULL || Line.Pos("\0037,44") > NULL || Line.Pos("\0037,45") >
		NULL || Line.Pos("\0037,46") > NULL || Line.Pos("\0037,47") >
		NULL || Line.Pos("\0037,48") > NULL || Line.Pos("\0037,49") >
		NULL || Line.Pos("\0037,50") > NULL || Line.Pos("\0037,51") >
		NULL || Line.Pos("\0037,52") > NULL || Line.Pos("\0037,53") >
		NULL || Line.Pos("\0037,54") > NULL || Line.Pos("\0037,55") >
		NULL || Line.Pos("\0037,56") > NULL || Line.Pos("\0037,57") >
		NULL || Line.Pos("\0037,58") > NULL || Line.Pos("\0037,59") >
		NULL || Line.Pos("\0037,60") > NULL || Line.Pos("\0037,61") >
		NULL || Line.Pos("\0037,62") > NULL || Line.Pos("\0037,63") >
		NULL || Line.Pos("\0037,64") > NULL || Line.Pos("\0037,65") >
		NULL || Line.Pos("\0037,66") > NULL || Line.Pos("\0037,67") >
		NULL || Line.Pos("\0037,68") > NULL || Line.Pos("\0037,69") >
		NULL || Line.Pos("\0037,70") > NULL || Line.Pos("\0037,71") >
		NULL || Line.Pos("\0037,72") > NULL || Line.Pos("\0037,73") >
		NULL || Line.Pos("\0037,74") > NULL || Line.Pos("\0037,75") >
		NULL || Line.Pos("\0037,76") > NULL || Line.Pos("\0037,77") >
		NULL || Line.Pos("\0037,78") > NULL || Line.Pos("\0037,79") >
		NULL || Line.Pos("\0037,80") > NULL || Line.Pos("\0037,81") >
		NULL || Line.Pos("\0037,82") > NULL || Line.Pos("\0037,83") >
		NULL || Line.Pos("\0037,84") > NULL || Line.Pos("\0037,85") >
		NULL || Line.Pos("\0037,86") > NULL || Line.Pos("\0037,87") >
		NULL || Line.Pos("\0037,88") > NULL || Line.Pos("\0037,89") >
		NULL || Line.Pos("\0037,90") > NULL || Line.Pos("\0037,91") >
		NULL || Line.Pos("\0037,92") > NULL || Line.Pos("\0037,93") >
		NULL || Line.Pos("\0037,94") > NULL || Line.Pos("\0037,95") >
		NULL || Line.Pos("\0037,96") > NULL || Line.Pos("\0037,97") >
		NULL || Line.Pos("\0037,98") > NULL || Line.Pos("\0037,99") >
		NULL);

	do // change into mirc colorformat above 16 colors
	{
		//Application->ProcessMessages();

		if (Line.Pos("\0038,")) {
			pos = Line.Pos("\0038,");
			pre = Line.SubString(pos + 3, 2);

			if (pre == "16" || pre == "17" || pre == "18" || pre == "19" ||
				pre == "20" || pre == "21" || pre == "22" || pre == "23" ||
				pre == "24" || pre == "25" || pre == "26" || pre == "27" ||
				pre == "28" || pre == "29" || pre == "30" || pre == "31" ||
				pre == "32" || pre == "33" || pre == "34" || pre == "35" ||
				pre == "36" || pre == "37" || pre == "38" || pre == "39" ||
				pre == "40" || pre == "41" || pre == "42" || pre == "43" ||
				pre == "44" || pre == "45" || pre == "46" || pre == "47" ||
				pre == "48" || pre == "49" || pre == "50" || pre == "51" ||
				pre == "52" || pre == "53" || pre == "54" || pre == "55" ||
				pre == "56" || pre == "57" || pre == "58" || pre == "59" ||
				pre == "60" || pre == "61" || pre == "62" || pre == "63" ||
				pre == "64" || pre == "65" || pre == "66" || pre == "67" ||
				pre == "68" || pre == "69" || pre == "70" || pre == "71" ||
				pre == "72" || pre == "73" || pre == "74" || pre == "75" ||
				pre == "76" || pre == "77" || pre == "78" || pre == "79" ||
				pre == "80" || pre == "81" || pre == "82" || pre == "83" ||
				pre == "84" || pre == "84" || pre == "86" || pre == "87" ||
				pre == "88" || pre == "89" || pre == "90" || pre == "91" ||
				pre == "92" || pre == "93" || pre == "94" || pre == "95" ||
				pre == "96" || pre == "97" || pre == "98" || pre == "99") {
				Line.Delete(pos + 2, 3);
			}
		}
	}
	while (Line.Pos("\0038,16") > NULL || Line.Pos("\0038,17") >
		NULL || Line.Pos("\0038,18") > NULL || Line.Pos("\0038,19") >
		NULL || Line.Pos("\0038,20") > NULL || Line.Pos("\0038,21") >
		NULL || Line.Pos("\0038,22") > NULL || Line.Pos("\0038,23") >
		NULL || Line.Pos("\0038,24") > NULL || Line.Pos("\0038,25") >
		NULL || Line.Pos("\0038,26") > NULL || Line.Pos("\0038,27") >
		NULL || Line.Pos("\0038,28") > NULL || Line.Pos("\0038,29") >
		NULL || Line.Pos("\0038,30") > NULL || Line.Pos("\0038,31") >
		NULL || Line.Pos("\0038,32") > NULL || Line.Pos("\0038,33") >
		NULL || Line.Pos("\0038,34") > NULL || Line.Pos("\0038,35") >
		NULL || Line.Pos("\0038,36") > NULL || Line.Pos("\0038,37") >
		NULL || Line.Pos("\0038,38") > NULL || Line.Pos("\0038,39") >
		NULL || Line.Pos("\0038,40") > NULL || Line.Pos("\0038,41") >
		NULL || Line.Pos("\0038,42") > NULL || Line.Pos("\0038,43") >
		NULL || Line.Pos("\0038,44") > NULL || Line.Pos("\0038,45") >
		NULL || Line.Pos("\0038,46") > NULL || Line.Pos("\0038,47") >
		NULL || Line.Pos("\0038,48") > NULL || Line.Pos("\0038,49") >
		NULL || Line.Pos("\0038,50") > NULL || Line.Pos("\0038,51") >
		NULL || Line.Pos("\0038,52") > NULL || Line.Pos("\0038,53") >
		NULL || Line.Pos("\0038,54") > NULL || Line.Pos("\0038,55") >
		NULL || Line.Pos("\0038,56") > NULL || Line.Pos("\0038,57") >
		NULL || Line.Pos("\0038,58") > NULL || Line.Pos("\0038,59") >
		NULL || Line.Pos("\0038,60") > NULL || Line.Pos("\0038,61") >
		NULL || Line.Pos("\0038,62") > NULL || Line.Pos("\0038,63") >
		NULL || Line.Pos("\0038,64") > NULL || Line.Pos("\0038,65") >
		NULL || Line.Pos("\0038,66") > NULL || Line.Pos("\0038,67") >
		NULL || Line.Pos("\0038,68") > NULL || Line.Pos("\0038,69") >
		NULL || Line.Pos("\0038,70") > NULL || Line.Pos("\0038,71") >
		NULL || Line.Pos("\0038,72") > NULL || Line.Pos("\0038,73") >
		NULL || Line.Pos("\0038,74") > NULL || Line.Pos("\0038,75") >
		NULL || Line.Pos("\0038,76") > NULL || Line.Pos("\0038,77") >
		NULL || Line.Pos("\0038,78") > NULL || Line.Pos("\0038,79") >
		NULL || Line.Pos("\0038,80") > NULL || Line.Pos("\0038,81") >
		NULL || Line.Pos("\0038,82") > NULL || Line.Pos("\0038,83") >
		NULL || Line.Pos("\0038,84") > NULL || Line.Pos("\0038,85") >
		NULL || Line.Pos("\0038,86") > NULL || Line.Pos("\0038,87") >
		NULL || Line.Pos("\0038,88") > NULL || Line.Pos("\0038,89") >
		NULL || Line.Pos("\0038,90") > NULL || Line.Pos("\0038,91") >
		NULL || Line.Pos("\0038,92") > NULL || Line.Pos("\0038,93") >
		NULL || Line.Pos("\0038,94") > NULL || Line.Pos("\0038,95") >
		NULL || Line.Pos("\0038,96") > NULL || Line.Pos("\0038,97") >
		NULL || Line.Pos("\0038,98") > NULL || Line.Pos("\0038,99") >
		NULL);

	do // change into mirc colorformat above 16 colors
	{
		//Application->ProcessMessages();

		if (Line.Pos("\0039,")) {
			pos = Line.Pos("\0039,");
			pre = Line.SubString(pos + 3, 2);

			if (pre == "16" || pre == "17" || pre == "18" || pre == "19" ||
				pre == "20" || pre == "21" || pre == "22" || pre == "23" ||
				pre == "24" || pre == "25" || pre == "26" || pre == "27" ||
				pre == "28" || pre == "29" || pre == "30" || pre == "31" ||
				pre == "32" || pre == "33" || pre == "34" || pre == "35" ||
				pre == "36" || pre == "37" || pre == "38" || pre == "39" ||
				pre == "40" || pre == "41" || pre == "42" || pre == "43" ||
				pre == "44" || pre == "45" || pre == "46" || pre == "47" ||
				pre == "48" || pre == "49" || pre == "50" || pre == "51" ||
				pre == "52" || pre == "53" || pre == "54" || pre == "55" ||
				pre == "56" || pre == "57" || pre == "58" || pre == "59" ||
				pre == "60" || pre == "61" || pre == "62" || pre == "63" ||
				pre == "64" || pre == "65" || pre == "66" || pre == "67" ||
				pre == "68" || pre == "69" || pre == "70" || pre == "71" ||
				pre == "72" || pre == "73" || pre == "74" || pre == "75" ||
				pre == "76" || pre == "77" || pre == "78" || pre == "79" ||
				pre == "80" || pre == "81" || pre == "82" || pre == "83" ||
				pre == "84" || pre == "84" || pre == "86" || pre == "87" ||
				pre == "88" || pre == "89" || pre == "90" || pre == "91" ||
				pre == "92" || pre == "93" || pre == "94" || pre == "95" ||
				pre == "96" || pre == "97" || pre == "98" || pre == "99") {
				Line.Delete(pos + 2, 3);
			}
		}
	}
	while (Line.Pos("\0039,16") > NULL || Line.Pos("\0039,17") >
		NULL || Line.Pos("\0039,18") > NULL || Line.Pos("\0039,19") >
		NULL || Line.Pos("\0039,20") > NULL || Line.Pos("\0039,21") >
		NULL || Line.Pos("\0039,22") > NULL || Line.Pos("\0039,23") >
		NULL || Line.Pos("\0039,24") > NULL || Line.Pos("\0039,25") >
		NULL || Line.Pos("\0039,26") > NULL || Line.Pos("\0039,27") >
		NULL || Line.Pos("\0039,28") > NULL || Line.Pos("\0039,29") >
		NULL || Line.Pos("\0039,30") > NULL || Line.Pos("\0039,31") >
		NULL || Line.Pos("\0039,32") > NULL || Line.Pos("\0039,33") >
		NULL || Line.Pos("\0039,34") > NULL || Line.Pos("\0039,35") >
		NULL || Line.Pos("\0039,36") > NULL || Line.Pos("\0039,37") >
		NULL || Line.Pos("\0039,38") > NULL || Line.Pos("\0039,39") >
		NULL || Line.Pos("\0039,40") > NULL || Line.Pos("\0039,41") >
		NULL || Line.Pos("\0039,42") > NULL || Line.Pos("\0039,43") >
		NULL || Line.Pos("\0039,44") > NULL || Line.Pos("\0039,45") >
		NULL || Line.Pos("\0039,46") > NULL || Line.Pos("\0039,47") >
		NULL || Line.Pos("\0039,48") > NULL || Line.Pos("\0039,49") >
		NULL || Line.Pos("\0039,50") > NULL || Line.Pos("\0039,51") >
		NULL || Line.Pos("\0039,52") > NULL || Line.Pos("\0039,53") >
		NULL || Line.Pos("\0039,54") > NULL || Line.Pos("\0039,55") >
		NULL || Line.Pos("\0039,56") > NULL || Line.Pos("\0039,57") >
		NULL || Line.Pos("\0039,58") > NULL || Line.Pos("\0039,59") >
		NULL || Line.Pos("\0039,60") > NULL || Line.Pos("\0039,61") >
		NULL || Line.Pos("\0039,62") > NULL || Line.Pos("\0039,63") >
		NULL || Line.Pos("\0039,64") > NULL || Line.Pos("\0039,65") >
		NULL || Line.Pos("\0039,66") > NULL || Line.Pos("\0039,67") >
		NULL || Line.Pos("\0039,68") > NULL || Line.Pos("\0039,69") >
		NULL || Line.Pos("\0039,70") > NULL || Line.Pos("\0039,71") >
		NULL || Line.Pos("\0039,72") > NULL || Line.Pos("\0039,73") >
		NULL || Line.Pos("\0039,74") > NULL || Line.Pos("\0039,75") >
		NULL || Line.Pos("\0039,76") > NULL || Line.Pos("\0039,77") >
		NULL || Line.Pos("\0039,78") > NULL || Line.Pos("\0039,79") >
		NULL || Line.Pos("\0039,80") > NULL || Line.Pos("\0039,81") >
		NULL || Line.Pos("\0039,82") > NULL || Line.Pos("\0039,83") >
		NULL || Line.Pos("\0039,84") > NULL || Line.Pos("\0039,85") >
		NULL || Line.Pos("\0039,86") > NULL || Line.Pos("\0039,87") >
		NULL || Line.Pos("\0039,88") > NULL || Line.Pos("\0039,89") >
		NULL || Line.Pos("\0039,90") > NULL || Line.Pos("\0039,91") >
		NULL || Line.Pos("\0039,92") > NULL || Line.Pos("\0039,93") >
		NULL || Line.Pos("\0039,94") > NULL || Line.Pos("\0039,95") >
		NULL || Line.Pos("\0039,96") > NULL || Line.Pos("\0039,97") >
		NULL || Line.Pos("\0039,98") > NULL || Line.Pos("\0039,99") >
		NULL);


	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00316"))
	 {
	  pos = Line.Pos("\00316");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00316") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00317"))
	 {
	  pos = Line.Pos("\00317");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00317") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00318"))
	 {
	  pos = Line.Pos("\00318");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00318") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00319"))
	 {
	  pos = Line.Pos("\00319");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00319") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00320"))
	 {
	  pos = Line.Pos("\00320");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00320") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00321"))
	 {
	  pos = Line.Pos("\00321");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00321") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00322"))
	 {
	  pos = Line.Pos("\00322");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00322") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00323"))
	 {
	  pos = Line.Pos("\00323");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00323") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00324"))
	 {
	  pos = Line.Pos("\00324");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00324") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00325"))
	 {
	  pos = Line.Pos("\00325");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00325") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00326"))
	 {
	  pos = Line.Pos("\00326");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00326") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00327"))
	 {
	  pos = Line.Pos("\00327");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00327") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00328"))
	 {
	  pos = Line.Pos("\00328");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00328") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00329"))
	 {
	  pos = Line.Pos("\00329");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00329") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00330"))
	 {
	  pos = Line.Pos("\00330");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00330") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00331"))
	 {
	  pos = Line.Pos("\00331");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00331") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00332"))
	 {
	  pos = Line.Pos("\00332");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00332") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00333"))
	 {
	  pos = Line.Pos("\00333");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00333") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00335"))
	 {
	  pos = Line.Pos("\00335");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00335") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00336"))
	 {
	  pos = Line.Pos("\00336");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00336") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00337"))
	 {
	  pos = Line.Pos("\00337");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00337") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00338"))
	 {
	  pos = Line.Pos("\00338");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00338") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00339"))
	 {
	  pos = Line.Pos("\00339");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00339") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00340"))
	 {
	  pos = Line.Pos("\00340");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00340") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00341"))
	 {
	  pos = Line.Pos("\00341");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00341") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00342"))
	 {
	  pos = Line.Pos("\00342");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00342") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00343"))
	 {
	  pos = Line.Pos("\00343");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00343") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00344"))
	 {
	  pos = Line.Pos("\00344");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00344") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00345"))
	 {
	  pos = Line.Pos("\00345");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00345") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00346"))
	 {
	  pos = Line.Pos("\00346");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00346") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00347"))
	 {
	  pos = Line.Pos("\00347");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00347") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00348"))
	 {
	  pos = Line.Pos("\00348");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00348") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00349"))
	 {
	  pos = Line.Pos("\00349");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00349") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00350"))
	 {
	  pos = Line.Pos("\00350");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00350") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00351"))
	 {
	  pos = Line.Pos("\00351");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00351") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00352"))
	 {
	  pos = Line.Pos("\00352");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00352") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00353"))
	 {
	  pos = Line.Pos("\00353");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00353") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00354"))
	 {
	  pos = Line.Pos("\00354");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00354") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00355"))
	 {
	  pos = Line.Pos("\00355");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00355") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00356"))
	 {
	  pos = Line.Pos("\00356");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00356") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00357"))
	 {
	  pos = Line.Pos("\00357");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00357") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00358"))
	 {
	  pos = Line.Pos("\00358");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00358") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00359"))
	 {
	  pos = Line.Pos("\00359");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00359") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00360"))
	 {
	  pos = Line.Pos("\00360");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00360") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00361"))
	 {
	  pos = Line.Pos("\00361");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00361") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00362"))
	 {
	  pos = Line.Pos("\00362");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00362") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00363"))
	 {
	  pos = Line.Pos("\00363");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00363") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00364"))
	 {
	  pos = Line.Pos("\00364");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00364") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00365"))
	 {
	  pos = Line.Pos("\00365");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00365") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00366"))
	 {
	  pos = Line.Pos("\00366");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00366") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00367"))
	 {
	  pos = Line.Pos("\00367");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00367") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00368"))
	 {
	  pos = Line.Pos("\00368");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00368") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00369"))
	 {
	  pos = Line.Pos("\00369");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00369") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00370"))
	 {
	  pos = Line.Pos("\00370");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00370") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00371"))
	 {
	  pos = Line.Pos("\00371");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00371") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00372"))
	 {
	  pos = Line.Pos("\00372");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00372") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00373"))
	 {
	  pos = Line.Pos("\00373");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00373") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00374"))
	 {
	  pos = Line.Pos("\00374");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00374") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00375"))
	 {
	  pos = Line.Pos("\00375");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00375") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00376"))
	 {
	  pos = Line.Pos("\00376");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00376") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00377"))
	 {
	  pos = Line.Pos("\00377");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00377") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00378"))
	 {
	  pos = Line.Pos("\00378");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00378") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00379"))
	 {
	  pos = Line.Pos("\00379");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00379") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00380"))
	 {
	  pos = Line.Pos("\00380");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00380") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00381"))
	 {
	  pos = Line.Pos("\00381");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00381") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00382"))
	 {
	  pos = Line.Pos("\00382");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00382") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00383"))
	 {
	  pos = Line.Pos("\00383");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00383") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00384"))
	 {
	  pos = Line.Pos("\00384");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00384") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00385"))
	 {
	  pos = Line.Pos("\00385");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00385") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00386"))
	 {
	  pos = Line.Pos("\00386");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00386") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00387"))
	 {
	  pos = Line.Pos("\00387");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00387") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00388"))
	 {
	  pos = Line.Pos("\00388");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00388") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00389"))
	 {
	  pos = Line.Pos("\00389");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00389") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00390"))
	 {
	  pos = Line.Pos("\00390");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00390") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00391"))
	 {
	  pos = Line.Pos("\00391");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00391") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00392"))
	 {
	  pos = Line.Pos("\00392");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00392") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00393"))
	 {
	  pos = Line.Pos("\00393");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00393") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00394"))
	 {
	  pos = Line.Pos("\00394");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00394") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00395"))
	 {
	  pos = Line.Pos("\00395");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00395") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00396"))
	 {
	  pos = Line.Pos("\00396");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00396") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00397"))
	 {
	  pos = Line.Pos("\00397");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00397") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00398"))
	 {
	  pos = Line.Pos("\00398");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00398") > NULL);

	do // delete colorformats above 16 colors
	{
	 if(Line.Pos("\00399"))
	 {
	  pos = Line.Pos("\00399");
	  {
	   Line.Delete(pos,3);
	  }
	 }
	}
	while(Line.Pos("\00399") > NULL);


 return Line;
}

UnicodeString __fastcall TColorParser::PrepareLine_(UnicodeString FInput)
{
 int pos;     //a,r,count
 UnicodeString buff;


	do {
		//Application->ProcessMessages();

		if (FInput.Pos("\00300\00300")) // remove double white
		{
			pos = FInput.Pos("\00300\00300");
			FInput.Delete(pos, 3);
		}
	}
	while (FInput.Pos("\00300\00300") > NULL);

	do {
		//Application->ProcessMessages();

		if (FInput.Pos("\00301\00301")) // remove double black
		{
			pos = FInput.Pos("\00301\00301");
			FInput.Delete(pos, 3);
		}
	}
	while (FInput.Pos("\00301\00301") > NULL);

	do {
		//Application->ProcessMessages();

		if (FInput.Pos("\00302\00302")) // remove double color
		{
			pos = FInput.Pos("\00302\00302");
			FInput.Delete(pos, 3);
		}
	}
	while (FInput.Pos("\00302\00302") > NULL);

	do {
		//Application->ProcessMessages();

		if (FInput.Pos("\00303\00303")) // remove double color
		{
			pos = FInput.Pos("\00303\00303");
			FInput.Delete(pos, 3);
		}
	}
	while (FInput.Pos("\00303\00303") > NULL);

	do {
		//Application->ProcessMessages();

		if (FInput.Pos("\00304\00304")) // remove double color
		{
			pos = FInput.Pos("\00304\00304");
			FInput.Delete(pos, 3);
		}
	}
	while (FInput.Pos("\00304\00304") > NULL);

	do {
		//Application->ProcessMessages();

		if (FInput.Pos("\00305\00305")) // remove double color
		{
			pos = FInput.Pos("\00305\00305");
			FInput.Delete(pos, 3);
		}
	}
	while (FInput.Pos("\00305\00305") > NULL);

	do {
		//Application->ProcessMessages();

		if (FInput.Pos("\00306\00306")) // remove double color
		{
			pos = FInput.Pos("\00306\00306");
			FInput.Delete(pos, 3);
		}
	}
	while (FInput.Pos("\00306\00306") > NULL);

	do {
		//Application->ProcessMessages();

		if (FInput.Pos("\00307\00307")) // remove double color
		{
			pos = FInput.Pos("\00307\00307");
			FInput.Delete(pos, 3);
		}
	}
	while (FInput.Pos("\00307\00307") > NULL);

	do {
		//Application->ProcessMessages();

		if (FInput.Pos("\00308\00308")) // remove double color
		{
			pos = FInput.Pos("\00308\00308");
			FInput.Delete(pos, 3);
		}
	}
	while (FInput.Pos("\00308\00308") > NULL);

	do {
		//Application->ProcessMessages();

		if (FInput.Pos("\00309\00309")) // remove double color
		{
			pos = FInput.Pos("\00309\00309");
			FInput.Delete(pos, 3);
		}
	}
	while (FInput.Pos("\00309\00309") > NULL);

	do {
		//Application->ProcessMessages();

		if (FInput.Pos("\00310\00310")) // remove double color
		{
			pos = FInput.Pos("\00310\00310");
			FInput.Delete(pos, 3);
		}
	}
	while (FInput.Pos("\00310\00310") > NULL);

	do {
		//Application->ProcessMessages();

		if (FInput.Pos("\00311\00311")) // remove double color
		{
			pos = FInput.Pos("\00311\00311");
			FInput.Delete(pos, 3);
		}
	}
	while (FInput.Pos("\00311\00311") > NULL);

	do {
		//Application->ProcessMessages();

		if (FInput.Pos("\00312\00312")) // remove double color
		{
			pos = FInput.Pos("\00312\00312");
			FInput.Delete(pos, 3);
		}
	}
	while (FInput.Pos("\00312\00312") > NULL);

	do {
		//Application->ProcessMessages();

		if (FInput.Pos("\00313\00313")) // remove double color
		{
			pos = FInput.Pos("\00313\00313");
			FInput.Delete(pos, 3);
		}
	}
	while (FInput.Pos("\00313\00313") > NULL);

	do {
		//Application->ProcessMessages();

		if (FInput.Pos("\00314\00314")) // remove double color
		{
			pos = FInput.Pos("\00314\00314");
			FInput.Delete(pos, 3);
		}
	}
	while (FInput.Pos("\00314\00314") > NULL);

	do {
		//Application->ProcessMessages();

		if (FInput.Pos("\00315\00315")) // remove double color
		{
			pos = FInput.Pos("\00315\00315");
			FInput.Delete(pos, 3);
		}
	}
	while (FInput.Pos("\00315\00315") > NULL);

	do {
		//Application->ProcessMessages();

		if (FInput.Pos("\0031\0031")) // remove double color
		{
			pos = FInput.Pos("\0031\0031");
			FInput.Delete(pos, 2);
		}
	}
	while (FInput.Pos("\0031\0031") > NULL);

	do {
		//Application->ProcessMessages();

		if (FInput.Pos("\0032\0032")) // remove double color
		{
			pos = FInput.Pos("\0032\0032");
			FInput.Delete(pos, 2);
		}
	}
	while (FInput.Pos("\0032\0032") > NULL);

	do {
		//Application->ProcessMessages();

		if (FInput.Pos("\0033\0033")) // remove double color
		{
			pos = FInput.Pos("\0033\0033");
			FInput.Delete(pos, 2);
		}
	}
	while (FInput.Pos("\0033\0033") > NULL);

	do {
		//Application->ProcessMessages();

		if (FInput.Pos("\0034\0034")) // remove double color
		{
			pos = FInput.Pos("\0034\0034");
			FInput.Delete(pos, 2);
		}
	}
	while (FInput.Pos("\0034\0034") > NULL);

	do {
		//Application->ProcessMessages();

		if (FInput.Pos("\0035\0035")) // remove double color
		{
			pos = FInput.Pos("\0035\0035");
			FInput.Delete(pos, 2);
		}
	}
	while (FInput.Pos("\0035\0035") > NULL);

	do {
		//Application->ProcessMessages();

		if (FInput.Pos("\0036\0036")) // remove double color
		{
			pos = FInput.Pos("\0036\0036");
			FInput.Delete(pos, 2);
		}
	}
	while (FInput.Pos("\0036\0036") > NULL);

	do {
		//Application->ProcessMessages();

		if (FInput.Pos("\0037\0037")) // remove double color
		{
			pos = FInput.Pos("\0037\0037");
			FInput.Delete(pos, 2);
		}
	}
	while (FInput.Pos("\0037\0037") > NULL);

	do {
		//Application->ProcessMessages();

		if (FInput.Pos("\0038\0038")) // remove double color
		{
			pos = FInput.Pos("\0038\0038");
			FInput.Delete(pos, 2);
		}
	}
	while (FInput.Pos("\0038\0038") > NULL);

	do {
		//Application->ProcessMessages();

		if (FInput.Pos("\0039\0039")) // remove double color
		{
			pos = FInput.Pos("\0039\0039");
			FInput.Delete(pos, 2);
		}
	}
	while (FInput.Pos("\0039\0039") > NULL);

 return FInput;
}


UnicodeString __fastcall TColorParser::WrapExtendedAscii(UnicodeString FInput)
{
 int pos;
 //Replace Extended Ascii above 127
 /*
 do
 {
  if(FInput.Pos("\x80"))
  {
   pos = FInput.Pos("\x80");
   FInput.Delete(pos, 1);
   FInput.Insert("€",pos);
  }
 }
 while(FInput.Pos("\x80") > NULL); */

 do
 {
  if(FInput.Pos("\x82"))
  {
   pos = FInput.Pos("\x82");
   FInput.Delete(pos, 1);
   FInput.Insert("‚",pos);
  }
 }
 while(FInput.Pos("\x82") > NULL);

 do
 {
  if(FInput.Pos("\x83"))
  {
   pos = FInput.Pos("\x83");
   FInput.Delete(pos, 1);
   FInput.Insert("ƒ",pos);
  }
 }
 while(FInput.Pos("\x83") > NULL);

 do
 {
  if(FInput.Pos("\x84"))
  {
   pos = FInput.Pos("\x84");
   FInput.Delete(pos, 1);
   FInput.Insert("„",pos);
  }
 }
 while(FInput.Pos("\x84") > NULL);

 do
 {
  if(FInput.Pos("\x85"))
  {
   pos = FInput.Pos("\x85");
   FInput.Delete(pos, 1);
   FInput.Insert("…",pos);
  }
 }
 while(FInput.Pos("\x85") > NULL);

 do
 {
  if(FInput.Pos("\x86"))
  {
   pos = FInput.Pos("\x86");
   FInput.Delete(pos, 1);
   FInput.Insert("†",pos);
  }
 }
 while(FInput.Pos("\x86") > NULL);

 do
 {
  if(FInput.Pos("\x87"))
  {
   pos = FInput.Pos("\x87");
   FInput.Delete(pos, 1);
   FInput.Insert("‡",pos);
  }
 }
 while(FInput.Pos("\x87") > NULL);

 do
 {
  if(FInput.Pos("\x88"))
  {
   pos = FInput.Pos("\x88");
   FInput.Delete(pos, 1);
   FInput.Insert("ˆ",pos);
  }
 }
 while(FInput.Pos("\x88") > NULL);

 do
 {
  if(FInput.Pos("\x89"))
  {
   pos = FInput.Pos("\x89");
   FInput.Delete(pos, 1);
   FInput.Insert("‰",pos);
  }
 }
 while(FInput.Pos("\x89") > NULL);

 do
 {
  if(FInput.Pos("\x8A"))
  {
   pos = FInput.Pos("\x8A");
   FInput.Delete(pos, 1);
   FInput.Insert("Š",pos);
  }
 }
 while(FInput.Pos("\x8A") > NULL);

 do
 {
  if(FInput.Pos("\x8B"))
  {
   pos = FInput.Pos("\x8B");
   FInput.Delete(pos, 1);
   FInput.Insert("‹",pos);
  }
 }
 while(FInput.Pos("\x8B") > NULL);

 do
 {
  if(FInput.Pos("\x8C"))
  {
   pos = FInput.Pos("\x8C");
   FInput.Delete(pos, 1);
   FInput.Insert("Œ",pos);
  }
 }
 while(FInput.Pos("\x8C") > NULL);

 do //just delete
 {
  if(FInput.Pos("\x8D"))
  {
   pos = FInput.Pos("\x8D");
   FInput.Delete(pos, 1);
  }
 }
 while(FInput.Pos("\x8D") > NULL);

 do
 {
  if(FInput.Pos("\x8E"))
  {
   pos = FInput.Pos("\x8E");
   FInput.Delete(pos, 1);
   FInput.Insert("Ž",pos);
  }
 }
 while(FInput.Pos("\x8E") > NULL);

 do //just delete
 {
  if(FInput.Pos("\x8F"))
  {
   pos = FInput.Pos("\x8F");
   FInput.Delete(pos, 1);
  }
 }
 while(FInput.Pos("\x8F") > NULL);

 do //just delete
 {
  if(FInput.Pos("\x90"))
  {
   pos = FInput.Pos("\x90");
   FInput.Delete(pos, 1);
  }
 }
 while(FInput.Pos("\x90") > NULL);

 do
 {
  if(FInput.Pos("\x91"))
  {
   pos = FInput.Pos("\x91");
   FInput.Delete(pos, 1);
   FInput.Insert("‘",pos);
  }
 }
 while(FInput.Pos("\x91") > NULL);

 do
 {
  if(FInput.Pos("\x92"))
  {
   pos = FInput.Pos("\x92");
   FInput.Delete(pos, 1);
   FInput.Insert("’",pos);
  }
 }
 while(FInput.Pos("\x92") > NULL);

 do
 {
  if(FInput.Pos("\x93"))
  {
   pos = FInput.Pos("\x93");
   FInput.Delete(pos, 1);
   FInput.Insert("“",pos);
  }
 }
 while(FInput.Pos("\x93") > NULL);

 do
 {
  if(FInput.Pos("\x94"))
  {
   pos = FInput.Pos("\x94");
   FInput.Delete(pos, 1);
   FInput.Insert("”",pos);
  }
 }
 while(FInput.Pos("\x94") > NULL);

 do
 {
  if(FInput.Pos("\x95"))
  {
   pos = FInput.Pos("\x95");
   FInput.Delete(pos, 1);
   FInput.Insert("•",pos);
  }
 }
 while(FInput.Pos("\x95") > NULL);

 do
 {
  if(FInput.Pos("\x96"))
  {
   pos = FInput.Pos("\x96");
   FInput.Delete(pos, 1);
   FInput.Insert("–",pos);
  }
 }
 while(FInput.Pos("\x96") > NULL);

 do
 {
  if(FInput.Pos("\x97"))
  {
   pos = FInput.Pos("\x97");
   FInput.Delete(pos, 1);
   FInput.Insert("—",pos);
  }
 }
 while(FInput.Pos("\x97") > NULL);

 do
 {
  if(FInput.Pos("\x98"))
  {
   pos = FInput.Pos("\x98");
   FInput.Delete(pos, 1);
   FInput.Insert("˜",pos);
  }
 }
 while(FInput.Pos("\x98") > NULL);

 do
 {
  if(FInput.Pos("\x99"))
  {
   pos = FInput.Pos("\x99");
   FInput.Delete(pos, 1);
   FInput.Insert("™",pos);
  }
 }
 while(FInput.Pos("\x99") > NULL);

 do
 {
  if(FInput.Pos("\x9A"))
  {
   pos = FInput.Pos("\x9A");
   FInput.Delete(pos, 1);
   FInput.Insert("š",pos);
  }
 }
 while(FInput.Pos("\x9A") > NULL);

 do
 {
  if(FInput.Pos("\x9B"))
  {
   pos = FInput.Pos("\x9B");
   FInput.Delete(pos, 1);
   FInput.Insert("›",pos);
  }
 }
 while(FInput.Pos("\x9B") > NULL);

 do
 {
  if(FInput.Pos("\x9C"))
  {
   pos = FInput.Pos("\x9C");
   FInput.Delete(pos, 1);
   FInput.Insert("œ",pos);
  }
 }
 while(FInput.Pos("\x9C") > NULL);

 do
 {
  if(FInput.Pos("\x9E"))
  {
   pos = FInput.Pos("\x9E");
   FInput.Delete(pos, 1);
   FInput.Insert("ž",pos);
  }
 }
 while(FInput.Pos("\x9E") > NULL);

 do
 {
  if(FInput.Pos("\x9F"))
  {
   pos = FInput.Pos("\x9F");
   FInput.Delete(pos, 1);
   FInput.Insert("Ÿ",pos);
  }
 }
 while(FInput.Pos("\x9F") > NULL);

 do
 {
  if(FInput.Pos("\xA0"))
  {
   pos = FInput.Pos("\xA0");
   FInput.Delete(pos, 1);
   FInput.Insert(" ",pos);
  }
 }
 while(FInput.Pos("\xA0") > NULL);

 do
 {
  if(FInput.Pos("\xA1"))
  {
   pos = FInput.Pos("\xA1");
   FInput.Delete(pos, 1);
   FInput.Insert("¡",pos);
  }
 }
 while(FInput.Pos("\xA1") > NULL);

 do
 {
  if(FInput.Pos("\xA2"))
  {
   pos = FInput.Pos("\xA2");
   FInput.Delete(pos, 1);
   FInput.Insert("¢",pos);
  }
 }
 while(FInput.Pos("\xA2") > NULL);

 do
 {
  if(FInput.Pos("\xA3"))
  {
   pos = FInput.Pos("\xA3");
   FInput.Delete(pos, 1);
   FInput.Insert("£",pos);
  }
 }
 while(FInput.Pos("\xA3") > NULL);

 do
 {
  if(FInput.Pos("\xA4"))
  {
   pos = FInput.Pos("\xA4");
   FInput.Delete(pos, 1);
   FInput.Insert("¤",pos);
  }
 }
 while(FInput.Pos("\xA4") > NULL);

 do
 {
  if(FInput.Pos("\xA5"))
  {
   pos = FInput.Pos("\xA5");
   FInput.Delete(pos, 1);
   FInput.Insert("¥",pos);
  }
 }
 while(FInput.Pos("\xA5") > NULL);

 do
 {
  if(FInput.Pos("\xA6"))
  {
   pos = FInput.Pos("\xA6");
   FInput.Delete(pos, 1);
   FInput.Insert("¦",pos);
  }
 }
 while(FInput.Pos("\xA6") > NULL);

 do
 {
  if(FInput.Pos("\xA7"))
  {
   pos = FInput.Pos("\xA7");
   FInput.Delete(pos, 1);
   FInput.Insert("§",pos);
  }
 }
 while(FInput.Pos("\xA7") > NULL);

 do
 {
  if(FInput.Pos("\xA8"))
  {
   pos = FInput.Pos("\xA8");
   FInput.Delete(pos, 1);
   FInput.Insert("¨",pos);
  }
 }
 while(FInput.Pos("\xA8") > NULL);

 do
 {
  if(FInput.Pos("\xA9"))
  {
   pos = FInput.Pos("\xA9");
   FInput.Delete(pos, 1);
   FInput.Insert("©",pos);
  }
 }
 while(FInput.Pos("\xA9") > NULL);

 do
 {
  if(FInput.Pos("\xAA"))
  {
   pos = FInput.Pos("\xAA");
   FInput.Delete(pos, 1);
   FInput.Insert("ª",pos);
  }
 }
 while(FInput.Pos("\xAA") > NULL);

 do
 {
  if(FInput.Pos("\xAB"))
  {
   pos = FInput.Pos("\xAB");
   FInput.Delete(pos, 1);
   FInput.Insert("«",pos);
  }
 }
 while(FInput.Pos("\xAB") > NULL);

 do
 {
  if(FInput.Pos("\xAC"))
  {
   pos = FInput.Pos("\xAC");
   FInput.Delete(pos, 1);
   FInput.Insert("¬",pos);
  }
 }
 while(FInput.Pos("\xAC") > NULL);

 do
 {
  if(FInput.Pos("\xAE"))
  {
   pos = FInput.Pos("\xAE");
   FInput.Delete(pos, 1);
   FInput.Insert("®",pos);
  }
 }
 while(FInput.Pos("\xAE") > NULL);

 do
 {
  if(FInput.Pos("\xAF"))
  {
   pos = FInput.Pos("\xAF");
   FInput.Delete(pos, 1);
   FInput.Insert("¯",pos);
  }
 }
 while(FInput.Pos("\xAF") > NULL);

 do
 {
  if(FInput.Pos("\xB0"))
  {
   pos = FInput.Pos("\xB0");
   FInput.Delete(pos, 1);
   FInput.Insert("°",pos);
  }
 }
 while(FInput.Pos("\xB0") > NULL);

 do
 {
  if(FInput.Pos("\xB1"))
  {
   pos = FInput.Pos("\xB1");
   FInput.Delete(pos, 1);
   FInput.Insert("±",pos);
  }
 }
 while(FInput.Pos("\xB1") > NULL);

 do
 {
  if(FInput.Pos("\xB2"))
  {
   pos = FInput.Pos("\xB2");
   FInput.Delete(pos, 1);
   FInput.Insert("²",pos);
  }
 }
 while(FInput.Pos("\xB2") > NULL);

 do
 {
  if(FInput.Pos("\xB3"))
  {
   pos = FInput.Pos("\xB3");
   FInput.Delete(pos, 1);
   FInput.Insert("³",pos);
  }
 }
 while(FInput.Pos("\xB3") > NULL);

 do
 {
  if(FInput.Pos("\xB4"))
  {
   pos = FInput.Pos("\xB4");
   FInput.Delete(pos, 1);
   FInput.Insert("´",pos);
  }
 }
 while(FInput.Pos("\xB4") > NULL);

 do
 {
  if(FInput.Pos("\xB5"))
  {
   pos = FInput.Pos("\xB5");
   FInput.Delete(pos, 1);
   FInput.Insert("µ",pos);
  }
 }
 while(FInput.Pos("\xB5") > NULL);

 do
 {
  if(FInput.Pos("\xB6"))
  {
   pos = FInput.Pos("\xB6");
   FInput.Delete(pos, 1);
   FInput.Insert("¶",pos);
  }
 }
 while(FInput.Pos("\xB6") > NULL);

 do
 {
  if(FInput.Pos("\xB7"))
  {
   pos = FInput.Pos("\xB7");
   FInput.Delete(pos, 1);
   FInput.Insert("·",pos);
  }
 }
 while(FInput.Pos("\xB7") > NULL);

 do
 {
  if(FInput.Pos("\xB8"))
  {
   pos = FInput.Pos("\xB8");
   FInput.Delete(pos, 1);
   FInput.Insert("¸",pos);
  }
 }
 while(FInput.Pos("\xB8") > NULL);

 do
 {
  if(FInput.Pos("\xB9"))
  {
   pos = FInput.Pos("\xB9");
   FInput.Delete(pos, 1);
   FInput.Insert("¹",pos);
  }
 }
 while(FInput.Pos("\xB9") > NULL);

 do
 {
  if(FInput.Pos("\xBA"))
  {
   pos = FInput.Pos("\xBA");
   FInput.Delete(pos, 1);
   FInput.Insert("º",pos);
  }
 }
 while(FInput.Pos("\xBA") > NULL);

 do
 {
  if(FInput.Pos("\xBB"))
  {
   pos = FInput.Pos("\xBB");
   FInput.Delete(pos, 1);
   FInput.Insert("»",pos);
  }
 }
 while(FInput.Pos("\xBB") > NULL);

 do
 {
  if(FInput.Pos("\xBC"))
  {
   pos = FInput.Pos("\xBC");
   FInput.Delete(pos, 1);
   FInput.Insert("¼",pos);
  }
 }
 while(FInput.Pos("\xBC") > NULL);

 do
 {
  if(FInput.Pos("\xBD"))
  {
   pos = FInput.Pos("\xBD");
   FInput.Delete(pos, 1);
   FInput.Insert("½",pos);
  }
 }
 while(FInput.Pos("\xBD") > NULL);

 do
 {
  if(FInput.Pos("\xBE"))
  {
   pos = FInput.Pos("\xBE");
   FInput.Delete(pos, 1);
   FInput.Insert("¾",pos);
  }
 }
 while(FInput.Pos("\xBE") > NULL);

 do
 {
  if(FInput.Pos("\xBF"))
  {
   pos = FInput.Pos("\xBF");
   FInput.Delete(pos, 1);
   FInput.Insert("¿",pos);
  }
 }
 while(FInput.Pos("\xBF") > NULL);

 do
 {
  if(FInput.Pos("\xC0"))
  {
   pos = FInput.Pos("\xC0");
   FInput.Delete(pos, 1);
   FInput.Insert("À",pos);
  }
 }
 while(FInput.Pos("\xC0") > NULL);

 do
 {
  if(FInput.Pos("\xC1"))
  {
   pos = FInput.Pos("\xC1");
   FInput.Delete(pos, 1);
   FInput.Insert("Á",pos);
  }
 }
 while(FInput.Pos("\xC1") > NULL);

 do
 {
  if(FInput.Pos("\xC2"))
  {
   pos = FInput.Pos("\xC2");
   FInput.Delete(pos, 1);
   FInput.Insert("Â",pos);
  }
 }
 while(FInput.Pos("\xC2") > NULL);

 do
 {
  if(FInput.Pos("\xC3"))
  {
   pos = FInput.Pos("\xC3");
   FInput.Delete(pos, 1);
   FInput.Insert("Ã",pos);
  }
 }
 while(FInput.Pos("\xC3") > NULL);

 do
 {
  if(FInput.Pos("\xC4"))
  {
   pos = FInput.Pos("\xC4");
   FInput.Delete(pos, 1);
   FInput.Insert("Ä",pos);
  }
 }
 while(FInput.Pos("\xC4") > NULL);

 do
 {
  if(FInput.Pos("\xC5"))
  {
   pos = FInput.Pos("\xC5");
   FInput.Delete(pos, 1);
   FInput.Insert("Å",pos);
  }
 }
 while(FInput.Pos("\xC5") > NULL);

 do
 {
  if(FInput.Pos("\xC6"))
  {
   pos = FInput.Pos("\xC6");
   FInput.Delete(pos, 1);
   FInput.Insert("Æ",pos);
  }
 }
 while(FInput.Pos("\xC6") > NULL);

 do
 {
  if(FInput.Pos("\xC7"))
  {
   pos = FInput.Pos("\xC7");
   FInput.Delete(pos, 1);
   FInput.Insert("Ç",pos);
  }
 }
 while(FInput.Pos("\xC7") > NULL);

 do
 {
  if(FInput.Pos("\xC8"))
  {
   pos = FInput.Pos("\xC8");
   FInput.Delete(pos, 1);
   FInput.Insert("È",pos);
  }
 }
 while(FInput.Pos("\xC8") > NULL);

 do
 {
  if(FInput.Pos("\xC9"))
  {
   pos = FInput.Pos("\xC9");
   FInput.Delete(pos, 1);
   FInput.Insert("É",pos);
  }
 }
 while(FInput.Pos("\xC9") > NULL);

 do
 {
  if(FInput.Pos("\xCA"))
  {
   pos = FInput.Pos("\xCA");
   FInput.Delete(pos, 1);
   FInput.Insert("Ê",pos);
  }
 }
 while(FInput.Pos("\xCA") > NULL);

 do
 {
  if(FInput.Pos("\xCB"))
  {
   pos = FInput.Pos("\xCB");
   FInput.Delete(pos, 1);
   FInput.Insert("Ë",pos);
  }
 }
 while(FInput.Pos("\xCB") > NULL);

 do
 {
  if(FInput.Pos("\xCC"))
  {
   pos = FInput.Pos("\xCC");
   FInput.Delete(pos, 1);
   FInput.Insert("Ì",pos);
  }
 }
 while(FInput.Pos("\xCC") > NULL);

 do
 {
  if(FInput.Pos("\xCD"))
  {
   pos = FInput.Pos("\xCD");
   FInput.Delete(pos, 1);
   FInput.Insert("Í",pos);
  }
 }
 while(FInput.Pos("\xCD") > NULL);

 do
 {
  if(FInput.Pos("\xCE"))
  {
   pos = FInput.Pos("\xCE");
   FInput.Delete(pos, 1);
   FInput.Insert("Î",pos);
  }
 }
 while(FInput.Pos("\xCE") > NULL);

 do
 {
  if(FInput.Pos("\xCF"))
  {
   pos = FInput.Pos("\xCF");
   FInput.Delete(pos, 1);
   FInput.Insert("Ï",pos);
  }
 }
 while(FInput.Pos("\xCF") > NULL);

 do
 {
  if(FInput.Pos("\xD0"))
  {
   pos = FInput.Pos("\xD0");
   FInput.Delete(pos, 1);
   FInput.Insert("Ð",pos);
  }
 }
 while(FInput.Pos("\xD0") > NULL);

 do
 {
  if(FInput.Pos("\xD1"))
  {
   pos = FInput.Pos("\xD1");
   FInput.Delete(pos, 1);
   FInput.Insert("Ñ",pos);
  }
 }
 while(FInput.Pos("\xD1") > NULL);

 do
 {
  if(FInput.Pos("\xD2"))
  {
   pos = FInput.Pos("\xD2");
   FInput.Delete(pos, 1);
   FInput.Insert("Ò",pos);
  }
 }
 while(FInput.Pos("\xD2") > NULL);

 do
 {
  if(FInput.Pos("\xD3"))
  {
   pos = FInput.Pos("\xD3");
   FInput.Delete(pos, 1);
   FInput.Insert("Ó",pos);
  }
 }
 while(FInput.Pos("\xD3") > NULL);

 do
 {
  if(FInput.Pos("\xD4"))
  {
   pos = FInput.Pos("\xD4");
   FInput.Delete(pos, 1);
   FInput.Insert("Ô",pos);
  }
 }
 while(FInput.Pos("\xD4") > NULL);

 do
 {
  if(FInput.Pos("\xD5"))
  {
   pos = FInput.Pos("\xD5");
   FInput.Delete(pos, 1);
   FInput.Insert("Õ",pos);
  }
 }
 while(FInput.Pos("\xD5") > NULL);

 do
 {
  if(FInput.Pos("\xD6"))
  {
   pos = FInput.Pos("\xD6");
   FInput.Delete(pos, 1);
   FInput.Insert("Ö",pos);
  }
 }
 while(FInput.Pos("\xD6") > NULL);

 do
 {
  if(FInput.Pos("\xD7"))
  {
   pos = FInput.Pos("\xD7");
   FInput.Delete(pos, 1);
   FInput.Insert("×",pos);
  }
 }
 while(FInput.Pos("\xD7") > NULL);

 do
 {
  if(FInput.Pos("\xD8"))
  {
   pos = FInput.Pos("\xD8");
   FInput.Delete(pos, 1);
   FInput.Insert("Ø",pos);
  }
 }
 while(FInput.Pos("\xD8") > NULL);

 do
 {
  if(FInput.Pos("\xD9"))
  {
   pos = FInput.Pos("\xD9");
   FInput.Delete(pos, 1);
   FInput.Insert("Ù",pos);
  }
 }
 while(FInput.Pos("\xD9") > NULL);

 do
 {
  if(FInput.Pos("\xDA"))
  {
   pos = FInput.Pos("\xDA");
   FInput.Delete(pos, 1);
   FInput.Insert("Ú",pos);
  }
 }
 while(FInput.Pos("\xDA") > NULL);

 do
 {
  if(FInput.Pos("\xDB"))
  {
   pos = FInput.Pos("\xDB");
   FInput.Delete(pos, 1);
   FInput.Insert("Û",pos);
  }
 }
 while(FInput.Pos("\xDB") > NULL);

 do
 {
  if(FInput.Pos("\xDC"))
  {
   pos = FInput.Pos("\xDC");
   FInput.Delete(pos, 1);
   FInput.Insert("Ü",pos);
  }
 }
 while(FInput.Pos("\xDC") > NULL);

 do
 {
  if(FInput.Pos("\xDD"))
  {
   pos = FInput.Pos("\xDD");
   FInput.Delete(pos, 1);
   FInput.Insert("Ý",pos);
  }
 }
 while(FInput.Pos("\xDD") > NULL);

 do
 {
  if(FInput.Pos("\xDE"))
  {
   pos = FInput.Pos("\xDE");
   FInput.Delete(pos, 1);
   FInput.Insert("Þ",pos);
  }
 }
 while(FInput.Pos("\xDE") > NULL);

 do
 {
  if(FInput.Pos("\xDF"))
  {
   pos = FInput.Pos("\xDF");
   FInput.Delete(pos, 1);
   FInput.Insert("ß",pos);
  }
 }
 while(FInput.Pos("\xDF") > NULL);

 do
 {
  if(FInput.Pos("\xE0"))
  {
   pos = FInput.Pos("\xE0");
   FInput.Delete(pos, 1);
   FInput.Insert("à",pos);
  }
 }
 while(FInput.Pos("\xE0") > NULL);

 do
 {
  if(FInput.Pos("\xE1"))
  {
   pos = FInput.Pos("\xE1");
   FInput.Delete(pos, 1);
   FInput.Insert("á",pos);
  }
 }
 while(FInput.Pos("\xE1") > NULL);

 do
 {
  if(FInput.Pos("\xE2"))
  {
   pos = FInput.Pos("\xE2");
   FInput.Delete(pos, 1);
   FInput.Insert("ã",pos);
  }
 }
 while(FInput.Pos("\xE2") > NULL);

 do
 {
  if(FInput.Pos("\xE3"))
  {
   pos = FInput.Pos("\xE3");
   FInput.Delete(pos, 1);
   FInput.Insert("ã",pos);
  }
 }
 while(FInput.Pos("\xE3") > NULL);

 do
 {
  if(FInput.Pos("\xE4"))
  {
   pos = FInput.Pos("\xE4");
   FInput.Delete(pos, 1);
   FInput.Insert("ä",pos);
  }
 }
 while(FInput.Pos("\xE4") > NULL);

 do
 {
  if(FInput.Pos("\xE5"))
  {
   pos = FInput.Pos("\xE5");
   FInput.Delete(pos, 1);
   FInput.Insert("å",pos);
  }
 }
 while(FInput.Pos("\xE5") > NULL);

 do
 {
  if(FInput.Pos("\xE6"))
  {
   pos = FInput.Pos("\xE6");
   FInput.Delete(pos, 1);
   FInput.Insert("æ",pos);
  }
 }
 while(FInput.Pos("\xE6") > NULL);

 do
 {
  if(FInput.Pos("\xE7"))
  {
   pos = FInput.Pos("\xE7");
   FInput.Delete(pos, 1);
   FInput.Insert("ç",pos);
  }
 }
 while(FInput.Pos("\xE7") > NULL);

 do
 {
  if(FInput.Pos("\xE8"))
  {
   pos = FInput.Pos("\xE8");
   FInput.Delete(pos, 1);
   FInput.Insert("è",pos);
  }
 }
 while(FInput.Pos("\xE8") > NULL);

 do
 {
  if(FInput.Pos("\xE9"))
  {
   pos = FInput.Pos("\xE9");
   FInput.Delete(pos, 1);
   FInput.Insert("é",pos);
  }
 }
 while(FInput.Pos("\xE9") > NULL);

 do
 {
  if(FInput.Pos("\xEA"))
  {
   pos = FInput.Pos("\xEA");
   FInput.Delete(pos, 1);
   FInput.Insert("ê",pos);
  }
 }
 while(FInput.Pos("\xEA") > NULL);

 do
 {
  if(FInput.Pos("\xEB"))
  {
   pos = FInput.Pos("\xEB");
   FInput.Delete(pos, 1);
   FInput.Insert("ë",pos);
  }
 }
 while(FInput.Pos("\xEB") > NULL);

 do
 {
  if(FInput.Pos("\xEC"))
  {
   pos = FInput.Pos("\xEC");
   FInput.Delete(pos, 1);
   FInput.Insert("ì",pos);
  }
 }
 while(FInput.Pos("\xEC") > NULL);

 do
 {
  if(FInput.Pos("\xED"))
  {
   pos = FInput.Pos("\xED");
   FInput.Delete(pos, 1);
   FInput.Insert("í",pos);
  }
 }
 while(FInput.Pos("\xED") > NULL);

 do
 {
  if(FInput.Pos("\xEE"))
  {
   pos = FInput.Pos("\xEE");
   FInput.Delete(pos, 1);
   FInput.Insert("î",pos);
  }
 }
 while(FInput.Pos("\xEE") > NULL);

 do
 {
  if(FInput.Pos("\xEF"))
  {
   pos = FInput.Pos("\xEF");
   FInput.Delete(pos, 1);
   FInput.Insert("ï",pos);
  }
 }
 while(FInput.Pos("\xEF") > NULL);

 do
 {
  if(FInput.Pos("\xF0"))
  {
   pos = FInput.Pos("\xF0");
   FInput.Delete(pos, 1);
   FInput.Insert("ð",pos);
  }
 }
 while(FInput.Pos("\xF0") > NULL);

 do
 {
  if(FInput.Pos("\xF1"))
  {
   pos = FInput.Pos("\xF1");
   FInput.Delete(pos, 1);
   FInput.Insert("ñ",pos);
  }
 }
 while(FInput.Pos("\xF1") > NULL);

 do
 {
  if(FInput.Pos("\xF2"))
  {
   pos = FInput.Pos("\xF2");
   FInput.Delete(pos, 1);
   FInput.Insert("ò",pos);
  }
 }
 while(FInput.Pos("\xF2") > NULL);

 do
 {
  if(FInput.Pos("\xF3"))
  {
   pos = FInput.Pos("\xF3");
   FInput.Delete(pos, 1);
   FInput.Insert("ó",pos);
  }
 }
 while(FInput.Pos("\xF3") > NULL);

 do
 {
  if(FInput.Pos("\xF4"))
  {
   pos = FInput.Pos("\xF4");
   FInput.Delete(pos, 1);
   FInput.Insert("ô",pos);
  }
 }
 while(FInput.Pos("\xF4") > NULL);

 do
 {
  if(FInput.Pos("\xF5"))
  {
   pos = FInput.Pos("\xF5");
   FInput.Delete(pos, 1);
   FInput.Insert("õ",pos);
  }
 }
 while(FInput.Pos("\xF5") > NULL);

 do
 {
  if(FInput.Pos("\xF6"))
  {
   pos = FInput.Pos("\xF6");
   FInput.Delete(pos, 1);
   FInput.Insert("ö",pos);
  }
 }
 while(FInput.Pos("\xF6") > NULL);

 do
 {
  if(FInput.Pos("\xF7"))
  {
   pos = FInput.Pos("\xF7");
   FInput.Delete(pos, 1);
   FInput.Insert("÷",pos);
  }
 }
 while(FInput.Pos("\xF7") > NULL);

 do
 {
  if(FInput.Pos("\xF8"))
  {
   pos = FInput.Pos("\xF8");
   FInput.Delete(pos, 1);
   FInput.Insert("ø",pos);
  }
 }
 while(FInput.Pos("\xF8") > NULL);

 do
 {
  if(FInput.Pos("\xF9"))
  {
   pos = FInput.Pos("\xF9");
   FInput.Delete(pos, 1);
   FInput.Insert("ù",pos);
  }
 }
 while(FInput.Pos("\xF9") > NULL);

 do
 {
  if(FInput.Pos("\xFA"))
  {
   pos = FInput.Pos("\xFA");
   FInput.Delete(pos, 1);
   FInput.Insert("ú",pos);
  }
 }
 while(FInput.Pos("\xFA") > NULL);

 do
 {
  if(FInput.Pos("\xFB"))
  {
   pos = FInput.Pos("\xFB");
   FInput.Delete(pos, 1);
   FInput.Insert("û",pos);
  }
 }
 while(FInput.Pos("\xFB") > NULL);

 do
 {
  if(FInput.Pos("\xFC"))
  {
   pos = FInput.Pos("\xFC");
   FInput.Delete(pos, 1);
   FInput.Insert("ü",pos);
  }
 }
 while(FInput.Pos("\xFC") > NULL);

 /*
 do
 {
  if(FInput.Pos("\xFD"))
  {
   pos = FInput.Pos("\xFD");
   FInput.Delete(pos, 1);
   FInput.Insert("ý",pos);
  }
 }
 while(FInput.Pos("\xFD") > NULL); */

 do
 {
  if(FInput.Pos("\xFE"))
  {
   pos = FInput.Pos("\xFE");
   FInput.Delete(pos, 1);
   FInput.Insert("þ",pos);
  }
 }
 while(FInput.Pos("\xFE") > NULL);

 do
 {
  if(FInput.Pos("\xFF"))
  {
   pos = FInput.Pos("\xFF");
   FInput.Delete(pos, 1);
   FInput.Insert("ÿ",pos);
  }
 }
 while(FInput.Pos("\xFF") > NULL);

 //Do the also the Linegraphics Extensions
 do
 {
  if(FInput.Pos("\2500"))
  {
   pos = FInput.Pos("\2500");
   FInput.Delete(pos, 1);
   FInput.Insert("─",pos);
  }
 }
 while(FInput.Pos("\2500") > NULL);

 do
 {
  if(FInput.Pos("\2502"))
  {
   pos = FInput.Pos("\2502");
   FInput.Delete(pos, 1);
   FInput.Insert("│",pos);
  }
 }
 while(FInput.Pos("\2502") > NULL);

 do
 {
  if(FInput.Pos("\250C"))
  {
   pos = FInput.Pos("\250C");
   FInput.Delete(pos, 1);
   FInput.Insert("┌",pos);
  }
 }
 while(FInput.Pos("\250C") > NULL);

 do
 {
  if(FInput.Pos("\2510"))
  {
   pos = FInput.Pos("\2510");
   FInput.Delete(pos, 1);
   FInput.Insert("┐",pos);
  }
 }
 while(FInput.Pos("\2510") > NULL);

 do
 {
  if(FInput.Pos("\2514"))
  {
   pos = FInput.Pos("\2514");
   FInput.Delete(pos, 1);
   FInput.Insert("└",pos);
  }
 }
 while(FInput.Pos("\2514") > NULL);

 do
 {
  if(FInput.Pos("\2518"))
  {
   pos = FInput.Pos("\2518");
   FInput.Delete(pos, 1);
   FInput.Insert("┘",pos);
  }
 }
 while(FInput.Pos("\2518") > NULL);

 do
 {
  if(FInput.Pos("\251C"))
  {
   pos = FInput.Pos("\251C");
   FInput.Delete(pos, 1);
   FInput.Insert("├",pos);
  }
 }
 while(FInput.Pos("\251C") > NULL);

 do
 {
  if(FInput.Pos("\2524"))
  {
   pos = FInput.Pos("\2524");
   FInput.Delete(pos, 1);
   FInput.Insert("┤",pos);
  }
 }
 while(FInput.Pos("\2524") > NULL);

 do
 {
  if(FInput.Pos("\252C"))
  {
   pos = FInput.Pos("\252C");
   FInput.Delete(pos, 1);
   FInput.Insert("┬",pos);
  }
 }
 while(FInput.Pos("\252C") > NULL);

 do
 {
  if(FInput.Pos("\2534"))
  {
   pos = FInput.Pos("\2534");
   FInput.Delete(pos, 1);
   FInput.Insert("┴",pos);
  }
 }
 while(FInput.Pos("\2534") > NULL);

 do
 {
  if(FInput.Pos("\253C"))
  {
   pos = FInput.Pos("\253C");
   FInput.Delete(pos, 1);
   FInput.Insert("┼",pos);
  }
 }
 while(FInput.Pos("\253C") > NULL);

 do
 {
  if(FInput.Pos("\3B1"))
  {
   pos = FInput.Pos("\3B1");
   FInput.Delete(pos, 1);
   FInput.Insert("α",pos);
  }
 }
 while(FInput.Pos("\3B1") > NULL);

 do
 {
  if(FInput.Pos("\3B2"))
  {
   pos = FInput.Pos("\3B2");
   FInput.Delete(pos, 1);
   FInput.Insert("β",pos);
  }
 }
 while(FInput.Pos("\3B2") > NULL);

 do
 {
  if(FInput.Pos("\3B3"))
  {
   pos = FInput.Pos("\3B3");
   FInput.Delete(pos, 1);
   FInput.Insert("γ",pos);
  }
 }
 while(FInput.Pos("\3B3") > NULL);

 do
 {
  if(FInput.Pos("\394"))
  {
   pos = FInput.Pos("\394");
   FInput.Delete(pos, 1);
   FInput.Insert("Δ",pos);
  }
 }
 while(FInput.Pos("\394") > NULL);

 do
 {
  if(FInput.Pos("\2211"))
  {
   pos = FInput.Pos("\2211");
   FInput.Delete(pos, 1);
   FInput.Insert("∑",pos);
  }
 }
 while(FInput.Pos("\2211") > NULL);

 do
 {
  if(FInput.Pos("\221A"))
  {
   pos = FInput.Pos("\221A");
   FInput.Delete(pos, 1);
   FInput.Insert("√",pos);
  }
 }
 while(FInput.Pos("\221A") > NULL);

 do
 {
  if(FInput.Pos("\222B"))
  {
   pos = FInput.Pos("\222B");
   FInput.Delete(pos, 1);
   FInput.Insert("∫",pos);
  }
 }
 while(FInput.Pos("\222B") > NULL);

 do
 {
  if(FInput.Pos("\2248"))
  {
   pos = FInput.Pos("\2248");
   FInput.Delete(pos, 1);
   FInput.Insert("≈",pos);
  }
 }
 while(FInput.Pos("\2248") > NULL);

 do
 {
  if(FInput.Pos("\2260"))
  {
   pos = FInput.Pos("\2260");
   FInput.Delete(pos, 1);
   FInput.Insert("≠",pos);
  }
 }
 while(FInput.Pos("\2260") > NULL);

 do
 {
  if(FInput.Pos("\2264"))
  {
   pos = FInput.Pos("\2264");
   FInput.Delete(pos, 1);
   FInput.Insert("≤",pos);
  }
 }
 while(FInput.Pos("\2264") > NULL);

 do
 {
  if(FInput.Pos("\2265"))
  {
   pos = FInput.Pos("\2265");
   FInput.Delete(pos, 1);
   FInput.Insert("≥",pos);
  }
 }
 while(FInput.Pos("\2265") > NULL);

 do
 {
  if(FInput.Pos("\2190"))
  {
   pos = FInput.Pos("\2190");
   FInput.Delete(pos, 1);
   FInput.Insert("←",pos);
  }
 }
 while(FInput.Pos("\2190") > NULL);

 do
 {
  if(FInput.Pos("\2191"))
  {
   pos = FInput.Pos("\2191");
   FInput.Delete(pos, 1);
   FInput.Insert("↑",pos);
  }
 }
 while(FInput.Pos("\2191") > NULL);

 do
 {
  if(FInput.Pos("\2192"))
  {
   pos = FInput.Pos("\2192");
   FInput.Delete(pos, 1);
   FInput.Insert("→",pos);
  }
 }
 while(FInput.Pos("\2192") > NULL);

 do
 {
  if(FInput.Pos("\2193"))
  {
   pos = FInput.Pos("\2193");
   FInput.Delete(pos, 1);
   FInput.Insert("↓",pos);
  }
 }
 while(FInput.Pos("\2193") > NULL);

 do
 {
  if(FInput.Pos("\2194"))
  {
   pos = FInput.Pos("\2194");
   FInput.Delete(pos, 1);
   FInput.Insert("↔",pos);
  }
 }
 while(FInput.Pos("\2194") > NULL);

 do
 {
  if(FInput.Pos("\2195"))
  {
   pos = FInput.Pos("\2195");
   FInput.Delete(pos, 1);
   FInput.Insert("↕",pos);
  }
 }
 while(FInput.Pos("\2195") > NULL);

 do
 {
  if(FInput.Pos("\2022"))
  {
   pos = FInput.Pos("\2022");
   FInput.Delete(pos, 1);
   FInput.Insert("•",pos);
  }
 }
 while(FInput.Pos("\2022") > NULL);

 do
 {
  if(FInput.Pos("\2044"))
  {
   pos = FInput.Pos("\2044");
   FInput.Delete(pos, 1);
   FInput.Insert("⁄",pos);
  }
 }
 while(FInput.Pos("\2044") > NULL);

 do
 {
  if(FInput.Pos("\2030"))
  {
   pos = FInput.Pos("\2030");
   FInput.Delete(pos, 1);
   FInput.Insert("‰",pos);
  }
 }
 while(FInput.Pos("\2030") > NULL);

 do
 {
  if(FInput.Pos("\2122"))
  {
   pos = FInput.Pos("\2122");
   FInput.Delete(pos, 1);
   FInput.Insert("™",pos);
  }
 }
 while(FInput.Pos("\2122") > NULL);

 do
 {
  if(FInput.Pos("\20AC"))
  {
   pos = FInput.Pos("\20AC");
   FInput.Delete(pos, 1);
   FInput.Insert("€",pos);
  }
 }
 while(FInput.Pos("\20AC") > NULL);

 return FInput;
}
