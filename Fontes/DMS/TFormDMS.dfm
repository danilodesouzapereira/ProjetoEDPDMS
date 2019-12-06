object FormDMS: TFormDMS
  Left = 0
  Top = 0
  Caption = 'DMS'
  ClientHeight = 271
  ClientWidth = 364
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 136
    Top = 8
    Width = 113
    Height = 41
    Caption = 'Ativar'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Memo1: TMemo
    Left = 96
    Top = 72
    Width = 185
    Height = 169
    Lines.Strings = (
      'Memo1')
    TabOrder = 1
  end
  object ServerSocket1: TServerSocket
    Active = False
    Port = 2000
    ServerType = stNonBlocking
    OnClientConnect = ServerSocket1ClientConnect
    OnClientDisconnect = ServerSocket1ClientDisconnect
    OnClientRead = ServerSocket1ClientRead
    Left = 8
  end
end
