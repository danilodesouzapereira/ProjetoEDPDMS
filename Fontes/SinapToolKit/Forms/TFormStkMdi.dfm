object FormStkMdi: TFormStkMdi
  Left = 0
  Top = 0
  Align = alRight
  BorderIcons = []
  BorderStyle = bsSizeToolWin
  Caption = 'Sinap Tool Kit: EDP'
  ClientHeight = 266
  ClientWidth = 384
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  Position = poDesigned
  PixelsPerInch = 96
  TextHeight = 13
  object ActionList: TActionList
    Left = 16
    Top = 8
    object ActionImportaOracle: TAction
      Caption = 'Importar Rede do Oracle/EO'
      OnExecute = ActionImportaOracleExecute
    end
  end
end
