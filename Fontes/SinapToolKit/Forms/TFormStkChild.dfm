object FormStkChild: TFormStkChild
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
    Images = ImageList
    Left = 88
    Top = 40
    object ActionImportaRedeGIS: TAction
      Caption = 'Importar Rede do GIS'
      Hint = 'Importar redes a partir dos dados do GIS'
      ImageIndex = 0
      Visible = False
      OnExecute = ActionImportaRedeGISExecute
    end
    object ActionGateway: TAction
      Caption = 'Acessar SINAP/Gateway'
      Enabled = False
      ImageIndex = 9
      Visible = False
      OnExecute = ActionGatewayExecute
    end
    object ActionCalcIndCont: TAction
      Caption = #205'ndices de Continuidade'
      ImageIndex = 10
      OnExecute = ActionCalcIndContExecute
    end
    object ActionOcorrencias: TAction
      Caption = 'Ocorr'#234'ncias'
      Hint = 'Gerenciamento de ocorr'#234'ncias de interrup'#231#227'o.'
      ImageIndex = 3
      OnExecute = ActionOcorrenciasExecute
    end
    object ActionEnumeracao: TAction
      Caption = 'Enumera Religadores'
      Hint = 
        'Executa enumera'#231#227'o de alternativas para a aloca'#231#227'o de religadore' +
        's.'
      ImageIndex = 5
      OnExecute = ActionEnumeracaoExecute
    end
    object ActionAlocaChaves: TAction
      Caption = 'Aloca Religadores'
      Hint = 'Executa aloca'#231#227'o otimizada de religadores.'
      ImageIndex = 6
      OnExecute = ActionAlocaChavesExecute
    end
    object ActionImportaAccess: TAction
      Caption = 'Importa Rede Access'
      Visible = False
      OnExecute = ActionImportaAccessExecute
    end
  end
  object ImageList: TImageList
    Left = 24
    Top = 42
    Bitmap = {
      494C01010B003800380110001000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000400000003000000001002000000000000030
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FAFAFA05F7F7F708F7F7F708F7F7
      F708F7F7F708F7F7F708F7F7F708F7F7F708F7F7F708F7F7F708F7F7F708F7F7
      F708F7F7F708F7F7F708F7F7F708FAFAFA050000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000575757A8474747B8474747B84747
      47B8474747B8474747B8474747B8474747B8474747B8474747B8474747B84747
      47B8474747B8474747B8474747B8585858A70000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000C0C0C0000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000040404FB5C5C5CA38383837C8181
      817E8181817E8181817E8181817E8181817E8181817E8181817E8181817E8383
      837C8383837C8383837C5C5C5CA3040404FB0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000FFFF000000
      00000000000000FFFF0000000000000000000000000000FFFF00000000000000
      000000FFFF000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000090909F6B8B8B847FFFFFF00FEFE
      FE01FEFEFE01FEFEFE01FEFEFE01FEFEFE01FEFEFE01FFFFFF00FEFEFE01CFCF
      CF30CECECE31FFFFFF00B8B8B847090909F60000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000000000000000FF
      FF0000FFFF0000FFFF000000000000FFFF000000000000FFFF0000FFFF0000FF
      FF000000000000000000000000000000000000000000FFFFFF00808080008080
      8000808080008080800080808000808080008080800080808000808080008080
      800080808000808080008080800000000000090909F6B8B8B847F3F3F30C7171
      718E515151AE535353AC535353AC535353AC585858A7D2D2D22DCACACA352222
      22DD2C2C2CD3D9D9D926B9B9B946090909F60000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000000000000000FF
      FF0000FFFF0000FFFF0000000000FFFFFF000000000000FFFF0000FFFF0000FF
      FF000000000000000000000000000000000000000000FFFFFF000000FF00C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C0008080800000000000090909F6B8B8B847F6F6F6098A8A
      8A757070708F7272728D7272728D7272728D76767689DADADA25DFDFDF209F9F
      9F604B4B4BB496969669BABABA45090909F60000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000FFFF0000FF
      FF0000FFFF0000000000FFFFFF0080808000FFFFFF000000000000FFFF0000FF
      FF0000FFFF0000000000000000000000000000000000FFFFFF00C0C0C000C0C0
      C000000000000000000000000000000000000000000000000000000000000000
      0000C0C0C000C0C0C0008080800000000000090909F6B7B7B748FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00DCDC
      DC23C2C2C23DF1F1F10EB8B8B847090909F60000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000FFFF0000FF
      FF0000000000FFFFFF0000FFFF008080800000FFFF00FFFFFF000000000000FF
      FF0000FFFF0000000000000000000000000000000000FFFFFF00C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C0008080800000000000090909F6B8B8B847F5F5F50A8080
      807F6363639C6565659A6565659A6565659A6A6A6A95D7D7D728CFCFCF302A2A
      2AD5363636C9E2E2E21DB9B9B946090909F60000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000FFFF0000FFFF0000FFFF0000FF
      FF000000000000FFFF00FFFFFF0080808000FFFFFF0000FFFF000000000000FF
      FF0000FFFF0000FFFF0000FFFF000000000000000000FFFFFF00C0C0C000C0C0
      C000000000000000000000000000000000000000000000000000000000000000
      0000C0C0C000C0C0C0008080800000000000090909F6B8B8B847F5F5F50A7C7C
      7C835F5F5FA06060609F6060609F6060609F6565659AD5D5D52ADADADA258D8D
      8D72404040BF97979768BABABA45090909F60000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000FFFF0000FF
      FF0000000000FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF000000000000FF
      FF0000FFFF0000000000000000000000000000000000FFFFFF00C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C0008080800000000000090909F6B7B7B748FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00E4E4
      E41BC2C2C23DEAEAEA15B8B8B847090909F60000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000FFFF0000FF
      FF0000FFFF0000000000FFFFFF0000FFFF00FFFFFF000000000000FFFF0000FF
      FF0000FFFF0000000000000000000000000000000000FFFFFF00C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C0008080800000000000090909F6B8B8B847F7F7F7088E8E
      8E717575758A7777778877777788767676897B7B7B84DCDCDC23D4D4D42B3232
      32CD404040BFE8E8E817B9B9B946090909F60000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000000000000000FF
      FF0000FFFF0000FFFF0000000000000000000000000000FFFF0000FFFF0000FF
      FF000000000000000000000000000000000000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF0000000000090909F6B8B8B847F3F3F30C6D6D
      6D924D4D4DB24F4F4FB04F4F4FB04E4E4EB1545454ABD1D1D12ED5D5D52A7A7A
      7A85343434CB97979768BABABA45090909F60000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000000000000000FF
      FF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000090909F6B8B8B847FFFFFF00FEFE
      FE01FDFDFD02FDFDFD02FDFDFD02FDFDFD02FDFDFD02FFFFFF00FFFFFF00FFFF
      FF00DBDBDB24E5E5E51AB9B9B946090909F60000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000FFFF000000
      00000000000000FFFF0000FFFF0000FFFF0000FFFF0000FFFF00000000000000
      000000FFFF000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000040404FB5F5F5FA0888888778686
      86798686867986868679868686798686867986868679868686798585857A8585
      857A88888877898989765F5F5FA0040404FB0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000FFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000535353AC444444BB444444BB4444
      44BB444444BB444444BB444444BB444444BB444444BB444444BB444444BB4444
      44BB444444BB444444BB444444BB555555AA0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000FFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000F8F8F807F4F4F40BF5F5F50AF5F5
      F50AF5F5F50AF5F5F50AF5F5F50AF5F5F50AF5F5F50AF5F5F50AF5F5F50AF5F5
      F50AF5F5F50AF5F5F50AF5F5F50AF9F9F9060000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000808080000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000808080000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000080808000000000008080
      8000808080008080800000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000C0C0C00080808000000000008080
      8000000000000000000000000000000000000000000000000000000000008080
      8000000000008080800000000000000000000000000000000000000000000000
      0000000000008080800000000000000000000000000080808000000000000000
      000000000000000000000000000000000000000000000000000000000000C0C0
      C00000000000C0C0C00000000000C0C0C0000000FF000000FF000000FF00C0C0
      C000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000808080008080
      8000000000000000000000000000000000000000000000000000000000000000
      0000808080000000000000000000000000000000000000000000000000000000
      0000000000000000FF000000FF000000000000FFFF0000FFFF00000000000000
      000000000000000000000000000000000000000000000000000000000000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C00000000000000000000000000000000000FFFF0000000000000000000000FF
      FF00FFFFFF0000FFFF00FFFFFF0000FFFF000000000000000000000000000000
      000000000000000000000000000000000000C0C0C000C0C0C000808080000000
      0000000000008080800000000000000000000000000000000000000000008080
      8000000000000000000080808000808080000000000000000000000000000000
      00000000FF000000FF000000FF000000000000FFFF0000FFFF0000FFFF000000
      000000000000000000000000000000000000000000000000000000000000C0C0
      C00000000000C0C0C00000000000C0C0C00000000000C0C0C00000000000C0C0
      C00000000000000000000000000000000000FFFF00000000000000FFFF00FFFF
      FF0000FFFF00FFFFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000008080800000000000000000000000
      0000808080000000000000000000000000000000000000000000000000000000
      0000000000008080800080808000000000000000000000000000000000000000
      FF000000FF000000FF000000FF000000000000FFFF0000FFFF0000FFFF0000FF
      FF0000000000000000000000000000000000000000000000000000000000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C00000000000000000000000000000000000FFFF000000000000FFFFFF0000FF
      FF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000000000000000000000
      0000000000000000000000000000000000008080800000000000000000008080
      8000000000008080800000000000000000000000000000000000000000000000
      000000000000C0C0C000000000008080800000000000808080000000FF000000
      FF000000FF000000FF000000FF000000000000FFFF0000FFFF0000FFFF0000FF
      FF0000FFFF00808080000000000000000000000000000000000000000000C0C0
      C00000000000C0C0C00000000000C0C0C00000000000C0C0C00000000000C0C0
      C00000000000000000000000000000000000FFFF00000000000000FFFF00FFFF
      FF0000FFFF00FFFFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000008080
      800080808000C0C0C00000000000C0C0C00000000000000000000000FF000000
      FF000000FF000000FF000000FF000000000000FFFF0000FFFF0000FFFF0000FF
      FF0000FFFF00000000000000000000000000000000000000000000000000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C00000000000000000000000000000000000FFFF000000000000FFFFFF0000FF
      FF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FF
      FF0000000000000000000000FF000000FF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000C0C0C000000000008080800000000000000000000000FF000000
      FF000000FF000000FF000000FF00000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000C0C0
      C00000000000C0C0C00000000000C0C0C00000000000C0C0C00000000000C0C0
      C00000000000000000000000000000000000FFFF00000000000000FFFF00FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000FF000000FF000000000080808000000000000000
      0000808080000000000000000000808080000000000080808000000000000000
      00000000000080808000C0C0C0000000000000000000000000000000FF000000
      FF000000FF000000FF000000000000FF000000000000FF000000FF000000FF00
      0000FF000000000000000000000000000000000000000000000000000000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C0000000000000000000000000000000000000000000000000000000000000FF
      FF00FFFFFF0000FFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000008080800000000000000000000000
      0000808080000000000000000000000000008080800000000000000000008080
      8000000000000000000080808000C0C0C00000000000808080000000FF000000
      FF000000FF000000000000FF000000FF000000FF000000000000FF000000FF00
      0000FF000000808080000000000000000000000000000000000000000000C0C0
      C00000000000000000000000000000000000000000000000000000000000C0C0
      C000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000808080008080
      8000808080008080800080808000000000000000000080808000000000000000
      0000808080000000000000000000000000000000000000000000000000000000
      FF000000000000FF000000FF000000FF000000FF000000FF000000000000FF00
      000000000000000000000000000000000000000000000000000000000000C0C0
      C000000000000000000000000000FFFF000000000000FFFF000000000000C0C0
      C000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000080808000808080000000
      0000000000000000000080808000808080000000000000000000000000008080
      8000000000008080800000000000000000000000000000000000000000000000
      000000FF000000FF000000FF000000FF000000FF000000FF000000FF00000000
      000000000000000000000000000000000000000000000000000000000000C0C0
      C00000000000000000000000000000000000000000000000000000000000C0C0
      C000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000C0C0C000000000008080
      8000808080008080800000000000808080000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000FF000000FF000000FF000000FF000000FF0000000000000000
      000000000000000000000000000000000000000000000000000000000000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000080808000C0C0C00000000000C0C0
      C000000000008080800000000000808080008080800080808000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000008080800000000000000000000000000080808000000000000000
      000000000000000000000000000000000000000000000000000000000000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000C0C0C000000000008080
      8000C0C0C0008080800000000000808080000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000808080000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000808080000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000080808000C0C0C0000000
      0000000000000000000080808000808080000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000241CEDFF241CEDFF241CEDFF241C
      EDFF241CEDFF241CEDFF241CEDFF241CEDFF241CEDFF241CEDFF241CEDFF241C
      EDFF241CEDFF241CEDFF241CEDFF241CEDFF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000241CEDFF241CEDFF241CEDFF241C
      EDFF241CEDFF241CEDFF241CEDFF241CEDFF241CEDFF241CEDFF241CEDFF241C
      EDFF241CEDFF241CEDFF241CEDFF241CEDFF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF0000000000241CEDFF241CEDFF241CEDFF241C
      EDFF241CEDFF241CEDFF241CEDFF241CEDFF241CEDFF241CEDFF241CEDFF241C
      EDFF241CEDFF241CEDFF241CEDFF241CEDFF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FFFFFF00FFFFFF008080
      8000FFFFFF00FFFFFF0080808000FFFFFF00FFFFFF0080808000FFFFFF00FFFF
      FF0080808000FFFFFF00FFFFFF00000000000000000000000000000000000000
      0000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF0000000000241CEDFF241CEDFF241CEDFF7671
      F4FFC8C6FAFFC8C6FAFFC8C6FAFFC8C6FAFFC8C6FAFFC8C6FAFFC8C6FAFFBAB8
      F9FF7671F4FF241CEDFF241CEDFF241CEDFF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000FF00FFFFFF008080
      80000000FF00FFFFFF00808080000000FF00FFFFFF0080808000FFFFFF00FFFF
      FF0080808000FFFFFF00FFFFFF00000000000000000000000000000000000000
      0000000000000000000000000000FFFFFF000000000000000000FFFFFF000000
      00000000000000000000FFFFFF0000000000241CEDFF322AEEFFD6D4FCFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFADAAF8FF241CEDFF241CEDFF00000000FFFFFF00808080008080
      8000808080008080800080808000808080008080800080808000808080008080
      8000808080008080800080808000000000000000000080808000808080008080
      8000808080008080800080808000808080008080800080808000808080008080
      8000808080008080800080808000000000000000000000000000000000000000
      0000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF0000000000241CEDFF9F9BF7FFFFFFFFFFD6D4
      FCFF5B55F2FF241CEDFF241CEDFF241CEDFF241CEDFF241CEDFF241CEDFF6963
      F3FFF1F1FEFFFFFFFFFF8480F5FF241CEDFF00000000FFFFFF000000FF00C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000808080000000000000000000FFFFFF00FFFFFF008080
      8000FFFFFF00FFFFFF0080808000FFFFFF00FFFFFF0080808000FFFFFF00FFFF
      FF0080808000FFFFFF00FFFFFF00000000000000000000000000000000000000
      FF00000000000000000000000000FFFFFF0000000000BFBFBF00000000000000
      0000FFFFFF0000000000FFFFFF0000000000241CEDFFFFFFFFFFFFFFFFFF3F38
      EFFF241CEDFF241CEDFF241CEDFF241CEDFF241CEDFF241CEDFF241CEDFF241C
      EDFF5B55F2FFFFFFFFFFD6D4FCFF241CEDFF00000000FFFFFF00C0C0C000C0C0
      C000000000000000000000000000000000000000000000000000000000000000
      0000C0C0C000C0C0C0008080800000000000000000000000FF00FFFFFF008080
      80000000FF00FFFFFF00808080000000FF00FFFFFF00808080000000FF00FFFF
      FF00808080000000FF00FFFFFF00000000000000000000000000000000000000
      FF000000FF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF0000000000241CEDFFFFFFFFFFC8C6FAFF241C
      EDFF241CEDFF241CEDFF241CEDFF241CEDFF241CEDFF241CEDFF241CEDFF241C
      EDFF241CEDFFFFFFFFFFFFFFFFFF241CEDFF00000000FFFFFF00C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C00080808000000000000000000080808000808080008080
      8000808080008080800080808000808080008080800080808000808080008080
      800080808000808080008080800000000000000000000000FF000000FF000000
      FF000000FF000000FF0000000000FFFFFF000000000000000000FFFFFF000000
      000000000000000000000000000000000000241CEDFFFFFFFFFFF1F1FEFF241C
      EDFF241CEDFF241CEDFF241CEDFF241CEDFF241CEDFF241CEDFF241CEDFF241C
      EDFF3F38EFFFFFFFFFFFF1F1FEFF241CEDFF00000000FFFFFF00C0C0C000C0C0
      C000000000000000000000000000000000000000000000000000000000000000
      0000C0C0C000C0C0C000808080000000000000000000FFFFFF00FFFFFF008080
      8000FFFFFF00FFFFFF0080808000FFFFFF00FFFFFF0080808000FFFFFF00FFFF
      FF0080808000FFFFFF00FFFFFF0000000000000000000000FF000000FF000000
      FF000000FF000000FF000000FF0000000000FFFFFF00FFFFFF00FFFFFF000000
      0000FFFFFF00FFFFFF000000000000000000241CEDFFC8C6FAFFFFFFFFFFADAA
      F8FF241CEDFF241CEDFF241CEDFF241CEDFF241CEDFF241CEDFF241CEDFF322A
      EEFFBAB8F9FFFFFFFFFFADAAF8FF241CEDFF00000000FFFFFF00C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C0008080800000000000000000000000FF00FFFFFF008080
      80000000FF00FFFFFF00808080000000FF00FFFFFF00808080000000FF00FFFF
      FF00808080000000FF00FFFFFF0000000000000000000000FF000000FF000000
      FF000000FF000000FF000000FF000000FF0000000000BFBFBF00FFFFFF000000
      0000FFFFFF00000000000000000000000000241CEDFF4D47F0FFF1F1FEFFFFFF
      FFFFE4E3FDFFC8C6FAFFC8C6FAFFC8C6FAFFC8C6FAFFC8C6FAFFC8C6FAFFF1F1
      FEFFFFFFFFFFF1F1FEFF322AEEFF241CEDFF00000000FFFFFF00C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C00080808000000000000000000080808000808080008080
      8000808080008080800080808000808080008080800080808000808080008080
      800080808000808080008080800000000000000000000000FF000000FF000000
      FF000000FF000000FF000000FF0000000000FFFFFF00FFFFFF00FFFFFF000000
      000000000000000000000000000000000000241CEDFF241CEDFF4D47F0FFC8C6
      FAFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFBAB8F9FF3F38EFFF241CEDFF241CEDFF00000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF000000000000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF0080808000FFFFFF00FFFFFF0080808000FFFFFF00FFFF
      FF0080808000FFFFFF00FFFFFF0000000000000000000000FF000000FF000000
      FF000000FF000000FF0000000000000000000000000000000000000000000000
      000000000000000000000000000000000000241CEDFF241CEDFF241CEDFF241C
      EDFF241CEDFF241CEDFF241CEDFF241CEDFF241CEDFF241CEDFF241CEDFF241C
      EDFF241CEDFF241CEDFF241CEDFF241CEDFF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00808080000000FF00FFFFFF00808080000000FF00FFFF
      FF00808080000000FF00FFFFFF00000000000000000000000000000000000000
      FF000000FF000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000241CEDFF241CEDFF241CEDFF241C
      EDFF241CEDFF241CEDFF241CEDFF241CEDFF241CEDFF241CEDFF241CEDFF241C
      EDFF241CEDFF241CEDFF241CEDFF241CEDFF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      FF00000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000241CEDFF241CEDFF241CEDFF241C
      EDFF241CEDFF241CEDFF241CEDFF241CEDFF241CEDFF241CEDFF241CEDFF241C
      EDFF241CEDFF241CEDFF241CEDFF241CEDFF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FF000000FF000000FF000000FF00
      0000FF000000FF000000C0C0C000C0C0C000C0C0C000C0C0C000FF000000FF00
      0000FF000000FF000000FF000000FF0000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000241CEDFF241CEDFF241CEDFF241C
      EDFF241CEDFF241CEDFF241CEDFF241CEDFF241CEDFF241CEDFF241CEDFF241C
      EDFF241CEDFF241CEDFF241CEDFF241CEDFF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FF000000FF000000FF000000FF00
      0000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF00
      0000FF000000FF000000FF000000FF000000424D3E000000000000003E000000
      2800000040000000300000000100010000000000800100000000000000000000
      000000000000000000000000FFFFFF00FEFFFFFF00000000FC7FFFFF00000000
      FC7FFFFF00000000D837000000000000E00F000000000000E00F000000000000
      C007000000000000C0070000000000000001000000000000C007000000000000
      C007000000000000E00F000000000000E00F000000000000D837FFFF00000000
      FEFFFFFF00000000FEFFFFFF00000000C007FFFF81FEFFFFC007FFF801E2F83F
      C00720F807E01010C007007F03E0E00FC007007C03F0C007C007003C23C08003
      C007000F3FC08003C0070004E3C08003C007000C22308003C00701FF00208003
      C007E3FC0020C007C007FFFC0062E00FC007FFFF001E3018C007FFF8001FF83F
      C007FFF8001FFFFFC007FFFF007FFFFFFFFF0000FFFFFFFFFC000000FFFF0000
      FC000000FFFF0000FC00000000000000FC00000000000000EC00000000000000
      E400000000000000E00000000000000000000000000000000001000000000000
      00030000000000000007000000000000000F000000000000E3FF0000FFFF0000
      E7FF0000FFFF0000EFFF0000FFFF000000000000000000000000000000000000
      000000000000}
  end
  object ActionListEnerq: TActionList
    Left = 160
    Top = 41
    object ActionSimuladorServer: TAction
      Caption = 'Simulador: Server'
      OnExecute = ActionSimuladorServerExecute
    end
    object ActionSimuladorClient: TAction
      Caption = 'Simulador: Client'
      OnExecute = ActionSimuladorClientExecute
    end
  end
  object ActionList1: TActionList
    Left = 24
    Top = 104
    object ActionRedeCarregada: TAction
      OnExecute = ActionRedeCarregadaExecute
    end
  end
end