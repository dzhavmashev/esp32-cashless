// Function : FUN_40100de8
// Address  : 0x40100de8
// Size     : 39 bytes


void FUN_40100de8(int param_1)

{
  if (*(int *)(param_1 + 0x10) != 0) {
    if ((*(byte *)(*(int *)(param_1 + 0x10) + 0xeb) & 1) != 0) {
      FUN_4010b4ac();
    }
    if ((*(uint *)(param_1 + 0x48) & 0x80) != 0) {
      FUN_40113304(0x40100b10,*(undefined4 *)(param_1 + 0x10));
    }
    FUN_4010b4d8(*(undefined4 *)(param_1 + 0x10));
  }
  return;
}

