//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "mmsystem.h"

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int moveBallHorizontal = -11, moveBallVertical = -8;

int pickups = 0;

int player1points =0;
int player2points = 0;

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
 if (player2->Top + player2->Height < table->Height - 15)
player2->Top += 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TimerBallTimer(TObject *Sender)
{
 ball->Left +=  moveBallHorizontal;
 ball->Top +=  moveBallVertical;
 // top wall pickup
 if (ball->Top-5 <= table->Top)
    {
    moveBallVertical = - moveBallVertical;
    }
 // down wall pickup
 if (ball->Top + ball->Height +5 >= table->Height)
    {
     moveBallVertical = - moveBallVertical;
    }

 //alien loses
    if  (ball->Left < player1->Left &&
        (ball->Top + ball->Height/2 < player1->Top ||
        ball->Top + ball->Height / 2 > player1->Top + player1->Height))

         {
         PlaySound("Three", HInstance, SND_ASYNC | SND_RESOURCE);
        //sndPlaySound("snd/gameover.wav",SND_ASYNC);


        TimerBall->Enabled = false;
        ball->Visible = false;
        player2points ++;
        Label1->Visible = true;
        Label1->Caption = "Predator wins! >";
        Label2Score->Visible = true;
        Label2Score->Caption = IntToStr(player1points) + ":" + IntToStr(player2points);
        Label3Pickups->Visible = true;
        Label3Pickups->Caption = "Number of pickups: " + IntToStr(pickups);
        nextRound->Visible = true;
        newGame->Visible = true;
         }
 //alien pickup
 else if ((ball->Top + ball->Height/2 > player1->Top  &&
 ball->Top + ball->Height/2 < player1->Top + player1->Height &&
 ball->Left < player1->Left + player1->Width ))
   {

            if (moveBallHorizontal < 0)
         {
             pickups++;
              PlaySound("Two", HInstance, SND_ASYNC | SND_RESOURCE);
             //sndPlaySound("snd/alien.wav",SND_ASYNC);
             moveBallHorizontal = -moveBallHorizontal;


            // ball fasten
              if (ball->Top > player1->Top + player1->Height/3 - ball->Height/2 &&
            ball->Top < player1->Top + 2*player1->Height/3 - ball->Height/2)
            {
            PlaySound("One", HInstance, SND_ASYNC | SND_RESOURCE);
            //sndPlaySound("snd/accelerateball.wav",SND_ASYNC);
            moveBallHorizontal += 1.5;
            }
         }
   }

  //predator loses
    if  (ball->Left + ball->Width > player2->Left + player2->Width &&
        (ball->Top + ball->Height / 2 < player2->Top ||
        ball->Top + ball->Height / 2 > player2->Top + player2->Height))
         {
         PlaySound("Seven", HInstance, SND_ASYNC | SND_RESOURCE);
        //sndPlaySound("snd/ugly.wav",SND_ASYNC);
        TimerBall->Enabled = false;
        ball->Visible = false;
        player1points ++;
        Label1->Visible = true;
        Label1->Caption = "< Alien wins!";
        Label2Score->Visible = true;
        Label2Score->Caption = IntToStr(player1points) + ":" + IntToStr(player2points);
        Label3Pickups->Visible = true;
        Label3Pickups->Caption = "Number of pickups: " + IntToStr(pickups);
        nextRound->Visible = true;
        newGame->Visible = true;
         }
// predator pickup
else if (ball->Top + ball->Height/2 >= player2->Top  &&
ball->Top + ball->Height/2 <= player2->Top + player2->Height &&
ball->Left + ball->Width >= player2->Left )
{

if (moveBallHorizontal > 0)
   {
   pickups++;
   PlaySound("Four", HInstance, SND_ASYNC | SND_RESOURCE);
    //sndPlaySound("snd/predator.wav",SND_ASYNC);
    moveBallHorizontal = - moveBallHorizontal;


   if (ball->Top > player2->Top + player2->Height/3 - ball->Height/2 &&
            ball->Top < player2->Top + 2*player2->Height/3 - ball->Height/2)
        {
        PlaySound("One", HInstance, SND_ASYNC | SND_RESOURCE);
            //sndPlaySound("snd/accelerateball.wav",SND_ASYNC);
            moveBallHorizontal -= 1.5;
        }
   }
}
//shrink alien and predator
 if (pickups == 8)
    {
        Form1->player1->Picture->Bitmap -> Handle = LoadBitmap(HInstance, "ID_zmniejszgracz1");
        //LoadFromFile("img/zmniejszgracz1.bmp");

        Form1->player2->Picture->Bitmap -> Handle = LoadBitmap(HInstance, "ID_zmniejszgracz2");
        //LoadFromFile("img/zmniejszgracz2.bmp");
        player2->Left = table->Width - 20 - player2->Width;


    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::newGameClick(TObject *Sender)
{
Form1->player1->Picture->Bitmap -> Handle = LoadBitmap(HInstance, "ID_alien1");
Form1->player2->Picture-> Bitmap -> Handle = LoadBitmap(HInstance, "ID_predator2");
//LoadFromFile("img/predator2.bmp");
moveBallHorizontal = -11;
moveBallVertical = -8;
pickups = 0;
TimerBall->Enabled = true;
ball->Visible = true;
Label1->Visible = false;
Label2Score->Visible = false;
Label3Pickups->Visible = false;
newGame->Visible = false;
nextRound->Visible = false;

player1->Left = table->Left + 20;
player2->Left = table->Width - 20 - player2->Width;
ball->Left = table->Width/2;
ball->Top = table->Height/2;
player1->Top = table->Height/2 - player1->Height/2;
player2->Top = table->Height/2 - player2->Height/2;
player1points =0;
player2points = 0;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::nextRoundClick(TObject *Sender)
{
Form1->player1->Picture->Bitmap -> Handle = LoadBitmap(HInstance, "ID_alien1");
Form1->player2->Picture-> Bitmap -> Handle = LoadBitmap(HInstance, "ID_predator2");
//Form1->player1->Picture->LoadFromFile("img/alien1.bmp");
//Form1->player2->Picture->LoadFromFile("img/predator2.bmp");
moveBallHorizontal = -11;
moveBallVertical = -8;
pickups = 0;
TimerBall->Enabled = true;
ball->Visible = true;
Label1->Visible = false;
Label2Score->Visible = false;
Label3Pickups->Visible = false;
newGame->Visible = false;
nextRound->Visible = false;

player1->Left = table->Left + 20;
player2->Left = table->Width - 20 - player2->Width;
ball->Left = table->Width/2;
ball->Top = table->Height/2;
player1->Top = table->Height/2 - player1->Height/2;
player2->Top = table->Height/2 - player2->Height/2;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
 ShowMessage(" Welcome!\n\n The battle to conquer Earth begins.\n Alien moves using A and Z.\n Predator moves using up and down arrows.\n Pickup in the middle of Alien or Predator to fasten Earth ball.\n After 8 pickups both Alien and Predator shrink.\n\n Click ok to begin hunting.");
}
//---------------------------------------------------------------------------

