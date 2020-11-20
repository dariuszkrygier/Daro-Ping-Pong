//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TImage *player1;
        TImage *player2;
        TTimer *Player1Up;
        TTimer *Player1Down;
        TTimer *Player2Up;
        TTimer *Player2Down;
        TImage *table;
        TImage *ball;
        TTimer *TimerBall;
        TLabel *Label1;
        TButton *newGame;
        TButton *nextRound;
        TLabel *Label2Score;
        TLabel *Label3Pickups;
        void __fastcall Player1UpTimer(TObject *Sender);
        void __fastcall Player1DownTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall Player2UpTimer(TObject *Sender);
        void __fastcall Player2DownTimer(TObject *Sender);
        void __fastcall TimerBallTimer(TObject *Sender);
        void __fastcall newGameClick(TObject *Sender);
        void __fastcall nextRoundClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
