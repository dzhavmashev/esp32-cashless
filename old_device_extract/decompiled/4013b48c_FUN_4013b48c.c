// Function : FUN_4013b48c
// Address  : 0x4013b48c
// Size     : 82 bytes


undefined4 FUN_4013b48c(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_4013b448(param_1);
  if ((iVar1 == 0) && (iVar1 = FUN_4013b074(param_1,1), iVar1 == 0)) {
    memw();
    iVar1 = FUN_4013c8d0(param_1 + 8,param_1 + 0x2c,param_1 + 0x38,param_1 + 0x20,param_1 + 0x14,0,0
                        );
    if ((iVar1 == 0) &&
       (iVar1 = FUN_4013c7ac(param_1 + 0x2c,param_1 + 0x38,param_1 + 0x20,param_1 + 0x44,
                             param_1 + 0x50,param_1 + 0x5c), iVar1 == 0)) {
      return 0;
    }
  }
  return 0xffffbe00;
}

