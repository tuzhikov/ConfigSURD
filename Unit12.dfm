object FormConsole: TFormConsole
  Left = 536
  Top = 162
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = #1050#1086#1084#1072#1085#1076#1085#1072#1103' '#1082#1086#1085#1089#1086#1083#1100
  ClientHeight = 441
  ClientWidth = 614
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'MS Sans Serif'
  Font.Style = [fsBold]
  KeyPreview = True
  OldCreateOrder = False
  OnKeyDown = FormKeyDown
  PixelsPerInch = 96
  TextHeight = 20
  object Label1: TLabel
    Left = 152
    Top = 72
    Width = 252
    Height = 20
    Caption = #1057#1087#1080#1089#1086#1082' '#1085#1077#1082#1086#1090#1086#1088#1099#1093' '#1082#1086#1084#1072#1085#1076' '#1044#1050
  end
  object Label2: TLabel
    Left = 152
    Top = 16
    Width = 205
    Height = 20
    Caption = #1054#1090#1087#1088#1072#1074#1083#1103#1077#1084#1072#1103' '#1082#1086#1084#1072#1085#1076#1072
  end
  object edtCommand: TEdit
    Left = 152
    Top = 40
    Width = 457
    Height = 28
    TabOrder = 0
    Text = 'send485 6 010203040506'
  end
  object mmoOut: TMemo
    Left = 8
    Top = 136
    Width = 601
    Height = 297
    Lines.Strings = (
      '')
    ScrollBars = ssVertical
    TabOrder = 1
  end
  object btnSend: TButton
    Left = 8
    Top = 8
    Width = 137
    Height = 121
    Caption = #1055#1086#1089#1083#1072#1090#1100
    TabOrder = 2
    OnClick = btnSendClick
  end
  object cbbTemplateCmd: TComboBox
    Left = 152
    Top = 96
    Width = 457
    Height = 28
    Style = csDropDownList
    ItemHeight = 20
    TabOrder = 3
    OnChange = cbbTemplateCmdChange
    Items.Strings = (
      'help'
      'ifconfig'
      'get state'
      'get gps_time'
      'get ds1390_time'
      'get info'
      'get lineADC'
      'get linePWM'
      'get sensors')
  end
end
