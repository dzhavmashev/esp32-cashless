// Function : FUN_4012c33c
// Address  : 0x4012c33c
// Size     : 87 bytes


undefined4 FUN_4012c33c(int *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = *param_1;
  if (*(int *)(iVar3 + 0x20) < 0) {
    uVar4 = 1;
    for (uVar2 = *(uint *)(iVar3 + 0x1c) / *(uint *)(iVar3 + 0x18) + 1; uVar2 != 0;
        uVar2 = uVar2 >> 1) {
      uVar4 = uVar4 + 1 & 0xff;
    }
    iVar3 = param_1[3];
    param_1[3] = iVar3 + 1;
    if ((int)uVar4 < iVar3 + 1) {
      memw();
      return 0;
    }
  }
  param_1[0x35] = 4;
  param_1[0x34] = 0x16;
  *(undefined1 *)param_1[0x33] = 0;
  memw();
  memw();
  uVar1 = FUN_4012a534();
  return uVar1;
}

