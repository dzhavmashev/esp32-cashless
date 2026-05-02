// Function : FUN_4015617c
// Address  : 0x4015617c
// Size     : 62 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4015617c(int param_1)

{
  if (param_1 == 0) {
    FUN_40147fe4(1,8,4,0x3f4339d8);
    return;
  }
  if (*(int *)(param_1 + 0x34) != 0) {
    (**(code **)(_DAT_3ffc1a34 + 0xb0))();
  }
  if (*(int *)(param_1 + 0x38) != 0) {
    (**(code **)(_DAT_3ffc1a34 + 0xb0))();
  }
  (**(code **)(_DAT_3ffc1a34 + 0xb0))(param_1);
  return;
}

