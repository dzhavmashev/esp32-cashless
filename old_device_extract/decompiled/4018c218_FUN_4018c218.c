// Function : FUN_4018c218
// Address  : 0x4018c218
// Size     : 70 bytes


void FUN_4018c218(int param_1)

{
  short sVar1;
  short sVar2;
  
  if (((*(char *)(param_1 + 0xd) != '\0') && (*(char *)(param_1 + 0x168) != '\0')) &&
     (*(char *)(param_1 + 1) == '\x01')) {
    sVar1 = *(short *)(param_1 + 0x184);
    sVar2 = sVar1 + 1;
    *(short *)(param_1 + 0x184) = sVar2;
    memw();
    if (sVar1 < *(short *)(param_1 + 0x186)) {
      *(char *)(param_1 + 0x181) = *(char *)(param_1 + 0x183) * (char)sVar2;
      *(undefined1 *)(param_1 + 0x11) = 0;
      memw();
      memw();
      FUN_4018be94();
    }
  }
  return;
}

