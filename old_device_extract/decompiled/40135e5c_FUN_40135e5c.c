// Function : FUN_40135e5c
// Address  : 0x40135e5c
// Size     : 46 bytes


undefined4 FUN_40135e5c(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_401860ec(param_1,param_2);
  if (((iVar1 == 0) && (iVar1 = FUN_401860ec(param_1 + 0xc,param_2 + 0xc), iVar1 == 0)) &&
     (iVar1 = FUN_401860ec(param_1 + 0x18,param_2 + 0x18), iVar1 == 0)) {
    return 0;
  }
  return 0xffffb080;
}

