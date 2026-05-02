// Function : FUN_4013b4e0
// Address  : 0x4013b4e0
// Size     : 45 bytes


undefined4 FUN_4013b4e0(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_4013b448(param_1);
  if ((((iVar1 != 0) || (iVar1 = FUN_4013b48c(param_2), iVar1 != 0)) ||
      (iVar1 = FUN_401860ec(param_1 + 8,param_2 + 8), iVar1 != 0)) ||
     (iVar1 = FUN_401860ec(param_1 + 0x14,param_2 + 0x14), uVar2 = 0, iVar1 != 0)) {
    uVar2 = 0xffffbe00;
  }
  return uVar2;
}

