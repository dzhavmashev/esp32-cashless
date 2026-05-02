// Function : FUN_40150048
// Address  : 0x40150048
// Size     : 36 bytes


undefined4 FUN_40150048(int param_1)

{
  undefined4 uVar1;
  
  if (*(char *)(param_1 + 8) == '\0') {
    FUN_4015835c();
    return 0;
  }
  uVar1 = 0x102;
  if (*(char *)(param_1 + 8) == '\x01') {
    FUN_40148990(*(undefined4 *)(param_1 + 0xc));
    uVar1 = 0;
  }
  return uVar1;
}

