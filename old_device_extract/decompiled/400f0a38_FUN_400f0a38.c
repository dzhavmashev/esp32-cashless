// Function : FUN_400f0a38
// Address  : 0x400f0a38
// Size     : 24 bytes


void FUN_400f0a38(int *param_1)

{
  if (((*(byte *)((int)param_1 + 0xf) & 0x80) == 0) && (*param_1 != 0)) {
    func_0x40094d88();
  }
  FUN_400f0a18(param_1);
  return;
}

