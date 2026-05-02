// Function : FUN_400f1190
// Address  : 0x400f1190
// Size     : 45 bytes


bool FUN_400f1190(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  iVar1 = FUN_40184778(param_1);
  iVar2 = FUN_40184778(param_2);
  bVar3 = false;
  if (iVar1 == iVar2) {
    iVar1 = FUN_400f112c(param_1,param_2);
    bVar3 = iVar1 == 0;
  }
  return bVar3;
}

