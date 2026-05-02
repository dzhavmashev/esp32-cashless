// Function : FUN_400f0198
// Address  : 0x400f0198
// Size     : 18 bytes


void FUN_400f0198(int param_1)

{
  if (*(int *)(param_1 + 0x44) != 0) {
    func_0x40091740();
    *(undefined4 *)(param_1 + 0x44) = 0;
  }
  return;
}

