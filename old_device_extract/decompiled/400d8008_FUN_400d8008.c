// Function : FUN_400d8008
// Address  : 0x400d8008
// Size     : 52 bytes


void FUN_400d8008(int param_1)

{
  func_0x40091d60(0,1,0xffffffff);
  memw();
  if (*(char *)(param_1 + 0x55) != '\0') {
    memw();
    *(undefined1 *)(param_1 + 0x55) = 0;
    FUN_400f0780(0x3ffc5490,"NECTING");
    FUN_400d7d34(param_1,1);
  }
  return;
}

