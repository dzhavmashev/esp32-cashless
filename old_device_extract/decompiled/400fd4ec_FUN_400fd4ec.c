// Function : FUN_400fd4ec
// Address  : 0x400fd4ec
// Size     : 60 bytes


void FUN_400fd4ec(int param_1)

{
  uint uVar1;
  
  if (param_1 / 10 == 0) {
    uVar1 = 0x20;
  }
  else {
    uVar1 = param_1 / 10 + 0x30U & 0xff;
  }
  FUN_400fd40c(uVar1);
  FUN_400fd40c(param_1 % 10 + 0x30U & 0xff);
  return;
}

