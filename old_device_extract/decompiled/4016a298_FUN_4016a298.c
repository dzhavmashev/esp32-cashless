// Function : FUN_4016a298
// Address  : 0x4016a298
// Size     : 343 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4016a298(undefined4 param_1,char param_2)

{
  short sVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  _DAT_3ff5d044 = (*(code *)&SUB_40084594)(&DAT_3ff5d044);
  _DAT_3ff5d044 = _DAT_3ff5d044 & 0xfffffffe;
  memw();
  _DAT_3ff5d050 = (*(code *)&SUB_40084594)(&DAT_3ff5d050);
  _DAT_3ff5d050 = _DAT_3ff5d050 | 1;
  memw();
  _DAT_3ff5c018 = (*(code *)&SUB_40084594)(&DAT_3ff5c018);
  _DAT_3ff5c018 = _DAT_3ff5c018 | 0x8000000;
  memw();
  _DAT_3ff5c018 = (*(code *)&SUB_40084594)(&DAT_3ff5c018);
  sVar1 = _DAT_3ffca57a;
  _DAT_3ff5c018 = _DAT_3ff5c018 & 0xf7ffffff;
  memw();
  uVar2 = (*(code *)&SUB_40084594)(0x3ff5c050);
  _DAT_3ffc7e76 = (uVar2 & 0x3ff) - 0x400;
  iVar5 = (int)_DAT_3ffc7e76;
  memw();
  iVar4 = (int)sVar1;
  if (0x3e < (ushort)((uVar2 & 0x3ff) - 0x26d)) goto LAB_4016a3de;
  iVar6 = -0x160;
  if (iVar5 < -0x15f) {
    iVar6 = (uint)(iVar5 < -0x188) * -0x188 + (uint)(iVar5 >= -0x188) * iVar5;
  }
  if (iVar4 < iVar6) {
    iVar6 = iVar4 * 3 + iVar6;
LAB_4016a371:
    iVar4 = iVar6 + -2;
    if (iVar6 + -2 < 0) {
      iVar4 = iVar6 + 1;
    }
    _DAT_3ffca57a = (short)(iVar4 >> 2);
    iVar4 = (int)_DAT_3ffca57a;
    memw();
  }
  else if (iVar6 < iVar4) {
    if (iVar4 + -0x10 <= iVar6) {
      iVar6 = iVar6 * 3 + iVar4;
      goto LAB_4016a371;
    }
    _DAT_3ffca57a = sVar1 + -0xc;
    iVar4 = (int)_DAT_3ffca57a;
    memw();
  }
  else {
    iVar4 = (int)_DAT_3ffca57a;
  }
  if (DAT_3ffc7e78 == '\0') {
    if ((iVar4 <= _DAT_3ffca516 + 4) && (_DAT_3ffca516 + -4 <= iVar4)) goto LAB_4016a3de;
LAB_4016a3c0:
    _DAT_3ffca516 = (short)iVar4;
    memw();
  }
  else {
    if (iVar4 < -0x17f) goto LAB_4016a3c0;
    _DAT_3ffca516 = (short)((iVar4 + -0x180) / 2);
    memw();
  }
  if (param_2 != '\0') {
    (**(code **)(_DAT_3ffc7e64 + 0x84))((int)_DAT_3ffca516);
  }
LAB_4016a3de:
  uVar3 = (*(code *)&SUB_40084594)(&DAT_3ff5d044);
  memw();
  _DAT_3ff5d044 = uVar3 | 1;
  return;
}

