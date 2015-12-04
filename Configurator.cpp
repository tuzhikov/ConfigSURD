//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("Unit1.cpp", Form1);
USEFORM("project.cpp", Form2);
USEFORM("dayplans.cpp", Form3);
USEFORM("weeksplans.cpp", Form4);
USEFORM("year.cpp", Form5);
USEFORM("local.cpp", Form6);
USEFORM("guard.cpp", Form7);
USEFORM("fazas.cpp", Form8);
USEFORM("help_form.cpp", Form9);
USEFORM("Unit18.cpp", Form18);
USEFORM("Unit21.cpp", Form21);
USEFORM("Unit11.cpp", Form11);
USEFORM("light.cpp", Form10);
USEFORM("Unit12.cpp", Form12);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TForm1), &Form1);
                 Application->CreateForm(__classid(TForm2), &Form2);
                 Application->CreateForm(__classid(TForm3), &Form3);
                 Application->CreateForm(__classid(TForm4), &Form4);
                 Application->CreateForm(__classid(TForm5), &Form5);
                 Application->CreateForm(__classid(TForm6), &Form6);
                 Application->CreateForm(__classid(TForm7), &Form7);
                 Application->CreateForm(__classid(TForm8), &Form8);
                 Application->CreateForm(__classid(TForm9), &Form9);
                 Application->CreateForm(__classid(TForm18), &Form18);
                 Application->CreateForm(__classid(TForm21), &Form21);
                 Application->CreateForm(__classid(TForm11), &Form11);
                 Application->CreateForm(__classid(TForm10), &Form10);
                 Application->CreateForm(__classid(TForm12), &Form12);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch (...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------
