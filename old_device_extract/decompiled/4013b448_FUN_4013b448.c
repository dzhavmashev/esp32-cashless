// Function : FUN_4013b448
// Address  : 0x4013b448
// Size     : 65 bytes


undefined4 FUN_4013b448(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = FUN_4013b074(param_1,0);
  if (iVar1 == 0) {
    uVar2 = FUN_40131798(param_1 + 8);
    if (0x7f < uVar2) {
      iVar3 = param_1 + 0x14;
      iVar1 = FUN_4018601c(iVar3,0);
      if (((iVar1 != 0) && (uVar2 = FUN_40131798(iVar3), 1 < uVar2)) &&
         (iVar1 = FUN_401860ec(iVar3,param_1 + 8), iVar1 < 0)) {
        return 0;
      }
    }
  }
  return 0xffffbe00;
}

