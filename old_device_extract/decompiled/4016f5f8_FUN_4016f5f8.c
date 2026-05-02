// Function : FUN_4016f5f8
// Address  : 0x4016f5f8
// Size     : 417 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4016f5f8(uint param_1,short param_2,undefined1 param_3)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  char cVar4;
  char cVar5;
  undefined1 auStack_40 [16];
  uint uStack_30;
  uint uStack_2c;
  undefined4 uStack_28;
  
  DAT_3ffc7e8f = 1;
  memw();
  uVar2 = (*(code *)&SUB_40084594)(&DAT_3ff4e0c4);
  uStack_30 = uVar2 >> 0x10 & 0xf;
  uVar2 = (*(code *)&SUB_40084594)(&DAT_3ff4e0c4);
  uStack_2c = uVar2 >> 0x14 & 0xf;
  (*(code *)&SUB_400899d0)();
  _DAT_3ff4e0c4 = (*(code *)&SUB_40084594)(&DAT_3ff4e0c4);
  _DAT_3ff4e0c4 = _DAT_3ff4e0c4 & 0xfffffeff;
  memw();
  uStack_28 = 0xfffffeff;
  uVar2 = (*(code *)&SUB_40084594)(&DAT_3ff4e0c4);
  _DAT_3ff4e0c4 = uVar2 & 0xe7ffffff | 0x10000000;
  memw();
  _DAT_3ff4e0c4 = (*(code *)&SUB_40084594)(&DAT_3ff4e0c4);
  _DAT_3ff4e0c4 = _DAT_3ff4e0c4 & 0xfff0ffff;
  memw();
  _DAT_3ff4e0c4 = (*(code *)&SUB_40084594)(&DAT_3ff4e0c4);
  _DAT_3ff4e0c4 = _DAT_3ff4e0c4 & 0xff0fffff;
  memw();
  FUN_4016e460((int)param_2,param_3);
  FUN_4016f3ec(param_1 & 0xff);
  uVar2 = (*(code *)&SUB_40084594)(&DAT_3ff4e0c4);
  _DAT_3ff4e0c4 = (param_1 & 0x7f) << 1 | uVar2 & 0xffffff00;
  memw();
  cVar4 = '\f';
  cVar5 = '\0';
  do {
    _DAT_3ff4e0c4 = (*(code *)&SUB_40084594)(&DAT_3ff4e0c4);
    _DAT_3ff4e0c4 = _DAT_3ff4e0c4 | 0x100;
    memw();
    (*(code *)&SUB_40008534)(2);
    do {
      iVar3 = (*(code *)&SUB_40084594)(&DAT_3ff4e0c4);
      if (iVar3 < 0) break;
      uVar2 = (*(code *)&SUB_40084594)(&DAT_3ff4e0c4);
    } while ((uVar2 & 0x100) != 0);
    _DAT_3ff4e0c4 = (*(code *)&SUB_40084594)(&DAT_3ff4e0c4);
    _DAT_3ff4e0c4 = _DAT_3ff4e0c4 & 0xfffffeff;
    memw();
    (*(code *)&SUB_40008534)(0x28);
    cVar1 = (*(code *)&SUB_400898e8)(param_1 & 0xff,auStack_40,1);
    if ((((cVar1 == '\0') || ((cVar1 == '\x01' && (cVar5 == -1)))) ||
        ((cVar1 == -1 && (cVar5 == '\x01')))) || (cVar4 = cVar4 + -1, cVar5 = cVar1, cVar4 == '\0'))
    {
      DAT_3ffc7e8f = 0;
      memw();
      uVar2 = (*(code *)&SUB_40084594)(&DAT_3ff4e0c4);
      _DAT_3ff4e0c4 = uVar2 & 0xfff0ffff | uStack_30 << 0x10;
      memw();
      uVar2 = (*(code *)&SUB_40084594)(&DAT_3ff4e0c4);
      _DAT_3ff4e0c4 = uVar2 & 0xff0fffff | uStack_2c << 0x14;
      memw();
      _DAT_3ff4e0c4 = (*(code *)&SUB_40084594)(&DAT_3ff4e0c4);
      _DAT_3ff4e0c4 = _DAT_3ff4e0c4 & 0xe7ffffff;
      memw();
      (*(code *)&SUB_40089b34)();
      return;
    }
  } while( true );
}

