// Function : FUN_40186c10
// Address  : 0x40186c10
// Size     : 29 bytes


void FUN_40186c10(int param_1,uint param_2)

{
  uint uVar1;
  
  for (uVar1 = 0; uVar1 != param_2; uVar1 = uVar1 + 1 & 0xff) {
    *(char *)(param_1 + 10) = (char)uVar1;
    memw();
    param_1 = param_1 + 0xc;
  }
  memw();
  return;
}

