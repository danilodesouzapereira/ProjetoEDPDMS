object FormDMSCOM: TFormDMSCOM
  Left = 0
  Top = 0
  Caption = 'M'#243'dulo de comunica'#231#227'o'
  ClientHeight = 379
  ClientWidth = 276
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
    Top = 19
    Width = 139
    Height = 16
    Caption = 'Adicionar novo processo'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Button1: TButton
    Left = 168
    Top = 15
    Width = 105
    Height = 28
    Caption = 'Adicionar'
    TabOrder = 0
    OnClick = Button1Click
  end
  object GroupBox1: TGroupBox
    Left = 0
    Top = 224
    Width = 273
    Height = 153
    Caption = 'Socket Server'
    TabOrder = 1
    object Memo1: TMemo
      Left = 2
      Top = 15
      Width = 269
      Height = 136
      Align = alClient
      TabOrder = 0
      ExplicitLeft = 16
      ExplicitTop = 24
      ExplicitWidth = 289
      ExplicitHeight = 73
    end
  end
  object GroupBox2: TGroupBox
    Left = 0
    Top = 56
    Width = 273
    Height = 162
    Caption = 'Fila de processos'
    TabOrder = 2
    object Memo2: TMemo
      Left = 2
      Top = 15
      Width = 269
      Height = 145
      Align = alClient
      TabOrder = 0
      ExplicitLeft = 8
      ExplicitTop = 47
      ExplicitWidth = 289
      ExplicitHeight = 73
    end
  end
end
