// Function : FUN_4016f7a8
// Address  : 0x4016f7a8
// Size     : 194 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_4016f7a8(char param_1,undefined1 param_2,short param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  if ((_DAT_3ffca4c8 & 0x10) == 0) {
    uVar1 = (**(code **)(_DAT_3ffc7e64 + 0xf4))((int)param_1,param_2,(int)param_3);
    return uVar1;
  }
  iVar5 = (int)param_1;
  if ((iVar5 == 0) || (0xe < iVar5)) {
    FUN_40168620(0x3ffc3a88);
    uVar3 = 0xc;
    uVar4 = 0xc;
    uVar1 = 0x96c;
  }
  else if (iVar5 == 0xe) {
    uVar3 = 0x54;
    uVar1 = 0x9b4;
    uVar4 = 0x54;
  }
  else {
    uVar1 = (iVar5 + -1) * 5 & 0xffff;
    uVar3 = uVar1 + 0xc;
    uVar4 = uVar3 & 0xffff;
    uVar1 = uVar1 + 0x96c & 0xffff;
    uVar3 = uVar3 & 0xff;
  }
  uVar2 = (*(code *)&SUB_40084594)(0x3ff5d008);
  if ((uVar2 & 0x20000000) == 0) {
    FUN_4016f5f8(uVar3,(int)param_3,param_2);
    return uVar1;
  }
  do {
    iVar5 = (*(code *)&SUB_40084594)(0x3ff4e168);
  } while (iVar5 < 0);
  FUN_4016f3ec(uVar3);
  uVar3 = (*(code *)&SUB_40084594)(&DAT_3ff4e0c4);
  memw();
  _DAT_3ff4e0c4 = (uVar4 & 0x7f) << 1 | uVar3 & 0xffffff00;
  return uVar1;
}

