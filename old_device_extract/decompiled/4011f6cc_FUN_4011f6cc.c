// Function : FUN_4011f6cc
// Address  : 0x4011f6cc
// Size     : 72 bytes


int FUN_4011f6cc(uint param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  undefined1 in_PRID;
  
  if ((param_1 < 0x20) && ((byte)"I (%d) %s: Reserved data length:%d\n"[param_1 + 0x21] < 4)) {
    uVar4 = rsr(in_PRID);
    iVar5 = (uVar4 >> 0xd & 1) + param_1 * 2;
    iVar2 = iVar5 * 8;
    piVar3 = (int *)(iVar2 + 0x3ffbe128);
    iVar1 = *piVar3;
    if (param_2 == 0) {
      *piVar3 = 0x40085830;
      *(int *)(iVar2 + 0x3ffbe12c) = iVar5;
      memw();
    }
    else {
      *piVar3 = param_2;
      *(undefined4 *)(iVar2 + 0x3ffbe12c) = param_3;
    }
    if (iVar1 != 0x40085830) {
      return iVar1;
    }
    memw();
  }
  return 0;
}

