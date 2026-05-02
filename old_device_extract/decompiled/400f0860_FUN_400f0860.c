// Function : FUN_400f0860
// Address  : 0x400f0860
// Size     : 31 bytes


void FUN_400f0860(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  while ((iVar1 != param_3 && (iVar2 = FUN_400f0834(param_1), -1 < iVar2))) {
    *(char *)(param_2 + iVar1) = (char)iVar2;
    iVar1 = iVar1 + 1;
  }
  return;
}

