// Function : FUN_401813bc
// Address  : 0x401813bc
// Size     : 22 bytes


int FUN_401813bc(int param_1)

{
  if ((*(byte *)(param_1 + 0x3ff96355) & 3) == 1) {
    param_1 = param_1 + 0x20;
  }
  return param_1;
}

