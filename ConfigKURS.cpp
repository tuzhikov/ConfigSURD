//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("Unit1.cpp", FormMain);
USEFORM("project.cpp", FormProject);
USEFORM("dayplans.cpp", FormPlansDay);
USEFORM("weeksplans.cpp", Form4);
USEFORM("year.cpp", Form5);
USEFORM("guard.cpp", FormGuard);
USEFORM("fazas.cpp", frPhaseTemplate);
USEFORM("help_form.cpp", FormHelp);
USEFORM("Unit12.cpp", FormConsole);
USEFORM("Unit10.cpp", FormDk);
USEFORM("napr.cpp", frmDirection);
USEFORM("udzcg.cpp", FormUDZG);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TFormMain), &FormMain);
                 Application->CreateForm(__classid(TFormProject), &FormProject);
                 Application->CreateForm(__classid(TFormPlansDay), &FormPlansDay);
                 Application->CreateForm(__classid(TForm4), &Form4);
                 Application->CreateForm(__classid(TForm5), &Form5);
                 Application->CreateForm(__classid(TFormGuard), &FormGuard);
                 Application->CreateForm(__classid(TfrPhaseTemplate), &frPhaseTemplate);
                 Application->CreateForm(__classid(TFormHelp), &FormHelp);
                 Application->CreateForm(__classid(TFormConsole), &FormConsole);
                 Application->CreateForm(__classid(TFormDk), &FormDk);
                 Application->CreateForm(__classid(TfrmDirection), &frmDirection);
                 Application->CreateForm(__classid(TFormUDZG), &FormUDZG);
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
