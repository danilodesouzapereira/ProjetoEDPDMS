object FormDMSCOM: TFormDMSCOM
  Left = 0
  Top = 0
  Caption = 'Comunica'#231#227'o DMS'
  ClientHeight = 299
  ClientWidth = 340
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 96
    Top = 16
    Width = 145
    Height = 33
    Caption = 'Conectar'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 96
    Top = 131
    Width = 145
    Height = 33
    Caption = 'Enviar texto'
    TabOrder = 1
    OnClick = Button2Click
  end
  object edtMsg: TEdit
    Left = 32
    Top = 104
    Width = 273
    Height = 21
    TabOrder = 2
    Text = 'edtMsg'
  end
  object Memo1: TMemo
    Left = 32
    Top = 208
    Width = 273
    Height = 73
    Lines.Strings = (
      'Memo1')
    TabOrder = 3
  end
  object ClientSocket1: TClientSocket
    Active = False
    ClientType = ctNonBlocking
    Port = 2000
    OnRead = ClientSocket1Read
    OnError = ClientSocket1Error
    Left = 16
    Top = 8
  end
end
