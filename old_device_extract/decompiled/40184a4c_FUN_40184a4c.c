// Function : FUN_40184a4c
// Address  : 0x40184a4c
// Size     : 88 bytes


int FUN_40184a4c(int param_1,uint param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint auStack_24 [9];
  
  iVar1 = -1;
  if (param_2 < 0x7e) {
    iVar1 = (param_2 >> 4) * 4;
    iVar3 = param_1 + iVar1;
    auStack_24[0] =
         (3 << 0x20 - ((param_2 & 0xf) * -2 + 0x20) ^ 0xffffffffU) & *(uint *)(iVar3 + 0x18) |
         param_3 << 0x20 - ((param_2 & 0xf) * -2 + 0x20);
    piVar2 = *(int **)(param_1 + 0x50);
    *(uint *)(iVar3 + 0x18) = auStack_24[0];
    memw();
    iVar1 = (**(code **)(*piVar2 + 0x14))(piVar2,*(int *)(param_1 + 8) + 0x20 + iVar1,auStack_24,4);
    if (iVar1 != 0) {
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
  }
  memw();
  return iVar1;
}

