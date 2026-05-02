// Function : FUN_400f1e1c
// Address  : 0x400f1e1c
// Size     : 31 bytes


int FUN_400f1e1c(int param_1)

{
  uint uVar1;
  
  uVar1 = FUN_400f36bc();
  if (uVar1 < 80000000) {
    param_1 = param_1 * (0x50 / (uVar1 / 1000000));
  }
  return param_1;
}

