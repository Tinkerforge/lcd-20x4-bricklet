program ExampleHelloWorld;

{$ifdef MSWINDOWS}{$apptype CONSOLE}{$endif}
{$ifdef FPC}{$mode OBJFPC}{$H+}{$endif}

uses
  SysUtils, IPConnection, BrickletLCD20x4;

type
  TExample = class
  private
    ipcon: TIPConnection;
    lcd: TBrickletLCD20x4;
  public
    procedure Execute;
  end;

const
  HOST = 'localhost';
  PORT = 4223;
  UID = '9qL'; { Change to your UID }

var
  e: TExample;

procedure TExample.Execute;
begin
  { Create IP connection to brickd }
  ipcon := TIPConnection.Create(HOST, PORT);

  { Create device object }
  lcd := TBrickletLCD20x4.Create(UID);

  { Add device to IP connection }
  ipcon.AddDevice(lcd);
  { Don't use device before it is added to a connection }

  { Turn backlight on }
  lcd.BacklightOn;

  { Write "Hello World" }
  lcd.WriteLine(0, 0, 'Hello World');

  WriteLn('Press key to exit');
  ReadLn;
  ipcon.Destroy;
end;

begin
  e := TExample.Create;
  e.Execute;
  e.Destroy;
end.