// Function : FUN_400fd4c0
// Address  : 0x400fd4c0
// Size     : 39 bytes


void FUN_400fd4c0(uint param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 8;
  do {
    uVar1 = param_1 >> 0x1c;
    if (uVar1 < 10) {
      iVar3 = uVar1 + 0x30;
    }
    else {
      iVar3 = uVar1 + 0x57;
    }
    iVar2 = iVar2 + -1;
    FUN_400fd40c(iVar3);
    param_1 = param_1 << 4;
  } while (iVar2 != 0);
  return;
}

