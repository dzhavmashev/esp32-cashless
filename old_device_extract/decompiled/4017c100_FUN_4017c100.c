// Function : FUN_4017c100
// Address  : 0x4017c100
// Size     : 139 bytes


undefined4 * FUN_4017c100(int param_1,uint param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if (*(int *)(param_1 + 0x24) == 0) {
    puVar1 = (undefined4 *)(*(code *)&SUB_40094d60)(0x10);
    *(undefined4 **)(param_1 + 0x24) = puVar1;
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)(*(code *)&SUB_40094c54)(&DAT_3f4260d0,0x66,0,"ity");
    }
    puVar1[1] = 0;
    puVar1[2] = 0;
    *puVar1 = 0;
    puVar1[3] = 0;
  }
  iVar3 = *(int *)(param_1 + 0x24);
  if (*(int *)(iVar3 + 0xc) == 0) {
    uVar2 = (*(code *)&SUB_40094db8)(param_1,4,0x21);
    *(undefined4 *)(iVar3 + 0xc) = uVar2;
    if (*(int *)(*(int *)(param_1 + 0x24) + 0xc) != 0) goto LAB_4017c134;
LAB_4017c159:
    puVar1 = (undefined4 *)0x0;
  }
  else {
LAB_4017c134:
    puVar4 = (undefined4 *)(*(int *)(*(int *)(param_1 + 0x24) + 0xc) + param_2 * 4);
    puVar1 = (undefined4 *)*puVar4;
    if (puVar1 == (undefined4 *)0x0) {
      iVar3 = 1 << 0x20 - (0x20 - (param_2 & 0x1f));
      puVar1 = (undefined4 *)(*(code *)&SUB_40094db8)(param_1,1,(iVar3 + 5) * 4);
      if (puVar1 == (undefined4 *)0x0) goto LAB_4017c159;
      puVar1[1] = param_2;
      puVar1[2] = iVar3;
    }
    else {
      *puVar4 = *puVar1;
    }
    puVar1[4] = 0;
    puVar1[3] = 0;
  }
  return puVar1;
}

