object FormDMS: TFormDMS
  Left = 0
  Top = 0
  Caption = 'DMS'
  ClientHeight = 278
  ClientWidth = 383
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label2: TLabel
    Left = 8
    Top = 15
    Width = 262
    Height = 16
    Caption = 'Verificar se existem evento novos (n'#227'o lidos):'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Button1: TButton
    Left = 288
    Top = 8
    Width = 89
    Height = 33
    Caption = 'Consultar'
    TabOrder = 0
    OnClick = Button1Click
  end
  object GroupBox1: TGroupBox
    Left = 0
    Top = 47
    Width = 377
    Height = 226
    Caption = 'Socket Client'
    TabOrder = 1
    object memoResposta: TMemo
      Left = 2
      Top = 15
      Width = 373
      Height = 209
      Align = alClient
      TabOrder = 0
      ExplicitLeft = 16
      ExplicitTop = 22
      ExplicitWidth = 345
      ExplicitHeight = 156
    end
  end
end
