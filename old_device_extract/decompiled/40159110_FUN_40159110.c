// Function : FUN_40159110
// Address  : 0x40159110
// Size     : 119 bytes


undefined4 FUN_40159110(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  byte bVar3;
  byte *pbVar4;
  
  pbVar4 = *(byte **)(*(int *)(param_1 + 4) + 4);
  bVar3 = *pbVar4 & 0xf0;
  if (bVar3 != 0xc0) {
    if (bVar3 == 0xd0) {
      bVar3 = pbVar4[0x18];
      if (8 < bVar3) {
        return 0;
      }
      if ((1 << (bVar3 & 0x1f) & 399U) == 0) {
        return 0;
      }
    }
    else if (bVar3 != 0xa0) {
      return 0;
    }
  }
  iVar1 = FUN_4015aa74(0);
  if (iVar1 != 0xffff) {
    if ((byte)(DAT_3ffc89f6 - 0xdU) < 2) {
      uVar2 = FUN_40147e18(0,param_1);
      return uVar2;
    }
    if (DAT_3ffc89f6 == '\t') {
      uVar2 = FUN_40147cc4(0,param_1);
      return uVar2;
    }
  }
  return 0;
}

