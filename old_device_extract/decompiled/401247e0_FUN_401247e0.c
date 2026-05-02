// Function : FUN_401247e0
// Address  : 0x401247e0
// Size     : 59 bytes


void FUN_401247e0(int param_1)

{
  if (param_1 != 0) {
    (*(code *)&SUB_40085b60)(param_1 + 0x1c8);
    FUN_4011f9fc(param_1 + 0x1c8);
    if ((*(byte *)(param_1 + 0x19c) & 2) == 0) {
      FUN_40124070(param_1);
    }
    else {
      *(byte *)(param_1 + 0x19c) = *(byte *)(param_1 + 0x19c) | 4;
      memw();
    }
  }
  memw();
  return;
}

