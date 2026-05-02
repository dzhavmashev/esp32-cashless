// Function : FUN_4018c528
// Address  : 0x4018c528
// Size     : 30 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4018c528(int param_1)

{
  *(undefined4 *)(param_1 + 0x28) = 0;
  **(int **)(_DAT_3ffc0034 + 0x350) = param_1;
  *(int *)(_DAT_3ffc0034 + 0x350) = param_1 + 0x28;
  memw();
  return;
}

