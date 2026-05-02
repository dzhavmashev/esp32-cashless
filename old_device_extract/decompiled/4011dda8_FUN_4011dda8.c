// Function : FUN_4011dda8
// Address  : 0x4011dda8
// Size     : 109 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4011dda8(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iStack_3c;
  int iStack_38;
  uint uStack_34;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  
  (*(code *)&SUB_4008b530)(param_1,0,0x1c);
  iVar2 = _DAT_3ffc87d8;
  while (iVar2 != 0) {
    iVar1 = FUN_401855c4(iVar2,param_2);
    if (iVar1 != 0) {
      FUN_4018e3a8(*(undefined4 *)(iVar2 + 0x1c),&iStack_3c);
      *param_1 = *param_1 + iStack_3c;
      param_1[1] = param_1[1] + iStack_38;
      uVar3 = param_1[2];
      param_1[2] = (uVar3 < uStack_34) * uStack_34 + (uVar3 >= uStack_34) * uVar3;
      param_1[3] = param_1[3] + iStack_30;
      param_1[4] = param_1[4] + iStack_2c;
      param_1[5] = param_1[5] + iStack_28;
      param_1[6] = param_1[6] + iStack_24;
    }
    iVar2 = *(int *)(iVar2 + 0x20);
    memw();
  }
  return;
}

