// Function : FUN_400fcf88
// Address  : 0x400fcf88
// Size     : 305 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400fcf88(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  iVar1 = (*(code *)&SUB_400081d4)(0);
  iVar2 = (*(code *)&SUB_400081d4)(1);
  if ((iVar1 - 0xbU < 3) || (iVar2 - 0xbU < 3)) {
    uVar3 = (*(code *)&SUB_40084594)(&DAT_3ff000c0);
    uVar3 = uVar3 ^ 0xffffffff;
    uVar5 = (*(code *)&SUB_40084594)(&DAT_3ff0001c);
    uVar5 = uVar5 ^ 0xffffffff;
    uVar4 = (*(code *)&SUB_40084594)(&DAT_3ff000cc);
    uVar4 = uVar4 ^ 0xffffffff;
  }
  else {
    uVar4 = 0x37c36;
    uVar5 = 0xf;
    uVar3 = 0x61a8c08;
  }
  iVar1 = FUN_401218e8(1);
  if (iVar1 == 0) {
    uVar3 = uVar3 & 0xfffffffd;
    uVar6 = 0xe513f0;
  }
  else {
    uVar3 = uVar3 & 0xffffffbd;
    uVar6 = 0xe513b0;
  }
  uVar3 = uVar3 | uVar6;
  iVar1 = FUN_401218e8(2);
  if (iVar1 != 0) {
    uVar3 = uVar3 & 0xfffeffff;
  }
  _DAT_3ff4f0ac = (*(code *)&SUB_40084594)(&DAT_3ff4f0ac);
  _DAT_3ff4f0ac = _DAT_3ff4f0ac | 0x200000;
  memw();
  memw();
  _DAT_3ff6d0ac = (*(code *)&SUB_40084594)(&DAT_3ff6d0ac);
  _DAT_3ff6d0ac = _DAT_3ff6d0ac | 0x200000;
  memw();
  memw();
  _DAT_3ff000c0 = (*(code *)&SUB_40084594)(&DAT_3ff000c0);
  _DAT_3ff000c0 = (uVar3 ^ 0xffffffff) & _DAT_3ff000c0;
  memw();
  memw();
  _DAT_3ff000c4 = (*(code *)&SUB_40084594)(&DAT_3ff000c4);
  _DAT_3ff000c4 = uVar3 | _DAT_3ff000c4;
  memw();
  memw();
  _DAT_3ff0001c = (*(code *)&SUB_40084594)(&DAT_3ff0001c);
  _DAT_3ff0001c = (uVar5 ^ 0xffffffff) & _DAT_3ff0001c;
  memw();
  memw();
  _DAT_3ff00020 = (*(code *)&SUB_40084594)(&DAT_3ff00020);
  _DAT_3ff00020 = uVar5 | _DAT_3ff00020;
  memw();
  memw();
  _DAT_3ff000cc = (*(code *)&SUB_40084594)(&DAT_3ff000cc);
  _DAT_3ff000cc = (uVar4 ^ 0xffffffff) & _DAT_3ff000cc;
  memw();
  memw();
  FUN_400f552c(0x18);
  return;
}

