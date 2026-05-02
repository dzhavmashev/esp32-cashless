// Function : FUN_4016e460
// Address  : 0x4016e460
// Size     : 263 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4016e460(short param_1,char param_2)

{
  byte bVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  byte bVar7;
  int iStack_28;
  
  if (param_2 == '\0') {
    sVar2 = (short)(param_1 * 9 >> 2);
  }
  else {
    sVar2 = (short)(param_1 * 0x1b >> 3);
  }
  iStack_28 = (int)sVar2;
  iVar4 = (int)_DAT_3ffc7e8c;
  if (iStack_28 != iVar4) {
    bVar1 = 0x55;
    bVar7 = 0;
    if (DAT_3ffc7e91 != '\0') {
      bVar1 = 0xe;
    }
    uVar5 = 1;
    do {
      uVar6 = uVar5;
      if ((DAT_3ffc7e91 != '\0') && (uVar6 = 0xfd, bVar7 < 0xd)) {
        uVar6 = (uint)(byte)(bVar7 * '\x0f' + 0x25);
      }
      uVar3 = (*(code *)&SUB_40084594)(&DAT_3ff4e0c4);
      _DAT_3ff4e0c4 = uVar3 & 0xffffff00 | uVar6;
      bVar7 = bVar7 + 1;
      memw();
      uVar6 = (*(code *)&SUB_40084594)(0x3ff4e0c0);
      _DAT_3ff4e148 = (uVar6 & 0xffffff) + (iStack_28 - iVar4) | uVar6 & 0xff000000;
      memw();
      _DAT_3ff4e0c4 = (*(code *)&SUB_40084594)(&DAT_3ff4e0c4);
      _DAT_3ff4e0c4 = _DAT_3ff4e0c4 | 0x200;
      memw();
      _DAT_3ff4e0c4 = (*(code *)&SUB_40084594)(&DAT_3ff4e0c4);
      _DAT_3ff4e0c4 = _DAT_3ff4e0c4 & 0xfffffdff;
      uVar5 = uVar5 + 3 & 0xff;
      memw();
    } while (bVar1 != bVar7);
    memw();
    _DAT_3ffc7e8c = sVar2;
  }
  return;
}

