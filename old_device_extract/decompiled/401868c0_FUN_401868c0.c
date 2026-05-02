// Function : FUN_401868c0
// Address  : 0x401868c0
// Size     : 62 bytes


void FUN_401868c0(int param_1,uint param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar3 = (int)*(short *)(param_1 + 8);
  param_2 = param_2 & 0xff;
  if (iVar3 != 0) {
    iVar4 = 4;
    uVar1 = *(ushort *)(param_1 + 0xe);
    iVar2 = param_2 * 4;
    while (param_2 = param_2 + 1, (int)param_2 < (int)(uint)uVar1) {
      iVar5 = iVar4 + iVar2;
      iVar6 = *(int *)(*(int *)(param_1 + 0x18) + iVar5);
      if (iVar6 != 0) {
        iVar3 = iVar3 + -1;
        *(int *)(*(int *)(param_1 + 0x18) + iVar4) = iVar6;
        *(undefined4 *)(*(int *)(param_1 + 0x18) + iVar5) = 0;
        if (iVar3 == 0) break;
      }
      iVar4 = iVar4 + 4;
    }
  }
  memw();
  return;
}

