// Function : FUN_40160254
// Address  : 0x40160254
// Size     : 77 bytes


void FUN_40160254(uint param_1,undefined1 param_2,byte param_3,byte param_4)

{
  int iVar1;
  
  iVar1 = (param_1 & 0xff) * 0x24;
  *(undefined1 *)(iVar1 + 0x3ffc7b21) = param_2;
  *(byte *)(iVar1 + 0x3ffc7b25) = param_3;
  *(byte *)(iVar1 + 0x3ffc7b26) = param_4;
  memw();
  if (param_4 < *(byte *)(iVar1 + 0x3ffc7b24)) {
    *(byte *)(iVar1 + 0x3ffc7b24) = param_4;
    memw();
    memw();
  }
  else if (*(byte *)(iVar1 + 0x3ffc7b24) < param_3) {
    *(byte *)(iVar1 + 0x3ffc7b24) = param_3;
  }
  *(undefined2 *)((param_1 & 0xff) * 0x24 + 0x3ffc7b34) = 0;
  memw();
  memw();
  return;
}

