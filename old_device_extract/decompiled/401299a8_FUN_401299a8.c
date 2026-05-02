// Function : FUN_401299a8
// Address  : 0x401299a8
// Size     : 64 bytes


void FUN_401299a8(int *param_1)

{
  undefined1 uVar1;
  
  *(undefined4 *)(param_1[0x11] + 0x248) = *(undefined4 *)(*param_1 + 0x18);
  memw();
  FUN_40185804(param_1);
  if ((param_1[0x20] == 0x16) && (*(char *)param_1[0x1e] == '\x14')) {
    uVar1 = 3;
  }
  else {
    uVar1 = 2;
  }
  *(undefined1 *)(param_1[0x11] + 7) = uVar1;
  memw();
  memw();
  return;
}

