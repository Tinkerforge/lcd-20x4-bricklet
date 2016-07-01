Imports System
Imports Tinkerforge

Module ExampleHelloWorld
    Const HOST As String = "localhost"
    Const PORT As Integer = 4223
    Const UID As String = "XYZ" ' Change XYZ to the UID of your LCD 20x4 Bricklet

    Sub Main()
        Dim ipcon As New IPConnection() ' Create IP connection
        Dim lcd As New BrickletLCD20x4(UID, ipcon) ' Create device object

        ipcon.Connect(HOST, PORT) ' Connect to brickd
        ' Don't use device before ipcon is connected

        ' Turn backlight on
        lcd.BacklightOn()

        ' Write "Hello World"
        lcd.WriteLine(0, 0, "Hello World")

        Console.WriteLine("Press key to exit")
        Console.ReadLine()
        ipcon.Disconnect()
    End Sub
End Module
