// Function : FUN_40131574
// Address  : 0x40131574
// Size     : 77 bytes


undefined4 FUN_40131574(int param_1,uint param_2)

{
  int iVar1;
  
  if (param_2 < 0x2711) {
    if (param_2 <= *(uint *)(param_1 + 4)) {
      return 0;
    }
    iVar1 = FUN_4013ae30(param_2,4);
    if (iVar1 != 0) {
      if (*(int *)(param_1 + 8) != 0) {
        (*(code *)&SUB_4008b3d0)(iVar1,*(int *)(param_1 + 8),*(int *)(param_1 + 4) << 2);
        FUN_4013ae54(*(undefined4 *)(param_1 + 8),*(int *)(param_1 + 4) << 2);
        FUN_4013ae44(*(undefined4 *)(param_1 + 8));
      }
      *(uint *)(param_1 + 4) = param_2;
      *(int *)(param_1 + 8) = iVar1;
      memw();
      return 0;
    }
  }
  return 0xfffffff0;
}

