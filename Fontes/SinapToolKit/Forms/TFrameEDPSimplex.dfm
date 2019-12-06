object FrameEDPSimplex: TFrameEDPSimplex
  Left = 0
  Top = 0
  Width = 320
  Height = 240
  TabOrder = 0
  object ActionList: TActionList
    Images = ImageList1
    Left = 48
    Top = 32
    object ActionMedicoes: TAction
      Caption = 'Simplex - Medi'#231#245'es'
      ImageIndex = 1
      OnExecute = ActionMedicoesExecute
    end
    object ActionManutencaoInsp: TAction
      Caption = 'Simplex/Manuten'#231#227'o - Inspe'#231#245'es'
      Hint = 'Realiza a prioriza'#231#227'o de inspe'#231#245'es.'
      ImageIndex = 4
      OnExecute = ActionManutencaoInspExecute
    end
    object ActionManutencaoObras: TAction
      Caption = 'Simplex/Manuten'#231#227'o - Obras'
      Hint = 'Realiza a prioriza'#231#227'o de obras de manuten'#231#227'o.'
      ImageIndex = 0
      OnExecute = ActionManutencaoObrasExecute
    end
    object ActionManutencaoObrasPre: TAction
      Caption = 'Simplex/Manuten'#231#227'o - Pr'#233'-Processamento'
      Hint = 
        'Realiza pr'#233'-processamentos para execu'#231#227'o do m'#243'dulo de prioriza'#231#227 +
        'o de obras.'
      ImageIndex = 0
      OnExecute = ActionManutencaoObrasPreExecute
    end
    object ActionManutencaoObrasAuto: TAction
      Caption = 'Simplex/Manuten'#231#227'o - Obras Auto'
      ImageIndex = 0
      OnExecute = ActionManutencaoObrasAutoExecute
    end
    object ActionExpansao: TAction
      Caption = 'Simplex/Expans'#227'o'
      ImageIndex = 2
      OnExecute = ActionExpansaoExecute
    end
    object ActionAjuda: TAction
      Caption = 'Simplex - Ajuda'
      ImageIndex = 5
      OnExecute = ActionAjudaExecute
    end
  end
  object ImageList1: TImageList
    Left = 120
    Top = 32
    Bitmap = {
      494C010106000800E40010001000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000400000002000000001002000000000000020
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000840000008400000000000000000000000000000000000000000000000000
      000000000000F6F3EF108D6738CF73440AFF73440AFF8D6738CFF6F3EF100000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000008400
      0000C6C6C6008400000084000000000000000000000000000000000000000000
      000073440AFFA75B04FFC66800FFC66800FFC56700FFC56600FFA65904FF7344
      0AFF000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000084000000C6C6
      C600840000008400000084000000000000000000000000000000A78A669FA85C
      04FFC76A00FFC76900FFC66900FFC66800FFC66800FFC56700FFC56600FFC466
      00FFA65904FFA78A669F00000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000084000000C6C6C6008400
      0000840000008400000000000000000000000000000000000000A85D04FFC86B
      00FFC76A00FFC76A00FFC76900FFC66900FFC66800FFC66800FFC56700FFC566
      00FFC46600FFA65904FF00000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000084000000C6C6C600840000008400
      0000840000000000000000000000000000000000000073440AFFC96C00FFC86C
      00FFC86B00FFC86B00FFC76A00FFFFFFFFFFC66900FFC66800FFC66800FFC567
      00FFC56600FFC46600FF73440AFF000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000C6C6C600C6C6C600C6C6C600FFFFFF008484840084000000840000008400
      000000000000000000000000000000000000F6F3EF10A95E04FFC96D00FFC96C
      00FFC86C00FFC86B00FFB76302FF884E08FFA85B04FFC66900FFC66800FFC668
      00FFC56700FFC56600FFA65904FFF6F3EF100000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000084848400C6C6
      C600C6C6C600C6C6C600C6C6C600C6C6C600FFFFFF0084848400000000000000
      0000000000000000000000000000000000008D6738CFCA6E00FFC96D00FFC96D
      00FFC96C00FFC86C00FFC86B00FFFFFFFFFFA25904FFC76900FFC66900FFC668
      00FFC66800FFC56700FFC56600FF8D6738CF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000C6C6C600C6C6
      C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6C600FFFFFF00000000000000
      00000000000000000000000000000000000073440AFFCA6E00FFCA6E00FFC96D
      00FFC96D00FFC96C00FFC86C00FFD3C5B2FF8D6738FFC76A00FFC76900FFC669
      00FFC66800FFC66800FFC56700FF73440AFF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000C6C6C600C6C6C600C6C6
      C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6C6000000
      00000000000000000000000000000000000073440AFFCB6F00FFCA6E00FFCA6E
      00FFC96D00FFC96D00FFC96C00FFC86C00FFF6F3F0FFFFFFFFFFC76A00FFC769
      00FFC66900FFC66800FFC66800FF73440AFF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000C6C6C600C6C6C600C6C6
      C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6C6000000
      0000000000000000000000000000000000008D6738CFCB7000FFCB6F00FFCA6E
      00FFCA6E00FFC96D00FFC96D00FFC96C00FF8E5107FFFFFFFFFFB26103FFC76A
      00FFC76900FFC66900FFC66800FF8D6738CF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000C6C6C600FFFFFF00FFFF
      0000C6C6C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6C6000000
      000000000000000000000000000000000000F6F3EF10AB6004FFCB7000FFCB6F
      00FFCA6E00FFCA6E00FF784709FFC96D00FF935306FFFFFFFFFF9E5805FFC86B
      00FFC76A00FFC76900FFA75B04FFF6F3EF100000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000C6C6C600FFFFFF00FFFF
      0000C6C6C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6C6000000
      0000000000000000000000000000000000000000000073440AFFCB7000FFCB70
      00FFCB6F00FFCA6E00FFFFFFFFFFEEE8E0FFFFFFFFFFFFFFFFFFC86C00FFC86B
      00FFC76A00FFC76A00FF73440AFF000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFF0000FFFF0000C6C6C600C6C6C600C6C6C600C6C6C600000000000000
      0000000000000000000000000000000000000000000000000000AB6004FFCC70
      00FFCB7000FFCB6F00FFCA6E00FF9F5905FF9E5905FFC96D00FFC96C00FFC86C
      00FFC86B00FFA85C04FF00000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000084848400FFFF
      FF00FFFFFF00FFFFFF00C6C6C600C6C6C600C6C6C60084848400000000000000
      0000000000000000000000000000000000000000000000000000A78A669FAB60
      04FFCB7000FFCB7000FFCB6F00FFCA6E00FFCA6E00FFC96D00FFC96D00FFC96C
      00FFA85D04FFA78A669F00000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000C6C6C600C6C6C600C6C6C600C6C6C6000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000073440AFFAB6004FFCB7000FFCB6F00FFCA6E00FFCA6E00FFA95E04FF7344
      0AFF000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000F6F3EF108D6738CF73440AFF73440AFF8D6738CFF6F3EF100000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000C0C0C0000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000C0C0C00080808000C0C0C00000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFAFAFA05F7F7F708F7F7F708F7F7
      F708F7F7F708F7F7F708F7F7F708F7F7F708F7F7F708F7F7F708F7F7F708F7F7
      F708F7F7F708F7F7F708F7F7F708FAFAFA050000000080808000808000008080
      800000000000000000000000000000000000000000000000000000000000C0C0
      C000C0C0C000C0C0C0008080800000000000FDFDFDFFFDFDFDFFFDFDFDFFFDFD
      FDFFFDFDFDFFFDFDFDFFFDFDFDFFFDFDFDFFFDFDFDFFFDFDFDFFFDFDFDFFFDFD
      FDFFFDFDFDFFFDFDFDFFFDFDFDFFFEFDFDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF575757A8474747B8474747B84747
      47B8474747B8474747B8474747B8474747B8474747B8474747B8474747B84747
      47B8474747B8474747B8474747B8585858A7C0C0C00080808000808080008080
      0000808080000000000000000000000000000000000000000000C0C0C000C0C0
      C000C0C0C000C0C0C0008080800000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFEFEFFFEFEFDFFFEFEFDFFFEFE
      FDFFFEFEFDFFFEFEFDFFFEFEFDFFFEFEFDFFFEFEFDFFFEFEFDFFFEFEFDFFFEFE
      FDFFFEFEFDFFFEFEFDFFFEFDFDFFFEFEFEFF040404FB5C5C5CA38383837C8181
      817E8181817E8181817E8181817E8181817E8181817E8181817E8181817E8383
      837C8383837C8383837C5C5C5CA3040404FB0000000080808000808080008080
      800080800000808080000000000000000000000000000000000080808000C0C0
      C000C0C0C000808080000000000000000000CAC3BFFFB8AFABFFBBB1ADFFBBB1
      ADFFBBB1ADFFBBB1ADFFBAB0ACFFB9AFABFFB9AFABFFBAB1ACFFBBB1ADFFBBB1
      ADFFBBB1ADFFBBB2ADFFB8AEAAFFCBC3C0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF090909F6B8B8B847FFFFFF00FEFE
      FE01FEFEFE01FEFEFE01FEFEFE01FEFEFE01FEFEFE01FFFFFF00FEFEFE01CFCF
      CF30CECECE31FFFFFF00B8B8B847090909F60000000000000000808080008080
      8000808000008000000080808000000000000000000080808000C0C0C000C0C0
      C00080808000000000000000000000000000A29590FFE6E2E1FFE4E0DFFFE1DD
      DCFFE3DFDDFFE1DDDBFFE7E4E2FFEBE9E8FFEAE8E6FFE3DFDEFFE2DEDCFFE3DF
      DEFFE3DFDDFFE3E0DEFFE2DEDCFFEAE8E6FFE7E3E2FFE0DCDAFFDCD8D6FFE1DD
      DBFFDFDBD9FFDFDBD9FFDDD9D7FFE0DCDAFFE0DCDBFFDDD8D6FFE0DCDBFFE0DC
      DAFFDEDAD8FFDFDBDAFFDDD8D7FFE2DEDDFF090909F6B8B8B847F3F3F30C7171
      718E515151AE535353AC535353AC535353AC585858A7D2D2D22DCACACA352222
      22DD2C2C2CD3D9D9D926B9B9B946090909F60000000000000000000000008080
      800080808000808000008000000080808000C0C0C000C0C0C000C0C0C0008080
      8000000000000000000000000000000000009B8C87FFD0C9C6FFFFFFFFFFFFFF
      FFFFFEFEFEFFFFFFFFFFF3F2F1FFB3A9A4FFC4BCB9FFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF988A84FF8F8079FFB1A7A2FF9082
      7DFF9D908AFF9D908AFFA99E99FF978983FF958780FFB1A7A2FF958680FF998B
      85FFA79B96FF9F928CFFA29691FFD0CAC7FF090909F6B8B8B847F6F6F6098A8A
      8A757070708F7272728D7272728D7272728D76767689DADADA25DFDFDF209F9F
      9F604B4B4BB496969669BABABA45090909F60000000000000000000000000000
      00008080800080808000808000008000000080808000C0C0C000808080000000
      000000000000000000000000000000000000A79A95FFB9AFABFFA89B96FFDFDA
      D8FFFDFDFDFFBFB6B3FF9F918BFFD7D2CFFFBDB4B0FFA49791FFF2F0EFFFFFFF
      FFFFFCFCFCFFFDFDFDFFFDFDFDFFFEFEFEFFADA29DFFB2A6A2FFF2F0EFFFACA5
      A1FFC7BFBDFFC9C1BDFFE0DCDAFFBBB2AEFFB8AFABFFF4F2F1FFB9AEABFFBEB6
      B2FFDED9D7FFCDC7C4FFD2CCCAFFFFFFFFFF090909F6B7B7B748FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00DCDC
      DC23C2C2C23DF1F1F10EB8B8B847090909F60000000000000000000000000000
      0000000000008080800080808000808000000000000080808000000000000000
      000000000000000000000000000000000000A49691FFD6D1CEFFDFDBD9FFAFA4
      9FFF9F928CFFC1B8B5FFFAF9F9FFFFFFFFFFFFFFFFFFD8D2CFFF9B8D87FFDDD8
      D6FFFFFFFFFFFEFDFDFFFFFFFFFFFFFFFFFFAA9E99FFAFA29EFFEDE9E8FFADA5
      A1FFC6BEBBFFC5BDB9FFDDD8D6FFB9AFAAFFB4ABA7FFEAE6E5FFB6ABA7FFBDB4
      B1FFD5CFCDFFC6BEBBFFD1CBC8FFFFFFFFFF090909F6B8B8B847F5F5F50A8080
      807F6363639C6565659A6565659A6565659A6A6A6A95D7D7D728CFCFCF302A2A
      2AD5363636C9E2E2E21DB9B9B946090909F60000000000000000000000000000
      0000000000008080800080808000C0C0C000C0C0C00080808000000000000000
      000000000000808080008080800000000000A1938EFFC1B8B4FFF4F3F2FFFFFF
      FFFFF6F4F4FFFFFFFFFFFFFFFFFFFEFEFEFFFCFBFBFFFFFFFFFFEFEDECFFA093
      8EFFC9C2BEFFE9E6E4FFE4E0DEFFFFFFFFFFABA09BFFA79A95FFDCD6D4FFA59B
      96FFC6BEBBFFC6BEBBFFDFDAD8FFB9B0ABFFB5ABA8FFEBE8E7FFB7ACA8FFBEB5
      B2FFD5CFCDFFC6BEBBFFD3CDCAFFFFFFFFFF090909F6B8B8B847F5F5F50A7C7C
      7C835F5F5FA06060609F6060609F6060609F6565659AD5D5D52ADADADA258D8D
      8D72404040BF97979768BABABA45090909F60000000000000000000000008080
      800080808000C0C0C000C0C0C00080808000C0C0C000C0C0C000808080000000
      0000000000008080800080800000808080009A8C86FFDCD7D5FFFFFFFFFFFDFD
      FDFFFFFEFEFFFFFFFFFFE6E2E1FFF6F4F4FFFFFFFFFFFCFCFCFFFEFEFEFFFDFC
      FCFFBBB1ADFF887770FFB6ACA7FFFFFFFFFFABA09BFFCEC7C4FFA49792FFC0B7
      B3FFDAD4D2FFC2B9B6FFDFDAD9FFB9B0ABFFB5ABA8FFEBE8E7FFB7ACA8FFBEB5
      B1FFDED9D7FFCDC7C4FFD2CCC9FFFFFFFFFF090909F6B7B7B748FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00E4E4
      E41BC2C2C23DEAEAEA15B8B8B847090909F60000000080808000C0C0C000C0C0
      C000C0C0C000C0C0C0008080800000000000C0C0C000C0C0C000C0C0C000C0C0
      C000808080000000000080808000C0C0C000A39690FFA0938DFFB4AAA5FFF7F6
      F6FFFFFFFFFFC8C0BCFF9C8E88FFA69994FFD3CCC9FFFFFFFFFFFEFDFDFFFFFF
      FFFFCBC4C0FF84736CFFB7ADA9FFFFFFFFFFA59994FFFDFDFDFFFEFEFEFFFFFF
      FFFFDCD6D4FFC0B8B4FFDED9D7FFBAB0ACFFB5ABA7FFEBE8E7FFB7ABA8FFC0B7
      B4FFB2A6A2FFA89C97FFD6D0CEFFFFFFFFFF090909F6B8B8B847F7F7F7088E8E
      8E717575758A7777778877777788767676897B7B7B84DCDCDC23D4D4D42B3232
      32CD404040BFE8E8E817B9B9B946090909F6C0C0C000C0C0C000808080008080
      8000C0C0C000C0C0C000000000000000000000000000C0C0C000808080008080
      800000000000808080000000000000000000AB9F9AFFFBFBFBFFCCC5C2FFA497
      92FFAEA29DFFADA29DFFFEFEFEFFF0EEEDFFB0A5A0FFA79B96FFE5E2E0FFFFFF
      FFFFFAFAFAFFFDFDFDFFFFFFFFFFFFFFFFFFA59994FFFCFCFCFFFDFDFDFFFFFF
      FFFFDBD5D3FFC3BAB6FFE1DCDBFFB9AEAAFFB6ABA8FFEDE9E8FFAFA29EFFF0EE
      EEFFC6BEBBFFCAC2BFFFFAF9F9FFFFFFFFFF090909F6B8B8B847F3F3F30C6D6D
      6D924D4D4DB24F4F4FB04F4F4FB04E4E4EB1545454ABD1D1D12ED5D5D52A7A7A
      7A85343434CB97979768BABABA45090909F68080800080808000000000000000
      000080808000C0C0C000C0C0C000000000000000000000000000808080000000
      000080808000C0C0C00000000000000000009C8D88FFAC9F9AFFF6F5F4FFEBE8
      E7FFC7BFBCFFFEFEFEFFFFFFFFFFFEFEFEFFFFFFFFFFE0DBD9FFA49892FFB5AB
      A7FFF6F5F5FFF2F0EFFFEEECEBFFFFFFFFFFA69A95FFFDFDFDFFFEFEFEFFFFFF
      FFFFE1DCDAFF9E908BFFA89D97FFC3BAB7FFB4AAA6FFECE9E8FFACA09BFFFBFB
      FBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF090909F6B8B8B847FFFFFF00FEFE
      FE01FDFDFD02FDFDFD02FDFDFD02FDFDFD02FDFDFD02FFFFFF00FFFFFF00FFFF
      FF00DBDBDB24E5E5E51AB9B9B946090909F60000000000000000000000008080
      8000C0C0C000C0C0C000808080000000000000000000C0C0C000000000008080
      800080808000000000000000000000000000A99D98FFECE9E8FFFDFDFCFFFFFF
      FFFFFFFFFFFFFEFEFEFFFFFFFFFFFEFEFEFFFDFDFDFFFFFFFFFFFEFEFEFFCCC5
      C2FFAB9F9AFF968B86FFB1A9A5FFFFFFFFFFA69A95FFFDFDFDFFFFFFFFFFFFFF
      FFFFFEFEFEFFE2DDDCFFDCD8D6FFF7F5F5FFAEA39EFFF7F5F4FFAEA29DFFFAFA
      F9FFFEFEFEFFFDFDFCFFFFFFFFFFFFFFFFFF040404FB5F5F5FA0888888778686
      86798686867986868679868686798686867986868679868686798585857A8585
      857A88888877898989765F5F5FA0040404FB000000000000000080808000C0C0
      C000C0C0C000C0C0C0000000000000000000C0C0C00080808000808080008080
      8000000000000000000000000000000000009F918CFFD1CAC8FFF8F7F7FFFFFF
      FFFFFDFDFCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFEFEFFFDFCFCFFFFFF
      FFFFC9C3BFFF675650FFA09591FFFFFFFFFFA39691FFFDFDFDFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFDFDFDFFA39690FFCCC5C2FFA39590FFFDFD
      FDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF535353AC444444BB444444BB4444
      44BB444444BB444444BB444444BB444444BB444444BB444444BB444444BB4444
      44BB444444BB444444BB444444BB555555AA0000000000000000000000008080
      8000000000000000000000000000808080008080800080808000C0C0C0000000
      000000000000000000000000000000000000BCB2AEFFBCB2AEFFF2F0EFFFFFFF
      FFFFFEFEFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFEFEFFFFFF
      FFFFE9E7E6FFE1DEDDFFEFEDEDFFFFFFFFFFB7ADA9FFFEFEFEFFFFFFFFFFFFFF
      FFFFFFFFFFFFFEFEFDFFFDFCFCFFFFFFFFFFD4CECBFFAFA39FFFD1CBC8FFFFFF
      FFFFFEFEFEFFFFFFFFFFFFFFFFFFFFFFFFFFF8F8F807F4F4F40BF5F5F50AF5F5
      F50AF5F5F50AF5F5F50AF5F5F50AF5F5F50AF5F5F50AF5F5F50AF5F5F50AF5F5
      F50AF5F5F50AF5F5F50AF5F5F50AF9F9F906424D3E000000000000003E000000
      2800000040000000200000000100010000000000000100000000000000000000
      000000000000000000000000FFFFFF00FFF3F81F00000000FFE1F00F00000000
      FFC1C00300000000FF83C00300000000F007800100000000C00F000000000000
      801F000000000000801F000000000000000F000000000000000F000000000000
      000F000000000000000F800100000000801FC00300000000801FC00300000000
      C03FF00F00000000F0FFF81F00000000DFF10000000000008FE1000000000000
      07C100000000000083C3000000000000C187000000000000E00F000000000000
      F01F000000000000F83F000000000000F839000000000000E018000000000000
      8100000000000000038300000000000031C3000000000000E187000000000000
      C30F000000000000EE1F00000000000000000000000000000000000000000000
      000000000000}
  end
end
