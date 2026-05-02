// Function : FUN_4018e388
// Address  : 0x4018e388
// Size     : 10 bytes


undefined4 FUN_4018e388(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined4 *)(param_1 + 8);
  }
  return uVar1;
}

