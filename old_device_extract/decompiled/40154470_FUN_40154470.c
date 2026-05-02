// Function : FUN_40154470
// Address  : 0x40154470
// Size     : 38 bytes


bool FUN_40154470(undefined1 param_1,undefined1 param_2,undefined1 param_3)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = FUN_4015436c(param_1,param_2,param_3);
  bVar1 = false;
  if (iVar2 != 0) {
    iVar2 = FUN_40188b5c(iVar2,1);
    bVar1 = iVar2 == 0;
  }
  return bVar1;
}

