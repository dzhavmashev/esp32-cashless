// Function : FUN_4015d8cc
// Address  : 0x4015d8cc
// Size     : 47 bytes


void FUN_4015d8cc(char param_1,int param_2)

{
  if (param_1 != '\0') {
    memw();
    FUN_40162394(0,*(ushort *)(param_2 + 0x26) & 0xfff,param_2 + 4,*(undefined2 *)(param_2 + 0x28),
                 *(undefined4 *)(param_2 + 0x20));
    return;
  }
  FUN_40162500();
  return;
}

