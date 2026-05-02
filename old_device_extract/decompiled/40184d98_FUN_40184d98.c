// Function : FUN_40184d98
// Address  : 0x40184d98
// Size     : 93 bytes


int FUN_40184d98(int *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar2 = *param_1;
  memw();
  memw();
  if ((*(uint *)(iVar2 + 0x44) & 4) != 0) {
    uVar4 = 3;
    memw();
    if ((*(uint *)(iVar2 + 0x20) >> 4 & 3) == 1) goto LAB_40184dc5;
  }
  memw();
  uVar4 = *(uint *)(iVar2 + 0x20) >> 4 & 3;
LAB_40184dc5:
  uVar1 = 0;
  memw();
  if ((*(uint *)(iVar2 + 0x20) & 2) != 0) {
    memw();
    uVar1 = *(uint *)(iVar2 + 0x20) & 1 | 2;
  }
  iVar3 = 2;
  if (uVar4 < 2) {
    iVar3 = 1;
  }
  return (*(uint *)(iVar2 + 0x20) >> 2 & 3) + 6 + (uint)(uVar1 != 0) + iVar3;
}

