// Function : FUN_4014ab3c
// Address  : 0x4014ab3c
// Size     : 50 bytes


void FUN_4014ab3c(uint param_1)

{
  if (7 < (param_1 & 0xff)) {
    FUN_40147fe4(1,0x400,2,0x3f4366ad);
    return;
  }
  *(undefined1 *)((param_1 & 0xff) + 0x3ffc89c6) = 0;
  memw();
  memw();
  return;
}

