// Function : FUN_400ec104
// Address  : 0x400ec104
// Size     : 159 bytes


int FUN_400ec104(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  int iStack_38;
  uint uStack_34;
  uint uStack_30;
  int iStack_2c;
  uint uStack_28;
  uint auStack_24 [9];
  
  uVar2 = *(uint *)(param_1 + 0xc);
  if (param_2 < uVar2) {
    if ((*(uint *)(param_1 + 8) <= uVar2) || (*(uint *)(param_1 + 0x14) == 0)) goto LAB_400ec154;
    iStack_38 = *(int *)(param_1 + 4) + uVar2;
    uStack_34 = *(uint *)(param_1 + 8) - *(int *)(param_1 + 0x10);
    if (0x59f < uStack_34) {
      uStack_34 = 0x5a0;
    }
    uStack_30 = param_2;
    if (*(int *)(param_1 + 0x20) == 0) goto LAB_400ec134;
  }
  else {
    if ((param_2 <= *(uint *)(param_1 + 0x14)) && (*(uint *)(param_1 + 0x10) <= param_2))
    goto LAB_400ec154;
    *(uint *)(param_1 + 0x10) = param_2;
    iStack_2c = *(int *)(param_1 + 4) + uVar2;
    uStack_28 = *(int *)(param_1 + 8) - param_2;
    if (0x59f < uStack_28) {
      uStack_28 = 0x5a0;
    }
    auStack_24[0] = param_2;
    if (*(int *)(param_1 + 0x20) != 0) {
      iVar1 = (**(code **)(param_1 + 0x24))(param_1 + 0x18,&iStack_2c,&uStack_28,auStack_24);
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x10) + -1 + iVar1;
      goto LAB_400ec154;
    }
LAB_400ec134:
    FUN_40170584();
  }
  iVar1 = (**(code **)(param_1 + 0x24))(param_1 + 0x18,&iStack_38,&uStack_34,&uStack_30);
  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0xc);
  *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0xc) + -1 + iVar1;
LAB_400ec154:
  return (1 - param_2) + *(int *)(param_1 + 0x14);
}

