// Function : FUN_40186a1c
// Address  : 0x40186a1c
// Size     : 36 bytes


undefined4 FUN_40186a1c(int param_1)

{
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 1;
  if (*(byte *)(param_1 + 1) != 0) {
    iVar2 = param_1;
    do {
      if (iVar2 == param_1 + (uint)*(byte *)(param_1 + 1)) {
        return 1;
      }
      pcVar1 = (char *)(iVar2 + 2);
      iVar2 = iVar2 + 1;
    } while (*pcVar1 == '\0');
    uVar3 = 0;
  }
  return uVar3;
}

