// Function : FUN_400ed370
// Address  : 0x400ed370
// Size     : 76 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_400ed370(undefined4 param_1)

{
  int iVar1;
  char acStack_34 [16];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  iVar1 = FUN_400efed8(0x3ffc53f4,param_1,0,acStack_34,0x10);
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    func_0x40082ecc();
  }
  return iVar1 != 0 && acStack_34[0] == -0x17;
}

