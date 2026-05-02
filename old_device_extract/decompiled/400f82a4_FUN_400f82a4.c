// Function : FUN_400f82a4
// Address  : 0x400f82a4
// Size     : 154 bytes


undefined4 FUN_400f82a4(int param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int local_60 [6];
  int aiStack_48 [9];
  int iStack_24;
  
  if ((param_1 == 0) || (param_2 == (int *)0x0)) {
    return 0x102;
  }
  if (*(int *)(param_1 + 4) != 0) {
    return 0x106;
  }
  if (0xf < *(int *)(param_1 + 8) - 0x10U) {
    return 0x106;
  }
  uVar1 = FUN_400f7fd0();
  iVar2 = FUN_400f7e98(local_60);
  if ((iVar2 == 0) || (uVar1 == 0)) {
LAB_400f82e5:
    uVar5 = 0x105;
  }
  else {
    uVar3 = *(int *)(param_1 + 8) - 0x10;
    if (uVar3 == (local_60[0] - 1U) % uVar1) {
      iVar4 = FUN_400f8354(local_60);
      iVar2 = 0;
      if (aiStack_48[1] != iVar4) goto LAB_400f82fc;
    }
    else {
LAB_400f82fc:
      if ((uVar3 != (aiStack_48[2] - 1U) % uVar1) ||
         (iVar2 = FUN_400f8354(aiStack_48 + 2), iStack_24 != iVar2)) goto LAB_400f82e5;
      iVar2 = 1;
    }
    uVar5 = 0;
    *param_2 = aiStack_48[iVar2 * 8];
    memw();
  }
  return uVar5;
}

