//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int moveBallHorizontal = -8, moveBallVertical = -8;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Player1UpTimer(TObject *Sender)
{
if (player1->Top > 14)
player1->Top -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Player1DownTimer(TObject *Sender)
{
if (player1->Top + player1->Height < table->Height - 14)
player1->Top += 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if (Key == 'A') Player1Up->Enabled = true;
if (Key == 'Z') Player1Down->Enabled = true;
if (Key == VK_UP) Player2Up->Enabled = true;
if (Key == VK_DOWN) Player2Down->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if (Key == 'A') Player1Up->Enabled = false;
if (Key == 'Z') Player1Down->Enabled = false;
if (Key == VK_UP) Player2Up->Enabled = false;
if (Key == VK_DOWN) Player2Down->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Player2UpTimer(TObject *Sender)
{
  if (player2->Top > 14)
player2->Top -= 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Player2DownTimer(TObject *Sender)
{
 if (player2->Top + player2->Height < table->Height - 14)
player2->Top += 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TimerBallTimer(TObject *Sender)
{
 ball->Left +=  moveBallHorizontal;
 ball->Top +=  moveBallVertical;
 // odbicie od górnej sciany
 if (ball->Top-5 <= table->Top)
    {
    moveBallVertical = - moveBallVertical;
    }
 // odbicie od dolnej sciany
 if (ball->Top + ball->Height +5 >= table->Height)
    {
     moveBallVertical = - moveBallVertical;
    }

 //skucha
    if ( ((ball->Left < player1->Left &&
        (ball->Top + ball->Height/2 < player1->Top ||
        ball->Top + ball->Height / 2 > player1->Top + player1->Height))
        ||
        (ball->Left + ball->Width > player2->Left + player2->Width &&
         (ball->Top + ball->Height / 2 < player2->Top ||
         ball->Top + ball->Height / 2 > player2->Top + player2->Height))))

         {
         TimerBall->Enabled = false;
         ball->Visible = false;
         }
 //lewe odbicie
 else if ((ball->Top + ball->Height/2 > player1->Top  &&
 ball->Top + ball->Height/2 < player1->Top + player1->Height &&
 ball->Left < player1->Left + player1->Width ))
   {
            if (moveBallHorizontal < 0)
            {
             moveBallHorizontal = -moveBallHorizontal;
            }

            // przyspieszenie pi³ki  odbicie srodkiem
              if (ball->Top > player1->Top + player1->Height/3 - ball->Height/2 &&
            ball->Top < player1->Top + 2*player1->Height/3 - ball->Height/2)
        {
            moveBallHorizontal += 3;
        }

   }

// prawe odbicie
else if (ball->Top + ball->Height/2 >= player2->Top  &&
ball->Top + ball->Height/2 <= player2->Top + player2->Height &&
ball->Left + ball->Width >= player2->Left )
{
if (moveBallHorizontal > 0)
   {
    moveBallHorizontal = - moveBallHorizontal;
   }

   if (ball->Top > player2->Top + player2->Height/3 - ball->Height/2 &&
            ball->Top < player2->Top + 2*player2->Height/3 - ball->Height/2)
        {
            moveBallHorizontal -= 3;
        }
}
}
//---------------------------------------------------------------------------
