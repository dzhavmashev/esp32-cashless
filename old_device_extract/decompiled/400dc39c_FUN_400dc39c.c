// Function : FUN_400dc39c
// Address  : 0x400dc39c
// Size     : 44 bytes


void FUN_400dc39c(int param_1)

{
  undefined4 uVar1;
  
  if ((*(char *)(param_1 + 0x70) == '\0') && (*(char *)(param_1 + 0x30) != '\0')) {
    *(undefined1 *)(param_1 + 0x70) = 1;
    uVar1 = FUN_400f1a9c();
    *(undefined4 *)(param_1 + 0x74) = uVar1;
    if (*(int *)(param_1 + 0x48) != 0) {
      func_0x4009246c(*(int *)(param_1 + 0x48),3,0,0,0);
    }
  }
  return;
}

