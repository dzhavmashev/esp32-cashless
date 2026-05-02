// Function : FUN_40108224
// Address  : 0x40108224
// Size     : 25 bytes


int FUN_40108224(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = FUN_40108208(param_1);
  if (iVar1 == 0) {
    puVar2 = (undefined4 *)FUN_40173a8c();
    *puVar2 = 9;
  }
  memw();
  return iVar1;
}

