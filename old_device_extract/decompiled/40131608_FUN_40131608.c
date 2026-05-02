// Function : FUN_40131608
// Address  : 0x40131608
// Size     : 114 bytes


undefined4 FUN_40131608(int param_1,uint param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  if (param_2 < 0x2711) {
    uVar4 = *(uint *)(param_1 + 4);
    if (*(uint *)(param_1 + 4) <= param_2) {
      uVar2 = FUN_40131574(param_1);
      return uVar2;
    }
    do {
      uVar1 = uVar4;
      uVar4 = uVar1 - 1;
      if (uVar4 == 0) break;
    } while (*(int *)(*(int *)(param_1 + 8) + uVar4 * 4) == 0);
    iVar5 = (param_2 < uVar1) * uVar1 + (param_2 >= uVar1) * param_2;
    iVar3 = FUN_4013ae30(iVar5,4);
    if (iVar3 != 0) {
      if (*(int *)(param_1 + 8) != 0) {
        (*(code *)&SUB_4008b3d0)(iVar3,*(int *)(param_1 + 8),iVar5 * 4);
        FUN_4013ae54(*(undefined4 *)(param_1 + 8),*(int *)(param_1 + 4) << 2);
        FUN_4013ae44(*(undefined4 *)(param_1 + 8));
      }
      *(int *)(param_1 + 4) = iVar5;
      *(int *)(param_1 + 8) = iVar3;
      memw();
      return 0;
    }
  }
  return 0xfffffff0;
}

