// Function : FUN_400dc43c
// Address  : 0x400dc43c
// Size     : 44 bytes


void FUN_400dc43c(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_400f1a9c();
  *(undefined1 *)(param_1 + 0x5a) = 0;
  *(undefined4 *)(param_1 + 0x60) = 0;
  *(undefined2 *)(param_1 + 100) = 0;
  *(undefined1 *)(param_1 + 0x66) = 0;
  *(uint *)(param_1 + 0x5c) = (uint)*(ushort *)(param_1 + 0x68) + iVar1;
  if (*(char *)(param_1 + 0x70) != '\0') {
    FUN_400dc3c8(param_1);
  }
  return;
}

